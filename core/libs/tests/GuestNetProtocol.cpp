#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <string>
#include <source_location>
#include "prx/libSceNet/libSceNet.hpp"


static void Require(bool condition, std::source_location where = std::source_location::current()) {
    if (!condition) {
        std::fprintf(stderr, "check failed at line %u\n", where.line());
        std::abort();
    }
}

static void CheckProtocol(int socket, int expected) {
    for (const std::uint32_t capacity : {0u, 1u, 3u, 4u, 8u}) {
        std::array<std::uint8_t, 8> bytes;
        bytes.fill(0xa5);
        auto size = capacity;
        Require(sceNetGetsockopt(socket, 0xffff, 0x1016, bytes.data(), &size) == 0);
        Require(size == std::min(capacity, 4u));
        Require(std::memcmp(bytes.data(), &expected, size) == 0);
        Require(std::all_of(bytes.begin() + size, bytes.end(), [](auto value) { return value == 0xa5; }));
    }
}

int main() {
    Require(sceNetInit_nid_postfix() == 0);
    for (const int family : {2, 28}) {
        for (const int type : {1, 2}) {
            const int expected = type == 1 ? 6 : 17;
            for (const int protocol : {0, expected}) {
                const int socket = sceNetSocket("protocol", family, type, protocol);
                Require(socket >= 0);
                CheckProtocol(socket, expected);
                std::uint32_t size = 4;
                int value = 99;
                Require(sceNetGetsockopt(socket, 0xffff, 0x1016, nullptr, &size) < 0 && *sceNetErrnoLoc() == 22);
                Require(sceNetGetsockopt(socket, 0xffff, 0x1016, &value, nullptr) < 0 && *sceNetErrnoLoc() == 22);
                Require(value == 99 && size == 4);
                Require(sceNetSetsockopt(socket, 0xffff, 0x1016, &value, sizeof(value)) < 0);
                CheckProtocol(socket, expected);
                Require(sceNetSocketClose(socket) == 0);
                Require(sceNetGetsockopt(socket, 0xffff, 0x1016, &value, &size) < 0 && *sceNetErrnoLoc() == 9);
                Require(value == 99 && size == 4);
            }
        }
        const int listener = sceNetSocket("protocol-listener", family, 1, 0);
        const int client = sceNetSocket("protocol-client", family, 1, 6);
        Require(listener >= 0 && client >= 0);
        std::array<std::uint8_t, 28> address{};
        std::uint32_t size = family == 2 ? 16 : 28;
        address[0] = size;
        address[1] = family;
        if (family == 2) { address[4] = 127; address[7] = 1; }
        else address[23] = 1;
        Require(sceNetBind_nid_postfix(listener, address.data(), size) == 0);
        Require(sceNetListen(listener, 1) == 0);
        CheckProtocol(listener, 6);
        Require(sceNetGetsockname(listener, address.data(), &size) == 0);
        Require(sceNetConnect(client, address.data(), size) == 0);
        const int accepted = sceNetAccept(listener, nullptr, nullptr);
        Require(accepted >= 0);
        CheckProtocol(accepted, 6);
        CheckProtocol(client, 6);
        for (const int socket : {accepted, client, listener}) Require(sceNetSocketClose(socket) == 0);
    }
    bool sceNetDhcpGetInfoExCaught = false;
    try {
        sceNetDhcpGetInfoEx(0, 0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        sceNetDhcpGetInfoExCaught = (std::string(error.what()) == "sceNetDhcpGetInfoEx not implemented");
    }
    Require(sceNetDhcpGetInfoExCaught);
    bool sceNetDhcpStartCaught = false;
    try {
        sceNetDhcpStart(0, nullptr, nullptr, 0, 0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetDhcpStartCaught = (std::string(error.what()) == "sceNetDhcpStart not implemented");
    }
    Require(sceNetDhcpStartCaught);
    bool sceNetDhcpStopCaught = false;
    try {
        sceNetDhcpStop(0);
    } catch (const std::runtime_error& error) {
        sceNetDhcpStopCaught = (std::string(error.what()) == "sceNetDhcpStop not implemented");
    }
    Require(sceNetDhcpStopCaught);
    bool sceNetConfigAddIfaddr6Caught = false;
    try {
        sceNetConfigAddIfaddr6(0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        sceNetConfigAddIfaddr6Caught = (std::string(error.what()) == "sceNetConfigAddIfaddr6 not implemented");
    }
    Require(sceNetConfigAddIfaddr6Caught);
    bool sceNetConfigDelIfaddr6Caught = false;
    try {
        sceNetConfigDelIfaddr6(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigDelIfaddr6Caught = (std::string(error.what()) == "sceNetConfigDelIfaddr6 not implemented");
    }
    Require(sceNetConfigDelIfaddr6Caught);
    bool sceNetConfigDelDefaultRoute6Caught = false;
    try {
        sceNetConfigDelDefaultRoute6();
    } catch (const std::runtime_error& error) {
        sceNetConfigDelDefaultRoute6Caught = (std::string(error.what()) == "sceNetConfigDelDefaultRoute6 not implemented");
    }
    Require(sceNetConfigDelDefaultRoute6Caught);
    bool sceNetConfigSetIfaddr6Caught = false;
    try {
        sceNetConfigSetIfaddr6(0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        sceNetConfigSetIfaddr6Caught = (std::string(error.what()) == "sceNetConfigSetIfaddr6 not implemented");
    }
    Require(sceNetConfigSetIfaddr6Caught);
    bool sceNetConfigSetIfaddr6WithFlagsCaught = false;
    try {
        sceNetConfigSetIfaddr6WithFlags(0, nullptr, 0, 0);
    } catch (const std::runtime_error& error) {
        sceNetConfigSetIfaddr6WithFlagsCaught = (std::string(error.what()) == "sceNetConfigSetIfaddr6WithFlags not implemented");
    }
    Require(sceNetConfigSetIfaddr6WithFlagsCaught);
    bool sceNetConfigSetDefaultRoute6Caught = false;
    try {
        sceNetConfigSetDefaultRoute6(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigSetDefaultRoute6Caught = (std::string(error.what()) == "sceNetConfigSetDefaultRoute6 not implemented");
    }
    Require(sceNetConfigSetDefaultRoute6Caught);
    bool sceNetConfigGetIfaddr6Caught = false;
    try {
        sceNetConfigGetIfaddr6(0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        sceNetConfigGetIfaddr6Caught = (std::string(error.what()) == "sceNetConfigGetIfaddr6 not implemented");
    }
    Require(sceNetConfigGetIfaddr6Caught);
    bool sceNetConfigGetDefaultRoute6Caught = false;
    try {
        sceNetConfigGetDefaultRoute6(nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigGetDefaultRoute6Caught = (std::string(error.what()) == "sceNetConfigGetDefaultRoute6 not implemented");
    }
    Require(sceNetConfigGetDefaultRoute6Caught);
    bool sceNetConfigDelRoute6Caught = false;
    try {
        sceNetConfigDelRoute6(nullptr, 0);
    } catch (const std::runtime_error& error) {
        sceNetConfigDelRoute6Caught = (std::string(error.what()) == "sceNetConfigDelRoute6 not implemented");
    }
    Require(sceNetConfigDelRoute6Caught);
    bool sceNetConfigAddRoute6Caught = false;
    try {
        sceNetConfigAddRoute6(nullptr, nullptr, 0);
    } catch (const std::runtime_error& error) {
        sceNetConfigAddRoute6Caught = (std::string(error.what()) == "sceNetConfigAddRoute6 not implemented");
    }
    Require(sceNetConfigAddRoute6Caught);
    bool sceNetAddrConfig6StartCaught = false;
    try {
        sceNetAddrConfig6Start(0, nullptr, nullptr, 0, 0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetAddrConfig6StartCaught = (std::string(error.what()) == "sceNetAddrConfig6Start not implemented");
    }
    Require(sceNetAddrConfig6StartCaught);
    bool sceNetAddrConfig6StopCaught = false;
    try {
        sceNetAddrConfig6Stop(0);
    } catch (const std::runtime_error& error) {
        sceNetAddrConfig6StopCaught = (std::string(error.what()) == "sceNetAddrConfig6Stop not implemented");
    }
    Require(sceNetAddrConfig6StopCaught);
    bool sceNetAddrConfig6GetInfoCaught = false;
    try {
        sceNetAddrConfig6GetInfo(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetAddrConfig6GetInfoCaught = (std::string(error.what()) == "sceNetAddrConfig6GetInfo not implemented");
    }
    Require(sceNetAddrConfig6GetInfoCaught);
    bool sceNetInfoDumpStartCaught = false;
    try {
        sceNetInfoDumpStart(0, 0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetInfoDumpStartCaught = (std::string(error.what()) == "sceNetInfoDumpStart not implemented");
    }
    Require(sceNetInfoDumpStartCaught);
    bool sceNetInfoDumpStopCaught = false;
    try {
        sceNetInfoDumpStop();
    } catch (const std::runtime_error& error) {
        sceNetInfoDumpStopCaught = (std::string(error.what()) == "sceNetInfoDumpStop not implemented");
    }
    Require(sceNetInfoDumpStopCaught);
    bool sceNetDhcpdStartCaught = false;
    try {
        sceNetDhcpdStart(0, nullptr, nullptr, 0, 0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetDhcpdStartCaught = (std::string(error.what()) == "sceNetDhcpdStart not implemented");
    }
    Require(sceNetDhcpdStartCaught);
    bool sceNetDhcpdStopCaught = false;
    try {
        sceNetDhcpdStop(0);
    } catch (const std::runtime_error& error) {
        sceNetDhcpdStopCaught = (std::string(error.what()) == "sceNetDhcpdStop not implemented");
    }
    Require(sceNetDhcpdStopCaught);
    bool sceNetDuplicateIpStartCaught = false;
    try {
        sceNetDuplicateIpStart(0, nullptr, nullptr, 0, 0);
    } catch (const std::runtime_error& error) {
        sceNetDuplicateIpStartCaught = (std::string(error.what()) == "sceNetDuplicateIpStart not implemented");
    }
    Require(sceNetDuplicateIpStartCaught);
    bool sceNetDuplicateIpStopCaught = false;
    try {
        sceNetDuplicateIpStop(0);
    } catch (const std::runtime_error& error) {
        sceNetDuplicateIpStopCaught = (std::string(error.what()) == "sceNetDuplicateIpStop not implemented");
    }
    Require(sceNetDuplicateIpStopCaught);
    bool sceNetConfigWlanAdhocClearWakeOnWlanCaught = false;
    try {
        sceNetConfigWlanAdhocClearWakeOnWlan(0);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanAdhocClearWakeOnWlanCaught = (std::string(error.what()) == "sceNetConfigWlanAdhocClearWakeOnWlan not implemented");
    }
    Require(sceNetConfigWlanAdhocClearWakeOnWlanCaught);
    bool sceNetConfigWlanAdhocCreateCaught = false;
    try {
        sceNetConfigWlanAdhocCreate(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanAdhocCreateCaught = (std::string(error.what()) == "sceNetConfigWlanAdhocCreate not implemented");
    }
    Require(sceNetConfigWlanAdhocCreateCaught);
    bool sceNetConfigWlanAdhocGetWakeOnWlanInfoCaught = false;
    try {
        sceNetConfigWlanAdhocGetWakeOnWlanInfo(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanAdhocGetWakeOnWlanInfoCaught = (std::string(error.what()) == "sceNetConfigWlanAdhocGetWakeOnWlanInfo not implemented");
    }
    Require(sceNetConfigWlanAdhocGetWakeOnWlanInfoCaught);
}
