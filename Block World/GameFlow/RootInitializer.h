#include "Services/SoundService.h"
#include "Services/WindowService.h"
#include "Services/MapService.h"
#include "Services/SelectionService.h"
#include "Services/InventoryService.h"
#include "Services/DestructionService.h"
#include "Services/PlacementService.h"

namespace GameFlow {
	namespace WindowService = WindowService;
	namespace MapService = MapService;
	namespace SelectionService = SelectionService;
	namespace DestructionService = DestructionService;
	namespace InventoryService = InventoryService;
	namespace SoundService = SoundService;

	void Init() {
		SoundService::Init();
		WindowService::Init();
		MapService::Init();
		SelectionService::Init();
		DestructionService::Init();
		InventoryService::Init();
		PlacementService::Init();
	}

	void Update(double dt) {
		WindowService::Update(dt);
		SelectionService::Update(dt);
		DestructionService::Update(dt);
	}
}