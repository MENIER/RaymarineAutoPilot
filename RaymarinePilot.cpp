#include "RaymarinePilot.h"

#define _DEBUG_RAYMARINE_PILOT
#ifdef _DEBUG_RAYMARINE_PILOT
#define  DEBUG_ParseHeader
#define _DEBUG_ParsePGN126720_Seatalk1PilotMode
#define _DEBUG_ParseN2kPGN65361_seatalkSilenceAlarm
#define _DEBUG_ParseN2kPGN65288_SeatalkAlarm
#define _DEBUG_ParseN2kPGN126208seatalk
#define _DEBUG_ParseN2kPGN65359_SeatalkPilotHeading
#define _DEBUG_ParseN2kPGN65360_SeatalkPilotLockedHeading
#define _DEBUG_ParseN2kPGN127237_HeadingTrackControl
#define _DEBUG_RAYMARINE_PILOT_ParseN2kPGN65379SeatalkPilotMode
#define _DEBUG_ParseN2kPGN65345_SeatalkPilotWindLockedDatum
#endif

void RaymarinePilot::SetN2kPGN126208 (tN2kMsg &N2kMsg,uint8_t destinationAddress,
		tN2kGroupFunctionCode function, unsigned long PGN)
{
	N2kMsg.SetPGN(PGN126208_NmeaGeneral);
	N2kMsg.Priority = 3;
	N2kMsg.Destination = destinationAddress;
	N2kMsg.AddByte(function)   ;
	N2kMsg.Add3ByteInt(PGN);
}
//0163FF00F804013B07030404000005FFFF  //command     PGN FF63 65379 stdby
//0163FF00F804013B07030404000105FFFF  //command     PGN FF63 65379 wind
void RaymarinePilot::SetN2kPGN126208EvoPilotMode(tN2kMsg &N2kMsg,
		uint8_t destinationAddress, tN2kSeatalkPilotModes mode) {
	SetN2kPGN126208(
			N2kMsg,
			destinationAddress,
			N2kgfc_Command,
			PGN65379_SeatalkPilotMode);
	N2kMsg.AddByte(0xf8);//4 // priority + reserved Priority Setting
	N2kMsg.AddByte(0x04);//5 // 4 params //Number of Pairs of Commanded Parameters to follow
	N2kMsg.AddByte(0x01);//6 // first param - 1 of PGN 65379 (manufacturer code)
	N2kMsg.Add2ByteUInt(ManufacturersRegNumRaymarine);////0x073B
	N2kMsg.AddByte(0x03);//9 // second param -  3 of pgn 65369 (Industry code)
	N2kMsg.AddByte(0x04);//10// Ind. code 4
	N2kMsg.AddByte(0x04);//11// third parameter - 4 of pgn 65379 (mode)
	N2kMsg.Add2ByteUInt(mode);
	N2kMsg.AddByte(0x05);// value of weird raymarine param
	N2kMsg.AddByte(0xff);
	N2kMsg.AddByte(0xff);
}

void RaymarinePilot::SetN2kPGN126208EvoPilotCourse(tN2kMsg &N2kMsg, uint8_t destinationAddress, double heading, int change) {
	double course = heading + change;
	if ((course) >= 360) {
		course -= 360;
	} else if ((course) < 0) {
		course += 360;
	}

	uint16_t courseRadials10000 = (uint16_t) (DegToRad(course) * 10000); //(newCourse * 174.53);
	byte byte0, byte1;
	byte0 = courseRadials10000 & 0xff;
	byte1 = courseRadials10000 >> 8;

	//01,50,ff,00,f8,03,01,3b,07,03,04,06,00,00
	SetN2kPGN126208(
			N2kMsg,
			destinationAddress,
			N2kgfc_Command,
			PGN65360_SeatalkPilotLockedHeading);

	N2kMsg.AddByte(0xf8);//4    // priority + reserved   	N2kMsg.AddByte(0xf8);//4             N2kMsg.AddByte(0xf8);//4
	N2kMsg.AddByte(0x03);//5    // n params   	N2kMsg.AddByte(0x04);//5             N2kMsg.AddByte(0x04);//5
	N2kMsg.AddByte(0x01);//6     // param 1   	N2kMsg.AddByte(0x01);//6             N2kMsg.AddByte(0x01);//6
	N2kMsg.AddByte(0x3b);//7    // param 1    	N2kMsg.AddByte(0x3b);//7             N2kMsg.AddByte(0x3b);//7
	N2kMsg.AddByte(0x07);//8     // param 1   	N2kMsg.AddByte(0x07);//8             N2kMsg.AddByte(0x07);//8
	N2kMsg.AddByte(0x03);//9    // param 2    	N2kMsg.AddByte(0x03);//9             N2kMsg.AddByte(0x03);//9
	N2kMsg.AddByte(0x04);//10    // param 2       N2kMsg.AddByte(0x04);//10            N2kMsg.AddByte(0x04);//10
	N2kMsg.AddByte(0x06);//11    // param 3: heading
	N2kMsg.AddByte(byte0);//12   // param 3: heading
	N2kMsg.AddByte(byte1);       // param 3: heading
}

