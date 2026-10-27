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

    std::puts("audio out info calls: PASS");
}
