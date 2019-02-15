/* PMAC Ethernet communication library Version 4 

Author: Cristina Lazar - clazar@cells.es
Created: 08/26/2008

This library implements the protocol for communication 
with PMAC controller cards using TCP/IP, as described in 
the Delta Tau manuals.

*/

#include "pcommx.h"

/* try to set up a TCP connection to PMAC controller. 
   Requires: a valid IP address | NULL if default address should be used
   Returns: sockfd on success | a negative number on failure */

int open_pmac_device(const char *ipaddr)
{
  struct sockaddr_in client;
  int sockfd;

  if((sockfd=socket(PF_INET,SOCK_STREAM, 0))!=-1)
    {
      if(ipaddr!=NULL)
	client.sin_addr.s_addr=inet_addr(ipaddr);
      else
	client.sin_addr.s_addr=inet_addr(PMAC_DEFAULT_IP);
      client.sin_family=PF_INET;
      client.sin_port=htons(PMAC_PORT);
      if(connect(sockfd,(__CONST_SOCKADDR_ARG)&client,(socklen_t) (sizeof(client)))!=0)
	{
	  perror("open_pmac_device: PMAC connect failed");
	  return(ERR_NOCONN);
	}
      else
	return(sockfd);
    }
  else
    {
      perror("open_pmac_device: PMAC socket creation failed");
      return(ERR_SOCKCREAT);
    }
}
	
/* close a connection previously opened by open_pmac_device().
   Requires: socket descriptor
   Returns: 0 on success | -1 on failure. */

int close_pmac_device(int sockfd)
{
  if(shutdown(sockfd,SHUT_RDWR)==-1)
    {
      perror("close_pmac_device: PMAC connection shut-down failed");
      return(ERR_SOCKCLOSE);
    }
  return(0);
}

/*  generic function for communication with PMAC controller.
    On success, controller response is returned to caller in the same buffer used for sending the command.
    Requires: socket descriptor, buffered data to be sent to the device, length of the buffer. 
    Returns: number of characters read on success | a negative number on failure. */

