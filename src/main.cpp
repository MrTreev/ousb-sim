#include "ousb.h"
#include "util.h"
#include <imgui.h>
#include <rlImGui.h>

class Application {
    int  screenWidth  = 1280;
    int  screenHeight = 800;
    int  target_fps   = 60;
    Ousb ousb{};

    struct {
        bool general_registers = true;
        bool io_registers      = true;
    } gui;

public:
    Application() {
        SetConfigFlags(nosign(FLAG_MSAA_4X_HINT) | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
        InitWindow(screenWidth, screenHeight, "raylib-Extras [ImGui] example - simple ImGui Demo");
        SetTargetFPS(target_fps);
        rlImGuiSetup(true);
    }

    void draw_general_registers() const {
        if (!gui.general_registers) return;
        if (ImGui::Begin("General Registers", nullptr)) {
            ImGui::Text("R0:  0x%02X", ousb.registers.R0());
            ImGui::Text("R1:  0x%02X", ousb.registers.R1());
            ImGui::Text("R2:  0x%02X", ousb.registers.R2());
            ImGui::Text("R3:  0x%02X", ousb.registers.R3());
            ImGui::Text("R4:  0x%02X", ousb.registers.R4());
            ImGui::Text("R5:  0x%02X", ousb.registers.R5());
            ImGui::Text("R6:  0x%02X", ousb.registers.R6());
            ImGui::Text("R7:  0x%02X", ousb.registers.R7());
            ImGui::Text("R8:  0x%02X", ousb.registers.R8());
            ImGui::Text("R9:  0x%02X", ousb.registers.R9());
            ImGui::Text("R10: 0x%02X", ousb.registers.R10());
            ImGui::Text("R11: 0x%02X", ousb.registers.R11());
            ImGui::Text("R12: 0x%02X", ousb.registers.R12());
            ImGui::Text("R13: 0x%02X", ousb.registers.R13());
            ImGui::Text("R14: 0x%02X", ousb.registers.R14());
            ImGui::Text("R15: 0x%02X", ousb.registers.R15());
            ImGui::Text("R16: 0x%02X", ousb.registers.R16());
            ImGui::Text("R17: 0x%02X", ousb.registers.R17());
            ImGui::Text("R18: 0x%02X", ousb.registers.R18());
            ImGui::Text("R19: 0x%02X", ousb.registers.R19());
            ImGui::Text("R20: 0x%02X", ousb.registers.R20());
            ImGui::Text("R21: 0x%02X", ousb.registers.R21());
            ImGui::Text("R22: 0x%02X", ousb.registers.R22());
            ImGui::Text("R23: 0x%02X", ousb.registers.R23());
            ImGui::Text("R24: 0x%02X", ousb.registers.R24());
            ImGui::Text("R25: 0x%02X", ousb.registers.R25());
            ImGui::Text("R26: 0x%02X", ousb.registers.R26());
            ImGui::Text("R27: 0x%02X", ousb.registers.R27());
            ImGui::Text("R28: 0x%02X", ousb.registers.R28());
            ImGui::Text("R29: 0x%02X", ousb.registers.R29());
            ImGui::Text("R30: 0x%02X", ousb.registers.R30());
            ImGui::Text("R31: 0x%02X", ousb.registers.R31());
        }
        ImGui::End();
    }

    void draw_io_registers() const {
        if (!gui.io_registers) return;
        if (ImGui::Begin("IO Registers", nullptr)) {
            ImGui::Text("EEAR: 0x%04X", ousb.io_registers.EEAR());
            ImGui::Text("EEDR: 0x%02X", ousb.io_registers.EEDR());
            ImGui::Text("EECR: 0x%02X", ousb.io_registers.EECR());
        }
        ImGui::End();
    }

    bool tick() {
        if (WindowShouldClose()) return false;
        BeginDrawing();
        ClearBackground(DARKGRAY);
        rlImGuiBegin();
        draw_general_registers();
        draw_io_registers();
        rlImGuiEnd();
        EndDrawing();
        return true;
    }
};

int main() {
    Application app{};
    while (app.tick()) {}
}
