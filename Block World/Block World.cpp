#include <iostream>
#include "GameFlow/Libraries.h"
#include "GameFlow/Classes/Init.h"
#include "GameFlow/Services/Input/InputService.h"

void React(sf::Vector2i vect) {
	std::cout << vect.x << ' ' << vect.y << '\n';
}

void F(void*) {
	std::cout << "F" << std::endl;
}

int main() {
	InputService::MouseService::EVENTS::MouseLeftClick.Connect(React);

	Event<void*> *EventF = InputService::KeyboardService::GetKeyPressedEvent(sf::Keyboard::Key::F);
	EventF->Connect(F);

	while (true) {
		InputService::Update();
		sf::sleep(sf::milliseconds(10));
	}
	
	return 0;
}