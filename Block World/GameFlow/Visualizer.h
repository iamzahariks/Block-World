namespace Visualizer {
	void VisualizeBlocks();
	void VisualizeInventory();
	void MakeInventorySlot(InventoryService::CLASSES::InventoryItem* invItem, sf::Vector2f position);

	void Visualize() {
		WindowService::Clear();

		// Background
		WindowService::GAME_WINDOW.draw(WindowService::BACKGROUND_SPRITE);
		//

		// Blocks
		VisualizeBlocks();

		if (GameFlow::DestructionService::GetDestructionSprite() != nullptr) {
			WindowService::GAME_WINDOW.draw(*GameFlow::DestructionService::GetDestructionSprite());
		}

		WindowService::GAME_WINDOW.draw(*GameFlow::SelectionService::GetSelectionSprite());
		//

		// Interface
		VisualizeInventory();
		//

		WindowService::GAME_WINDOW.draw(WindowService::CURSORE);
		WindowService::Display();
	}

	void VisualizeBlocks() {
		int countOfElements = MapService::CONSTS::BLOCKS.size();
		for (int i = 0; i < countOfElements; i++) {
			Block *block = &MapService::CONSTS::BLOCKS.at(i);
			sf::Vector2f worldPosition = WindowService::ConvertWorldPositionToPixelPosition(block->GetWorldPosition());

			block->GetSprite()->setPosition(worldPosition);
			WindowService::GAME_WINDOW.draw(*block->GetSprite());
		}
	}

	void VisualizeInventory() {
		int countItems = InventoryService::USER_INVENTORY.size();
		if (countItems == 0) return;
		
		// Visualize when items equal 1
		if (countItems == 1) {
			MakeInventorySlot(&InventoryService::USER_INVENTORY.at(0), sf::Vector2f(452, 700));
			return;
		}
		else if (countItems == 2) {
			MakeInventorySlot(&InventoryService::USER_INVENTORY.at(0), sf::Vector2f(352, 700));
			MakeInventorySlot(&InventoryService::USER_INVENTORY.at(1), sf::Vector2f(600, 700));
		}
		else if (countItems == 3) {
			MakeInventorySlot(&InventoryService::USER_INVENTORY.at(0), sf::Vector2f(302, 700));
			MakeInventorySlot(&InventoryService::USER_INVENTORY.at(1), sf::Vector2f(452, 700));
			MakeInventorySlot(&InventoryService::USER_INVENTORY.at(2), sf::Vector2f(602, 700));
		}
		//
	}

	void MakeInventorySlot(InventoryService::CLASSES::InventoryItem *invItem, sf::Vector2f position) {
		invItem->GetBackgroundSprite()->setPosition(position);
		invItem->item->GetSprite()->setPosition(position + sf::Vector2f(24, 24));

		WindowService::GAME_WINDOW.draw(*invItem->GetBackgroundSprite());
		WindowService::GAME_WINDOW.draw(*invItem->item->GetSprite());

		invItem->GetCountText()->setString(std::to_string(invItem->count));
		invItem->GetCountText()->setPosition(position - sf::Vector2f(0, 15));

		if (InventoryService::GetItemBySlot() == invItem) {
			invItem->GetCountText()->setFillColor(sf::Color::Red);
		}
		else {
			invItem->GetCountText()->setFillColor(sf::Color::White);
		}

		WindowService::GAME_WINDOW.draw(*invItem->GetCountText());
	}
} 