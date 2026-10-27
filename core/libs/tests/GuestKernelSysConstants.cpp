#include "SceTypes.hpp"
#include "prx/libkernel_sys/libkernel_sys.hpp"
#include <cstdlib>
#include <stdexcept>
#include <string>

namespace {

constexpr int GUEST_ENOTSUP = 45;
constexpr int SCE_KERNEL_ERROR_EPERM = static_cast<int>(0x80020001);
constexpr int SCE_KERNEL_ERROR_ENOENT = static_cast<int>(0x80020002);
constexpr int SCE_KERNEL_ERROR_ENOTSUP = static_cast<int>(0x8002002d);
constexpr int SCE_KERNEL_ERROR_ENOSYS = static_cast<int>(0x8002004e);

void Require(bool value) { if (!value) std::abort(); }

}

int main() {
    Require(pthread_switch_add_np_nid_postfix() == GUEST_ENOTSUP);
    Require(pthread_switch_delete_np_nid_postfix() == GUEST_ENOTSUP);

    Require(sceKernelAddResource() == 0);
    Require(sceKernelEventLogInit() == 0);
    Require(sceKernelIsGenuineKratosCex() == 0);
    Require(sceKernelReleaseTraceDirectMemory() == 0);

    Require(sceKernelHasNeoMode() == 1);
    Require(sceKernelIsAuthenticNeo() == 1);
    Require(sceKernelIsGenuineN() == 1);

    Require(sceKernelCreateEport() == SCE_KERNEL_ERROR_EPERM);
    Require(sceKernelDeleteEport() == SCE_KERNEL_ERROR_EPERM);
    Require(sceKernelOpenEport() == SCE_KERNEL_ERROR_EPERM);
    Require(sceKernelCloseEport() == SCE_KERNEL_ERROR_EPERM);
    Require(sceKernelTriggerEport() == SCE_KERNEL_ERROR_EPERM);

    Require(sceKernelQueryTraceMemory() == SCE_KERNEL_ERROR_ENOENT);

    Require(sceKernelIccGetCPMode() == SCE_KERNEL_ERROR_ENOTSUP);
    Require(sceKernelIccSetCPMode() == SCE_KERNEL_ERROR_ENOTSUP);

    Require(sceKernelClearGameDirectMemory() == SCE_KERNEL_ERROR_ENOSYS);
    Require(sceKernelMapTraceMemory() == SCE_KERNEL_ERROR_ENOSYS);
    Require(sceKernelTraceMemoryTypeProtect() == SCE_KERNEL_ERROR_ENOSYS);
    bool sceKernelSetProcessPropertyStringCaught = false;
    try {
        sceKernelSetProcessPropertyString();
    } catch (const std::runtime_error& error) {
        sceKernelSetProcessPropertyStringCaught = (std::string(error.what()) == "sceKernelSetProcessPropertyString not implemented");
    }
    Require(sceKernelSetProcessPropertyStringCaught);
    bool sceKernelSetSafemodeCaught = false;
    try {
        sceKernelSetSafemode();
    } catch (const std::runtime_error& error) {
        sceKernelSetSafemodeCaught = (std::string(error.what()) == "sceKernelSetSafemode not implemented");
    }
    Require(sceKernelSetSafemodeCaught);
    bool sceKernelSetSafemodeDirectCaught = false;
    try {
        sceKernelSetSafemodeDirect();
    } catch (const std::runtime_error& error) {
        sceKernelSetSafemodeDirectCaught = (std::string(error.what()) == "sceKernelSetSafemodeDirect not implemented");
    }
    Require(sceKernelSetSafemodeDirectCaught);
    bool sceKernelSetSuspendStateCaught = false;
    try {
        sceKernelSetSuspendState();
    } catch (const std::runtime_error& error) {
        sceKernelSetSuspendStateCaught = (std::string(error.what()) == "sceKernelSetSuspendState not implemented");
    }
    Require(sceKernelSetSuspendStateCaught);
    bool sceKernelSetTimezoneInfoCaught = false;
    try {
        sceKernelSetTimezoneInfo();
    } catch (const std::runtime_error& error) {
        sceKernelSetTimezoneInfoCaught = (std::string(error.what()) == "sceKernelSetTimezoneInfo not implemented");
    }
    Require(sceKernelSetTimezoneInfoCaught);
    bool sceKernelSetUpdatemodeCaught = false;
    try {
        sceKernelSetUpdatemode();
    } catch (const std::runtime_error& error) {
        sceKernelSetUpdatemodeCaught = (std::string(error.what()) == "sceKernelSetUpdatemode not implemented");
    }
    Require(sceKernelSetUpdatemodeCaught);
    bool sceKernelSetVmContainerCaught = false;
    try {
        sceKernelSetVmContainer();
    } catch (const std::runtime_error& error) {
        sceKernelSetVmContainerCaught = (std::string(error.what()) == "sceKernelSetVmContainer not implemented");
    }
    Require(sceKernelSetVmContainerCaught);
    bool sceKernelSettimeofdayCaught = false;
    try {
        sceKernelSettimeofday();
    } catch (const std::runtime_error& error) {
        sceKernelSettimeofdayCaught = (std::string(error.what()) == "sceKernelSettimeofday not implemented");
    }
    Require(sceKernelSettimeofdayCaught);
    bool sceKernelSflashGetWritePrioCaught = false;
    try {
        sceKernelSflashGetWritePrio();
    } catch (const std::runtime_error& error) {
        sceKernelSflashGetWritePrioCaught = (std::string(error.what()) == "sceKernelSflashGetWritePrio not implemented");
    }
    Require(sceKernelSflashGetWritePrioCaught);
    bool sceKernelSflashSetWritePrioCaught = false;
    try {
        sceKernelSflashSetWritePrio();
    } catch (const std::runtime_error& error) {
        sceKernelSflashSetWritePrioCaught = (std::string(error.what()) == "sceKernelSflashSetWritePrio not implemented");
    }
    Require(sceKernelSflashSetWritePrioCaught);
    bool sceKernelSlvNotifyErrorCaught = false;
    try {
        sceKernelSlvNotifyError();
    } catch (const std::runtime_error& error) {
        sceKernelSlvNotifyErrorCaught = (std::string(error.what()) == "sceKernelSlvNotifyError not implemented");
    }
    Require(sceKernelSlvNotifyErrorCaught);
    bool sceKernelSpawnCaught = false;
    try {
        sceKernelSpawn();
    } catch (const std::runtime_error& error) {
        sceKernelSpawnCaught = (std::string(error.what()) == "sceKernelSpawn not implemented");
    }
    Require(sceKernelSpawnCaught);
    bool sceKernelStreamWriteActivateCaught = false;
    try {
        sceKernelStreamWriteActivate();
    } catch (const std::runtime_error& error) {
        sceKernelStreamWriteActivateCaught = (std::string(error.what()) == "sceKernelStreamWriteActivate not implemented");
    }
    Require(sceKernelStreamWriteActivateCaught);
    bool sceKernelStreamWriteCreateCaught = false;
    try {
        sceKernelStreamWriteCreate();
    } catch (const std::runtime_error& error) {
        sceKernelStreamWriteCreateCaught = (std::string(error.what()) == "sceKernelStreamWriteCreate not implemented");
    }
    Require(sceKernelStreamWriteCreateCaught);
    bool sceKernelStreamWriteDeactivateCaught = false;
    try {
        sceKernelStreamWriteDeactivate();
    } catch (const std::runtime_error& error) {
        sceKernelStreamWriteDeactivateCaught = (std::string(error.what()) == "sceKernelStreamWriteDeactivate not implemented");
    }
    Require(sceKernelStreamWriteDeactivateCaught);
    bool sceKernelStreamWriteDeleteCaught = false;
    try {
        sceKernelStreamWriteDelete();
    } catch (const std::runtime_error& error) {
        sceKernelStreamWriteDeleteCaught = (std::string(error.what()) == "sceKernelStreamWriteDelete not implemented");
    }
    Require(sceKernelStreamWriteDeleteCaught);
    bool sceKernelStreamWriteReadCaught = false;
    try {
        sceKernelStreamWriteRead();
    } catch (const std::runtime_error& error) {
        sceKernelStreamWriteReadCaught = (std::string(error.what()) == "sceKernelStreamWriteRead not implemented");
    }
    Require(sceKernelStreamWriteReadCaught);
    bool sceKernelStreamWriteStatCaught = false;
    try {
        sceKernelStreamWriteStat();
    } catch (const std::runtime_error& error) {
        sceKernelStreamWriteStatCaught = (std::string(error.what()) == "sceKernelStreamWriteStat not implemented");
    }
    Require(sceKernelStreamWriteStatCaught);
    bool sceKernelStreamWriteWriteCaught = false;
    try {
        sceKernelStreamWriteWrite();
    } catch (const std::runtime_error& error) {
        sceKernelStreamWriteWriteCaught = (std::string(error.what()) == "sceKernelStreamWriteWrite not implemented");
    }
    Require(sceKernelStreamWriteWriteCaught);
    bool sceKernelSuspendDirectMemoryReleaseCaught = false;
    try {
        sceKernelSuspendDirectMemoryRelease();
    } catch (const std::runtime_error& error) {
        sceKernelSuspendDirectMemoryReleaseCaught = (std::string(error.what()) == "sceKernelSuspendDirectMemoryRelease not implemented");
    }
    Require(sceKernelSuspendDirectMemoryReleaseCaught);
    bool sceKernelSuspendProcessCaught = false;
    try {
        sceKernelSuspendProcess();
    } catch (const std::runtime_error& error) {
        sceKernelSuspendProcessCaught = (std::string(error.what()) == "sceKernelSuspendProcess not implemented");
    }
    Require(sceKernelSuspendProcessCaught);
    bool sceKernelSuspendSystemCaught = false;
    try {
        sceKernelSuspendSystem();
    } catch (const std::runtime_error& error) {
        sceKernelSuspendSystemCaught = (std::string(error.what()) == "sceKernelSuspendSystem not implemented");
    }
    Require(sceKernelSuspendSystemCaught);
    bool sceKernelSwitchToBaseModeCaught = false;
    try {
        sceKernelSwitchToBaseMode();
    } catch (const std::runtime_error& error) {
        sceKernelSwitchToBaseModeCaught = (std::string(error.what()) == "sceKernelSwitchToBaseMode not implemented");
    }
    Require(sceKernelSwitchToBaseModeCaught);
    bool sceKernelSwitchToNativeModeCaught = false;
    try {
        sceKernelSwitchToNativeMode();
    } catch (const std::runtime_error& error) {
        sceKernelSwitchToNativeModeCaught = (std::string(error.what()) == "sceKernelSwitchToNativeMode not implemented");
    }
    Require(sceKernelSwitchToNativeModeCaught);
    bool sceKernelSwitchToNeoModeCaught = false;
    try {
        sceKernelSwitchToNeoMode();
    } catch (const std::runtime_error& error) {
        sceKernelSwitchToNeoModeCaught = (std::string(error.what()) == "sceKernelSwitchToNeoMode not implemented");
    }
    Require(sceKernelSwitchToNeoModeCaught);
    return 0;
}
