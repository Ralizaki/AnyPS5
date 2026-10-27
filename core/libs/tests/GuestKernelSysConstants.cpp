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
    bool sceKernelCreateBudgetCaught = false;
    try {
        sceKernelCreateBudget();
    } catch (const std::runtime_error& error) {
        sceKernelCreateBudgetCaught = (std::string(error.what()) == "sceKernelCreateBudget not implemented");
    }
    Require(sceKernelCreateBudgetCaught);
    bool sceKernelDebugAcquireAndUpdateDebugRegisterCaught = false;
    try {
        sceKernelDebugAcquireAndUpdateDebugRegister();
    } catch (const std::runtime_error& error) {
        sceKernelDebugAcquireAndUpdateDebugRegisterCaught = (std::string(error.what()) == "sceKernelDebugAcquireAndUpdateDebugRegister not implemented");
    }
    Require(sceKernelDebugAcquireAndUpdateDebugRegisterCaught);
    bool sceKernelDebugGetAppStatusCaught = false;
    try {
        sceKernelDebugGetAppStatus();
    } catch (const std::runtime_error& error) {
        sceKernelDebugGetAppStatusCaught = (std::string(error.what()) == "sceKernelDebugGetAppStatus not implemented");
    }
    Require(sceKernelDebugGetAppStatusCaught);
    bool sceKernelDebugGetPauseCountCaught = false;
    try {
        sceKernelDebugGetPauseCount();
    } catch (const std::runtime_error& error) {
        sceKernelDebugGetPauseCountCaught = (std::string(error.what()) == "sceKernelDebugGetPauseCount not implemented");
    }
    Require(sceKernelDebugGetPauseCountCaught);
    bool sceKernelDebugGetPrivateLogTextCaught = false;
    try {
        sceKernelDebugGetPrivateLogText();
    } catch (const std::runtime_error& error) {
        sceKernelDebugGetPrivateLogTextCaught = (std::string(error.what()) == "sceKernelDebugGetPrivateLogText not implemented");
    }
    Require(sceKernelDebugGetPrivateLogTextCaught);
    bool sceKernelDebugGetSchedLockModeCaught = false;
    try {
        sceKernelDebugGetSchedLockMode();
    } catch (const std::runtime_error& error) {
        sceKernelDebugGetSchedLockModeCaught = (std::string(error.what()) == "sceKernelDebugGetSchedLockMode not implemented");
    }
    Require(sceKernelDebugGetSchedLockModeCaught);
    bool sceKernelDebugGetSdkLogTextCaught = false;
    try {
        sceKernelDebugGetSdkLogText();
    } catch (const std::runtime_error& error) {
        sceKernelDebugGetSdkLogTextCaught = (std::string(error.what()) == "sceKernelDebugGetSdkLogText not implemented");
    }
    Require(sceKernelDebugGetSdkLogTextCaught);
    bool sceKernelDebugGpuPaDebugIsInProgressCaught = false;
    try {
        sceKernelDebugGpuPaDebugIsInProgress();
    } catch (const std::runtime_error& error) {
        sceKernelDebugGpuPaDebugIsInProgressCaught = (std::string(error.what()) == "sceKernelDebugGpuPaDebugIsInProgress not implemented");
    }
    Require(sceKernelDebugGpuPaDebugIsInProgressCaught);
    bool sceKernelDebugInjectProcessEventCaught = false;
    try {
        sceKernelDebugInjectProcessEvent();
    } catch (const std::runtime_error& error) {
        sceKernelDebugInjectProcessEventCaught = (std::string(error.what()) == "sceKernelDebugInjectProcessEvent not implemented");
    }
    Require(sceKernelDebugInjectProcessEventCaught);
    bool sceKernelDebugPackageCorruptedCaught = false;
    try {
        sceKernelDebugPackageCorrupted();
    } catch (const std::runtime_error& error) {
        sceKernelDebugPackageCorruptedCaught = (std::string(error.what()) == "sceKernelDebugPackageCorrupted not implemented");
    }
    Require(sceKernelDebugPackageCorruptedCaught);
    bool sceKernelDebugRaiseExceptionWithContextCaught = false;
    try {
        sceKernelDebugRaiseExceptionWithContext();
    } catch (const std::runtime_error& error) {
        sceKernelDebugRaiseExceptionWithContextCaught = (std::string(error.what()) == "sceKernelDebugRaiseExceptionWithContext not implemented");
    }
    Require(sceKernelDebugRaiseExceptionWithContextCaught);
    bool sceKernelDebugRaiseExceptionWithInfoCaught = false;
    try {
        sceKernelDebugRaiseExceptionWithInfo();
    } catch (const std::runtime_error& error) {
        sceKernelDebugRaiseExceptionWithInfoCaught = (std::string(error.what()) == "sceKernelDebugRaiseExceptionWithInfo not implemented");
    }
    Require(sceKernelDebugRaiseExceptionWithInfoCaught);
    bool sceKernelDebugReleaseDebugContextCaught = false;
    try {
        sceKernelDebugReleaseDebugContext();
    } catch (const std::runtime_error& error) {
        sceKernelDebugReleaseDebugContextCaught = (std::string(error.what()) == "sceKernelDebugReleaseDebugContext not implemented");
    }
    Require(sceKernelDebugReleaseDebugContextCaught);
    bool sceKernelDeleteACInfoCaught = false;
    try {
        sceKernelDeleteACInfo();
    } catch (const std::runtime_error& error) {
        sceKernelDeleteACInfoCaught = (std::string(error.what()) == "sceKernelDeleteACInfo not implemented");
    }
    Require(sceKernelDeleteACInfoCaught);
    bool sceKernelDeleteBudgetCaught = false;
    try {
        sceKernelDeleteBudget();
    } catch (const std::runtime_error& error) {
        sceKernelDeleteBudgetCaught = (std::string(error.what()) == "sceKernelDeleteBudget not implemented");
    }
    Require(sceKernelDeleteBudgetCaught);
    bool sceKernelDeleteCpumodeEventCaught = false;
    try {
        sceKernelDeleteCpumodeEvent();
    } catch (const std::runtime_error& error) {
        sceKernelDeleteCpumodeEventCaught = (std::string(error.what()) == "sceKernelDeleteCpumodeEvent not implemented");
    }
    Require(sceKernelDeleteCpumodeEventCaught);
    bool sceKernelDeleteGpuExceptionEventCaught = false;
    try {
        sceKernelDeleteGpuExceptionEvent();
    } catch (const std::runtime_error& error) {
        sceKernelDeleteGpuExceptionEventCaught = (std::string(error.what()) == "sceKernelDeleteGpuExceptionEvent not implemented");
    }
    Require(sceKernelDeleteGpuExceptionEventCaught);
    bool sceKernelDeleteProcessFromCanvasMapCaught = false;
    try {
        sceKernelDeleteProcessFromCanvasMap();
    } catch (const std::runtime_error& error) {
        sceKernelDeleteProcessFromCanvasMapCaught = (std::string(error.what()) == "sceKernelDeleteProcessFromCanvasMap not implemented");
    }
    Require(sceKernelDeleteProcessFromCanvasMapCaught);
    bool sceKernelDeleteSavedAppCaught = false;
    try {
        sceKernelDeleteSavedApp();
    } catch (const std::runtime_error& error) {
        sceKernelDeleteSavedAppCaught = (std::string(error.what()) == "sceKernelDeleteSavedApp not implemented");
    }
    Require(sceKernelDeleteSavedAppCaught);
    bool sceKernelDirectMemoryQueryForIdCaught = false;
    try {
        sceKernelDirectMemoryQueryForId();
    } catch (const std::runtime_error& error) {
        sceKernelDirectMemoryQueryForIdCaught = (std::string(error.what()) == "sceKernelDirectMemoryQueryForId not implemented");
    }
    Require(sceKernelDirectMemoryQueryForIdCaught);
    bool sceKernelEnableDmemAliasing2Caught = false;
    try {
        sceKernelEnableDmemAliasing2();
    } catch (const std::runtime_error& error) {
        sceKernelEnableDmemAliasing2Caught = (std::string(error.what()) == "sceKernelEnableDmemAliasing2 not implemented");
    }
    Require(sceKernelEnableDmemAliasing2Caught);
    bool sceKernelEnablePthreadObjectCheckCaught = false;
    try {
        sceKernelEnablePthreadObjectCheck();
    } catch (const std::runtime_error& error) {
        sceKernelEnablePthreadObjectCheckCaught = (std::string(error.what()) == "sceKernelEnablePthreadObjectCheck not implemented");
    }
    Require(sceKernelEnablePthreadObjectCheckCaught);
    bool sceKernelEndAppMountCaught = false;
    try {
        sceKernelEndAppMount();
    } catch (const std::runtime_error& error) {
        sceKernelEndAppMountCaught = (std::string(error.what()) == "sceKernelEndAppMount not implemented");
    }
    Require(sceKernelEndAppMountCaught);
    bool sceKernelEndAppMount2Caught = false;
    try {
        sceKernelEndAppMount2();
    } catch (const std::runtime_error& error) {
        sceKernelEndAppMount2Caught = (std::string(error.what()) == "sceKernelEndAppMount2 not implemented");
    }
    Require(sceKernelEndAppMount2Caught);
    return 0;
}