void RaymarinePilot::SetN2kPGN126208TurnToWaypointMode(tN2kMsg &N2kMsg, uint8_t destinationAddress) {
	//"01,63,ff,00,f8,04,01,3b,07,03,04,04,81,01,05,ff,ff"
	SetN2kPGN126208(
			N2kMsg,
			destinationAddress,
			N2kgfc_Command,
			PGN65379_SeatalkPilotMode);

	N2kMsg.AddByte(0xf8);//4 // priority + reserved
	N2kMsg.AddByte(0x04);//5 //
	N2kMsg.AddByte(0x01);//6
	N2kMsg.Add2ByteUInt(ManufacturersRegNumRaymarine);////0x073B
	N2kMsg.AddByte(0x03);//9
	N2kMsg.AddByte(0x04);//10
	N2kMsg.AddByte(0x04);//11
	N2kMsg.AddByte(0x81);//12
	N2kMsg.AddByte(0x01);
	N2kMsg.AddByte(0x05);
	N2kMsg.AddByte(0xff);
	N2kMsg.AddByte(0xff);
}
//0100EF01F805013B070304046C051950060300
//0100EF01F805013B070304046C051950060200
//0100EF01F805013B070304046C051950060100
//||command
//  | PGN|
//RESPONCES:
//126720    3B9F6C1950 01 00030001000200 7	204	0 leisure
//126720    3B9F6C1950 02 00030001000200 7	204	0
//126720	3B9F6C1950 03 00030001000200 7	204	0 performance
#define DEBUG_SetN2kPGN126208PiloteResponse
void RaymarinePilot::SetN2kPGN126208PiloteResponse(tN2kMsg &N2kMsg, uint8_t destinationAddress, tN2kSeatalkResponceLevel level)
{
#ifdef DEBUG_SetN2kPGN126208PiloteResponse
	_OUTPUT_STREAM.print(F("SetN2kPGN126208PiloteResponse:"));_OUTPUT_STREAM.println( level);
#endif
	SetN2kPGN126208(
			N2kMsg,
			destinationAddress,
			N2kgfc_Command,
			PGN126720_Seatalk1PilotMode);
	N2kMsg.Priority = 7;
	/*N2kMsg.AddByte(N2kgfc_Command);//N2kgfc_Command
	N2kMsg.AddByte(0x00);//PGN126720_Seatalk1PilotMode
	N2kMsg.AddByte(0xEF);//PGN126720_Seatalk1PilotMode
	N2kMsg.AddByte(0x01);//PGN126720_Seatalk1PilotMode*/
	N2kMsg.AddByte(0xF8);//
	N2kMsg.AddByte(0x05);//
	N2kMsg.AddByte(0x01);//
	N2kMsg.AddByte(0x3B);//N2kMsg.Add2ByteUInt(ManufacturersRegNumRaymarine);////0x073B
	N2kMsg.AddByte(0x07);//N2kMsg.Add2ByteUInt(ManufacturersRegNumRaymarine);////0x073B
	N2kMsg.AddByte(0x03);//N2kMsg.AddByte(0x03);
	N2kMsg.AddByte(0x04);//N2kMsg.AddByte(0x04);
	N2kMsg.AddByte(0x04);//N2kMsg.AddByte(0x04);
	N2kMsg.AddByte(0x6C);//N2kMsg.AddByte(0x6c);
	N2kMsg.AddByte(0x05);//N2kMsg.AddByte(0x05);
	N2kMsg.AddByte(0x19);//
	N2kMsg.AddByte(0x50);//
	N2kMsg.AddByte(0x06);//
	N2kMsg.AddByte(level);//
	N2kMsg.AddByte(0x00);//
}

void RaymarinePilot::SetN2kPGN126208TurnToWaypoint(tN2kMsg &N2kMsg, uint8_t destinationAddress) {
	//00,00,ef,01,ff,ff,ff,ff,ff,ff,04,01,3b,07,03,04,04,6c,05,1a,50"
	SetN2kPGN126208(
			N2kMsg,
			destinationAddress,
			N2kgfc_Request,
			PGN126720_Seatalk1PilotMode);
	N2kMsg.AddByte(0xff);//04//32 manufacturerCode
	N2kMsg.AddByte(0xff);//05
	N2kMsg.AddByte(0xff);//06//48 uniqueId
	N2kMsg.AddByte(0xff);//07//56 OfSelectionPairs
	N2kMsg.AddByte(0xff);//08//64 OfParameters
	N2kMsg.AddByte(0xff);//09//72 selectionParameter
	N2kMsg.AddByte(0x04);//10//80 selectionValue
	N2kMsg.AddByte(0x01);//11//88
	N2kMsg.Add2ByteUInt(ManufacturersRegNumRaymarine);////0x073B
	N2kMsg.AddByte(0x03);
	N2kMsg.AddByte(0x04);
	N2kMsg.AddByte(0x04);
	N2kMsg.AddByte(0x6c);
	N2kMsg.AddByte(0x05);
	N2kMsg.AddByte(0x1a);
	N2kMsg.AddByte(0x50);
}
void RaymarinePilot::SetN2kSeatalkKeyCommand (tN2kMsg &N2kMsg, uint8_t destinationAddress,
		tN2kSeatalkKeyCodes key)
{
	switch (key) {
	case EV_KEY_PLUS_1:
	case EV_KEY_MINUS_1:
	case EV_KEY_MINUS_10:
	case EV_KEY_PLUS_10:
	case EV_KEY_MINUS_1_MINUS_10:
	case EV_KEY_PLUS_1_PLUS_10:
		SetN2kPGN126720SeatalkKeyCommand(N2kMsg, destinationAddress,(tN2kSeatalkKeyCodes1)key);
		break;
	case EV_PILOT_MODE_AUTO:
	case EV_PILOT_MODE_STANDBY:
	case EV_PILOT_MODE_WIND:
	case EV_PILOT_MODE_TRACK:
	case EV_PILOT_MODE_TRACK1:
		SetN2kPGN126208EvoPilotMode(N2kMsg, destinationAddress,(tN2kSeatalkPilotModes)key);
		break;
	case EV_PILOT_RESPONCE_LEISURE:
	case EV_PILOT_RESPONCE_CRUISING:
	case EV_PILOT_RESPONCE_PERFORMANCE:
		SetN2kPGN126208PiloteResponse(N2kMsg, destinationAddress,(tN2kSeatalkResponceLevel)key);
		break;
	}
}

