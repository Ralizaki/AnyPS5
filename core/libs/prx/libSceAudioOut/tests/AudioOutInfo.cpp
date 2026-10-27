#include "prx/libSceAudioOut/include/AudioOut.hpp"
#include "prx/libc/include/general/VabiMacros.hpp"

#include <cstdio>
#include <cstdlib>
#include <stdexcept>

static void Require(bool value, const char* message) {
    if (value) return;
    std::fprintf(stderr, "%s\n", message);
    std::abort();
}

template <typename Call>
static bool Throws(Call call) {
    try {
        call();
    } catch (const std::runtime_error&) {
        return true;
    }
    return false;
}

int main() {
    Require(sceAudioOutGetSimulatedHandleStatusInfo() == static_cast<int>(0x809B00FF), "simulated handle status info is not supported");
    Require(sceAudioOutGetInfoOpenNum() == 0, "open port count info returns 0");
    Require(sceAudioOutGetInfo() == 0, "port info returns 0");

    Require(Throws([] { sceAudioOutOpenEx(); }), "sceAudioOutOpenEx not implemented");
    Require(Throws([] { sceAudioOutSetSystemDebugState(); }), "sceAudioOutSetSystemDebugState not implemented");
    Require(Throws([] { sceAudioOutGetHandleStatusInfo(); }), "sceAudioOutGetHandleStatusInfo not implemented");
    Require(Throws([] { sceAudioOutGetSimulatedHandleStatusInfo2(); }), "sceAudioOutGetSimulatedHandleStatusInfo2 not implemented");
    Require(Throws([] { sceAudioOutChangeAppModuleState(); }), "sceAudioOutChangeAppModuleState not implemented");
    Require(Throws([] { sceAudioOutGetSimulatedBusUsableStatusByBusType(); }), "sceAudioOutGetSimulatedBusUsableStatusByBusType not implemented");
    Require(Throws([] { sceAudioOutAttachToApplicationByPid(); }), "sceAudioOutAttachToApplicationByPid not implemented");
    Require(Throws([] { sceAudioOutDetachFromApplicationByPid(); }), "sceAudioOutDetachFromApplicationByPid not implemented");
    Require(Throws([] { sceAudioOutPtOpen(); }), "sceAudioOutPtOpen not implemented");
    Require(Throws([] { sceAudioOutPtClose(); }), "sceAudioOutPtClose not implemented");
    Require(Throws([] { sceAudioOutPtGetLastOutputTime(); }), "sceAudioOutPtGetLastOutputTime not implemented");
    Require(Throws([] { sceAudioOutExPtOpen(); }), "sceAudioOutExPtOpen not implemented");
    Require(Throws([] { sceAudioOutExPtClose(); }), "sceAudioOutExPtClose not implemented");
    Require(Throws([] { sceAudioOutExPtGetLastOutputTime(); }), "sceAudioOutExPtGetLastOutputTime not implemented");
    Require(Throws([] { sceAudioOutExGetLastOutputTime(); }), "sceAudioOutExGetLastOutputTime not implemented");
    Require(Throws([] { sceAudioOutSetPadSpkVolume(); }), "sceAudioOutSetPadSpkVolume not implemented");
    Require(Throws([] { sceAudioOutSetPadJackVolume(); }), "sceAudioOutSetPadJackVolume not implemented");
    Require(Throws([] { sceAudioOutSetUsbVolume(); }), "sceAudioOutSetUsbVolume not implemented");
    Require(Throws([] { sceAudioOutSetCaesarVolume(); }), "sceAudioOutSetCaesarVolume not implemented");
    Require(Throws([] { sceAudioOutSetHeadphoneOutMode(); }), "sceAudioOutSetHeadphoneOutMode not implemented");
    Require(Throws([] { sceAudioOutGetFocusEnablePid(); }), "sceAudioOutGetFocusEnablePid not implemented");
    Require(Throws([] { sceAudioOutSetVolumeDown(); }), "sceAudioOutSetVolumeDown not implemented");
    Require(Throws([] { sceAudioOutSetChatBalance(); }), "sceAudioOutSetChatBalance not implemented");
    Require(Throws([] { sceAudioOutSetRecMode(); }), "sceAudioOutSetRecMode not implemented");
    Require(Throws([] { sceAudioOutSetAllMute(); }), "sceAudioOutSetAllMute not implemented");
    Require(Throws([] { sceAudioOutSetSparkEQ(); }), "sceAudioOutSetSparkEQ not implemented");
    Require(Throws([] { sceAudioOutArbitrationInitialize(); }), "sceAudioOutArbitrationInitialize not implemented");
    Require(Throws([] { sceAudioOutEnable3DAudioByArbitration(); }), "sceAudioOutEnable3DAudioByArbitration not implemented");
    Require(Throws([] { sceAudioOutAssignHRTF(); }), "sceAudioOutAssignHRTF not implemented");
    Require(Throws([] { sceAudioOutEnable3DAudioForUser(); }), "sceAudioOutEnable3DAudioForUser not implemented");
    Require(Throws([] { sceAudioOutEnableMonoHpOutput(); }), "sceAudioOutEnableMonoHpOutput not implemented");
    Require(Throws([] { sceAudioOutEnableTVVirtual(); }), "sceAudioOutEnableTVVirtual not implemented");
    Require(Throws([] { sceAudioOutEnableTVCorrection(); }), "sceAudioOutEnableTVCorrection not implemented");
    Require(Throws([] { sceAudioOutEnableVrControllerLowPowerMode(); }), "sceAudioOutEnableVrControllerLowPowerMode not implemented");
    Require(Throws([] { sceAudioOutEnableCinematicVrRotation(); }), "sceAudioOutEnableCinematicVrRotation not implemented");
    Require(Throws([] { sceAudioOutCustomHrtfIsExist(); }), "sceAudioOutCustomHrtfIsExist not implemented");
    Require(Throws([] { sceAudioOutExConfigureOutputMode(); }), "sceAudioOutExConfigureOutputMode not implemented");
    Require(Throws([] { sceAudioOutExSystemInfoIsSupportedAudioOutExMode(); }), "sceAudioOutExSystemInfoIsSupportedAudioOutExMode not implemented");
    Require(Throws([] { sceAudioOutExGetSystemInfo(); }), "sceAudioOutExGetSystemInfo not implemented");
    Require(Throws([] { sceAudioOutExGetOutputInfo(); }), "sceAudioOutExGetOutputInfo not implemented");
    Require(Throws([] { sceAudioOutSysConfigureOutputMode(); }), "sceAudioOutSysConfigureOutputMode not implemented");
    Require(Throws([] { sceAudioOutSysGetMonitorInfo(); }), "sceAudioOutSysGetMonitorInfo not implemented");
    Require(Throws([] { sceAudioOutSysHdmiMonitorInfoIsSupportedAudioOutMode(); }), "sceAudioOutSysHdmiMonitorInfoIsSupportedAudioOutMode not implemented");
    Require(Throws([] { sceAudioOutSysGetSystemInfo(); }), "sceAudioOutSysGetSystemInfo not implemented");
    Require(Throws([] { sceAudioOutSysGetOutputInfo(); }), "sceAudioOutSysGetOutputInfo not implemented");

    std::puts("audio out info calls: PASS");
}
