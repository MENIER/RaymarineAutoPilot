/*
pgnsToString.h
Copyright (c) 2023 MENIER Camille
Created on: 29 nov. 2021
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


This Example for NMEA2000 tools for String PGN
*/

#ifndef PGNSTOSTRING_H_
#define PGNSTOSTRING_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <Arduino.h>
#include <WString.h>
const char *toStringPgn(unsigned long pgn)
{
	switch(pgn)
	{
	case 59392L: return PSTR("isoAcknowledgement");
	case 59904L: return PSTR("isoRequest");
	case 60160L: return PSTR("isoTransportProtocolDataTransfer");
	case 60416L: return PSTR("isoTransportProtocolConnectionManagement");
	case 60928L: return PSTR("isoAddressClaim");
	case 61184L: return PSTR("seatalkWirelessKeypadLightControl");
	case 61440L: return PSTR("unknownSingleFrameNonAddressed");
	case 65001L: return PSTR("bus1PhaseCBasicAcQuantities");
	case 65002L: return PSTR("bus1PhaseBBasicAcQuantities");
	case 65003L: return PSTR("bus1PhaseABasicAcQuantities");
	case 65004L: return PSTR("bus1AverageBasicAcQuantities");
	case 65005L: return PSTR("utilityTotalAcEnergy");
	case 65006L: return PSTR("utilityPhaseCAcReactivePower");
	case 65007L: return PSTR("utilityPhaseCAcPower");
	case 65008L: return PSTR("utilityPhaseCBasicAcQuantities");
	case 65009L: return PSTR("utilityPhaseBAcReactivePower");
	case 65010L: return PSTR("utilityPhaseBAcPower");
	case 65011L: return PSTR("utilityPhaseBBasicAcQuantities");
	case 65012L: return PSTR("utilityPhaseAAcReactivePower");
	case 65013L: return PSTR("utilityPhaseAAcPower");
	case 65014L: return PSTR("utilityPhaseABasicAcQuantities");
	case 65015L: return PSTR("utilityTotalAcReactivePower");
	case 65016L: return PSTR("utilityTotalAcPower");
	case 65017L: return PSTR("utilityAverageBasicAcQuantities");
	case 65018L: return PSTR("generatorTotalAcEnergy");
	case 65019L: return PSTR("generatorPhaseCAcReactivePower");
	case 65020L: return PSTR("generatorPhaseCAcPower");
	case 65021L: return PSTR("generatorPhaseCBasicAcQuantities");
	case 65022L: return PSTR("generatorPhaseBAcReactivePower");
	case 65023L: return PSTR("generatorPhaseBAcPower");
	case 65024L: return PSTR("generatorPhaseBBasicAcQuantities");
	case 65025L: return PSTR("generatorPhaseAAcReactivePower");
	case 65026L: return PSTR("generatorPhaseAAcPower");
	case 65027L: return PSTR("generatorPhaseABasicAcQuantities");
	case 65028L: return PSTR("generatorTotalAcReactivePower");
	case 65029L: return PSTR("generatorTotalAcPower");
	case 65030L: return PSTR("generatorAverageBasicAcQuantities");
	case 65240L: return PSTR("isoCommandedAddress");
	case 65280L: return PSTR("manufacturerProprietarySingleFrameNonAddressed");
	case 65284L: return PSTR("maretronProprietaryDcBreakerCurrent");
	case 65285L: return PSTR("airmarBootStateAcknowledgment");
	case 65288L: return PSTR("seatalkAlarm");
	case 65289L: return PSTR("simnetTrimTabSensorCalibration");
	case 65290L: return PSTR("simnetPaddleWheelSpeedConfiguration");
	case 65292L: return PSTR("simnetClearFluidLevelWarnings");
	case 65293L: return PSTR("simnetLgc2000Configuration");
	case 65309L: return PSTR("navicoWirelessBatteryStatus");
	case 65312L: return PSTR("navicoWirelessSignalStatus");
	case 65325L: return PSTR("simnetReprogramStatus");
	case 65341L: return PSTR("simnetAutopilotMode");
	case 65345L: return PSTR("seatalkPilotWindDatum");
	case 65359L: return PSTR("seatalkPilotHeading");
	case 65360L: return PSTR("seatalkPilotLockedHeading");
	case 65361L: return PSTR("seatalkSilenceAlarm");
	case 65371L: return PSTR("seatalkKeypadMessage");
	case 65374L: return PSTR("seatalkKeypadHeartbeat");
	case 65379L: return PSTR("seatalkPilotMode");
	case 65408L: return PSTR("airmarDepthQualityFactor");
	case 65409L: return PSTR("airmarSpeedPulseCount");
	case 65410L: return PSTR("airmarDeviceInformation");
	case 65480L: return PSTR("simnetAutopilotMode");
	case 65536L: return PSTR("unknownFastPacketAddressed");
	case 126208L: return PSTR("nmeaRequestGroupFunction");
	case 126464L: return PSTR("pgnListTransmitAndReceive");
	case 126720L: return PSTR("seatalk1PilotMode");
	case 126976L: return PSTR("unknownFastPacketNonAddressed");
	case 126983L: return PSTR("alert");
	case 126984L: return PSTR("alertResponse");
	case 126985L: return PSTR("alertText");
	case 126986L: return PSTR("alertConfiguration");
	case 126987L: return PSTR("alertThreshold");
	case 126988L: return PSTR("alertValue");
	case 126992L: return PSTR("systemTime");
	case 126993L: return PSTR("heartbeat");
	case 126996L: return PSTR("productInformation");
	case 126998L: return PSTR("configurationInformation");
	case 127233L: return PSTR("manOverboardNotification");
	case 127237L: return PSTR("headingTrackControl");
	case 127245L: return PSTR("rudder");
	case 127250L: return PSTR("vesselHeading");
	case 127251L: return PSTR("rateOfTurn");
	case 127252L: return PSTR("heave");
	case 127257L: return PSTR("attitude");
	case 127258L: return PSTR("magneticVariation");
	case 127488L: return PSTR("engineParametersRapidUpdate");
	case 127489L: return PSTR("engineParametersDynamic");
	case 127493L: return PSTR("transmissionParametersDynamic");
	case 127496L: return PSTR("tripParametersVessel");
	case 127497L: return PSTR("tripParametersEngine");
	case 127498L: return PSTR("engineParametersStatic");
	case 127500L: return PSTR("loadControllerConnectionStateControl");
	case 127501L: return PSTR("binarySwitchBankStatus");
	case 127502L: return PSTR("switchBankControl");
	case 127503L: return PSTR("acInputStatus");
	case 127504L: return PSTR("acOutputStatus");
	case 127505L: return PSTR("fluidLevel");
	case 127506L: return PSTR("dcDetailedStatus");
	case 127507L: return PSTR("chargerStatus");
	case 127508L: return PSTR("batteryStatus");
	case 127509L: return PSTR("inverterStatus");
	case 127510L: return PSTR("chargerConfigurationStatus");
	case 127511L: return PSTR("inverterConfigurationStatus");
	case 127512L: return PSTR("agsConfigurationStatus");
	case 127513L: return PSTR("batteryConfigurationStatus");
	case 127514L: return PSTR("agsStatus");
	case 127744L: return PSTR("acPowerCurrentPhaseA");
	case 127745L: return PSTR("acPowerCurrentPhaseB");
	case 127746L: return PSTR("acPowerCurrentPhaseC");
	case 127750L: return PSTR("converterStatus");
	case 127751L: return PSTR("dcVoltageCurrent");
	case 128000L: return PSTR("leewayAngle");
	case 128259L: return PSTR("speed");
	case 128267L: return PSTR("waterDepth");
	case 128275L: return PSTR("distanceLog");
	case 128520L: return PSTR("trackedTargetData");
	case 128776L: return PSTR("windlassControlStatus");
	case 128777L: return PSTR("anchorWindlassOperatingStatus");
	case 128778L: return PSTR("anchorWindlassMonitoringStatus");
	case 129025L: return PSTR("positionRapidUpdate");
	case 129026L: return PSTR("cogSogRapidUpdate");
	case 129027L: return PSTR("positionDeltaRapidUpdate");
	case 129028L: return PSTR("altitudeDeltaRapidUpdate");
	case 129029L: return PSTR("gnssPositionData");
	case 129033L: return PSTR("timeDate");
	case 129038L: return PSTR("aisClassAPositionReport");
	case 129039L: return PSTR("aisClassBPositionReport");
	case 129040L: return PSTR("aisClassBExtendedPositionReport");
	case 129041L: return PSTR("aisAidsToNavigationAtonReport");
	case 129044L: return PSTR("datum");
	case 129045L: return PSTR("userDatum");
	case 129283L: return PSTR("crossTrackError");
	case 129284L: return PSTR("navigationData");
	case 129285L: return PSTR("navigationRouteWpInformation");
	case 129291L: return PSTR("setDriftRapidUpdate");
	case 129301L: return PSTR("navigationRouteTimeToFromMark");
	case 129302L: return PSTR("bearingAndDistanceBetweenTwoMarks");
	case 129538L: return PSTR("gnssControlStatus");
	case 129539L: return PSTR("gnssDops");
	case 129540L: return PSTR("gnssSatsInView");
	case 129541L: return PSTR("gpsAlmanacData");
	case 129542L: return PSTR("gnssPseudorangeNoiseStatistics");
	case 129545L: return PSTR("gnssRaimOutput");
	case 129546L: return PSTR("gnssRaimSettings");
	case 129547L: return PSTR("gnssPseudorangeErrorStatistics");
	case 129549L: return PSTR("dgnssCorrections");
	case 129550L: return PSTR("gnssDifferentialCorrectionReceiverInterface");
	case 129551L: return PSTR("gnssDifferentialCorrectionReceiverSignal");
	case 129556L: return PSTR("glonassAlmanacData");
	case 129792L: return PSTR("aisDgnssBroadcastBinaryMessage");
	case 129793L: return PSTR("aisUtcAndDateReport");
	case 129794L: return PSTR("aisClassAStaticAndVoyageRelatedData");
	case 129795L: return PSTR("aisAddressedBinaryMessage");
	case 129796L: return PSTR("aisAcknowledge");
	case 129797L: return PSTR("aisBinaryBroadcastMessage");
	case 129798L: return PSTR("aisSarAircraftPositionReport");
	case 129799L: return PSTR("radioFrequencyModePower");
	case 129800L: return PSTR("aisUtcDateInquiry");
	case 129801L: return PSTR("aisAddressedSafetyRelatedMessage");
	case 129802L: return PSTR("aisSafetyRelatedBroadcastMessage");
	case 129803L: return PSTR("aisInterrogation");
	case 129804L: return PSTR("aisAssignmentModeCommand");
	case 129805L: return PSTR("aisDataLinkManagementMessage");
	case 129806L: return PSTR("aisChannelManagement");
	case 129807L: return PSTR("aisClassBGroupAssignment");
	case 129808L: return PSTR("dscCallInformation");
	case 129809L: return PSTR("aisClassBStaticDataMsg24PartA");
	case 129810L: return PSTR("aisClassBStaticDataMsg24PartB");
	case 130060L: return PSTR("label");
	case 130061L: return PSTR("channelSourceConfiguration");
	case 130064L: return PSTR("routeAndWpServiceDatabaseList");
	case 130065L: return PSTR("routeAndWpServiceRouteList");
	case 130066L: return PSTR("routeAndWpServiceRouteWpListAttributes");
	case 130067L: return PSTR("routeAndWpServiceRouteWpNamePosition");
	case 130068L: return PSTR("routeAndWpServiceRouteWpName");
	case 130069L: return PSTR("routeAndWpServiceXteLimitNavigationMethod");
	case 130070L: return PSTR("routeAndWpServiceWpComment");
	case 130071L: return PSTR("routeAndWpServiceRouteComment");
	case 130072L: return PSTR("routeAndWpServiceDatabaseComment");
	case 130073L: return PSTR("routeAndWpServiceRadiusOfTurn");
	case 130074L: return PSTR("routeAndWpServiceWpListWpNamePosition");
	case 130306L: return PSTR("windData");
	case 130310L: return PSTR("environmentalParameters");
	case 130311L: return PSTR("environmentalParameters");
	case 130312L: return PSTR("temperature");
	case 130313L: return PSTR("humidity");
	case 130314L: return PSTR("actualPressure");
	case 130315L: return PSTR("setPressure");
	case 130316L: return PSTR("temperatureExtendedRange");
	case 130320L: return PSTR("tideStationData");
	case 130321L: return PSTR("salinityStationData");
	case 130322L: return PSTR("currentStationData");
	case 130323L: return PSTR("meteorologicalStationData");
	case 130324L: return PSTR("mooredBuoyStationData");
	case 130560L: return PSTR("payloadMass");
	case 130567L: return PSTR("watermakerInputSettingAndStatus");
	case 130569L: return PSTR("currentStatusAndFile");
	case 130570L: return PSTR("libraryDataFile");
	case 130571L: return PSTR("libraryDataGroup");
	case 130572L: return PSTR("libraryDataSearch");
	case 130573L: return PSTR("supportedSourceData");
	case 130574L: return PSTR("supportedZoneData");
	case 130576L: return PSTR("smallCraftStatus");
	case 130577L: return PSTR("directionData");
	case 130578L: return PSTR("vesselSpeedComponents");
	case 130579L: return PSTR("systemConfiguration");
	case 130580L: return PSTR("systemConfigurationDeprecated");
	case 130581L: return PSTR("zoneConfigurationDeprecated");
	case 130582L: return PSTR("zoneVolume");
	case 130583L: return PSTR("availableAudioEqPresets");
	case 130584L: return PSTR("availableBluetoothAddresses");
	case 130585L: return PSTR("bluetoothSourceStatus");
	case 130586L: return PSTR("zoneConfiguration");
	case 130816L: return PSTR("sonichubInit2");
	case 130817L: return PSTR("navicoProductInformation");
	case 130818L: return PSTR("simnetReprogramData");
	case 130819L: return PSTR("simnetRequestReprogram");
	case 130820L: return PSTR("simnetReprogramStatus");
	case 130821L: return PSTR("furunoUnknown");
	case 130824L: return PSTR("maretronAnnunciator");
	case 130827L: return PSTR("lowranceUnknown");
	case 130828L: return PSTR("simnetSetSerialNumber");
	case 130831L: return PSTR("suzukiEngineAndStorageDeviceConfig");
	case 130832L: return PSTR("simnetFuelUsedHighResolution");
	case 130834L: return PSTR("simnetEngineAndTankConfiguration");
	case 130835L: return PSTR("simnetSetEngineAndTankConfiguration");
	case 130836L: return PSTR("simnetFluidLevelSensorConfiguration");
	case 130838L: return PSTR("simnetFluidLevelWarning");
	case 130839L: return PSTR("simnetPressureSensorConfiguration");
	case 130840L: return PSTR("simnetDataUserGroupConfiguration");
	case 130842L: return PSTR("simnetAisClassBStaticDataMsg24PartA");
	case 130843L: return PSTR("simnetSonarStatusFrequencyAndDspVoltage");
	case 130845L: return PSTR("simnetCompassHeadingOffset");
	case 130846L: return PSTR("furunoMotionSensorStatusExtended");
	case 130847L: return PSTR("seatalkNodeStatistics");
	case 130850L: return PSTR("simnetEventCommandApCommand");
	case 130851L: return PSTR("simnetEventReplyApCommand");
	case 130856L: return PSTR("simnetAlarmMessage");
	case 130880L: return PSTR("airmarAdditionalWeatherData");
	case 130881L: return PSTR("airmarHeaterControl");
	case 130944L: return PSTR("airmarPost");
	default:return PSTR("Unknow");
	}
}
#ifdef __cplusplus
}
#endif
#endif /* PGNSTOSTRING_H_ */
