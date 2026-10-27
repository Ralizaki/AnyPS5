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
    bool sceKernelIsAllowedToSelectDvdRegionCaught = false;
    try {
        sceKernelIsAllowedToSelectDvdRegion();
    } catch (const std::runtime_error& error) {
        sceKernelIsAllowedToSelectDvdRegionCaught = (std::string(error.what()) == "sceKernelIsAllowedToSelectDvdRegion not implemented");
    }
    Require(sceKernelIsAllowedToSelectDvdRegionCaught);
    bool sceKernelIsDebuggerAttachedCaught = false;
    try {
        sceKernelIsDebuggerAttached();
    } catch (const std::runtime_error& error) {
        sceKernelIsDebuggerAttachedCaught = (std::string(error.what()) == "sceKernelIsDebuggerAttached not implemented");
    }
    Require(sceKernelIsDebuggerAttachedCaught);
    bool sceKernelIsExperimentalBetaCaught = false;
    try {
        sceKernelIsExperimentalBeta();
    } catch (const std::runtime_error& error) {
        sceKernelIsExperimentalBetaCaught = (std::string(error.what()) == "sceKernelIsExperimentalBeta not implemented");
    }
    Require(sceKernelIsExperimentalBetaCaught);
    bool sceKernelIsGenuineCEXCaught = false;
    try {
        sceKernelIsGenuineCEX();
    } catch (const std::runtime_error& error) {
        sceKernelIsGenuineCEXCaught = (std::string(error.what()) == "sceKernelIsGenuineCEX not implemented");
    }
    Require(sceKernelIsGenuineCEXCaught);
    bool sceKernelIsGenuineDevKitCaught = false;
    try {
        sceKernelIsGenuineDevKit();
    } catch (const std::runtime_error& error) {
        sceKernelIsGenuineDevKitCaught = (std::string(error.what()) == "sceKernelIsGenuineDevKit not implemented");
    }
    Require(sceKernelIsGenuineDevKitCaught);
    bool sceKernelIsGenuineTestKitCaught = false;
    try {
        sceKernelIsGenuineTestKit();
    } catch (const std::runtime_error& error) {
        sceKernelIsGenuineTestKitCaught = (std::string(error.what()) == "sceKernelIsGenuineTestKit not implemented");
    }
    Require(sceKernelIsGenuineTestKitCaught);
    bool sceKernelIsInSandboxCaught = false;
    try {
        sceKernelIsInSandbox();
    } catch (const std::runtime_error& error) {
        sceKernelIsInSandboxCaught = (std::string(error.what()) == "sceKernelIsInSandbox not implemented");
    }
    Require(sceKernelIsInSandboxCaught);
    bool sceKernelIsKratosCaught = false;
    try {
        sceKernelIsKratos();
    } catch (const std::runtime_error& error) {
        sceKernelIsKratosCaught = (std::string(error.what()) == "sceKernelIsKratos not implemented");
    }
    Require(sceKernelIsKratosCaught);
    bool sceKernelIsM2DeviceAttachedCaught = false;
    try {
        sceKernelIsM2DeviceAttached();
    } catch (const std::runtime_error& error) {
        sceKernelIsM2DeviceAttachedCaught = (std::string(error.what()) == "sceKernelIsM2DeviceAttached not implemented");
    }
    Require(sceKernelIsM2DeviceAttachedCaught);
    bool sceKernelIsMainOnStanbyModeCaught = false;
    try {
        sceKernelIsMainOnStanbyMode();
    } catch (const std::runtime_error& error) {
        sceKernelIsMainOnStanbyModeCaught = (std::string(error.what()) == "sceKernelIsMainOnStanbyMode not implemented");
    }
    Require(sceKernelIsMainOnStanbyModeCaught);
    bool sceKernelIsMainOnStandbyModeCaught = false;
    try {
        sceKernelIsMainOnStandbyMode();
    } catch (const std::runtime_error& error) {
        sceKernelIsMainOnStandbyModeCaught = (std::string(error.what()) == "sceKernelIsMainOnStandbyMode not implemented");
    }
    Require(sceKernelIsMainOnStandbyModeCaught);
    bool sceKernelIsModuleLoadedCaught = false;
    try {
        sceKernelIsModuleLoaded();
    } catch (const std::runtime_error& error) {
        sceKernelIsModuleLoadedCaught = (std::string(error.what()) == "sceKernelIsModuleLoaded not implemented");
    }
    Require(sceKernelIsModuleLoadedCaught);
    bool sceKernelIsNeoModeCaught = false;
    try {
        sceKernelIsNeoMode();
    } catch (const std::runtime_error& error) {
        sceKernelIsNeoModeCaught = (std::string(error.what()) == "sceKernelIsNeoMode not implemented");
    }
    Require(sceKernelIsNeoModeCaught);
    bool sceKernelIsProsperoCaught = false;
    try {
        sceKernelIsProspero();
    } catch (const std::runtime_error& error) {
        sceKernelIsProsperoCaught = (std::string(error.what()) == "sceKernelIsProspero not implemented");
    }
    Require(sceKernelIsProsperoCaught);
    bool sceKernelIsPs4ProcessCaught = false;
    try {
        sceKernelIsPs4Process();
    } catch (const std::runtime_error& error) {
        sceKernelIsPs4ProcessCaught = (std::string(error.what()) == "sceKernelIsPs4Process not implemented");
    }
    Require(sceKernelIsPs4ProcessCaught);
    bool sceKernelIsTestKitCaught = false;
    try {
        sceKernelIsTestKit();
    } catch (const std::runtime_error& error) {
        sceKernelIsTestKitCaught = (std::string(error.what()) == "sceKernelIsTestKit not implemented");
    }
    Require(sceKernelIsTestKitCaught);
    bool sceKernelJitGetSharedMemoryInfoCaught = false;
    try {
        sceKernelJitGetSharedMemoryInfo();
    } catch (const std::runtime_error& error) {
        sceKernelJitGetSharedMemoryInfoCaught = (std::string(error.what()) == "sceKernelJitGetSharedMemoryInfo not implemented");
    }
    Require(sceKernelJitGetSharedMemoryInfoCaught);
    bool sceKernelKernelHeapUsageCaught = false;
    try {
        sceKernelKernelHeapUsage();
    } catch (const std::runtime_error& error) {
        sceKernelKernelHeapUsageCaught = (std::string(error.what()) == "sceKernelKernelHeapUsage not implemented");
    }
    Require(sceKernelKernelHeapUsageCaught);
    bool sceKernelLoadStartModuleInternalForMonoCaught = false;
    try {
        sceKernelLoadStartModuleInternalForMono();
    } catch (const std::runtime_error& error) {
        sceKernelLoadStartModuleInternalForMonoCaught = (std::string(error.what()) == "sceKernelLoadStartModuleInternalForMono not implemented");
    }
    Require(sceKernelLoadStartModuleInternalForMonoCaught);
    bool sceKernelLwfsAllocateBlockCaught = false;
    try {
        sceKernelLwfsAllocateBlock();
    } catch (const std::runtime_error& error) {
        sceKernelLwfsAllocateBlockCaught = (std::string(error.what()) == "sceKernelLwfsAllocateBlock not implemented");
    }
    Require(sceKernelLwfsAllocateBlockCaught);
    bool sceKernelLwfsLseekCaught = false;
    try {
        sceKernelLwfsLseek();
    } catch (const std::runtime_error& error) {
        sceKernelLwfsLseekCaught = (std::string(error.what()) == "sceKernelLwfsLseek not implemented");
    }
    Require(sceKernelLwfsLseekCaught);
    bool sceKernelLwfsSetAttributeCaught = false;
    try {
        sceKernelLwfsSetAttribute();
    } catch (const std::runtime_error& error) {
        sceKernelLwfsSetAttributeCaught = (std::string(error.what()) == "sceKernelLwfsSetAttribute not implemented");
    }
    Require(sceKernelLwfsSetAttributeCaught);
    bool sceKernelLwfsTrimBlockCaught = false;
    try {
        sceKernelLwfsTrimBlock();
    } catch (const std::runtime_error& error) {
        sceKernelLwfsTrimBlockCaught = (std::string(error.what()) == "sceKernelLwfsTrimBlock not implemented");
    }
    Require(sceKernelLwfsTrimBlockCaught);
    bool sceKernelLwfsWriteCaught = false;
    try {
        sceKernelLwfsWrite();
    } catch (const std::runtime_error& error) {
        sceKernelLwfsWriteCaught = (std::string(error.what()) == "sceKernelLwfsWrite not implemented");
    }
    Require(sceKernelLwfsWriteCaught);
    bool sceKernelMapSanitizerShadowMemoryCaught = false;
    try {
        sceKernelMapSanitizerShadowMemory();
    } catch (const std::runtime_error& error) {
        sceKernelMapSanitizerShadowMemoryCaught = (std::string(error.what()) == "sceKernelMapSanitizerShadowMemory not implemented");
    }
    Require(sceKernelMapSanitizerShadowMemoryCaught);
    return 0;
}