void RaymarinePilot::SetN2kPGN126720SeatalkKeyCommand(tN2kMsg &N2kMsg, uint8_t destinationAddress,
		tN2kSeatalkKeyCodes1 command) {
	//const key_command = "3b,9f,f0,81,86,21,%s,%s,ff,ff,ff,ff,ff,c1,c2,cd,66,80,d3,42,b1,c8"

	byte commandByte0, commandByte1;
	commandByte0 = command >> 8;
	commandByte1 = command & 0x00ff;

	N2kMsg.SetPGN(PGN126720_Seatalk1Keystroke);
	N2kMsg.Priority = 7;
	N2kMsg.Destination = destinationAddress;
	//N2kMsg.Add2ByteUInt(ManufacturersRegNumRaymarine);////0x073B
	N2kMsg.AddByte(0x3b);//1 manufacturerCode 11 bit//ManufacturersRegNumRaymarine
	N2kMsg.AddByte(0x9f);//2
	N2kMsg.AddByte(0xf0);//3 raymarine code
	N2kMsg.AddByte(0x81);//4
	N2kMsg.AddByte(0x86);//5  //command 134
	N2kMsg.AddByte(0x21);//6 <EnumPair Value='33' Name='S100' />//Télécommande sans fil S100
	N2kMsg.AddByte(commandByte0);//7
	N2kMsg.AddByte(commandByte1);
	N2kMsg.AddByte(0xff);//8
	N2kMsg.AddByte(0xff);//9
	N2kMsg.AddByte(0xff);//10
	N2kMsg.AddByte(0xff);//11
	N2kMsg.AddByte(0xff);//12
	N2kMsg.AddByte(0xc1);//13
	N2kMsg.AddByte(0xc2);//14
	N2kMsg.AddByte(0xcd);//15
	N2kMsg.AddByte(0x66);//16
	N2kMsg.AddByte(0x80);//17
	N2kMsg.AddByte(0xd3);//18
	N2kMsg.AddByte(0x42);//19
	N2kMsg.AddByte(0xb1);//20
	N2kMsg.AddByte(0xc8);//21
}


//19:05:36: $PPTXT,PGN,65288,seatalkAlarm,,Priority,7,Destination,255,Source,204*68
//19:05:36: $PPTXT,$PCDIN,00FF08,00000205,CC,3B9FFF011B010000*22*56
//19:05:36: $PPTXT,AlarmCode,PilotCUDisconnected,alarmGroup,Autopilot,AlarmStatus,MetAndNotSilenced*26
//19:05:36: $PPTXT,Alarm,alarmStatusHex,codeHEX,groupHEX,1,1B,0*3b
//19:05:36: $PPTXT,PGN,65288,seatalkAlarm,,Priority,7,Destination,255,Source,0*6e
//19:05:36: $PPTXT,$PCDIN,00FF08,00000215,00,3B9F00002200FF2D*26*56
//19:05:36: $PPTXT,AlarmCode,PilotNoPilot,alarmGroup,Instrument,AlarmStatus,NotMet*7e
//19:05:36: $PPTXT,Alarm,alarmStatusHex,codeHEX,groupHEX,0,22,1B*0a
//19:05:36: $PPTXT,PGN,65288,seatalkAlarm,,Priority,7,Destination,255,Source,204*68
//19:05:36: $PPTXT,$PCDIN,00FF08,0000022B,CC,3B9FFF001B010000*56*21
//19:05:36: $PPTXT,AlarmCode,PilotCUDisconnected,alarmGroup,Autopilot,AlarmStatus,NotMet*52
//19:05:36: $PPTXT,Alarm,alarmStatusHex,codeHEX,groupHEX,0,1B,22*0a
//19:05:37: $PPTXT,PGN,65288,seatalkAlarm,,Priority,7,Destination,255,Source,204*68
//19:05:37: $PPTXT,$PCDIN,00FF08,0000053B,CC,3B9FFF001B010000*50*21
//19:05:37: $PPTXT,AlarmCode,PilotCUDisconnected,alarmGroup,Autopilot,AlarmStatus,NotMet*52
//19:05:37: $PPTXT,Alarm,alarmStatusHex,codeHEX,groupHEX,0,1B,1B*79
//19:05:37: $PPTXT,Ok model:Raymarine EV-1 Course Computer,detected name is: *65
//19:05:37: $PPTXT,Stations connected,0*10
//19:05:38: $PPTXT,PGN,65288,seatalkAlarm,,Priority,7,Destination,255,Source,204*68
//19:05:38: $PPTXT,$PCDIN,00FF08,0000098D,CC,3B9FFF001B010000*51*21
//19:05:38: $PPTXT,AlarmCode,PilotCUDisconnected,alarmGroup,Autopilot,AlarmStatus,NotMet*52
//19:05:38: $PPTXT,Alarm,alarmStatusHex,codeHEX,groupHEX,0,1B,1B*79
//19:05:39: $PPTXT,PGN,65288,seatalkAlarm,,Priority,7,Destination,255,Source,204*68
//19:05:39: $PPTXT,$PCDIN,00FF08,00000DD0,CC,3B9FFF001B010000*24*56
//19:05:39: $PPTXT,AlarmCode,PilotCUDisconnected,alarmGroup,Autopilot,AlarmStatus,NotMet*52
//19:05:39: $PPTXT,Alarm,alarmStatusHex,codeHEX,groupHEX,0,1B,1B*79
//19:05:39: $PPTXT,Stations connected,0*10
//19:05:40: $PPTXT,PGN,65288,seatalkAlarm,,Priority,7,Destination,255,Source,204*68
//19:05:40: $PPTXT,$PCDIN,00FF08,000011B8,CC,3B9FFF001B010000*5E*5a
//19:05:40: $PPTXT,AlarmCode,PilotCUDisconnected,alarmGroup,Autopilot,AlarmStatus,NotMet*52
//19:05:40: $PPTXT,Alarm,alarmStatusHex,codeHEX,groupHEX,0,1B,1B*79
//19:01:09: $PPTXT,PGN,65288,seatalkAlarm,,Priority,7,Destination,255,Source,204*68
//19:01:09: $PPTXT,$PCDIN,00FF08,0002A355,CC,3B9FFF0114010000*23*56
//19:01:09: $PPTXT,AlarmCode,PilotOffCourse,alarmGroup,Autopilot,AlarmStatus,MetAndNotSilenced*63

