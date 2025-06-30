class Block {
private:
	std::string id, name;
	int breakLevel;
	float breakTime;

	sf::Texture *texture;
	sf::Sprite *sprite;
	sf::Vector2i worldPosition;
public:
	float GetTimeToDestroy(int userBreakLevel) {
		if ((this->GetBreakLevel() == -1) || (this->GetBreakTime() == -1)) return -1.0;
		if (userBreakLevel < this->GetBreakLevel()) return -1.0;
		return this->breakTime / (float)(userBreakLevel - this->GetBreakLevel() + 1);
	}

	// Block Information
	std::string GetID() {
		return this->id;
	}

	std::string GetName() {
		return this->name;
	}
	
	int GetBreakLevel() {
		return this->breakLevel;
	}

	float GetBreakTime() {
		return this->breakTime;
	}
	//

	// Positions
	void SetWorldPosition(sf::Vector2i newPosition) {
		this->worldPosition = newPosition;
	}

	sf::Vector2i GetWorldPosition() {
		return this->worldPosition; 
	}
	//

	// Sprites
	sf::Sprite* GetSprite() {
		return this->sprite;
	}

	Block Clone() {
		Block newBlock{ this->GetID(), this->GetName(), this->GetBreakLevel(), this->GetBreakTime(), this->texture};
		return newBlock;
	}
	//

	Block(std::string id, std::string name, int breakLevel, float breakTime, sf::Texture *texture) {
		this->id = id;
		this->name = name;
		this->breakLevel = breakLevel;
		this->breakTime = breakTime;

		this->texture = texture;
		this->sprite = new sf::Sprite(*this->texture);
		this->sprite->setScale(sf::Vector2f(2.5f, 2.5f));
	}
};