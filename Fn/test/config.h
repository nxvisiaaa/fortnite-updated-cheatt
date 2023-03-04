static BOOL WritePrivateProfileInt(LPCSTR lpAppName, LPCSTR lpKeyName, int nInteger, LPCSTR lpFileName) {
    char lpString[1024];
    sprintf(lpString, E("%d"), nInteger);
    return WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName);
}
static BOOL WritePrivateProfileFloat(LPCSTR lpAppName, LPCSTR lpKeyName, float nInteger, LPCSTR lpFileName) {
    char lpString[1024];
    sprintf(lpString, E("%f"), nInteger);
    return WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName);
}
static float GetPrivateProfileFloat(LPCSTR lpAppName, LPCSTR lpKeyName, FLOAT flDefault, LPCSTR lpFileName)
{
    char szData[32];

    GetPrivateProfileStringA(lpAppName, lpKeyName, std::to_string(flDefault).c_str(), szData, 32, lpFileName);

    return (float)atof(szData);
}

static void Save_Settings(LPCSTR path)
{
    WritePrivateProfileInt((E("Visuals")), (E("m_playeresp")), visuals::box, path);
    WritePrivateProfileInt((E("Visuals")), (E("m_boxstyle")), visuals::boxMode, path);
    WritePrivateProfileInt((E("Visuals")), (E("m_radarstyle")), modules::radarstyle, path);
    WritePrivateProfileInt((E("Visuals")), (E("m_skeleton")), visuals::skel, path);
    WritePrivateProfileInt((E("Visuals")), (E("m_crosshair")), visuals::crosshair, path);
    WritePrivateProfileInt((E("Visuals")), (E("m_playername")), visuals::name, path);
    WritePrivateProfileInt((E("Visuals")), (E("m_drawhead")), visuals::show_head, path);
    WritePrivateProfileInt((E("Visuals")), (E("m_outline")), visuals::outline, path);
    WritePrivateProfileInt((E("Visuals")), (E("m_snaplines")), visuals::lines, path);
    WritePrivateProfileInt((E("Visuals")), (E("m_linemode")), visuals::lineMode, path);

    WritePrivateProfileInt((E("Aimbot")), (E("m_aimbot")), aimbot::aimbot, path);
    WritePrivateProfileInt((E("Aimbot")), (E("m_smooth")), aimbot::smooth, path);
    WritePrivateProfileFloat((E("Aimbot")), (E("m_aimbotfov")), aimbot::aimfov, path);
    WritePrivateProfileFloat((E("Aimbot")), (E("m_aimbotsmooth")), aimbot::aimspeed, path);
    WritePrivateProfileInt((E("Aimbot")), (E("m_fovcircle")), aimbot::fovcircle, path);
    WritePrivateProfileInt((E("Aimbot")), (E("m_aimkey")), hotkeys::aimkey, path);
    WritePrivateProfileInt((E("Aimbot")), (E("m_hitbox")), aimbot::hitbox, path);
    WritePrivateProfileInt((E("Aimbot")), (E("m_prediction")), aimbot::prediction, path);

    WritePrivateProfileFloat((E("Colors")), (E("m_espr")), colors::espcolor[0], path);
    WritePrivateProfileFloat((E("Colors")), (E("m_espg")), colors::espcolor[1], path);
    WritePrivateProfileFloat((E("Colors")), (E("m_espb")), colors::espcolor[2], path);
    WritePrivateProfileFloat((E("Colors")), (E("m_crossr")), colors::boxcolor[0], path);
    WritePrivateProfileFloat((E("Colors")), (E("m_crossg")), colors::boxcolor[1], path);
    WritePrivateProfileFloat((E("Colors")), (E("m_crossb")), colors::boxcolor[2], path);
    WritePrivateProfileFloat((E("Colors")), (E("m_fovcolr")), colors::fovcol[0], path);
    WritePrivateProfileFloat((E("Colors")), (E("m_fovcolg")), colors::fovcol[1], path);
    WritePrivateProfileFloat((E("Colors")), (E("m_fovcolb")), colors::fovcol[2], path);

    WritePrivateProfileInt((E("Distance")), (E("m_playerdistance")), visuals::MaxDistance, path);
    WritePrivateProfileInt((E("Distance")), (E("m_esqueletoistance")), visuals::MaxSkeletonDrawDistance, path);
}
static void Load_Settings(LPCSTR path)
{
    visuals::box = GetPrivateProfileIntA((E("Visuals")), (E("m_playeresp")), visuals::box, path);
    modules::radarstyle = GetPrivateProfileIntA((E("Visuals")), (E("m_radarstyle")), modules::radarstyle, path);
    visuals::boxMode = GetPrivateProfileIntA((E("Visuals")), (E("m_boxstyle")), visuals::boxMode, path);
    visuals::crosshair = GetPrivateProfileIntA((E("Visuals")), (E("m_crosshair")), visuals::crosshair, path);
    visuals::skel = GetPrivateProfileIntA((E("Visuals")), (E("m_skeleton")), visuals::skel, path);
    visuals::name = GetPrivateProfileIntA((E("Visuals")), (E("m_playername")), visuals::name, path);
    visuals::show_head = GetPrivateProfileIntA((E("Visuals")), (E("m_drawhead")), visuals::show_head, path);
    visuals::outline = GetPrivateProfileIntA((E("Visuals")), (E("m_outline")), visuals::outline, path);
    visuals::lines = GetPrivateProfileIntA((E("Visuals")), (E("m_snaplines")), visuals::lines, path);
    visuals::lineMode = GetPrivateProfileIntA((E("Visuals")), (E("m_linemode")), visuals::lineMode, path);
    thick::box_thick = GetPrivateProfileIntA((E("Visuals")), (E("m_boxthick")), thick::box_thick, path);
    modules::radar = GetPrivateProfileIntA((E("Visuals")), (E("m_radar")), modules::radar, path);

    aimbot::aimbot = GetPrivateProfileIntA((E("Aimbot")), (E("m_aimbot")), aimbot::aimbot, path);
    aimbot::smooth = GetPrivateProfileIntA((E("Aimbot")), (E("m_smooth")), aimbot::smooth, path);
    aimbot::aimfov = GetPrivateProfileFloat((E("Aimbot")), (E("m_aimbotfov")), aimbot::aimfov, path);
    aimbot::aimspeed = GetPrivateProfileFloat((E("Aimbot")), (E("m_aimbotsmooth")), aimbot::aimspeed, path);
    aimbot::fovcircle = GetPrivateProfileIntA((E("Aimbot")), (E("m_fovcircle")), aimbot::fovcircle, path);
    hotkeys::aimkey = GetPrivateProfileIntA((E("Aimbot")), (E("m_aimkey")), hotkeys::aimkey, path);
    aimbot::hitbox = GetPrivateProfileIntA((E("Aimbot")), (E("m_hitbox")), aimbot::hitbox, path);
    aimbot::prediction = GetPrivateProfileIntA((E("Aimbot")), (E("m_prediction")), aimbot::prediction, path);

    colors::espcolor[0] = GetPrivateProfileFloat((E("Colors")), (E("m_espr")), colors::espcolor[0], path);
    colors::espcolor[1] = GetPrivateProfileFloat((E("Colors")), (E("m_espg")), colors::espcolor[1], path);
    colors::espcolor[2] = GetPrivateProfileFloat((E("Colors")), (E("m_espb")), colors::espcolor[2], path);
    colors::boxcolor[0] = GetPrivateProfileFloat((E("Colors")), (E("m_invisibleespr")), colors::boxcolor[0], path);
    colors::boxcolor[1] = GetPrivateProfileFloat((E("Colors")), (E("m_invisibleespg")), colors::boxcolor[1], path);
    colors::boxcolor[2] = GetPrivateProfileFloat((E("Colors")), (E("m_invisibleespb")), colors::boxcolor[2], path);
    colors::skelcol[0] = GetPrivateProfileFloat((E("Colors")), (E("m_skelr")), colors::skelcol[0], path);
    colors::skelcol[1] = GetPrivateProfileFloat((E("Colors")), (E("m_skelg")), colors::skelcol[1], path);
    colors::skelcol[2] = GetPrivateProfileFloat((E("Colors")), (E("m_skelb")), colors::skelcol[2], path);
    colors::fovcol[0] = GetPrivateProfileFloat((E("Colors")), (E("m_fovcolr")), colors::fovcol[0], path);
    colors::fovcol[1] = GetPrivateProfileFloat((E("Colors")), (E("m_fovcolg")), colors::fovcol[1], path);
    colors::fovcol[2] = GetPrivateProfileFloat((E("Colors")), (E("m_fovcolb")), colors::fovcol[2], path);

    visuals::MaxDistance = GetPrivateProfileIntA((E("Distance")), (E("m_playerdistance")), visuals::MaxDistance, path);
    visuals::MaxSkeletonDrawDistance = GetPrivateProfileIntA((E("Distance")), (E("m_esqueletoistance")), visuals::MaxSkeletonDrawDistance, path);
};