bool RaymarinePilot::ParseN2kPGN65288_SeatalkAlarm(const tN2kMsg &N2kMsg,
		tN2kSeatalkAlarmStatus     &alarmStatus,
		tN2kSeatalkAlarmId         &alarmId,
		tN2kSeatalkAlarmGroupCodes &alarmGroup) {
	if (N2kMsg.PGN != PGN65288_SeatalkAlarm) return false;
	int Index = 0;
	Index=3;
	alarmStatus= (tN2kSeatalkAlarmStatus    )N2kMsg.GetByte(Index);
	//	Index = 4;
	alarmId    = (tN2kSeatalkAlarmId        )N2kMsg.GetByte(Index);
	//	Index = 5;
	alarmGroup = (tN2kSeatalkAlarmGroupCodes)N2kMsg.GetByte(Index);
#if defined(_DEBUG_ParseN2kPGN65288_SeatalkAlarm)
	_OUTPUT_STREAM.print(F("alarmId:"    ));_OUTPUT_STREAM.println(N2kEnumTypeToStr(alarmId    ));
	_OUTPUT_STREAM.print(F("alarmGroup:" ));_OUTPUT_STREAM.println(N2kEnumTypeToStr(alarmGroup ));
	_OUTPUT_STREAM.print(F("alarmStatus:"));_OUTPUT_STREAM.println(N2kEnumTypeToStr(alarmStatus));
	_OUTPUT_STREAM.print(F("Alarm,alarmStatusHex,codeHEX,groupHEX"));
	_OUTPUT_STREAM.print(alarmStatus, HEX);
	_OUTPUT_STREAM.print(alarmId, HEX);
	_OUTPUT_STREAM.println(alarmGroup, HEX);
#endif
	return true;
}
//0000EF01FFFFFFFFFFFF04013B070304046C051A50
//0163FF00F804013B07030404000005FFFF  //command     PGN FF63 65379
//0163FF00F804013B07030404000105FFFF  //command     PGN FF63 65379
//0263FF0000040000                    //Acknowledge PGN FF63 65379
//0141FF00F803013B070304043937        //command     PGN FF63 65345
//0241FF00000300F0                    //Acknowledge PGN FF63 65345
//0141FF00F803013B                    //command     PGN FF63 65345
//0241FF00000300F0                    //Acknowledge PGN FF63 65345
//0263FF0000040000                    //Acknowledge PGN FF63 65379
//||functionCode
//  |PGN |F8  01
//          xx      030404
//              3B07 raymarine id
bool RaymarinePilot::ParseN2kPGN126208Nmea(const tN2kMsg &N2kMsg)
{
	int Index=0;//functionCode
	uint16_t piloteMode;
	uint32_t pgn;
	uint16_t manufacturerCode;
	uint8_t uniqueId;
	uint8_t OfSelectionPairs;
	Index=0;
	tN2kGroupFunctionCode functionCode	  = (tN2kGroupFunctionCode)N2kMsg.GetByte(Index);
	Index= 1; pgn             = N2kMsg.Get3ByteUInt(Index);
	switch (functionCode)
	{
	case N2kgfc_Command:
		uint16_t code             = N2kMsg.Get2ByteUInt(Index);
		manufacturerCode          = code&0x07FF;
		Index= 6; uniqueId        = N2kMsg.GetByte(Index);
		Index= 7; OfSelectionPairs= N2kMsg.GetByte(Index);
		Index=12; piloteMode      = N2kMsg.Get2ByteUInt(Index);
		break;
	}

	return false;
}

// Set Seatalk Alarm State
void RaymarinePilot::SetN2kPGN65288_SeatalkAlarm(tN2kMsg &N2kMsg,
		uint8_t                    destinationAddress,
		tN2kSeatalkAlarmStatus     AlarmStatus,
		tN2kSeatalkAlarmId         AlarmId,
		tN2kSeatalkAlarmGroupCodes AlarmGroup) {
	N2kMsg.SetPGN(PGN65288_SeatalkAlarm);
	N2kMsg.Priority = 3;
	N2kMsg.Destination = destinationAddress;
	N2kMsg.AddByte(0xe7);  // Binary; 011100111011 00 100
	N2kMsg.AddByte(0x64);
	N2kMsg.AddByte(0x00);  // SID
	N2kMsg.AddByte(AlarmStatus); // Alarm State
	N2kMsg.AddByte(AlarmId);    // Alarm ID
	N2kMsg.AddByte(AlarmGroup); // Alarm Group
	N2kMsg.AddByte(0x00);       // Alarm Priority (0)
	N2kMsg.AddByte(0x01);       // Alarm Priority (1)
}

