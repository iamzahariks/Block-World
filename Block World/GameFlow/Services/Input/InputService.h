#include "Mouse/MouseService.h"
#include "Keyboard/KeyboardService.h"

namespace InputService {
	namespace MouseService = MouseService;
	namespace KeyboardService = KeyboardService;

	void Update() {
		MouseService::Update();
		KeyboardService::Update();
	}
}