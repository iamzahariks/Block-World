namespace SelectionService {
	namespace OBJECTS {
		sf::Texture CHOICE_TEXTURE{ "Content/Images/Choice.png" };
		sf::Sprite CHOICE_SPRITE{ CHOICE_TEXTURE };
	}

	sf::Vector2i MOUSE_WORLD_POSITION{ 0, 0 };

	void InsertBlock(sf::Vector2i) {
		std::cout << "PLACE" << std::endl;
		MapService::AddBlock(BlockService::GetBlockById("Grass"), MOUSE_WORLD_POSITION, false);
	}

	void Init() {
		OBJECTS::CHOICE_SPRITE.setScale(sf::Vector2f(2.5f, 2.5f));
		MouseService::EVENTS::MouseRightClick.Connect(InsertBlock);
	}

	void Update() {
		sf::Vector2i mousePosition = MouseService::GetMousePosition() - WindowService::GAME_WINDOW.getPosition() - sf::Vector2i(7, 30);

		MOUSE_WORLD_POSITION = WindowService::GetWorldPositionByPixelPosition(
			sf::Vector2f(mousePosition.x, mousePosition.y)
		);
		OBJECTS::CHOICE_SPRITE.setPosition(WindowService::ConvertWorldPositionToPixelPosition(MOUSE_WORLD_POSITION));
	}

	sf::Sprite* GetSprite() {
		return &OBJECTS::CHOICE_SPRITE;
	}
}