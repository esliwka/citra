// Copyright 2023 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "video_core/renderer_base.h"
#include "video_core/renderer_software/sw_rasterizer.h"

namespace Core {
class System;
}

namespace SwRenderer {

struct ScreenInfo {
    u32 width;
    u32 height;
    std::vector<u8> pixels;
};

class RendererSoftware : public VideoCore::RendererBase {
public:
    explicit RendererSoftware(Core::System& system, Frontend::EmuWindow& window);
    ~RendererSoftware() override;

    [[nodiscard]] VideoCore::RasterizerInterface* Rasterizer() const override {
        return rasterizer.get();
    }

    [[nodiscard]] const ScreenInfo& Screen(VideoCore::ScreenId id) const noexcept {
        return screen_infos[static_cast<u32>(id)];
    }

    void SwapBuffers() override;
    void TryPresent(int timeout_ms, bool is_secondary) override {}
    void Sync() override {}

private:
    void PrepareRenderTarget();
    void LoadFBToScreenInfo(int i);

private:
    Memory::MemorySystem& memory;
    std::unique_ptr<RasterizerSoftware> rasterizer;
    std::array<ScreenInfo, 3> screen_infos{};
};

} // namespace SwRenderer
