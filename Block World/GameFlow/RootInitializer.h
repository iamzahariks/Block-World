#include "Services/WindowService.h"
#include "Services/MapService.h"

namespace GameFlow {
	namespace WindowService = WindowService;
	namespace MapService = MapService;

	void Init() {
		MapService::Init();
	}
}