#include "prx/libSceSaveData.native/include/Api.hpp"
#include "prx/libc/include/general/VabiMacros.hpp"
#include <cstdio>
#include <cstdint>
#include <stdexcept>
#include <string>

template <typename TCall>
static bool ReportsNotImplemented(const char* name, TCall call) {
    try {
        call();
    } catch (const std::runtime_error& error) {
        return std::string(error.what()) == std::string(name) + " not implemented";
    }
    return false;
}

int main() {
    if (!ReportsNotImplemented("sceSaveDataCancel", [] { sceSaveDataCancel(0); })) {
        std::fprintf(stderr, "sceSaveDataCancel did not report not implemented\n");
        return 1;
    }
    if (!ReportsNotImplemented("sceSaveDataPrepareForTransferring", [] { sceSaveDataPrepareForTransferring(nullptr, nullptr); })) {
        std::fprintf(stderr, "sceSaveDataPrepareForTransferring did not report not implemented\n");
        return 1;
    }
    return 0;
}
