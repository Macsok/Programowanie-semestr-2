#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Sprite.h"

const int window_X{ 800 };
const int window_Y{ 600 };

int main()
{

    Sprite sprite(400, 300);
    sf::RenderWindow window{ sf::VideoMode{window_X, window_Y}, "Pacman M. SOKOLOWSKI" };
    window.setFramerateLimit(60);

    sf::Event event;

    while (true) {
        window.clear(sf::Color::Black);
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        }

        sprite.update();
        window.draw(sprite);
        window.display();
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
