#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <atomic>
#include <mutex>
#include <urlmon.h>
#include <d3d9.h>
#include <array>
#include <vector>
#include <string>
#include <tlhelp32.h>

#include "Imgui/imgui_packs.cpp"
#include "Imgui/imgui.h"
#include "Imgui/imgui_impl_dx9.h"
#include "Imgui/imgui_impl_win32.h"

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "font.h"

#include "xor.h"
#include "driver.h"
#include "vector.h"
#include "var.h"
#include "utilities.h"
#include "overlay.h"
#include "config.h"

static bool IsInScreen(Vector3 pos, int over = 30) {
    if (pos.x > -over && pos.x < modules::Width + over && pos.y > -over && pos.y < modules::Height + over) {
        return true;
    }
    else {
        return false;
    }
}
static auto find_signature(const char* sig, const char* mask) -> ULONG64 //would not work due driver
{
    auto buffer = std::make_unique<std::array<std::uint8_t, 0x100000>>();
    auto data = buffer.get()->data();

    for (std::uintptr_t i = 0u; i < (2u << 25u); ++i)
    {
        readarray(modules::BaseAddress + i * 0x100000, data, 0x100000);

        if (!data)
            return 0;

        for (std::uintptr_t j = 0; j < 0x100000u; ++j)
        {
            if ([](std::uint8_t const* data, std::uint8_t const* sig, char const* mask)
                {
                    for (; *mask; ++mask, ++data, ++sig)
                    {
                        if (*mask == 'x' && *data != *sig) return false;
                    }
                    return (*mask) == 0;
                }(data + j, (std::uint8_t*)sig, mask))
            {
                std::uintptr_t result = modules::BaseAddress + i * 0x100000 + j;
                std::uint32_t rel = 0;

                readarray(result + 3, &rel, rel);

                if (!rel)
                    return 0;

                return result + rel + 7;
            }
        }
    }

    return 0;
}

// u can add things optionaly
