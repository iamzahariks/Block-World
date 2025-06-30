#include "Services/WindowService.h"
#include "Services/MapService.h"
#include "Services/SelectionService.h"
#include "Services/DestructionService.h"
#include "Services/InventoryService.h"
#include "Services/PlacementService.h"

namespace GameFlow {
	namespace WindowService = WindowService;
	namespace MapService = MapService;
	namespace SelectionService = SelectionService;
	namespace DestructionService = DestructionService;
	namespace InventoryService = InventoryService;
	namespace PlacementService = PlacementService;

	void Init() {
		WindowService::Init();
		MapService::Init();
		SelectionService::Init();
		DestructionService::Init();
		PlacementService::Init();
	}

	void Update(double dt) {
		WindowService::Update(dt);
		SelectionService::Update(dt);
		DestructionService::Update(dt);
	}
}