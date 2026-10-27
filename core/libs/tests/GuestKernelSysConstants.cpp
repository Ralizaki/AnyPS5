#include "SceTypes.hpp"
#include "prx/libkernel_sys/libkernel_sys.hpp"
#include <cstdlib>
#include <stdexcept>
#include <string>
#include "prx/libkernel/include/Api.hpp"

namespace {

constexpr int GUEST_ENOTSUP = 45;
constexpr int SCE_KERNEL_ERROR_EPERM = static_cast<int>(0x80020001);
constexpr int SCE_KERNEL_ERROR_ENOENT = static_cast<int>(0x80020002);
constexpr int SCE_KERNEL_ERROR_ENOTSUP = static_cast<int>(0x8002002d);
constexpr int SCE_KERNEL_ERROR_ENOSYS = static_cast<int>(0x8002004e);

void Require(bool value) { if (!value) std::abort(); }

template <typename TCall>
bool ReportsNotImplemented(const char* name, TCall call) {
    try {
        call();
    } catch (const std::runtime_error& error) {
        return std::string(error.what()) == std::string(name) + " not implemented";
    }
    return false;
}

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

    Require(ReportsNotImplemented("physhm_open", [] { return physhm_open_nid_postfix(); }));
    Require(ReportsNotImplemented("physhm_unlink", [] { return physhm_unlink_nid_postfix(); }));
    Require(ReportsNotImplemented("sceKernelGetProcessAbiType", [] { return sceKernelGetProcessAbiType(); }));
    Require(ReportsNotImplemented("sceKernelPrintBacktraceWithModuleInfo", [] { return sceKernelPrintBacktraceWithModuleInfo(); }));
    Require(ReportsNotImplemented("AC1FtjqMCL0", [] { return sceKernelUnknown03(); }));
    Require(ReportsNotImplemented("0iEKNAvT600", [] { return sceKernelUnknown04(); }));
    Require(ReportsNotImplemented("2cELEBPdYQ0", [] { return sceKernelUnknown05(); }));
    Require(ReportsNotImplemented("5xYxiOtOccA", [] { return sceKernelUnknown06(); }));
    Require(ReportsNotImplemented("6W+shIH315Q", [] { return sceKernelUnknown07(); }));
    Require(ReportsNotImplemented("7ilObq815O4", [] { return sceKernelUnknown08(); }));
    Require(ReportsNotImplemented("7iq7Hfs8HBk", [] { return sceKernelUnknown09(); }));
    Require(ReportsNotImplemented("AMJZhpC+siY", [] { return sceKernelUnknown10(); }));
    Require(ReportsNotImplemented("E9XkHowt+dY", [] { return sceKernelUnknown11(); }));
    Require(ReportsNotImplemented("GADjreszOgM", [] { return sceKernelUnknown12(); }));
    Require(ReportsNotImplemented("Giyg2xGrXDU", [] { return sceKernelUnknown13(); }));
    Require(ReportsNotImplemented("KC3y21wrqzc", [] { return sceKernelUnknown14(); }));
    Require(ReportsNotImplemented("Qb8wS4GZUsw", [] { return sceKernelUnknown15(); }));
    Require(ReportsNotImplemented("aAQZSjb2fho", [] { return sceKernelUnknown16(); }));
    Require(ReportsNotImplemented("pnz21I6VjDs", [] { return sceKernelUnknown17(); }));
    Require(ReportsNotImplemented("qk043QPsrZU", [] { return sceKernelUnknown18(); }));
    Require(ReportsNotImplemented("uDGXwUKqi8s", [] { return sceKernelUnknown19(); }));
    Require(ReportsNotImplemented("__Ux86_64_setcontext", [] { return __Ux86_64_setcontext(); }));
    return 0;
}
