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
    bool sceKernelMapToolMemoryCaught = false;
    try {
        sceKernelMapToolMemory();
    } catch (const std::runtime_error& error) {
        sceKernelMapToolMemoryCaught = (std::string(error.what()) == "sceKernelMapToolMemory not implemented");
    }
    Require(sceKernelMapToolMemoryCaught);
    bool sceKernelMapperGetParamCaught = false;
    try {
        sceKernelMapperGetParam();
    } catch (const std::runtime_error& error) {
        sceKernelMapperGetParamCaught = (std::string(error.what()) == "sceKernelMapperGetParam not implemented");
    }
    Require(sceKernelMapperGetParamCaught);
    bool sceKernelMemoryPoolMoveCaught = false;
    try {
        sceKernelMemoryPoolMove();
    } catch (const std::runtime_error& error) {
        sceKernelMemoryPoolMoveCaught = (std::string(error.what()) == "sceKernelMemoryPoolMove not implemented");
    }
    Require(sceKernelMemoryPoolMoveCaught);
    bool sceKernelMlockallCaught = false;
    try {
        sceKernelMlockall();
    } catch (const std::runtime_error& error) {
        sceKernelMlockallCaught = (std::string(error.what()) == "sceKernelMlockall not implemented");
    }
    Require(sceKernelMlockallCaught);
    bool sceKernelNormalizePathCaught = false;
    try {
        sceKernelNormalizePath();
    } catch (const std::runtime_error& error) {
        sceKernelNormalizePathCaught = (std::string(error.what()) == "sceKernelNormalizePath not implemented");
    }
    Require(sceKernelNormalizePathCaught);
    bool sceKernelNotifyAppEventCaught = false;
    try {
        sceKernelNotifyAppEvent();
    } catch (const std::runtime_error& error) {
        sceKernelNotifyAppEventCaught = (std::string(error.what()) == "sceKernelNotifyAppEvent not implemented");
    }
    Require(sceKernelNotifyAppEventCaught);
    bool sceKernelNotifyAppStateChangedCaught = false;
    try {
        sceKernelNotifyAppStateChanged();
    } catch (const std::runtime_error& error) {
        sceKernelNotifyAppStateChangedCaught = (std::string(error.what()) == "sceKernelNotifyAppStateChanged not implemented");
    }
    Require(sceKernelNotifyAppStateChangedCaught);
    bool sceKernelNotifySystemSuspendResumeProgressCaught = false;
    try {
        sceKernelNotifySystemSuspendResumeProgress();
    } catch (const std::runtime_error& error) {
        sceKernelNotifySystemSuspendResumeProgressCaught = (std::string(error.what()) == "sceKernelNotifySystemSuspendResumeProgress not implemented");
    }
    Require(sceKernelNotifySystemSuspendResumeProgressCaught);
    bool sceKernelNotifySystemSuspendStartCaught = false;
    try {
        sceKernelNotifySystemSuspendStart();
    } catch (const std::runtime_error& error) {
        sceKernelNotifySystemSuspendStartCaught = (std::string(error.what()) == "sceKernelNotifySystemSuspendStart not implemented");
    }
    Require(sceKernelNotifySystemSuspendStartCaught);
    bool sceKernelOpenInternalCaught = false;
    try {
        sceKernelOpenInternal();
    } catch (const std::runtime_error& error) {
        sceKernelOpenInternalCaught = (std::string(error.what()) == "sceKernelOpenInternal not implemented");
    }
    Require(sceKernelOpenInternalCaught);
    bool sceKernelOpenSemaCaught = false;
    try {
        sceKernelOpenSema();
    } catch (const std::runtime_error& error) {
        sceKernelOpenSemaCaught = (std::string(error.what()) == "sceKernelOpenSema not implemented");
    }
    Require(sceKernelOpenSemaCaught);
    bool sceKernelPrepareDirectMemorySwapCaught = false;
    try {
        sceKernelPrepareDirectMemorySwap();
    } catch (const std::runtime_error& error) {
        sceKernelPrepareDirectMemorySwapCaught = (std::string(error.what()) == "sceKernelPrepareDirectMemorySwap not implemented");
    }
    Require(sceKernelPrepareDirectMemorySwapCaught);
    bool sceKernelPrepareToResumeProcessCaught = false;
    try {
        sceKernelPrepareToResumeProcess();
    } catch (const std::runtime_error& error) {
        sceKernelPrepareToResumeProcessCaught = (std::string(error.what()) == "sceKernelPrepareToResumeProcess not implemented");
    }
    Require(sceKernelPrepareToResumeProcessCaught);
    bool sceKernelPrepareToSuspendProcessCaught = false;
    try {
        sceKernelPrepareToSuspendProcess();
    } catch (const std::runtime_error& error) {
        sceKernelPrepareToSuspendProcessCaught = (std::string(error.what()) == "sceKernelPrepareToSuspendProcess not implemented");
    }
    Require(sceKernelPrepareToSuspendProcessCaught);
    bool sceKernelProtectDirectMemoryCaught = false;
    try {
        sceKernelProtectDirectMemory();
    } catch (const std::runtime_error& error) {
        sceKernelProtectDirectMemoryCaught = (std::string(error.what()) == "sceKernelProtectDirectMemory not implemented");
    }
    Require(sceKernelProtectDirectMemoryCaught);
    bool sceKernelProtectDirectMemoryForPIDCaught = false;
    try {
        sceKernelProtectDirectMemoryForPID();
    } catch (const std::runtime_error& error) {
        sceKernelProtectDirectMemoryForPIDCaught = (std::string(error.what()) == "sceKernelProtectDirectMemoryForPID not implemented");
    }
    Require(sceKernelProtectDirectMemoryForPIDCaught);
    bool sceKernelQueryToolMemoryCaught = false;
    try {
        sceKernelQueryToolMemory();
    } catch (const std::runtime_error& error) {
        sceKernelQueryToolMemoryCaught = (std::string(error.what()) == "sceKernelQueryToolMemory not implemented");
    }
    Require(sceKernelQueryToolMemoryCaught);
    bool sceKernelRandomizedPathCaught = false;
    try {
        sceKernelRandomizedPath();
    } catch (const std::runtime_error& error) {
        sceKernelRandomizedPathCaught = (std::string(error.what()) == "sceKernelRandomizedPath not implemented");
    }
    Require(sceKernelRandomizedPathCaught);
    bool sceKernelRdupCaught = false;
    try {
        sceKernelRdup();
    } catch (const std::runtime_error& error) {
        sceKernelRdupCaught = (std::string(error.what()) == "sceKernelRdup not implemented");
    }
    Require(sceKernelRdupCaught);
    bool sceKernelRebootCaught = false;
    try {
        sceKernelReboot();
    } catch (const std::runtime_error& error) {
        sceKernelRebootCaught = (std::string(error.what()) == "sceKernelReboot not implemented");
    }
    Require(sceKernelRebootCaught);
    bool sceKernelReleaseToolMemoryCaught = false;
    try {
        sceKernelReleaseToolMemory();
    } catch (const std::runtime_error& error) {
        sceKernelReleaseToolMemoryCaught = (std::string(error.what()) == "sceKernelReleaseToolMemory not implemented");
    }
    Require(sceKernelReleaseToolMemoryCaught);
    bool sceKernelReportUnpatchedFunctionCallCaught = false;
    try {
        sceKernelReportUnpatchedFunctionCall();
    } catch (const std::runtime_error& error) {
        sceKernelReportUnpatchedFunctionCallCaught = (std::string(error.what()) == "sceKernelReportUnpatchedFunctionCall not implemented");
    }
    Require(sceKernelReportUnpatchedFunctionCallCaught);
    bool sceKernelReserve2mbPageCaught = false;
    try {
        sceKernelReserve2mbPage();
    } catch (const std::runtime_error& error) {
        sceKernelReserve2mbPageCaught = (std::string(error.what()) == "sceKernelReserve2mbPage not implemented");
    }
    Require(sceKernelReserve2mbPageCaught);
    bool sceKernelReserveSystemDirectMemoryCaught = false;
    try {
        sceKernelReserveSystemDirectMemory();
    } catch (const std::runtime_error& error) {
        sceKernelReserveSystemDirectMemoryCaught = (std::string(error.what()) == "sceKernelReserveSystemDirectMemory not implemented");
    }
    Require(sceKernelReserveSystemDirectMemoryCaught);
    bool sceKernelRestoreAppCaught = false;
    try {
        sceKernelRestoreApp();
    } catch (const std::runtime_error& error) {
        sceKernelRestoreAppCaught = (std::string(error.what()) == "sceKernelRestoreApp not implemented");
    }
    Require(sceKernelRestoreAppCaught);
    return 0;
}
