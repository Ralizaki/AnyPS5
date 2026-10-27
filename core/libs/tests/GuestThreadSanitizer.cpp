#include "prx/libkernel/include/Api.hpp"
#include "prx/libc/include/general/VabiMacros.hpp"
#include <cstdlib>

int main() {
    if (sceKernelIsThreadSanitizerEnabled() != 0) std::abort();
    if (sceKernelIsAddressSanitizerEnabled() != 0) std::abort();
    if (sceKernelGetSanitizerMallocReplaceExternal() == nullptr) std::abort();
    if (sceKernelGetSanitizerMallocReplaceExternal()->size != sizeof(MallocReplace)) std::abort();
    if (sceKernelGetSanitizerNewReplaceExternal() == nullptr) std::abort();
    if (sceKernelGetSanitizerNewReplaceExternal()->size != sizeof(NewReplace)) std::abort();
    return 0;
}
