#include "prx/libkernel/include/Api.hpp"
#include "prx/libSceDbgThreadSanitizer/include/Api.hpp"
#include <stdexcept>
#include <string>
#include "prx/libc/include/general/VabiMacros.hpp"
#include <cstdlib>

int main() {
    if (sceKernelIsThreadSanitizerEnabled() != 0) std::abort();
    bool __tsan_acquireCaught = false;
    try {
        __tsan_acquire(nullptr);
    } catch (const std::runtime_error& error) {
        __tsan_acquireCaught = (std::string(error.what()) == "__tsan_acquire not implemented");
    }
    if (!__tsan_acquireCaught) std::abort();
    bool __tsan_releaseCaught = false;
    try {
        __tsan_release(nullptr);
    } catch (const std::runtime_error& error) {
        __tsan_releaseCaught = (std::string(error.what()) == "__tsan_release not implemented");
    }
    if (!__tsan_releaseCaught) std::abort();
    return 0;
}
