namespace BlockService {
	Block* GetBlockById(std::string id);
	void AddBlockInList(std::string id, std::string name, int breakLevel, float breakTime, sf::Texture *texture);
	bool BlockExist(std::string id);

	std::map<std::string, Block> storage;

	void Init() {
		AddBlockInList("Grass", "Grass", 0, 1.0, new sf::Texture{"Content/Classes/Block/Textures/Grass.png"});
		AddBlockInList("Dirt", "Dirt", 0, 1.0, new sf::Texture{ "Content/Classes/Block/Textures/Dirt.png" });
		AddBlockInList("Stone", "Stone", 0, 2.0, new sf::Texture{ "Content/Classes/Block/Textures/Stone.png" });
		AddBlockInList("Bedrock", "Bedrock", -1, 1.0, new sf::Texture{ "Content/Classes/Block/Textures/Bedrock.png" });
	}

	Block* GetBlockById(std::string id) {
		auto blockInfo = storage.find(id);
		return (blockInfo != storage.end()) ? &(blockInfo->second) : nullptr;
	}

	void AddBlockInList(std::string id, std::string name, int breakLevel, float breakTime, sf::Texture *texture) {
		auto blockInfo = storage.find(id);

		if (blockInfo != storage.end()) {
			throw std::runtime_error("Block ID was identical! ID: "+id);
			return;
		}

		storage.insert(std::make_pair(id, Block{ id, name, breakLevel, breakTime, texture }));
	}

	bool BlockExist(std::string id) {
		auto blockInfo = storage.find(id);
		if (blockInfo != storage.end()) return true;
		return false;
	}
}