#pragma once
#include <SFML/Graphics.hpp>

class Sprite : public sf::Drawable
{
public:
	Sprite(float pox_X, float pos_Y);
	Sprite() = delete;
	~Sprite() = default;

	void update();

	//	Funkcje zwracajace wspolrzedne krawedzi
	float left();
	float right();
	float top();
	float bottom();
	
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	bool hadHitGround();

	sf::Vector2f getPosition();

private:
	//	Stworzenie obiektu gracza
	sf::CircleShape player;

	const float circleRadius = 10.0;
	//	Nadpisanie metody draw
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	const float spriteVelocity{ 4.0f };
	sf::Vector2f velocityVector{spriteVelocity, spriteVelocity};

	bool hitGround = false;
};

