#include "Include.h"

std::vector<std::pair<EntityInfo, EntityState>> g_entities;

uintptr_t GetEntity(int index) {
    return ReadMemory<uintptr_t>(clientBase + Offsets::dwEntityList + index * 0x10);
}

bool IsValidEntity(uintptr_t ent) {
    if (!ent || ent == localPlayer) return false;

    int health = ReadMemory<int>(ent + Offsets::m_iHealth);
    uintptr_t modelPtr = ReadMemory<uintptr_t>(ent + 0x10);

    char buffer[128]{};
    ReadProcessMemory(hProcess, (LPCVOID)modelPtr, buffer, sizeof(buffer), nullptr);
    std::string modelName(buffer);
    std::string lower = ToLower(modelName);

    if (lower.find("common") != std::string::npos ||
        lower.find("infected") != std::string::npos ||
        lower.find("zombie") != std::string::npos ||
        lower.find("witch") != std::string::npos)
        return true;

    return health > 0;
}


void UpdateLocalPlayer() {
    uintptr_t localPtrAddr = clientBase + Offsets::dwLocalPlayer;
    while (!(localPlayer = ReadMemory<uintptr_t>(localPtrAddr))) {
        std::cout << "[INFO] Waiting for localPlayer pointer...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::cout << "[SUCCESS] localPlayer found at 0x" << std::hex << localPlayer << std::endl;
}

void Bunnyhop() {
    if (!enableBunnyhop) return;
    if (!(GetAsyncKeyState(VK_SPACE) & 0x8000)) return;

    uintptr_t lp = ReadMemory<uintptr_t>(clientBase + Offsets::dwLocalPlayer);
    if (!lp) return;

    int flags = ReadMemory<int>(lp + Offsets::m_fFlags);
    if (flags & (1 << 0)) {
        WriteMemory<int>(clientBase + Offsets::dwForceJump, 6);
    }
}

std::string ToLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return result;
}

EntityType GetEntityTypeFromModelPtr(uintptr_t ent) {
    uintptr_t modelPtr = ReadMemory<uintptr_t>(ent + 0x10);
    if (!modelPtr) return EntityType::Unknown;

    char buffer[128]{};
    if (!ReadProcessMemory(hProcess, (LPCVOID)modelPtr, buffer, sizeof(buffer), nullptr))
        return EntityType::Unknown;

    std::string modelName(buffer);
    std::string lower = ToLower(modelName);

    // Debug Log
    std::cout << "[DEBUG] Model name: " << modelName << std::endl;

    if (lower.find("witch") != std::string::npos) return EntityType::Witch;
    if (lower.find("common") != std::string::npos ||
        lower.find("infected") != std::string::npos ||
        lower.find("zombie") != std::string::npos)
        return EntityType::Common;

    return EntityType::Unknown;
}

EntityInfo ReadEntityInfo(uintptr_t entity) {
    EntityInfo info;
    info.position = ReadMemory<Vec3>(entity + Offsets::m_vecOrigin);
    info.team = ReadMemory<int>(entity + Offsets::m_iTeamNum);
    info.health = ReadMemory<int>(entity + Offsets::m_iHealth);
    info.zombieClass = ReadMemory<int>(entity + Offsets::m_zombieClass);
    info.type = GetEntityTypeFromModelPtr(entity);
    return info;
}

EntityState ReadEntityState(uintptr_t entity) {
    EntityState state;
    state.health = ReadMemory<int>(entity + Offsets::m_iHealth);
    state.lifeState = ReadMemory<BYTE>(entity + Offsets::m_lifeState);
    state.healthBuffer = ReadMemory<float>(entity + Offsets::m_healthBuffer);
    state.reviveCount = ReadMemory<int>(entity + Offsets::m_currentReviveCount);
    state.isIncapacitated = ReadMemory<bool>(entity + Offsets::m_isIncapacitated);
    state.isOnThirdStrike = ReadMemory<bool>(entity + Offsets::m_bIsOnThirdStrike);
    state.isGoingToDie = ReadMemory<bool>(entity + Offsets::m_isGoingToDie);
    state.survivorCharacter = ReadMemory<int>(entity + Offsets::m_survivorCharacter);
    return state;
}

void LoopEntities() {
    g_entities.clear();

    for (int i = 0; i < 1024; ++i) { // range entity
        uintptr_t ent = GetEntity(i);
        if (!ent || ent == localPlayer) continue;

        EntityInfo info = ReadEntityInfo(ent);
        EntityState state = ReadEntityState(ent);

        bool validSurvivor = IsValidSurvivor(info, state);

        bool validSpecial = IsValidSpecialInfected(info, state);

        bool validTank = IsTank(info);

        bool isValidModelEntity =
            (info.type == EntityType::Common || info.type == EntityType::Witch);

        if (validSurvivor || validSpecial || validTank || isValidModelEntity) {
            g_entities.push_back({ info, state });
        }
    }
}
