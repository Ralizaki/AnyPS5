#include "prx/libSceAudioOut/include/AudioOut.hpp"
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

template <typename TCall>
static bool ReportsNotImplemented(const char* name, TCall call) {
    try {
        call();
    } catch (const std::runtime_error& error) {
        return std::string(error.what()) == std::string(name) + " not implemented";
    }
    return false;
}

int main() {
    Require(sceAudioOutGetSimulatedHandleStatusInfo() == static_cast<int>(0x809B00FF), "simulated handle status info is not supported");
    Require(sceAudioOutGetInfoOpenNum() == 0, "open port count info returns 0");
    Require(sceAudioOutGetInfo() == 0, "port info returns 0");
    Require(ReportsNotImplemented("sceAudioOutPtOpen", [] { return sceAudioOutPtOpen(); }), "sceAudioOutPtOpen reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutPtClose", [] { return sceAudioOutPtClose(); }), "sceAudioOutPtClose reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutPtGetLastOutputTime", [] { return sceAudioOutPtGetLastOutputTime(); }), "sceAudioOutPtGetLastOutputTime reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutExPtOpen", [] { return sceAudioOutExPtOpen(); }), "sceAudioOutExPtOpen reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutExPtClose", [] { return sceAudioOutExPtClose(); }), "sceAudioOutExPtClose reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutExPtGetLastOutputTime", [] { return sceAudioOutExPtGetLastOutputTime(); }), "sceAudioOutExPtGetLastOutputTime reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutExGetLastOutputTime", [] { return sceAudioOutExGetLastOutputTime(); }), "sceAudioOutExGetLastOutputTime reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutSetPadSpkVolume", [] { return sceAudioOutSetPadSpkVolume(); }), "sceAudioOutSetPadSpkVolume reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutSetPadJackVolume", [] { return sceAudioOutSetPadJackVolume(); }), "sceAudioOutSetPadJackVolume reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutSetUsbVolume", [] { return sceAudioOutSetUsbVolume(); }), "sceAudioOutSetUsbVolume reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutSetCaesarVolume", [] { return sceAudioOutSetCaesarVolume(); }), "sceAudioOutSetCaesarVolume reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutSetHeadphoneOutMode", [] { return sceAudioOutSetHeadphoneOutMode(); }), "sceAudioOutSetHeadphoneOutMode reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutGetFocusEnablePid", [] { return sceAudioOutGetFocusEnablePid(); }), "sceAudioOutGetFocusEnablePid reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutSetVolumeDown", [] { return sceAudioOutSetVolumeDown(); }), "sceAudioOutSetVolumeDown reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutSetChatBalance", [] { return sceAudioOutSetChatBalance(); }), "sceAudioOutSetChatBalance reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutSetRecMode", [] { return sceAudioOutSetRecMode(); }), "sceAudioOutSetRecMode reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutSetAllMute", [] { return sceAudioOutSetAllMute(); }), "sceAudioOutSetAllMute reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutSetSparkEQ", [] { return sceAudioOutSetSparkEQ(); }), "sceAudioOutSetSparkEQ reports not implemented");
    Require(ReportsNotImplemented("sceAudioOutArbitrationInitialize", [] { return sceAudioOutArbitrationInitialize(); }), "sceAudioOutArbitrationInitialize reports not implemented");
    std::puts("audio out info calls: PASS");
}
