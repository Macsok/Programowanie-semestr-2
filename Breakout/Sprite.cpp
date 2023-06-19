#include "Sprite.h"
//#include <stdafx.h>

Sprite::Sprite(float pos_X, float pos_Y) {
	player.setPosition(pos_X, pos_Y);
	player.setRadius(this->circleRadius);
	player.setFillColor(sf::Color::Yellow);
	player.setOrigin(this->circleRadius, this->circleRadius);
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->player, state);
}

//	odswiezanie polozenia
void Sprite::update() {
	player.move(this->velocityVector);

	//	Kolizje z krawedziami
	if (this->left() < 0) {
		velocityVector.x = spriteVelocity;
	}
	else if (this->right() > 800) {
		//velocityVector.x = -spriteVelocity;
		velocityVector.x = -spriteVelocity;
	}

	if (this->top() < 0) {
		velocityVector.y = spriteVelocity;
	}
	else if (this->bottom() > 600) {
		velocityVector.y = -spriteVelocity;
		this->hitGround = true;
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

//	Zmiana toru ruchu
void Sprite::moveUp() {
	this->velocityVector.y = -spriteVelocity;
}

void Sprite::moveDown() {
	this->velocityVector.y = spriteVelocity;
}

void Sprite::moveRight() {
	this->velocityVector.x = spriteVelocity;
}

void Sprite::moveLeft() {
	this->velocityVector.x = -spriteVelocity;
}

sf::Vector2f Sprite::getPosition() {
	return player.getPosition();
}

bool Sprite::hadHitGround() {
	if (this->hitGround) {
		hitGround = false;
		return true;
	}
	return false;
}