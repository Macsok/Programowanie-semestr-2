#include "Sprite.h"

Sprite::Sprite(float pos_X, float pos_Y) {
	player.setPosition(pos_X, pos_Y);
	player.setRadius(this->circleRadius);
	player.setFillColor(sf::Color::Yellow);
	player.setOrigin(this->circleRadius, this->circleRadius);
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->player, state);
}

void Sprite::update() {
	player.move(this->velocityVector);

	//	Kolizje z krawedziami
	if (this->left() < 0) {
		velocityVector.x = spriteVelocity;
	}
	else if (this->right() > 800) {
		//velocityVector.x = -spriteVelocity;
		velocityVector.x = 0;
	}

	if (this->top() < 0) {
		velocityVector.y = spriteVelocity;
	}
	else if (this->bottom() > 600) {
		velocityVector.y = -spriteVelocity;
	}
}

//	Funkcje zwracajace wspolrzedne krawedzi
float Sprite::left() {
	return this->player.getPosition().x - this->player.getRadius();
}

float Sprite::right() {
	return this->player.getPosition().x + this->player.getRadius();
}

float Sprite::top() {
	return this->player.getPosition().y - this->player.getRadius();
}

float Sprite::bottom() {
	return this->player.getPosition().y + this->player.getRadius();
}
