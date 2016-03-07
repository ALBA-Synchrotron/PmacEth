/* PMAC Ethernet communication library Version 4 

Author: Cristina Lazar - clazar@cells.es
Created: 08/26/2008

This library implements the protocol for communication 
with PMAC controller cards using TCP/IP, as described in 
the Delta Tau manuals.

*/

#ifndef PCOMMX_H
#define PCOMMX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <fcntl.h>
#include <pthread.h>

#define PMAC_NO 1
#define PMAC_DEFAULT_IP "192.6.94.5"
#define PMAC_PORT 1025
#define ETHERNETCMDSIZE 8

/* request type values */
#define VR_UPLOAD           0xC0
#define VR_DOWNLOAD         0x40

/* request values */
#define VR_PMAC_SENDLINE 0xB0
#define VR_PMAC_GETLINE 0xB1
#define VR_PMAC_FLUSH 0xB3
#define VR_PMAC_GETMEM 0xB4
#define VR_PMAC_SETMEM 0xB5
#define VR_PMAC_SENDCTRLCHAR 0xB6   
#define VR_PMAC_SETBIT 0xBA
#define VR_PMAC_SETBITS 0xBB
#define VR_PMAC_PORT 0xBE
#define VR_PMAC_GETRESPONSE 0xBF
#define VR_PMAC_READREADY 0xC2
#define VR_CTRL_RESPONSE 0xC4
#define VR_PMAC_GETBUFFER 0xC5
#define VR_PMAC_WRITEBUFFER 0xC6
#define VR_PMAC_WRITEERROR 0xC7     /* not documented, not implemented yet */
#define VR_FWDOWNLOAD 0xCB
#define VR_IPADDRESS 0xE0

/* error codes */
#define ERR_SOCKCREAT -1
#define ERR_NOCONN -2
#define ERR_SOCKCLOSE -3
#define ERR_COMM1 -4
#define ERR_COMM2 -5
#define ERR_BADMSG -6
#define ERR_BUFSIZE -7
#define ERR_WRITEBUF -8

/* communication packet format */
struct EthernetCmd
{
  u_int8_t   RequestType;
  u_int8_t   Request;
  u_int16_t  wValue;
  u_int16_t  wIndex;
  u_int16_t  wLength;
  u_int8_t   bData[1492];
};

#ifdef __cplusplus
extern "C"{
#endif

  int open_pmac_device(const char *ipaddr);
  int close_pmac_device(int sockfd);
  int pmac_get_response(int sockfd, char *buf, int buf_len);

  int pmac_read_ready(int device);   
  int pmac_send_line(int device, char *buf);
  int pmac_get_line(int device, char *buf, int buf_len);
  int pmac_send_control_char(int sockfd, unsigned char c);
  int pmac_get_control_response(int sockfd, unsigned char c, char *buf, int buf_len);

  int pmac_sock_flush(int sockfd, int flush_timeout);
  int pmac_get_buffer(int sockfd, char *buf, int buf_len);
  int pmac_write_buffer(int sockfd, char *buf, int buf_len);
  int pmac_get_mem(int sockfd, unsigned int offset, char *buf, int buf_len);
  int pmac_set_mem(int sockfd, unsigned int offset, char *buf);

  int pmac_get_ip(int sockfd, char *ipaddr);
  int pmac_set_ip(int sockfd, const char *ipaddr);
  int pmac_set_bit(int sockfd, unsigned int offset, unsigned short bitno, unsigned short on);
  int pmac_set_bits(int sockfd, u_int16_t offset, u_int32_t *mask);
  int pmac_fw_download(int sockfd, char *data, int len, int bRestart);
  int pmac_test_port(int sockfd, unsigned short offset, int direction);

#ifdef __cplusplus
}
#endif

#endif
