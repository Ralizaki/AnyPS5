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
    bool pwrite_nid_postfixCaught = false;
    try {
        pwrite_nid_postfix();
    } catch (const std::runtime_error& error) {
        pwrite_nid_postfixCaught = (std::string(error.what()) == "pwrite_nid_postfix not implemented");
    }
    Require(pwrite_nid_postfixCaught);
    bool sceKernelGetIdTableCurrentCountCaught = false;
    try {
        sceKernelGetIdTableCurrentCount();
    } catch (const std::runtime_error& error) {
        sceKernelGetIdTableCurrentCountCaught = (std::string(error.what()) == "sceKernelGetIdTableCurrentCount not implemented");
    }
    Require(sceKernelGetIdTableCurrentCountCaught);
    bool sceKernelGetIoreqCaught = false;
    try {
        sceKernelGetIoreq();
    } catch (const std::runtime_error& error) {
        sceKernelGetIoreqCaught = (std::string(error.what()) == "sceKernelGetIoreq not implemented");
    }
    Require(sceKernelGetIoreqCaught);
    bool sceKernelGetIpcPathCaught = false;
    try {
        sceKernelGetIpcPath();
    } catch (const std::runtime_error& error) {
        sceKernelGetIpcPathCaught = (std::string(error.what()) == "sceKernelGetIpcPath not implemented");
    }
    Require(sceKernelGetIpcPathCaught);
    bool sceKernelGetKnobsCaught = false;
    try {
        sceKernelGetKnobs();
    } catch (const std::runtime_error& error) {
        sceKernelGetKnobsCaught = (std::string(error.what()) == "sceKernelGetKnobs not implemented");
    }
    Require(sceKernelGetKnobsCaught);
    bool sceKernelGetKqueueFromEqueueCaught = false;
    try {
        sceKernelGetKqueueFromEqueue();
    } catch (const std::runtime_error& error) {
        sceKernelGetKqueueFromEqueueCaught = (std::string(error.what()) == "sceKernelGetKqueueFromEqueue not implemented");
    }
    Require(sceKernelGetKqueueFromEqueueCaught);
    bool sceKernelGetMemoryPstateCaught = false;
    try {
        sceKernelGetMemoryPstate();
    } catch (const std::runtime_error& error) {
        sceKernelGetMemoryPstateCaught = (std::string(error.what()) == "sceKernelGetMemoryPstate not implemented");
    }
    Require(sceKernelGetMemoryPstateCaught);
    bool sceKernelGetPagingStatsOfAllObjectsCaught = false;
    try {
        sceKernelGetPagingStatsOfAllObjects();
    } catch (const std::runtime_error& error) {
        sceKernelGetPagingStatsOfAllObjectsCaught = (std::string(error.what()) == "sceKernelGetPagingStatsOfAllObjects not implemented");
    }
    Require(sceKernelGetPagingStatsOfAllObjectsCaught);
    bool sceKernelGetPagingStatsOfAllThreadsCaught = false;
    try {
        sceKernelGetPagingStatsOfAllThreads();
    } catch (const std::runtime_error& error) {
        sceKernelGetPagingStatsOfAllThreadsCaught = (std::string(error.what()) == "sceKernelGetPagingStatsOfAllThreads not implemented");
    }
    Require(sceKernelGetPagingStatsOfAllThreadsCaught);
    bool sceKernelGetParentAppCaught = false;
    try {
        sceKernelGetParentApp();
    } catch (const std::runtime_error& error) {
        sceKernelGetParentAppCaught = (std::string(error.what()) == "sceKernelGetParentApp not implemented");
    }
    Require(sceKernelGetParentAppCaught);
    bool sceKernelGetPhysPageSizeCaught = false;
    try {
        sceKernelGetPhysPageSize();
    } catch (const std::runtime_error& error) {
        sceKernelGetPhysPageSizeCaught = (std::string(error.what()) == "sceKernelGetPhysPageSize not implemented");
    }
    Require(sceKernelGetPhysPageSizeCaught);
    bool sceKernelGetProcessNameCaught = false;
    try {
        sceKernelGetProcessName();
    } catch (const std::runtime_error& error) {
        sceKernelGetProcessNameCaught = (std::string(error.what()) == "sceKernelGetProcessName not implemented");
    }
    Require(sceKernelGetProcessNameCaught);
    bool sceKernelGetProcessTypeOfBudgetCaught = false;
    try {
        sceKernelGetProcessTypeOfBudget();
    } catch (const std::runtime_error& error) {
        sceKernelGetProcessTypeOfBudgetCaught = (std::string(error.what()) == "sceKernelGetProcessTypeOfBudget not implemented");
    }
    Require(sceKernelGetProcessTypeOfBudgetCaught);
    bool sceKernelGetProductCodeCaught = false;
    try {
        sceKernelGetProductCode();
    } catch (const std::runtime_error& error) {
        sceKernelGetProductCodeCaught = (std::string(error.what()) == "sceKernelGetProductCode not implemented");
    }
    Require(sceKernelGetProductCodeCaught);
    bool sceKernelGetProductStrCaught = false;
    try {
        sceKernelGetProductStr();
    } catch (const std::runtime_error& error) {
        sceKernelGetProductStrCaught = (std::string(error.what()) == "sceKernelGetProductStr not implemented");
    }
    Require(sceKernelGetProductStrCaught);
    bool sceKernelGetPs4SystemSwVersionCaught = false;
    try {
        sceKernelGetPs4SystemSwVersion();
    } catch (const std::runtime_error& error) {
        sceKernelGetPs4SystemSwVersionCaught = (std::string(error.what()) == "sceKernelGetPs4SystemSwVersion not implemented");
    }
    Require(sceKernelGetPs4SystemSwVersionCaught);
    bool sceKernelGetPsmIntdevModeForRcmgrCaught = false;
    try {
        sceKernelGetPsmIntdevModeForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetPsmIntdevModeForRcmgrCaught = (std::string(error.what()) == "sceKernelGetPsmIntdevModeForRcmgr not implemented");
    }
    Require(sceKernelGetPsmIntdevModeForRcmgrCaught);
    bool sceKernelGetPsnAccessTraceLogForRcmgrCaught = false;
    try {
        sceKernelGetPsnAccessTraceLogForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetPsnAccessTraceLogForRcmgrCaught = (std::string(error.what()) == "sceKernelGetPsnAccessTraceLogForRcmgr not implemented");
    }
    Require(sceKernelGetPsnAccessTraceLogForRcmgrCaught);
    bool sceKernelGetQafExpirationTimeNotafterForRcmgrCaught = false;
    try {
        sceKernelGetQafExpirationTimeNotafterForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetQafExpirationTimeNotafterForRcmgrCaught = (std::string(error.what()) == "sceKernelGetQafExpirationTimeNotafterForRcmgr not implemented");
    }
    Require(sceKernelGetQafExpirationTimeNotafterForRcmgrCaught);
    bool sceKernelGetQafExpirationTimeNotbeforeForRcmgrCaught = false;
    try {
        sceKernelGetQafExpirationTimeNotbeforeForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetQafExpirationTimeNotbeforeForRcmgrCaught = (std::string(error.what()) == "sceKernelGetQafExpirationTimeNotbeforeForRcmgr not implemented");
    }
    Require(sceKernelGetQafExpirationTimeNotbeforeForRcmgrCaught);
    bool sceKernelGetQafGenerationForRcmgrCaught = false;
    try {
        sceKernelGetQafGenerationForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetQafGenerationForRcmgrCaught = (std::string(error.what()) == "sceKernelGetQafGenerationForRcmgr not implemented");
    }
    Require(sceKernelGetQafGenerationForRcmgrCaught);
    bool sceKernelGetQafNameForRcmgrCaught = false;
    try {
        sceKernelGetQafNameForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetQafNameForRcmgrCaught = (std::string(error.what()) == "sceKernelGetQafNameForRcmgr not implemented");
    }
    Require(sceKernelGetQafNameForRcmgrCaught);
    bool sceKernelGetRenderingModeCaught = false;
    try {
        sceKernelGetRenderingMode();
    } catch (const std::runtime_error& error) {
        sceKernelGetRenderingModeCaught = (std::string(error.what()) == "sceKernelGetRenderingMode not implemented");
    }
    Require(sceKernelGetRenderingModeCaught);
    bool sceKernelGetResidentCountCaught = false;
    try {
        sceKernelGetResidentCount();
    } catch (const std::runtime_error& error) {
        sceKernelGetResidentCountCaught = (std::string(error.what()) == "sceKernelGetResidentCount not implemented");
    }
    Require(sceKernelGetResidentCountCaught);
    bool sceKernelGetResidentFmemCountCaught = false;
    try {
        sceKernelGetResidentFmemCount();
    } catch (const std::runtime_error& error) {
        sceKernelGetResidentFmemCountCaught = (std::string(error.what()) == "sceKernelGetResidentFmemCount not implemented");
    }
    Require(sceKernelGetResidentFmemCountCaught);
    return 0;
}