int pmac_get_response(int sockfd, char *buf, int buf_len)
{
  struct EthernetCmd EthCmd;
  char cResponse[1400];
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_get_response: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_DOWNLOAD;
  EthCmd.Request     = VR_PMAC_GETRESPONSE;
  EthCmd.wValue      = 0;
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = htons(strlen(buf));
  strncpy(EthCmd.bData,buf,strlen(buf));
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE + strlen(buf),0)==-1)
    {
      perror("pmac_get_response: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,cResponse,1400,0))==-1)
    {
      perror("pmac_get_response: can't get response message from controller");
      return(ERR_COMM2);
    }
  strncpy(buf,cResponse,((retval>buf_len)?(buf_len-1):retval));

  /* if controller response is just <ACK>, keep it;
     if controller response ends with <CR><ACK>, replace <CR> with <NUL> */
  if(retval>buf_len && buf_len>1)
    buf[buf_len-1]='\0';
  else
    {
      if(retval>1)
	if(buf[retval-2]=='\r')
	  buf[retval-2]='\0';
	else
	  buf[retval-1]='\0';
    }
  return(retval);
}

/* check if controller card is ready to be read.
   Requires: socket descriptor
   Returns: 
    1 if there's data to be read
    0 if there's no data to be read
    a negative number on error   */

int pmac_read_ready(int sockfd)
{
  struct EthernetCmd EthCmd;
  char cResponse[2];
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_read_ready: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_UPLOAD;
  EthCmd.Request     = VR_PMAC_READREADY;
  EthCmd.wValue      = 0;
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = htons(2);
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE,0)==-1)
    {
      perror("pmac_read_ready: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,cResponse,2,0))==-1)
    {
      perror("pmac_read_ready: can't receive message from controller");
      return(ERR_COMM2);
    }
  if(retval==2)
    if(cResponse[0]&0xFF)
      return(1);
    else
      return(0);
  else
    {
      perror("pmac_read_ready: received bad message from controller");
      return(ERR_BADMSG);
    }
}

/* generic function for sending data to the PMAC controller. Data string should not be terminated with <CR>.
   Requires: socket descriptor, data buffer to send
   Returns: 0 on success | a negative number on error  */

int pmac_send_line(int sockfd, char *buf)
{
  struct EthernetCmd EthCmd;
  char cResponse[2];
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_send_line: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_DOWNLOAD;
  EthCmd.Request     = VR_PMAC_SENDLINE;
  EthCmd.wValue      = 0;
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = htons(strlen(buf));
  strncpy(EthCmd.bData,buf,strlen(buf));
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE + strlen(buf),0)==-1)
    {
      perror("pmac_send_line: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,cResponse,2,0))==-1)
    {
      perror("pmac_send_line: can't confirm message was sent to controller");
      return(ERR_COMM2);
    }
  if(retval==1)
    return(0);
  else
    {
      perror("pmac_send_line: received bad message from controller");
      return(ERR_BADMSG);
    }
}

/* get any available PMAC string ended with <CR> | <ACK> | <LF>.
   Requires: socket descriptor, buffer to return data in, size of buffer
   Returns: number of characters retrieved from PMAC | a negative number on error  */

int pmac_get_line(int sockfd, char *buf,int buf_len)
{
  struct EthernetCmd EthCmd;
  char cResponse[2048];
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_get_line: PMAC is not connected");
      return ERR_NOCONN;
    }
  EthCmd.RequestType = VR_UPLOAD;
  EthCmd.Request     = VR_PMAC_GETLINE;
  EthCmd.wValue      = 0;
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = 0;
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE,0)==-1)
    {
      perror("pmac_get_line: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,cResponse,2048,0))==-1)
    {
      perror("pmac_get_line: can't receive message from controller");
      return(ERR_COMM2);
    }

  /* NO '\0' at EOString */
  strncpy(buf,cResponse,((retval>buf_len)?(buf_len-1):retval));
  return(retval);
}

/* send control characters to PMAC, (see also pmac_get_control_response!)
   Requires: socket descriptor, character to send
   Returns: 0 on success | a negative number on error  */

int pmac_send_control_char(int sockfd, unsigned char c)
{
  struct EthernetCmd EthCmd;
  char cResponse;
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_send_control_char: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_DOWNLOAD;
  EthCmd.Request     = VR_PMAC_SENDCTRLCHAR;
  EthCmd.wValue      = htons(c);
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = 0;
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE,0)==-1)
    {
      perror("pmac_send_control_char: can't send character to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,&cResponse,1,0))==-1)
    {
      perror("pmac_send_control_char: can't confirm character was sent to controller");
      return(ERR_COMM2);
    }
  return(0);
}

/* send control characters to PMAC & obtain controller response; should be used for ^B, ^C, ^F, ^G, ^P, ^V. 
   Requires: socket descriptor, control character to send, buffer to get response in, length of buffer
   Returns: number of characters received from controller | a negative number on error  */

int pmac_get_control_response(int sockfd, unsigned char c, char *buf, int buf_len)
{
  struct EthernetCmd EthCmd;
  char cResponse[1400];
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_get_control_response: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_UPLOAD;
  EthCmd.Request     = VR_CTRL_RESPONSE;
  EthCmd.wValue      = htons(c);
  EthCmd.wIndex      = 0;
  //thanks to Lothar this command cand handle TurboPmac query about global CS status.
  //EthCmd.wLength     = htons(1400);
  EthCmd.wLength     = htons(1535);
 
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE,0)==-1)
    {
      perror("pmac_get_control_response: can't send character to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,cResponse,1400,0))==-1)
    {
      perror("pmac_get_control_response: can't confirm character was sent to controller");
      return(ERR_COMM2);
    }
  strncpy(buf,cResponse,((retval>buf_len)?(buf_len-1):retval));

  /* if controller response is just <ACK>, keep it;
     if controller response ends with <CR><ACK>, replace <CR> with <NUL> */
  if(retval>buf_len && buf_len>1)
    buf[buf_len-1]='\0';
  else
    {
      if(retval>1)
	if(buf[retval-2]=='\r')
	  buf[retval-2]='\0';
	else
	  buf[retval-1]='\0';
    }
  return(retval);
}

/* discard current PMAC command & response strings.
   Requires: socket descriptor, a timeout value
   Returns: 0 on success | a negative number on error   */

int pmac_sock_flush(int sockfd, int flush_timeout)
{
  struct EthernetCmd EthCmd;
  char cResponse[2];
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_sock_flush: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_DOWNLOAD;
  EthCmd.Request     = VR_PMAC_FLUSH;
  EthCmd.wValue      = htons(flush_timeout);
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = 0;
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE,0)==-1)
    {
      perror("pmac_sock_flush: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,cResponse,2,0))==-1)
    {
      perror("pmac_sock_flush: can't receive message from controller");
      return(ERR_COMM2);
    }
  if(retval==1)
    return(0);
  else
    {
      perror("pmac_sock_flush: received bad message from controller");
      return(ERR_BADMSG);
    }
}

/* get any available PMAC string up to an <ACK> or <LF>, maximum 1400 bytes. 
   If a <BEL> or <STX> is detected only data up to the next <CR> is returned.
   If there's no data to be read from PMAC buffer, the recv() call will BLOCK.
   Requires: socket descriptor, buffer to store data in, buffer length
   Returns: number of characters retrieved | a negative number on error  */

int pmac_get_buffer(int sockfd, char *buf, int buf_len)
{
  struct EthernetCmd EthCmd;
  char cResponse[1400];
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_get_buffer: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_UPLOAD;
  EthCmd.Request     = VR_PMAC_GETBUFFER;
  EthCmd.wValue      = 0;
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = 0;
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE,0)==-1)
    {
      perror("pmac_get_buffer: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,cResponse,1400,0))==-1)
    {
      perror("pmac_get_buffer: can't receive message from controller");
      return(ERR_COMM2);
    }
  if(retval>1400)
    {
      perror("pmac_get_buffer: received bad message from controller");
      return(ERR_BADMSG);
    }  

  /* NO '\0' at EOString */
  strncpy(buf,cResponse,((retval>buf_len)?(buf_len-1):retval));
  return(retval);
}

/* write multiple lines to PMAC: maximum 1024 bytes, lines ended with <NUL>.
   Requires: socket descriptor, data buffer to write, buffer length
   Returns: 0 on success | a negative number on  */

int pmac_write_buffer(int sockfd, char *buf, int buf_len)
{
  struct EthernetCmd EthCmd;
  unsigned char cResponse[4];
  int retval;
  union {
    unsigned int i;
    unsigned char c[4];
  } line_no;

  if(buf_len>1024)
    {
      fprintf(stderr,"pmac_write_buffer: buffer size > 1024\n");
      return(ERR_BUFSIZE);
    }
  
  if(sockfd<0)
    {
      perror("pmac_write_buffer: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_DOWNLOAD;
  EthCmd.Request     = VR_PMAC_WRITEBUFFER;
  EthCmd.wValue      = 0;
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = htons(buf_len);
  memcpy(EthCmd.bData,buf,buf_len);
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE+buf_len,0)==-1)
    {
      perror("pmac_write_buffer: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,cResponse,4,0))==-1)
    {
      perror("pmac_write_buffer: can't receive message from controller");
      return(ERR_COMM2);
    }
  if(retval!=4)
    {
      perror("pmac_write_buffer: received bad message from controller");
      return(ERR_BADMSG);
    }

  /* test for errors */  
  if(cResponse[3]==0x80)
    {
      line_no.i=0;
      line_no.c[0]=cResponse[0];
      line_no.c[1]=cResponse[1];
      fprintf(stderr,"pmac_write_buffer: error type %#X in line %d\n",cResponse[2],line_no.i);
      return(ERR_WRITEBUF);
    }
  return(0);
}

/* read current PMAC IP address, (i.e. IP address that's currently set.)
   Requires: sockfd, buffer for storing IP as [human-readable] string
   Returns: 0 on success | a negative number on error   */

int pmac_get_ip(int sockfd, char *ipaddr)
{
  struct EthernetCmd EthCmd;
  unsigned char ctrl_ip[4];
  int retval;

  if(sockfd<0)
    {
      perror("pmac_get_ip: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_UPLOAD;
  EthCmd.Request     = VR_IPADDRESS;
  EthCmd.wValue      = 0;
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = htons(4);
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE,0)==-1)
    {
      perror("pmac_get_ip: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,ctrl_ip,4,0))==-1)
    {
      perror("pmac_get_ip: can't receive message from controller");
      return(ERR_COMM2);
    }
  if(retval==4)
    {
      sprintf(ipaddr,"%u.%u.%u.%u",ctrl_ip[0],ctrl_ip[1],ctrl_ip[2],ctrl_ip[3]);
      return(0);
    }
  else
    {
      perror("pmac_get_ip: received bad message from controller");
      return(ERR_BADMSG);
    }
}

/* set PMAC IP address.
   The new address will be used after a PMAC reset.
   Requires: socket descriptor, string containing new IP address in human-readable form
   Returns: number of IP bytes written (should be 4) */

int pmac_set_ip(int sockfd, const char *ipaddr)
{
  struct EthernetCmd EthCmd;
  char cResponse[4];
  union {
    in_addr_t ip_address;
    u_int8_t binary_data[4];
  } data;

  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_set_ip: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_DOWNLOAD;
  EthCmd.Request     = VR_IPADDRESS;
  EthCmd.wValue      = 0;
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = htons(4);
  data.ip_address=inet_addr(ipaddr);
  strncpy(EthCmd.bData,data.binary_data,4);
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE + 4,0)==-1)
    {
      perror("pmac_set_ip: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,cResponse,4,0))==-1)
    {
      perror("pmac_set_ip: get response failed");
      return(ERR_COMM2);
    }
  return(retval);
}

/* retrieve DPRAM data from PMAC controller, maximum 1400 bytes.
   Requires: socket descriptor, DPRAM byte offset, data buffer, length of buffer
   Returns: number of bytes retrieved | a negative number on error  */

int pmac_get_mem(int sockfd, unsigned int offset, char *buf, int buf_len)
{
  struct EthernetCmd EthCmd;
  char cResponse[1400];
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_get_mem: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_UPLOAD;
  EthCmd.Request     = VR_PMAC_GETMEM;
  EthCmd.wValue      = htons(offset);
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = htons(buf_len);
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE,0)==-1)
    {
      perror("pmac_get_mem: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,cResponse,1400,0))==-1)
    {
      perror("pmac_get_mem: can't get response message from controller");
      return(ERR_COMM2);
    }

  /* NO '\0' at EOString */
  strncpy(buf,cResponse,((retval>buf_len)?(buf_len-1):retval));
  return(retval);
}

/* write data to DPRAM, maximum 1400 bytes.
   Requires: socket descriptor, DPRAM byte offset, data buffer
   Returns: 0 on success | a negative number on error   */

int pmac_set_mem(int sockfd, unsigned int offset, char *buf)
{
  struct EthernetCmd EthCmd;
  char cResponse;
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_set_mem: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_UPLOAD;
  EthCmd.Request     = VR_PMAC_SETMEM;
  EthCmd.wValue      = htons(offset);
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = htons(strlen(buf));
  strncpy(EthCmd.bData,buf,strlen(buf));
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE + strlen(buf),0)==-1)
    {
      perror("pmac_set_mem: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,&cResponse,1,0))==-1)
    {
      perror("pmac_set_mem: can't confirm message was sent to controller");
      return(ERR_COMM2);
    }
  if(retval==1)
    return(0);
  else
    {
      perror("pmac_set_mem: received bad message from controller");
      return(ERR_BADMSG);
    }
}

/* set/clear 1 bit in a 32-bit word in DPRAM.
   Requires: socket descriptor, DPRAM byte offset, bit number, operation type: 1 = set, 0=clear
   Returns: 0 on success | a negative number on error   */

int pmac_set_bit(int sockfd, unsigned int offset, unsigned short bitno, unsigned short on)
{
  struct EthernetCmd EthCmd;
  char cResponse;
  u_int32_t mask=0x00000001;
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_set_bit: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_UPLOAD;
  EthCmd.Request     = VR_PMAC_SETBIT;
  EthCmd.wValue      = htons(offset);
  EthCmd.wIndex      = htons(on);
  EthCmd.wLength     = htons(4);
  mask<<=bitno;

  /* if clearing a bit complement mask to prepare firmware for AND */
  if(!on)
    mask=~mask;
  memcpy(EthCmd.bData,&mask,4);
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE + 4,0)==-1)
    {
      perror("pmac_set_bit: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,&cResponse,1,0))==-1)
    {
      perror("pmac_set_bit: can't confirm message was sent to controller");
      return(ERR_COMM2);
    }
  if(retval==1)
    return(0);
  else
    {
      perror("pmac_set_bit: received bad message from controller");
      return(ERR_BADMSG);
    }
}

/* set/clear bits in a 32-bit word in DPRAM.
   Requires: socket descriptor, DPRAM byte offset, bit mask
   Returns: 0 on success | a negative number on error   */

int pmac_set_bits(int sockfd, u_int16_t offset, u_int32_t *mask)
{
  struct EthernetCmd EthCmd;
  char cResponse;
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_set_bits: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_UPLOAD;
  EthCmd.Request     = VR_PMAC_SETBITS;
  EthCmd.wValue      = htons(offset);
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = htons(8);
  memcpy(EthCmd.bData,mask,8);
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE + 8,0)==-1)
    {
      perror("pmac_set_bits: can't send message to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,&cResponse,1,0))==-1)
    {
      perror("pmac_set_bits: can't confirm message was sent to controller");
      return(ERR_COMM2);
    }
  if(retval==1)
    return(0);
  else
    {
      perror("pmac_set_bits: received bad message from controller");
      return(ERR_BADMSG);
    }
}

/* write raw data to PMAC host port for firmware download. NOT TESTED!!!
   Requires: socket descriptor, data buffer to write (lines ended with <NUL>), data length, *restart bit* (1 on start!?)
   Returns: 0 on success | a negative number on error   */

int pmac_fw_download(int sockfd, char *data, int len, int bRestart)
{
  struct EthernetCmd EthCmd;
  char cResponse;
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_fw_download: PMAC is not connected");
      return(ERR_NOCONN);
    }
  EthCmd.RequestType = VR_DOWNLOAD;
  EthCmd.Request     = VR_FWDOWNLOAD;
  EthCmd.wValue      = htons(bRestart);
  EthCmd.wIndex      = 0;
  EthCmd.wLength     = htons(len);
  memcpy(EthCmd.bData,data,len);
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE + len,0)==-1)
    {
      perror("pmac_fw_download: can't send data to controller");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,&cResponse,1,0))==-1)
    {
      perror("pmac_fw_download: can't confirm data was sent to controller");
      return(ERR_COMM2);
    }
  if(retval==1)
    return(0);
  else
    {
      perror("pmac_fw_download: received bad message from controller");
      return(ERR_BADMSG);
    }
}

