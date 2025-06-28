#include "../../Block World/GameFlow/Libraries.h"

template <typename T>
class Connector {
	void(*func)(T);

	void Disconnect() {
		delete this;
	}

	Connector(void(*func)(T)) {
		this->func = func;
	}
};

template <template <typename> class Connector, typename T>
class Event {
private:
	int id;
	std::map<int, Connector> storage;

	int GetID() {
		return ++(this->id);
	}
public:
	void Disconnect(Connector oldConnector) {
		int id = oldConnector.id;
		storage.find(id);
	}

	void Call(T info) {
		for (auto conn : this->storage) {
			conn.second->func(info);
		}
	}

	Connector Connect(void(*func)(T)) {
		int id = this->GetID();
		Connector newConnector = new Connector(func);
		storage.insert(id, newConnector);
		return newConnector;
	}
};
