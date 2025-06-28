#include <iostream>
#include "Content/RootInitializer.h"

int main() {
	Content::Init();

	sf::RenderWindow window(sf::VideoMode({ 1000, 800 }), "Block World", sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	std::vector<Block> blocks;
	for (int i = 0; i < 25; i++) {
		sf::Vector2f pos(i * 40, 760);

		Block gettedBlock = BlockService::GetBlockById("Stone")->Clone();
		gettedBlock.SetPosition(pos);

		blocks.push_back(gettedBlock);
	}

	for (int i = 0; i < 25; i++) {
		sf::Vector2f pos(i * 40, 720);

		Block gettedBlock = BlockService::GetBlockById("Dirt")->Clone();
		gettedBlock.SetPosition(pos);

		blocks.push_back(gettedBlock);
	}

	for (int i = 0; i < 25; i++) {
		sf::Vector2f pos(i * 40, 680);

		Block gettedBlock = BlockService::GetBlockById("Grass")->Clone();
		gettedBlock.SetPosition(pos);

		blocks.push_back(gettedBlock);
	}

	while (window.isOpen()) {
		std::cout << window.getSize().x << ' ' << window.getSize().y << std::endl;

		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();

		int count = blocks.size();
		for (int i = 0; i < count; i++) {
			window.draw(*blocks.at(i).GetSprite());
		}

		window.display();
	}

	return 0;
}