class Item {
private:
	std::string id, name, type;
	sf::Texture *texture;
	sf::Sprite *sprite;
public:
	std::string GetId() {
		return this->id;
	}

	std::string GetName() {
		return this->name;
	}

	std::string GetType() {
		return this->type;
	}

	sf::Sprite* GetSprite() {
		return this->sprite;
	}

	Item Clone() {;
		return Item{this->GetId(), this->GetName(), this->GetType(), this->texture};
	}

	Item(std::string id, std::string name, std::string type, sf::Texture *texture) {
		this->id = id;
		this->name = name;
		this->type = type;
		this->texture = texture;

		this->sprite = new sf::Sprite{ *this->texture };
		this->sprite->setScale(sf::Vector2f(3.0f, 3.0f));
	}
};