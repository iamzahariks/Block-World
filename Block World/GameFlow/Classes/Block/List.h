namespace Blocks {
	Block* GetBlockById(std::string id);
	void AddBlockInList(std::string id, std::string name, int breakLevel, float breakTime);
	bool BlockExist(std::string id);

	std::map<std::string, Block> storage;

	void Init() {
		AddBlockInList("Grass", "Grass", 0, 1.0);
		AddBlockInList("Dirt", "Dirt", 0, 1.0);
		AddBlockInList("Stone", "Stone", 0, 2.0);
		AddBlockInList("Barrier", "Barrier", -1, 1.0);
		AddBlockInList("Bedrock", "Bedrock", -1, 1.0);
	}

	Block* GetBlockById(std::string id) {
		auto blockInfo = storage.find(id);
		return (blockInfo != storage.end()) ? &(blockInfo->second) : nullptr;
	}

	void AddBlockInList(std::string id, std::string name, int breakLevel, float breakTime) {
		auto blockInfo = storage.find(id);

		if (blockInfo != storage.end()) {
			throw std::runtime_error("Block ID was identical! ID: "+id);
			return;
		}

		storage.insert(std::make_pair(id, Block{ id, name, breakLevel, breakTime }));
	}

	bool BlockExist(std::string id) {
		auto blockInfo = storage.find(id);
		if (blockInfo != storage.end()) return true;
		return false;
	}
}