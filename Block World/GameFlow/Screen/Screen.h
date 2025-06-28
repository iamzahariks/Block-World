#include "../Libraries.h"

class Screen {
private: 
	sf::Window window;
	std::string title;
	int fps;
public:
	void SetTitle(std::string newTitle) {
		title = this->title;
		window.setTitle(this->title);
	}

	std::string GetTitle() {
		return this->title;
	}

	void SetFPS(int fps) {
		this->fps = fps;
		window.setFramerateLimit(this->fps);
	}

	int GetFPS() {
		return fps;
	}

	Screen(std::string title, int fps) {
		this->title = title;
		this->fps = fps;
	}
};