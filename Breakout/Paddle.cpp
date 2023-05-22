#include "Paddle.h"

Paddle::Paddle(float pos_X, float pos_Y) {
	player.setPosition(pos_X, pos_Y);
	player.setSize({ this->paddleWidth, this->paddleHeight });
	player.setFillColor(sf::Color::Green);
	player.setOrigin(this->paddleWidth / 2.f, this->paddleHeight / 2.f);
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->player, state);
}

//	Poruszanie sie
void Paddle::keyboardUpdate() {
	//player.move(this->velocityVector);

	//	Kolizje z krawedziami
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->left() > 0) {
		velocityVector.x = -spriteVelocity;
		velocityVector.y = 0;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->right() < 800) {
		velocityVector.x = spriteVelocity;
		velocityVector.y = 0;
	}
	else velocityVector.x = 0;

	player.move(this->velocityVector);
}

//	Funkcje zwracajace wspolrzedne krawedzi
float Paddle::left() {
	return this->player.getPosition().x - this->player.getSize().x / 2.f;
}

float Paddle::right() {
	return this->player.getPosition().x + this->player.getSize().x / 2.f;
}

float Paddle::top() {
	return this->player.getPosition().y - this->player.getSize().y / 2.f;
}

float Paddle::bottom() {
	return this->player.getPosition().y + this->player.getSize().y / 2.f;
}

sf::Vector2f Paddle::getPosition() {
	return player.getPosition();
}