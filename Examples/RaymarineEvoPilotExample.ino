
/*

Copyright (c) 2023 MENIER Camille

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


This Example for use RaymarinePilot library
 Remote control of raymarine pilot by serial Terminal
 */

////////////////////WEMOS R32///////////////////////////////////////////////////////////////
//                                      +-----+
//         +----[PWR]-------------------| USB |--+
//         |                            +-----+  |
//   ESP   |         GND/RST2  [ ][ ]            |       ESP
//         |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |   C5  SCL
//         |          5V/MISO2 [ ][ ]  A4/SDA[ ] |   C4  SDA
//         |                             AREF[ ] |       RST
//         |             ESPDUINO         GND[ ] |       GND
//  GPIO 00| [ ]N/C                    SCK/13[ ] |   B5  GPIO 18 /SCK / V_SPI_CLK
//   5V    | [ ]IOREF                 MISO/12[ ] |   .   GPIO 19 /U0_CTS / MSIO / V_SPI_Q
//  RST    | [ ]RST                   MOSI/11[ ]~|   .   GPIO 23
//  3V3    | [ ]3V3    +---+               10[ ]~|   .   GPIO 05
//   5v    | [ ]5v    -| A |-               9[ ]~|   .   GPIO 13
//  GND    | [ ]GND   -| R |-               8[ ] |   B0  GPIO 12
//  GND    | [ ]GND   -| D |-                    |
//  Vin    | [ ]Vin   -| U |-               7[ ] |   D7  GPIO 14 //BOOT PWM
//         |          -| I |-               6[ ]~|   D6  GPIO 27
//  GPIO 02| [ ]A0    -| N |-               5[ ]~|   D5  GPIO 16
//  GPIO 04| [ ]A1    -| O |-               4[ ] |   D4  GPIO 17
//  GPIO 36| [ ]A2     +---+           INT1/3[ ]~|   D3  GPIO 25
//  GPIO 34| [ ]A3                     INT0/2[ ] |   D2  GPIO 26
//  GPIO 38| [ ]A4/SDA  RST SCK MISO     TX>1[ ] |   D1  GPIO TX_UART0
//  GPIO 39| [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |   D0  GPIO RX_UART0
//         |            [ ] [ ] [ ]              |
//         |  UNO_R3    GND MOSI 5V  ____________/
//          \_______________________/
//
//
#include "Arduino.h"
#define ESP32_CAN_TX_PIN GPIO_NUM_27 //D9 13
#define ESP32_CAN_RX_PIN GPIO_NUM_26 //D8 12
#include <Preferences.h>
#include <NMEA2000.h>
#include <NMEA2000_CAN.h>
#include <N2kDeviceList.h>
#define _DEBUG_RAYMARINE_PILOT
#include <RaymarinePilot.h>
#include <pgnsToString.h>

#ifndef _OUTPUT_STREAM
#define _OUTPUT_STREAM Serial
#endif

tN2kDeviceList *pN2kDeviceList;
//MAC ADRESS
// To store last Node Address
int NodeAddress;
short pilotSourceAddress=-1;
// Nonvolatile storage on ESP32 - To store LastDeviceAddress
Preferences preferences;
const unsigned long TransmitMessages[8] PROGMEM = {
		PGN65288_SeatalkAlarm             ,   // Send Seatalk Alarm State
		PGN65361_SeatalkSilenceAlarm      ,
		PGN126208_NmeaRequestGroupFunction,   // Set Pilot Mode
		PGN126720_Seatalk1PilotMode       ,   // Send Key Command
		PGN129283_CrossTrackError         ,
		PGN129284_NavigationData          ,   //tack simul
		PGN130306_WindData                ,
		0
};
const unsigned long ReceiveMessages[9] PROGMEM = {
		PGN65345_SeatalkPilotWindDatum, //read locked Wind direction
		PGN65288_SeatalkAlarm      ,   // Read Seatalk Alarm State
		PGN65361_SeatalkSilenceAlarm,
		PGN65379_SeatalkPilotMode  ,   // Read Pilot Mode
		PGN126720_Seatalk1PilotMode,
		PGN65359_SeatalkPilotHeading,
		PGN65360_SeatalkPilotLockedHeading,
		PGN127250_VesselHeading    ,   // Read Heading
		0
};
RaymarinePilot raymarinePilot;
#define WindUpdatePeriod 1000
void SimulSendN2kWind() {
	static unsigned long WindUpdated=millis();
	tN2kMsg N2kMsg;
	if ( WindUpdated+WindUpdatePeriod<millis() ) {
		double v=DegToRad(71);
		//SetN2kPGN130306
		SetN2kWindSpeed(N2kMsg, 1, KnotsToms(10), DegToRad(71),N2kWind_Apprent);
		WindUpdated=millis();
		NMEA2000.SendMsg(N2kMsg);
	}
}
void tracePacket(const tN2kMsg &N2kMsg)
{
#ifdef _DEBUG_RAYMARINE_PILOT
	char buf [6] ; // large enough for biggest long int
	sprintf (buf, "%06i", N2kMsg.PGN) ;  // leading zeroes, at least 4 chars.
	_OUTPUT_STREAM.print(buf);_OUTPUT_STREAM.print(',');
	for (int i = 0; i < N2kMsg.DataLen; i++) {
		if(N2kMsg.Data[i]<0x0f)
			_OUTPUT_STREAM.print('0');
		_OUTPUT_STREAM.print(N2kMsg.Data[i],HEX);
	}
	sprintf (buf, "%02i", N2kMsg.Priority) ;  // leading zeroes, at least 4 chars.
	_OUTPUT_STREAM.print(buf);_OUTPUT_STREAM.print(',');
	sprintf (buf, "%03i", N2kMsg.Destination) ;
	_OUTPUT_STREAM.print(buf);_OUTPUT_STREAM.print(',');
	sprintf (buf, "%03i", N2kMsg.Source) ;
	_OUTPUT_STREAM.print(buf);_OUTPUT_STREAM.print(',');
	_OUTPUT_STREAM.print(toStringPgn( N2kMsg.PGN));_OUTPUT_STREAM.print(',');
#endif
}

