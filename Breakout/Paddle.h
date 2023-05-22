#pragma once
#include <SFML/Graphics.hpp>
class Paddle : public sf::Drawable {
public:
	Paddle(float pox_X, float pos_Y);
	Paddle() = delete;
	~Paddle() = default;

	//	Poruszanie obiektu
	void keyboardUpdate();

	//	Funkcje zwracajace wspolrzedne krawedzi
	float left();
	float right();
	float top();
	float bottom();

	sf::Vector2f getPosition();

private:
	//	Stworzenie obiektu
	sf::RectangleShape player;

	const float paddleHeight = 20.0;
	const float paddleWidth = 80.0;

	//	Nadpisanie metody draw
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	const float spriteVelocity{ 8.0f };
	sf::Vector2f velocityVector{ spriteVelocity, 0 };
};

