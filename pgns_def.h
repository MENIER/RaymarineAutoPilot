/*
pgns_def.h

Copyright (c) 2023 MENIER Camille
base of works: CANboat
https://github.com/canboat/canboat

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


This is header for Usefull Defines NMEA2000 PGNS,ManufacturersReg and ClassCode
*/
#ifndef _PGNS_H_
#define _PGNS_H_

#define	PGN59392_IsoAcknowledgement                                          59392UL //0x0E800
#define	PGN59904_IsoRequest                                                  59904UL //0x0EA00
#define	PGN60160_IsoTransportProtocolDataTransfer                            60160UL //0x0EB00
#define	PGN60416_IsoTransportProtocolConnectionManagementRequestToSend       60416UL //0x0EC00
#define	PGN60416_IsoTransportProtocolConnectionManagementClearToSend         60416UL //0x0EC00
#define	PGN60416_IsoTransportProtocolConnectionManagementEndOfMessage        60416UL //0x0EC00
#define	PGN60416_IsoTransportProtocolConnectionManagementBroadcastAnnounce   60416UL //0x0EC00
#define	PGN60416_IsoTransportProtocolConnectionManagementAbort               60416UL //0x0EC00
#define	PGN60928_IsoAddressClaim                                             60928UL //0x0EE00
#define	PGN61184_SeatalkWirelessKeypadLightControl                           61184UL //0x0EF00
#define	PGN61184_SeatalkWirelessKeypadLightControl                           61184UL //0x0EF00
#define	PGN61184_VictronBatteryRegister                                      61184UL //0x0EF00
#define	PGN61184_ManufacturerProprietarySingleFrameAddressed                 61184UL //0x0EF00
#define	PGN61440_UnknownSingleFrameNonAddressed                              61440UL //0x0F000
#define	PGN65001_Bus1PhaseCBasicAcQuantities                                 65001UL //0x0FDE9
#define	PGN65002_Bus1PhaseBBasicAcQuantities                                 65002UL //0x0FDEA
#define	PGN65003_Bus1PhaseABasicAcQuantities                                 65003UL //0x0FDEB
#define	PGN65004_Bus1AverageBasicAcQuantities                                65004UL //0x0FDEC
#define	PGN65005_UtilityTotalAcEnergy                                        65005UL //0x0FDED
#define	PGN65006_UtilityPhaseCAcReactivePower                                65006UL //0x0FDEE
#define	PGN65007_UtilityPhaseCAcPower                                        65007UL //0x0FDEF
#define	PGN65008_UtilityPhaseCBasicAcQuantities                              65008UL //0x0FDF0
#define	PGN65009_UtilityPhaseBAcReactivePower                                65009UL //0x0FDF1
#define	PGN65010_UtilityPhaseBAcPower                                        65010UL //0x0FDF2
#define	PGN65011_UtilityPhaseBBasicAcQuantities                              65011UL //0x0FDF3
#define	PGN65012_UtilityPhaseAAcReactivePower                                65012UL //0x0FDF4
#define	PGN65013_UtilityPhaseAAcPower                                        65013UL //0x0FDF5
#define	PGN65014_UtilityPhaseABasicAcQuantities                              65014UL //0x0FDF6
#define	PGN65015_UtilityTotalAcReactivePower                                 65015UL //0x0FDF7
#define	PGN65016_UtilityTotalAcPower                                         65016UL //0x0FDF8
#define	PGN65017_UtilityAverageBasicAcQuantities                             65017UL //0x0FDF9
#define	PGN65018_GeneratorTotalAcEnergy                                      65018UL //0x0FDFA
#define	PGN65019_GeneratorPhaseCAcReactivePower                              65019UL //0x0FDFB
#define	PGN65020_GeneratorPhaseCAcPower                                      65020UL //0x0FDFC
#define	PGN65021_GeneratorPhaseCBasicAcQuantities                            65021UL //0x0FDFD
#define	PGN65022_GeneratorPhaseBAcReactivePower                              65022UL //0x0FDFE
#define	PGN65023_GeneratorPhaseBAcPower                                      65023UL //0x0FDFF
#define	PGN65024_GeneratorPhaseBBasicAcQuantities                            65024UL //0x0FE00
#define	PGN65025_GeneratorPhaseAAcReactivePower                              65025UL //0x0FE01
#define	PGN65026_GeneratorPhaseAAcPower                                      65026UL //0x0FE02
#define	PGN65027_GeneratorPhaseABasicAcQuantities                            65027UL //0x0FE03
#define	PGN65028_GeneratorTotalAcReactivePower                               65028UL //0x0FE04
#define	PGN65029_GeneratorTotalAcPower                                       65029UL //0x0FE05
#define	PGN65030_GeneratorAverageBasicAcQuantities                           65030UL //0x0FE06
#define	PGN65240_IsoCommandedAddress                                         65240UL //0x0FED8
#define	PGN65280_FurunoHeave                                                 65280UL //0x0FF00
#define	PGN65280_ManufacturerProprietarySingleFrameNonAddressed              65280UL //0x0FF00
#define	PGN65284_MaretronProprietaryDcBreakerCurrent                         65284UL //0x0FF04
#define	PGN65285_AirmarBootStateAcknowledgment                               65285UL //0x0FF05
#define	PGN65285_LowranceTemperature                                         65285UL //0x0FF05
#define	PGN65286_ChetcoDimmer                                                65286UL //0x0FF06
#define	PGN65286_AirmarBootStateRequest                                      65286UL //0x0FF06
#define	PGN65287_AirmarAccessLevel                                           65287UL //0x0FF07
#define	PGN65287_SimnetConfigureTemperatureSensor                            65287UL //0x0FF07
#define	PGN65288_SeatalkAlarm                                                65288UL //0x0FF08
#define	PGN65289_SimnetTrimTabSensorCalibration                              65289UL //0x0FF09
#define	PGN65290_SimnetPaddleWheelSpeedConfiguration                         65290UL //0x0FF0A
#define	PGN65292_SimnetClearFluidLevelWarnings                               65292UL //0x0FF0C
#define	PGN65293_SimnetLgc2000Configuration                                  65293UL //0x0FF0D
#define	PGN65309_NavicoWirelessBatteryStatus                                 65309UL //0x0FF1D
#define	PGN65312_NavicoWirelessSignalStatus                                  65312UL //0x0FF20
#define	PGN65325_SimnetReprogramStatus                                       65325UL //0x0FF2D
#define	PGN65341_SimnetAutopilotMode                                         65341UL //0x0FF3D
#define	PGN65345_SeatalkPilotWindDatum                                       65345UL //0x0FF41
#define	PGN65359_SeatalkPilotHeading                                         65359UL //0x0FF4F
#define	PGN65360_SeatalkPilotLockedHeading                                   65360UL //0x0FF50
#define	PGN65361_SeatalkSilenceAlarm                                         65361UL //0x0FF51
#define	PGN65371_SeatalkKeypadMessage                                        65371UL //0x0FF5B
#define	PGN65374_SeatalkKeypadHeartbeat                                      65374UL //0x0FF5E
#define	PGN65379_SeatalkPilotMode                                            65379UL //0x0FF63
#define	PGN65408_AirmarDepthQualityFactor                                    65408UL //0x0FF80
#define	PGN65409_AirmarSpeedPulseCount                                       65409UL //0x0FF81
#define	PGN65410_AirmarDeviceInformation                                     65410UL //0x0FF82
#define	PGN65480_SimnetAutopilotMode                                         65480UL //0x0FFC8
#define	PGN65536_UnknownFastPacketAddressed                                  65536UL //0x10000
#define	PGN126208_NmeaGeneral                                                126208UL //0x1ED00
#define	PGN126208_NmeaRequestGroupFunction                                   126208UL //0x1ED00
#define	PGN126208_NmeaCommandGroupFunction                                   126208UL //0x1ED00
#define	PGN126208_NmeaAcknowledgeGroupFunction                               126211UL //0x1ED00
#define	PGN126208_NmeaReadFieldsGroupFunction                                126208UL //0x1ED00
#define	PGN126208_NmeaReadFieldsReplyGroupFunction                           126208UL //0x1ED00
#define	PGN126208_NmeaWriteFieldsGroupFunction                               126208UL //0x1ED00
#define	PGN126208_NmeaWriteFieldsReplyGroupFunction                          126208UL //0x1ED00
#define	PGN126464_PgnListTransmitAndReceive                                  126464UL //0x1EE00
#define	PGN126720_FusionMediaControl                                         126720UL //0x1EF00
#define	PGN126720_FusionSiriusControl                                        126720UL //0x1EF00
#define	PGN126720_FusionRequestStatus                                        126720UL //0x1EF00
#define	PGN126720_FusionSetSource                                            126720UL //0x1EF00
#define	PGN126720_FusionMute                                                 126720UL //0x1EF00
#define	PGN126720_FusionSetZoneVolume                                        126720UL //0x1EF00
#define	PGN126720_FusionSetAllVolumes                                        126720UL //0x1EF00
#define	PGN126720_Seatalk1PilotMode                                          126720UL //0x1EF00
#define	PGN126720_Seatalk1Keystroke                                          126720UL //0x1EF00
#define	PGN126720_Seatalk1DeviceIdentification                               126720UL //0x1EF00
#define	PGN126720_AirmarAttitudeOffset                                       126720UL //0x1EF00
#define	PGN126720_AirmarCalibrateCompass                                     126720UL //0x1EF00
#define	PGN126720_AirmarTrueWindOptions                                      126720UL //0x1EF00
#define	PGN126720_AirmarSimulateMode                                         126720UL //0x1EF00
#define	PGN126720_AirmarCalibrateDepth                                       126720UL //0x1EF00
#define	PGN126720_AirmarCalibrateSpeed                                       126720UL //0x1EF00
#define	PGN126720_AirmarCalibrateTemperature                                 126720UL //0x1EF00
#define	PGN126720_AirmarSpeedFilter                                          126720UL //0x1EF00
#define	PGN126720_AirmarTemperatureFilter                                    126720UL //0x1EF00
#define	PGN126720_AirmarNmea2000Options                                      126720UL //0x1EF00
#define	PGN126720_AirmarAddressableMultiFrame                                126720UL //0x1EF00
#define	PGN126720_MaretronSlaveResponse                                      126720UL //0x1EF00
#define	PGN126720_ManufacturerProprietaryFastPacketAddressed                 126720UL //0x1EF00
#define	PGN126976_UnknownFastPacketNonAddressed                              126976UL //0x1F000
#define	PGN126983_Alert                                                      126983UL //0x1F007
#define	PGN126984_AlertResponse                                              126984UL //0x1F008
#define	PGN126985_AlertText                                                  126985UL //0x1F009
#define	PGN126986_AlertConfiguration                                         126986UL //0x1F00A
#define	PGN126987_AlertThreshold                                             126987UL //0x1F00B
#define	PGN126988_AlertValue                                                 126988UL //0x1F00C
#define	PGN126992_SystemTime                                                 126992UL //0x1F010
#define	PGN126993_Heartbeat                                                  126993UL //0x1F011
#define	PGN126996_ProductInformation                                         126996UL //0x1F014
#define	PGN126998_ConfigurationInformation                                   126998UL //0x1F016
#define	PGN127233_ManOverboardNotification                                   127233UL //0x1F101
#define	PGN127237_HeadingTrackControl                                        127237UL //0x1F105
#define	PGN127245_Rudder                                                     127245UL //0x1F10D
#define	PGN127250_VesselHeading                                              127250UL //0x1F112
#define	PGN127251_RateOfTurn                                                 127251UL //0x1F113
#define	PGN127252_Heave                                                      127252UL //0x1F114
#define	PGN127257_Attitude                                                   127257UL //0x1F119
#define	PGN127258_MagneticVariation                                          127258UL //0x1F11A
#define	PGN127488_EngineParametersRapidUpdate                                127488UL //0x1F200
#define	PGN127489_EngineParametersDynamic                                    127489UL //0x1F201
#define	PGN127493_TransmissionParametersDynamic                              127493UL //0x1F205
#define	PGN127496_TripParametersVessel                                       127496UL //0x1F208
#define	PGN127497_TripParametersEngine                                       127497UL //0x1F209
#define	PGN127498_EngineParametersStatic                                     127498UL //0x1F20A
#define	PGN127500_LoadControllerConnectionStateControl                       127500UL //0x1F20C
#define	PGN127501_BinarySwitchBankStatus                                     127501UL //0x1F20D
#define	PGN127502_SwitchBankControl                                          127502UL //0x1F20E
#define	PGN127503_AcInputStatus                                              127503UL //0x1F20F
#define	PGN127504_AcOutputStatus                                             127504UL //0x1F210
#define	PGN127505_FluidLevel                                                 127505UL //0x1F211
#define	PGN127506_DcDetailedStatus                                           127506UL //0x1F212
#define	PGN127507_ChargerStatus                                              127507UL //0x1F213
#define	PGN127508_BatteryStatus                                              127508UL //0x1F214
#define	PGN127509_InverterStatus                                             127509UL //0x1F215
#define	PGN127510_ChargerConfigurationStatus                                 127510UL //0x1F216
#define	PGN127511_InverterConfigurationStatus                                127511UL //0x1F217
#define	PGN127512_AgsConfigurationStatus                                     127512UL //0x1F218
#define	PGN127513_BatteryConfigurationStatus                                 127513UL //0x1F219
#define	PGN127514_AgsStatus                                                  127514UL //0x1F21A
#define	PGN127744_AcPowerCurrentPhaseA                                       127744UL //0x1F300
#define	PGN127745_AcPowerCurrentPhaseB                                       127745UL //0x1F301
#define	PGN127746_AcPowerCurrentPhaseC                                       127746UL //0x1F302
#define	PGN127750_ConverterStatus                                            127750UL //0x1F306
#define	PGN127751_DcVoltageCurrent                                           127751UL //0x1F307
#define	PGN128000_LeewayAngle                                                128000UL //0x1F400
#define	PGN128259_Speed                                                      128259UL //0x1F503
#define	PGN128267_WaterDepth                                                 128267UL //0x1F50B
#define	PGN128275_DistanceLog                                                128275UL //0x1F513
#define	PGN128520_TrackedTargetData                                          128520UL //0x1F608
#define	PGN128776_WindlassControlStatus                                      128776UL //0x1F708
#define	PGN128777_AnchorWindlassOperatingStatus                              128777UL //0x1F709
#define	PGN128778_AnchorWindlassMonitoringStatus                             128778UL //0x1F70A
#define	PGN129025_PositionRapidUpdate                                        129025UL //0x1F801
#define	PGN129026_CogSogRapidUpdate                                          129026UL //0x1F802
#define	PGN129027_PositionDeltaRapidUpdate                                   129027UL //0x1F803
#define	PGN129028_AltitudeDeltaRapidUpdate                                   129028UL //0x1F804
#define	PGN129029_GnssPositionData                                           129029UL //0x1F805
#define	PGN129033_TimeDate                                                   129033UL //0x1F809
#define	PGN129038_AisClassAPositionReport                                    129038UL //0x1F80E
#define	PGN129039_AisClassBPositionReport                                    129039UL //0x1F80F
#define	PGN129040_AisClassBExtendedPositionReport                            129040UL //0x1F810
#define	PGN129041_AisAidsToNavigationAtonReport                              129041UL //0x1F811
#define	PGN129044_Datum                                                      129044UL //0x1F814
#define	PGN129045_UserDatum                                                  129045UL //0x1F815
#define	PGN129283_CrossTrackError                                            129283UL //0x1F903
#define	PGN129284_NavigationData                                             129284UL //0x1F904
#define	PGN129285_NavigationRouteWpInformation                               129285UL //0x1F905
#define	PGN129291_SetDriftRapidUpdate                                        129291UL //0x1F90B
#define	PGN129301_NavigationRouteTimeToFromMark                              129301UL //0x1F915
#define	PGN129302_BearingAndDistanceBetweenTwoMarks                          129302UL //0x1F916
#define	PGN129538_GnssControlStatus                                          129538UL //0x1FA02
#define	PGN129539_GnssDops                                                   129539UL //0x1FA03
#define	PGN129540_GnssSatsInView                                             129540UL //0x1FA04
#define	PGN129541_GpsAlmanacData                                             129541UL //0x1FA05
#define	PGN129542_GnssPseudorangeNoiseStatistics                             129542UL //0x1FA06
#define	PGN129545_GnssRaimOutput                                             129545UL //0x1FA09
#define	PGN129546_GnssRaimSettings                                           129546UL //0x1FA0A
#define	PGN129547_GnssPseudorangeErrorStatistics                             129547UL //0x1FA0B
#define	PGN129549_DgnssCorrections                                           129549UL //0x1FA0D
#define	PGN129550_GnssDifferentialCorrectionReceiverInterface                129550UL //0x1FA0E
#define	PGN129551_GnssDifferentialCorrectionReceiverSignal                   129551UL //0x1FA0F
#define	PGN129556_GlonassAlmanacData                                         129556UL //0x1FA14
#define	PGN129792_AisDgnssBroadcastBinaryMessage                             129792UL //0x1FB00
#define	PGN129793_AisUtcAndDateReport                                        129793UL //0x1FB01
#define	PGN129794_AisClassAStaticAndVoyageRelatedData                        129794UL //0x1FB02
#define	PGN129795_AisAddressedBinaryMessage                                  129795UL //0x1FB03
#define	PGN129796_AisAcknowledge                                             129796UL //0x1FB04
#define	PGN129797_AisBinaryBroadcastMessage                                  129797UL //0x1FB05
#define	PGN129798_AisSarAircraftPositionReport                               129798UL //0x1FB06
#define	PGN129799_RadioFrequencyModePower                                    129799UL //0x1FB07
#define	PGN129800_AisUtcDateInquiry                                          129800UL //0x1FB08
#define	PGN129801_AisAddressedSafetyRelatedMessage                           129801UL //0x1FB09
#define	PGN129802_AisSafetyRelatedBroadcastMessage                           129802UL //0x1FB0A
#define	PGN129803_AisInterrogation                                           129803UL //0x1FB0B
#define	PGN129804_AisAssignmentModeCommand                                   129804UL //0x1FB0C
#define	PGN129805_AisDataLinkManagementMessage                               129805UL //0x1FB0D
#define	PGN129806_AisChannelManagement                                       129806UL //0x1FB0E
#define	PGN129807_AisClassBGroupAssignment                                   129807UL //0x1FB0F
#define	PGN129808_DscDistressCallInformation                                 129808UL //0x1FB10
#define	PGN129808_DscCallInformation                                         129808UL //0x1FB10
#define	PGN129809_AisClassBStaticDataMsg24PartA                              129809UL //0x1FB11
#define	PGN129810_AisClassBStaticDataMsg24PartB                              129810UL //0x1FB12
#define	PGN130060_Label                                                      130060UL //0x1FC0C
#define	PGN130061_ChannelSourceConfiguration                                 130061UL //0x1FC0D
#define	PGN130064_RouteAndWpServiceDatabaseList                              130064UL //0x1FC10
#define	PGN130065_RouteAndWpServiceRouteList                                 130065UL //0x1FC11
#define	PGN130066_RouteAndWpServiceRouteWpListAttributes                     130066UL //0x1FC12
#define	PGN130067_RouteAndWpServiceRouteWpNamePosition                       130067UL //0x1FC13
#define	PGN130068_RouteAndWpServiceRouteWpName                               130068UL //0x1FC14
#define	PGN130069_RouteAndWpServiceXteLimitNavigationMethod                  130069UL //0x1FC15
#define	PGN130070_RouteAndWpServiceWpComment                                 130070UL //0x1FC16
#define	PGN130071_RouteAndWpServiceRouteComment                              130071UL //0x1FC17
#define	PGN130072_RouteAndWpServiceDatabaseComment                           130072UL //0x1FC18
#define	PGN130073_RouteAndWpServiceRadiusOfTurn                              130073UL //0x1FC19
#define	PGN130074_RouteAndWpServiceWpListWpNamePosition                      130074UL //0x1FC1A
#define	PGN130306_WindData                                                   130306UL //0x1FD02
#define	PGN130310_EnvironmentalParameters                                    130310UL //0x1FD06
#define	PGN130311_EnvironmentalParameters                                    130311UL //0x1FD07
#define	PGN130312_Temperature                                                130312UL //0x1FD08
#define	PGN130313_Humidity                                                   130313UL //0x1FD09
#define	PGN130314_ActualPressure                                             130314UL //0x1FD0A
#define	PGN130315_SetPressure                                                130315UL //0x1FD0B
#define	PGN130316_TemperatureExtendedRange                                   130316UL //0x1FD0C
#define	PGN130320_TideStationData                                            130320UL //0x1FD10
#define	PGN130321_SalinityStationData                                        130321UL //0x1FD11
#define	PGN130322_CurrentStationData                                         130322UL //0x1FD12
#define	PGN130323_MeteorologicalStationData                                  130323UL //0x1FD13
#define	PGN130324_MooredBuoyStationData                                      130324UL //0x1FD14
#define	PGN130560_PayloadMass                                                130560UL //0x1FE00
#define	PGN130567_WatermakerInputSettingAndStatus                            130567UL //0x1FE07
#define	PGN130569_CurrentStatusAndFile                                       130569UL //0x1FE09
#define	PGN130570_LibraryDataFile                                            130570UL //0x1FE0A
#define	PGN130571_LibraryDataGroup                                           130571UL //0x1FE0B
#define	PGN130572_LibraryDataSearch                                          130572UL //0x1FE0C
#define	PGN130573_SupportedSourceData                                        130573UL //0x1FE0D
#define	PGN130574_SupportedZoneData                                          130574UL //0x1FE0E
#define	PGN130576_SmallCraftStatus                                           130576UL //0x1FE10
#define	PGN130577_DirectionData                                              130577UL //0x1FE11
#define	PGN130578_VesselSpeedComponents                                      130578UL //0x1FE12
#define	PGN130579_SystemConfiguration                                        130579UL //0x1FE13
#define	PGN130580_SystemConfigurationDeprecated                              130580UL //0x1FE14
#define	PGN130581_ZoneConfigurationDeprecated                                130581UL //0x1FE15
#define	PGN130582_ZoneVolume                                                 130582UL //0x1FE16
#define	PGN130583_AvailableAudioEqPresets                                    130583UL //0x1FE17
#define	PGN130584_AvailableBluetoothAddresses                                130584UL //0x1FE18
#define	PGN130585_BluetoothSourceStatus                                      130585UL //0x1FE19
#define	PGN130586_ZoneConfiguration                                          130586UL //0x1FE1A
#define	PGN130816_SonichubInit2                                              130816UL //0x1FF00
#define	PGN130816_SonichubAmRadio                                            130816UL //0x1FF00
#define	PGN130816_SonichubZoneInfo                                           130816UL //0x1FF00
#define	PGN130816_SonichubSource                                             130816UL //0x1FF00
#define	PGN130816_SonichubSourceList                                         130816UL //0x1FF00
#define	PGN130816_SonichubControl                                            130816UL //0x1FF00
#define	PGN130816_SonichubUnknown                                            130816UL //0x1FF00
#define	PGN130816_SonichubFmRadio                                            130816UL //0x1FF00
#define	PGN130816_SonichubPlaylist                                           130816UL //0x1FF00
#define	PGN130816_SonichubTrack                                              130816UL //0x1FF00
#define	PGN130816_SonichubArtist                                             130816UL //0x1FF00
#define	PGN130816_SonichubAlbum                                              130816UL //0x1FF00
#define	PGN130816_SonichubMenuItem                                           130816UL //0x1FF00
#define	PGN130816_SonichubZones                                              130816UL //0x1FF00
#define	PGN130816_SonichubMaxVolume                                          130816UL //0x1FF00
#define	PGN130816_SonichubVolume                                             130816UL //0x1FF00
#define	PGN130816_SonichubInit1                                              130816UL //0x1FF00
#define	PGN130816_SonichubPosition                                           130816UL //0x1FF00
#define	PGN130816_SonichubInit3                                              130816UL //0x1FF00
#define	PGN130816_SimradTextMessage                                          130816UL //0x1FF00
#define	PGN130816_ManufacturerProprietaryFastPacketNonAddressed              130816UL //0x1FF00
#define	PGN130817_NavicoProductInformation                                   130817UL //0x1FF01
#define	PGN130818_SimnetReprogramData                                        130818UL //0x1FF02
#define	PGN130819_SimnetRequestReprogram                                     130819UL //0x1FF03
#define	PGN130820_SimnetReprogramStatus                                      130820UL //0x1FF04
#define	PGN130820_FurunoUnknown                                              130820UL //0x1FF04
#define	PGN130820_FusionSourceName                                           130820UL //0x1FF04
#define	PGN130820_FusionTrackInfo                                            130820UL //0x1FF04
#define	PGN130820_FusionTrack                                                130820UL //0x1FF04
#define	PGN130820_FusionArtist                                               130820UL //0x1FF04
#define	PGN130820_FusionAlbum                                                130820UL //0x1FF04
#define	PGN130820_FusionUnitName                                             130820UL //0x1FF04
#define	PGN130820_FusionZoneName                                             130820UL //0x1FF04
#define	PGN130820_FusionPlayProgress                                         130820UL //0x1FF04
#define	PGN130820_FusionAmFmStation                                          130820UL //0x1FF04
#define	PGN130820_FusionVhf                                                  130820UL //0x1FF04
#define	PGN130820_FusionSquelch                                              130820UL //0x1FF04
#define	PGN130820_FusionScan                                                 130820UL //0x1FF04
#define	PGN130820_FusionMenuItem                                             130820UL //0x1FF04
#define	PGN130820_FusionReplay                                               130820UL //0x1FF04
#define	PGN130820_FusionMute                                                 130820UL //0x1FF04
#define	PGN130820_FusionSubVolume                                            130820UL //0x1FF04
#define	PGN130820_FusionTone                                                 130820UL //0x1FF04
#define	PGN130820_FusionVolume                                               130820UL //0x1FF04
#define	PGN130820_FusionPowerState                                           130820UL //0x1FF04
#define	PGN130820_FusionSiriusxmChannel                                      130820UL //0x1FF04
#define	PGN130820_FusionSiriusxmTitle                                        130820UL //0x1FF04
#define	PGN130820_FusionSiriusxmArtist                                       130820UL //0x1FF04
#define	PGN130820_FusionSiriusxmGenre                                        130820UL //0x1FF04
#define	PGN130821_FurunoUnknown                                              130821UL //0x1FF05
#define	PGN130824_BGWindData                                                 130824UL //0x1FF08
#define	PGN130824_MaretronAnnunciator                                        130824UL //0x1FF08
#define	PGN130827_LowranceUnknown                                            130827UL //0x1FF0B
#define	PGN130828_SimnetSetSerialNumber                                      130828UL //0x1FF0C
#define	PGN130831_SuzukiEngineAndStorageDeviceConfig                         130831UL //0x1FF0F
#define	PGN130832_SimnetFuelUsedHighResolution                               130832UL //0x1FF10
#define	PGN130834_SimnetEngineAndTankConfiguration                           130834UL //0x1FF12
#define	PGN130835_SimnetSetEngineAndTankConfiguration                        130835UL //0x1FF13
#define	PGN130836_SimnetFluidLevelSensorConfiguration                        130836UL //0x1FF14
#define	PGN130836_MaretronProprietarySwitchStatusCounter                     130836UL //0x1FF14
#define	PGN130837_SimnetFuelFlowTurbineConfiguration                         130837UL //0x1FF15
#define	PGN130837_MaretronProprietarySwitchStatusTimer                       130837UL //0x1FF15
#define	PGN130838_SimnetFluidLevelWarning                                    130838UL //0x1FF16
#define	PGN130839_SimnetPressureSensorConfiguration                          130839UL //0x1FF17
#define	PGN130840_SimnetDataUserGroupConfiguration                           130840UL //0x1FF18
#define	PGN130842_SimnetAisClassBStaticDataMsg24PartA                        130842UL //0x1FF1A
#define	PGN130842_FurunoSixDegreesOfFreedomMovement                          130842UL //0x1FF1A
#define	PGN130842_SimnetAisClassBStaticDataMsg24PartB                        130842UL //0x1FF1A
#define	PGN130843_FurunoHeelAngleRollInformation                             130843UL //0x1FF1B
#define	PGN130843_SimnetSonarStatusFrequencyAndDspVoltage                    130843UL //0x1FF1B
#define	PGN130845_SimnetCompassHeadingOffset                                 130845UL //0x1FF1D
#define	PGN130845_FurunoMultiSatsInViewExtended                              130845UL //0x1FF1D
#define	PGN130845_SimnetCompassLocalField                                    130845UL //0x1FF1D
#define	PGN130845_SimnetCompassFieldAngle                                    130845UL //0x1FF1D
#define	PGN130845_SimnetParameterHandle                                      130845UL //0x1FF1D
#define	PGN130846_FurunoMotionSensorStatusExtended                           130846UL //0x1FF1E
#define	PGN130847_SeatalkNodeStatistics                                      130847UL //0x1FF1F
#define	PGN130850_SimnetEventCommandApCommand                                130850UL //0x1FF22
#define	PGN130850_SimnetEventCommandAlarm                                    130850UL //0x1FF22
#define	PGN130850_SimnetEventCommandUnknown                                  130850UL //0x1FF22
#define	PGN130851_SimnetEventReplyApCommand                                  130851UL //0x1FF23
#define	PGN130856_SimnetAlarmMessage                                         130856UL //0x1FF28
#define	PGN130880_AirmarAdditionalWeatherData                                130880UL //0x1FF40
#define	PGN130881_AirmarHeaterControl                                        130881UL //0x1FF41
#define	PGN130944_AirmarPost                                                 130944UL //0x1FF80