/* function for testing PMAC ports.
   Requires: socket descriptor, *unknown* offset, direction: 1 test sending to port, 0 test receiving from port
   Returns: 0 on success | a negative number on failure   */

int pmac_test_port(int sockfd, unsigned short offset, int direction)
{
  struct EthernetCmd EthCmd;
  char c,cResponse;
  int retval;
  
  if(sockfd<0)
    {
      perror("pmac_test_port: PMAC is not connected");
      return(ERR_NOCONN);
    }
  if(direction)
    {
      c='p';
      EthCmd.RequestType = VR_DOWNLOAD;
      EthCmd.Request     = VR_PMAC_PORT;
      EthCmd.wValue      = htons(offset);
      EthCmd.wIndex      = htons(c);
      EthCmd.wLength     = 0;
    }
  else
    {
      EthCmd.RequestType = VR_UPLOAD;
      EthCmd.Request     = VR_PMAC_PORT;
      EthCmd.wValue      = htons(offset);
      EthCmd.wIndex      = 0;
      EthCmd.wLength     = 0;
    }
  if(send(sockfd,&EthCmd,ETHERNETCMDSIZE,0)==-1)
    {
      perror("pmac_test_port: can't send data to port");
      return(ERR_COMM1);
    }
  if((retval=recv(sockfd,&cResponse,1,0))==-1)
    {
      perror("pmac_test_port: can't confirm data was sent to port");
      return(ERR_COMM2);
    }
  else
    return(0);
}
