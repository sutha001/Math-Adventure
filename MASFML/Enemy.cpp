#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	evRect.width = texture->getSize().x / float(imageCount.x);
	evRect.height = texture->getSize().y / float(imageCount.y);

}


Enemy::~Enemy()
{

}

int Enemy::Update(int row, float deltaTime, int at)
{
	currentImage.y = row;
	totalTime += deltaTime;
	int state = at;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
			state = 0;
		}
	}

	evRect.left = currentImage.x * evRect.width;
	evRect.top = currentImage.y * evRect.height;
	return state;
}