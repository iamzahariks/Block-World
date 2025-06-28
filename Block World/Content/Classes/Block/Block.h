class Block {
private:
	std::string id, name;
	int breakLevel;
	float breakTime;
public:
	float GetTimeToDestroy(int userBreakLevel) {
		if ((this->GetBreakLevel() == -1) || (this->GetBreakTime() == -1)) return -1.0;
		if (userBreakLevel < this->GetBreakLevel()) return -1.0;
		return  breakTime / (float)(userBreakLevel - this->GetBreakLevel() + 1);
	}

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

	Block Clone() {
		Block newBlock{ this->GetID(), this->GetName(), this->GetBreakLevel(), this->GetBreakTime()};
		return newBlock;
	}

	Block(std::string id, std::string name, int breakLevel, float breakTime) {
		this->id = id;
		this->name = name;
		this->breakLevel = breakLevel;
		this->breakTime = breakTime;
	}
};