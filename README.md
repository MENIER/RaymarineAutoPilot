# RaymarineAutoPilot
It is based on the work of tthese projects in GitHub: 
https://github.com/matztam/raymarine-evo-pilot-remote 
and
https://github.com/AK-Homberger/ESP32-Evo-Remote-Pilot-NMEA2000
and
https://github.com/canboat/canboat/blob/master/docs/canboat.html
Many thanks for all the work to identify the NMEA 2000 codes for the EV-1 Course Computer.
The code is using the NMEA 2000 libraries from Timo Lappalainen (https://github.com/ttlappalainen).

Download and install the following libraries from GitHub link above:

    NMEA2000
    NMEA2000_esp32
    
--------------------------RaymarineAutoPilot library description-------------------------------

Send event keys:

	EV_PILOT_RESPONCE_LEISURE
	EV_PILOT_RESPONCE_CRUISING
	EV_PILOT_RESPONCE_PERFORMANCE
	EV_PILOT_MODE_AUTO
	EV_PILOT_MODE_WIND      
	EV_PILOT_MODE_TRACK     
	EV_PILOT_MODE_TRACK1    
	EV_KEY_PLUS_1           
	EV_KEY_PLUS_10          
	EV_KEY_MINUS_1          
	EV_KEY_MINUS_10         
	EV_KEY_MINUS_1_MINUS_10 
	EV_KEY_PLUS_1_PLUS_10   
	EV_KEY_TACK_PORTSIDE    
	EV_KEY_TACK_STARBORD    

PGNS in read mode:

			PGN65345_SeatalkPilotWindDatum, //read locked Wind direction
			PGN65288_SeatalkAlarm,   // Read Seatalk Alarm State
			PGN65361_SeatalkSilenceAlarm,
			PGN65379_SeatalkPilotMode  ,   // Read Pilot Mode
			PGN126720_Seatalk1PilotMode,
			PGN65359_SeatalkPilotHeading,
			PGN65360_SeatalkPilotLockedHeading,
			PGN127250_VesselHeading    ,   // Read Heading
PGNS in write mode:

			PGN65288_SeatalkAlarm ,   // Send Seatalk Alarm State
			PGN65361_SeatalkSilenceAlarm,
			PGN126208_NmeaRequestGroupFunction,   // Set Pilot Mode
			PGN126720_Seatalk1PilotMode ,   // Send Key Command
			PGN130306_WindData    ,
