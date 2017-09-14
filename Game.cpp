#include "Game.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Game::Game()
    : mWindow(sf::VideoMode(1920, 1080), "SFML Application")
    , mPlayer()
{
    //    mPlayer.setRadius(40.f);
    mtexture.loadFromFile("resources/Spaceship-PNG-File.png");
    //    mPlayer.setOrigin(10, 20);
    mPlayer.setPosition(960.f, 785.f);
    //    mPlayer.setFillColor(sf::Color::Cyan);

    mPlayer.setScale(0.1, 0.1);
    mPlayer.setTexture(mtexture);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(mWindow.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        auto TimePerFrame = sf::seconds(1.f / 60.f);
        while(timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event)) {
        switch(event.type) {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    //    if(key == sf::Keyboard::W)
    //        mIsMovingUp = isPressed;
    //    else if(key == sf::Keyboard::S)
    //        mIsMovingDown = isPressed;
    //    else
    if(key == sf::Keyboard::Left)
        mIsMovingLeft = isPressed;
    else if(key == sf::Keyboard::Right)
        mIsMovingRight = isPressed;
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);

    if(mIsMovingRight && !mIsMovingLeft) {
        theta = theta + 0.05;
        movement.x -= cos(theta) * 16;
        movement.y -= sin(theta) * 16;
    }
    if(mIsMovingLeft && !mIsMovingRight) {
        theta = theta - 0.05;
        movement.x += cos(theta) * 16;
        movement.y += sin(theta) * 16;
    }

    //    if(mIsMovingUp)
    //        movement.y -= PlayerSpeed;
    //    if(mIsMovingDown)
    //        movement.y += PlayerSpeed;
    //    if(mIsMovingLeft)
    //        movement.x -= PlayerSpeed;
    //    if(mIsMovingRight)
    //        movement.x += PlayerSpeed;
    //    mPlayer.move(movement * deltaTime.asSeconds());
    mPlayer.move(movement);
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}
