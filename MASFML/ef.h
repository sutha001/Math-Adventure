#pragma once
#include <SFML/Graphics.hpp>

class EF
{
public:
	EF(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~EF();

	int Update(int row, float deltaTime, int at);

public:
	sf::IntRect evRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};
