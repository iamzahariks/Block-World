template <typename T>
class Event {
public:
	// Event Connector
	class EventConnector {
	private:
		Event* root;
		int id;
	public:
		void (*func)(T);

		int GetID() {
			return this->id;
		}

		void Disconnect() {
			this->root->Disconnect(this->id);
			free(this);
		}

		EventConnector(Event* root, void(*func)(T), int ID) {
			this->root = root;
			this->func = func;
			this->id = ID;
		}
	};
	//

	void Disconnect(int ID) {
		auto info = this->storage.find(ID);
		this->storage.erase(info);
	}

	void Call(T info) {
		for (auto conn : this->storage) {
			conn.second->func(info);
		}
	}

	EventConnector* Connect(void(*func)(T)) {
		EventConnector* newConnector = new EventConnector{ this, func, this->GetID() };
		storage.insert(std::make_pair(newConnector->GetID(), newConnector));
		return newConnector;
	}
private:
	int id;
	std::map<int, EventConnector*> storage;

	int GetID() {
		return ++(this->id);
	}
};