int getDeviceSourceAddress(String model) {
	if (!pN2kDeviceList->ReadResetIsListUpdated())
		return -1;
	for (uint8_t i = 0; i < N2kMaxBusDevices; i++) {
		const tNMEA2000::tDevice *device = pN2kDeviceList->FindDeviceBySource(
				i);
		if (device == 0)
			continue;
		String modelVersion = device->GetModelVersion();
		_OUTPUT_STREAM.println(
				"Model,detected name is:" + modelVersion +
				";Address: "+ device->GetSource());
		if (modelVersion.indexOf(model) >= 0) {
			_OUTPUT_STREAM.println(
					"Ok model,detected name is:" + modelVersion +
					";Address: "+ device->GetSource());
			return device->GetSource();
		}
	}
	return -2;
}
void setPiloteSourceAddress() {
	if (pilotSourceAddress < 0) {
		pilotSourceAddress = getDeviceSourceAddress("EV-1"); // No EV-1 detected. Return!
	}
	if (pilotSourceAddress < 0) {
		Serial.println("Panic!PILOT_MODE_NO_EV_1_DETECTED");
	}
}
void HandleNMEA2000Msg(const tN2kMsg &N2kMsg) {
	uint11_t manufacturerCode;
	uint2_t reserved1;
	uint3_t industryCode;
	tracePacket(N2kMsg);
	switch(N2kMsg.PGN)
	{
	/*case PGN126208_NmeaRequestGroupFunction:
		raymarinePilot.ParseN2kPGN126208Nmea(N2kMsg);
		break;*/

	case PGN127251_RateOfTurn:
	{
		unsigned char SID; double RateOfTurn;
		ParseN2kPGN127251(N2kMsg,SID,RateOfTurn);
		_OUTPUT_STREAM.println("RateOfTurn, SID,"+String(RadToDeg(RateOfTurn))+","+String(SID));
		break;
	}

	//Random value in the time???????????????????
#ifdef DEBUG_RaymarineMsgHandlerPGN127250_VesselHeading
	case PGN127250_VesselHeading:
	{
		unsigned char SID;
		tN2kHeadingReference ref;
		double _Deviation = 0;
		double _Variation;
		double _HeadingRad;

		if (ParseN2kPGN127250(N2kMsg, SID, _HeadingRad, _Deviation, _Variation, ref)) {
			if ( !N2kIsNA(_Variation) ) Variation = _Variation; // Update Variation
			if ( !N2kIsNA(_HeadingRad) && !N2kIsNA(Variation) ) _HeadingRad -= Variation;
			setCallBackHeadingMagneticDegrees((unsigned int) (RadToDeg(_HeadingRad)));
		}
	}
	break;
#endif

	case PGN65361_SeatalkSilenceAlarm:
	{
		uint8_t alarmId;
		uint8_t alarmGroup;
		uint32_t reserved2;
		raymarinePilot.ParseN2kPGN65361_SeatalkSilenceAlarm(N2kMsg,
				alarmId,
				alarmGroup,
				reserved2
		);
	}
	break;
	case PGN127257_Attitude:
	{
		unsigned char SID; double Yaw; double Pitch; double Roll;
		ParseN2kPGN127257(N2kMsg, SID,Yaw, Pitch,Roll);
		_OUTPUT_STREAM.println("Yaw, Pitch,Roll,"+String(RadToDeg(Yaw))+"'"+String(RadToDeg(Pitch))+"'"+String(RadToDeg(Pitch)));
	}
	break;
	case PGN65288_SeatalkAlarm:
	{
		RaymarinePilot::tN2kSeatalkAlarmId AlarmId;
		RaymarinePilot::tN2kSeatalkAlarmGroupCodes AlarmGroup;
		RaymarinePilot::tN2kSeatalkAlarmStatus AlarmStatus;
		raymarinePilot.ParseN2kPGN65288_SeatalkAlarm(N2kMsg,AlarmStatus, AlarmId, AlarmGroup);
	}
	break;
	case PGN65359_SeatalkPilotHeading:
	{
		double	headingTrue;
		double	headingMagnetic;
		raymarinePilot.ParseN2kPGN65359_SeatalkPilotHeading(N2kMsg,
				headingTrue,
				headingMagnetic);
	}	break;
	case PGN65360_SeatalkPilotLockedHeading:
	{
		double	headingTrue;
		double	headingMagnetic;
		raymarinePilot.ParseN2kPGN65360_SeatalkPilotLockedHeading(N2kMsg,
				headingTrue,
				headingMagnetic	);
	}	break;
	case PGN126720_Seatalk1PilotMode:
	{
		RaymarinePilot::tN2kSeatalkPilotModesParse pilotMode;
		unsigned char submode;
		raymarinePilot.ParseN2kPGN126720_Seatalk1PilotMode(N2kMsg,
				pilotMode,
				submode);
	}
	break;
	case PGN65379_SeatalkPilotMode:
	{
		RaymarinePilot::tN2kSeatalkPilotModes	pilotMode;
		uint8_t	pilotModeData;
		uint24_t	reserved2;
		raymarinePilot.ParseN2kPGN65379SeatalkPilotMode(N2kMsg,
				pilotMode,
				pilotModeData,
				reserved2);
	}
	break;
	case PGN65345_SeatalkPilotWindDatum:
	{
		double WindAngle;
		double RollingAverageWindAngle;
		raymarinePilot.ParseN2kPGN65345_SeatalkPilotWindLockedDatum(N2kMsg,
				WindAngle,
				RollingAverageWindAngle);
	}
	break;
	case PGN127237_HeadingTrackControl:
	{
		double commandedRudderAngle;
		raymarinePilot.ParseN2kPGN127237_headingTrackControl(N2kMsg,commandedRudderAngle);

	}
	break;
	default:_OUTPUT_STREAM.println();
	}
}
void HandleSerialCommand() {
	tN2kMsg N2kMsg;
	if (_OUTPUT_STREAM.available()) {
		char chr = _OUTPUT_STREAM.read();
		{
			_OUTPUT_STREAM.println("_OUTPUT_STREAM Receive;"+String(chr));
			_OUTPUT_STREAM.println("NodeAddress;"+String(NodeAddress));
			_OUTPUT_STREAM.println("pilotSourceAddress;"+String(pilotSourceAddress));
			switch ( chr ) {
			case '+':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_KEY_PLUS_1                );_OUTPUT_STREAM.println(F("EV_KEY_PLUS_1"                ));break;
			case '-':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_KEY_MINUS_1               );_OUTPUT_STREAM.println(F("EV_KEY_MINUS_1"               ));break;
			case 'm':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_KEY_MINUS_10              );_OUTPUT_STREAM.println(F("EV_KEY_MINUS_10"              ));break;
			case 'p':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_KEY_PLUS_10               );_OUTPUT_STREAM.println(F("EV_KEY_PLUS_10"               ));break;
			case 'M':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_KEY_MINUS_1_MINUS_10      );_OUTPUT_STREAM.println(F("EV_KEY_MINUS_1_MINUS_10"      ));break;
			case 'P':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_KEY_PLUS_1_PLUS_10        );_OUTPUT_STREAM.println(F("EV_KEY_PLUS_1_PLUS_10"        ));break;
			case 'a':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_PILOT_MODE_AUTO           );_OUTPUT_STREAM.println(F("EV_PILOT_MODE_AUTO"           ));break;
			case 's':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_PILOT_MODE_STANDBY        );_OUTPUT_STREAM.println(F("EV_PILOT_MODE_STANDBY"        ));break;
			case 'w':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_PILOT_MODE_WIND           );_OUTPUT_STREAM.println(F("EV_PILOT_MODE_WIND"           ));break;
			case 't':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_PILOT_MODE_TRACK          );_OUTPUT_STREAM.println(F("EV_PILOT_MODE_TRACK"          ));break;
			case 'y':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_PILOT_MODE_TRACK1         );_OUTPUT_STREAM.println(F("EV_PILOT_MODE_TRACK1"         ));break;
			case 'l':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_PILOT_RESPONCE_LEISURE    );_OUTPUT_STREAM.println(F("EV_PILOT_RESPONCE_LEISURE"    ));break;
			case 'c':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_PILOT_RESPONCE_CRUISING   );_OUTPUT_STREAM.println(F("EV_PILOT_RESPONCE_CRUISING"   ));break;
			case 'f':raymarinePilot.SetN2kSeatalkKeyCommand(N2kMsg,pilotSourceAddress,RaymarinePilot::EV_PILOT_RESPONCE_PERFORMANCE);_OUTPUT_STREAM.println(F("EV_PILOT_RESPONCE_PERFORMANCE"));break;
			default:_OUTPUT_STREAM.println("UnKnow Command");
			}
			NMEA2000.SendMsg(N2kMsg);
		}
	}
}
//The setup function is called once at startup of the sketch
void setup()
{
	_OUTPUT_STREAM.begin(115200);
	delay(100);
	_OUTPUT_STREAM.println();
	_OUTPUT_STREAM.println( "Init Raymarine EVO remote control version V1.0 ");
	_OUTPUT_STREAM.println(__FILE__);
	_OUTPUT_STREAM.println("");
	_OUTPUT_STREAM.printf("Sketch size: %u\n\r", ESP.getSketchSize());
	_OUTPUT_STREAM.printf("Free size: %u\n\r"  , ESP.getFreeSketchSpace());

	uint8_t chipid[6];
	uint32_t id = 0;
	int i = 0;
	esp_efuse_read_mac(chipid);
	for (i = 0; i < 6; i++)
		id += (chipid[i] << (7 * i));
	// Reserve enough buffer for sending all messages. This does not work on small memory devices like Uno or Mega
	NMEA2000.SetN2kCANReceiveFrameBufSize(150);
	NMEA2000.SetN2kCANMsgBufSize(8);
	// Set Product information
	NMEA2000.SetProductInformation("00000001", // Manufacturer's Model _OUTPUT_STREAM code
			100, // Manufacturer's product code
			"Evo Pilot Remote", // Manufacturer's Model ID
			"1.0.0.0", // Manufacturer's Software version code
			"1.0.0.0");
	// Set device information
	NMEA2000.SetDeviceInformation(id, // Unique number. Use e.g. _OUTPUT_STREAM number.
			132, // Device function=Analog to NMEA 2000 Gateway. See codes on http://www.nmea.org/Assets/20120726%20nmea%202000%20class%20&%20function%20codes%20v%202.00.pdf
			25, // Device class=Inter/Intranetwork Device. See codes on  http://www.nmea.org/Assets/20120726%20nmea%202000%20class%20&%20function%20codes%20v%202.00.pdf
			2046);
	// Uncomment 3 rows below to see, what device will send to bus
	//NMEA2000.SetForwardStream(&_OUTPUT_STREAM);  // PC output on due programming port
	//NMEA2000.SetForwardType(tNMEA2000::fwdt_Text); // Show in clear text. Leave uncommented for default Actisense format.
	//NMEA2000.SetForwardOwnMessages();
	preferences.begin("nvs", false); // Open nonvolatile storage (nvs)
	NodeAddress = preferences.getInt("LastNodeAddress", 34); // Read stored last NodeAddress, default 34
	preferences.end();
	_OUTPUT_STREAM.println("NodeAddress=" + String(NodeAddress));
	// If you also want to see all traffic on the bus use N2km_ListenAndNode instead of N2km_NodeOnly below
	NMEA2000.SetMode(tNMEA2000::N2km_NodeOnly, NodeAddress); //N2km_NodeOnly N2km_ListenAndNode
	NMEA2000.ExtendTransmitMessages(TransmitMessages);
	NMEA2000.ExtendReceiveMessages(ReceiveMessages);
	NMEA2000.EnableForward(false); // Disable all msg forwarding to USB (=_OUTPUT_STREAM)
	NMEA2000.SetMsgHandler(HandleNMEA2000Msg);
	pN2kDeviceList = new tN2kDeviceList(&NMEA2000);
	if (NMEA2000.Open())
		_OUTPUT_STREAM.println(F("OK NMEA2000 Open "));
	else
		_OUTPUT_STREAM.println(F( "Error NMEA2000 Open "));
}

// The loop function is called in an endless loop
void loop()
{
	HandleSerialCommand();
	setPiloteSourceAddress();

	NMEA2000.ParseMessages();
	int SourceAddress = NMEA2000.GetN2kSource();
	if (SourceAddress != NodeAddress) { // Save potentially changed Source Address to NVS memory
		NodeAddress = SourceAddress; // Set new Node Address (to save only once)
		preferences.begin("nvs", false);
		preferences.putInt("LastNodeAddress", SourceAddress);
		preferences.end();
		_OUTPUT_STREAM.println("Address Change: New Address=" + String(SourceAddress));
	}
}
