#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(int argc, char** argv) {
	sf::SoundBuffer sound_buffer;
	sound_buffer.loadFromFile("./data/startup.wav");
	sf::Sound sound(sound_buffer);
	sound.play();
	sf::RenderWindow window(sf::VideoMode(800, 600), "Cybermatrix OS");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		window.display();
    }
	return 0;
}
