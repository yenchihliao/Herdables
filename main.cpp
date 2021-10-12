#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
	sf::RenderWindow window(sf::VideoMode(500, 500), "Tyranny");
	sf::CircleShape dot(3);
	dot.setFillColor(sf::Color::Blue);

	while(window.isOpen()){
		sf::Event event;
		sf::Vector2i pos = sf::Mouse::getPosition(window);
		float dx = 0, dy = 0;
		while(window.pollEvent(event)){
			// Event window close
			if(event.type == sf::Event::Closed) window.close();
			if(event.type == sf::Event::MouseButtonPressed){
				if(event.key.code == sf::Mouse::Right){
					std::cout << "clicked" << std::endl;
					dot.setPosition(pos.x, pos.y);
				}
			}

			window.clear();
			window.draw(dot);
			window.display();
		}
	}
}
