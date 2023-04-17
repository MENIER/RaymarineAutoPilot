#ifndef _RAYMARINE_PILOTE_H_
#define _RAYMARINE_PILOTE_H_
/*
RaymarinePilot.h

Copyright (c) 2023 MENIER Camille
base of works:
https://github.com/matztam/raymarine-evo-pilot-remote
https://github.com/sbender9/signalk-raymarine-autopilot

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


This is class for controlling Raymarine EVO autopilot.
*/
#define RAYMARINE_FULL_CODE

#include <NMEA2000.h>
#include <N2kMsg.h>
#include <N2kTypes.h>
#include <N2kMessages.h>
#include <N2kDeviceList.h>
#include <NMEA2000StdTypes.h>
#include <N2kGroupFunction.h>
#include <pgns_def.h>

//#define _OUTPUT_STREAM_NMEA

#ifdef _OUTPUT_STREAM_NMEA
#define _OUTPUT_STREAM serialNmea
#include <PrintNmea.h>
extern "C" PrintNmea serialNmea;
#else
#define _OUTPUT_STREAM Serial
#endif

#define PGN_BROADCAST 0

typedef unsigned char uint2_t;
typedef unsigned char uint3_t;
typedef unsigned char uint4_t;
typedef unsigned char uint5_t;
typedef uint16_t      uint11_t;
typedef uint32_t      uint24_t;

class RaymarinePilot {
public:

	enum tN2kSeatalkPilotModes {
		PILOT_MODE_STANDBY = 0x0000,//Standby
		PILOT_MODE_AUTO    = 0x0040,//compass commanded
		PILOT_MODE_WIND    = 0x0100,//Wind Mode
		PILOT_MODE_TRACK   = 0x0180,//Track Mode
		PILOT_MODE_TRACK1  = 0x0181 //No Drift, COG referenced (In track, course changes)
	};
	enum tN2kSeatalkPilotModesParse {
		Standby =0x40, //64 0x40
		Auto    =0x42, //66 0x42
		Wind    =0x46, //70
		Track   =74};
	enum tN2kSeatalkKeyCodes1 {
		KEY_PLUS_1           = 0x07f8,
		KEY_PLUS_10          = 0x08f7,
		KEY_MINUS_10         = 0x06f9,
		KEY_MINUS_1          = 0x05fa,
		KEY_MINUS_1_MINUS_10 = 0x21de,
		KEY_PLUS_1_PLUS_10   = 0x22dd,
		KEY_STANDBY          = 0xFD02,//not run?
		KEY_AUTO             = 0xFE01,//not run?
		KEY_TACK_PORTSIDE    = KEY_MINUS_1_MINUS_10,
		KEY_TACK_STARBORD    = KEY_PLUS_1_PLUS_10};
	enum tN2kSeatalkResponceLevel {
				leisure    = 0x01,
				cruising   = 0x02,
				performance = 0x03};
	enum tN2kSeatalkKeyCodes {
		EV_NO_EV_1_DETECTED     =-2,
		EV_PILOT_MODE_UNKNOW    =-1,
		EV_PILOT_RESPONCE_LEISURE=leisure,
		EV_PILOT_RESPONCE_CRUISING=cruising,
		EV_PILOT_RESPONCE_PERFORMANCE=performance,
		EV_PILOT_MODE_STANDBY   = PILOT_MODE_STANDBY,
		EV_PILOT_MODE_AUTO      = PILOT_MODE_AUTO,
		EV_PILOT_MODE_WIND      = PILOT_MODE_WIND,
		EV_PILOT_MODE_TRACK     = PILOT_MODE_TRACK,
		EV_PILOT_MODE_TRACK1    = PILOT_MODE_TRACK1,
		EV_KEY_PLUS_1           = KEY_PLUS_1,
		EV_KEY_PLUS_10          = KEY_PLUS_10,
		EV_KEY_MINUS_1          = KEY_MINUS_1,//0x05fa,
		EV_KEY_MINUS_10         = KEY_MINUS_10,//0x06f9
		EV_KEY_MINUS_1_MINUS_10 = KEY_MINUS_1_MINUS_10,//0x21de,
		EV_KEY_PLUS_1_PLUS_10   = KEY_PLUS_1_PLUS_10,//0x22dd,
		EV_KEY_TACK_PORTSIDE    = KEY_MINUS_1_MINUS_10,
		EV_KEY_TACK_STARBORD    = KEY_PLUS_1_PLUS_10};
	enum tN2kSeatalkAlarmGroupCodes {
		instrument   = 0x00,
		autopilot    = 0x01,
		radar        = 0x02,
		chartplotter = 0x03,
		ais          = 0x04	};

