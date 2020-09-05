//bunyip24#2516
#include "../../Header Files/includes.h"
namespace Offsets {
	PVOID* uWorld = 0;

	namespace Engine {
		namespace World {
			DWORD OwningGameInstance = 0;
			DWORD Levels = 0;
		}

		namespace Level {
			DWORD AActors = 0x98;
		}

		namespace GameInstance {
			DWORD LocalPlayers = 0;
		}

		namespace Player {
			DWORD PlayerController = 0x30;
		}

		namespace Controller {
			DWORD ControlRotation = 0x288;
			PVOID SetControlRotation = 0;
			PVOID ClientSetRotation;
		}

		namespace PlayerController {
			DWORD AcknowledgedPawn = 0x2A0; //0x298
			DWORD PlayerCameraManager = 0x2B8;
		}

		namespace Pawn {
			DWORD PlayerState = 0x240;
		}

		namespace PlayerState {
			PVOID GetPlayerName = 0;
		}

		namespace Actor {
			DWORD RootComponent = 0x130;
			DWORD CustomTimeDilation = 0x98;
		}

		namespace Character {
			DWORD Mesh = 0x280;
		}

		namespace SceneComponent {
			//DWORD SceneComponent = 0x0130;
			DWORD RelativeLocation = 0x11C;
			DWORD ComponentVelocity = 0x140;
		}

		namespace StaticMeshComponent {
			DWORD ComponentToWorld = 0x1C0;
			DWORD StaticMesh = 0x488;
		}

		namespace SkinnedMeshComponent {
			DWORD CachedWorldSpaceBounds = 0x5F8;//0x5A0;
		}
	}

	namespace FortniteGame {
		namespace FortPawn {
			DWORD bIsDBNO = 0x552;
			DWORD bIsDying = 0x538;
			DWORD CurrentWeapon = 0x5A0;//0x588;
		}

		namespace FortPickup {
			DWORD PrimaryPickupItemEntry = 0x298;
		}

		namespace FortItemEntry {
			DWORD ItemDefinition = 0x18;
		}

		namespace FortItemDefinition {
			DWORD DisplayName = 0x70;
			DWORD Tier = 0x54;
		}

		namespace FortPlayerStateAthena {
			DWORD TeamIndex = 0xE88;
		}

		namespace FortWeapon {
			DWORD WeaponData = 0x378;
			DWORD AmmoCount = 0x0934;
			DWORD LastFireAbilityTime = 0xAB8;
			DWORD LastFireTime = 0x8BC;
			DWORD LastFireTimeVerified = 0x8C0;
		}

		namespace FortHoagieVehicle {
			DWORD BoostCooldown = 0x105C;
		}

		namespace FortWeaponItemDefinition {
			DWORD WeaponStatHandle = 0x7D8;
		}

		namespace FortProjectileAthena {
			DWORD FireStartLoc = 0x868;
		}

		namespace FortBaseWeaponStats {
			//DWORD ReloadTime = 0;
			DWORD ReloadTime = 0xFC;
			DWORD ReloadScale = 0x100;
			DWORD ChargeDownTime = 0x12C;
		}

		namespace BuildingContainer {
			DWORD bAlreadySearched = 0xC81;
		}
	}

	namespace UI {
		namespace ItemCount {
			DWORD ItemDefinition = 0;
		}
	}

	BOOLEAN Initialize() {
		auto addr = Util::FindPattern("\x48\x8B\x1D\x00\x00\x00\x00\x48\x85\xDB\x74\x3B\x41", "xxx????xxxxxx");
		if (!addr) {
			MessageBox(0, L"Please contact an administrator and give the error code:\n0x08", L"Error", 0);
			return FALSE;
		}

		uWorld = reinterpret_cast<decltype(uWorld)>(RELATIVE_ADDR(addr, 7));

		// SetControlRotation
		Engine::Controller::SetControlRotation = Util::FindObject(L"/Script/Engine.Controller.SetControlRotation");
		if (!Engine::Controller::SetControlRotation) {
			MessageBox(0, L"Please contact an administrator and give the error code:\n0x09", L"Error", 0);
			return FALSE;
		}

		// ClientSetRotation
		Engine::Controller::ClientSetRotation = Util::FindObject(L"/Script/Engine.Controller.ClientSetRotation");
		if (!Engine::Controller::ClientSetRotation) {
			MessageBox(0, L"Please contact an administrator and give the error code:\n0x10", L"Error", 0);
			return FALSE;
		}

		// GetPlayerName
		Engine::PlayerState::GetPlayerName = Util::FindObject(L"/Script/Engine.PlayerState.GetPlayerName");
		if (!Engine::PlayerState::GetPlayerName) {
			MessageBox(0, L"Please contact an administrator and give the error code:\n0x11", L"Error", 0);
			return FALSE;
		}

		Engine::World::OwningGameInstance = 0x180;
		Engine::World::Levels = 0x138;
		Engine::GameInstance::LocalPlayers = 0x38;
		Engine::Player::PlayerController = 0x30;
		Engine::PlayerController::AcknowledgedPawn = 0x2A0;
		Engine::Controller::ControlRotation = 0x288;
		Engine::Pawn::PlayerState = 0x240;
		Engine::Actor::RootComponent = 0x130;
		Engine::Character::Mesh = 0x280;
		//Engine::SceneComponent::SceneComponent = 0x0130;
		Engine::SceneComponent::RelativeLocation = 0x11C;
		Engine::SceneComponent::ComponentVelocity = 0x140;
		Engine::StaticMeshComponent::StaticMesh = 0x488;
		Engine::SkinnedMeshComponent::CachedWorldSpaceBounds = 0x5F8; //
		FortniteGame::FortPawn::bIsDBNO = 0x552;
		FortniteGame::FortPawn::bIsDying = 0x538;
		FortniteGame::FortPlayerStateAthena::TeamIndex = 0xE88; //
		FortniteGame::FortPickup::PrimaryPickupItemEntry = 0x298;
		FortniteGame::FortItemDefinition::DisplayName = 0x70;
		//FortniteGame::FortHoagieVehicle::BoostCooldown = 0x105C;
		FortniteGame::FortItemDefinition::Tier = 0x54;
		FortniteGame::FortItemEntry::ItemDefinition = 0x18;
		FortniteGame::FortPawn::CurrentWeapon = 0x5A0;
		FortniteGame::FortWeapon::WeaponData = 0x378;
		FortniteGame::FortWeaponItemDefinition::WeaponStatHandle = 0x7D8; //
		FortniteGame::FortProjectileAthena::FireStartLoc = 0x868; // 0x850
		FortniteGame::FortBaseWeaponStats::ReloadTime = 0xFC;
		FortniteGame::BuildingContainer::bAlreadySearched = 0xC81; //

		return TRUE;
	}
}