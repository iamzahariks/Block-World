namespace SoundService {
	sf::SoundBuffer BLOCK_DESTROY_SOUND{ "Content/Sounds/BlockDestroy.mp3" };

	void Init() {
		sf::Music* music = new sf::Music{ "Content/Music/HouseTheme.mp3" };
		music->setLooping(true);
		music->play();
	}

	void PlayBlockDestroy() {
		sf::Sound *blockDestroy = new sf::Sound{ BLOCK_DESTROY_SOUND };
		blockDestroy->play();
	}
}