namespace KeyboardService {
	bool KeyIsPressed(sf::Keyboard::Key key);

	namespace CLASSES {
		class KeyboardEvent {
		public:
			bool wasPressed = false;
			sf::Keyboard::Key key;
			Event<void*> *event = new Event<void*>;

			KeyboardEvent(sf::Keyboard::Key key) {
				this->key = key;
			}
		};
	}

	namespace CONSTS {
		std::vector<CLASSES::KeyboardEvent*> storage;
	}

	void Update() {
		int countOfElements = CONSTS::storage.size();
		for (int index = 0; index < countOfElements; index++) {
			CLASSES::KeyboardEvent *KE = CONSTS::storage.at(index);

			if (KeyIsPressed(KE->key) && (!KE->wasPressed)) {
				KE->wasPressed = true;
				KE->event->Call(nullptr);
			}
			else if ((!KeyIsPressed(KE->key) && (KE->wasPressed))) {
				KE->wasPressed = false;
			}
		}
	}

	Event<void*>* GetKeyPressedEvent(sf::Keyboard::Key key) {
		int countOfElements = CONSTS::storage.size();

		for (int index = 0; index < countOfElements; index++) {
			CLASSES::KeyboardEvent *KE = CONSTS::storage.at(index);
			if (KE->key != key) continue;
			return KE->event;
		}

		CLASSES::KeyboardEvent *KE = new CLASSES::KeyboardEvent(key);
		CONSTS::storage.push_back(KE);
		return KE->event;
	}

	bool KeyIsPressed(sf::Keyboard::Key key) {
		return sf::Keyboard::isKeyPressed(key);
	}
}