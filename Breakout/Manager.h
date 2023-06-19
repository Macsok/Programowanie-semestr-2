#pragma once
class Manager
{
private:
	const unsigned blocksX{ 10 }, blocksY{ 4 }, blockWidth{ 60 }, blockHeight{ 20 };

public:
	bool collisionTest(Paddle& paddle, Sprite& ball);
	bool collisionTest(Block& block, Sprite& ball);

	void update(Sprite& ball);
	void renderBlocks();
	void setBlocksTexture(sf::Texture& texture);
	sf::Texture generateTexture(std::string path);
	sf::Font generateDefaultFont(std::string path);
	sf::Text allocateText(int pos_X, int pos_Y, sf::Font& font);

	Manager operator+(const Manager& m) const;

	std::vector<Block> blocks;
	int points = 0;
	int lifes = 3;
};