#define ClassCode10SystemTools                              10  /*Equipment that queries and measures NMEA 2000 bus traffic andmay be used to configure, troubleshoot and/or test. System Toolsshall not be permanently connected to the NMEA 2000 bus. */
#define ClassCode20SafetySystems                            20  /*Equipment that is inheritantly designed to ensure personnel and/orvessel safety by recording, detecting, and/or alerting onsafety/security related occurances. */
#define ClassCode25InterIntranetworkDevice                  25  /*NMEA 2000 equipment used as nodes to interconnectcommunication paths, including both inter- and intra- networkcommunication */
#define ClassCode30ElectricalDistribution                   30  /*Equipment that monitors and/or controls non-propulsion electricalpower use aboard a vessel. */
#define ClassCode35ElectricalGeneration                     35  /*Equipment that outputs electrical "power", not used primarily topropel the vessel */
#define ClassCode40SteeringAndControlSurfaces               40  /*Equipment used to change the direction and/or attitude of thevessel {Formerly 'Steering Systems'}Follow-up controller (Helm/JoyStick/etc.)Mode controllerDevices that employ a mechanical, electrical or hydraulic system toguide the ship without assistance from a human being (also knownas self-steering gear) {Formerly 'Automatic Steering Controller'} */
#define ClassCode50Propulsion                               50  /*Equipment used to move the vessel (ex. Trolling, Thruster, Kicker,and Propulsion devices) {Formerly Propulsion Systems} */
#define ClassCode60Navigation                               60  /*Equipment that provide information related to the passage of thevessel and potental obstructions/hazards {Formerly NavigationSystems} */
#define ClassCode70Communication                            70  /*Equipment used to communicate ship to ship, ship to shore, orintra ship, such as VHF, SSB, Intercom(s) and SATCOMs, etc.{Formerly Communications Systems} */
#define ClassCode75SensorCommunicationInterface             75  /*Equipment that measures one or more of the same parameter perfunction code for general purpose use. Devices under this classcode may require configuration, such as temperature source. Forexample a device that reports data from two (2) temperaturesensors would require one address (Class 75, Function 130). Adevice that reports data from one (1) temperature sensor and one(1) pressure sensor would require two (2) addresses, one to reportthe temperature (Class 75, Function 130) and one to report thepressure (Class 75, Function 140) */
#define ClassCode80InstrumentationGeneralSystems            80  /*Instrumentation/General systems {Deprecated class and assignedDEPRECATED - Class not for use in new    functions - see specific functions for recommendations for futuredesigns! */
#define ClassCode85ExternalEnvironment                      85  /*Equipment monitoring the meteorological conditions on the exteriorof the vessel. */
#define ClassCode90InternalEnvironment                      90  /*Equipment monitoring the conditions of interior spaces such ascabins, compartments and engine rooms. {Formerly Environmental(HVAC) Systems} */
#define ClassCode100DeckCargoAndFishingEquipment           100  /*Deck, cargo and fishing equipment systems */
#define ClassCode120Display                                120  /*Equipment that provides visual or audible indication/reporting ofdata parameters */
#define ClassCode125Entertainment                          125  /*Multimedia or other communication equipment not impacting safevessel navigation. */
#define ClassCode130                                       130
#define Class10Function130Diagnostic                       130
#define Class10Function140BusTrafficLogger                 140
#define Class20Function110AlarmEnunciator                  110
#define Class20Function130EmergencyPositionIndicatingRadio 130
#define Class20Function135ManOverboard                     135
#define Class25Function130PcGateway                        130
#define Class25Function131Nmea2000ToAnalogGateway          131
#define Class25Function132AnalogToNmea2000Gateway          132
#define Class25Function135Nmea0183Gateway                  135
#define Class25Function140Router                           140
#define Class25Function150Bridge                           150
#define Class25Function160Repeater                         160
#define Class35Function140Engine                           140
#define Class35Function141DcGeneratorAlternator            141
#define Class35Function141SolarPanelSolarArray             141
#define Class35Function143WindGeneratorDc                  143
#define Class35Function144FuelCell                         144
#define Class35Function145NetworkPowerSupply               145
#define Class50Function130EngineroomMonitoring             130
#define Class50Function140Engine                           140
#define Class50Function141DcGeneratorAlternator            141
#define Class50Function150EngineController                 150
#define Class50Function151AcGenerator                      151
#define Class50Function155Motor                            155
#define Class60Function130BottomDepth                      130
#define Class60Function135BottomDepthSpeed                 135
#define Class60Function140OwnshipAttitude                  140
#define Class60Function145OwnshipPositionGnss              145
#define Class60Function150OwnshipPositionLoranC            150
#define Class60Function155Speed                            155
#define Class75Function130Temperature                      130
#define Class80Function130TimeDateSystems                  130
#define Class85Function130Atmospheric                      130
#define Class85Function160Aquatic                          160
#define Class90Function130Hvac                             130
#define Class100Function130ScaleCatch                      130
#define Class120Function130Display                         130
#define Class125Function130MultimediaPlayer                130
#define Class125Function140MultimediaController            140

