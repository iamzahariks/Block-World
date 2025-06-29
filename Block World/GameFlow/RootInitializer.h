#include "Services/WindowService.h"
#include "Services/MapService.h"
#include "Services/SelectionService.h"

namespace GameFlow {
	namespace WindowService = WindowService;
	namespace MapService = MapService;
	namespace SelectionService = SelectionService;

	void Init() {
		MapService::Init();
		SelectionService::Init();
	}
}