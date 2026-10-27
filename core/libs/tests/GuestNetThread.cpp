#include "prx/libSceNet/include/Net.hpp"
#include "SceTypes.hpp"
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <stdexcept>
#include <string>

namespace {

constexpr int Einval = 22;
constexpr int Eopnotsupp = 45;
constexpr int NetError = static_cast<int>(0x80410100u);



struct Run {
    std::atomic<int> started{0};
    std::atomic<bool> pastExit{false};
};

Run run;

void Require(bool value, const char* what) {
    if (value) return;
    std::fprintf(stderr, "%s\n", what);
    std::abort();
}

void APS5_VABI Count(void* arg) {
    ++static_cast<Run*>(arg)->started;
}

void APS5_VABI ExitEarly(void* arg) {
    auto* run = static_cast<Run*>(arg);
    ++run->started;
    sceNetThreadExit();
    run->pastExit = true;
}

}

int main() {
    NetThreadParameter counting{Count, &run, 0, 0};
    Pthread thread = nullptr;
    Require(sceNetThreadCreate(&thread, &counting, "anyps5-net-thread") == 0 && thread != nullptr, "sceNetThreadCreate failed");
    Require(sceNetThreadJoin(thread) == 0, "sceNetThreadJoin failed");
    Require(run.started == 1, "the thread did not run its entry with its argument");

    Pthread untouched = reinterpret_cast<Pthread>(&run);
    *sceNetErrnoLoc() = 0;
    Require(sceNetThreadCreate(&untouched, nullptr, "anyps5-net-thread") == (NetError | Einval), "a null parameter was not refused with EINVAL");
    Require(*sceNetErrnoLoc() == Einval && untouched == reinterpret_cast<Pthread>(&run), "a refused create set no errno or wrote the thread");

    NetThreadParameter exiting{ExitEarly, &run, 0, 1};
    Require(sceNetThreadCreate(&thread, &exiting, nullptr) == 0, "sceNetThreadCreate failed without a name");
    Require(sceNetThreadJoin(thread) == 0, "joining an exited thread failed");
    Require(run.started == 2 && !run.pastExit, "sceNetThreadExit did not end the thread");

    static NetThreadParameter detached{Count, &run, 0, 0};
    Require(sceNetThreadCreate(nullptr, &detached, "anyps5-net-thread") == 0, "a null thread output was refused");
    const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(5);
    while (run.started != 3 && std::chrono::steady_clock::now() < deadline) std::this_thread::sleep_for(std::chrono::milliseconds(1));
    Require(run.started == 3, "the thread created without an output did not run");

    *sceNetErrnoLoc() = 0;
    Require(sceNetEmulationGet(nullptr, 0) == (NetError | Eopnotsupp) && *sceNetErrnoLoc() == Eopnotsupp, "sceNetEmulationGet did not return EOPNOTSUPP");
    *sceNetErrnoLoc() = 0;
    Require(sceNetEmulationSet(nullptr, 0) == (NetError | Eopnotsupp) && *sceNetErrnoLoc() == Eopnotsupp, "sceNetEmulationSet did not return EOPNOTSUPP");
    bool controlCaught = false;
    try {
        sceNetControl(0, 0, 0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        controlCaught = (std::string(error.what()) == "sceNetControl not implemented");
    }
    Require(controlCaught, "sceNetControl not implemented");
    bool dbgInitCaught = false;
    try {
        sceNetDbgInit(nullptr, 0);
    } catch (const std::runtime_error& error) {
        dbgInitCaught = (std::string(error.what()) == "sceNetDbgInit not implemented");
    }
    Require(dbgInitCaught, "sceNetDbgInit not implemented");
    bool cbCreateCaught = false;
    try {
        sceNetEventCallbackCreate(0, nullptr, nullptr, 0);
    } catch (const std::runtime_error& error) {
        cbCreateCaught = (std::string(error.what()) == "sceNetEventCallbackCreate not implemented");
    }
    Require(cbCreateCaught, "sceNetEventCallbackCreate not implemented");
    bool cbDestroyCaught = false;
    try {
        sceNetEventCallbackDestroy(0, 0);
    } catch (const std::runtime_error& error) {
        cbDestroyCaught = (std::string(error.what()) == "sceNetEventCallbackDestroy not implemented");
    }
    Require(cbDestroyCaught, "sceNetEventCallbackDestroy not implemented");
    bool cbGetErrorCaught = false;
    try {
        sceNetEventCallbackGetError(0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        cbGetErrorCaught = (std::string(error.what()) == "sceNetEventCallbackGetError not implemented");
    }
    Require(cbGetErrorCaught, "sceNetEventCallbackGetError not implemented");
    bool cbWaitCaught = false;
    try {
        sceNetEventCallbackWaitCB(0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        cbWaitCaught = (std::string(error.what()) == "sceNetEventCallbackWaitCB not implemented");
    }
    Require(cbWaitCaught, "sceNetEventCallbackWaitCB not implemented");
    bool sockIntCaught = false;
    try {
        sceNetSocketInternal(nullptr, 0, 0, 0);
    } catch (const std::runtime_error& error) {
        sockIntCaught = (std::string(error.what()) == "sceNetSocketInternal not implemented");
    }
    Require(sockIntCaught, "sceNetSocketInternal not implemented");
    bool syncCreateCaught = false;
    try {
        sceNetSyncCreate(nullptr, 0, nullptr);
    } catch (const std::runtime_error& error) {
        syncCreateCaught = (std::string(error.what()) == "sceNetSyncCreate not implemented");
    }
    Require(syncCreateCaught, "sceNetSyncCreate not implemented");
    bool syncDestroyCaught = false;
    try {
        sceNetSyncDestroy(nullptr);
    } catch (const std::runtime_error& error) {
        syncDestroyCaught = (std::string(error.what()) == "sceNetSyncDestroy not implemented");
    }
    Require(syncDestroyCaught, "sceNetSyncDestroy not implemented");
    bool syncGetCaught = false;
    try {
        sceNetSyncGet(0);
    } catch (const std::runtime_error& error) {
        syncGetCaught = (std::string(error.what()) == "sceNetSyncGet not implemented");
    }
    Require(syncGetCaught, "sceNetSyncGet not implemented");
    bool syncSignalCaught = false;
    try {
        sceNetSyncSignal(nullptr, 0);
    } catch (const std::runtime_error& error) {
        syncSignalCaught = (std::string(error.what()) == "sceNetSyncSignal not implemented");
    }
    Require(syncSignalCaught, "sceNetSyncSignal not implemented");
    bool syncWaitCaught = false;
    try {
        sceNetSyncWait(nullptr, nullptr);
    } catch (const std::runtime_error& error) {
        syncWaitCaught = (std::string(error.what()) == "sceNetSyncWait not implemented");
    }
    Require(syncWaitCaught, "sceNetSyncWait not implemented");
    bool sysctlCaught = false;
    try {
        sceNetSysctl(nullptr, 0, nullptr, nullptr, nullptr, 0);
    } catch (const std::runtime_error& error) {
        sysctlCaught = (std::string(error.what()) == "sceNetSysctl not implemented");
    }
    Require(sysctlCaught, "sceNetSysctl not implemented");
    bool showIfconfigBufCaught = false;
    try {
        sceNetShowIfconfigForBuffer(nullptr, 0, 0);
    } catch (const std::runtime_error& error) {
        showIfconfigBufCaught = (std::string(error.what()) == "sceNetShowIfconfigForBuffer not implemented");
    }
    Require(showIfconfigBufCaught, "sceNetShowIfconfigForBuffer not implemented");
    bool showRouteBufCaught = false;
    try {
        sceNetShowRouteForBuffer(nullptr, 0, 0);
    } catch (const std::runtime_error& error) {
        showRouteBufCaught = (std::string(error.what()) == "sceNetShowRouteForBuffer not implemented");
    }
    Require(showRouteBufCaught, "sceNetShowRouteForBuffer not implemented");
    bool showNetstatBufCaught = false;
    try {
        sceNetShowNetstatForBuffer(nullptr, 0, 0);
    } catch (const std::runtime_error& error) {
        showNetstatBufCaught = (std::string(error.what()) == "sceNetShowNetstatForBuffer not implemented");
    }
    Require(showNetstatBufCaught, "sceNetShowNetstatForBuffer not implemented");
    bool showNetstatExBufCaught = false;
    try {
        sceNetShowNetstatExForBuffer(nullptr, 0, 0, 0);
    } catch (const std::runtime_error& error) {
        showNetstatExBufCaught = (std::string(error.what()) == "sceNetShowNetstatExForBuffer not implemented");
    }
    Require(showNetstatExBufCaught, "sceNetShowNetstatExForBuffer not implemented");
    bool inetNtopScopeCaught = false;
    try {
        sceNetInetNtopWithScopeId(0, nullptr, nullptr, 0, 0);
    } catch (const std::runtime_error& error) {
        inetNtopScopeCaught = (std::string(error.what()) == "sceNetInetNtopWithScopeId not implemented");
    }
    Require(inetNtopScopeCaught, "sceNetInetNtopWithScopeId not implemented");
    bool inetPtonScopeCaught = false;
    try {
        sceNetInetPtonWithScopeId(0, nullptr, nullptr, nullptr);
    } catch (const std::runtime_error& error) {
        inetPtonScopeCaught = (std::string(error.what()) == "sceNetInetPtonWithScopeId not implemented");
    }
    Require(inetPtonScopeCaught, "sceNetInetPtonWithScopeId not implemented");
    bool showRoute6BufCaught = false;
    try {
        sceNetShowRoute6ForBuffer(nullptr, 0, 0);
    } catch (const std::runtime_error& error) {
        showRoute6BufCaught = (std::string(error.what()) == "sceNetShowRoute6ForBuffer not implemented");
    }
    Require(showRoute6BufCaught, "sceNetShowRoute6ForBuffer not implemented");
    bool setIfFlagsCaught = false;
    try {
        sceNetConfigSetIfFlags(0, 0);
    } catch (const std::runtime_error& error) {
        setIfFlagsCaught = (std::string(error.what()) == "sceNetConfigSetIfFlags not implemented");
    }
    Require(setIfFlagsCaught, "sceNetConfigSetIfFlags not implemented");
    bool unsetIfFlagsCaught = false;
    try {
        sceNetConfigUnsetIfFlags(0, 0);
    } catch (const std::runtime_error& error) {
        unsetIfFlagsCaught = (std::string(error.what()) == "sceNetConfigUnsetIfFlags not implemented");
    }
    Require(unsetIfFlagsCaught, "sceNetConfigUnsetIfFlags not implemented");
    bool delIfaddrCaught = false;
    try {
        sceNetConfigDelIfaddr(0);
    } catch (const std::runtime_error& error) {
        delIfaddrCaught = (std::string(error.what()) == "sceNetConfigDelIfaddr not implemented");
    }
    Require(delIfaddrCaught, "sceNetConfigDelIfaddr not implemented");
    bool downIfCaught = false;
    try {
        sceNetConfigDownInterface(0);
    } catch (const std::runtime_error& error) {
        downIfCaught = (std::string(error.what()) == "sceNetConfigDownInterface not implemented");
    }
    Require(downIfCaught, "sceNetConfigDownInterface not implemented");
    bool setDefaultRouteCaught = false;
    try {
        sceNetConfigSetDefaultRoute(nullptr);
    } catch (const std::runtime_error& error) {
        setDefaultRouteCaught = (std::string(error.what()) == "sceNetConfigSetDefaultRoute not implemented");
    }
    Require(setDefaultRouteCaught, "sceNetConfigSetDefaultRoute not implemented");
    std::puts("net thread tests passed");
    return 0;
}
