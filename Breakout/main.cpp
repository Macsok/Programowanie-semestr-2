#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Sprite.h"
#include "Paddle.h"
#include "Block.h"

//  Template kolizji
template <class T1, class T2> bool isIntersecting(T1& A, T2& B) {
    return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}

bool collisionTest(Paddle& paddle, Sprite& ball) {
    if (!isIntersecting(paddle, ball)) return false;
    ball.moveUp();
    
    //  Dodatkowa zmiana kierunku pilki
    if (ball.getPosition().x < paddle.getPosition().x) {
        ball.moveLeft();
    }
    else if (ball.getPosition().x > paddle.getPosition().x) {
        ball.moveRight();
    }

    return true;
}

bool collisionTest(Block& block, Sprite& ball) {
    if (!isIntersecting(block, ball)) return false;

    block.destroy();

    float overlapLeft{ ball.right() - block.left() };
    float overlapRight{ block.right() - ball.left() };

    float overlapTop{ ball.bottom() - block.top() };
    float overlapBottom{ block.bottom() - ball.top() };

    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

    float overlapX{ ballFromLeft ? overlapLeft : overlapRight };
    float overlapY{ ballFromTop ? overlapTop : overlapBottom };

    if (abs(overlapX) < abs(overlapY)) {
        ballFromLeft ? ball.moveLeft() : ball.moveRight();
    }
    else {
        ballFromTop ? ball.moveUp() : ball.moveDown();
    }
}

const int window_X{ 800 };
const int window_Y{ 600 };

int main()
{

    Sprite ball(window_X / 2, window_Y / 2);
    Paddle paddle(window_X / 2, window_Y - 30);

    sf::RenderWindow window{ sf::VideoMode{window_X, window_Y}, "Breakout M. SOKOLOWSKI" };
    window.setFramerateLimit(60);

    sf::Event event;

    //  Punkty / text
    int points = 0;
    sf::Text text;
    sf::Font myFont;
    if (!myFont.loadFromFile("./Fonts/Pangolin-Regular.ttf")) {
        std::cout << "Font not found";
    }
    text.move(10, window_Y - 50);
    text.setFont(myFont);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);

    //  textures

    sf::Texture marble;
    if (!marble.loadFromFile("./Textures/pink-marble.png")) {
        std::cout << "Texture not found";
    }
    marble.setRepeated(true);
    marble.setSmooth(true);
    paddle.myTexture(marble);

    //  Bloki
    const unsigned blocksX{ 10 }, blocksY{ 4 }, blockWidth{ 60 }, blockHeight{ 20 };
    std::string map_sketch[blocksY] = {
        "# ##### ##",
        "## ### ###",
        "### # ####",
        "#### #####"
    };
    std::vector<Block> blocks;

    for (int i = 0; i < blocksY; i++) {
        for (int j = 0; j < blocksX; j++) {
            if (map_sketch[i][j] == '#') {
                blocks.emplace_back((j + 1) * (blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
            }
        }
    }

    //  Ustawianie textur
    for (auto& block : blocks) {
        block.myTexture(marble);
    }

    while (true) {
        window.clear(sf::Color::Black);
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        }

        paddle.keyboardUpdate();
        
        
        window.draw(paddle);
        collisionTest(paddle, ball);

        //  Niszczenie bloków
        //  Sprawdzenie kolizji ze wszystkimi blokami
        for (auto& block : blocks) if (collisionTest(block, ball)) {
            points++;
            break;
        }

        auto iterator = std::remove_if(begin(blocks), end(blocks), [](Block& block) { return block.isDestroyed(); });
        blocks.erase(iterator, end(blocks));

        ball.update();
        window.draw(ball);

        for (auto& block : blocks) {
            window.draw(block);
        }

        // Aktualizacja tekstu
        text.setString("Points: " + std::to_string(points));
        window.draw(text);

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
