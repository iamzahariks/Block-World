namespace InventoryService {
	void SetNextItem(int settedItem);
	void ToNextItem();
	void ToLastItem();
	void SetItem1(void*) { SetNextItem(0); }
	void SetItem2(void*) { SetNextItem(1); }
	void SetItem3(void*) { SetNextItem(2); }

	void Scroll(int delta) {
		if (delta == 1) {
			ToNextItem();
		}
		else {
			ToLastItem();
		}
	}

	namespace CLASSES {
		class InventoryItem {
		private:
			sf::Texture* backgroundTexture;
			sf::Sprite* backgroundSprite;

			sf::Font* font;
			sf::Text* countText;
			sf::Text* itemNameText;
		public:
			Item* item;
			int count;

			sf::Text* GetCountText() {
				return this->countText;
			}

			sf::Text* GetItemNameText() {
				return this->itemNameText;
			}

			sf::Sprite* GetBackgroundSprite() {
				return this->backgroundSprite;
			}

			InventoryItem(Item* item, int count, sf::Texture* backTexture, sf::Font* font) {
				this->item = item;
				this->count = count;

				this->backgroundTexture = backTexture;
				this->backgroundSprite = new sf::Sprite(*this->backgroundTexture);
				this->backgroundSprite->setScale(sf::Vector2f(3.f, 3.f));

				this->font = font;
				this->countText = new sf::Text{ *this->font };
				this->countText->setFillColor(sf::Color::White);
			}
		};
	}

	int CHOISED_SLOT = 0;
	sf::Texture SLOT_TEXTURE{ "Content/Images/InventorySlot.png" };
	std::vector<CLASSES::InventoryItem> USER_INVENTORY;

	sf::Font FONT{"Content/Fonts/FredokaOne-Regular.ttf"};

	void Init() {
		KeyboardService::GetKeyPressedEvent(sf::Keyboard::Key::Num1)->Connect(SetItem1);
		KeyboardService::GetKeyPressedEvent(sf::Keyboard::Key::Num2)->Connect(SetItem2);
		KeyboardService::GetKeyPressedEvent(sf::Keyboard::Key::Num3)->Connect(SetItem3);

		MouseService::EVENTS::WheelScrolled.Connect(Scroll);
	}

	void SetNextItem(int settedItem) {
		int countItems = USER_INVENTORY.size();

		if (countItems == 0) {
			CHOISED_SLOT = 0;
			return;
		}

		CHOISED_SLOT = settedItem;
		CHOISED_SLOT = (CHOISED_SLOT >= countItems) ? 0 : ((CHOISED_SLOT < 0) ? (countItems-1) : CHOISED_SLOT);
	}

	void ToNextItem() {
		SetNextItem(CHOISED_SLOT + 1);
	}

	void ToLastItem() {
		SetNextItem(CHOISED_SLOT - 1);
	}

	CLASSES::InventoryItem* GetItemBySlot() {
		if (USER_INVENTORY.size() == 0) return nullptr;
		return &USER_INVENTORY.at(CHOISED_SLOT);
	}

	void AddItem(Item* item, int count = 1) {
		int countItems = USER_INVENTORY.size();
		for (int i = 0; i < countItems; i++) {
			CLASSES::InventoryItem*invItem = &USER_INVENTORY.at(i);
			if (item->GetId() != invItem->item->GetId()) continue;
			
			invItem->count += count;
			return;
		}

		CLASSES::InventoryItem invItem{ item->Clone(), count, &SLOT_TEXTURE, &FONT };
		USER_INVENTORY.push_back(invItem);
	}

	void RemoveItem(Item* item, int count = 1) {
		int countItems = USER_INVENTORY.size();
		for (int i = 0; i < countItems; i++) {
			CLASSES::InventoryItem* invItem = &USER_INVENTORY.at(i);
			if (item->GetId() != invItem->item->GetId()) continue;

			invItem->count = (invItem->count - count < 0) ? 0 : (invItem->count - count);
			if (invItem->count == 0) {
				USER_INVENTORY.erase(USER_INVENTORY.begin() + i);
				ToLastItem();
			}

			return;
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