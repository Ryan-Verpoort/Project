#include "SFML/Graphics.hpp"
#include <cmath>
#include <math.h>

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gyruss");
    // window.setFramerateLimit(60);

    sf::Font font;
    if(!font.loadFromFile("resources/sansation.ttf"))
	return EXIT_FAILURE;

    sf::Texture texture;
    if(!texture.loadFromFile("resources/Spaceship.png"))
	return EXIT_FAILURE;

	texture.setSmooth(true);

    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(30);
    pauseMessage.setPosition(100.f, 210.f);
    pauseMessage.setColor(sf::Color::White);
    pauseMessage.setString("Welcome to SFML Gyruss, Press space to start!!");

    sf::Sprite shape;
    shape.setTexture(texture);
    shape.setScale(0.1, 0.1);

    bool isPlaying = false;

    // set the change in angle for the rotate function for left and right movement
    float anticlockwise = -4.0;
    float clockwise = 4.0;

    // alows for the transformation of cartesian to polar cordinates
    sf::Transform t;

    sf::Clock clock;

    while(window.isOpen()) {

	sf::Event event;
	while(window.pollEvent(event)) {

	    if((event.type == sf::Event::Closed) ||
	        ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
		window.close();
		break;
	    }
	    if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)) {
		if(!isPlaying) {

		    isPlaying = true;
		    // set the centre of the shape, the radius of the shape and the starting positiong to be 6 O'clock
		    shape.setOrigin(50, 50);
		    // shape.setRadius(50);
		    shape.setPosition(800.0f / 2.0f, 600.0f / 1.1f);
		}
	    }

	    if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::P)) {
		//window.close();
		window.draw(pauseMessage);
		isPlaying = false;
		break;
	    }

	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

		// clear the window and change the new position of the shape
		window.clear(sf::Color::Black);
		t.rotate(clockwise, { 800 / 2.f, 600 / 2.f });
	    }

	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

		// clear the window and change the new position of the shape
		window.clear(sf::Color::Black);
		t.rotate(anticlockwise, { 800 / 2.f, 600 / 2.f });
	    }
	}

	window.clear(sf::Color(0, 0, 0));

	if(isPlaying) {
	    // redraw the shape
	    window.draw(shape, t);

	} else {

	    //            draw the  splash menu
	    window.draw(pauseMessage);
	}

	window.display();
    }

    return 0;
}