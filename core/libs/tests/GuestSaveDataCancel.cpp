#include "prx/libSceSaveData.native/include/Api.hpp"
#include "prx/libc/include/general/VabiMacros.hpp"
#include <cstdio>
#include <cstdint>
#include <stdexcept>
#include <string>

int main() {
    try {
        sceSaveDataCancel(0);
        std::fprintf(stderr, "sceSaveDataCancel returned instead of reporting that it is not implemented\n");
        return 1;
    } catch (const std::runtime_error& error) {
        if (std::string(error.what()) != "sceSaveDataCancel not implemented") {
            std::fprintf(stderr, "sceSaveDataCancel threw: %s\n", error.what());
            return 1;
        }
    }
    try {
        sceSaveDataPrepareForTransferring(nullptr, nullptr);
        std::fprintf(stderr, "sceSaveDataPrepareForTransferring returned instead of reporting that it is not implemented\n");
        return 1;
    } catch (const std::runtime_error& error) {
        if (std::string(error.what()) != "sceSaveDataPrepareForTransferring not implemented") {
            std::fprintf(stderr, "sceSaveDataPrepareForTransferring threw: %s\n", error.what());
            return 1;
        }
    }
    return 0;
}
