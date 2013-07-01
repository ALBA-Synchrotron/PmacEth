//=============================================================================
//
// file :        PmacEth.h
//
// description : Include for the PmacEth class.
//
// project :	PMAC over Ethernet
//
// $Author:  $
//
// $Revision:  $
//
// $Log:  $
//
// copyleft :    European Synchrotron Radiation Facility
//               BP 220, Grenoble 38043
//               FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================
#ifndef _PMACETH_H
#define _PMACETH_H

#include <tango.h>

//using namespace Tango;

/**
 * @author	$Author:  $
 * @version	$Revision:  $
 */

 //	Add your own constants definitions here.
 //-----------------------------------------------


namespace PmacEth_ns
{

/**
 * Class Description:
 * Device Server for PMAC over Ethernet
 */

/*
 *	Device States Description:
*  Tango::ON :   PMAC - PC connection established.
*  Tango::OFF :  PMAC - PC connection not set.
 */


class PmacEth: public Tango::Device_3Impl
{
public :
	//	Add your own data members here
	//-----------------------------------------


	//	Here is the Start of the automatic code generation part
	//-------------------------------------------------------------	
/**
 *	@name attributes
 *	Attributs member data.
 */
//@{
		Tango::DevLong	*attr_Position_read;
		Tango::DevLong	*attr_Velocity_read;
		Tango::DevLong	*attr_FollowErr_read;
//@}

/**
 *	@name Device properties
 *	Device properties member data.
 */
//@{
/**
 *	IP address of PMAC controller card.
 */
	string	iP_address;
//@}

/**@name Constructors
 * Miscellaneous constructors */
//@{
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
	PmacEth(Tango::DeviceClass *cl,string &s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
	PmacEth(Tango::DeviceClass *cl,const char *s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device name
 *	@param d	Device description.
 */
	PmacEth(Tango::DeviceClass *cl,const char *s,const char *d);
//@}

/**@name Destructor
 * Only one desctructor is defined for this class */
//@{
/**
 * The object desctructor.
 */	
	~PmacEth() {delete_device();};
/**
 *	will be called at device destruction or at init command.
 */
	void delete_device();
//@}

	
/**@name Miscellaneous methods */
//@{
/**
 *	Initialize the device
 */
	virtual void init_device();
/**
 *	Always executed method befor execution command method.
 */
	virtual void always_executed_hook();

//@}

/**
 * @name PmacEth methods prototypes
 */

//@{
/**
 *	Hardware acquisition for attributes.
 */
	virtual void read_attr_hardware(vector<long> &attr_list);
/**
 *	Extract real attribute values for Position acquisition result.
 */
	virtual void read_Position(Tango::Attribute &attr);
/**
 *	Extract real attribute values for Velocity acquisition result.
 */
	virtual void read_Velocity(Tango::Attribute &attr);
/**
 *	Extract real attribute values for FollowErr acquisition result.
 */
	virtual void read_FollowErr(Tango::Attribute &attr);
/**
 *	Read/Write allowed for Position attribute.
 */
	virtual bool is_Position_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for Velocity attribute.
 */
	virtual bool is_Velocity_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for FollowErr attribute.
 */
	virtual bool is_FollowErr_allowed(Tango::AttReqType type);
/**
 *	Execution allowed for OpenConnection command.
 */
	virtual bool is_OpenConnection_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for CloseConnection command.
 */
	virtual bool is_CloseConnection_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for AboutPmac command.
 */
	virtual bool is_AboutPmac_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for FirmwareInfo command.
 */
	virtual bool is_FirmwareInfo_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for GetIPaddr command.
 */
	virtual bool is_GetIPaddr_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for SetIPaddr command.
 */
	virtual bool is_SetIPaddr_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for JogPlus command.
 */
	virtual bool is_JogPlus_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for JogMinus command.
 */
	virtual bool is_JogMinus_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for JogStop command.
 */
	virtual bool is_JogStop_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for JogToPos command.
 */
	virtual bool is_JogToPos_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for JogDistFromPos command.
 */
	virtual bool is_JogDistFromPos_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for JogDistFromCmdPos command.
 */
	virtual bool is_JogDistFromCmdPos_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for GetFeedrateOverride command.
 */
	virtual bool is_GetFeedrateOverride_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for SetFeedrateOverride command.
 */
	virtual bool is_SetFeedrateOverride_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for ResetMotor command.
 */
	virtual bool is_ResetMotor_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for HomeMotor command.
 */
	virtual bool is_HomeMotor_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for HomeZeroMotor command.
 */
	virtual bool is_HomeZeroMotor_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for KillMotor command.
 */
	virtual bool is_KillMotor_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for ClearAmplifFault command.
 */
	virtual bool is_ClearAmplifFault_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for GlobalReset command.
 */
	virtual bool is_GlobalReset_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for GlobalResetReinit command.
 */
	virtual bool is_GlobalResetReinit_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for SendCtrlChar command.
 */
	virtual bool is_SendCtrlChar_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for GlobalStatus command.
 */
	virtual bool is_GlobalStatus_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for CoordSysStatus command.
 */
	virtual bool is_CoordSysStatus_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for GetIVariable command.
 */
	virtual bool is_GetIVariable_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for SetIVariable command.
 */
	virtual bool is_SetIVariable_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for GetMVariable command.
 */
	virtual bool is_GetMVariable_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for SetMVariable command.
 */
	virtual bool is_SetMVariable_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for GetPVariable command.
 */
	virtual bool is_GetPVariable_allowed(const CORBA::Any &any);
/**
 *      Execution allowed for GetPVariableRange command.
 */
        virtual bool is_GetPVariableRange_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for SetPVariable command.
 */
	virtual bool is_SetPVariable_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for SaveIVars command.
 */
	virtual bool is_SaveIVars_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DownloadFile command.
 */
	virtual bool is_DownloadFile_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for UploadVars command.
 */
	virtual bool is_UploadVars_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for UploadProg command.
 */
	virtual bool is_UploadProg_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for GetMotorNo command.
 */
	virtual bool is_GetMotorNo_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for SetMotorNo command.
 */
	virtual bool is_SetMotorNo_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DefineCoordSys command.
 */
	virtual bool is_DefineCoordSys_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for GetCoordSys command.
 */
	virtual bool is_GetCoordSys_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for OnlineCmd command.
 */
	virtual bool is_OnlineCmd_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for EnablePLC command.
 */
	virtual bool is_EnablePLC_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for DisablePLC command.
 */
	virtual bool is_DisablePLC_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for RunMotionProg command.
 */
	virtual bool is_RunMotionProg_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for GetMotorPos command.
 */
	virtual bool is_GetMotorPos_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for ListPLC command.
 */
	virtual bool is_ListPLC_allowed(const CORBA::Any &any);

/**
 * Open TCP connection with the PMAC controller card.
 *	The device property IP_address must contain the actual PMAC IP address.
 *	@exception DevFailed
 */
	void	open_connection();
/**
 * Close current TCP connection between PC & PMAC.
 *	@exception DevFailed
 */
	void	close_connection();
/**
 * Display information about PMAC controller card.
 *	@return	
 *	@exception DevFailed
 */
	Tango::DevString	about_pmac();
/**
 * Display information about PMAC firmware in  use.
 *	@return	
 *	@exception DevFailed
 */
	Tango::DevString	firmware_info();
/**
 * Get current/set PMAC IP address from controller card.
 *	@return	PMAC IP address read from controller card.
 *	@exception DevFailed
 */
	Tango::DevString	get_ipaddr();
/**
 * dotted decimal form.
 *	@param	argin	PMAC IP address to set; dotted decimal form.
 *	@exception DevFailed
 */
	void	set_ipaddr(Tango::DevString);
/**
 * Jog motor indefinitely in the positive direction.
 *	@exception DevFailed
 */
	void	jog_plus(const Tango::DevVarShortArray *);
/**
 * Jog motor indefinitely in the negative direction.
 *	@exception DevFailed
 */
	void	jog_minus(const Tango::DevVarShortArray *);
/**
 * Stop jogging motor.
 *	Restore position control if motor was killed.
 *	@exception DevFailed
 */
	void	jog_stop(const Tango::DevVarShortArray *);
/**
 * Jog motor to specified position.
 *	@param	argin	Position motor should move to, in encoder counts.
 *	@exception DevFailed
 */
	void	jog_to_pos(const Tango::DevVarDoubleArray *);
/**
 * Jog motor specified distance from the current actual position.
 *	@param	argin	Distance from current actual position, in encoder counts.
 *	@exception DevFailed
 */
	void	jog_dist_from_pos(Tango::DevLong);
/**
 * Jog motor specified distance from the current commanded position.
 *	@param	argin	Distance from current commanded position, in encoder counts.
 *	@exception DevFailed
 */
	void	jog_dist_from_cmd_pos(Tango::DevLong);
/**
 * Report current feedrate override value.
 *	@return	Feedrate override in percents.
 *	@exception DevFailed
 */
	Tango::DevDouble	get_feedrate_override();
/**
 * Set feedrate override (percentage).
 *	@param	argin	Feedrate override in percents.
 *	@exception DevFailed
 */
	void	set_feedrate_override(Tango::DevFloat);
/**
 * Reset feedback device(s) and phasing.
 *	@exception DevFailed
 */
	void	reset_motor(const Tango::DevVarShortArray *);
/**
 * Perform homing routine for current motor.
 *	@exception DevFailed
 */
	void	home_motor(const Tango::DevVarShortArray *);
/**
 * Perform zero-move routine for current motor.
 *	@exception DevFailed
 */
	void	home_zero_motor(const Tango::DevVarShortArray *);
/**
 * Kill output for current motor.
 *	@exception DevFailed
 */
	void	kill_motor(const Tango::DevVarShortArray *);
/**
 * Clear Geo amplifier fault display. (Geo PMAC only)
 *	@exception DevFailed
 */
	void	clear_amplif_fault();
/**
 * Global reset, including all motors & coordinate systems.
 *	@exception DevFailed
 */
	void	global_reset();
/**
 * Global reset & re-initialize controller card.
 *	@exception DevFailed
 */
	void	global_reset_reinit();
/**
 * Send a control character to the PMAC card & get its response, if any.
 *	@param	argin	Control character to send:\n A - abort all motion programs & moves\n D - disable all PLC & PLCC programs\n K - kill outputs for all motors\n L - close rotary program buffer\n O - do feed hold on all coordinate systems\n Q - quit all programs at end of calculated moves\n R - run working programs in all coordinate systems\n S - step working programs in all coordinate systems\n U - open rotary program buffer\n B - report all motor status words to host\n C - report all coordinate system status words to host\n F - report all motor following errors (unscaled)\n G - report global status words in binary form\n P - report all motor positions (unscaled)\n V - report all motor velocities (unscaled)
 *	@return	Command response from controller card, if any.
 *	@exception DevFailed
 */
	Tango::DevString	send_ctrl_char(Tango::DevString);
/**
 * Report global status.
 *	@return	Global status words in hex ASCII form.
 *	@exception DevFailed
 */
	Tango::DevString	global_status();
/**
 * Report current coordinate system status.
 *	@return	Coordinate system status in hex ASCII form.
 *	@exception DevFailed
 */
	Tango::DevString	coord_sys_status();
/**
 * Report the value of the I variable indicated in Command Argin.
 *	@param	argin	I variable number
 *	@return	I variable value
 *	@exception DevFailed
 */
	Tango::DevDouble	get_ivariable(Tango::DevULong);
/**
 * Set the I variable indicated in the first element of Command Argin to
 *	the value specified by the second element of Command Argin.
 *	@param	argin	I variable number, I variable value
 *	@exception DevFailed
 */
	void	set_ivariable(const Tango::DevVarDoubleArray *);
/**
 * Report the value of the M variable indicated in Command Argin.
 *	@param	argin	M variable number
 *	@return	M variable value
 *	@exception DevFailed
 */
	Tango::DevDouble	get_mvariable(Tango::DevULong);
/**
 * Set the M variable indicated in the first element of Command Argin to
 *	the value specified by the second element of Command Argin.
 *	@param	argin	M variable number, M variable value
 *	@exception DevFailed
 */
	void	set_mvariable(const Tango::DevVarDoubleArray *);
/**
 * Report the value of the P variable indicated in Command Argin.
 *	@param	argin	P variable number
 *	@return	P variable value
 *	@exception DevFailed
 */
	Tango::DevDouble	get_pvariable(Tango::DevULong);
/**
 * Report the values of the range of P variables indicated in Command Argin.
 *  @param  argin   P variable range start
 *  @param  argin   P variable range end
 *  @return P variable values
 *  @exception DevFailed
 */
        Tango::DevVarDoubleArray*    get_pvariablerange(const Tango::DevVarULongArray*);

/**
 * Set the P variable indicated in the first element of Command Argin to
 *	the value specified by the second element of Command Argin.
 *	@param	argin	P variable number, P variable value
 *	@exception DevFailed
 */
	void	set_pvariable(const Tango::DevVarDoubleArray *);
/**
 * Save I variables into non-volatile memory.
 *	@exception DevFailed
 */
	void	save_ivars();
/**
 * Download file to PMAC card.
 *	@param	argin	Name of the file to download to PMAC.
 *	@exception DevFailed
 */
	void	download_file(Tango::DevString);
/**
 * Upload variables from PMAC.
 *	@param	argin	Name of the file to save variables to.
 *	@exception DevFailed
 */
	void	upload_vars(Tango::DevString);
/**
 * Not implemented yet.
 *	@param	argin	Name of the file to upload program to.
 *	@exception DevFailed
 */
	void	upload_prog(Tango::DevString);
/**
 * Get current motor number.
 *	@return	Current motor number.
 *	@exception DevFailed
 */
	Tango::DevShort	get_motor_no();
/**
 * Set current motor number.
 *	@param	argin	Motor number.
 *	@exception DevFailed
 */
	void	set_motor_no(Tango::DevShort);
/**
 * Define a coordinate system for the current motor axis, specifying scale factor & offset.
 *	@param	argin	Scale factor, Offset
 *	@exception DevFailed
 */
	void	define_coord_sys(const Tango::DevVarDoubleArray *);
/**
 * Report axis definition of current motor in current coordinate system.
 *	@return	
 *	@exception DevFailed
 */
	Tango::DevString	get_coord_sys();

/**
 * Executes an online command on Pmac.
 *	@return	
 *	@exception DevFailed
 */
	Tango::DevString	online_cmd(Tango::DevString);

/**
 * Enables PLC on Pmac.
 *	@return	
 *	@exception DevFailed
 */
	void	enable_plc(Tango::DevShort);

/**
 * Disables PLC on Pmac.
 *	@return	
 *	@exception DevFailed
 */
	void	disable_plc(Tango::DevShort);

/**
 * Run motion program on Pmac.
 *	@return	
 *	@exception DevFailed
 */
	void	run_motion_prog(Tango::DevShort);

/**
 * Get motor position.
 *	@return	
 *	@exception DevFailed
 */
	Tango::DevDouble	get_motor_pos(Tango::DevShort);

/**
 * List PLC.
 *	@return	
 *	@exception DevFailed
 */
	Tango::DevVarStringArray*	list_plc(Tango::DevShort);


/**
 *	Read the device properties from database
 */
	 void get_device_property();
//@}

	//	Here is the end of the automatic code generation part
	//-------------------------------------------------------------	


static const char ctrl_char[26];


protected :	
	//	Add your own data members here
	//-----------------------------------------
  int sockfd;
};

}	// namespace_ns

#endif	// _PMACETH_H
