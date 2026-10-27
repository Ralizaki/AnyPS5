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
    bool pthread_attr_getaffinity_np_nid_postfixCaught = false;
    try {
        pthread_attr_getaffinity_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_attr_getaffinity_np_nid_postfixCaught = (std::string(error.what()) == "pthread_attr_getaffinity_np_nid_postfix not implemented");
    }
    Require(pthread_attr_getaffinity_np_nid_postfixCaught);
    bool pthread_attr_getsolosched_np_nid_postfixCaught = false;
    try {
        pthread_attr_getsolosched_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_attr_getsolosched_np_nid_postfixCaught = (std::string(error.what()) == "pthread_attr_getsolosched_np_nid_postfix not implemented");
    }
    Require(pthread_attr_getsolosched_np_nid_postfixCaught);
    bool pthread_attr_setaffinity_np_nid_postfixCaught = false;
    try {
        pthread_attr_setaffinity_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_attr_setaffinity_np_nid_postfixCaught = (std::string(error.what()) == "pthread_attr_setaffinity_np_nid_postfix not implemented");
    }
    Require(pthread_attr_setaffinity_np_nid_postfixCaught);
    bool pthread_attr_setstackaddr_nid_postfixCaught = false;
    try {
        pthread_attr_setstackaddr_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_attr_setstackaddr_nid_postfixCaught = (std::string(error.what()) == "pthread_attr_setstackaddr_nid_postfix not implemented");
    }
    Require(pthread_attr_setstackaddr_nid_postfixCaught);
    bool pthread_get_specificarray_np_nid_postfixCaught = false;
    try {
        pthread_get_specificarray_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_get_specificarray_np_nid_postfixCaught = (std::string(error.what()) == "pthread_get_specificarray_np_nid_postfix not implemented");
    }
    Require(pthread_get_specificarray_np_nid_postfixCaught);
    bool pthread_get_user_context_np_nid_postfixCaught = false;
    try {
        pthread_get_user_context_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_get_user_context_np_nid_postfixCaught = (std::string(error.what()) == "pthread_get_user_context_np_nid_postfix not implemented");
    }
    Require(pthread_get_user_context_np_nid_postfixCaught);
    bool pthread_getstack_np_nid_postfixCaught = false;
    try {
        pthread_getstack_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_getstack_np_nid_postfixCaught = (std::string(error.what()) == "pthread_getstack_np_nid_postfix not implemented");
    }
    Require(pthread_getstack_np_nid_postfixCaught);
    bool pthread_mutex_getprioceiling_nid_postfixCaught = false;
    try {
        pthread_mutex_getprioceiling_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_mutex_getprioceiling_nid_postfixCaught = (std::string(error.what()) == "pthread_mutex_getprioceiling_nid_postfix not implemented");
    }
    Require(pthread_mutex_getprioceiling_nid_postfixCaught);
    bool pthread_mutex_init_for_mono_nid_postfixCaught = false;
    try {
        pthread_mutex_init_for_mono_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_mutex_init_for_mono_nid_postfixCaught = (std::string(error.what()) == "pthread_mutex_init_for_mono_nid_postfix not implemented");
    }
    Require(pthread_mutex_init_for_mono_nid_postfixCaught);
    bool pthread_mutex_setprioceiling_nid_postfixCaught = false;
    try {
        pthread_mutex_setprioceiling_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_mutex_setprioceiling_nid_postfixCaught = (std::string(error.what()) == "pthread_mutex_setprioceiling_nid_postfix not implemented");
    }
    Require(pthread_mutex_setprioceiling_nid_postfixCaught);
    bool pthread_mutexattr_getgen_np_nid_postfixCaught = false;
    try {
        pthread_mutexattr_getgen_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_mutexattr_getgen_np_nid_postfixCaught = (std::string(error.what()) == "pthread_mutexattr_getgen_np_nid_postfix not implemented");
    }
    Require(pthread_mutexattr_getgen_np_nid_postfixCaught);
    bool pthread_mutexattr_setgen_np_nid_postfixCaught = false;
    try {
        pthread_mutexattr_setgen_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_mutexattr_setgen_np_nid_postfixCaught = (std::string(error.what()) == "pthread_mutexattr_setgen_np_nid_postfix not implemented");
    }
    Require(pthread_mutexattr_setgen_np_nid_postfixCaught);
    bool pthread_resume_user_context_np_nid_postfixCaught = false;
    try {
        pthread_resume_user_context_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_resume_user_context_np_nid_postfixCaught = (std::string(error.what()) == "pthread_resume_user_context_np_nid_postfix not implemented");
    }
    Require(pthread_resume_user_context_np_nid_postfixCaught);
    bool pthread_set_user_context_np_nid_postfixCaught = false;
    try {
        pthread_set_user_context_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_set_user_context_np_nid_postfixCaught = (std::string(error.what()) == "pthread_set_user_context_np_nid_postfix not implemented");
    }
    Require(pthread_set_user_context_np_nid_postfixCaught);
    bool pthread_single_np_nid_postfixCaught = false;
    try {
        pthread_single_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_single_np_nid_postfixCaught = (std::string(error.what()) == "pthread_single_np_nid_postfix not implemented");
    }
    Require(pthread_single_np_nid_postfixCaught);
    bool pthread_suspend_all_np_nid_postfixCaught = false;
    try {
        pthread_suspend_all_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_suspend_all_np_nid_postfixCaught = (std::string(error.what()) == "pthread_suspend_all_np_nid_postfix not implemented");
    }
    Require(pthread_suspend_all_np_nid_postfixCaught);
    bool pthread_suspend_np_nid_postfixCaught = false;
    try {
        pthread_suspend_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_suspend_np_nid_postfixCaught = (std::string(error.what()) == "pthread_suspend_np_nid_postfix not implemented");
    }
    Require(pthread_suspend_np_nid_postfixCaught);
    bool pthread_suspend_user_context_np_nid_postfixCaught = false;
    try {
        pthread_suspend_user_context_np_nid_postfix();
    } catch (const std::runtime_error& error) {
        pthread_suspend_user_context_np_nid_postfixCaught = (std::string(error.what()) == "pthread_suspend_user_context_np_nid_postfix not implemented");
    }
    Require(pthread_suspend_user_context_np_nid_postfixCaught);
    bool ptrace_nid_postfixCaught = false;
    try {
        ptrace_nid_postfix();
    } catch (const std::runtime_error& error) {
        ptrace_nid_postfixCaught = (std::string(error.what()) == "ptrace_nid_postfix not implemented");
    }
    Require(ptrace_nid_postfixCaught);
    bool reboot_nid_postfixCaught = false;
    try {
        reboot_nid_postfix();
    } catch (const std::runtime_error& error) {
        reboot_nid_postfixCaught = (std::string(error.what()) == "reboot_nid_postfix not implemented");
    }
    Require(reboot_nid_postfixCaught);
    bool revoke_nid_postfixCaught = false;
    try {
        revoke_nid_postfix();
    } catch (const std::runtime_error& error) {
        revoke_nid_postfixCaught = (std::string(error.what()) == "revoke_nid_postfix not implemented");
    }
    Require(revoke_nid_postfixCaught);
    bool rfork_thread_nid_postfixCaught = false;
    try {
        rfork_thread_nid_postfix();
    } catch (const std::runtime_error& error) {
        rfork_thread_nid_postfixCaught = (std::string(error.what()) == "rfork_thread_nid_postfix not implemented");
    }
    Require(rfork_thread_nid_postfixCaught);
    bool rtld_printf_nid_postfixCaught = false;
    try {
        rtld_printf_nid_postfix();
    } catch (const std::runtime_error& error) {
        rtld_printf_nid_postfixCaught = (std::string(error.what()) == "rtld_printf_nid_postfix not implemented");
    }
    Require(rtld_printf_nid_postfixCaught);
    return 0;
}
