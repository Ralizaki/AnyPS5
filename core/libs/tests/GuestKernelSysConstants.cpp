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
    bool sceCoredumpDebugForceCoredumpOnAppCloseCaught = false;
    try {
        sceCoredumpDebugForceCoredumpOnAppClose();
    } catch (const std::runtime_error& error) {
        sceCoredumpDebugForceCoredumpOnAppCloseCaught = (std::string(error.what()) == "sceCoredumpDebugForceCoredumpOnAppClose not implemented");
    }
    Require(sceCoredumpDebugForceCoredumpOnAppCloseCaught);
    bool sceCoredumpDebugTriggerCoredumpCaught = false;
    try {
        sceCoredumpDebugTriggerCoredump();
    } catch (const std::runtime_error& error) {
        sceCoredumpDebugTriggerCoredumpCaught = (std::string(error.what()) == "sceCoredumpDebugTriggerCoredump not implemented");
    }
    Require(sceCoredumpDebugTriggerCoredumpCaught);
    bool sceCoredumpGetStopInfoGpuCaught = false;
    try {
        sceCoredumpGetStopInfoGpu();
    } catch (const std::runtime_error& error) {
        sceCoredumpGetStopInfoGpuCaught = (std::string(error.what()) == "sceCoredumpGetStopInfoGpu not implemented");
    }
    Require(sceCoredumpGetStopInfoGpuCaught);
    bool sceCoredumpInternalGetThreadContextInfoCaught = false;
    try {
        sceCoredumpInternalGetThreadContextInfo();
    } catch (const std::runtime_error& error) {
        sceCoredumpInternalGetThreadContextInfoCaught = (std::string(error.what()) == "sceCoredumpInternalGetThreadContextInfo not implemented");
    }
    Require(sceCoredumpInternalGetThreadContextInfoCaught);
    bool sceKernelAddACInfoCaught = false;
    try {
        sceKernelAddACInfo();
    } catch (const std::runtime_error& error) {
        sceKernelAddACInfoCaught = (std::string(error.what()) == "sceKernelAddACInfo not implemented");
    }
    Require(sceKernelAddACInfoCaught);
    bool sceKernelAddCpumodeEventCaught = false;
    try {
        sceKernelAddCpumodeEvent();
    } catch (const std::runtime_error& error) {
        sceKernelAddCpumodeEventCaught = (std::string(error.what()) == "sceKernelAddCpumodeEvent not implemented");
    }
    Require(sceKernelAddCpumodeEventCaught);
    bool sceKernelAddGpuExceptionEventCaught = false;
    try {
        sceKernelAddGpuExceptionEvent();
    } catch (const std::runtime_error& error) {
        sceKernelAddGpuExceptionEventCaught = (std::string(error.what()) == "sceKernelAddGpuExceptionEvent not implemented");
    }
    Require(sceKernelAddGpuExceptionEventCaught);
    bool sceKernelAddProcessToCanvasMapCaught = false;
    try {
        sceKernelAddProcessToCanvasMap();
    } catch (const std::runtime_error& error) {
        sceKernelAddProcessToCanvasMapCaught = (std::string(error.what()) == "sceKernelAddProcessToCanvasMap not implemented");
    }
    Require(sceKernelAddProcessToCanvasMapCaught);
    bool sceKernelAllocateDirectMemory2Caught = false;
    try {
        sceKernelAllocateDirectMemory2();
    } catch (const std::runtime_error& error) {
        sceKernelAllocateDirectMemory2Caught = (std::string(error.what()) == "sceKernelAllocateDirectMemory2 not implemented");
    }
    Require(sceKernelAllocateDirectMemory2Caught);
    bool sceKernelAllocateDirectMemoryForAppCaught = false;
    try {
        sceKernelAllocateDirectMemoryForApp();
    } catch (const std::runtime_error& error) {
        sceKernelAllocateDirectMemoryForAppCaught = (std::string(error.what()) == "sceKernelAllocateDirectMemoryForApp not implemented");
    }
    Require(sceKernelAllocateDirectMemoryForAppCaught);
    bool sceKernelAllocateDirectMemoryForMiniAppCaught = false;
    try {
        sceKernelAllocateDirectMemoryForMiniApp();
    } catch (const std::runtime_error& error) {
        sceKernelAllocateDirectMemoryForMiniAppCaught = (std::string(error.what()) == "sceKernelAllocateDirectMemoryForMiniApp not implemented");
    }
    Require(sceKernelAllocateDirectMemoryForMiniAppCaught);
    bool sceKernelAllocateToolMemoryCaught = false;
    try {
        sceKernelAllocateToolMemory();
    } catch (const std::runtime_error& error) {
        sceKernelAllocateToolMemoryCaught = (std::string(error.what()) == "sceKernelAllocateToolMemory not implemented");
    }
    Require(sceKernelAllocateToolMemoryCaught);
    bool sceKernelAllocateTraceDirectMemoryCaught = false;
    try {
        sceKernelAllocateTraceDirectMemory();
    } catch (const std::runtime_error& error) {
        sceKernelAllocateTraceDirectMemoryCaught = (std::string(error.what()) == "sceKernelAllocateTraceDirectMemory not implemented");
    }
    Require(sceKernelAllocateTraceDirectMemoryCaught);
    bool sceKernelAprCtrlCaught = false;
    try {
        sceKernelAprCtrl();
    } catch (const std::runtime_error& error) {
        sceKernelAprCtrlCaught = (std::string(error.what()) == "sceKernelAprCtrl not implemented");
    }
    Require(sceKernelAprCtrlCaught);
    bool sceKernelAprSubmitCommandBufferAndGetResult_TESTCaught = false;
    try {
        sceKernelAprSubmitCommandBufferAndGetResult_TEST();
    } catch (const std::runtime_error& error) {
        sceKernelAprSubmitCommandBufferAndGetResult_TESTCaught = (std::string(error.what()) == "sceKernelAprSubmitCommandBufferAndGetResult_TEST not implemented");
    }
    Require(sceKernelAprSubmitCommandBufferAndGetResult_TESTCaught);
    bool sceKernelAprSubmitCommandBuffer_TESTCaught = false;
    try {
        sceKernelAprSubmitCommandBuffer_TEST();
    } catch (const std::runtime_error& error) {
        sceKernelAprSubmitCommandBuffer_TESTCaught = (std::string(error.what()) == "sceKernelAprSubmitCommandBuffer_TEST not implemented");
    }
    Require(sceKernelAprSubmitCommandBuffer_TESTCaught);
    bool sceKernelAvailableToolMemorySizeCaught = false;
    try {
        sceKernelAvailableToolMemorySize();
    } catch (const std::runtime_error& error) {
        sceKernelAvailableToolMemorySizeCaught = (std::string(error.what()) == "sceKernelAvailableToolMemorySize not implemented");
    }
    Require(sceKernelAvailableToolMemorySizeCaught);
    bool sceKernelBacktraceSelfCaught = false;
    try {
        sceKernelBacktraceSelf();
    } catch (const std::runtime_error& error) {
        sceKernelBacktraceSelfCaught = (std::string(error.what()) == "sceKernelBacktraceSelf not implemented");
    }
    Require(sceKernelBacktraceSelfCaught);
    bool sceKernelBeginAppMountCaught = false;
    try {
        sceKernelBeginAppMount();
    } catch (const std::runtime_error& error) {
        sceKernelBeginAppMountCaught = (std::string(error.what()) == "sceKernelBeginAppMount not implemented");
    }
    Require(sceKernelBeginAppMountCaught);
    bool sceKernelBeginAppMount2Caught = false;
    try {
        sceKernelBeginAppMount2();
    } catch (const std::runtime_error& error) {
        sceKernelBeginAppMount2Caught = (std::string(error.what()) == "sceKernelBeginAppMount2 not implemented");
    }
    Require(sceKernelBeginAppMount2Caught);
    bool sceKernelCallIndirectBufferCaught = false;
    try {
        sceKernelCallIndirectBuffer();
    } catch (const std::runtime_error& error) {
        sceKernelCallIndirectBufferCaught = (std::string(error.what()) == "sceKernelCallIndirectBuffer not implemented");
    }
    Require(sceKernelCallIndirectBufferCaught);
    bool sceKernelCallIndirectBuffer2Caught = false;
    try {
        sceKernelCallIndirectBuffer2();
    } catch (const std::runtime_error& error) {
        sceKernelCallIndirectBuffer2Caught = (std::string(error.what()) == "sceKernelCallIndirectBuffer2 not implemented");
    }
    Require(sceKernelCallIndirectBuffer2Caught);
    bool sceKernelClearBootReqNotifyCountCaught = false;
    try {
        sceKernelClearBootReqNotifyCount();
    } catch (const std::runtime_error& error) {
        sceKernelClearBootReqNotifyCountCaught = (std::string(error.what()) == "sceKernelClearBootReqNotifyCount not implemented");
    }
    Require(sceKernelClearBootReqNotifyCountCaught);
    bool sceKernelCloseSemaCaught = false;
    try {
        sceKernelCloseSema();
    } catch (const std::runtime_error& error) {
        sceKernelCloseSemaCaught = (std::string(error.what()) == "sceKernelCloseSema not implemented");
    }
    Require(sceKernelCloseSemaCaught);
    return 0;
}
