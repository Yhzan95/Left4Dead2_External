#pragma once
#include <cstdint>

namespace Offsets
{
	// Offsets 
	constexpr uintptr_t dwLocalPlayer = 0x726BD8; // Localplayer
	constexpr uintptr_t m_vecOrigin = 0x124;
	constexpr uintptr_t dwForceJump = 0x759E70;
	constexpr uintptr_t dwViewMatrix = 0x601FDC;
	constexpr uintptr_t viewMatrixInnerOffset = 0x2E4;
	constexpr uintptr_t dwEntityList = 0x73A574;
	constexpr uintptr_t m_iClass = 0x1964; // Client.dll
	constexpr uintptr_t m_iFOV = 0x1390; // Client.dll
	constexpr uintptr_t m_iTeamNum = 0xE4; // Client.dll
	constexpr uintptr_t m_iHealth = 0xEC;
	constexpr uintptr_t m_fFlags = 0xF0;
	constexpr uintptr_t m_zombieClass = 0x1C90;
	constexpr uintptr_t m_rage = 0x12EC;
	constexpr uintptr_t m_wanderRage = 0x12F8;

	constexpr uintptr_t m_iHideHUD = 0x48;
	// Class DT_TerrorPlayer
	inline constexpr uintptr_t m_isIncapacitated = 0x1EA9;
	inline constexpr uintptr_t m_lifeState = 0x147;
	inline constexpr uintptr_t m_currentReviveCount = 0x1EBC;
	inline constexpr uintptr_t m_bIsOnThirdStrike = 0x1EC0;
	inline constexpr uintptr_t m_isGoingToDie = 0x1FB4;
	//inline constexpr uintptr_t m_zombieClass = 0x1C90;
	inline constexpr uintptr_t m_survivorCharacter = 0x1C8C;
	inline constexpr uintptr_t m_healthBuffer = 0x1FAC;
	inline constexpr uintptr_t m_zombieState = 0x1C94;
	inline constexpr uintptr_t m_isCulling = 0x1C98;
	//plus tard
	inline constexpr uintptr_t m_reviveOwner = 0x1F88;
	inline constexpr uintptr_t m_reviveTarget = 0x1F8C;
	inline constexpr uintptr_t m_useActionTarget = 0x1BA0;
	inline constexpr uintptr_t m_useActionOwner = 0x1BA4;
	inline constexpr uintptr_t m_iCurrentUseAction = 0x1BA8;
	//inline constexpr uintptr_t m_bAdrenalineActive = 0x1FD8;
	inline constexpr uintptr_t m_isGhost = 0x1C9A;
	inline constexpr uintptr_t m_hOwnerEntity = 0x138;
	inline constexpr uintptr_t m_modelIndex = 0x638;
}