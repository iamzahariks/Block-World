#include <iostream>
#include "Content/RootInitializer.h"
#include "GameFlow/RootInitializer.h"
#include "GameFlow/Visualizer.h"

int main() {
	Content::Init();
	GameFlow::Init();

	system("cls");
	clock_t START_TIME = clock();
	while (WindowService::GAME_WINDOW.isOpen()) {
		// DELTA TIME
		clock_t NOW_TIME = clock();
		double dt = (double)(NOW_TIME - START_TIME) / CLOCKS_PER_SEC;
		START_TIME = NOW_TIME;
		//

		while (const std::optional event = WindowService::GAME_WINDOW.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				WindowService::GAME_WINDOW.close();
			else if (const auto* wheelScrolled = event->getIf<sf::Event::MouseWheelScrolled>()) {
				if (WindowService::GAME_WINDOW.hasFocus()) {
					if (wheelScrolled->delta == 1) {
						MouseService::EVENTS::WheelScrolled.Call(1);
					}
					else {
						MouseService::EVENTS::WheelScrolled.Call(-1);
					}
				}
			}
		}

		if (!WindowService::GAME_WINDOW.hasFocus()) continue;

		// Update Root Parts
		MouseService::Update();
		KeyboardService::Update();
		//
		
		// Update Other Parts
		GameFlow::Update(dt);
		//

		// Visualize Interface
		Visualizer::Visualize();
		//
	}

	return 0;
}