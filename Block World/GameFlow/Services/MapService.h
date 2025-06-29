namespace MapService {
	bool AddBlock(Block* block, sf::Vector2i worldPosition = sf::Vector2i{ 0, 0 }, bool ignoreNeighboors = true);
	bool RemoveBlockByWorldPosition(sf::Vector2i worldPosition);
	Block* GetBlockByWorldPosition(sf::Vector2i worldPosition);

	namespace CONSTS {
		std::vector<Block> BLOCKS;
	}
	
	// CREATE MAP
	void Init() {
		sf::Vector2i WorldSize = WindowService::GetWorldSize();

		// Make Bedrock
		for (int x = 0; x < WorldSize.x; x++) {
			Block* bedrock = BlockService::GetBlockById("Bedrock");
			AddBlock(bedrock, sf::Vector2i(x, 0));
		}
		//

		//Make Stone
		for (int y = 1; y <= 5; y++) {
			for (int x = 0; x < WorldSize.x; x++) {
				Block* stone = BlockService::GetBlockById("Stone");
				AddBlock(stone, sf::Vector2i(x, y));
			}
		}
		

		// Make Dirt
		for (int y = 6; y <= 7; y++) {
			for (int x = 0; x < WorldSize.x; x++) {
				Block* dirt = BlockService::GetBlockById("Dirt");
				AddBlock(dirt, sf::Vector2i(x, y));
			}
		}
		//

		// Make Grass
		for (int y = 8; y <= 8; y++) {
			for (int x = 0; x < WorldSize.x; x++) {
				Block* grass = BlockService::GetBlockById("Grass");
				AddBlock(grass, sf::Vector2i(x, y));
			}
		}
		//
	}
	//

	bool AddBlock(Block *block, sf::Vector2i worldPosition, bool ignoreNeighboors) {
		Block myBlock = block->Clone();
		myBlock.SetWorldPosition(worldPosition);

		// Check Position
		if (GetBlockByWorldPosition(worldPosition) != nullptr) return false;
		//

		// Found Neighboor
		if (!ignoreNeighboors) {
			bool neighboorWasFounded = false;
			for (int x = -1; x <= 1; x += 2) {
				if (neighboorWasFounded) break;
				for (int y = -1; y <= 1; y += 2) {
					if (GetBlockByWorldPosition(sf::Vector2i(worldPosition.x + x, worldPosition.y + y)) != nullptr) {
						neighboorWasFounded = true;
						break;
					}
				}
			}

			if (neighboorWasFounded) return false;
		}
		//

		CONSTS::BLOCKS.push_back(myBlock);
	}

	bool RemoveBlockByWorldPosition(sf::Vector2i worldPosition) {
		int countBlocks = CONSTS::BLOCKS.size();
		for (int i = 0; i < countBlocks; i++) {
			Block gettedBlock = CONSTS::BLOCKS.at(i);

			if ((gettedBlock.GetWorldPosition().x != worldPosition.x) ||
				(gettedBlock.GetWorldPosition().y != worldPosition.y)) {
				continue;
			}

			CONSTS::BLOCKS.erase(CONSTS::BLOCKS.begin() + i);
			return true;
		}

		return false;
	}

	Block* GetBlockByWorldPosition(sf::Vector2i worldPosition) {
		int countBlocks = CONSTS::BLOCKS.size();
		for (int i = 0; i < countBlocks; i++) {
			Block gettedBlock = CONSTS::BLOCKS.at(i);

			if ((gettedBlock.GetWorldPosition().x != worldPosition.x) ||
				(gettedBlock.GetWorldPosition().y != worldPosition.y)) {
				continue;
			}

			return &gettedBlock;
		}
		return nullptr;
	}
}