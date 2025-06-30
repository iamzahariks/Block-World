namespace ItemsService {
	Item* GetItemById(std::string id);
	void AddItemInList(std::string id, std::string name, std::string type, sf::Texture* texture);
	std::map<std::string, Item> storage;

	void Init() {
		AddItemInList("Grass", "Grass", "Block", new sf::Texture{ "Content/Classes/Block/Textures/Grass.png" });
		AddItemInList("Dirt", "Dirt", "Block", new sf::Texture{ "Content/Classes/Block/Textures/Dirt.png" });
		AddItemInList("Stone", "Stone", "Block", new sf::Texture{ "Content/Classes/Block/Textures/Stone.png" });
		AddItemInList("Bedrock", "Bedrock", "Block", new sf::Texture{ "Content/Classes/Block/Textures/Bedrock.png" });
	}

	void AddItemInList(std::string id, std::string name, std::string type, sf::Texture *texture) {
		storage.insert(std::make_pair(id, Item{ id, name, type, texture }));
	}

	Item* GetItemById(std::string id) {
		auto blockInfo = storage.find(id);
		return (blockInfo != storage.end()) ? &(blockInfo->second) : nullptr;
	}
}