#include "prx/libSceAudioOut/include/AudioOut.hpp"
#include "prx/libSceAudioOut/include/AudioOut2.hpp"
#include "prx/libc/include/general/VabiMacros.hpp"

#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <string>

static void Require(bool value, const char* message) {
    if (value) return;
    std::fprintf(stderr, "%s\n", message);
    std::abort();
}

int main() {
    Require(sceAudioOutGetSimulatedHandleStatusInfo() == static_cast<int>(0x809B00FF), "simulated handle status info is not supported");
    Require(sceAudioOutGetInfoOpenNum() == 0, "open port count info returns 0");
    Require(sceAudioOutGetInfo() == 0, "port info returns 0");
    bool sceAudioOutEnable3DAudioByArbitrationCaught = false;
    try {
        sceAudioOutEnable3DAudioByArbitration();
    } catch (const std::runtime_error& error) {
        sceAudioOutEnable3DAudioByArbitrationCaught = (std::string(error.what()) == "sceAudioOutEnable3DAudioByArbitration not implemented");
    }
    Require(sceAudioOutEnable3DAudioByArbitrationCaught, "sceAudioOutEnable3DAudioByArbitration should throw not implemented");
    bool sceAudioOutAssignHRTFCaught = false;
    try {
        sceAudioOutAssignHRTF();
    } catch (const std::runtime_error& error) {
        sceAudioOutAssignHRTFCaught = (std::string(error.what()) == "sceAudioOutAssignHRTF not implemented");
    }
    Require(sceAudioOutAssignHRTFCaught, "sceAudioOutAssignHRTF should throw not implemented");
    bool sceAudioOutEnable3DAudioForUserCaught = false;
    try {
        sceAudioOutEnable3DAudioForUser();
    } catch (const std::runtime_error& error) {
        sceAudioOutEnable3DAudioForUserCaught = (std::string(error.what()) == "sceAudioOutEnable3DAudioForUser not implemented");
    }
    Require(sceAudioOutEnable3DAudioForUserCaught, "sceAudioOutEnable3DAudioForUser should throw not implemented");
    bool sceAudioOutEnableMonoHpOutputCaught = false;
    try {
        sceAudioOutEnableMonoHpOutput();
    } catch (const std::runtime_error& error) {
        sceAudioOutEnableMonoHpOutputCaught = (std::string(error.what()) == "sceAudioOutEnableMonoHpOutput not implemented");
    }
    Require(sceAudioOutEnableMonoHpOutputCaught, "sceAudioOutEnableMonoHpOutput should throw not implemented");
    bool sceAudioOutEnableTVVirtualCaught = false;
    try {
        sceAudioOutEnableTVVirtual();
    } catch (const std::runtime_error& error) {
        sceAudioOutEnableTVVirtualCaught = (std::string(error.what()) == "sceAudioOutEnableTVVirtual not implemented");
    }
    Require(sceAudioOutEnableTVVirtualCaught, "sceAudioOutEnableTVVirtual should throw not implemented");
    bool sceAudioOutEnableTVCorrectionCaught = false;
    try {
        sceAudioOutEnableTVCorrection();
    } catch (const std::runtime_error& error) {
        sceAudioOutEnableTVCorrectionCaught = (std::string(error.what()) == "sceAudioOutEnableTVCorrection not implemented");
    }
    Require(sceAudioOutEnableTVCorrectionCaught, "sceAudioOutEnableTVCorrection should throw not implemented");
    bool sceAudioOutEnableVrControllerLowPowerModeCaught = false;
    try {
        sceAudioOutEnableVrControllerLowPowerMode();
    } catch (const std::runtime_error& error) {
        sceAudioOutEnableVrControllerLowPowerModeCaught = (std::string(error.what()) == "sceAudioOutEnableVrControllerLowPowerMode not implemented");
    }
    Require(sceAudioOutEnableVrControllerLowPowerModeCaught, "sceAudioOutEnableVrControllerLowPowerMode should throw not implemented");
    bool sceAudioOutEnableCinematicVrRotationCaught = false;
    try {
        sceAudioOutEnableCinematicVrRotation();
    } catch (const std::runtime_error& error) {
        sceAudioOutEnableCinematicVrRotationCaught = (std::string(error.what()) == "sceAudioOutEnableCinematicVrRotation not implemented");
    }
    Require(sceAudioOutEnableCinematicVrRotationCaught, "sceAudioOutEnableCinematicVrRotation should throw not implemented");
    bool sceAudioOutCustomHrtfIsExistCaught = false;
    try {
        sceAudioOutCustomHrtfIsExist();
    } catch (const std::runtime_error& error) {
        sceAudioOutCustomHrtfIsExistCaught = (std::string(error.what()) == "sceAudioOutCustomHrtfIsExist not implemented");
    }
    Require(sceAudioOutCustomHrtfIsExistCaught, "sceAudioOutCustomHrtfIsExist should throw not implemented");
    bool sceAudioOut2UserCreateExCaught = false;
    try {
        sceAudioOut2UserCreateEx();
    } catch (const std::runtime_error& error) {
        sceAudioOut2UserCreateExCaught = (std::string(error.what()) == "sceAudioOut2UserCreateEx not implemented");
    }
    Require(sceAudioOut2UserCreateExCaught, "sceAudioOut2UserCreateEx should throw not implemented");
    bool sceAudioOut2ArbitrationInitializeCaught = false;
    try {
        sceAudioOut2ArbitrationInitialize();
    } catch (const std::runtime_error& error) {
        sceAudioOut2ArbitrationInitializeCaught = (std::string(error.what()) == "sceAudioOut2ArbitrationInitialize not implemented");
    }
    Require(sceAudioOut2ArbitrationInitializeCaught, "sceAudioOut2ArbitrationInitialize should throw not implemented");
    bool sceAudioOut2MbusInitCaught = false;
    try {
        sceAudioOut2MbusInit();
    } catch (const std::runtime_error& error) {
        sceAudioOut2MbusInitCaught = (std::string(error.what()) == "sceAudioOut2MbusInit not implemented");
    }
    Require(sceAudioOut2MbusInitCaught, "sceAudioOut2MbusInit should throw not implemented");
    bool sceAudioOut2MbusSetPortConnectionsCaught = false;
    try {
        sceAudioOut2MbusSetPortConnections();
    } catch (const std::runtime_error& error) {
        sceAudioOut2MbusSetPortConnectionsCaught = (std::string(error.what()) == "sceAudioOut2MbusSetPortConnections not implemented");
    }
    Require(sceAudioOut2MbusSetPortConnectionsCaught, "sceAudioOut2MbusSetPortConnections should throw not implemented");
    bool sceAudioOut2MbusSetConnectionsCaught = false;
    try {
        sceAudioOut2MbusSetConnections();
    } catch (const std::runtime_error& error) {
        sceAudioOut2MbusSetConnectionsCaught = (std::string(error.what()) == "sceAudioOut2MbusSetConnections not implemented");
    }
    Require(sceAudioOut2MbusSetConnectionsCaught, "sceAudioOut2MbusSetConnections should throw not implemented");
    bool sceAudioOut2MbusSetPortStatusesCaught = false;
    try {
        sceAudioOut2MbusSetPortStatuses();
    } catch (const std::runtime_error& error) {
        sceAudioOut2MbusSetPortStatusesCaught = (std::string(error.what()) == "sceAudioOut2MbusSetPortStatuses not implemented");
    }
    Require(sceAudioOut2MbusSetPortStatusesCaught, "sceAudioOut2MbusSetPortStatuses should throw not implemented");
    bool sceAudioOut2MbusSetHeadphoneOutModeCaught = false;
    try {
        sceAudioOut2MbusSetHeadphoneOutMode();
    } catch (const std::runtime_error& error) {
        sceAudioOut2MbusSetHeadphoneOutModeCaught = (std::string(error.what()) == "sceAudioOut2MbusSetHeadphoneOutMode not implemented");
    }
    Require(sceAudioOut2MbusSetHeadphoneOutModeCaught, "sceAudioOut2MbusSetHeadphoneOutMode should throw not implemented");
    bool sceAudioOut2MbusUserLoginFor3DAudioCaught = false;
    try {
        sceAudioOut2MbusUserLoginFor3DAudio();
    } catch (const std::runtime_error& error) {
        sceAudioOut2MbusUserLoginFor3DAudioCaught = (std::string(error.what()) == "sceAudioOut2MbusUserLoginFor3DAudio not implemented");
    }
    Require(sceAudioOut2MbusUserLoginFor3DAudioCaught, "sceAudioOut2MbusUserLoginFor3DAudio should throw not implemented");
    bool sceAudioOut2MbusSetDeviceConnectionsCaught = false;
    try {
        sceAudioOut2MbusSetDeviceConnections();
    } catch (const std::runtime_error& error) {
        sceAudioOut2MbusSetDeviceConnectionsCaught = (std::string(error.what()) == "sceAudioOut2MbusSetDeviceConnections not implemented");
    }
    Require(sceAudioOut2MbusSetDeviceConnectionsCaught, "sceAudioOut2MbusSetDeviceConnections should throw not implemented");
    bool sceAudioOut2MbusSetMorpheusParamCaught = false;
    try {
        sceAudioOut2MbusSetMorpheusParam();
    } catch (const std::runtime_error& error) {
        sceAudioOut2MbusSetMorpheusParamCaught = (std::string(error.what()) == "sceAudioOut2MbusSetMorpheusParam not implemented");
    }
    Require(sceAudioOut2MbusSetMorpheusParamCaught, "sceAudioOut2MbusSetMorpheusParam should throw not implemented");
    bool sceAudioOut2MbusSetCaesarParamCaught = false;
    try {
        sceAudioOut2MbusSetCaesarParam();
    } catch (const std::runtime_error& error) {
        sceAudioOut2MbusSetCaesarParamCaught = (std::string(error.what()) == "sceAudioOut2MbusSetCaesarParam not implemented");
    }
    Require(sceAudioOut2MbusSetCaesarParamCaught, "sceAudioOut2MbusSetCaesarParam should throw not implemented");
    bool sceAudioOut2MbusSetSparkParamCaught = false;
    try {
        sceAudioOut2MbusSetSparkParam();
    } catch (const std::runtime_error& error) {
        sceAudioOut2MbusSetSparkParamCaught = (std::string(error.what()) == "sceAudioOut2MbusSetSparkParam not implemented");
    }
    Require(sceAudioOut2MbusSetSparkParamCaught, "sceAudioOut2MbusSetSparkParam should throw not implemented");
    bool sceAudioOut2AllAudioMainToHeadphoneForDiagCaught = false;
    try {
        sceAudioOut2AllAudioMainToHeadphoneForDiag();
    } catch (const std::runtime_error& error) {
        sceAudioOut2AllAudioMainToHeadphoneForDiagCaught = (std::string(error.what()) == "sceAudioOut2AllAudioMainToHeadphoneForDiag not implemented");
    }
    Require(sceAudioOut2AllAudioMainToHeadphoneForDiagCaught, "sceAudioOut2AllAudioMainToHeadphoneForDiag should throw not implemented");
    bool sceAudioOut2LoPortGetStateExCaught = false;
    try {
        sceAudioOut2LoPortGetStateEx();
    } catch (const std::runtime_error& error) {
        sceAudioOut2LoPortGetStateExCaught = (std::string(error.what()) == "sceAudioOut2LoPortGetStateEx not implemented");
    }
    Require(sceAudioOut2LoPortGetStateExCaught, "sceAudioOut2LoPortGetStateEx should throw not implemented");
    bool sceAudioOut2ReportRegisterHandlerCaught = false;
    try {
        sceAudioOut2ReportRegisterHandler();
    } catch (const std::runtime_error& error) {
        sceAudioOut2ReportRegisterHandlerCaught = (std::string(error.what()) == "sceAudioOut2ReportRegisterHandler not implemented");
    }
    Require(sceAudioOut2ReportRegisterHandlerCaught, "sceAudioOut2ReportRegisterHandler should throw not implemented");
    bool sceAudioOut2ReportUnregisterHandlerCaught = false;
    try {
        sceAudioOut2ReportUnregisterHandler();
    } catch (const std::runtime_error& error) {
        sceAudioOut2ReportUnregisterHandlerCaught = (std::string(error.what()) == "sceAudioOut2ReportUnregisterHandler not implemented");
    }
    Require(sceAudioOut2ReportUnregisterHandlerCaught, "sceAudioOut2ReportUnregisterHandler should throw not implemented");
    bool sceAudioOut2GetTvCorrectionInfoCaught = false;
    try {
        sceAudioOut2GetTvCorrectionInfo();
    } catch (const std::runtime_error& error) {
        sceAudioOut2GetTvCorrectionInfoCaught = (std::string(error.what()) == "sceAudioOut2GetTvCorrectionInfo not implemented");
    }
    Require(sceAudioOut2GetTvCorrectionInfoCaught, "sceAudioOut2GetTvCorrectionInfo should throw not implemented");
    bool sceAudioOut2GetIpcHandleCaught = false;
    try {
        sceAudioOut2GetIpcHandle();
    } catch (const std::runtime_error& error) {
        sceAudioOut2GetIpcHandleCaught = (std::string(error.what()) == "sceAudioOut2GetIpcHandle not implemented");
    }
    Require(sceAudioOut2GetIpcHandleCaught, "sceAudioOut2GetIpcHandle should throw not implemented");
    bool sceAudioOut2GetSystemStateExCaught = false;
    try {
        sceAudioOut2GetSystemStateEx();
    } catch (const std::runtime_error& error) {
        sceAudioOut2GetSystemStateExCaught = (std::string(error.what()) == "sceAudioOut2GetSystemStateEx not implemented");
    }
    Require(sceAudioOut2GetSystemStateExCaught, "sceAudioOut2GetSystemStateEx should throw not implemented");
    bool sceAudioOut2SetDebugHeadphoneModeCaught = false;
    try {
        sceAudioOut2SetDebugHeadphoneMode();
    } catch (const std::runtime_error& error) {
        sceAudioOut2SetDebugHeadphoneModeCaught = (std::string(error.what()) == "sceAudioOut2SetDebugHeadphoneMode not implemented");
    }
    Require(sceAudioOut2SetDebugHeadphoneModeCaught, "sceAudioOut2SetDebugHeadphoneMode should throw not implemented");
    bool sceAudioOut2DebugStateCtrlCaught = false;
    try {
        sceAudioOut2DebugStateCtrl();
    } catch (const std::runtime_error& error) {
        sceAudioOut2DebugStateCtrlCaught = (std::string(error.what()) == "sceAudioOut2DebugStateCtrl not implemented");
    }
    Require(sceAudioOut2DebugStateCtrlCaught, "sceAudioOut2DebugStateCtrl should throw not implemented");
    bool sceAudioOut2ContextBedWriteCaught = false;
    try {
        sceAudioOut2ContextBedWrite();
    } catch (const std::runtime_error& error) {
        sceAudioOut2ContextBedWriteCaught = (std::string(error.what()) == "sceAudioOut2ContextBedWrite not implemented");
    }
    Require(sceAudioOut2ContextBedWriteCaught, "sceAudioOut2ContextBedWrite should throw not implemented");
    bool sceAudioOut2PortCreateExCaught = false;
    try {
        sceAudioOut2PortCreateEx();
    } catch (const std::runtime_error& error) {
        sceAudioOut2PortCreateExCaught = (std::string(error.what()) == "sceAudioOut2PortCreateEx not implemented");
    }
    Require(sceAudioOut2PortCreateExCaught, "sceAudioOut2PortCreateEx should throw not implemented");
    bool sceAudioOut2TerminateCaught = false;
    try {
        sceAudioOut2Terminate();
    } catch (const std::runtime_error& error) {
        sceAudioOut2TerminateCaught = (std::string(error.what()) == "sceAudioOut2Terminate not implemented");
    }
    Require(sceAudioOut2TerminateCaught, "sceAudioOut2Terminate should throw not implemented");
    bool sceAudioOut2PortRegisterCaught = false;
    try {
        sceAudioOut2PortRegister();
    } catch (const std::runtime_error& error) {
        sceAudioOut2PortRegisterCaught = (std::string(error.what()) == "sceAudioOut2PortRegister not implemented");
    }
    Require(sceAudioOut2PortRegisterCaught, "sceAudioOut2PortRegister should throw not implemented");
    bool sceAudioOut2PortUnregisterCaught = false;
    try {
        sceAudioOut2PortUnregister();
    } catch (const std::runtime_error& error) {
        sceAudioOut2PortUnregisterCaught = (std::string(error.what()) == "sceAudioOut2PortUnregister not implemented");
    }
    Require(sceAudioOut2PortUnregisterCaught, "sceAudioOut2PortUnregister should throw not implemented");
    bool sceAudioOut2GetAmbisonicsEncodeCoefficientsCaught = false;
    try {
        sceAudioOut2GetAmbisonicsEncodeCoefficients();
    } catch (const std::runtime_error& error) {
        sceAudioOut2GetAmbisonicsEncodeCoefficientsCaught = (std::string(error.what()) == "sceAudioOut2GetAmbisonicsEncodeCoefficients not implemented");
    }
    Require(sceAudioOut2GetAmbisonicsEncodeCoefficientsCaught, "sceAudioOut2GetAmbisonicsEncodeCoefficients should throw not implemented");
    bool sceAudioOut2GetHrtfIdForCronosCaught = false;
    try {
        sceAudioOut2GetHrtfIdForCronos();
    } catch (const std::runtime_error& error) {
        sceAudioOut2GetHrtfIdForCronosCaught = (std::string(error.what()) == "sceAudioOut2GetHrtfIdForCronos not implemented");
    }
    Require(sceAudioOut2GetHrtfIdForCronosCaught, "sceAudioOut2GetHrtfIdForCronos should throw not implemented");
    std::puts("audio out info calls: PASS");
}
