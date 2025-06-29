#include <iostream>
#include "Content/RootInitializer.h"
#include "GameFlow/RootInitializer.h"

int main() {
	Content::Init();
	GameFlow::Init();

	while (WindowService::GAME_WINDOW.isOpen()) {
		while (const std::optional event = WindowService::GAME_WINDOW.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				WindowService::GAME_WINDOW.close();
		}

		WindowService::Clear();
		WindowService::GAME_WINDOW.draw(WindowService::BACKGROUND_SPRITE);

		int countOfElements = MapService::CONSTS::BLOCKS.size();
		for (int i = 0; i < countOfElements; i++) {
			Block block = MapService::CONSTS::BLOCKS.at(i);
			block.GetSprite()->setPosition(WindowService::ConvertWorldPositionToPixelPosition(block.GetWorldPosition()));
			WindowService::GAME_WINDOW.draw(*block.GetSprite());
		}

		WindowService::Display();
	}

	return 0;
}