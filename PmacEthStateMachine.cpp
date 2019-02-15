/*----- PROTECTED REGION ID(PmacEthStateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        PmacEthStateMachine.cpp
//
// description : State machine file for the PmacEth class
//
// project :     PMAC over Ethernet
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================

#include <PmacEth.h>

/*----- PROTECTED REGION END -----*/	//	PmacEth::PmacEthStateMachine.cpp

//================================================================
//  States  |  Description
//================================================================
//  ON      |  PMAC - PC connection established.
//  OFF     |  PMAC - PC connection not set.


namespace PmacEth_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_Position_allowed()
 *	Description : Execution allowed for Position attribute
 */
//--------------------------------------------------------
bool PmacEth::is_Position_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for Position attribute in read access.
	/*----- PROTECTED REGION ID(PmacEth::PositionStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::PositionStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_Velocity_allowed()
 *	Description : Execution allowed for Velocity attribute
 */
//--------------------------------------------------------
bool PmacEth::is_Velocity_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for Velocity attribute in read access.
	/*----- PROTECTED REGION ID(PmacEth::VelocityStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::VelocityStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_FollowErr_allowed()
 *	Description : Execution allowed for FollowErr attribute
 */
//--------------------------------------------------------
bool PmacEth::is_FollowErr_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for FollowErr attribute in read access.
	/*----- PROTECTED REGION ID(PmacEth::FollowErrStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::FollowErrStateAllowed_READ
	return true;
}

//=================================================
//		Commands Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_OpenConnection_allowed()
 *	Description : Execution allowed for OpenConnection attribute
 */
