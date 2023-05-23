#include "Block.h"

Block::Block(float t_X, float t_Y, float t_Width, float t_Height) {
	shape.setPosition(t_X, t_Y);
	shape.setSize({ t_Width, t_Height });
	shape.setFillColor(sf::Color::Green);
	shape.setOrigin(t_Width / 2.f, t_Height / 2.f);
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates state) const {
	target.draw(this->shape, state);
}

float Block::left() {
	return this->shape.getPosition().x - this->shape.getSize().x / 2.f;
}

float Block::right() {
	return this->shape.getPosition().x + this->shape.getSize().x / 2.f;
}

float Block::top() {
	return this->shape.getPosition().y - this->shape.getSize().y / 2.f;
}

float Block::bottom() {
	return this->shape.getPosition().y + this->shape.getSize().y / 2.f;
}

sf::Vector2f Block::getPosition() {
	return shape.getPosition();
}

bool Block::isDestroyed() {
	return this->destroyed;
}

void Block::destroy() {
	this->destroyed = true;
}

sf::Vector2f Block::getSize() {
	return shape.getSize();
}

void Block::myTexture(sf::Texture& texture) {
	shape.setTexture(&texture);
}