#include "brick.hpp"

sf::Texture brick::texture;

const sf::Color colorLevel1{0, 255, 0, 80};	 // Dull green
const sf::Color colorLevel2{0, 255, 0, 170}; // Medium green
const sf::Color colorLevel3{0, 255, 0, 255}; // Bright green

void brick::degradeColorLevel() noexcept
{
	if (_colorLevel > 0)
	{
		--_colorLevel;
	}
}

bool brick::isColorLevelTooLow() const noexcept
{
	return _colorLevel <= 0;
}

brick::brick(float x, float y)
{
	if (texture.loadFromFile("figures//brick.jpg"))
	{
		sprite.setTexture(texture);
	}

	sprite.setPosition(x, y);
	sprite.setOrigin(getCenter());
}

void brick::update()
{
	if (_colorLevel == 1)
	{
		sprite.setColor(colorLevel1);
	}
	else if (_colorLevel == 2)
	{
		sprite.setColor(colorLevel2);
	}
	else if (_colorLevel == 3)
	{
		sprite.setColor(colorLevel3);
	}
}

void brick::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}
