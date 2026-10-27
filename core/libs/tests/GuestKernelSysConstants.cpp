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
    bool sceKernelGetUtokenDataExecutionForRcmgrCaught = false;
    try {
        sceKernelGetUtokenDataExecutionForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetUtokenDataExecutionForRcmgrCaught = (std::string(error.what()) == "sceKernelGetUtokenDataExecutionForRcmgr not implemented");
    }
    Require(sceKernelGetUtokenDataExecutionForRcmgrCaught);
    bool sceKernelGetUtokenExpirationTimeNotafterForRcmgrCaught = false;
    try {
        sceKernelGetUtokenExpirationTimeNotafterForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetUtokenExpirationTimeNotafterForRcmgrCaught = (std::string(error.what()) == "sceKernelGetUtokenExpirationTimeNotafterForRcmgr not implemented");
    }
    Require(sceKernelGetUtokenExpirationTimeNotafterForRcmgrCaught);
    bool sceKernelGetUtokenExpirationTimeNotbeforeForRcmgrCaught = false;
    try {
        sceKernelGetUtokenExpirationTimeNotbeforeForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetUtokenExpirationTimeNotbeforeForRcmgrCaught = (std::string(error.what()) == "sceKernelGetUtokenExpirationTimeNotbeforeForRcmgr not implemented");
    }
    Require(sceKernelGetUtokenExpirationTimeNotbeforeForRcmgrCaught);
    bool sceKernelGetUtokenFakeSharefactoryForRcmgrCaught = false;
    try {
        sceKernelGetUtokenFakeSharefactoryForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetUtokenFakeSharefactoryForRcmgrCaught = (std::string(error.what()) == "sceKernelGetUtokenFakeSharefactoryForRcmgr not implemented");
    }
    Require(sceKernelGetUtokenFakeSharefactoryForRcmgrCaught);
    bool sceKernelGetUtokenFlagedUpdaterForRcmgrCaught = false;
    try {
        sceKernelGetUtokenFlagedUpdaterForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetUtokenFlagedUpdaterForRcmgrCaught = (std::string(error.what()) == "sceKernelGetUtokenFlagedUpdaterForRcmgr not implemented");
    }
    Require(sceKernelGetUtokenFlagedUpdaterForRcmgrCaught);
    bool sceKernelGetUtokenNpEnvSwitchingForRcmgrCaught = false;
    try {
        sceKernelGetUtokenNpEnvSwitchingForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetUtokenNpEnvSwitchingForRcmgrCaught = (std::string(error.what()) == "sceKernelGetUtokenNpEnvSwitchingForRcmgr not implemented");
    }
    Require(sceKernelGetUtokenNpEnvSwitchingForRcmgrCaught);
    bool sceKernelGetUtokenSaveDataRepairForRcmgrCaught = false;
    try {
        sceKernelGetUtokenSaveDataRepairForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetUtokenSaveDataRepairForRcmgrCaught = (std::string(error.what()) == "sceKernelGetUtokenSaveDataRepairForRcmgr not implemented");
    }
    Require(sceKernelGetUtokenSaveDataRepairForRcmgrCaught);
    bool sceKernelGetUtokenStoreModeForRcmgrCaught = false;
    try {
        sceKernelGetUtokenStoreModeForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetUtokenStoreModeForRcmgrCaught = (std::string(error.what()) == "sceKernelGetUtokenStoreModeForRcmgr not implemented");
    }
    Require(sceKernelGetUtokenStoreModeForRcmgrCaught);
    bool sceKernelGetUtokenUseSoftwagnerForAcmgrCaught = false;
    try {
        sceKernelGetUtokenUseSoftwagnerForAcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetUtokenUseSoftwagnerForAcmgrCaught = (std::string(error.what()) == "sceKernelGetUtokenUseSoftwagnerForAcmgr not implemented");
    }
    Require(sceKernelGetUtokenUseSoftwagnerForAcmgrCaught);
    bool sceKernelGetUtokenUseSoftwagnerForRcmgrCaught = false;
    try {
        sceKernelGetUtokenUseSoftwagnerForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetUtokenUseSoftwagnerForRcmgrCaught = (std::string(error.what()) == "sceKernelGetUtokenUseSoftwagnerForRcmgr not implemented");
    }
    Require(sceKernelGetUtokenUseSoftwagnerForRcmgrCaught);
    bool sceKernelGetUtokenWeakenedPortRestrictionForRcmgrCaught = false;
    try {
        sceKernelGetUtokenWeakenedPortRestrictionForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetUtokenWeakenedPortRestrictionForRcmgrCaught = (std::string(error.what()) == "sceKernelGetUtokenWeakenedPortRestrictionForRcmgr not implemented");
    }
    Require(sceKernelGetUtokenWeakenedPortRestrictionForRcmgrCaught);
    bool sceKernelGetVrCaptureSizeCaught = false;
    try {
        sceKernelGetVrCaptureSize();
    } catch (const std::runtime_error& error) {
        sceKernelGetVrCaptureSizeCaught = (std::string(error.what()) == "sceKernelGetVrCaptureSize not implemented");
    }
    Require(sceKernelGetVrCaptureSizeCaught);
    bool sceKernelGiveDirectMemoryToMapperCaught = false;
    try {
        sceKernelGiveDirectMemoryToMapper();
    } catch (const std::runtime_error& error) {
        sceKernelGiveDirectMemoryToMapperCaught = (std::string(error.what()) == "sceKernelGiveDirectMemoryToMapper not implemented");
    }
    Require(sceKernelGiveDirectMemoryToMapperCaught);
    bool sceKernelHwGetBdDriveInfoCaught = false;
    try {
        sceKernelHwGetBdDriveInfo();
    } catch (const std::runtime_error& error) {
        sceKernelHwGetBdDriveInfoCaught = (std::string(error.what()) == "sceKernelHwGetBdDriveInfo not implemented");
    }
    Require(sceKernelHwGetBdDriveInfoCaught);
    bool sceKernelHwHasOpticalOutCaught = false;
    try {
        sceKernelHwHasOpticalOut();
    } catch (const std::runtime_error& error) {
        sceKernelHwHasOpticalOutCaught = (std::string(error.what()) == "sceKernelHwHasOpticalOut not implemented");
    }
    Require(sceKernelHwHasOpticalOutCaught);
    bool sceKernelHwHasWlanBtCaught = false;
    try {
        sceKernelHwHasWlanBt();
    } catch (const std::runtime_error& error) {
        sceKernelHwHasWlanBtCaught = (std::string(error.what()) == "sceKernelHwHasWlanBt not implemented");
    }
    Require(sceKernelHwHasWlanBtCaught);
    bool sceKernelIccControlBDPowerStateCaught = false;
    try {
        sceKernelIccControlBDPowerState();
    } catch (const std::runtime_error& error) {
        sceKernelIccControlBDPowerStateCaught = (std::string(error.what()) == "sceKernelIccControlBDPowerState not implemented");
    }
    Require(sceKernelIccControlBDPowerStateCaught);
    bool sceKernelIccControlUSBPowerStateCaught = false;
    try {
        sceKernelIccControlUSBPowerState();
    } catch (const std::runtime_error& error) {
        sceKernelIccControlUSBPowerStateCaught = (std::string(error.what()) == "sceKernelIccControlUSBPowerState not implemented");
    }
    Require(sceKernelIccControlUSBPowerStateCaught);
    bool sceKernelIccGetBDPowerStateCaught = false;
    try {
        sceKernelIccGetBDPowerState();
    } catch (const std::runtime_error& error) {
        sceKernelIccGetBDPowerStateCaught = (std::string(error.what()) == "sceKernelIccGetBDPowerState not implemented");
    }
    Require(sceKernelIccGetBDPowerStateCaught);
    bool sceKernelIccGetBootTimestampCaught = false;
    try {
        sceKernelIccGetBootTimestamp();
    } catch (const std::runtime_error& error) {
        sceKernelIccGetBootTimestampCaught = (std::string(error.what()) == "sceKernelIccGetBootTimestamp not implemented");
    }
    Require(sceKernelIccGetBootTimestampCaught);
    bool sceKernelIccGetCountTimeCaught = false;
    try {
        sceKernelIccGetCountTime();
    } catch (const std::runtime_error& error) {
        sceKernelIccGetCountTimeCaught = (std::string(error.what()) == "sceKernelIccGetCountTime not implemented");
    }
    Require(sceKernelIccGetCountTimeCaught);
    bool sceKernelIccGetCpuInfoBitCaught = false;
    try {
        sceKernelIccGetCpuInfoBit();
    } catch (const std::runtime_error& error) {
        sceKernelIccGetCpuInfoBitCaught = (std::string(error.what()) == "sceKernelIccGetCpuInfoBit not implemented");
    }
    Require(sceKernelIccGetCpuInfoBitCaught);
    bool sceKernelIccGetErrLogCaught = false;
    try {
        sceKernelIccGetErrLog();
    } catch (const std::runtime_error& error) {
        sceKernelIccGetErrLogCaught = (std::string(error.what()) == "sceKernelIccGetErrLog not implemented");
    }
    Require(sceKernelIccGetErrLogCaught);
    bool sceKernelIccGetHwInfoCaught = false;
    try {
        sceKernelIccGetHwInfo();
    } catch (const std::runtime_error& error) {
        sceKernelIccGetHwInfoCaught = (std::string(error.what()) == "sceKernelIccGetHwInfo not implemented");
    }
    Require(sceKernelIccGetHwInfoCaught);
    bool sceKernelIccGetPowerNumberOfBootShutdownCaught = false;
    try {
        sceKernelIccGetPowerNumberOfBootShutdown();
    } catch (const std::runtime_error& error) {
        sceKernelIccGetPowerNumberOfBootShutdownCaught = (std::string(error.what()) == "sceKernelIccGetPowerNumberOfBootShutdown not implemented");
    }
    Require(sceKernelIccGetPowerNumberOfBootShutdownCaught);
    return 0;
}
