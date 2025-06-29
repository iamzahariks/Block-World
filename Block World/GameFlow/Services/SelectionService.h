namespace SelectionService {
	namespace VALUES {
		namespace CHOICE_ANIMATION {
			int SPRITE_NOW = 0;
			double ANIM_LENGTH = 0.05, ANIM_TIMER = 0;
			std::vector<sf::Texture> TEXTURES;
			std::vector<sf::Sprite> SPRITES;
		}

		sf::Vector2i MOUSE_WORLD_POSITION{ 0, 0 };
	}

	void Init() {
		// Load Selection Animation
		VALUES::CHOICE_ANIMATION::TEXTURES.push_back(sf::Texture{ "Content/Images/SelectionAnimation/Select1.png" });
		VALUES::CHOICE_ANIMATION::TEXTURES.push_back(sf::Texture{ "Content/Images/SelectionAnimation/Select2.png" });
		VALUES::CHOICE_ANIMATION::TEXTURES.push_back(sf::Texture{ "Content/Images/SelectionAnimation/Select3.png" });
		//

		// Make Sprites
		int countOfTextures = VALUES::CHOICE_ANIMATION::TEXTURES.size();
		for (int spriteIndex = 0; spriteIndex < countOfTextures; spriteIndex++) {
			sf::Texture *gettedTexture = &VALUES::CHOICE_ANIMATION::TEXTURES.at(spriteIndex);
			sf::Sprite makedSprite{ *gettedTexture };

			makedSprite.setScale(sf::Vector2f(2.5f, 2.5f));
			VALUES::CHOICE_ANIMATION::SPRITES.push_back(makedSprite);
		}
		//
	}

	void Update(double dt) {
		sf::Vector2i mousePosition = 
			MouseService::GetMousePosition() - WindowService::GAME_WINDOW.getPosition() - sf::Vector2i(7, 30);

		// Save World Position
		VALUES::MOUSE_WORLD_POSITION = WindowService::GetWorldPositionByPixelPosition(
			sf::Vector2f(mousePosition.x, mousePosition.y)
		);
		//

		// Update Animation Timer
		VALUES::CHOICE_ANIMATION::ANIM_TIMER += dt;
		if (VALUES::CHOICE_ANIMATION::ANIM_TIMER >= VALUES::CHOICE_ANIMATION::ANIM_LENGTH) {
			VALUES::CHOICE_ANIMATION::ANIM_TIMER = 0;

			VALUES::CHOICE_ANIMATION::SPRITE_NOW += 1;
			VALUES::CHOICE_ANIMATION::SPRITE_NOW %= VALUES::CHOICE_ANIMATION::TEXTURES.size();
		}
	}

	sf::Vector2i GetSelectionWorldPosition() {
		return VALUES::MOUSE_WORLD_POSITION;
	}

	sf::Sprite* GetSelectionSprite() {
		sf::Sprite* gettedSprite = &VALUES::CHOICE_ANIMATION::SPRITES.at(VALUES::CHOICE_ANIMATION::SPRITE_NOW);
		gettedSprite->setPosition(WindowService::ConvertWorldPositionToPixelPosition(VALUES::MOUSE_WORLD_POSITION));
		return gettedSprite;
	}
}