#pragma once

#include "Include.h"

struct EntityInfo;
struct EntityState;
enum class EntityType;

uintptr_t GetEntity(int index);
bool IsValidEntity(uintptr_t entity);
EntityInfo ReadEntityInfo(uintptr_t entity);
EntityState ReadEntityState(uintptr_t entity);
EntityType GetEntityTypeFromModelPtr(uintptr_t ent);
std::string ToLower(const std::string& str);

void UpdateLocalPlayer();
void Bunnyhop();
void LoopEntities();

extern std::vector<std::pair<EntityInfo, EntityState>> g_entities;
