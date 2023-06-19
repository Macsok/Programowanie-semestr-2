#include "Scripts.cpp"

//  Detekcja kolizji, zmiana kierunku poruszania sie pilki
bool Manager::collisionTest(Paddle& paddle, Sprite& ball) {
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

//  Detekcja kolizji, zmiana kierunku poruszania sie pilki 
bool Manager::collisionTest(Block& block, Sprite& ball) {
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
    return true;
}

//  Wygenerowanie vectora blokow
void Manager::renderBlocks() {
    std::string map_sketch[] = {
        "# ##### ##",
        "# # # # ##",
        "#### #####",
        "##########"
    };

    for (int i = 0; i < blocksY; i++) {
        for (int j = 0; j < blocksX; j++) {
            if (map_sketch[i][j] == '#') {
                this->blocks.emplace_back((j + 1) * (blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
            }
        }
    }
}

//  Sprawdzenie kolizji z pilka i aktualizacja listy blokow, dodatnie punktu
void Manager::update(Sprite& ball) {
    //  Niszczenie bloków
    //  Sprawdzenie kolizji ze wszystkimi blokami
    for (auto& block : blocks) if (collisionTest(block, ball)) {
        this->points++;
        break;
    }

    //  Usuwanie blokow po zderzeniu, aktualizacja listy blokow
    auto iterator = std::remove_if(begin(blocks), end(blocks), [](Block& block) { return block.isDestroyed(); });
    blocks.erase(iterator, end(blocks));
 }

//  Ustawienie textury blokow
void Manager::setBlocksTexture(sf::Texture& texture) {
    //  Ustawianie textur
    for (auto& block : this->blocks) {
        block.myTexture(texture);
    }
}

//  Generowanie textury z pliku + ustawienia domyslne
sf::Texture Manager::generateTexture(std::string path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cout << "Texture not found";
    }
    texture.setRepeated(true);
    texture.setSmooth(true);
    return texture;
}

//  Tworzenie domyslnej czcionki z pliku
sf::Font Manager::generateDefaultFont(std::string path) {
    sf::Font myFont;
    if (!myFont.loadFromFile(path)) {
        std::cout << "Font not found";
    }
    return myFont;
}

sf::Text Manager::allocateText(int pos_X, int pos_Y, sf::Font& font) {
    sf::Text text;
    text.move(pos_X, pos_Y);
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    return text;
}

Manager Manager::operator+(const Manager& m) const {
    Manager temp;
    temp.points += m.points;
    temp.lifes += m.lifes;
    return temp;
}