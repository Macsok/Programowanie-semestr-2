#include "Scripts.cpp"

void Game::play() {
    //  Stworzenie obiektów
    Sprite ball(float(window_X / 2), float(window_Y / 2));
    Paddle paddle(float(window_X / 2), float(window_Y - 30));
    Manager manage;

    sf::RenderWindow window{ sf::VideoMode{window_X, window_Y}, "Breakout M. SOKOLOWSKI" };
    window.setFramerateLimit(60);
    
    sf::Event event;

    sf::Font myFont = manage.generateDefaultFont("./Fonts/Pangolin-Regular.ttf");
    sf::Text text = manage.allocateText(10, window_Y - 50, myFont);

    //  tekstury
    sf::Texture texture = manage.generateTexture("./Textures/pink-marble.png");

    paddle.myTexture(texture);

    manage.renderBlocks();
    manage.setBlocksTexture(texture);
    //-------------------------------------------------------   Pêtla gry
    while (true) {
        window.clear(sf::Color::Black);
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        }

        //  Rysowanie/kolizje pilka-paletka
        paddle.keyboardUpdate();
        window.draw(paddle);

        //  Sprawdzanie kolizji
        manage.collisionTest(paddle, ball);
        manage.update(ball);
        if (ball.hadHitGround()) manage.points -= 10;

        ball.update();
        window.draw(ball);
        for (auto& block : manage.blocks) {
            window.draw(block);
        }

        // Aktualizacja tekstu
        text.setString("Points: " + std::to_string(manage.points));
        window.draw(text);

        window.display();
    }
}