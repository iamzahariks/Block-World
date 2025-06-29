namespace MouseService {
	sf::Vector2i GetMousePosition();
	bool LeftClicked();
	bool RightClicked();
	bool WheelClicked();

	namespace EVENTS {
		Event<sf::Vector2i> MouseMoved;
		Event<sf::Vector2i> MouseLeftClick;
		Event<sf::Vector2i> MouseRightClick;
		Event<sf::Vector2i> WheelClicked;
	}

	namespace CONSTS {
		sf::Vector2i MOUSE_LAST_POS = GetMousePosition();
		bool LEFT_WAS_CLICKED = false;
		bool RIGHT_WAS_CLICKED = false;
		bool WHEEL_WAS_CLICKED = false;
	}

	void Update() {
		// Check Move
		sf::Vector2i gettedNowPos = GetMousePosition();
		if ((gettedNowPos.x - CONSTS::MOUSE_LAST_POS.x != 0) || (gettedNowPos.y - CONSTS::MOUSE_LAST_POS.y != 0)) {
			EVENTS::MouseMoved.Call(sf::Vector2i(
				gettedNowPos.x - CONSTS::MOUSE_LAST_POS.x,
				gettedNowPos.y - CONSTS::MOUSE_LAST_POS.y
			));

			CONSTS::MOUSE_LAST_POS = gettedNowPos;
		}
		//

		// Check Left
		if (LeftClicked() && (!CONSTS::LEFT_WAS_CLICKED)) {
			EVENTS::MouseLeftClick.Call(GetMousePosition());
			CONSTS::LEFT_WAS_CLICKED = true;
		}
		else if ((!LeftClicked()) && (CONSTS::LEFT_WAS_CLICKED)) {
			CONSTS::LEFT_WAS_CLICKED = false;
		}
		//

		// Check Right
		if (RightClicked() && (!CONSTS::RIGHT_WAS_CLICKED)) {
			EVENTS::MouseRightClick.Call(GetMousePosition());
			CONSTS::RIGHT_WAS_CLICKED = true;
		}
		else if ((!RightClicked()) && (CONSTS::RIGHT_WAS_CLICKED)) {
			CONSTS::RIGHT_WAS_CLICKED = false;
		}
		//

		// Check Wheel Clicked
		if (WheelClicked() && (!CONSTS::WHEEL_WAS_CLICKED)) {
			EVENTS::WheelClicked.Call(GetMousePosition());
			CONSTS::WHEEL_WAS_CLICKED = true;
		}
		else if ((!WheelClicked()) && (CONSTS::WHEEL_WAS_CLICKED)) {
			CONSTS::WHEEL_WAS_CLICKED = false;
		}
		//
	}
	
	sf::Vector2i GetMousePosition() {
		return sf::Mouse::getPosition();
	}

	bool LeftClicked() {
		return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	}

	bool RightClicked() {
		return sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
	}

	bool WheelClicked() {
		return sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle);
	}
}