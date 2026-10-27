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
    bool sceKernelYieldCpumodeCaught = false;
    try {
        sceKernelYieldCpumode();
    } catch (const std::runtime_error& error) {
        sceKernelYieldCpumodeCaught = (std::string(error.what()) == "sceKernelYieldCpumode not implemented");
    }
    Require(sceKernelYieldCpumodeCaught);
    bool sceLibcMspaceCreateForMonoMutexCaught = false;
    try {
        sceLibcMspaceCreateForMonoMutex();
    } catch (const std::runtime_error& error) {
        sceLibcMspaceCreateForMonoMutexCaught = (std::string(error.what()) == "sceLibcMspaceCreateForMonoMutex not implemented");
    }
    Require(sceLibcMspaceCreateForMonoMutexCaught);
    bool scePthreadMutexGetprioceilingCaught = false;
    try {
        scePthreadMutexGetprioceiling();
    } catch (const std::runtime_error& error) {
        scePthreadMutexGetprioceilingCaught = (std::string(error.what()) == "scePthreadMutexGetprioceiling not implemented");
    }
    Require(scePthreadMutexGetprioceilingCaught);
    bool scePthreadMutexInitForInternalLibcCaught = false;
    try {
        scePthreadMutexInitForInternalLibc();
    } catch (const std::runtime_error& error) {
        scePthreadMutexInitForInternalLibcCaught = (std::string(error.what()) == "scePthreadMutexInitForInternalLibc not implemented");
    }
    Require(scePthreadMutexInitForInternalLibcCaught);
    bool scePthreadMutexIsownedCaught = false;
    try {
        scePthreadMutexIsowned();
    } catch (const std::runtime_error& error) {
        scePthreadMutexIsownedCaught = (std::string(error.what()) == "scePthreadMutexIsowned not implemented");
    }
    Require(scePthreadMutexIsownedCaught);
    bool scePthreadMutexSetprioceilingCaught = false;
    try {
        scePthreadMutexSetprioceiling();
    } catch (const std::runtime_error& error) {
        scePthreadMutexSetprioceilingCaught = (std::string(error.what()) == "scePthreadMutexSetprioceiling not implemented");
    }
    Require(scePthreadMutexSetprioceilingCaught);
    bool scePthreadMutexattrGetgenCaught = false;
    try {
        scePthreadMutexattrGetgen();
    } catch (const std::runtime_error& error) {
        scePthreadMutexattrGetgenCaught = (std::string(error.what()) == "scePthreadMutexattrGetgen not implemented");
    }
    Require(scePthreadMutexattrGetgenCaught);
    bool scePthreadMutexattrInitForInternalLibcCaught = false;
    try {
        scePthreadMutexattrInitForInternalLibc();
    } catch (const std::runtime_error& error) {
        scePthreadMutexattrInitForInternalLibcCaught = (std::string(error.what()) == "scePthreadMutexattrInitForInternalLibc not implemented");
    }
    Require(scePthreadMutexattrInitForInternalLibcCaught);
    bool scePthreadMutexattrSetgenCaught = false;
    try {
        scePthreadMutexattrSetgen();
    } catch (const std::runtime_error& error) {
        scePthreadMutexattrSetgenCaught = (std::string(error.what()) == "scePthreadMutexattrSetgen not implemented");
    }
    Require(scePthreadMutexattrSetgenCaught);
    bool scePthreadSetBesteffortCaught = false;
    try {
        scePthreadSetBesteffort();
    } catch (const std::runtime_error& error) {
        scePthreadSetBesteffortCaught = (std::string(error.what()) == "scePthreadSetBesteffort not implemented");
    }
    Require(scePthreadSetBesteffortCaught);
    bool scePthreadSingleCaught = false;
    try {
        scePthreadSingle();
    } catch (const std::runtime_error& error) {
        scePthreadSingleCaught = (std::string(error.what()) == "scePthreadSingle not implemented");
    }
    Require(scePthreadSingleCaught);
    bool scePthreadSuspendCaught = false;
    try {
        scePthreadSuspend();
    } catch (const std::runtime_error& error) {
        scePthreadSuspendCaught = (std::string(error.what()) == "scePthreadSuspend not implemented");
    }
    Require(scePthreadSuspendCaught);
    bool scePthreadSuspendAllCaught = false;
    try {
        scePthreadSuspendAll();
    } catch (const std::runtime_error& error) {
        scePthreadSuspendAllCaught = (std::string(error.what()) == "scePthreadSuspendAll not implemented");
    }
    Require(scePthreadSuspendAllCaught);
    bool scePthreadTimedjoinCaught = false;
    try {
        scePthreadTimedjoin();
    } catch (const std::runtime_error& error) {
        scePthreadTimedjoinCaught = (std::string(error.what()) == "scePthreadTimedjoin not implemented");
    }
    Require(scePthreadTimedjoinCaught);
    bool sched_getparam_nid_postfixCaught = false;
    try {
        sched_getparam_nid_postfix();
    } catch (const std::runtime_error& error) {
        sched_getparam_nid_postfixCaught = (std::string(error.what()) == "sched_getparam_nid_postfix not implemented");
    }
    Require(sched_getparam_nid_postfixCaught);
    bool sched_getscheduler_nid_postfixCaught = false;
    try {
        sched_getscheduler_nid_postfix();
    } catch (const std::runtime_error& error) {
        sched_getscheduler_nid_postfixCaught = (std::string(error.what()) == "sched_getscheduler_nid_postfix not implemented");
    }
    Require(sched_getscheduler_nid_postfixCaught);
    bool sched_setparam_nid_postfixCaught = false;
    try {
        sched_setparam_nid_postfix();
    } catch (const std::runtime_error& error) {
        sched_setparam_nid_postfixCaught = (std::string(error.what()) == "sched_setparam_nid_postfix not implemented");
    }
    Require(sched_setparam_nid_postfixCaught);
    bool sched_setscheduler_nid_postfixCaught = false;
    try {
        sched_setscheduler_nid_postfix();
    } catch (const std::runtime_error& error) {
        sched_setscheduler_nid_postfixCaught = (std::string(error.what()) == "sched_setscheduler_nid_postfix not implemented");
    }
    Require(sched_setscheduler_nid_postfixCaught);
    bool sem_setname_nid_postfixCaught = false;
    try {
        sem_setname_nid_postfix();
    } catch (const std::runtime_error& error) {
        sem_setname_nid_postfixCaught = (std::string(error.what()) == "sem_setname_nid_postfix not implemented");
    }
    Require(sem_setname_nid_postfixCaught);
    bool set_phys_fmem_limit_nid_postfixCaught = false;
    try {
        set_phys_fmem_limit_nid_postfix();
    } catch (const std::runtime_error& error) {
        set_phys_fmem_limit_nid_postfixCaught = (std::string(error.what()) == "set_phys_fmem_limit_nid_postfix not implemented");
    }
    Require(set_phys_fmem_limit_nid_postfixCaught);
    bool sigqueue_nid_postfixCaught = false;
    try {
        sigqueue_nid_postfix();
    } catch (const std::runtime_error& error) {
        sigqueue_nid_postfixCaught = (std::string(error.what()) == "sigqueue_nid_postfix not implemented");
    }
    Require(sigqueue_nid_postfixCaught);
    bool sigreturn_nid_postfixCaught = false;
    try {
        sigreturn_nid_postfix();
    } catch (const std::runtime_error& error) {
        sigreturn_nid_postfixCaught = (std::string(error.what()) == "sigreturn_nid_postfix not implemented");
    }
    Require(sigreturn_nid_postfixCaught);
    bool statfs_nid_postfixCaught = false;
    try {
        statfs_nid_postfix();
    } catch (const std::runtime_error& error) {
        statfs_nid_postfixCaught = (std::string(error.what()) == "statfs_nid_postfix not implemented");
    }
    Require(statfs_nid_postfixCaught);
    bool swapon_nid_postfixCaught = false;
    try {
        swapon_nid_postfix();
    } catch (const std::runtime_error& error) {
        swapon_nid_postfixCaught = (std::string(error.what()) == "swapon_nid_postfix not implemented");
    }
    Require(swapon_nid_postfixCaught);
    bool symlinkat_nid_postfixCaught = false;
    try {
        symlinkat_nid_postfix();
    } catch (const std::runtime_error& error) {
        symlinkat_nid_postfixCaught = (std::string(error.what()) == "symlinkat_nid_postfix not implemented");
    }
    Require(symlinkat_nid_postfixCaught);
    return 0;
}
