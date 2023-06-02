#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/*
void menuScreen(sf::RenderWindow& window) {
    sf::Vector2f dim(sf::Vector2f{ 80.f, 40.f });
    sf::RectangleShape playButton(dim);
    playButton.setOrigin(sf::Vector2f{ 40.f, 20.f });
    playButton.setPosition(400, 300);
    playButton.setFillColor(sf::Color::Green);

    sf::Event event;

    while (true) {
        window.clear(sf::Color::Black);
        window.pollEvent(event);
        //std::cout << "test";

        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        }

        window.draw(playButton);
        window.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) break;
    }
}
*/