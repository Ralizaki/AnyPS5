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
    bool sceKernelSetAppInfoCaught = false;
    try {
        sceKernelSetAppInfo();
    } catch (const std::runtime_error& error) {
        sceKernelSetAppInfoCaught = (std::string(error.what()) == "sceKernelSetAppInfo not implemented");
    }
    Require(sceKernelSetAppInfoCaught);
    bool sceKernelSetAppStateCaught = false;
    try {
        sceKernelSetAppState();
    } catch (const std::runtime_error& error) {
        sceKernelSetAppStateCaught = (std::string(error.what()) == "sceKernelSetAppState not implemented");
    }
    Require(sceKernelSetAppStateCaught);
    bool sceKernelSetBackupRestoreModeCaught = false;
    try {
        sceKernelSetBackupRestoreMode();
    } catch (const std::runtime_error& error) {
        sceKernelSetBackupRestoreModeCaught = (std::string(error.what()) == "sceKernelSetBackupRestoreMode not implemented");
    }
    Require(sceKernelSetBackupRestoreModeCaught);
    bool sceKernelSetBaseModeClockCaught = false;
    try {
        sceKernelSetBaseModeClock();
    } catch (const std::runtime_error& error) {
        sceKernelSetBaseModeClockCaught = (std::string(error.what()) == "sceKernelSetBaseModeClock not implemented");
    }
    Require(sceKernelSetBaseModeClockCaught);
    bool sceKernelSetBesteffortCaught = false;
    try {
        sceKernelSetBesteffort();
    } catch (const std::runtime_error& error) {
        sceKernelSetBesteffortCaught = (std::string(error.what()) == "sceKernelSetBesteffort not implemented");
    }
    Require(sceKernelSetBesteffortCaught);
    bool sceKernelSetBootReqNotifyCaught = false;
    try {
        sceKernelSetBootReqNotify();
    } catch (const std::runtime_error& error) {
        sceKernelSetBootReqNotifyCaught = (std::string(error.what()) == "sceKernelSetBootReqNotify not implemented");
    }
    Require(sceKernelSetBootReqNotifyCaught);
    bool sceKernelSetBudgetCaught = false;
    try {
        sceKernelSetBudget();
    } catch (const std::runtime_error& error) {
        sceKernelSetBudgetCaught = (std::string(error.what()) == "sceKernelSetBudget not implemented");
    }
    Require(sceKernelSetBudgetCaught);
    bool sceKernelSetCallRecordCaught = false;
    try {
        sceKernelSetCallRecord();
    } catch (const std::runtime_error& error) {
        sceKernelSetCallRecordCaught = (std::string(error.what()) == "sceKernelSetCallRecord not implemented");
    }
    Require(sceKernelSetCallRecordCaught);
    bool sceKernelSetCompressionAttributeCaught = false;
    try {
        sceKernelSetCompressionAttribute();
    } catch (const std::runtime_error& error) {
        sceKernelSetCompressionAttributeCaught = (std::string(error.what()) == "sceKernelSetCompressionAttribute not implemented");
    }
    Require(sceKernelSetCompressionAttributeCaught);
    bool sceKernelSetCoredumpAppInfoCaught = false;
    try {
        sceKernelSetCoredumpAppInfo();
    } catch (const std::runtime_error& error) {
        sceKernelSetCoredumpAppInfoCaught = (std::string(error.what()) == "sceKernelSetCoredumpAppInfo not implemented");
    }
    Require(sceKernelSetCoredumpAppInfoCaught);
    bool sceKernelSetCpumodeGameCaught = false;
    try {
        sceKernelSetCpumodeGame();
    } catch (const std::runtime_error& error) {
        sceKernelSetCpumodeGameCaught = (std::string(error.what()) == "sceKernelSetCpumodeGame not implemented");
    }
    Require(sceKernelSetCpumodeGameCaught);
    bool sceKernelSetDataTransferModeCaught = false;
    try {
        sceKernelSetDataTransferMode();
    } catch (const std::runtime_error& error) {
        sceKernelSetDataTransferModeCaught = (std::string(error.what()) == "sceKernelSetDataTransferMode not implemented");
    }
    Require(sceKernelSetDataTransferModeCaught);
    bool sceKernelSetEmergencyErrorLogCaught = false;
    try {
        sceKernelSetEmergencyErrorLog();
    } catch (const std::runtime_error& error) {
        sceKernelSetEmergencyErrorLogCaught = (std::string(error.what()) == "sceKernelSetEmergencyErrorLog not implemented");
    }
    Require(sceKernelSetEmergencyErrorLogCaught);
    bool sceKernelSetFsstParamCaught = false;
    try {
        sceKernelSetFsstParam();
    } catch (const std::runtime_error& error) {
        sceKernelSetFsstParamCaught = (std::string(error.what()) == "sceKernelSetFsstParam not implemented");
    }
    Require(sceKernelSetFsstParamCaught);
    bool sceKernelSetGPICaught = false;
    try {
        sceKernelSetGPI();
    } catch (const std::runtime_error& error) {
        sceKernelSetGPICaught = (std::string(error.what()) == "sceKernelSetGPI not implemented");
    }
    Require(sceKernelSetGPICaught);
    bool sceKernelSetGameDirectMemoryLimitCaught = false;
    try {
        sceKernelSetGameDirectMemoryLimit();
    } catch (const std::runtime_error& error) {
        sceKernelSetGameDirectMemoryLimitCaught = (std::string(error.what()) == "sceKernelSetGameDirectMemoryLimit not implemented");
    }
    Require(sceKernelSetGameDirectMemoryLimitCaught);
    bool sceKernelSetGpuCuCaught = false;
    try {
        sceKernelSetGpuCu();
    } catch (const std::runtime_error& error) {
        sceKernelSetGpuCuCaught = (std::string(error.what()) == "sceKernelSetGpuCu not implemented");
    }
    Require(sceKernelSetGpuCuCaught);
    bool sceKernelSetIoreqCaught = false;
    try {
        sceKernelSetIoreq();
    } catch (const std::runtime_error& error) {
        sceKernelSetIoreqCaught = (std::string(error.what()) == "sceKernelSetIoreq not implemented");
    }
    Require(sceKernelSetIoreqCaught);
    bool sceKernelSetKnobsCaught = false;
    try {
        sceKernelSetKnobs();
    } catch (const std::runtime_error& error) {
        sceKernelSetKnobsCaught = (std::string(error.what()) == "sceKernelSetKnobs not implemented");
    }
    Require(sceKernelSetKnobsCaught);
    bool sceKernelSetMemoryPstateCaught = false;
    try {
        sceKernelSetMemoryPstate();
    } catch (const std::runtime_error& error) {
        sceKernelSetMemoryPstateCaught = (std::string(error.what()) == "sceKernelSetMemoryPstate not implemented");
    }
    Require(sceKernelSetMemoryPstateCaught);
    bool sceKernelSetNeoModeClockCaught = false;
    try {
        sceKernelSetNeoModeClock();
    } catch (const std::runtime_error& error) {
        sceKernelSetNeoModeClockCaught = (std::string(error.what()) == "sceKernelSetNeoModeClock not implemented");
    }
    Require(sceKernelSetNeoModeClockCaught);
    bool sceKernelSetPackageInfoCaught = false;
    try {
        sceKernelSetPackageInfo();
    } catch (const std::runtime_error& error) {
        sceKernelSetPackageInfoCaught = (std::string(error.what()) == "sceKernelSetPackageInfo not implemented");
    }
    Require(sceKernelSetPackageInfoCaught);
    bool sceKernelSetPhysFmemLimitCaught = false;
    try {
        sceKernelSetPhysFmemLimit();
    } catch (const std::runtime_error& error) {
        sceKernelSetPhysFmemLimitCaught = (std::string(error.what()) == "sceKernelSetPhysFmemLimit not implemented");
    }
    Require(sceKernelSetPhysFmemLimitCaught);
    bool sceKernelSetProcessNameCaught = false;
    try {
        sceKernelSetProcessName();
    } catch (const std::runtime_error& error) {
        sceKernelSetProcessNameCaught = (std::string(error.what()) == "sceKernelSetProcessName not implemented");
    }
    Require(sceKernelSetProcessNameCaught);
    bool sceKernelSetProcessPropertyCaught = false;
    try {
        sceKernelSetProcessProperty();
    } catch (const std::runtime_error& error) {
        sceKernelSetProcessPropertyCaught = (std::string(error.what()) == "sceKernelSetProcessProperty not implemented");
    }
    Require(sceKernelSetProcessPropertyCaught);
    return 0;
}
