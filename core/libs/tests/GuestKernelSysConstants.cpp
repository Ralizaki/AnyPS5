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
    bool sceKernelEventLogPreadCaught = false;
    try {
        sceKernelEventLogPread();
    } catch (const std::runtime_error& error) {
        sceKernelEventLogPreadCaught = (std::string(error.what()) == "sceKernelEventLogPread not implemented");
    }
    Require(sceKernelEventLogPreadCaught);
    bool sceKernelEventLogReadCaught = false;
    try {
        sceKernelEventLogRead();
    } catch (const std::runtime_error& error) {
        sceKernelEventLogReadCaught = (std::string(error.what()) == "sceKernelEventLogRead not implemented");
    }
    Require(sceKernelEventLogReadCaught);
    bool sceKernelEventLogWriteCaught = false;
    try {
        sceKernelEventLogWrite();
    } catch (const std::runtime_error& error) {
        sceKernelEventLogWriteCaught = (std::string(error.what()) == "sceKernelEventLogWrite not implemented");
    }
    Require(sceKernelEventLogWriteCaught);
    bool sceKernelExpectedHddFormatCaught = false;
    try {
        sceKernelExpectedHddFormat();
    } catch (const std::runtime_error& error) {
        sceKernelExpectedHddFormatCaught = (std::string(error.what()) == "sceKernelExpectedHddFormat not implemented");
    }
    Require(sceKernelExpectedHddFormatCaught);
    bool sceKernelFlockCaught = false;
    try {
        sceKernelFlock();
    } catch (const std::runtime_error& error) {
        sceKernelFlockCaught = (std::string(error.what()) == "sceKernelFlock not implemented");
    }
    Require(sceKernelFlockCaught);
    bool sceKernelGetACInfoAllForCoredumpCaught = false;
    try {
        sceKernelGetACInfoAllForCoredump();
    } catch (const std::runtime_error& error) {
        sceKernelGetACInfoAllForCoredumpCaught = (std::string(error.what()) == "sceKernelGetACInfoAllForCoredump not implemented");
    }
    Require(sceKernelGetACInfoAllForCoredumpCaught);
    bool sceKernelGetAppCategoryTypeCaught = false;
    try {
        sceKernelGetAppCategoryType();
    } catch (const std::runtime_error& error) {
        sceKernelGetAppCategoryTypeCaught = (std::string(error.what()) == "sceKernelGetAppCategoryType not implemented");
    }
    Require(sceKernelGetAppCategoryTypeCaught);
    bool sceKernelGetAppInfoByAppIdCaught = false;
    try {
        sceKernelGetAppInfoByAppId();
    } catch (const std::runtime_error& error) {
        sceKernelGetAppInfoByAppIdCaught = (std::string(error.what()) == "sceKernelGetAppInfoByAppId not implemented");
    }
    Require(sceKernelGetAppInfoByAppIdCaught);
    bool sceKernelGetAppStateCaught = false;
    try {
        sceKernelGetAppState();
    } catch (const std::runtime_error& error) {
        sceKernelGetAppStateCaught = (std::string(error.what()) == "sceKernelGetAppState not implemented");
    }
    Require(sceKernelGetAppStateCaught);
    bool sceKernelGetAslrStatusCaught = false;
    try {
        sceKernelGetAslrStatus();
    } catch (const std::runtime_error& error) {
        sceKernelGetAslrStatusCaught = (std::string(error.what()) == "sceKernelGetAslrStatus not implemented");
    }
    Require(sceKernelGetAslrStatusCaught);
    bool sceKernelGetAutoUpdateVersionCaught = false;
    try {
        sceKernelGetAutoUpdateVersion();
    } catch (const std::runtime_error& error) {
        sceKernelGetAutoUpdateVersionCaught = (std::string(error.what()) == "sceKernelGetAutoUpdateVersion not implemented");
    }
    Require(sceKernelGetAutoUpdateVersionCaught);
    bool sceKernelGetBackupRestoreModeCaught = false;
    try {
        sceKernelGetBackupRestoreMode();
    } catch (const std::runtime_error& error) {
        sceKernelGetBackupRestoreModeCaught = (std::string(error.what()) == "sceKernelGetBackupRestoreMode not implemented");
    }
    Require(sceKernelGetBackupRestoreModeCaught);
    bool sceKernelGetBackupRestoreModeOfNextBootCaught = false;
    try {
        sceKernelGetBackupRestoreModeOfNextBoot();
    } catch (const std::runtime_error& error) {
        sceKernelGetBackupRestoreModeOfNextBootCaught = (std::string(error.what()) == "sceKernelGetBackupRestoreModeOfNextBoot not implemented");
    }
    Require(sceKernelGetBackupRestoreModeOfNextBootCaught);
    bool sceKernelGetBasicProductShapeCaught = false;
    try {
        sceKernelGetBasicProductShape();
    } catch (const std::runtime_error& error) {
        sceKernelGetBasicProductShapeCaught = (std::string(error.what()) == "sceKernelGetBasicProductShape not implemented");
    }
    Require(sceKernelGetBasicProductShapeCaught);
    bool sceKernelGetBetaUpdateTestForRcmgrCaught = false;
    try {
        sceKernelGetBetaUpdateTestForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetBetaUpdateTestForRcmgrCaught = (std::string(error.what()) == "sceKernelGetBetaUpdateTestForRcmgr not implemented");
    }
    Require(sceKernelGetBetaUpdateTestForRcmgrCaught);
    bool sceKernelGetBioUsageAllCaught = false;
    try {
        sceKernelGetBioUsageAll();
    } catch (const std::runtime_error& error) {
        sceKernelGetBioUsageAllCaught = (std::string(error.what()) == "sceKernelGetBioUsageAll not implemented");
    }
    Require(sceKernelGetBioUsageAllCaught);
    bool sceKernelGetBootReqNotifyCountCaught = false;
    try {
        sceKernelGetBootReqNotifyCount();
    } catch (const std::runtime_error& error) {
        sceKernelGetBootReqNotifyCountCaught = (std::string(error.what()) == "sceKernelGetBootReqNotifyCount not implemented");
    }
    Require(sceKernelGetBootReqNotifyCountCaught);
    bool sceKernelGetBudgetCaught = false;
    try {
        sceKernelGetBudget();
    } catch (const std::runtime_error& error) {
        sceKernelGetBudgetCaught = (std::string(error.what()) == "sceKernelGetBudget not implemented");
    }
    Require(sceKernelGetBudgetCaught);
    bool sceKernelGetBuildNumberCaught = false;
    try {
        sceKernelGetBuildNumber();
    } catch (const std::runtime_error& error) {
        sceKernelGetBuildNumberCaught = (std::string(error.what()) == "sceKernelGetBuildNumber not implemented");
    }
    Require(sceKernelGetBuildNumberCaught);
    bool sceKernelGetCallRecordCaught = false;
    try {
        sceKernelGetCallRecord();
    } catch (const std::runtime_error& error) {
        sceKernelGetCallRecordCaught = (std::string(error.what()) == "sceKernelGetCallRecord not implemented");
    }
    Require(sceKernelGetCallRecordCaught);
    bool sceKernelGetChildAppCaught = false;
    try {
        sceKernelGetChildApp();
    } catch (const std::runtime_error& error) {
        sceKernelGetChildAppCaught = (std::string(error.what()) == "sceKernelGetChildApp not implemented");
    }
    Require(sceKernelGetChildAppCaught);
    bool sceKernelGetCompiledSdkVersionByPathCaught = false;
    try {
        sceKernelGetCompiledSdkVersionByPath();
    } catch (const std::runtime_error& error) {
        sceKernelGetCompiledSdkVersionByPathCaught = (std::string(error.what()) == "sceKernelGetCompiledSdkVersionByPath not implemented");
    }
    Require(sceKernelGetCompiledSdkVersionByPathCaught);
    bool sceKernelGetCompiledSdkVersionByPidCaught = false;
    try {
        sceKernelGetCompiledSdkVersionByPid();
    } catch (const std::runtime_error& error) {
        sceKernelGetCompiledSdkVersionByPidCaught = (std::string(error.what()) == "sceKernelGetCompiledSdkVersionByPid not implemented");
    }
    Require(sceKernelGetCompiledSdkVersionByPidCaught);
    bool sceKernelGetCoredumpAppInfoCaught = false;
    try {
        sceKernelGetCoredumpAppInfo();
    } catch (const std::runtime_error& error) {
        sceKernelGetCoredumpAppInfoCaught = (std::string(error.what()) == "sceKernelGetCoredumpAppInfo not implemented");
    }
    Require(sceKernelGetCoredumpAppInfoCaught);
    return 0;
}
