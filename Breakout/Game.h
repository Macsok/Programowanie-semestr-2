#pragma once
class Game
{
public:
	Game(unsigned int x = 800, unsigned int y = 600) : window_X(x), window_Y(y) {};
	void play();
private:
	const unsigned int window_X{ 800 };
	const unsigned int window_Y{ 600 };
};