// Seatalk Silence Alarm
//const raymarine_silence =  "%s,7,65361,%s,255,8,3b,9f,%s,%s,00,00,00,00"
//3B9F140100000000
void RaymarinePilot::SetN2kPGN65361_SeatalkSilenceAlarm(tN2kMsg &N2kMsg,
		uint8_t destinationAddress,
		tN2kSeatalkAlarmId AlarmId,
		tN2kSeatalkAlarmGroupCodes AlarmGroup) {
	N2kMsg.SetPGN(PGN65361_SeatalkSilenceAlarm);
	N2kMsg.Priority = 7;
	N2kMsg.Destination = 255;//destinationAddress;//Broadcast
	//ManufacturersRegNumRaymarine 0x073B 0x9F3B
	N2kMsg.AddByte(0x3b);//N2kMsg.AddByte(0xe7);  // Binary; 011100111011 00 100 //byte 0
	N2kMsg.AddByte(0x9f);//N2kMsg.AddByte(0x64);                                 //byte 1
	N2kMsg.AddByte(AlarmId);  // Alarm ID
	N2kMsg.AddByte(AlarmGroup); // Alarm Group
	N2kMsg.AddByte(0x00);
	N2kMsg.AddByte(0x00);
	N2kMsg.AddByte(0x00);
	N2kMsg.AddByte(0x00);
}
//3B9F 6C19 50 03 00030001000200  //Pilote responce sensibility responce
//3B9F 6C19 50 02 00030001000200  //Pilote responce sensibility responce
//3B9F F081 84 B6C516 40 00130205 //Pilote mode 40 STBY
//3B9F F081 84 36C71C 40 00090205 //Pilote mode 40 STBY
//3B9F F081 84 76C71D 40 00090205 //Pilote mode 40 STBY
//3B9F F081 AE 02000CA5
//3B9F F081 9C 310709
//3B9F F081 9C 710709
//3B9F F081 90 0003
//3B9F F081 90 1005
//3B9F F081 A4 5612030179E00800
bool RaymarinePilot::ParseN2kPGN126720_Seatalk1PilotMode(const tN2kMsg &N2kMsg,
		tN2kSeatalkPilotModesParse &pilotMode,
		unsigned char &subMode) {
	if (N2kMsg.PGN != PGN126720_Seatalk1PilotMode) return false;
	//3B9F
#ifdef RAYMARINE_FULL_CODE
	bool isOk =ParseHeader(N2kMsg);
#endif
	int Index=2;
	uint16_t proprietaryId  =N2kMsg.Get2ByteUInt(Index);//81F0//<Match>33264</Match> <Description>0x81f0</Description>
	uint8_t command         =N2kMsg.GetByte(Index);

#ifdef _DEBUG_ParsePGN126720_Seatalk1PilotMode
	_OUTPUT_STREAM.print(",proprietaryId,"+String((proprietaryId,HEX)));//<Match>33264</Match> <Description>0x81f0</Description>
	_OUTPUT_STREAM.print(",command,"+String((command,HEX)));
#endif

	if(proprietaryId==0x196C)
	{
		if(command==0x50)
		{
			signed char levelResponce=N2kMsg.GetByte(Index);
			_OUTPUT_STREAM.print(F("levelResponce:"));_OUTPUT_STREAM.println(levelResponce);
		}
	}
	//0 1 2 3 4 5 6 7 8 9 0
	//3B9FF0818436C61846001B0205 //WIND
	//3B9FF0818476C5154000130205
	//    81f0
	//        84
	//                MODE
	else if(proprietaryId==33264/*0x81f0*/)
		if(command==0x84)//132
		{
			Index=5;
			double value=N2kMsg.Get3ByteUInt(Index); //24 bit sensor??
			Index=8;
			pilotMode=(tN2kSeatalkPilotModesParse)N2kMsg.GetByte(Index);
			subMode  =N2kMsg.GetByte(Index);
#ifdef  _DEBUG_ParsePGN126720_Seatalk1PilotMode
			switch(pilotMode)
			{
			//_OUTPUT_STREAM.println("PiloteMode,"+N2kEnumTypeToStr(pilotMode)  );
			case Standby   : _OUTPUT_STREAM.println("Standby"   );break;
			case Auto      : _OUTPUT_STREAM.println("Auto"      );break;
			case Wind      : _OUTPUT_STREAM.println("Wind"      );break;
			case Track     : _OUTPUT_STREAM.println("Track"     );break;
			}
#endif
#ifdef RAYMARINE_FULL_CODE
			return isOk;
#else
			return true;
#endif
		}
	//0 1 2 3 4 5 6 7 8
	//3B9FF081AE02030CA5 //WIND
	//3B9FF081AE02000CA5 //STBY
#ifdef EXPERIMENTAL_ParseN2kPGN126720_Seatalk1PilotModeAE
		else if (command==0xAE)
		{
			Index=6;
			pilotMode=N2kMsg.GetByte(Index);
			//00 STBY 03 Wind
		}
#endif
#ifdef EXPERIMENTAL_ParseN2kPGN126720_Seatalk1PilotMode9C
		else if (command==0x9C)
		{
			pilotMode=N2kMsg.GetByte(Index);
			//discretes values 71,31,F1,B1
			analogue value=N2kMsg.GetByte(Index);
			//discretes values 06,05
		}
#endif
#ifdef  _DEBUG_ParsePGN126720_Seatalk1PilotMode
	_OUTPUT_STREAM.println(",Unknow"   );
#endif
	return false;
	//	commande F0 rare touch key?
	//	3B9FF0817F018E8F
	//	3B9FF0817F018E8E
	//	3B9FF0817F018E8E
	//	3B9FF0817F018E8E
	//	3B9FF0817F018E8D
	//	3B9FF0817F017A8D
	//	3B9FF0817F017A8D
	//	3B9FF0817F017A8D
	//	3B9FF0817F01668D
	//	3B9FF0817F01668D
	//	3B9FF0817F01668D
	//	3B9FF0817F01668D

}
bool RaymarinePilot::ParseN2kPGN127237_headingTrackControl(const tN2kMsg &N2kMsg,
		double &commandedRudderAngle){
	tN2kOnOff rudderLimitExceeded;
	tN2kOnOff offHeadingLimitExceeded;
	tN2kOnOff offTrackLimitExceeded;
	tN2kOnOff Override;
	tN2kSteeringMode steeringMode;
	tN2kTurnMode turnMode;
	tN2kHeadingReference headingReference;
	uint5_t reserved;
	tN2kRudderDirectionOrder commandedRudderDirection;
	double headingToSteerCourse;
	double track;
	double rudderLimit;
	double offHeadingLimit;
	double radiusOfTurnOrder;
	double rateOfTurnOrder;
	int16_t offTrackLimit;
	double vesselHeading;
	ParseN2kPGN127237_headingTrackControl(N2kMsg,
			rudderLimitExceeded,
			offHeadingLimitExceeded,
			offTrackLimitExceeded,
			Override,
			steeringMode,
			turnMode,
			headingReference,
			reserved,
			commandedRudderDirection,
			commandedRudderAngle,
			headingToSteerCourse,
			track,
			rudderLimit,
			offHeadingLimit,
			radiusOfTurnOrder,
			rateOfTurnOrder,
			offTrackLimit,
			vesselHeading);
	if(steeringMode==N2kSM_FollowUpDevice)
	{
#ifdef _DEBUG_RAYMARINE_PILOT
		Serial.print(F("commandedRudderAngle:"));Serial.println( RadToDeg(commandedRudderAngle));
#endif
		return true;
	}
#ifdef _DEBUG_RAYMARINE_PILOT
	Serial.println(F("commandedRudderAngle:Unknow"));
#endif
	return false;
}
//$PMPGN,127237,Priority,2,Destination,255,Source,172
//                                             0011223344
//PGNReceived:127237,$PCDIN,01F105,00000045,AC,3CC21FE3F2FFFFFFFFFFFFFFFFFF7FFF7FFF7FFFFF*25
//if N2kSM_FollowUpDevice commandedRudderAngle is ok
bool RaymarinePilot::ParseN2kPGN127237_headingTrackControl(const tN2kMsg &N2kMsg,
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
		double &vesselHeading)
{
	if (N2kMsg.PGN != PGN127237_HeadingTrackControl) return false;

	int Index=0;
	byte value;
	value=N2kMsg.GetByte(Index);
	//3C C2 1F 480D FFFFFFFFFFFFFFFFFF7FFF7FFF7FFFFF //Autopilot
	//3C C0 1F FF7F FFFFFFFFFFFFFFFFFF7FFF7FFF7FFFFF //SDBY

	rudderLimitExceeded    =(tN2kOnOff) (value& 0x00000011);
	offHeadingLimitExceeded=(tN2kOnOff)((value& 0x00001100)>>2);
	offTrackLimitExceeded  =(tN2kOnOff)((value& 0x00110000)>>4);
	Override               =(tN2kOnOff)(value>>6);
	//C0 stby C2 autopilot 11 000 000=>11 000 010
	value=N2kMsg.GetByte(Index);
	steeringMode           =(tN2kSteeringMode)     (value& 0b00000111);
	turnMode               =(tN2kTurnMode)        ((value& 0b00111000)>>3);
	headingReference       =(tN2kHeadingReference)(value>>6);
	value=N2kMsg.GetByte(Index);
	reserved               =(value& 0b00011111);
	commandedRudderDirection=(tN2kRudderDirectionOrder)(value>>5);
	commandedRudderAngle	=N2kMsg.Get2ByteDouble(0.0001,Index);
	headingToSteerCourse	=N2kMsg.Get2ByteUDouble(0.0001,Index);
	track					=N2kMsg.Get2ByteUDouble(0.0001,Index);
	rudderLimit				=N2kMsg.Get2ByteUDouble(0.0001,Index);
	offHeadingLimit			=N2kMsg.Get2ByteUDouble(0.0001,Index);
	radiusOfTurnOrder		=N2kMsg.Get2ByteDouble(0.0001,Index);
	rateOfTurnOrder			=N2kMsg.Get2ByteDouble(3.125e-05,Index);//rad/s
	offTrackLimit			=N2kMsg.Get2ByteUInt(Index);//meter
	vesselHeading			=N2kMsg.Get2ByteUDouble(0.0001,Index);
	//	#define _DEBUG_RAYMARINE_PILOT_PGN127237_HeadingTrackControl
#ifdef _DEBUG_RAYMARINE_PILOT_PGN127237_HeadingTrackControl
	_OUTPUT_STREAM.println("rudderLimitExceeded:"+String(rudderLimitExceeded));
	_OUTPUT_STREAM.println("offHeadingLimitExceeded:"+String(offHeadingLimitExceeded));
	_OUTPUT_STREAM.println("offTrackLimitExceeded:"+String(offTrackLimitExceeded));
	_OUTPUT_STREAM.println("override:"+String(Override));
	_OUTPUT_STREAM.println("steeringMode:"+String(steeringMode));
	_OUTPUT_STREAM.println("turnMode:"+String(turnMode));
	_OUTPUT_STREAM.println("headingReference:"+String(headingReference));
	_OUTPUT_STREAM.println("reserved:"+String(reserved));
	_OUTPUT_STREAM.println("commandedRudderDirection:"+String(RadToDeg(commandedRudderDirection)));
	_OUTPUT_STREAM.println(
			",commandedRudderAngle,"+String(RadToDeg(commandedRudderAngle))
			+",headingToSteerCourse,"+String(RadToDeg(headingToSteerCourse))
			+",track,"+String(RadToDeg(track))
			+",rudderLimit,"+String(RadToDeg(rudderLimit))
			+",offHeadingLimit,"+String(RadToDeg(offHeadingLimit))
			+",radiusOfTurnOrder,"+String(RadToDeg(radiusOfTurnOrder))
			+",rateOfTurnOrder,"+String(RadToDeg(rateOfTurnOrder))
			+",offTrackLimit,"+String(RadToDeg(offTrackLimit))
			+",vesselHeading,"+String(RadToDeg(vesselHeading))) ;
#endif

	return true;
}
bool RaymarinePilot::ParseN2kPGN65360_SeatalkPilotLockedHeading (const tN2kMsg &N2kMsg,
		double	&headingTrue,
		double	&headingMagnetic)
{
	//uint8_t	sid;
	//uint8_t	reserved2;
	if (N2kMsg.PGN !=PGN65360_SeatalkPilotLockedHeading) return false;
	return ParseN2kSeatalkPilotHeading(N2kMsg,
			/*sid,*/
			headingTrue,
			headingMagnetic
	/*reserved2*/		);
}

