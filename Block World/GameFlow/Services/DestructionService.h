namespace DestructionService {
	namespace VALUES {
		namespace DESTRUCTION {
			std::vector<sf::Texture> TEXTURES;
			std::vector<sf::Sprite> SPRITES;
		}

		Block *selectedBlock = nullptr;
		double TIMER = 0;
	}

	void Init() {
		// Load Destruction Animation
		VALUES::DESTRUCTION::TEXTURES.push_back(sf::Texture{ "Content/Images/DestructionAnimation/Destruct1.png" });
		VALUES::DESTRUCTION::TEXTURES.push_back(sf::Texture{ "Content/Images/DestructionAnimation/Destruct2.png" });
		VALUES::DESTRUCTION::TEXTURES.push_back(sf::Texture{ "Content/Images/DestructionAnimation/Destruct3.png" });
		//

		// Make Sprites
		int countOfTextures = VALUES::DESTRUCTION::TEXTURES.size();
		for (int spriteIndex = 0; spriteIndex < countOfTextures; spriteIndex++) {
			sf::Texture* gettedTexture = &VALUES::DESTRUCTION::TEXTURES.at(spriteIndex);
			sf::Sprite makedSprite{ *gettedTexture };

			makedSprite.setScale(sf::Vector2f(2.5f, 2.5f));
			VALUES::DESTRUCTION::SPRITES.push_back(makedSprite);
		}
		//
	}

	void Update(double dt) {
		Block* selectedBlock = MapService::GetBlockByWorldPosition(SelectionService::GetSelectionWorldPosition());
		if (!MouseService::LeftClicked() || (selectedBlock == nullptr)) {
			VALUES::TIMER = 0;
			VALUES::selectedBlock = nullptr;
			return;
		}

		if (selectedBlock != VALUES::selectedBlock) {
			VALUES::TIMER = 0;
			VALUES::selectedBlock = selectedBlock;
		}

		VALUES::TIMER += dt;
		if ((selectedBlock->GetTimeToDestroy(0) == -1) || VALUES::TIMER < selectedBlock->GetTimeToDestroy(0)) return;

		MapService::RemoveBlockByWorldPosition(selectedBlock->GetWorldPosition());
		VALUES::TIMER = 0;
		VALUES::selectedBlock = nullptr;
	}

	sf::Sprite* GetDestructionSprite() {
		if ((VALUES::selectedBlock == nullptr) || VALUES::selectedBlock->GetTimeToDestroy(0) == -1) return nullptr;

		// Choice Texture
		double alpha = VALUES::TIMER / VALUES::selectedBlock->GetTimeToDestroy(0);
		int spriteIndex = 0;

		int countOfTextures = VALUES::DESTRUCTION::TEXTURES.size();
		double betta = (1.0 / countOfTextures);

		while (alpha - betta > 0) {
			spriteIndex += 1;
			alpha -= betta;
		}

		// Set Sprite Position
		sf::Sprite *choisedSprite
			= &VALUES::DESTRUCTION::SPRITES.at((countOfTextures < spriteIndex) ? countOfTextures : spriteIndex);

		choisedSprite->setPosition(
			WindowService::ConvertWorldPositionToPixelPosition(VALUES::selectedBlock->GetWorldPosition())
		);
		//

		return choisedSprite;
	}
}