	enum tN2kSeatalkAlarmStatus {
		NotMet            = 0x00,
		MetAndNotSilenced = 0x01,
		MetAndSilenced    = 0x02,	};
	enum tN2kSeatalkAlarmId	{
		NoAlarm	                                    =	0	,// 0
		ShallowDepth	                            =	1	,// 1
		DeepDepth	                                =	2	,// 2
		ShallowAnchor	                            =	3	,// 3
		DeepAnchor	                                =	4	,// 4
		OffCourse	                                =	5	,// 5
		AWAHigh                                     =	6	,// 6
		AWALow                                      =   7	,// 7
		AWSHigh                                     =	8	,// 8
		AWSLow                                      =   9	,// 9
		TWAHigh                                     =	10	,// A
		TWALow                                      =   11	,// B
		TWSHigh                                     =	12	,// C
		TWSLow                                      =   13	,// D
		WPArrival	                                =	14	,// E
		BoatSpeedHigh	                            =	15	,// F
		BoatSpeedLow	                            =	16	,// 10
		SeaTempHigh	                                =	17	,// 11
		SeaTempLow	                                =	18	,// 12
		PilotWatch	                                =	19	,// 13
		PilotOffCourse	                            =	20	,// 14
		PilotWindShift	                            =	21	,// 15
		PilotLowBattery	                            =	22	,// 16
		PilotLastMinuteOfWatch	                    =	23	,// 17
		PilotNoNMEAData	                            =	24	,// 18
		PilotLargeXTE	                            =	25	,// 19
		PilotNMEADataError	                        =	26	,// 1A
		PilotCUDisconnected	                        =	27	,// 1B
		PilotAutoRelease	                        =	28	,// 1C
		PilotWayPointAdvance	                    =	29	,// 1D
		PilotDriveStopped	                        =	30	,// 1E
		PilotTypeUnspecified	                    =	31	,// 1F
		PilotCalibrationRequired                    =	32	,// 20
		PilotLastHeading	                        =	33	,// 21
		PilotNoPilot	                            =	34	,// 22
		PilotRouteComplete	                        =	35	,// 23
		PilotVariableText	                        =	36	,// 24
		GPSFailure	                                =	37	,// 25
		MOB	                                        =	38	,// 26
		Seatalk1Anchor	                            =	39	,// 27
		PilotSwappedMotorPower	                    =	40	,// 28
		PilotStandbyTooFastToFish	                =	41	,// 29
		PilotNoGPSFix	                            =	42	,// 2A
		PilotNoGPSCOG	                            =	43	,// 2B
		PilotStartUp	                            =	44	,// 2C
		PilotTooSlow	                            =	45	,// 2D
		PilotNoCompass	                            =	46	,// 2E
		PilotRateGyroFault	                        =	47	,// 2F
		PilotCurrentLimit	                        =	48	,// 30
		PilotWayPointAdvancePort	                =	49	,// 31
		PilotWayPointAdvanceStbd	                =	50	,// 32
		PilotNoWindData	                            =	51	,// 33
		PilotNoSpeedData	                        =	52	,// 34
		PilotSeatalkFail1	                        =	53	,// 35
		PilotSeatalkFail2	                        =	54	,// 36
		PilotWarningTooFastToFish	                =	55	,// 37
		PilotAutoDocksideFail	                    =	56	,// 38
		PilotTurnTooFast	                        =	57	,// 39
		PilotNoNavData	                            =	58	,// 3A
		PilotLostWaypointData	                    =	59	,// 3B
		PilotEEPROMCorrupt	                        =	60	,// 3C
		PilotRudderFeedbackFail	                    =	61	,// 3D
		PilotAutolearnFail1	                        =	62	,// 3E
		PilotAutolearnFail2	                        =	63	,// 3F
		PilotAutolearnFail3	                        =	64	,// 40
		PilotAutolearnFail4	                        =	65	,// 41
		PilotAutolearnFail5	                        =	66	,// 42
		PilotAutolearnFail6	                        =	67	,// 43
		PilotWarningCalRequired	                    =	68	,// 44
		PilotWarningOffCourse	                    =	69	,// 45
		PilotWarningXTE	                            =	70	,// 46
		PilotWarningWindShift	                    =	71	,// 47
		PilotWarningDriveShort	                    =	72	,// 48
		PilotWarningClutchShort	                    =	73	,// 49
		PilotWarningSolenoidShort	                =	74	,// 4A
		PilotJoystickFault	                        =	75	,// 4B
		PilotNoJoystickData	                        =	76	,// 4C
		notassigned0	                            =	77	,// 4D
		notassigned1	                            =	78	,// 4E
		notassigned2	                            =	79	,// 4F
		PilotInvalidCommand	                        =	80	,// 50
		AISTXMalfunction	                        =	81	,// 51
		AISAntennaVSWRfault	                        =	82	,// 52
		AISRxchannel1malfunction	                =	83	,// 53
		AISRxchannel2malfunction	                =	84	,// 54
		AISNosensorpositioninuse	                =	85	,// 55
		AISNovalidSOGinformation	                =	86	,// 56
		AISNovalidCOGinformation	                =	87	,// 57
		AIS12Valarm	                                =	88	,// 58
		AIS6Valarm	                                =	89	,// 59
		AISNoisethresholdexceededchannelA	        =	90	,// 5A
		AISNoisethresholdexceededchannelB	        =	91	,// 5B
		AISTransmitterPAfault	                    =	92	,// 5C
		AIS3V3alarm	                                =	93	,// 5D
		AISRxchannel70malfunction	                =	94	,// 5E
		AISHeadinglostInvalid	                    =	95	,// 5F
		AISinternalGPSlost	                        =	96	,// 60
		AISNosensorposition	                        =	97	,// 61
		AISLockfailure	                            =	98	,// 62
		AISInternalGGAtimeout	                    =	99	,// 63
		AISProtocolstackrestart	                    =	100	,// 64
		PilotNoIPScommunications	                =	101	,// 65
		PilotPowerOnorSleepSwitchResetWhileEngaged	=	102	,// 66
		PilotUnexpectedResetWhileEngaged	        =	103	,// 67
		AISDangerousTarget	                        =	104	,// 68
		AISLostTarget	                            =	105	,// 69
		AISSafetyRelatedMessage	                    =	106	,// 6A
		AISConnectionLost	                        =	107	,// 6B
		NoFix	                                    =	108  // 6C
	};

