#include "prx/libSceSaveData/include/Api.hpp"
#include "SceTypes.hpp"
#include "prx/libc/include/general/VabiMacros.hpp"

#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

extern "C" {

#ifndef SAVEDATA_NATIVE_BACKEND

#endif
}

static void Check(bool value, int line) {
    if (!value) {
        std::fprintf(stderr, "Save-data replacement check failed at line %d\n", line);
        std::abort();
    }
}
#define Require(value) Check((value), __LINE__)

#ifndef SAVEDATA_NATIVE_BACKEND
template <typename TCall>
static bool ReportsNotImplemented(const char* name, TCall call) {
    try {
        call();
    } catch (const std::runtime_error& error) {
        return std::string(error.what()) == std::string(name) + " not implemented";
    }
    return false;
}
#endif

int main() {
    const auto originalDirectory = std::filesystem::current_path();
    const auto root = std::filesystem::temp_directory_path() /
        ("anyps5-savedata-replacement-" +
         std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
    Require(std::filesystem::create_directory(root));
    std::filesystem::current_path(root);

    constexpr std::int32_t userId = 7531;
#ifdef SAVEDATA_NATIVE_BACKEND
    const auto savePath = std::filesystem::path("_sd_mem") / ("u" + std::to_string(userId)) / "slot0.bin";
#else
    const auto savePath = std::filesystem::path("_sd") / "sce_sdmemory" /
        std::to_string(userId) / "memory.dat";
#endif
    std::filesystem::create_directories(savePath.parent_path());
    const std::vector<char> oldData{'o', 'l', 'd'};
    {
        std::ofstream file(savePath, std::ios::binary);
        Require(file.is_open());
        file.write(oldData.data(), static_cast<std::streamsize>(oldData.size()));
        Require(static_cast<bool>(file));
    }

    Require(sceSaveDataInitialize3(nullptr) == 0);
    SaveDataMemorySetup2 setup{};
    setup.user_id = userId;
    setup.memory_size = oldData.size() + 3;
    SaveDataMemorySetupResult result{};
    int status = sceSaveDataSetupSaveDataMemory2(&setup, &result);

#ifndef SAVEDATA_NATIVE_BACKEND
    struct MemorySyncParam {
        std::int32_t user_id;
        std::uint32_t slot_id;
        std::uint32_t option;
    } sync{userId, 0, 0};
    if (status == 0) {
        status = sceSaveDataSyncSaveDataMemory(&sync);
    }
#endif

    Require(result.existed_memory_size == oldData.size());
    Require(status == 0);
    std::vector<char> savedData;
    {
        std::ifstream savedFile(savePath, std::ios::binary);
        savedData.assign(std::istreambuf_iterator<char>(savedFile), std::istreambuf_iterator<char>());
    }
    Require(savedData.size() == setup.memory_size);
    Require(std::equal(oldData.begin(), oldData.end(), savedData.begin()));
    Require(std::all_of(savedData.begin() + static_cast<std::ptrdiff_t>(oldData.size()),
                        savedData.end(), [](char byte) { return byte == 0; }));

#ifdef SAVEDATA_NATIVE_BACKEND
    Require(sceSaveDataTerminate() == 0);
#endif

#ifndef SAVEDATA_NATIVE_BACKEND
    Require(ReportsNotImplemented("sceSaveDataAbort", [] { return sceSaveDataAbort(); }));
    Require(ReportsNotImplemented("sceSaveDataBindPsnAccount", [] { return sceSaveDataBindPsnAccount(); }));
    Require(ReportsNotImplemented("sceSaveDataBindPsnAccountForSystemBackup", [] { return sceSaveDataBindPsnAccountForSystemBackup(); }));
    Require(ReportsNotImplemented("sceSaveDataChangeDatabase", [] { return sceSaveDataChangeDatabase(); }));
    Require(ReportsNotImplemented("sceSaveDataChangeInternal", [] { return sceSaveDataChangeInternal(); }));
    Require(ReportsNotImplemented("sceSaveDataCheckBackupData", [] { return sceSaveDataCheckBackupData(); }));
    Require(ReportsNotImplemented("sceSaveDataCheckBackupDataForCdlg", [] { return sceSaveDataCheckBackupDataForCdlg(); }));
    Require(ReportsNotImplemented("sceSaveDataCheckBackupDataInternal", [] { return sceSaveDataCheckBackupDataInternal(); }));
    Require(ReportsNotImplemented("sceSaveDataCheckBackupDataLight", [] { return sceSaveDataCheckBackupDataLight(); }));
    Require(ReportsNotImplemented("sceSaveDataCheckCloudData", [] { return sceSaveDataCheckCloudData(); }));
    Require(ReportsNotImplemented("sceSaveDataCheckSaveDataBroken", [] { return sceSaveDataCheckSaveDataBroken(); }));
    Require(ReportsNotImplemented("sceSaveDataCheckSaveDataVersion", [] { return sceSaveDataCheckSaveDataVersion(); }));
    Require(ReportsNotImplemented("sceSaveDataCheckSaveDataVersionLatest", [] { return sceSaveDataCheckSaveDataVersionLatest(); }));
    Require(ReportsNotImplemented("sceSaveDataClearProgress", [] { return sceSaveDataClearProgress(); }));
    Require(ReportsNotImplemented("sceSaveDataCreateUploadData", [] { return sceSaveDataCreateUploadData(); }));
    Require(ReportsNotImplemented("sceSaveDataDebugGetThreadId", [] { return sceSaveDataDebugGetThreadId(); }));
    Require(ReportsNotImplemented("sceSaveDataDeleteAllUser", [] { return sceSaveDataDeleteAllUser(); }));
    Require(ReportsNotImplemented("sceSaveDataDeleteBackupData", [] { return sceSaveDataDeleteBackupData(); }));
    Require(ReportsNotImplemented("sceSaveDataDeleteCloudData", [] { return sceSaveDataDeleteCloudData(); }));
    Require(ReportsNotImplemented("sceSaveDataDeleteProspero", [] { return sceSaveDataDeleteProspero(); }));
    Require(ReportsNotImplemented("sceSaveDataDeleteTitle", [] { return sceSaveDataDeleteTitle(); }));
    Require(ReportsNotImplemented("sceSaveDataDeleteUser", [] { return sceSaveDataDeleteUser(); }));
    Require(ReportsNotImplemented("sceSaveDataDirNameSearchInternal", [] { return sceSaveDataDirNameSearchInternal(); }));
    Require(ReportsNotImplemented("sceSaveDataDownload", [] { return sceSaveDataDownload(); }));
    Require(ReportsNotImplemented("sceSaveDataGetAllSize", [] { return sceSaveDataGetAllSize(); }));
    Require(ReportsNotImplemented("sceSaveDataGetAppLaunchedUser", [] { return sceSaveDataGetAppLaunchedUser(); }));
    Require(ReportsNotImplemented("sceSaveDataGetAutoUploadConditions", [] { return sceSaveDataGetAutoUploadConditions(); }));
    Require(ReportsNotImplemented("sceSaveDataGetAutoUploadRequestInfo", [] { return sceSaveDataGetAutoUploadRequestInfo(); }));
    Require(ReportsNotImplemented("sceSaveDataGetAutoUploadSetting", [] { return sceSaveDataGetAutoUploadSetting(); }));
    Require(ReportsNotImplemented("sceSaveDataGetBoundPsnAccountCount", [] { return sceSaveDataGetBoundPsnAccountCount(); }));
    Require(ReportsNotImplemented("sceSaveDataGetClientThreadPriority", [] { return sceSaveDataGetClientThreadPriority(); }));
    Require(ReportsNotImplemented("sceSaveDataGetCloudQuotaInfo", [] { return sceSaveDataGetCloudQuotaInfo(); }));
    Require(ReportsNotImplemented("sceSaveDataGetEventInfo", [] { return sceSaveDataGetEventInfo(); }));
    Require(ReportsNotImplemented("sceSaveDataGetMountedSaveDataCount", [] { return sceSaveDataGetMountedSaveDataCount(); }));
    Require(ReportsNotImplemented("sceSaveDataGetProgress", [] { return sceSaveDataGetProgress(); }));
    Require(ReportsNotImplemented("sceSaveDataGetSaveDataCount", [] { return sceSaveDataGetSaveDataCount(); }));
    Require(ReportsNotImplemented("sceSaveDataGetSaveDataRootDir", [] { return sceSaveDataGetSaveDataRootDir(); }));
    Require(ReportsNotImplemented("sceSaveDataGetSaveDataRootPath", [] { return sceSaveDataGetSaveDataRootPath(); }));
    Require(ReportsNotImplemented("sceSaveDataGetSaveDataRootUsbPath", [] { return sceSaveDataGetSaveDataRootUsbPath(); }));
    Require(ReportsNotImplemented("sceSaveDataGetSavePoint", [] { return sceSaveDataGetSavePoint(); }));
    Require(ReportsNotImplemented("sceSaveDataGetUpdatedDataCount", [] { return sceSaveDataGetUpdatedDataCount(); }));
    Require(ReportsNotImplemented("sceSaveDataInitialize2", [] { return sceSaveDataInitialize2(); }));
    Require(ReportsNotImplemented("sceSaveDataInitializeForCdlg", [] { return sceSaveDataInitializeForCdlg(); }));
    Require(ReportsNotImplemented("sceSaveDataIsDeletingUsbDb", [] { return sceSaveDataIsDeletingUsbDb(); }));
    Require(ReportsNotImplemented("sceSaveDataIsMounted", [] { return sceSaveDataIsMounted(); }));
    Require(ReportsNotImplemented("sceSaveDataManualDelete", [] { return sceSaveDataManualDelete(); }));
    Require(ReportsNotImplemented("sceSaveDataManualDownload", [] { return sceSaveDataManualDownload(); }));
    Require(ReportsNotImplemented("sceSaveDataManualUpload", [] { return sceSaveDataManualUpload(); }));
    Require(ReportsNotImplemented("sceSaveDataMount5", [] { return sceSaveDataMount5(); }));
    Require(ReportsNotImplemented("sceSaveDataMountInternal", [] { return sceSaveDataMountInternal(); }));
    Require(ReportsNotImplemented("sceSaveDataMountSys", [] { return sceSaveDataMountSys(); }));
    Require(ReportsNotImplemented("sceSaveDataRebuildDatabase", [] { return sceSaveDataRebuildDatabase(); }));
    Require(ReportsNotImplemented("sceSaveDataRegisterEventCallback", [] { return sceSaveDataRegisterEventCallback(); }));
    Require(ReportsNotImplemented("sceSaveDataRestoreBackupData", [] { return sceSaveDataRestoreBackupData(); }));
    Require(ReportsNotImplemented("sceSaveDataRestoreBackupDataForCdlg", [] { return sceSaveDataRestoreBackupDataForCdlg(); }));
    Require(ReportsNotImplemented("sceSaveDataRestoreLoadSaveDataMemory", [] { return sceSaveDataRestoreLoadSaveDataMemory(); }));
    Require(ReportsNotImplemented("sceSaveDataSetAutoUploadSetting", [] { return sceSaveDataSetAutoUploadSetting(); }));
    Require(ReportsNotImplemented("sceSaveDataSetEventInfo", [] { return sceSaveDataSetEventInfo(); }));
    Require(ReportsNotImplemented("sceSaveDataSetSaveDataLibraryUser", [] { return sceSaveDataSetSaveDataLibraryUser(); }));
    Require(ReportsNotImplemented("sceSaveDataShutdownStart", [] { return sceSaveDataShutdownStart(); }));
    Require(ReportsNotImplemented("sceSaveDataSupportedFakeBrokenStatus", [] { return sceSaveDataSupportedFakeBrokenStatus(); }));
    Require(ReportsNotImplemented("sceSaveDataSyncCloudList", [] { return sceSaveDataSyncCloudList(); }));
    Require(ReportsNotImplemented("sceSaveDataUmountSys", [] { return sceSaveDataUmountSys(); }));
    Require(ReportsNotImplemented("sceSaveDataUmountWithBackup", [] { return sceSaveDataUmountWithBackup(); }));
    Require(ReportsNotImplemented("sceSaveDataUnregisterEventCallback", [] { return sceSaveDataUnregisterEventCallback(); }));
    Require(ReportsNotImplemented("sceSaveDataUpload", [] { return sceSaveDataUpload(); }));
#endif

    std::filesystem::current_path(originalDirectory);
    std::filesystem::remove_all(root);
}
