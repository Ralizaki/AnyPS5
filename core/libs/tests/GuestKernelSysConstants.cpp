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
    bool sceKernelGetCpuUsageCaught = false;
    try {
        sceKernelGetCpuUsage();
    } catch (const std::runtime_error& error) {
        sceKernelGetCpuUsageCaught = (std::string(error.what()) == "sceKernelGetCpuUsage not implemented");
    }
    Require(sceKernelGetCpuUsageCaught);
    bool sceKernelGetCpuUsageAllCaught = false;
    try {
        sceKernelGetCpuUsageAll();
    } catch (const std::runtime_error& error) {
        sceKernelGetCpuUsageAllCaught = (std::string(error.what()) == "sceKernelGetCpuUsageAll not implemented");
    }
    Require(sceKernelGetCpuUsageAllCaught);
    bool sceKernelGetCpuUsageProcCaught = false;
    try {
        sceKernelGetCpuUsageProc();
    } catch (const std::runtime_error& error) {
        sceKernelGetCpuUsageProcCaught = (std::string(error.what()) == "sceKernelGetCpuUsageProc not implemented");
    }
    Require(sceKernelGetCpuUsageProcCaught);
    bool sceKernelGetCpuUsageProc2Caught = false;
    try {
        sceKernelGetCpuUsageProc2();
    } catch (const std::runtime_error& error) {
        sceKernelGetCpuUsageProc2Caught = (std::string(error.what()) == "sceKernelGetCpuUsageProc2 not implemented");
    }
    Require(sceKernelGetCpuUsageProc2Caught);
    bool sceKernelGetCpuUsageThreadCaught = false;
    try {
        sceKernelGetCpuUsageThread();
    } catch (const std::runtime_error& error) {
        sceKernelGetCpuUsageThreadCaught = (std::string(error.what()) == "sceKernelGetCpuUsageThread not implemented");
    }
    Require(sceKernelGetCpuUsageThreadCaught);
    bool sceKernelGetCpumodeGameCaught = false;
    try {
        sceKernelGetCpumodeGame();
    } catch (const std::runtime_error& error) {
        sceKernelGetCpumodeGameCaught = (std::string(error.what()) == "sceKernelGetCpumodeGame not implemented");
    }
    Require(sceKernelGetCpumodeGameCaught);
    bool sceKernelGetCurrentFanDutyCaught = false;
    try {
        sceKernelGetCurrentFanDuty();
    } catch (const std::runtime_error& error) {
        sceKernelGetCurrentFanDutyCaught = (std::string(error.what()) == "sceKernelGetCurrentFanDuty not implemented");
    }
    Require(sceKernelGetCurrentFanDutyCaught);
    bool sceKernelGetDataTransferModeCaught = false;
    try {
        sceKernelGetDataTransferMode();
    } catch (const std::runtime_error& error) {
        sceKernelGetDataTransferModeCaught = (std::string(error.what()) == "sceKernelGetDataTransferMode not implemented");
    }
    Require(sceKernelGetDataTransferModeCaught);
    bool sceKernelGetDebugMenuMiniModeForRcmgrCaught = false;
    try {
        sceKernelGetDebugMenuMiniModeForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetDebugMenuMiniModeForRcmgrCaught = (std::string(error.what()) == "sceKernelGetDebugMenuMiniModeForRcmgr not implemented");
    }
    Require(sceKernelGetDebugMenuMiniModeForRcmgrCaught);
    bool sceKernelGetDebugMenuModeForPsmForRcmgrCaught = false;
    try {
        sceKernelGetDebugMenuModeForPsmForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetDebugMenuModeForPsmForRcmgrCaught = (std::string(error.what()) == "sceKernelGetDebugMenuModeForPsmForRcmgr not implemented");
    }
    Require(sceKernelGetDebugMenuModeForPsmForRcmgrCaught);
    bool sceKernelGetDebugMenuModeForRcmgrCaught = false;
    try {
        sceKernelGetDebugMenuModeForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetDebugMenuModeForRcmgrCaught = (std::string(error.what()) == "sceKernelGetDebugMenuModeForRcmgr not implemented");
    }
    Require(sceKernelGetDebugMenuModeForRcmgrCaught);
    bool sceKernelGetDefaultToolMemorySizeCaught = false;
    try {
        sceKernelGetDefaultToolMemorySize();
    } catch (const std::runtime_error& error) {
        sceKernelGetDefaultToolMemorySizeCaught = (std::string(error.what()) == "sceKernelGetDefaultToolMemorySize not implemented");
    }
    Require(sceKernelGetDefaultToolMemorySizeCaught);
    bool sceKernelGetEmergencyErrorLogCaught = false;
    try {
        sceKernelGetEmergencyErrorLog();
    } catch (const std::runtime_error& error) {
        sceKernelGetEmergencyErrorLogCaught = (std::string(error.what()) == "sceKernelGetEmergencyErrorLog not implemented");
    }
    Require(sceKernelGetEmergencyErrorLogCaught);
    bool sceKernelGetExecutableModuleHandleCaught = false;
    try {
        sceKernelGetExecutableModuleHandle();
    } catch (const std::runtime_error& error) {
        sceKernelGetExecutableModuleHandleCaught = (std::string(error.what()) == "sceKernelGetExecutableModuleHandle not implemented");
    }
    Require(sceKernelGetExecutableModuleHandleCaught);
    bool sceKernelGetExtLibcHandleCaught = false;
    try {
        sceKernelGetExtLibcHandle();
    } catch (const std::runtime_error& error) {
        sceKernelGetExtLibcHandleCaught = (std::string(error.what()) == "sceKernelGetExtLibcHandle not implemented");
    }
    Require(sceKernelGetExtLibcHandleCaught);
    bool sceKernelGetFakeFinalizeMenuForRcmgrCaught = false;
    try {
        sceKernelGetFakeFinalizeMenuForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetFakeFinalizeMenuForRcmgrCaught = (std::string(error.what()) == "sceKernelGetFakeFinalizeMenuForRcmgr not implemented");
    }
    Require(sceKernelGetFakeFinalizeMenuForRcmgrCaught);
    bool sceKernelGetFirstImageAddrCaught = false;
    try {
        sceKernelGetFirstImageAddr();
    } catch (const std::runtime_error& error) {
        sceKernelGetFirstImageAddrCaught = (std::string(error.what()) == "sceKernelGetFirstImageAddr not implemented");
    }
    Require(sceKernelGetFirstImageAddrCaught);
    bool sceKernelGetFlagedUpdaterForRcmgrCaught = false;
    try {
        sceKernelGetFlagedUpdaterForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetFlagedUpdaterForRcmgrCaught = (std::string(error.what()) == "sceKernelGetFlagedUpdaterForRcmgr not implemented");
    }
    Require(sceKernelGetFlagedUpdaterForRcmgrCaught);
    bool sceKernelGetForceUpdateModeForRcmgrCaught = false;
    try {
        sceKernelGetForceUpdateModeForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetForceUpdateModeForRcmgrCaught = (std::string(error.what()) == "sceKernelGetForceUpdateModeForRcmgr not implemented");
    }
    Require(sceKernelGetForceUpdateModeForRcmgrCaught);
    bool sceKernelGetGPOCaught = false;
    try {
        sceKernelGetGPO();
    } catch (const std::runtime_error& error) {
        sceKernelGetGPOCaught = (std::string(error.what()) == "sceKernelGetGPO not implemented");
    }
    Require(sceKernelGetGPOCaught);
    bool sceKernelGetHwFeatureInfoForDecidCaught = false;
    try {
        sceKernelGetHwFeatureInfoForDecid();
    } catch (const std::runtime_error& error) {
        sceKernelGetHwFeatureInfoForDecidCaught = (std::string(error.what()) == "sceKernelGetHwFeatureInfoForDecid not implemented");
    }
    Require(sceKernelGetHwFeatureInfoForDecidCaught);
    bool sceKernelGetHwModelNameCaught = false;
    try {
        sceKernelGetHwModelName();
    } catch (const std::runtime_error& error) {
        sceKernelGetHwModelNameCaught = (std::string(error.what()) == "sceKernelGetHwModelName not implemented");
    }
    Require(sceKernelGetHwModelNameCaught);
    bool sceKernelGetHwSerialNumberCaught = false;
    try {
        sceKernelGetHwSerialNumber();
    } catch (const std::runtime_error& error) {
        sceKernelGetHwSerialNumberCaught = (std::string(error.what()) == "sceKernelGetHwSerialNumber not implemented");
    }
    Require(sceKernelGetHwSerialNumberCaught);
    bool sceKernelGetIdPsCaught = false;
    try {
        sceKernelGetIdPs();
    } catch (const std::runtime_error& error) {
        sceKernelGetIdPsCaught = (std::string(error.what()) == "sceKernelGetIdPs not implemented");
    }
    Require(sceKernelGetIdPsCaught);
    return 0;
}
