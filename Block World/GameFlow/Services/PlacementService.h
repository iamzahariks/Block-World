namespace PlacementService {
	bool PlaceBlock(Block* block, sf::Vector2i worldPosition, bool removeFromInventory = true);

	void MouseRightClickToPlace(sf::Vector2i mousePosition) {
		InventoryService::CLASSES::InventoryItem* invItem = InventoryService::GetItemBySlot();
		if ((invItem == nullptr) || (invItem->item->GetType() != "Block")) return;

		Block* foundedBlock = BlockService::GetBlockById(invItem->item->GetId());
		if (foundedBlock == nullptr) return;

		PlaceBlock(foundedBlock, SelectionService::GetSelectionWorldPosition(), true);
	}

	void Init() {
		MouseService::EVENTS::MouseRightClick.Connect(MouseRightClickToPlace);
	}

	bool PlaceBlock(Block* block, sf::Vector2i worldPosition, bool removeFromInventory) {
		if (removeFromInventory) {
			if (InventoryService::FindItemById(block->GetID()) == nullptr) return false;
		}

		bool status = MapService::AddBlock(block, worldPosition, false);

		if ((!status) || (!removeFromInventory)) return false;
		InventoryService::RemoveItem(InventoryService::FindItemById(block->GetID())->item, 1);
	}
}