//3B9F6830AD30FAFF
bool RaymarinePilot::ParseN2kPGN65345_SeatalkPilotWindLockedDatum(
		const tN2kMsg &N2kMsg, double &WindAngle,
		double &RollingAverageWindAngle) {
	if (N2kMsg.PGN != PGN65345_SeatalkPilotWindDatum)
		return false;
	//Index = 0;3B9F
	int Index = 2;
	WindAngle               = N2kMsg.Get2ByteDouble(0.0001, Index);
	RollingAverageWindAngle = N2kMsg.Get2ByteDouble(0.0001, Index);
#ifdef _DEBUG_ParseN2kPGN65345_SeatalkPilotWindLockedDatum
	Serial.print(F("WindAngle:"));Serial.println( RadToDeg(WindAngle));
	Serial.print(F("RollingAverageWindAngle:"));Serial.println( RadToDeg(RollingAverageWindAngle));
#endif
	return true;
}
//3B9FFFFFFFDBBFFF7
bool RaymarinePilot::ParseN2kPGN65359_SeatalkPilotHeading(const tN2kMsg &N2kMsg,
		double	&headingTrue,
		double	&headingMagnetic){
	if (N2kMsg.PGN !=PGN65359_SeatalkPilotHeading) return false;
	return ParseN2kSeatalkPilotHeading(N2kMsg,
			headingTrue,
			headingMagnetic);
}