#define	ManufacturersRegNumARKSEnterprisesInc                                       69	//0x45
#define	ManufacturersRegNumFWMurphyEnovationControls                                78	//0x4E
#define	ManufacturersRegNumTwinDisc                                                 80	//0x50
#define	ManufacturersRegNumKohlerPowerSystems                                       85	//0x55
#define	ManufacturersRegNumHemisphereGPSInc                                         88	//0x58
#define	ManufacturersRegNumBEPMarine                                                116	//0x74
#define	ManufacturersRegNumAirmar                                                   135	//0x87
#define	ManufacturersRegNumMaretron                                                 137	//0x89
#define	ManufacturersRegNumLowrance                                                 140	//0x8C
#define	ManufacturersRegNumMercuryMarine                                            144	//0x90
#define	ManufacturersRegNumNautibusElectronicGmbH                                   147	//0x93
#define	ManufacturersRegNumBlueWaterData                                            148	//0x94
#define	ManufacturersRegNumWesterbeke                                               154	//0x9A
#define	ManufacturersRegNumOffshoreSystemsUKLtd                                     161	//0xA1
#define	ManufacturersRegNumEvinrudeBRP                                              163	//0xA3
#define	ManufacturersRegNumCPACSystemsAB                                            165	//0xA5
#define	ManufacturersRegNumXantrexTechnologyInc                                     168	//0xA8
#define	ManufacturersRegNumYanmarMarine                                             172	//0xAC
#define	ManufacturersRegNumVolvoPenta                                               174	//0xAE
#define	ManufacturersRegNumHondaMarine                                              175	//0xAF
#define	ManufacturersRegNumCarlingTechnologiesIncMoritzAerospace                    176	//0xB0
#define	ManufacturersRegNumBeedeInstruments                                         185	//0xB9
#define	ManufacturersRegNumFloscanInstrumentCoInc                                   192	//0xC0
#define	ManufacturersRegNumNobletec                                                 193	//0xC1
#define	ManufacturersRegNumMysticValleyCommunications                               198	//0xC6
#define	ManufacturersRegNumActia                                                    199	//0xC7
#define	ManufacturersRegNumHondaMarine                                              200	//0xC8
#define	ManufacturersRegNumDisenosYTechnologia                                      201	//0xC9
#define	ManufacturersRegNumDigitalSwitchingSystems                                  211	//0xD3
#define	ManufacturersRegNumXintexAtena                                              215	//0xD7
#define	ManufacturersRegNumEMMINETWORKSL                                            224	//0xE0
#define	ManufacturersRegNumHondaMarine                                              225	//0xE1
#define	ManufacturersRegNumZF                                                       228	//0xE4
#define	ManufacturersRegNumGarmin                                                   229	//0xE5
#define	ManufacturersRegNumYachtMonitoringSolutions                                 233	//0xE9
#define	ManufacturersRegNumSailormadeMarineTelemetryTetraTechnologyLTD              235	//0xEB
#define	ManufacturersRegNumEride                                                    243	//0xF3
#define	ManufacturersRegNumHondaMarine                                              250	//0xFA
#define	ManufacturersRegNumHondaMotorCompanyLTD                                     257	//0x101
#define	ManufacturersRegNumGroco                                                    272	//0x110
#define	ManufacturersRegNumActisense                                                273	//0x111
#define	ManufacturersRegNumAmphenolLTWTechnology                                    274	//0x112
#define	ManufacturersRegNumNavico                                                   275	//0x113
#define	ManufacturersRegNumHamiltonJet                                              283	//0x11B
#define	ManufacturersRegNumSeaRecovery                                              285	//0x11D
#define	ManufacturersRegNumCoelmoSRLItaly                                           286	//0x11E
#define	ManufacturersRegNumBEPMarine                                                295	//0x127
#define	ManufacturersRegNumEmpirBus                                                 304	//0x130
#define	ManufacturersRegNumNovAtel                                                  305	//0x131
#define	ManufacturersRegNumSleipnerMotorAS                                          306	//0x132
#define	ManufacturersRegNumMBWTechnologies                                          307	//0x133
#define	ManufacturersRegNumFischerPanda                                             311	//0x137
#define	ManufacturersRegNumICOM                                                     315	//0x13B
#define	ManufacturersRegNumQwerty                                                   328	//0x148
#define	ManufacturersRegNumDief                                                     329	//0x149
#define	ManufacturersRegNumBoningAutomationstechnologieGmbHAmp                      341	//0x155
#define	ManufacturersRegNumKoreanMaritimeUniversity                                 345	//0x159
#define	ManufacturersRegNumThraneandThrane                                          351	//0x15F
#define	ManufacturersRegNumMastervolt                                               355	//0x163
#define	ManufacturersRegNumFischerPandaGenerators                                   356	//0x164
#define	ManufacturersRegNumVictronEnergy                                            358	//0x166
#define	ManufacturersRegNumRollsRoyceMarine                                         370	//0x172
#define	ManufacturersRegNumElectronicDesign                                         373	//0x175
#define	ManufacturersRegNumNorthernLights                                           374	//0x176
#define	ManufacturersRegNumGlendinning                                              378	//0x17A
#define	ManufacturersRegNumBAmp                                                     381	//0x17D
#define	ManufacturersRegNumRosePointNavigationSystems                               384	//0x180
#define	ManufacturersRegNumJohnsonOutdoorsMarineElectronicsIncGeonav                385	//0x181
#define	ManufacturersRegNumCapi2                                                    394	//0x18A
#define	ManufacturersRegNumBeyondMeasure                                            396	//0x18C
#define	ManufacturersRegNumLivorsiMarine                                            400	//0x190
#define	ManufacturersRegNumComNav                                                   404	//0x194
#define	ManufacturersRegNumChetco                                                   409	//0x199
#define	ManufacturersRegNumFusionElectronics                                        419	//0x1A3
#define	ManufacturersRegNumStandardHorizon                                          421	//0x1A5
#define	ManufacturersRegNumTrueHeadingAB                                            422	//0x1A6
#define	ManufacturersRegNumEgersundMarineElectronicsAS                              426	//0x1AA
#define	ManufacturersRegNumemTrakMarineElectronics                                  427	//0x1AB
#define	ManufacturersRegNumTohatsuCoJP                                              431	//0x1AF
#define	ManufacturersRegNumDigitalYacht                                             437	//0x1B5
#define	ManufacturersRegNumComarSystemsLimited                                      438	//0x1B6
#define	ManufacturersRegNumCummins                                                  440	//0x1B8
#define	ManufacturersRegNumVDOakaContinentalCorporation                             443	//0x1BB
#define	ManufacturersRegNumParkerHannifinakaVillageMarineTech                       451	//0x1C3
#define	ManufacturersRegNumAlltekMarineElectronicsCorp                              459	//0x1CB
#define	ManufacturersRegNumSANGIORGIOSEIN                                           460	//0x1CC
#define	ManufacturersRegNumVeethreeElectronicsAmp                                   466	//0x1D2
#define	ManufacturersRegNumHumminbirdMarineElectronics                              467	//0x1D3
#define	ManufacturersRegNumSiTEXMarineElectronics                                   470	//0x1D6
#define	ManufacturersRegNumSeaCrossMarineAB                                         471	//0x1D7
#define	ManufacturersRegNumGMEakaStandardCommunicationsPtyLTD                       475	//0x1DB
#define	ManufacturersRegNumHumminbirdMarineElectronics                              476	//0x1DC
#define	ManufacturersRegNumOceanSatBV                                               478	//0x1DE
#define	ManufacturersRegNumChetcoDigitialInstruments                                481	//0x1E1
#define	ManufacturersRegNumWatcheye                                                 493	//0x1ED
#define	ManufacturersRegNumLcjCapteurs                                              499	//0x1F3
#define	ManufacturersRegNumAttwoodMarine                                            502	//0x1F6
#define	ManufacturersRegNumNaviopSRL                                                503	//0x1F7
#define	ManufacturersRegNumVesperMarineLtd                                          504	//0x1F8
#define	ManufacturersRegNumMarinesoftCoLTD                                          510	//0x1FE
#define	ManufacturersRegNumNoLandEngineering                                        517	//0x205
#define	ManufacturersRegNumTransasUSA                                               518	//0x206
#define	ManufacturersRegNumNationalInstrumentsKorea                                 529	//0x211
#define	ManufacturersRegNumOnwaMarine                                               532	//0x214
#define	ManufacturersRegNumMarinecraftSouthKorea                                    571	//0x23B
#define	ManufacturersRegNumMcMurdoGroupakaOroliaLTD                                 573	//0x23D
#define	ManufacturersRegNumAdvansea                                                 578	//0x242
#define	ManufacturersRegNumKVH                                                      579	//0x243
#define	ManufacturersRegNumSanJoseTechnology                                        580	//0x244
#define	ManufacturersRegNumYachtControl                                             583	//0x247
#define	ManufacturersRegNumSuzukiMotorCorporation                                   586	//0x24A
#define	ManufacturersRegNumUSCoastGuard                                             591	//0x24F
#define	ManufacturersRegNumShipModuleakaCustomware                                  595	//0x253
#define	ManufacturersRegNumAquaticAV                                                600	//0x258
#define	ManufacturersRegNumAventicsGmbH                                             605	//0x25D
#define	ManufacturersRegNumIntellian                                                606	//0x25E
#define	ManufacturersRegNumSamwonIT                                                 612	//0x264
#define	ManufacturersRegNumArltTecnologies                                          614	//0x266
#define	ManufacturersRegNumBavariaYacts                                             637	//0x27D
#define	ManufacturersRegNumDiverseYachtServices                                     641	//0x281
#define	ManufacturersRegNumWemaUSAdbaKUS                                            644	//0x284
#define	ManufacturersRegNumGarmin                                                   645	//0x285
#define	ManufacturersRegNumShenzhenJiuzhouHimunication                              658	//0x292
#define	ManufacturersRegNumRockfordCorp                                             688	//0x2B0
#define	ManufacturersRegNumJLAudio                                                  704	//0x2C0
#define	ManufacturersRegNumAutonnic                                                 715	//0x2CB
#define	ManufacturersRegNumYachtDevices                                             717	//0x2CD
#define	ManufacturersRegNumREAPSystems                                              734	//0x2DE
#define	ManufacturersRegNumAuElectronicsGroup                                       735	//0x2DF
#define	ManufacturersRegNumLxNav                                                    739	//0x2E3
#define	ManufacturersRegNumDaeMyung                                                 743	//0x2E7
#define	ManufacturersRegNumWoosung                                                  744	//0x2E8
#define	ManufacturersRegNumClarionUS                                                773	//0x305
#define	ManufacturersRegNumHMISystems                                               776	//0x308
#define	ManufacturersRegNumOceanSignal                                              777	//0x309
#define	ManufacturersRegNumSeekeeper                                                778	//0x30A
#define	ManufacturersRegNumPolyPlanar                                               781	//0x30D
#define	ManufacturersRegNumFischerPandaDE                                           785	//0x311
#define	ManufacturersRegNumBroydaIndustries                                         795	//0x31B
#define	ManufacturersRegNumCanadianAutomotive                                       796	//0x31C
#define	ManufacturersRegNumTidesMarine                                              797	//0x31D
#define	ManufacturersRegNumLumishore                                                798	//0x31E
#define	ManufacturersRegNumStillWaterDesignsandAudio                                799	//0x31F
#define	ManufacturersRegNumBJTechnologiesBeneteau                                   802	//0x322
#define	ManufacturersRegNumGillSensors                                              803	//0x323
#define	ManufacturersRegNumBlueWaterDesalination                                    811	//0x32B
#define	ManufacturersRegNumFLIR                                                     815	//0x32F
#define	ManufacturersRegNumUndheimSystems                                           824	//0x338
#define	ManufacturersRegNumTeamSurv                                                 838	//0x346
#define	ManufacturersRegNumFellMarine                                               844	//0x34C
#define	ManufacturersRegNumOceanvolt                                                847	//0x34F
#define	ManufacturersRegNumProspec                                                  862	//0x35E
#define	ManufacturersRegNumDataPanelCorp                                            868	//0x364
#define	ManufacturersRegNumL3Technologies                                           890	//0x37A
#define	ManufacturersRegNumRhodanMarineSystems                                      894	//0x37E
#define	ManufacturersRegNumNexfourSolutions                                         896	//0x380
#define	ManufacturersRegNumASAElectronics                                           905	//0x389
#define	ManufacturersRegNumMarinesCoSouthKorea                                      909	//0x38D
#define	ManufacturersRegNumNauticOn                                                 911	//0x38F
#define	ManufacturersRegNumEcotronix                                                930	//0x3A2
#define	ManufacturersRegNumTimbolierIndustries                                      962	//0x3C2
#define	ManufacturersRegNumTJCMicro                                                 963	//0x3C3
#define	ManufacturersRegNumCoxPowertrain                                            968	//0x3C8
#define	ManufacturersRegNumBlueSeas                                                 969	//0x3C9
#define	ManufacturersRegNumTeleflexMarineSeaStarSolutions                           1850//0x73A
#define	ManufacturersRegNumRaymarine                                                1851//0x73B
#define	ManufacturersRegNumNavionics                                                1852//0x73C
#define	ManufacturersRegNumJapanRadioCo                                             1853//0x73D
#define	ManufacturersRegNumNorthstarTechnologies                                    1854//0x73E
#define	ManufacturersRegNumFuruno                                                   1855//0x73F
#define	ManufacturersRegNumTrimble                                                  1856//0x740
#define	ManufacturersRegNumSimrad                                                   1857//0x741
#define	ManufacturersRegNumLitton                                                   1858//0x742
#define	ManufacturersRegNumKvasarAB                                                 1859//0x743
#define	ManufacturersRegNumMMP                                                      1860//0x744
#define	ManufacturersRegNumVectorCantech                                            1861//0x745
#define	ManufacturersRegNumYamahaMarine                                             1862//0x746
#define	ManufacturersRegNumFariaInstruments                                         1863//0x747

#endif
