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
    bool kmq_notify_nid_postfixCaught = false;
    try {
        kmq_notify_nid_postfix();
    } catch (const std::runtime_error& error) {
        kmq_notify_nid_postfixCaught = (std::string(error.what()) == "kmq_notify_nid_postfix not implemented");
    }
    Require(kmq_notify_nid_postfixCaught);
    bool kmq_open_nid_postfixCaught = false;
    try {
        kmq_open_nid_postfix();
    } catch (const std::runtime_error& error) {
        kmq_open_nid_postfixCaught = (std::string(error.what()) == "kmq_open_nid_postfix not implemented");
    }
    Require(kmq_open_nid_postfixCaught);
    bool kmq_setattr_nid_postfixCaught = false;
    try {
        kmq_setattr_nid_postfix();
    } catch (const std::runtime_error& error) {
        kmq_setattr_nid_postfixCaught = (std::string(error.what()) == "kmq_setattr_nid_postfix not implemented");
    }
    Require(kmq_setattr_nid_postfixCaught);
    bool kmq_timedreceive_nid_postfixCaught = false;
    try {
        kmq_timedreceive_nid_postfix();
    } catch (const std::runtime_error& error) {
        kmq_timedreceive_nid_postfixCaught = (std::string(error.what()) == "kmq_timedreceive_nid_postfix not implemented");
    }
    Require(kmq_timedreceive_nid_postfixCaught);
    bool kmq_timedsend_nid_postfixCaught = false;
    try {
        kmq_timedsend_nid_postfix();
    } catch (const std::runtime_error& error) {
        kmq_timedsend_nid_postfixCaught = (std::string(error.what()) == "kmq_timedsend_nid_postfix not implemented");
    }
    Require(kmq_timedsend_nid_postfixCaught);
    bool kmq_unlink_nid_postfixCaught = false;
    try {
        kmq_unlink_nid_postfix();
    } catch (const std::runtime_error& error) {
        kmq_unlink_nid_postfixCaught = (std::string(error.what()) == "kmq_unlink_nid_postfix not implemented");
    }
    Require(kmq_unlink_nid_postfixCaught);
    bool ksem_close_nid_postfixCaught = false;
    try {
        ksem_close_nid_postfix();
    } catch (const std::runtime_error& error) {
        ksem_close_nid_postfixCaught = (std::string(error.what()) == "ksem_close_nid_postfix not implemented");
    }
    Require(ksem_close_nid_postfixCaught);
    bool ksem_destroy_nid_postfixCaught = false;
    try {
        ksem_destroy_nid_postfix();
    } catch (const std::runtime_error& error) {
        ksem_destroy_nid_postfixCaught = (std::string(error.what()) == "ksem_destroy_nid_postfix not implemented");
    }
    Require(ksem_destroy_nid_postfixCaught);
    bool ksem_getvalue_nid_postfixCaught = false;
    try {
        ksem_getvalue_nid_postfix();
    } catch (const std::runtime_error& error) {
        ksem_getvalue_nid_postfixCaught = (std::string(error.what()) == "ksem_getvalue_nid_postfix not implemented");
    }
    Require(ksem_getvalue_nid_postfixCaught);
    bool ksem_init_nid_postfixCaught = false;
    try {
        ksem_init_nid_postfix();
    } catch (const std::runtime_error& error) {
        ksem_init_nid_postfixCaught = (std::string(error.what()) == "ksem_init_nid_postfix not implemented");
    }
    Require(ksem_init_nid_postfixCaught);
    bool ksem_open_nid_postfixCaught = false;
    try {
        ksem_open_nid_postfix();
    } catch (const std::runtime_error& error) {
        ksem_open_nid_postfixCaught = (std::string(error.what()) == "ksem_open_nid_postfix not implemented");
    }
    Require(ksem_open_nid_postfixCaught);
    bool ksem_post_nid_postfixCaught = false;
    try {
        ksem_post_nid_postfix();
    } catch (const std::runtime_error& error) {
        ksem_post_nid_postfixCaught = (std::string(error.what()) == "ksem_post_nid_postfix not implemented");
    }
    Require(ksem_post_nid_postfixCaught);
    bool ksem_timedwait_nid_postfixCaught = false;
    try {
        ksem_timedwait_nid_postfix();
    } catch (const std::runtime_error& error) {
        ksem_timedwait_nid_postfixCaught = (std::string(error.what()) == "ksem_timedwait_nid_postfix not implemented");
    }
    Require(ksem_timedwait_nid_postfixCaught);
    bool ksem_trywait_nid_postfixCaught = false;
    try {
        ksem_trywait_nid_postfix();
    } catch (const std::runtime_error& error) {
        ksem_trywait_nid_postfixCaught = (std::string(error.what()) == "ksem_trywait_nid_postfix not implemented");
    }
    Require(ksem_trywait_nid_postfixCaught);
    bool ksem_unlink_nid_postfixCaught = false;
    try {
        ksem_unlink_nid_postfix();
    } catch (const std::runtime_error& error) {
        ksem_unlink_nid_postfixCaught = (std::string(error.what()) == "ksem_unlink_nid_postfix not implemented");
    }
    Require(ksem_unlink_nid_postfixCaught);
    bool ksem_wait_nid_postfixCaught = false;
    try {
        ksem_wait_nid_postfix();
    } catch (const std::runtime_error& error) {
        ksem_wait_nid_postfixCaught = (std::string(error.what()) == "ksem_wait_nid_postfix not implemented");
    }
    Require(ksem_wait_nid_postfixCaught);
    bool mdbg_call_nid_postfixCaught = false;
    try {
        mdbg_call_nid_postfix();
    } catch (const std::runtime_error& error) {
        mdbg_call_nid_postfixCaught = (std::string(error.what()) == "mdbg_call_nid_postfix not implemented");
    }
    Require(mdbg_call_nid_postfixCaught);
    bool mdbg_service_nid_postfixCaught = false;
    try {
        mdbg_service_nid_postfix();
    } catch (const std::runtime_error& error) {
        mdbg_service_nid_postfixCaught = (std::string(error.what()) == "mdbg_service_nid_postfix not implemented");
    }
    Require(mdbg_service_nid_postfixCaught);
    bool mount_nid_postfixCaught = false;
    try {
        mount_nid_postfix();
    } catch (const std::runtime_error& error) {
        mount_nid_postfixCaught = (std::string(error.what()) == "mount_nid_postfix not implemented");
    }
    Require(mount_nid_postfixCaught);
    bool openintr_nid_postfixCaught = false;
    try {
        openintr_nid_postfix();
    } catch (const std::runtime_error& error) {
        openintr_nid_postfixCaught = (std::string(error.what()) == "openintr_nid_postfix not implemented");
    }
    Require(openintr_nid_postfixCaught);
    bool profil_nid_postfixCaught = false;
    try {
        profil_nid_postfix();
    } catch (const std::runtime_error& error) {
        profil_nid_postfixCaught = (std::string(error.what()) == "profil_nid_postfix not implemented");
    }
    Require(profil_nid_postfixCaught);
    return 0;
}
