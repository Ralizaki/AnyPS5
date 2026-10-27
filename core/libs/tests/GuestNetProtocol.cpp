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

    bool sceNetConfigWlanAdhocJoinCaught = false;
    try {
        sceNetConfigWlanAdhocJoin(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanAdhocJoinCaught = (std::string(error.what()) == "sceNetConfigWlanAdhocJoin not implemented");
    }
    Require(sceNetConfigWlanAdhocJoinCaught);
    bool sceNetConfigWlanAdhocLeaveCaught = false;
    try {
        sceNetConfigWlanAdhocLeave(0);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanAdhocLeaveCaught = (std::string(error.what()) == "sceNetConfigWlanAdhocLeave not implemented");
    }
    Require(sceNetConfigWlanAdhocLeaveCaught);
    bool sceNetConfigWlanAdhocPspEmuClearWakeOnWlanCaught = false;
    try {
        sceNetConfigWlanAdhocPspEmuClearWakeOnWlan(0);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanAdhocPspEmuClearWakeOnWlanCaught = (std::string(error.what()) == "sceNetConfigWlanAdhocPspEmuClearWakeOnWlan not implemented");
    }
    Require(sceNetConfigWlanAdhocPspEmuClearWakeOnWlanCaught);
    bool sceNetConfigWlanAdhocPspEmuGetWakeOnWlanInfoCaught = false;
    try {
        sceNetConfigWlanAdhocPspEmuGetWakeOnWlanInfo(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanAdhocPspEmuGetWakeOnWlanInfoCaught = (std::string(error.what()) == "sceNetConfigWlanAdhocPspEmuGetWakeOnWlanInfo not implemented");
    }
    Require(sceNetConfigWlanAdhocPspEmuGetWakeOnWlanInfoCaught);
    bool sceNetConfigWlanAdhocPspEmuSetWakeOnWlanCaught = false;
    try {
        sceNetConfigWlanAdhocPspEmuSetWakeOnWlan(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanAdhocPspEmuSetWakeOnWlanCaught = (std::string(error.what()) == "sceNetConfigWlanAdhocPspEmuSetWakeOnWlan not implemented");
    }
    Require(sceNetConfigWlanAdhocPspEmuSetWakeOnWlanCaught);
    bool sceNetConfigWlanAdhocScanJoinCaught = false;
    try {
        sceNetConfigWlanAdhocScanJoin(0, nullptr, nullptr, 0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanAdhocScanJoinCaught = (std::string(error.what()) == "sceNetConfigWlanAdhocScanJoin not implemented");
    }
    Require(sceNetConfigWlanAdhocScanJoinCaught);
    bool sceNetConfigWlanAdhocSetExtInfoElementCaught = false;
    try {
        sceNetConfigWlanAdhocSetExtInfoElement(0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanAdhocSetExtInfoElementCaught = (std::string(error.what()) == "sceNetConfigWlanAdhocSetExtInfoElement not implemented");
    }
    Require(sceNetConfigWlanAdhocSetExtInfoElementCaught);
    bool sceNetConfigWlanAdhocSetWakeOnWlanCaught = false;
    try {
        sceNetConfigWlanAdhocSetWakeOnWlan(0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanAdhocSetWakeOnWlanCaught = (std::string(error.what()) == "sceNetConfigWlanAdhocSetWakeOnWlan not implemented");
    }
    Require(sceNetConfigWlanAdhocSetWakeOnWlanCaught);
    bool sceNetConfigWlanApStartCaught = false;
    try {
        sceNetConfigWlanApStart(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanApStartCaught = (std::string(error.what()) == "sceNetConfigWlanApStart not implemented");
    }
    Require(sceNetConfigWlanApStartCaught);
    bool sceNetConfigWlanApStopCaught = false;
    try {
        sceNetConfigWlanApStop(0);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanApStopCaught = (std::string(error.what()) == "sceNetConfigWlanApStop not implemented");
    }
    Require(sceNetConfigWlanApStopCaught);
    bool sceNetConfigWlanBackgroundScanQueryCaught = false;
    try {
        sceNetConfigWlanBackgroundScanQuery(0, nullptr, 0, nullptr, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanBackgroundScanQueryCaught = (std::string(error.what()) == "sceNetConfigWlanBackgroundScanQuery not implemented");
    }
    Require(sceNetConfigWlanBackgroundScanQueryCaught);
    bool sceNetConfigWlanBackgroundScanStartCaught = false;
    try {
        sceNetConfigWlanBackgroundScanStart(0, nullptr, 0);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanBackgroundScanStartCaught = (std::string(error.what()) == "sceNetConfigWlanBackgroundScanStart not implemented");
    }
    Require(sceNetConfigWlanBackgroundScanStartCaught);
    bool sceNetConfigWlanBackgroundScanStopCaught = false;
    try {
        sceNetConfigWlanBackgroundScanStop(0);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanBackgroundScanStopCaught = (std::string(error.what()) == "sceNetConfigWlanBackgroundScanStop not implemented");
    }
    Require(sceNetConfigWlanBackgroundScanStopCaught);
    bool sceNetConfigWlanDiagGetDeviceInfoCaught = false;
    try {
        sceNetConfigWlanDiagGetDeviceInfo(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanDiagGetDeviceInfoCaught = (std::string(error.what()) == "sceNetConfigWlanDiagGetDeviceInfo not implemented");
    }
    Require(sceNetConfigWlanDiagGetDeviceInfoCaught);
    bool sceNetConfigWlanDiagSetAntennaCaught = false;
    try {
        sceNetConfigWlanDiagSetAntenna(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanDiagSetAntennaCaught = (std::string(error.what()) == "sceNetConfigWlanDiagSetAntenna not implemented");
    }
    Require(sceNetConfigWlanDiagSetAntennaCaught);
    bool sceNetConfigWlanDiagSetTxFixedRateCaught = false;
    try {
        sceNetConfigWlanDiagSetTxFixedRate(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanDiagSetTxFixedRateCaught = (std::string(error.what()) == "sceNetConfigWlanDiagSetTxFixedRate not implemented");
    }
    Require(sceNetConfigWlanDiagSetTxFixedRateCaught);
    bool sceNetConfigWlanGetDeviceConfigCaught = false;
    try {
        sceNetConfigWlanGetDeviceConfig(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanGetDeviceConfigCaught = (std::string(error.what()) == "sceNetConfigWlanGetDeviceConfig not implemented");
    }
    Require(sceNetConfigWlanGetDeviceConfigCaught);
    bool sceNetConfigWlanInfraGetRssiInfoCaught = false;
    try {
        sceNetConfigWlanInfraGetRssiInfo(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanInfraGetRssiInfoCaught = (std::string(error.what()) == "sceNetConfigWlanInfraGetRssiInfo not implemented");
    }
    Require(sceNetConfigWlanInfraGetRssiInfoCaught);
    bool sceNetConfigWlanInfraLeaveCaught = false;
    try {
        sceNetConfigWlanInfraLeave(0);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanInfraLeaveCaught = (std::string(error.what()) == "sceNetConfigWlanInfraLeave not implemented");
    }
    Require(sceNetConfigWlanInfraLeaveCaught);
    bool sceNetConfigWlanInfraScanJoinCaught = false;
    try {
        sceNetConfigWlanInfraScanJoin(0, nullptr, nullptr, 0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanInfraScanJoinCaught = (std::string(error.what()) == "sceNetConfigWlanInfraScanJoin not implemented");
    }
    Require(sceNetConfigWlanInfraScanJoinCaught);
    bool sceNetConfigWlanScanCaught = false;
    try {
        sceNetConfigWlanScan(0, nullptr, 0, nullptr, 0, nullptr, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanScanCaught = (std::string(error.what()) == "sceNetConfigWlanScan not implemented");
    }
    Require(sceNetConfigWlanScanCaught);
    bool sceNetConfigWlanSetDeviceConfigCaught = false;
    try {
        sceNetConfigWlanSetDeviceConfig(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigWlanSetDeviceConfigCaught = (std::string(error.what()) == "sceNetConfigWlanSetDeviceConfig not implemented");
    }
    Require(sceNetConfigWlanSetDeviceConfigCaught);
    bool sceNetConfigEtherGetLinkModeCaught = false;
    try {
        sceNetConfigEtherGetLinkMode(0, nullptr);
    } catch (const std::runtime_error& error) {
        sceNetConfigEtherGetLinkModeCaught = (std::string(error.what()) == "sceNetConfigEtherGetLinkMode not implemented");
    }
    Require(sceNetConfigEtherGetLinkModeCaught);
    bool sceNetConfigEtherPostPlugInOutEventCaught = false;
    try {
        sceNetConfigEtherPostPlugInOutEvent(0);
    } catch (const std::runtime_error& error) {
        sceNetConfigEtherPostPlugInOutEventCaught = (std::string(error.what()) == "sceNetConfigEtherPostPlugInOutEvent not implemented");
    }
    Require(sceNetConfigEtherPostPlugInOutEventCaught);
    bool sceNetConfigEtherSetLinkModeCaught = false;
    try {
        sceNetConfigEtherSetLinkMode(0, 0);
    } catch (const std::runtime_error& error) {
        sceNetConfigEtherSetLinkModeCaught = (std::string(error.what()) == "sceNetConfigEtherSetLinkMode not implemented");
    }
    Require(sceNetConfigEtherSetLinkModeCaught);
}