//15:29:48: $PMPGN,65359,Priority,7,Destination,255,Source,204
//                                    0 1 2 3 4 5
//15:29:48: $PCDIN,00FF4F,0006BABA,CC,3B9FFFFFFF57BFFF*2C
//          $PCDIN,00FF4F,00000672,CC,3B9FFFFFFFD6C1FF*2F
//       D6C1  54977
//F57B=>7BF5= 31733=>3.1733rds=>181,816697129degrees
bool RaymarinePilot::ParseN2kSeatalkPilotHeading(const tN2kMsg &N2kMsg,
		double	&headingTrue,
		double	&headingMagnetic){
#ifdef _DEBUG_ParseN2kPGN65360_SeatalkPilotLockedHeading
	uint8_t	id;
	uint8_t	reserved2;
#endif
	int Index=0;
#ifdef RAYMARINE_FULL_CODE
	bool isOk=ParseHeader(N2kMsg);
#endif

#ifdef _DEBUG_ParseN2kPGN65360_SeatalkPilotLockedHeading
	id= N2kMsg.GetByte(Index);
#endif
	Index=3;	headingTrue 	=N2kMsg.Get2ByteUDouble(0.0001,Index);
	Index=5;	headingMagnetic	=N2kMsg.Get2ByteUDouble(0.0001,Index);
#ifdef _DEBUG_ParseN2kPGN65360_SeatalkPilotLockedHeading
	Index=7;	reserved2	    =N2kMsg.Get2ByteUDouble(0.0001,Index);
	/*if(N2kMsg.PGN==PGN65359_SeatalkPilotHeading)
		_OUTPUT_STREAM.print("PGN65359_SeatalkPilotHeading");
	if(N2kMsg.PGN==PGN65360_SeatalkPilotLockedHeading)
		_OUTPUT_STREAM.print("PGN65360_SeatalkPilotLockedHeading");*/
	//Index=5;_OUTPUT_STREAM.print(",Byte0-1,0x"+String(N2kMsg.GetByte(Index),HEX)+",0x"+String(N2kMsg.GetByte(Index),HEX));_OUTPUT_STREAM.println():
	_OUTPUT_STREAM.print(",headingMagnetic,"+String(RadToDeg(headingMagnetic)));
	_OUTPUT_STREAM.print(",headingTrue,"+String(RadToDeg(headingTrue)));
	_OUTPUT_STREAM.print(",reserved,"+String((reserved2)));
	_OUTPUT_STREAM.println();
#endif
#ifdef RAYMARINE_FULL_CODE
	return(isOk);
#else
	return true;
#endif

}

bool RaymarinePilot::ParseN2kPGN65361_SeatalkSilenceAlarm(const tN2kMsg &N2kMsg,
		uint8_t &alarmId,
		uint8_t &alarmGroup,
		uint32_t &reserved2){
	if (N2kMsg.PGN !=PGN65361_SeatalkSilenceAlarm) return false;
	int Index;
	uint16_t code;
#ifdef RAYMARINE_FULL_CODE
	bool isOk=ParseHeader(N2kMsg);
#endif


	Index=2; alarmId  	= N2kMsg.GetByte     (Index);
	Index=3; alarmGroup	= N2kMsg.GetByte     (Index);
	Index=4; reserved2  = N2kMsg.Get4ByteUInt(Index);

#if defined(_DEBUG_ParseN2kPGN65361_SeatalkSilenceAlarm)
	_OUTPUT_STREAM.print("alarmId,"+String((alarmId)));
	_OUTPUT_STREAM.print("alarmGroup,"+String((alarmGroup)));
	_OUTPUT_STREAM.print("reserved,"+String((reserved2)));
#endif

#ifdef DEBUG_RaymarinePilot::ParseN2kPGN65361_SeatalkSilenceAlarm
	return isOk;
#else
	return true;
#endif
}

