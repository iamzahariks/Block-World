#include <iostream>
#include "Content/RootInitializer.h"
#include "GameFlow/RootInitializer.h"

int main() {
	Content::Init();
	GameFlow::Init();

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
		}

		if (!WindowService::GAME_WINDOW.hasFocus()) continue;

		// Update Root Parts
		MouseService::Update();
		KeyboardService::Update();
		//
		
		// Update Other Parts
		GameFlow::Update(dt);
		//

		WindowService::Clear();
		WindowService::GAME_WINDOW.draw(WindowService::BACKGROUND_SPRITE);

		int countOfElements = MapService::CONSTS::BLOCKS.size();
		for (int i = 0; i < countOfElements; i++) {
			Block block = MapService::CONSTS::BLOCKS.at(i);
			block.GetSprite()->setPosition(WindowService::ConvertWorldPositionToPixelPosition(block.GetWorldPosition()));
			WindowService::GAME_WINDOW.draw(*block.GetSprite());
		}

		if (GameFlow::DestructionService::GetDestructionSprite() != nullptr) {
			WindowService::GAME_WINDOW.draw(*GameFlow::DestructionService::GetDestructionSprite());
		}

		WindowService::GAME_WINDOW.draw(*GameFlow::SelectionService::GetSelectionSprite());
		WindowService::GAME_WINDOW.draw(WindowService::CURSORE);

		WindowService::Display();
	}

	return 0;
}