	void SetEvoPilotWind(tN2kMsg &N2kMsg, double targetWindDirection);
	void SetN2kPGN126208EvoPilotMode       (tN2kMsg &N2kMsg,uint8_t destinationAddress,
			tN2kSeatalkPilotModes mode);
	void SetN2kPGN126208EvoPilotCourse     (tN2kMsg &N2kMsg,uint8_t destinationAddress,
			double heading,
			int change);
	void SetN2kPGN126208TurnToWaypointMode (tN2kMsg &N2kMsg, uint8_t destinationAddress);
	void SetN2kPGN126208TurnToWaypoint     (tN2kMsg &N2kMsg, uint8_t destinationAddress);
	void SetN2kPGN126208PiloteResponse(tN2kMsg &N2kMsg, uint8_t destinationAddress,tN2kSeatalkResponceLevel level);
	void SetN2kPGN126720SeatalkKeyCommand  (tN2kMsg &N2kMsg, uint8_t destinationAddress,
			tN2kSeatalkKeyCodes1 command);
	void SetN2kSeatalkKeyCommand (tN2kMsg &N2kMsg, uint8_t destinationAddress,
			tN2kSeatalkKeyCodes key);
	void SetN2kPGN65288_SeatalkAlarm  (tN2kMsg &N2kMsg,uint8_t destinationAddress,
			tN2kSeatalkAlarmStatus     AlarmStatus,
			tN2kSeatalkAlarmId         AlarmId,
			tN2kSeatalkAlarmGroupCodes AlarmGroup);
	bool ParseN2kPGN65288_SeatalkAlarm(const tN2kMsg &N2kMsg,
			tN2kSeatalkAlarmStatus     &AlarmStatus,
			tN2kSeatalkAlarmId         &AlarmId,
			tN2kSeatalkAlarmGroupCodes &AlarmGroup);
	bool ParseN2kPGN65345_SeatalkPilotWindLockedDatum(const tN2kMsg &N2kMsg,
			double &WindAngle,
			double &RollingAverageWindAngle);
	void SetN2kPGN65361_SeatalkSilenceAlarm(tN2kMsg &N2kMsg, uint8_t destinationAddress,
			tN2kSeatalkAlarmId AlarmId,
			tN2kSeatalkAlarmGroupCodes AlarmGroup);
	bool ParseN2kPGN126720_Seatalk1PilotMode(const tN2kMsg &N2kMsg,
			tN2kSeatalkPilotModesParse &Mode,
			unsigned char &Submode);
	bool ParseN2kPGN127237_headingTrackControl(const tN2kMsg &N2kMsg,
			tN2kOnOff &rudderLimitExceeded,
			tN2kOnOff &offHeadingLimitExceeded,
			tN2kOnOff &offTrackLimitExceeded,
			tN2kOnOff &Override,
			tN2kSteeringMode &steeringMode,
			tN2kTurnMode &turnMode,
			tN2kHeadingReference &headingReference,
			uint5_t &reserved,
			tN2kRudderDirectionOrder &commandedRudderDirection,
			double &commandedRudderAngle,
			double &headingToSteerCourse,
			double &track,
			double &rudderLimit,
			double &offHeadingLimit,
			double &radiusOfTurnOrder,
			double &rateOfTurnOrder,
			int16_t &offTrackLimit,
			double &vesselHeading);
	bool ParseN2kPGN127237_headingTrackControl(const tN2kMsg &N2kMsg,
			double &commandedRudderAngle);
	bool ParseN2kPGN65359_SeatalkPilotHeading(const tN2kMsg &N2kMsg,
			/*uint8_t	&sid,*/
			double	&headingTrue,
			double	&headingMagnetic
	/*uint8_t	&reserved2*/		);
	//	16:09:46: $PMPGN,65359,Priority,7,Destination,255,Source,204
	//	16:09:46: $PCDIN,00FF4F,00041546,CC,3B9FFFFFFF44C1FF*5C
	//	16:09:46: $PMPGN,65360,Priority,7,Destination,255,Source,204
	//	16:09:46: $PCDIN,00FF50,0004154F,CC,3B9FFFFFFF41C1FF*5E
	bool ParseN2kPGN65360_SeatalkPilotLockedHeading (const tN2kMsg &N2kMsg,
			double	&headingTrue,
			double	&headingMagnetic);
	bool ParseN2kPGN65361_SeatalkSilenceAlarm(const tN2kMsg &N2kMsg,
			uint8_t &alarmId,
			uint8_t &alarmGroup,
			uint32_t &reserved2	);
	bool ParseN2kPGN65371SeatalkKeypadMessage(const tN2kMsg &N2kMsg,
			uint8_t &proprietaryId,
			uint8_t &firstKey,
			uint8_t &secondKey,
			uint2_t &firstKeyState,
			uint2_t &secondKeyState,
			uint4_t &reserved2,
			uint8_t &encoderPosition);
	bool ParseN2kPGN65374SeatalkKeypadHeartbeat(const tN2kMsg &N2kMsg,
			uint8_t &proprietaryId,
			uint8_t &variant,
			uint8_t &status	);
	bool ParseN2kPGN126208Nmea(const tN2kMsg &N2kMsg);
	bool ParseN2kPGN65379SeatalkPilotMode(const tN2kMsg &N2kMsg,
			tN2kSeatalkPilotModes &pilotMode,
			uint8_t	              &pilotModeData,
			uint24_t              &reserved2	);
	bool ParseN2kPGN127245_Rudder(const tN2kMsg &N2kMsg,
			double &RudderPositionRad,
			tN2kRudderDirectionOrder &RudderDirectionOrder, double &AngleOrder);

private:
	inline void SetN2kPGN126208 (tN2kMsg &N2kMsg,uint8_t destinationAddress,
			tN2kGroupFunctionCode function, unsigned long PGN);
	inline bool ParseN2kSeatalkPilotHeading(const tN2kMsg &N2kMsg,
			double	 &headingTrue,
			double	 &headingMagnetic);
#ifdef RAYMARINE_FULL_CODE
		inline bool  ParseHeader(const tN2kMsg &N2kMsg);
#endif


public:
	const char* N2kEnumTypeToStr(tN2kSeatalkAlarmStatus     enumVal);
	const char* N2kEnumTypeToStr(tN2kSeatalkAlarmId         enumVal);
	const char* N2kEnumTypeToStr(tN2kSeatalkAlarmGroupCodes enumVal);
	const char* N2kEnumTypeToStr(tN2kSeatalkPilotModes      enumVal);

private:
	const char* tN2kSeatalkPilotModesReferenceStrs[5] = {
			"STBY","AUTO","WIND","TRACK","N/A"};
	const char* tN2kSeatalkAlarmGroupCodesReferenceStrs[5]={
			"instrument"   ,
			"autoPilot"    ,
			"radar"        ,
			"chartPlotter" ,
			"ais"	};
	const char* tN2kSeatalkAlarmStatusReferenceStrs[3] ={
			"NotMet",
			"MetAndNotSilenced",
			"MetAndSilenced"   ,	};
	const char* tN2kSeatalkAlarmIdReferenceStrs[109] = {
			"NoAlarm",
			"ShallowDepth",
			"DeepDepth",
			"ShallowAnchor",
			"DeepAnchor",
			"OffCourse",
			"AWAHigh",
			"AWALow",
			"AWSHigh",
			"AWSLow",
			"TWAHigh",
			"TWALow",
			"TWSHigh",
			"TWSLow",
			"WPArrival",
			"BoatSpeedHigh",
			"BoatSpeedLow",
			"SeaTempHigh",
			"SeaTempLow",
			"PilotWatch",
			"PilotOffCourse",
			"PilotWindShift",
			"PilotLowBattery",
			"PilotLastMinuteOfWatch",
			"PilotNoNMEAData",
			"PilotLargeXTE",
			"PilotNMEADataError",
			"PilotCUDisconnected",
			"PilotAutoRelease",
			"PilotWayPointAdvance",
			"PilotDriveStopped",
			"PilotTypeUnspecified",
			"PilotCalibrationRequired",
			"PilotLastHeading",
			"PilotNoPilot",
			"PilotRouteComplete",
			"PilotVariableText",
			"GPSFailure",
			"MOB",
			"Seatalk1Anchor",
			"PilotSwappedMotorPower",
			"PilotStandbyTooFastToFish",
			"PilotNoGPSFix",
			"PilotNoGPSCOG",
			"PilotStartUp",
			"PilotTooSlow",
			"PilotNoCompass",
			"PilotRateGyroFault",
			"PilotCurrentLimit",
			"PilotWayPointAdvancePort",
			"PilotWayPointAdvanceStbd",
			"PilotNoWindData",
			"PilotNoSpeedData",
			"PilotSeatalkFail1",
			"PilotSeatalkFail2",
			"PilotWarningTooFastToFish",
			"PilotAutoDocksideFail",
			"PilotTurnTooFast",
			"PilotNoNavData",
			"PilotLostWaypointData",
			"PilotEEPROMCorrupt",
			"PilotRudderFeedbackFail",
			"PilotAutolearnFail1",
			"PilotAutolearnFail2",
			"PilotAutolearnFail3",
			"PilotAutolearnFail4",
			"PilotAutolearnFail5",
			"PilotAutolearnFail6",
			"PilotWarningCalRequired",
			"PilotWarningOffCourse",
			"PilotWarningXTE",
			"PilotWarningWindShift",
			"PilotWarningDriveShort",
			"PilotWarningClutchShort",
			"PilotWarningSolenoidShort",
			"PilotJoystickFault",
			"PilotNoJoystickData",
			"notAssigned",
			"notAssigned",
			"notAssigned",
			"PilotInvalidCommand",
			"AISTXMalfunction",
			"AISAntennaVSWRfault",
			"AISRxchannel1malfunction",
			"AISRxchannel2malfunction",
			"AISNosensorpositioninuse",
			"AISNovalidSOGinformation",
			"AISNovalidCOGinformation",
			"AIS12Valarm",
			"AIS6Valarm",
			"AISNoisethresholdexceededchannelA",
			"AISNoisethresholdexceededchannelB",
			"AISTransmitterPAfault",
			"AIS3V3alarm",
			"AISRxchannel70malfunction",
			"AISHeadinglost/invalid",
			"AISinternalGPSlost",
			"AISNosensorposition",
			"AISLockfailure",
			"AISInternalGGAtimeout",
			"AISProtocolstackrestart",
			"PilotNoIPScommunications",
			"PilotPower-OnorSleep-SwitchResetWhileEngaged",
			"PilotUnexpectedResetWhileEngaged",
			"AISDangerousTarget",
			"AISLostTarget",
			"AISSafetyRelatedMessage(usedtosilence)",
			"AISConnectionLost",
			"NoFix"};
};

#endif
