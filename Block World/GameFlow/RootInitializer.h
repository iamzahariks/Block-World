#include "Services/WindowService.h"
#include "Services/MapService.h"
#include "Services/SelectionService.h"
#include "Services/DestructionService.h"

namespace GameFlow {
	namespace WindowService = WindowService;
	namespace MapService = MapService;
	namespace SelectionService = SelectionService;
	namespace DestructionService = DestructionService;

	void Init() {
		WindowService::Init();
		MapService::Init();
		SelectionService::Init();
		DestructionService::Init();
	}

	void Update(double dt) {
		WindowService::Update(dt);
		SelectionService::Update(dt);
		DestructionService::Update(dt);
	}
}