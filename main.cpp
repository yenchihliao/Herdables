#include <SFML/Graphics.hpp>

int main(){
	sf::RenderWindow window(sf::VideoMode(500, 500), "Tyranny");
	sf::CircleShape dot(3);
	dot.setFillColor(sf::Color::Blue);

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed) window.close();

			window.clear();
			window.draw(dot);
			window.display();
		}
	}
}
