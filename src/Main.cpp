#include <SFML/Graphics.hpp>

#include "HandleMenu.hpp"

int main(int argc, char** argv) {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Cybermatrix OS", sf::Style::Titlebar | sf::Style::Close);
	sf::Clock clock;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		HandleMenu(clock.getElapsedTime().asSeconds());
		clock.restart();
		window.clear();
		DrawMenu(window);
		window.display();
    }
	return 0;
}
