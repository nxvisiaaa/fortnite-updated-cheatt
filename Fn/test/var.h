#pragma once

using namespace std;

static ImFont* SkeetFont;
static IDirect3D9Ex* p_Object = NULL;
static IDirect3DDevice9Ex* p_Device = NULL;
static D3DPRESENT_PARAMETERS p_Params = { NULL };

#define M_Name L" "
static HWND MyWnd = NULL;
static HWND GameWnd = NULL;
static RECT GameRect = { NULL };
static MSG Message = { NULL };

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#define TopWindowGame 11
#define TopWindowMvoe 22

auto get_process_wnd(uint32_t pid) -> HWND;
auto DirectXInit(HWND hWnd) -> HRESULT;
auto SetupWindow() -> void;
auto render() -> void;
auto MainLoop() -> WPARAM;
auto WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam) -> LRESULT CALLBACK;
auto CleanuoD3D() -> void;
auto isTopwin() -> ULONG;
auto SetWindowToTarget() -> void;

typedef struct _FNlEntity {
    uint64_t Actor;
    int ID;
    uint64_t mesh;
    uint64_t PlayerState;
    uint64_t LocalPlayerState;
    bool Spotted;
}FNlEntity;
static std::vector<FNlEntity> entityList;
static auto IsVec3Valid(Vector3 vec3) -> BOOL
{
	return !(vec3.x == 0 && vec3.y == 0 && vec3.z == 0);
}
static float Calc3D_Dist(const Vector3& Src, const Vector3& Dst) {
    return sqrtf(pow((Src.x - Dst.x), 2) + pow((Src.y - Dst.y), 2) + pow((Src.z - Dst.z), 2));
}
namespace modules {

	static ULONG64 BaseAddress;
	static ULONG PID;

	static ULONG Width = GetSystemMetrics(SM_CXSCREEN);
	static ULONG Height = GetSystemMetrics(SM_CYSCREEN);
	static ULONG ScreenCenterX = NULL;
	static ULONG ScreenCenterY = NULL;

    static ImFont* SkeetFont;
    static ImFont* espFont;

	static ULONG Depth;

    static bool radar;
    static int radarstyle;
}
namespace offests {

	static ULONG64 offset_uworld;
	static ULONG64 offest_gname;
	static ULONG64 uworld;
	static ULONG64 persistent_level;
	static ULONG64 game_instance;
	static ULONG64 local_players_array;
	static ULONG64 player_controller;
	static ULONG64 camera_manager;
	static ULONG64 rootcomponent;
	static ULONG64 Pawn;
	static Vector3 relativelocation;

	static ULONG64 actor_array;
	static ULONG32 actor_count;
}
namespace thick{

	static int SkeletonThick = 1;
	static int box_thick = 1;
}

namespace visuals
{
	static bool box = false;
	static bool skel = false;
	static bool name = false;
	static bool lines = false;
	static bool outline = false;
	static bool show_head = false;
	static bool crosshair = false;
	static bool Health = false;

	static int boxMode = 0;
	static int skelMode = 0;
	static int lineMode = 0;


	static float MaxSkeletonDrawDistance = 50.f;
	static float MaxDistance = 500.f;
}

namespace aimbot
{
	static bool aimbot = false;
	static bool smooth = false;
	static bool fovcircle = false;
	static bool prediction = false;

	static float aimspeed = 1.0f;
	static float aimfov = 100.0f;
	static float lock = 0.0f;

	static int hitbox = 0;
}

static ULONG select_hitbox()
{
	static ULONG hitbox = 0;

	if (aimbot::hitbox == 0)
		hitbox = 68;  
	else if (aimbot::hitbox == 1)
		hitbox = 67;  
	else if (aimbot::hitbox == 2)
		hitbox = 2;
	return hitbox;
}

namespace hotkeys
{
	static ULONG aimkey;
}

static const char* RadarStyle[] =
{
    "Box",
    "Box Filled",
    "Circle",
    "Circle Filled"
};
static const char* Hitbox[] =
{
	"Head",
	"Neck",
	"Pelvis"
};
static const char* boxStyle[] =
{
    "2D",
    "2D Filled",
    "2D Corner",
    "2D Corner Filled",
    "3D Box"
};
static const char* linesMode[] =
{
    "Bottom",
    "Top",
    "Center"
};

static const char* keyNames[] =
{
    "",
    "Left Mouse",
    "Right Mouse",
    "Cancel",
    "Middle Mouse",
    "Mouse 5",
    "Mouse 4",
    "",
    "Backspace",
    "Tab",
    "",
    "",
    "Clear",
    "Enter",
    "",
    "",
    "Shift",
    "Control",
    "Alt",
    "Pause",
    "Caps",
    "",
    "",
    "",
    "",
    "",
    "",
    "Escape",
    "",
    "",
    "",
    "",
    "Space",
    "Page Up",
    "Page Down",
    "End",
    "Home",
    "Left",
    "Up",
    "Right",
    "Down",
    "",
    "",
    "",
    "Print",
    "Insert",
    "Delete",
    "",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "",
    "",
    "",
    "",
    "",
    "Numpad 0",
    "Numpad 1",
    "Numpad 2",
    "Numpad 3",
    "Numpad 4",
    "Numpad 5",
    "Numpad 6",
    "Numpad 7",
    "Numpad 8",
    "Numpad 9",
    "Multiply",
    "Add",
    "",
    "Subtract",
    "Decimal",
    "Divide",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "F11",
    "F12",
};
static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
{
    const char* const* items = (const char* const*)data;
    if (out_text)
        *out_text = items[idx];
    return true;
}

static int keystatus = 0;
static int realkey = 0;

static bool GetKey(int key)
{
    realkey = key;
    return true;
}
static void ChangeKey(void* blank)
{
    keystatus = 1;
    while (true)
    {
        for (int i = 0; i < 0x87; i++)
        {
            if (GetKeyState(i) & 0x8000)
            {
                hotkeys::aimkey = i;
                keystatus = 0;
                return;
            }
        }
    }
}
static void HotkeyButton(int aimkey, void* changekey, int status)
{
    const char* preview_value = NULL;
    if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(keyNames))
        Items_ArrayGetter(keyNames, aimkey, &preview_value);

    std::string aimkeys;
    if (preview_value == NULL)
        aimkeys = E("Select Key");
    else
        aimkeys = preview_value;

    if (status == 1)
    {
        aimkeys = E("Press key to bind");
    }
    if (ImGui::Button(aimkeys.c_str(), ImVec2(125, 20)))
    {
        if (status == 0)
        {
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
        }
    }
}
namespace colors {

    static float fovcol[3] = { 1.0f , 0.0f , 0.0f };
    static float linecol[3] = { 1.0f , 0.0f , 0.0f };
    static float boxcolor[3] = { 1.0f , 0.0f , 0.0f };
    static float espcolor[3] = { 1.0f , 0.0f , 0.0f };
    static float skelcol[3] = { 1.0f , 0.0f , 0.0f };
}

namespace setting {

    static int settsMode = 0;
}
static const char* settsName[] =
{
    "Default",
};