// Copyright 2015 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/service/cfg/cfg_s.h"

SERIALIZE_EXPORT_IMPL(Service::CFG::CFG_S)

namespace Service::CFG {

CFG_S::CFG_S(std::shared_ptr<Module> cfg) : Module::Interface(std::move(cfg), "cfg:s", 23) {
    static const FunctionInfo functions[] = {
        // cfg common
        // clang-format off
        {0x0001, &CFG_S::GetConfigInfoBlk2, "GetConfigInfoBlk2"},
        {0x0002, &CFG_S::SecureInfoGetRegion, "SecureInfoGetRegion"},
        {0x0003, &CFG_S::GenHashConsoleUnique, "GenHashConsoleUnique"},
        {0x0004, &CFG_S::GetRegionCanadaUSA, "GetRegionCanadaUSA"},
        {0x0005, &CFG_S::GetSystemModel, "GetSystemModel"},
        {0x0006, &CFG_S::GetModelNintendo2DS, "GetModelNintendo2DS"},
        {0x0007, nullptr, "WriteToFirstByteCfgSavegame"},
        {0x0008, nullptr, "GoThroughTable"},
        {0x0009, &CFG_S::GetCountryCodeString, "GetCountryCodeString"},
        {0x000A, &CFG_S::GetCountryCodeID, "GetCountryCodeID"},
        {0x000B, nullptr, "IsFangateSupported"},
        // cfg:s
        {0x0401, &CFG_S::GetConfigInfoBlk8, "GetConfigInfoBlk8"},
        {0x0402, &CFG_S::SetConfigInfoBlk4, "SetConfigInfoBlk4"},
        {0x0403, &CFG_S::UpdateConfigNANDSavegame, "UpdateConfigNANDSavegame"},
        {0x0404, nullptr, "GetLocalFriendCodeSeedData"},
        {0x0405, nullptr, "GetLocalFriendCodeSeed"},
        {0x0406, &CFG_S::SecureInfoGetRegion, "SecureInfoGetRegion"},
        {0x0407, &CFG_S::SecureInfoGetByte101, "SecureInfoGetByte101"},
        {0x0408, nullptr, "SecureInfoGetSerialNo"},
        {0x0409, nullptr, "UpdateConfigBlk00040003"},
        // clang-format on
    };
    RegisterHandlers(functions);
}

} // namespace Service::CFG
