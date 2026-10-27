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
    bool sceKernelSandboxPathCaught = false;
    try {
        sceKernelSandboxPath();
    } catch (const std::runtime_error& error) {
        sceKernelSandboxPathCaught = (std::string(error.what()) == "sceKernelSandboxPath not implemented");
    }
    Require(sceKernelSandboxPathCaught);
    bool sceKernelSaveAppCaught = false;
    try {
        sceKernelSaveApp();
    } catch (const std::runtime_error& error) {
        sceKernelSaveAppCaught = (std::string(error.what()) == "sceKernelSaveApp not implemented");
    }
    Require(sceKernelSaveAppCaught);
    bool sysc_e00_nid_postfixCaught = false;
    try {
        sysc_e00_nid_postfix();
    } catch (const std::runtime_error& error) {
        sysc_e00_nid_postfixCaught = (std::string(error.what()) == "sysc_e00_nid_postfix not implemented");
    }
    Require(sysc_e00_nid_postfixCaught);
    bool sysc_m00_nid_postfixCaught = false;
    try {
        sysc_m00_nid_postfix();
    } catch (const std::runtime_error& error) {
        sysc_m00_nid_postfixCaught = (std::string(error.what()) == "sysc_m00_nid_postfix not implemented");
    }
    Require(sysc_m00_nid_postfixCaught);
    bool sysc_s00_nid_postfixCaught = false;
    try {
        sysc_s00_nid_postfix();
    } catch (const std::runtime_error& error) {
        sysc_s00_nid_postfixCaught = (std::string(error.what()) == "sysc_s00_nid_postfix not implemented");
    }
    Require(sysc_s00_nid_postfixCaught);
    bool tcgetsid_nid_postfixCaught = false;
    try {
        tcgetsid_nid_postfix();
    } catch (const std::runtime_error& error) {
        tcgetsid_nid_postfixCaught = (std::string(error.what()) == "tcgetsid_nid_postfix not implemented");
    }
    Require(tcgetsid_nid_postfixCaught);
    bool tcsetsid_nid_postfixCaught = false;
    try {
        tcsetsid_nid_postfix();
    } catch (const std::runtime_error& error) {
        tcsetsid_nid_postfixCaught = (std::string(error.what()) == "tcsetsid_nid_postfix not implemented");
    }
    Require(tcsetsid_nid_postfixCaught);
    bool unmount_nid_postfixCaught = false;
    try {
        unmount_nid_postfix();
    } catch (const std::runtime_error& error) {
        unmount_nid_postfixCaught = (std::string(error.what()) == "unmount_nid_postfix not implemented");
    }
    Require(unmount_nid_postfixCaught);
    bool utrace_nid_postfixCaught = false;
    try {
        utrace_nid_postfix();
    } catch (const std::runtime_error& error) {
        utrace_nid_postfixCaught = (std::string(error.what()) == "utrace_nid_postfix not implemented");
    }
    Require(utrace_nid_postfixCaught);
    bool vfork_nid_postfixCaught = false;
    try {
        vfork_nid_postfix();
    } catch (const std::runtime_error& error) {
        vfork_nid_postfixCaught = (std::string(error.what()) == "vfork_nid_postfix not implemented");
    }
    Require(vfork_nid_postfixCaught);
    bool wait3_nid_postfixCaught = false;
    try {
        wait3_nid_postfix();
    } catch (const std::runtime_error& error) {
        wait3_nid_postfixCaught = (std::string(error.what()) == "wait3_nid_postfix not implemented");
    }
    Require(wait3_nid_postfixCaught);
    bool wait4_nid_postfixCaught = false;
    try {
        wait4_nid_postfix();
    } catch (const std::runtime_error& error) {
        wait4_nid_postfixCaught = (std::string(error.what()) == "wait4_nid_postfix not implemented");
    }
    Require(wait4_nid_postfixCaught);
    return 0;
}
