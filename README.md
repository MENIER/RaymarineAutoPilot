# RaymarineAutoPilot
RaymarineAutoPilot ESP32 NMEA2000
This library read write pilot mode :

	    PILOT_MODE_STANDBY
	    PILOT_MODE_WIND 
	    PILOT_MODE_TRACK
	    PILOT_MODE_TRACK1 //No Drift, COG referenced (In track, course changes)
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
Read rudder headingLocked windLocket heading.
PGNS in read mode:
	PGN65345_SeatalkPilotWindDatum, //read locked Wind direction
      PGN65288_SeatalkAlarm      ,   // Read Seatalk Alarm State
      PGN65361_SeatalkSilenceAlarm,
			PGN65379_SeatalkPilotMode  ,   // Read Pilot Mode
			PGN126720_Seatalk1PilotMode,
			PGN65359_SeatalkPilotHeading,
			PGN65360_SeatalkPilotLockedHeading,
			PGN127250_VesselHeading    ,   // Read Heading
PGNS in write mode
      PGN65288_SeatalkAlarm             ,   // Send Seatalk Alarm State
			PGN65361_SeatalkSilenceAlarm      ,
			PGN126208_NmeaRequestGroupFunction,   // Set Pilot Mode
			PGN126720_Seatalk1PilotMode       ,   // Send Key Command
			PGN129283_CrossTrackError         ,
			PGN129284_NavigationData          ,   //tack simul
			PGN130306_WindData                ,
