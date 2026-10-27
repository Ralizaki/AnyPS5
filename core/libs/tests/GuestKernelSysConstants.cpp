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
    bool sceKernelIccGetPowerOperatingTimeCaught = false;
    try {
        sceKernelIccGetPowerOperatingTime();
    } catch (const std::runtime_error& error) {
        sceKernelIccGetPowerOperatingTimeCaught = (std::string(error.what()) == "sceKernelIccGetPowerOperatingTime not implemented");
    }
    Require(sceKernelIccGetPowerOperatingTimeCaught);
    bool sceKernelIccGetPowerUpCauseCaught = false;
    try {
        sceKernelIccGetPowerUpCause();
    } catch (const std::runtime_error& error) {
        sceKernelIccGetPowerUpCauseCaught = (std::string(error.what()) == "sceKernelIccGetPowerUpCause not implemented");
    }
    Require(sceKernelIccGetPowerUpCauseCaught);
    bool sceKernelIccGetSysEventLogCaught = false;
    try {
        sceKernelIccGetSysEventLog();
    } catch (const std::runtime_error& error) {
        sceKernelIccGetSysEventLogCaught = (std::string(error.what()) == "sceKernelIccGetSysEventLog not implemented");
    }
    Require(sceKernelIccGetSysEventLogCaught);
    bool sceKernelIccGetUSBPowerStateCaught = false;
    try {
        sceKernelIccGetUSBPowerState();
    } catch (const std::runtime_error& error) {
        sceKernelIccGetUSBPowerStateCaught = (std::string(error.what()) == "sceKernelIccGetUSBPowerState not implemented");
    }
    Require(sceKernelIccGetUSBPowerStateCaught);
    bool sceKernelIccIndicatorBootDoneCaught = false;
    try {
        sceKernelIccIndicatorBootDone();
    } catch (const std::runtime_error& error) {
        sceKernelIccIndicatorBootDoneCaught = (std::string(error.what()) == "sceKernelIccIndicatorBootDone not implemented");
    }
    Require(sceKernelIccIndicatorBootDoneCaught);
    bool sceKernelIccIndicatorShutdownCaught = false;
    try {
        sceKernelIccIndicatorShutdown();
    } catch (const std::runtime_error& error) {
        sceKernelIccIndicatorShutdownCaught = (std::string(error.what()) == "sceKernelIccIndicatorShutdown not implemented");
    }
    Require(sceKernelIccIndicatorShutdownCaught);
    bool sceKernelIccIndicatorStandbyCaught = false;
    try {
        sceKernelIccIndicatorStandby();
    } catch (const std::runtime_error& error) {
        sceKernelIccIndicatorStandbyCaught = (std::string(error.what()) == "sceKernelIccIndicatorStandby not implemented");
    }
    Require(sceKernelIccIndicatorStandbyCaught);
    bool sceKernelIccIndicatorStandbyBootCaught = false;
    try {
        sceKernelIccIndicatorStandbyBoot();
    } catch (const std::runtime_error& error) {
        sceKernelIccIndicatorStandbyBootCaught = (std::string(error.what()) == "sceKernelIccIndicatorStandbyBoot not implemented");
    }
    Require(sceKernelIccIndicatorStandbyBootCaught);
    bool sceKernelIccIndicatorStandbyShutdownCaught = false;
    try {
        sceKernelIccIndicatorStandbyShutdown();
    } catch (const std::runtime_error& error) {
        sceKernelIccIndicatorStandbyShutdownCaught = (std::string(error.what()) == "sceKernelIccIndicatorStandbyShutdown not implemented");
    }
    Require(sceKernelIccIndicatorStandbyShutdownCaught);
    bool sceKernelIccNotifyBootStatusCaught = false;
    try {
        sceKernelIccNotifyBootStatus();
    } catch (const std::runtime_error& error) {
        sceKernelIccNotifyBootStatusCaught = (std::string(error.what()) == "sceKernelIccNotifyBootStatus not implemented");
    }
    Require(sceKernelIccNotifyBootStatusCaught);
    bool sceKernelIccNvsFlushCaught = false;
    try {
        sceKernelIccNvsFlush();
    } catch (const std::runtime_error& error) {
        sceKernelIccNvsFlushCaught = (std::string(error.what()) == "sceKernelIccNvsFlush not implemented");
    }
    Require(sceKernelIccNvsFlushCaught);
    bool sceKernelIccReadPowerBootMessageCaught = false;
    try {
        sceKernelIccReadPowerBootMessage();
    } catch (const std::runtime_error& error) {
        sceKernelIccReadPowerBootMessageCaught = (std::string(error.what()) == "sceKernelIccReadPowerBootMessage not implemented");
    }
    Require(sceKernelIccReadPowerBootMessageCaught);
    bool sceKernelIccSetBuzzerCaught = false;
    try {
        sceKernelIccSetBuzzer();
    } catch (const std::runtime_error& error) {
        sceKernelIccSetBuzzerCaught = (std::string(error.what()) == "sceKernelIccSetBuzzer not implemented");
    }
    Require(sceKernelIccSetBuzzerCaught);
    bool sceKernelIccSetCpuInfoBitCaught = false;
    try {
        sceKernelIccSetCpuInfoBit();
    } catch (const std::runtime_error& error) {
        sceKernelIccSetCpuInfoBitCaught = (std::string(error.what()) == "sceKernelIccSetCpuInfoBit not implemented");
    }
    Require(sceKernelIccSetCpuInfoBitCaught);
    bool sceKernelIccSetDownloadModeCaught = false;
    try {
        sceKernelIccSetDownloadMode();
    } catch (const std::runtime_error& error) {
        sceKernelIccSetDownloadModeCaught = (std::string(error.what()) == "sceKernelIccSetDownloadMode not implemented");
    }
    Require(sceKernelIccSetDownloadModeCaught);
    bool sceKernelInternalGetKmemStatisticsCaught = false;
    try {
        sceKernelInternalGetKmemStatistics();
    } catch (const std::runtime_error& error) {
        sceKernelInternalGetKmemStatisticsCaught = (std::string(error.what()) == "sceKernelInternalGetKmemStatistics not implemented");
    }
    Require(sceKernelInternalGetKmemStatisticsCaught);
    bool sceKernelInternalGetMapStatisticsCaught = false;
    try {
        sceKernelInternalGetMapStatistics();
    } catch (const std::runtime_error& error) {
        sceKernelInternalGetMapStatisticsCaught = (std::string(error.what()) == "sceKernelInternalGetMapStatistics not implemented");
    }
    Require(sceKernelInternalGetMapStatisticsCaught);
    bool sceKernelInternalHeapPrintBacktraceWithModuleInfoCaught = false;
    try {
        sceKernelInternalHeapPrintBacktraceWithModuleInfo();
    } catch (const std::runtime_error& error) {
        sceKernelInternalHeapPrintBacktraceWithModuleInfoCaught = (std::string(error.what()) == "sceKernelInternalHeapPrintBacktraceWithModuleInfo not implemented");
    }
    Require(sceKernelInternalHeapPrintBacktraceWithModuleInfoCaught);
    bool sceKernelInternalMapDirectMemoryCaught = false;
    try {
        sceKernelInternalMapDirectMemory();
    } catch (const std::runtime_error& error) {
        sceKernelInternalMapDirectMemoryCaught = (std::string(error.what()) == "sceKernelInternalMapDirectMemory not implemented");
    }
    Require(sceKernelInternalMapDirectMemoryCaught);
    bool sceKernelInternalMapNamedDirectMemoryCaught = false;
    try {
        sceKernelInternalMapNamedDirectMemory();
    } catch (const std::runtime_error& error) {
        sceKernelInternalMapNamedDirectMemoryCaught = (std::string(error.what()) == "sceKernelInternalMapNamedDirectMemory not implemented");
    }
    Require(sceKernelInternalMapNamedDirectMemoryCaught);
    bool sceKernelInternalResumeDirectMemoryReleaseCaught = false;
    try {
        sceKernelInternalResumeDirectMemoryRelease();
    } catch (const std::runtime_error& error) {
        sceKernelInternalResumeDirectMemoryReleaseCaught = (std::string(error.what()) == "sceKernelInternalResumeDirectMemoryRelease not implemented");
    }
    Require(sceKernelInternalResumeDirectMemoryReleaseCaught);
    bool sceKernelInternalSuspendDirectMemoryReleaseCaught = false;
    try {
        sceKernelInternalSuspendDirectMemoryRelease();
    } catch (const std::runtime_error& error) {
        sceKernelInternalSuspendDirectMemoryReleaseCaught = (std::string(error.what()) == "sceKernelInternalSuspendDirectMemoryRelease not implemented");
    }
    Require(sceKernelInternalSuspendDirectMemoryReleaseCaught);
    bool sceKernelResumeDirectMemoryReleaseCaught = false;
    try {
        sceKernelResumeDirectMemoryRelease();
    } catch (const std::runtime_error& error) {
        sceKernelResumeDirectMemoryReleaseCaught = (std::string(error.what()) == "sceKernelResumeDirectMemoryRelease not implemented");
    }
    Require(sceKernelResumeDirectMemoryReleaseCaught);
    bool sceKernelResumeProcessCaught = false;
    try {
        sceKernelResumeProcess();
    } catch (const std::runtime_error& error) {
        sceKernelResumeProcessCaught = (std::string(error.what()) == "sceKernelResumeProcess not implemented");
    }
    Require(sceKernelResumeProcessCaught);
    bool sceKernelRtldControlCaught = false;
    try {
        sceKernelRtldControl();
    } catch (const std::runtime_error& error) {
        sceKernelRtldControlCaught = (std::string(error.what()) == "sceKernelRtldControl not implemented");
    }
    Require(sceKernelRtldControlCaught);
    return 0;
}
