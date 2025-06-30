namespace InventoryService {
	namespace CLASSES {
		class InventoryItem {
		private:
			sf::Texture* texture;
		public:
			Item* item;
			int count;

			sf::Sprite* sprite;
			sf::Sprite* GetSprite() {
				return this->sprite;
			}

			InventoryItem(Item* item, int count, sf::Texture* texture) {
				this->item = item;
				this->count = count;

				this->texture = texture;
				this->sprite = new sf::Sprite{ *this->texture };
			}
		};
	}

	int CHOISED_SLOT = 0;
	sf::Texture SLOT_TEXTURE{ "Content/Images/InventorySlot.png" };
	std::vector<CLASSES::InventoryItem> USER_INVENTORY;

	void ToNextItem() {
		CHOISED_SLOT += 1;
		CHOISED_SLOT = (CHOISED_SLOT > USER_INVENTORY.size()) ? 0 : CHOISED_SLOT;
	}

	void ToLastItem() {
		CHOISED_SLOT -= 1;
		CHOISED_SLOT = (CHOISED_SLOT < 0) ? USER_INVENTORY.size() : CHOISED_SLOT;
	}

	CLASSES::InventoryItem* GetItemBySlot() {
		if (USER_INVENTORY.size() == 0) return nullptr;
		return &USER_INVENTORY.at(CHOISED_SLOT);
	}

	void AddItem(Item* item, int count = 1) {
		int countItems = USER_INVENTORY.size();
		for (int i = 0; i < countItems; i++) {
			CLASSES::InventoryItem*invItem = &USER_INVENTORY.at(i);
			if (item != invItem->item) continue;
			
			invItem->count += count;
			return;
		}

		CLASSES::InventoryItem invItem{ item, count, &SLOT_TEXTURE };
		USER_INVENTORY.push_back(invItem);
	}

	void RemoveItem(Item* item, int count = 1) {
		int countItems = USER_INVENTORY.size();
		for (int i = 0; i < countItems; i++) {
			CLASSES::InventoryItem* invItem = &USER_INVENTORY.at(i);
			if (item != invItem->item) continue;

			invItem->count = (invItem->count - count < 0) ? 0 : (invItem->count - count);
			if (invItem->count == 0) {
				if (CHOISED_SLOT == i) { ToLastItem(); }

				USER_INVENTORY.erase(USER_INVENTORY.begin() + i);
			}

			break;
		}
	}

	CLASSES::InventoryItem* FindItemById(std::string id) {
		int countItems = USER_INVENTORY.size();
		for (int i = 0; i < countItems; i++) {
			CLASSES::InventoryItem* invItem = &USER_INVENTORY.at(i);
			if (id != invItem->item->GetId()) continue;
			return invItem;
		}

		return nullptr;
	}

	CLASSES::InventoryItem* FindItem(Item* item) {
		int countItems = USER_INVENTORY.size();
		for (int i = 0; i < countItems; i++) {
			CLASSES::InventoryItem* invItem = &USER_INVENTORY.at(i);
			if (item != invItem->item) continue;
			return invItem;
		}

		return nullptr;
	}
}