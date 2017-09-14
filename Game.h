#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

using namespace std;

class Game
{
public:
    Game();
    void run();

private:
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    bool mIsMovingUp = false;
    bool mIsMovingDown = false;
    bool mIsMovingLeft = false;
    bool mIsMovingRight = false;

private:
    sf::RenderWindow mWindow;
    bool PlayerSpeed;
    // sf::CircleShape mPlayer;
    sf::Texture mtexture;
    sf::Sprite mPlayer;
    float theta;
    float rotation;
};
#endif // GAME_H
