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
    bool get_module_info_list_nid_postfixCaught = false;
    try {
        get_module_info_list_nid_postfix();
    } catch (const std::runtime_error& error) {
        get_module_info_list_nid_postfixCaught = (std::string(error.what()) == "get_module_info_list_nid_postfix not implemented");
    }
    Require(get_module_info_list_nid_postfixCaught);
    bool get_page_table_stats_nid_postfixCaught = false;
    try {
        get_page_table_stats_nid_postfix();
    } catch (const std::runtime_error& error) {
        get_page_table_stats_nid_postfixCaught = (std::string(error.what()) == "get_page_table_stats_nid_postfix not implemented");
    }
    Require(get_page_table_stats_nid_postfixCaught);
    bool get_sdk_compiled_version_nid_postfixCaught = false;
    try {
        get_sdk_compiled_version_nid_postfix();
    } catch (const std::runtime_error& error) {
        get_sdk_compiled_version_nid_postfixCaught = (std::string(error.what()) == "get_sdk_compiled_version_nid_postfix not implemented");
    }
    Require(get_sdk_compiled_version_nid_postfixCaught);
    bool get_self_auth_info_nid_postfixCaught = false;
    try {
        get_self_auth_info_nid_postfix();
    } catch (const std::runtime_error& error) {
        get_self_auth_info_nid_postfixCaught = (std::string(error.what()) == "get_self_auth_info_nid_postfix not implemented");
    }
    Require(get_self_auth_info_nid_postfixCaught);
    bool get_vm_map_timestamp_nid_postfixCaught = false;
    try {
        get_vm_map_timestamp_nid_postfix();
    } catch (const std::runtime_error& error) {
        get_vm_map_timestamp_nid_postfixCaught = (std::string(error.what()) == "get_vm_map_timestamp_nid_postfix not implemented");
    }
    Require(get_vm_map_timestamp_nid_postfixCaught);
    bool getfsstat_nid_postfixCaught = false;
    try {
        getfsstat_nid_postfix();
    } catch (const std::runtime_error& error) {
        getfsstat_nid_postfixCaught = (std::string(error.what()) == "getfsstat_nid_postfix not implemented");
    }
    Require(getfsstat_nid_postfixCaught);
    bool ipmimgr_call_nid_postfixCaught = false;
    try {
        ipmimgr_call_nid_postfix();
    } catch (const std::runtime_error& error) {
        ipmimgr_call_nid_postfixCaught = (std::string(error.what()) == "ipmimgr_call_nid_postfix not implemented");
    }
    Require(ipmimgr_call_nid_postfixCaught);
    bool is_in_sandbox_nid_postfixCaught = false;
    try {
        is_in_sandbox_nid_postfix();
    } catch (const std::runtime_error& error) {
        is_in_sandbox_nid_postfixCaught = (std::string(error.what()) == "is_in_sandbox_nid_postfix not implemented");
    }
    Require(is_in_sandbox_nid_postfixCaught);
    bool kenv_nid_postfixCaught = false;
    try {
        kenv_nid_postfix();
    } catch (const std::runtime_error& error) {
        kenv_nid_postfixCaught = (std::string(error.what()) == "kenv_nid_postfix not implemented");
    }
    Require(kenv_nid_postfixCaught);
    bool kldload_nid_postfixCaught = false;
    try {
        kldload_nid_postfix();
    } catch (const std::runtime_error& error) {
        kldload_nid_postfixCaught = (std::string(error.what()) == "kldload_nid_postfix not implemented");
    }
    Require(kldload_nid_postfixCaught);
    bool kldstat_nid_postfixCaught = false;
    try {
        kldstat_nid_postfix();
    } catch (const std::runtime_error& error) {
        kldstat_nid_postfixCaught = (std::string(error.what()) == "kldstat_nid_postfix not implemented");
    }
    Require(kldstat_nid_postfixCaught);
    bool kldsym_nid_postfixCaught = false;
    try {
        kldsym_nid_postfix();
    } catch (const std::runtime_error& error) {
        kldsym_nid_postfixCaught = (std::string(error.what()) == "kldsym_nid_postfix not implemented");
    }
    Require(kldsym_nid_postfixCaught);
    bool ktrace_nid_postfixCaught = false;
    try {
        ktrace_nid_postfix();
    } catch (const std::runtime_error& error) {
        ktrace_nid_postfixCaught = (std::string(error.what()) == "ktrace_nid_postfix not implemented");
    }
    Require(ktrace_nid_postfixCaught);
    bool lchflags_nid_postfixCaught = false;
    try {
        lchflags_nid_postfix();
    } catch (const std::runtime_error& error) {
        lchflags_nid_postfixCaught = (std::string(error.what()) == "lchflags_nid_postfix not implemented");
    }
    Require(lchflags_nid_postfixCaught);
    return 0;
}
