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
    bool amd64_set_fsbase_nid_postfixCaught = false;
    try {
        amd64_set_fsbase_nid_postfix();
    } catch (const std::runtime_error& error) {
        amd64_set_fsbase_nid_postfixCaught = (std::string(error.what()) == "amd64_set_fsbase_nid_postfix not implemented");
    }
    Require(amd64_set_fsbase_nid_postfixCaught);
    bool blockpool_batch_nid_postfixCaught = false;
    try {
        blockpool_batch_nid_postfix();
    } catch (const std::runtime_error& error) {
        blockpool_batch_nid_postfixCaught = (std::string(error.what()) == "blockpool_batch_nid_postfix not implemented");
    }
    Require(blockpool_batch_nid_postfixCaught);
    bool blockpool_map_nid_postfixCaught = false;
    try {
        blockpool_map_nid_postfix();
    } catch (const std::runtime_error& error) {
        blockpool_map_nid_postfixCaught = (std::string(error.what()) == "blockpool_map_nid_postfix not implemented");
    }
    Require(blockpool_map_nid_postfixCaught);
    bool blockpool_open_nid_postfixCaught = false;
    try {
        blockpool_open_nid_postfix();
    } catch (const std::runtime_error& error) {
        blockpool_open_nid_postfixCaught = (std::string(error.what()) == "blockpool_open_nid_postfix not implemented");
    }
    Require(blockpool_open_nid_postfixCaught);
    bool blockpool_unmap_nid_postfixCaught = false;
    try {
        blockpool_unmap_nid_postfix();
    } catch (const std::runtime_error& error) {
        blockpool_unmap_nid_postfixCaught = (std::string(error.what()) == "blockpool_unmap_nid_postfix not implemented");
    }
    Require(blockpool_unmap_nid_postfixCaught);
    bool cpuset_nid_postfixCaught = false;
    try {
        cpuset_nid_postfix();
    } catch (const std::runtime_error& error) {
        cpuset_nid_postfixCaught = (std::string(error.what()) == "cpuset_nid_postfix not implemented");
    }
    Require(cpuset_nid_postfixCaught);
    bool cpuset_getid_nid_postfixCaught = false;
    try {
        cpuset_getid_nid_postfix();
    } catch (const std::runtime_error& error) {
        cpuset_getid_nid_postfixCaught = (std::string(error.what()) == "cpuset_getid_nid_postfix not implemented");
    }
    Require(cpuset_getid_nid_postfixCaught);
    bool cpuset_setid_nid_postfixCaught = false;
    try {
        cpuset_setid_nid_postfix();
    } catch (const std::runtime_error& error) {
        cpuset_setid_nid_postfixCaught = (std::string(error.what()) == "cpuset_setid_nid_postfix not implemented");
    }
    Require(cpuset_setid_nid_postfixCaught);
    bool dynlib_get_obj_member_nid_postfixCaught = false;
    try {
        dynlib_get_obj_member_nid_postfix();
    } catch (const std::runtime_error& error) {
        dynlib_get_obj_member_nid_postfixCaught = (std::string(error.what()) == "dynlib_get_obj_member_nid_postfix not implemented");
    }
    Require(dynlib_get_obj_member_nid_postfixCaught);
    bool futimesat_nid_postfixCaught = false;
    try {
        futimesat_nid_postfix();
    } catch (const std::runtime_error& error) {
        futimesat_nid_postfixCaught = (std::string(error.what()) == "futimesat_nid_postfix not implemented");
    }
    Require(futimesat_nid_postfixCaught);
    bool sceKernelGetResourceCaught = false;
    try {
        sceKernelGetResource();
    } catch (const std::runtime_error& error) {
        sceKernelGetResourceCaught = (std::string(error.what()) == "sceKernelGetResource not implemented");
    }
    Require(sceKernelGetResourceCaught);
    bool sceKernelGetResourceLimitCaught = false;
    try {
        sceKernelGetResourceLimit();
    } catch (const std::runtime_error& error) {
        sceKernelGetResourceLimitCaught = (std::string(error.what()) == "sceKernelGetResourceLimit not implemented");
    }
    Require(sceKernelGetResourceLimitCaught);
    bool sceKernelGetResourceOneCaught = false;
    try {
        sceKernelGetResourceOne();
    } catch (const std::runtime_error& error) {
        sceKernelGetResourceOneCaught = (std::string(error.what()) == "sceKernelGetResourceOne not implemented");
    }
    Require(sceKernelGetResourceOneCaught);
    bool sceKernelGetSafemodeCaught = false;
    try {
        sceKernelGetSafemode();
    } catch (const std::runtime_error& error) {
        sceKernelGetSafemodeCaught = (std::string(error.what()) == "sceKernelGetSafemode not implemented");
    }
    Require(sceKernelGetSafemodeCaught);
    bool sceKernelGetSanitizerMallocReplaceCaught = false;
    try {
        sceKernelGetSanitizerMallocReplace();
    } catch (const std::runtime_error& error) {
        sceKernelGetSanitizerMallocReplaceCaught = (std::string(error.what()) == "sceKernelGetSanitizerMallocReplace not implemented");
    }
    Require(sceKernelGetSanitizerMallocReplaceCaught);
    bool sceKernelGetSanitizerNewReplaceCaught = false;
    try {
        sceKernelGetSanitizerNewReplace();
    } catch (const std::runtime_error& error) {
        sceKernelGetSanitizerNewReplaceCaught = (std::string(error.what()) == "sceKernelGetSanitizerNewReplace not implemented");
    }
    Require(sceKernelGetSanitizerNewReplaceCaught);
    bool sceKernelGetSocClockCaught = false;
    try {
        sceKernelGetSocClock();
    } catch (const std::runtime_error& error) {
        sceKernelGetSocClockCaught = (std::string(error.what()) == "sceKernelGetSocClock not implemented");
    }
    Require(sceKernelGetSocClockCaught);
    bool sceKernelGetSpecialIForRcmgrCaught = false;
    try {
        sceKernelGetSpecialIForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetSpecialIForRcmgrCaught = (std::string(error.what()) == "sceKernelGetSpecialIForRcmgr not implemented");
    }
    Require(sceKernelGetSpecialIForRcmgrCaught);
    bool sceKernelGetSubsysIdCaught = false;
    try {
        sceKernelGetSubsysId();
    } catch (const std::runtime_error& error) {
        sceKernelGetSubsysIdCaught = (std::string(error.what()) == "sceKernelGetSubsysId not implemented");
    }
    Require(sceKernelGetSubsysIdCaught);
    bool sceKernelGetSubsysSubIdCaught = false;
    try {
        sceKernelGetSubsysSubId();
    } catch (const std::runtime_error& error) {
        sceKernelGetSubsysSubIdCaught = (std::string(error.what()) == "sceKernelGetSubsysSubId not implemented");
    }
    Require(sceKernelGetSubsysSubIdCaught);
    bool sceKernelGetSystemLevelDebuggerModeForRcmgrCaught = false;
    try {
        sceKernelGetSystemLevelDebuggerModeForRcmgr();
    } catch (const std::runtime_error& error) {
        sceKernelGetSystemLevelDebuggerModeForRcmgrCaught = (std::string(error.what()) == "sceKernelGetSystemLevelDebuggerModeForRcmgr not implemented");
    }
    Require(sceKernelGetSystemLevelDebuggerModeForRcmgrCaught);
    bool sceKernelGetSystemSwBetaCaught = false;
    try {
        sceKernelGetSystemSwBeta();
    } catch (const std::runtime_error& error) {
        sceKernelGetSystemSwBetaCaught = (std::string(error.what()) == "sceKernelGetSystemSwBeta not implemented");
    }
    Require(sceKernelGetSystemSwBetaCaught);
    bool sceKernelGetThreadNameCaught = false;
    try {
        sceKernelGetThreadName();
    } catch (const std::runtime_error& error) {
        sceKernelGetThreadNameCaught = (std::string(error.what()) == "sceKernelGetThreadName not implemented");
    }
    Require(sceKernelGetThreadNameCaught);
    bool sceKernelGetUniversalModeCaught = false;
    try {
        sceKernelGetUniversalMode();
    } catch (const std::runtime_error& error) {
        sceKernelGetUniversalModeCaught = (std::string(error.what()) == "sceKernelGetUniversalMode not implemented");
    }
    Require(sceKernelGetUniversalModeCaught);
    bool sceKernelGetUpdVersionCaught = false;
    try {
        sceKernelGetUpdVersion();
    } catch (const std::runtime_error& error) {
        sceKernelGetUpdVersionCaught = (std::string(error.what()) == "sceKernelGetUpdVersion not implemented");
    }
    Require(sceKernelGetUpdVersionCaught);
    return 0;
}