bool RaymarinePilot::ParseN2kPGN65371SeatalkKeypadMessage(const tN2kMsg &N2kMsg,
		uint8_t &proprietaryId,
		uint8_t &firstKey,
		uint8_t &secondKey,
		uint2_t &firstKeyState,
		uint2_t &secondKeyState,
		uint4_t &reserved2,
		uint8_t &encoderPosition)
{
	if (N2kMsg.PGN !=PGN65371_SeatalkKeypadMessage) return false;
	int Index=0;
	uint16_t code=N2kMsg.Get2ByteUInt(Index);
#ifdef RAYMARINE_FULL_CODE
	bool isOk=ParseHeader(N2kMsg);
#endif

	Index=2;
	proprietaryId	= N2kMsg.GetByte(Index);
	firstKey	    = N2kMsg.GetByte(Index);
	secondKey	    = N2kMsg.GetByte(Index);
	firstKeyState	= N2kMsg.GetByte(Index);
	secondKeyState	= N2kMsg.GetByte(Index);
	reserved2	    = N2kMsg.GetByte(Index);
	encoderPosition	= N2kMsg.GetByte(Index);
#ifdef _DEBUG_RAYMARINE_PILOT
	_OUTPUT_STREAM.print("proprietaryId,"+String((proprietaryId)));
	_OUTPUT_STREAM.print("firstKey,"+String((firstKey)));
	_OUTPUT_STREAM.print("secondKey,"+String((secondKey)));
	_OUTPUT_STREAM.print("firstKeyState,"+String((firstKeyState)));
	_OUTPUT_STREAM.print("secondKeyState,"+String((secondKeyState)));
	_OUTPUT_STREAM.print("reserved,"+String((reserved2)));
	_OUTPUT_STREAM.print("encoderPosition,"+String((encoderPosition)));
#endif
#ifdef RAYMARINE_FULL_CODE
	return isOk;
#else
	return true;
#endif

}
bool RaymarinePilot::ParseN2kPGN127245_Rudder(const tN2kMsg &N2kMsg,
		double &RudderPositionRad,
		tN2kRudderDirectionOrder &RudderDirectionOrder,
		double &AngleOrder) {
	if (N2kMsg.PGN != PGN127245_Rudder)
		return false;
	unsigned char Instance;
	ParseN2kPGN127245(N2kMsg, RudderPositionRad, Instance, RudderDirectionOrder,
			AngleOrder);
	if (Instance != 0)
		return false;
	return true;
}
bool RaymarinePilot::ParseN2kPGN65374SeatalkKeypadHeartbeat(const tN2kMsg &N2kMsg,
		uint8_t &proprietaryId,
		uint8_t &variant,
		uint8_t &status)
{
	if (N2kMsg.PGN !=PGN65374_SeatalkKeypadHeartbeat) return false;
	int Index=0;
	uint16_t code=N2kMsg.Get2ByteUInt(Index);
#ifdef RAYMARINE_FULL_CODE
	bool isOk=ParseHeader(N2kMsg);
#endif

	Index=2;
	//industryCode	= N2kMsg.GetByte(Index);
	proprietaryId	= N2kMsg.GetByte(Index);
	variant	        = N2kMsg.GetByte(Index);
	status	        = N2kMsg.GetByte(Index);
#ifdef _DEBUG_RAYMARINE_PILOT
	_OUTPUT_STREAM.print(",proprietaryId,"+String((proprietaryId)));
	_OUTPUT_STREAM.print(",variant,"+String((variant)));
	_OUTPUT_STREAM.print(",status,"+String((status)));
#endif

#ifdef RAYMARINE_FULL_CODE
	return isOk;
#else
	return true;
#endif

}
//65379UL //0x0FF63
//3B9F0000000002FF stby
//3B9F0001000002FF wind
bool RaymarinePilot::ParseN2kPGN65379SeatalkPilotMode(const tN2kMsg &N2kMsg,
		tN2kSeatalkPilotModes &pilotMode,
		uint8_t	 &pilotModeData,
		uint24_t &reserved2)
{
	if (N2kMsg.PGN !=PGN65379_SeatalkPilotMode) return false;
	int Index=0;
#ifdef RAYMARINE_FULL_CODE
	bool isOk=ParseHeader(N2kMsg);
#endif

	Index=2;
	pilotMode		=(tN2kSeatalkPilotModes)N2kMsg.Get2ByteUInt(Index);
	pilotModeData	= N2kMsg.GetByte     (Index);
	reserved2		= N2kMsg.Get3ByteUInt(Index);
#ifdef _DEBUG_RAYMARINE_PILOT_ParseN2kPGN65379SeatalkPilotMode
	_OUTPUT_STREAM.print(",pilotMode,"+String((pilotMode)));
	_OUTPUT_STREAM.print(String(",")+N2kEnumTypeToStr(pilotMode));
	_OUTPUT_STREAM.print(",pilotModeData,"+String((pilotModeData)));
	_OUTPUT_STREAM.print(",reserved,"+String((reserved2)));
	_OUTPUT_STREAM.println();
#endif
#ifdef RAYMARINE_FULL_CODE
	return isOk;
#else
	return true;
#endif

}

#ifdef RAYMARINE_FULL_CODE
//match 3B9F
bool RaymarinePilot::ParseHeader(const tN2kMsg &N2kMsg)
{
	int Index=0;
	uint16_t code   = N2kMsg.Get2ByteUInt(Index);
	uint11_t manufacturerCode= code&0x07FF;////<Match>1851</Match> <Description>Raymarine</Description> //3B9F
#ifdef DEBUG_ParseHeader
	uint2_t reserved		= (code>>11)&0x0003;
	uint3_t industryCode	= (code>>13)&0x0007;//match 4 marine
	_OUTPUT_STREAM.print("manufacturerCode,"+String((manufacturerCode)));
	_OUTPUT_STREAM.print(",reserved,"+String((reserved)));
	_OUTPUT_STREAM.print(",industryCode,"+String((industryCode)));
#endif
	return manufacturerCode==ManufacturersRegNumRaymarine;
}
#endif


const char* RaymarinePilot::N2kEnumTypeToStr(tN2kSeatalkAlarmStatus enumVal)
{
	if (enumVal
			< (sizeof(tN2kSeatalkAlarmStatusReferenceStrs) / sizeof(const char*))) {
		return tN2kSeatalkAlarmStatusReferenceStrs[enumVal ];
	} else {
		return "";
	}
}
const char* RaymarinePilot::N2kEnumTypeToStr(
		tN2kSeatalkPilotModes enumVal) {
	switch (enumVal) {
	case PILOT_MODE_STANDBY:
		return tN2kSeatalkPilotModesReferenceStrs[0];
	case PILOT_MODE_AUTO:
		return tN2kSeatalkPilotModesReferenceStrs[1];
	case PILOT_MODE_WIND:
		return tN2kSeatalkPilotModesReferenceStrs[2];
	case PILOT_MODE_TRACK:
		return tN2kSeatalkPilotModesReferenceStrs[3];
	default:
		return "";
	}
}
const char* RaymarinePilot::N2kEnumTypeToStr(
		tN2kSeatalkAlarmGroupCodes enumVal) {
	if (enumVal	< (sizeof(tN2kSeatalkAlarmGroupCodesReferenceStrs)
			/ sizeof(const char*))) {
		return tN2kSeatalkAlarmGroupCodesReferenceStrs[enumVal];
	} else {
		return "";
	}
}
const char* RaymarinePilot::N2kEnumTypeToStr(
		tN2kSeatalkAlarmId enumVal) {
	if (enumVal	< (sizeof(tN2kSeatalkAlarmIdReferenceStrs) / sizeof(const char*))) {
		return tN2kSeatalkAlarmIdReferenceStrs[enumVal];
	} else {
		return "";
	}
}



