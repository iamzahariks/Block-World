namespace WindowService {
	sf::Vector2f ConvertWorldPositionToPixelPosition(sf::Vector2i worldPosition);
	sf::Vector2i GetWorldPositionByPixelPosition(sf::Vector2f pixelPosition);
	sf::Vector2i GetWorldSize();

	int BLOCK_SIZE = 40;
	sf::Vector2i WINDOW_PIXEL_SIZE{ 1000, 800 };

	sf::RenderWindow GAME_WINDOW(sf::VideoMode({ 1000, 800 }),
		"Block World", sf::Style::Close);

	sf::Texture BACKGROUND_TEXTURE { "Content/Images/Background.png" };
	sf::Sprite BACKGROUND_SPRITE { BACKGROUND_TEXTURE };

	sf::FloatRect WINDOW_BOUNDS{ sf::Vector2f(0.f,0.f), GAME_WINDOW.getDefaultView().getSize() };

	// Clear
	void Clear() {
		GAME_WINDOW.clear();
	}
	//

	// Display
	void Display() {
		GAME_WINDOW.display();
	}
	//

	sf::Vector2f ConvertWorldPositionToPixelPosition(sf::Vector2i worldPosition) {
		sf::Vector2i worldSize = GetWorldSize();
		return sf::Vector2f(worldPosition.x * BLOCK_SIZE, WINDOW_PIXEL_SIZE.y - worldPosition.y * BLOCK_SIZE);
	}

	sf::Vector2i GetWorldPositionByPixelPosition(sf::Vector2f pixelPosition) {
		int x = pixelPosition.x / BLOCK_SIZE;
		int y = pixelPosition.y / BLOCK_SIZE;

		sf::Vector2i worldSize = GetWorldSize();
		return sf::Vector2i(x, worldSize.y - y);
	}

	sf::Vector2i GetWorldSize() {
		return sf::Vector2i(WINDOW_PIXEL_SIZE.x / BLOCK_SIZE, WINDOW_PIXEL_SIZE.y / BLOCK_SIZE);
	}
}