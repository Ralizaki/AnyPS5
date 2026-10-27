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
    bool sceKernelTerminateProcessCaught = false;
    try {
        sceKernelTerminateProcess();
    } catch (const std::runtime_error& error) {
        sceKernelTerminateProcessCaught = (std::string(error.what()) == "sceKernelTerminateProcess not implemented");
    }
    Require(sceKernelTerminateProcessCaught);
    bool sceKernelTerminateSysCoreCaught = false;
    try {
        sceKernelTerminateSysCore();
    } catch (const std::runtime_error& error) {
        sceKernelTerminateSysCoreCaught = (std::string(error.what()) == "sceKernelTerminateSysCore not implemented");
    }
    Require(sceKernelTerminateSysCoreCaught);
    bool sceKernelTitleWorkdaroundIsEnabledCaught = false;
    try {
        sceKernelTitleWorkdaroundIsEnabled();
    } catch (const std::runtime_error& error) {
        sceKernelTitleWorkdaroundIsEnabledCaught = (std::string(error.what()) == "sceKernelTitleWorkdaroundIsEnabled not implemented");
    }
    Require(sceKernelTitleWorkdaroundIsEnabledCaught);
    bool sceKernelVirtualQueryAllCaught = false;
    try {
        sceKernelVirtualQueryAll();
    } catch (const std::runtime_error& error) {
        sceKernelVirtualQueryAllCaught = (std::string(error.what()) == "sceKernelVirtualQueryAll not implemented");
    }
    Require(sceKernelVirtualQueryAllCaught);
    bool sceKernelWaitCommandBufferCompletionCaught = false;
    try {
        sceKernelWaitCommandBufferCompletion();
    } catch (const std::runtime_error& error) {
        sceKernelWaitCommandBufferCompletionCaught = (std::string(error.what()) == "sceKernelWaitCommandBufferCompletion not implemented");
    }
    Require(sceKernelWaitCommandBufferCompletionCaught);
    bool sceKernelWriteEventQueueOnCompletionCommandCaught = false;
    try {
        sceKernelWriteEventQueueOnCompletionCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteEventQueueOnCompletionCommandCaught = (std::string(error.what()) == "sceKernelWriteEventQueueOnCompletionCommand not implemented");
    }
    Require(sceKernelWriteEventQueueOnCompletionCommandCaught);
    bool sceKernelWriteMapCommandCaught = false;
    try {
        sceKernelWriteMapCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteMapCommandCaught = (std::string(error.what()) == "sceKernelWriteMapCommand not implemented");
    }
    Require(sceKernelWriteMapCommandCaught);
    bool sceKernelWriteMapCommand2Caught = false;
    try {
        sceKernelWriteMapCommand2();
    } catch (const std::runtime_error& error) {
        sceKernelWriteMapCommand2Caught = (std::string(error.what()) == "sceKernelWriteMapCommand2 not implemented");
    }
    Require(sceKernelWriteMapCommand2Caught);
    bool sceKernelWriteMapDirectCommandCaught = false;
    try {
        sceKernelWriteMapDirectCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteMapDirectCommandCaught = (std::string(error.what()) == "sceKernelWriteMapDirectCommand not implemented");
    }
    Require(sceKernelWriteMapDirectCommandCaught);
    bool sceKernelWriteMapDirectWithGpuMaskIdCommandCaught = false;
    try {
        sceKernelWriteMapDirectWithGpuMaskIdCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteMapDirectWithGpuMaskIdCommandCaught = (std::string(error.what()) == "sceKernelWriteMapDirectWithGpuMaskIdCommand not implemented");
    }
    Require(sceKernelWriteMapDirectWithGpuMaskIdCommandCaught);
    bool sceKernelWriteMapWithGpuMaskIdCommandCaught = false;
    try {
        sceKernelWriteMapWithGpuMaskIdCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteMapWithGpuMaskIdCommandCaught = (std::string(error.what()) == "sceKernelWriteMapWithGpuMaskIdCommand not implemented");
    }
    Require(sceKernelWriteMapWithGpuMaskIdCommandCaught);
    bool sceKernelWriteModifyMtypeProtectWithGpuMaskIdCommandCaught = false;
    try {
        sceKernelWriteModifyMtypeProtectWithGpuMaskIdCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteModifyMtypeProtectWithGpuMaskIdCommandCaught = (std::string(error.what()) == "sceKernelWriteModifyMtypeProtectWithGpuMaskIdCommand not implemented");
    }
    Require(sceKernelWriteModifyMtypeProtectWithGpuMaskIdCommandCaught);
    bool sceKernelWriteModifyProtectCommandCaught = false;
    try {
        sceKernelWriteModifyProtectCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteModifyProtectCommandCaught = (std::string(error.what()) == "sceKernelWriteModifyProtectCommand not implemented");
    }
    Require(sceKernelWriteModifyProtectCommandCaught);
    bool sceKernelWriteModifyProtectWithGpuMaskIdCommandCaught = false;
    try {
        sceKernelWriteModifyProtectWithGpuMaskIdCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteModifyProtectWithGpuMaskIdCommandCaught = (std::string(error.what()) == "sceKernelWriteModifyProtectWithGpuMaskIdCommand not implemented");
    }
    Require(sceKernelWriteModifyProtectWithGpuMaskIdCommandCaught);
    bool sceKernelWriteMultiMapCommandCaught = false;
    try {
        sceKernelWriteMultiMapCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteMultiMapCommandCaught = (std::string(error.what()) == "sceKernelWriteMultiMapCommand not implemented");
    }
    Require(sceKernelWriteMultiMapCommandCaught);
    bool sceKernelWriteMultiMapWithGpuMaskIdCommandCaught = false;
    try {
        sceKernelWriteMultiMapWithGpuMaskIdCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteMultiMapWithGpuMaskIdCommandCaught = (std::string(error.what()) == "sceKernelWriteMultiMapWithGpuMaskIdCommand not implemented");
    }
    Require(sceKernelWriteMultiMapWithGpuMaskIdCommandCaught);
    bool sceKernelWriteRemapCommandCaught = false;
    try {
        sceKernelWriteRemapCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteRemapCommandCaught = (std::string(error.what()) == "sceKernelWriteRemapCommand not implemented");
    }
    Require(sceKernelWriteRemapCommandCaught);
    bool sceKernelWriteRemapWithGpuMaskIdCommandCaught = false;
    try {
        sceKernelWriteRemapWithGpuMaskIdCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteRemapWithGpuMaskIdCommandCaught = (std::string(error.what()) == "sceKernelWriteRemapWithGpuMaskIdCommand not implemented");
    }
    Require(sceKernelWriteRemapWithGpuMaskIdCommandCaught);
    bool sceKernelWriteSdkEventLogCaught = false;
    try {
        sceKernelWriteSdkEventLog();
    } catch (const std::runtime_error& error) {
        sceKernelWriteSdkEventLogCaught = (std::string(error.what()) == "sceKernelWriteSdkEventLog not implemented");
    }
    Require(sceKernelWriteSdkEventLogCaught);
    bool sceKernelWriteSdkEventLogVCaught = false;
    try {
        sceKernelWriteSdkEventLogV();
    } catch (const std::runtime_error& error) {
        sceKernelWriteSdkEventLogVCaught = (std::string(error.what()) == "sceKernelWriteSdkEventLogV not implemented");
    }
    Require(sceKernelWriteSdkEventLogVCaught);
    bool sceKernelWriteUnmapCommandCaught = false;
    try {
        sceKernelWriteUnmapCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteUnmapCommandCaught = (std::string(error.what()) == "sceKernelWriteUnmapCommand not implemented");
    }
    Require(sceKernelWriteUnmapCommandCaught);
    bool sceKernelWriteWaitOnAddressCommandCaught = false;
    try {
        sceKernelWriteWaitOnAddressCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteWaitOnAddressCommandCaught = (std::string(error.what()) == "sceKernelWriteWaitOnAddressCommand not implemented");
    }
    Require(sceKernelWriteWaitOnAddressCommandCaught);
    bool sceKernelWriteWaitOnCounterCommandCaught = false;
    try {
        sceKernelWriteWaitOnCounterCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteWaitOnCounterCommandCaught = (std::string(error.what()) == "sceKernelWriteWaitOnCounterCommand not implemented");
    }
    Require(sceKernelWriteWaitOnCounterCommandCaught);
    bool sceKernelWriteWriteAddressCommandCaught = false;
    try {
        sceKernelWriteWriteAddressCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteWriteAddressCommandCaught = (std::string(error.what()) == "sceKernelWriteWriteAddressCommand not implemented");
    }
    Require(sceKernelWriteWriteAddressCommandCaught);
    bool sceKernelWriteWriteCounterCommandCaught = false;
    try {
        sceKernelWriteWriteCounterCommand();
    } catch (const std::runtime_error& error) {
        sceKernelWriteWriteCounterCommandCaught = (std::string(error.what()) == "sceKernelWriteWriteCounterCommand not implemented");
    }
    Require(sceKernelWriteWriteCounterCommandCaught);
    return 0;
}
