#include "prx/libkernel/include/Api.hpp"
#include "prx/libc/include/Api.hpp"
#include "prx/libSceNet/include/Net.hpp"
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#else
#include <sys/socket.h>
#endif
#include <climits>
#include <stdexcept>
#include <string>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <source_location>
#include "prx/libc/include/general/VabiMacros.hpp"
#include "prx/libkernel/Socket/include/SocketPoll.hpp"

static void Require(bool condition, std::source_location location = std::source_location::current()) {
    if (!condition) {
        std::fprintf(stderr, "check failed at line %u\n", location.line());
        std::abort();
    }
}

int main() {
    Require(sceNetInit_nid_postfix() == 0);
    for (const int family : {2, 28}) {
        for (const int type : {1, 2}) {
            const int socket = sceNetSocket("buffer-validation", family, type, type == 1 ? 6 : 17);
            Require(socket >= 0);
            std::shared_ptr<void> owner;
            std::uintptr_t native = 0;
            Require(KernelFindSocketNative_nid_no_patch(socket, &owner, &native));
            for (const int option : {0x1001, 0x1002}) {
                const auto nativeBuffer = [&] {
                    int value = 0;
#ifdef _WIN32
                    int size = sizeof(value);
#else
                    socklen_t size = sizeof(value);
#endif
                    Require(::getsockopt(native, SOL_SOCKET, option == 0x1001 ? SO_SNDBUF : SO_RCVBUF,
                        reinterpret_cast<char*>(&value), &size) == 0);
                    return value;
                };
                const int initial = 32768;
                Require(sceNetSetsockopt(socket, 0xffff, option, &initial, sizeof(initial)) == 0);
                const int originalNative = nativeBuffer();
                for (const int invalid : {0, -1, -4096, INT_MIN}) {
                    Require(sceNetSetsockopt(socket, 0xffff, option, &invalid, sizeof(invalid)) == static_cast<int>(0x80410116u));
                    Require(*sceNetErrnoLoc() == 22);
                    Require(setsockopt_nid_postfix(socket, 0xffff, option, &invalid, sizeof(invalid)) == -1);
                    Require(*__error_nid_postfix() == 22);
                    int value = 0;
                    std::uint32_t size = sizeof(value);
                    Require(sceNetGetsockopt(socket, 0xffff, option, &value, &size) == 0 && value == initial);
                    Require(nativeBuffer() == originalNative);
                }
                Require(sceNetSetsockopt(socket, 0xffff, option, nullptr, sizeof(initial)) == static_cast<int>(0x80410116u));
                Require(sceNetSetsockopt(socket, 0xffff, option, &initial, 3) == static_cast<int>(0x80410116u));
                const int valid = 8192;
                Require(sceNetSetsockopt(socket, 0xffff, option, &valid, sizeof(valid)) == 0);
                int value = 0;
                std::uint32_t size = sizeof(value);
                Require(sceNetGetsockopt(socket, 0xffff, option, &value, &size) == 0 && value == valid);
            }
            Require(sceNetSocketClose(socket) == 0);
        }
    }
    const int zero = 0;
    Require(sceNetSetsockopt(-1, 0xffff, 0x1001, &zero, sizeof(zero)) == static_cast<int>(0x80410109u));
    Require(*sceNetErrnoLoc() == 9);
    bool getStatsCaught = false;
    try {
        sceNetGetStatisticsInfo(nullptr, 0);
    } catch (const std::runtime_error& error) {
        getStatsCaught = (std::string(error.what()) == "sceNetGetStatisticsInfo not implemented");
    }
    Require(getStatsCaught);
    bool getIfStatsCaught = false;
    try {
        sceNetGetInterfaceStats(nullptr, 0);
    } catch (const std::runtime_error& error) {
        getIfStatsCaught = (std::string(error.what()) == "sceNetGetInterfaceStats not implemented");
    }
    Require(getIfStatsCaught);
    bool showIfconfigCaught = false;
    try {
        sceNetShowIfconfigWithMemory(0);
    } catch (const std::runtime_error& error) {
        showIfconfigCaught = (std::string(error.what()) == "sceNetShowIfconfigWithMemory not implemented");
    }
    Require(showIfconfigCaught);
    bool showPolicyCaught = false;
    try {
        sceNetShowPolicyWithMemory(0);
    } catch (const std::runtime_error& error) {
        showPolicyCaught = (std::string(error.what()) == "sceNetShowPolicyWithMemory not implemented");
    }
    Require(showPolicyCaught);
    bool showRoute6Caught = false;
    try {
        sceNetShowRoute6WithMemory(0);
    } catch (const std::runtime_error& error) {
        showRoute6Caught = (std::string(error.what()) == "sceNetShowRoute6WithMemory not implemented");
    }
    Require(showRoute6Caught);
    bool allocRouteCaught = false;
    try {
        sceNetAllocateAllRouteInfo(0, nullptr);
    } catch (const std::runtime_error& error) {
        allocRouteCaught = (std::string(error.what()) == "sceNetAllocateAllRouteInfo not implemented");
    }
    Require(allocRouteCaught);
    bool allocRoute6Caught = false;
    try {
        sceNetAllocateAllRouteInfo6(0, nullptr);
    } catch (const std::runtime_error& error) {
        allocRoute6Caught = (std::string(error.what()) == "sceNetAllocateAllRouteInfo6 not implemented");
    }
    Require(allocRoute6Caught);
    bool freeRouteCaught = false;
    try {
        sceNetFreeAllRouteInfo(nullptr);
    } catch (const std::runtime_error& error) {
        freeRouteCaught = (std::string(error.what()) == "sceNetFreeAllRouteInfo not implemented");
    }
    Require(freeRouteCaught);
    bool getRouteCaught = false;
    try {
        sceNetGetRouteInfo(0, nullptr, 0, 0);
    } catch (const std::runtime_error& error) {
        getRouteCaught = (std::string(error.what()) == "sceNetGetRouteInfo not implemented");
    }
    Require(getRouteCaught);
    bool getArpCaught = false;
    try {
        sceNetGetArpInfo(nullptr, 0);
    } catch (const std::runtime_error& error) {
        getArpCaught = (std::string(error.what()) == "sceNetGetArpInfo not implemented");
    }
    Require(getArpCaught);
    bool getAppMemCaught = false;
    try {
        sceNetGetAppMemInfo(nullptr, 0);
    } catch (const std::runtime_error& error) {
        getAppMemCaught = (std::string(error.what()) == "sceNetGetAppMemInfo not implemented");
    }
    Require(getAppMemCaught);
    bool getSysMemCaught = false;
    try {
        sceNetGetSystemMemInfo(nullptr, 0);
    } catch (const std::runtime_error& error) {
        getSysMemCaught = (std::string(error.what()) == "sceNetGetSystemMemInfo not implemented");
    }
    Require(getSysMemCaught);
    bool getIfListCaught = false;
    try {
        sceNetGetIfList(0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        getIfListCaught = (std::string(error.what()) == "sceNetGetIfList not implemented");
    }
    Require(getIfListCaught);
    bool getIfListExCaught = false;
    try {
        sceNetGetIfListEx(0, nullptr, 0, 0);
    } catch (const std::runtime_error& error) {
        getIfListExCaught = (std::string(error.what()) == "sceNetGetIfListEx not implemented");
    }
    Require(getIfListExCaught);
    bool getIfListOnceCaught = false;
    try {
        sceNetGetIfListOnce(0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        getIfListOnceCaught = (std::string(error.what()) == "sceNetGetIfListOnce not implemented");
    }
    Require(getIfListOnceCaught);
    bool getIfnameNumListCaught = false;
    try {
        sceNetGetIfnameNumList(nullptr, 0, 0);
    } catch (const std::runtime_error& error) {
        getIfnameNumListCaught = (std::string(error.what()) == "sceNetGetIfnameNumList not implemented");
    }
    Require(getIfnameNumListCaught);
    bool getNameToIndexCaught = false;
    try {
        sceNetGetNameToIndex(0);
    } catch (const std::runtime_error& error) {
        getNameToIndexCaught = (std::string(error.what()) == "sceNetGetNameToIndex not implemented");
    }
    Require(getNameToIndexCaught);
    bool getSockoptExCaught = false;
    try {
        sceNetGetsockoptEx(0, 0, 0, nullptr, nullptr);
    } catch (const std::runtime_error& error) {
        getSockoptExCaught = (std::string(error.what()) == "sceNetGetsockoptEx not implemented");
    }
    Require(getSockoptExCaught);
    bool setSockoptExCaught = false;
    try {
        sceNetSetsockoptEx(0, 0, 0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        setSockoptExCaught = (std::string(error.what()) == "sceNetSetsockoptEx not implemented");
    }
    Require(setSockoptExCaught);
}