//--------------------------------------------------------
bool PmacEth::is_OpenConnection_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::ON)
	{
	/*----- PROTECTED REGION ID(PmacEth::OpenConnectionStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::OpenConnectionStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_CloseConnection_allowed()
 *	Description : Execution allowed for CloseConnection attribute
 */
//--------------------------------------------------------
bool PmacEth::is_CloseConnection_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::CloseConnectionStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::CloseConnectionStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_AboutPmac_allowed()
 *	Description : Execution allowed for AboutPmac attribute
 */
//--------------------------------------------------------
bool PmacEth::is_AboutPmac_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::AboutPmacStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::AboutPmacStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_FirmwareInfo_allowed()
 *	Description : Execution allowed for FirmwareInfo attribute
 */
//--------------------------------------------------------
bool PmacEth::is_FirmwareInfo_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::FirmwareInfoStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::FirmwareInfoStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_GetIPaddr_allowed()
 *	Description : Execution allowed for GetIPaddr attribute
 */
//--------------------------------------------------------
bool PmacEth::is_GetIPaddr_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::GetIPaddrStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::GetIPaddrStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_SetIPaddr_allowed()
 *	Description : Execution allowed for SetIPaddr attribute
 */
//--------------------------------------------------------
bool PmacEth::is_SetIPaddr_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::SetIPaddrStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::SetIPaddrStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_JogPlus_allowed()
 *	Description : Execution allowed for JogPlus attribute
 */
//--------------------------------------------------------
bool PmacEth::is_JogPlus_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::JogPlusStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::JogPlusStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_JogMinus_allowed()
 *	Description : Execution allowed for JogMinus attribute
 */
//--------------------------------------------------------
bool PmacEth::is_JogMinus_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::JogMinusStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::JogMinusStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_JogStop_allowed()
 *	Description : Execution allowed for JogStop attribute
 */
//--------------------------------------------------------
bool PmacEth::is_JogStop_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::JogStopStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::JogStopStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_JogToPos_allowed()
 *	Description : Execution allowed for JogToPos attribute
 */
//--------------------------------------------------------
bool PmacEth::is_JogToPos_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::JogToPosStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::JogToPosStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_JogDistFromPos_allowed()
 *	Description : Execution allowed for JogDistFromPos attribute
 */
//--------------------------------------------------------
bool PmacEth::is_JogDistFromPos_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::JogDistFromPosStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::JogDistFromPosStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_JogDistFromCmdPos_allowed()
 *	Description : Execution allowed for JogDistFromCmdPos attribute
 */
//--------------------------------------------------------
bool PmacEth::is_JogDistFromCmdPos_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::JogDistFromCmdPosStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::JogDistFromCmdPosStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_GetFeedrateOverride_allowed()
 *	Description : Execution allowed for GetFeedrateOverride attribute
 */
//--------------------------------------------------------
bool PmacEth::is_GetFeedrateOverride_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::GetFeedrateOverrideStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::GetFeedrateOverrideStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_SetFeedrateOverride_allowed()
 *	Description : Execution allowed for SetFeedrateOverride attribute
 */
//--------------------------------------------------------
bool PmacEth::is_SetFeedrateOverride_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::SetFeedrateOverrideStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::SetFeedrateOverrideStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_ResetMotor_allowed()
 *	Description : Execution allowed for ResetMotor attribute
 */
//--------------------------------------------------------
bool PmacEth::is_ResetMotor_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::ResetMotorStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::ResetMotorStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_HomeMotor_allowed()
 *	Description : Execution allowed for HomeMotor attribute
 */
//--------------------------------------------------------
bool PmacEth::is_HomeMotor_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::HomeMotorStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::HomeMotorStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_HomeZeroMotor_allowed()
 *	Description : Execution allowed for HomeZeroMotor attribute
 */
//--------------------------------------------------------
bool PmacEth::is_HomeZeroMotor_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::HomeZeroMotorStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::HomeZeroMotorStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_KillMotor_allowed()
 *	Description : Execution allowed for KillMotor attribute
 */
//--------------------------------------------------------
bool PmacEth::is_KillMotor_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::KillMotorStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::KillMotorStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_ClearAmplifFault_allowed()
 *	Description : Execution allowed for ClearAmplifFault attribute
 */
//--------------------------------------------------------
bool PmacEth::is_ClearAmplifFault_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::ClearAmplifFaultStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::ClearAmplifFaultStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_GlobalReset_allowed()
 *	Description : Execution allowed for GlobalReset attribute
 */
//--------------------------------------------------------
bool PmacEth::is_GlobalReset_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::GlobalResetStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::GlobalResetStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_GlobalResetReinit_allowed()
 *	Description : Execution allowed for GlobalResetReinit attribute
 */
//--------------------------------------------------------
bool PmacEth::is_GlobalResetReinit_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::GlobalResetReinitStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::GlobalResetReinitStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_SendCtrlChar_allowed()
 *	Description : Execution allowed for SendCtrlChar attribute
 */
//--------------------------------------------------------
bool PmacEth::is_SendCtrlChar_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::SendCtrlCharStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::SendCtrlCharStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_GlobalStatus_allowed()
 *	Description : Execution allowed for GlobalStatus attribute
 */
//--------------------------------------------------------
bool PmacEth::is_GlobalStatus_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::GlobalStatusStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::GlobalStatusStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_CoordSysStatus_allowed()
 *	Description : Execution allowed for CoordSysStatus attribute
 */
//--------------------------------------------------------
bool PmacEth::is_CoordSysStatus_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::CoordSysStatusStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::CoordSysStatusStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_GetIVariable_allowed()
 *	Description : Execution allowed for GetIVariable attribute
 */
//--------------------------------------------------------
bool PmacEth::is_GetIVariable_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::GetIVariableStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::GetIVariableStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_SetIVariable_allowed()
 *	Description : Execution allowed for SetIVariable attribute
 */
//--------------------------------------------------------
bool PmacEth::is_SetIVariable_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::SetIVariableStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::SetIVariableStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_GetMVariable_allowed()
 *	Description : Execution allowed for GetMVariable attribute
 */
//--------------------------------------------------------
bool PmacEth::is_GetMVariable_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for GetMVariable command.
	/*----- PROTECTED REGION ID(PmacEth::GetMVariableStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::GetMVariableStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_SetMVariable_allowed()
 *	Description : Execution allowed for SetMVariable attribute
 */
//--------------------------------------------------------
bool PmacEth::is_SetMVariable_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for SetMVariable command.
	/*----- PROTECTED REGION ID(PmacEth::SetMVariableStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::SetMVariableStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_GetPVariable_allowed()
 *	Description : Execution allowed for GetPVariable attribute
 */
//--------------------------------------------------------
bool PmacEth::is_GetPVariable_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::GetPVariableStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::GetPVariableStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_GetPVariableRange_allowed()
 *	Description : Execution allowed for GetPVariableRange attribute
 */
//--------------------------------------------------------
bool PmacEth::is_GetPVariableRange_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for GetPVariableRange command.
	/*----- PROTECTED REGION ID(PmacEth::GetPVariableRangeStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::GetPVariableRangeStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_SetPVariable_allowed()
 *	Description : Execution allowed for SetPVariable attribute
 */
//--------------------------------------------------------
bool PmacEth::is_SetPVariable_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for SetPVariable command.
	/*----- PROTECTED REGION ID(PmacEth::SetPVariableStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::SetPVariableStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_SaveIVars_allowed()
 *	Description : Execution allowed for SaveIVars attribute
 */
//--------------------------------------------------------
bool PmacEth::is_SaveIVars_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::SaveIVarsStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::SaveIVarsStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_DownloadFile_allowed()
 *	Description : Execution allowed for DownloadFile attribute
 */
//--------------------------------------------------------
bool PmacEth::is_DownloadFile_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::DownloadFileStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::DownloadFileStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_UploadVars_allowed()
 *	Description : Execution allowed for UploadVars attribute
 */
//--------------------------------------------------------
bool PmacEth::is_UploadVars_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::UploadVarsStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::UploadVarsStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_UploadProg_allowed()
 *	Description : Execution allowed for UploadProg attribute
 */
//--------------------------------------------------------
bool PmacEth::is_UploadProg_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::UploadProgStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::UploadProgStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_GetMotorNo_allowed()
 *	Description : Execution allowed for GetMotorNo attribute
 */
//--------------------------------------------------------
bool PmacEth::is_GetMotorNo_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::GetMotorNoStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::GetMotorNoStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_SetMotorNo_allowed()
 *	Description : Execution allowed for SetMotorNo attribute
 */
//--------------------------------------------------------
bool PmacEth::is_SetMotorNo_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::SetMotorNoStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::SetMotorNoStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_DefineCoordSys_allowed()
 *	Description : Execution allowed for DefineCoordSys attribute
 */
//--------------------------------------------------------
bool PmacEth::is_DefineCoordSys_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::DefineCoordSysStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::DefineCoordSysStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_GetCoordSys_allowed()
 *	Description : Execution allowed for GetCoordSys attribute
 */
//--------------------------------------------------------
bool PmacEth::is_GetCoordSys_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::GetCoordSysStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::GetCoordSysStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_OnlineCmd_allowed()
 *	Description : Execution allowed for OnlineCmd attribute
 */
//--------------------------------------------------------
bool PmacEth::is_OnlineCmd_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::OnlineCmdStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::OnlineCmdStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_EnablePLC_allowed()
 *	Description : Execution allowed for EnablePLC attribute
 */
//--------------------------------------------------------
bool PmacEth::is_EnablePLC_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::EnablePLCStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::EnablePLCStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_DisablePLC_allowed()
 *	Description : Execution allowed for DisablePLC attribute
 */
//--------------------------------------------------------
bool PmacEth::is_DisablePLC_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::DisablePLCStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::DisablePLCStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_RunMotionProg_allowed()
 *	Description : Execution allowed for RunMotionProg attribute
 */
//--------------------------------------------------------
bool PmacEth::is_RunMotionProg_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::RunMotionProgStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::RunMotionProgStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_GetMotorPos_allowed()
 *	Description : Execution allowed for GetMotorPos attribute
 */
//--------------------------------------------------------
bool PmacEth::is_GetMotorPos_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::GetMotorPosStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::GetMotorPosStateAllowed
		return false;
	}
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : PmacEth::is_ListPLC_allowed()
 *	Description : Execution allowed for ListPLC attribute
 */
//--------------------------------------------------------
bool PmacEth::is_ListPLC_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Compare device state with not allowed states.
	if (get_state()==Tango::OFF)
	{
	/*----- PROTECTED REGION ID(PmacEth::ListPLCStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PmacEth::ListPLCStateAllowed
		return false;
	}
	return true;
}

}	//	End of namespace