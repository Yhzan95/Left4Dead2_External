#pragma once

#include "Include.h"
enum class EntityType {
    Unknown,
    Common,
    Witch
};

struct EntityInfo {
    Vec3 position;
    int team;
    int health;
    int zombieClass;
    EntityType type; 
};

struct EntityState {
    int health;
    BYTE lifeState;
    float healthBuffer;
    int reviveCount;
    bool isIncapacitated;
    bool isOnThirdStrike;
    bool isGoingToDie;
    int survivorCharacter;
};

bool IsValidSurvivor(const EntityInfo& info, const EntityState& state);
bool IsValidSpecialInfected(const EntityInfo& info, const EntityState& state);
bool IsTank(const EntityInfo& info);
