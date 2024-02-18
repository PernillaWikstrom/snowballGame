#include "brick.hpp"

sf::Texture brick::texture;

const sf::Color colorLevel1{0, 255, 0, 80};	 // Dull green
const sf::Color colorLevel2{0, 255, 0, 170}; // Medium green
const sf::Color colorLevel3{0, 255, 0, 255}; // Bright green

/**
 * @brief Degrades color level as long as
 * the level is greater than zero.
 *
 */
void brick::degradeColorLevel() noexcept
{
	if (_colorLevel > 0)
	{
		--_colorLevel;
	}
}

/**
 * @brief Check if the color level is too low
 * @return true if color level is smaller or equals zero, otherwise false.
 *
 */
bool brick::isColorLevelTooLow() const noexcept
{
	return _colorLevel <= 0;
}

/**
 * @brief Constructor of the brick object.
 * Sets the brick texture with image.
 * @param x: position of the width
 * @param y: position of the height
 *
 */
brick::brick(float x, float y)
{
	if (texture.loadFromFile("figures/brick.jpg"))
	{
		sprite.setTexture(texture);
	}

	sprite.setPosition(x, y);
	sprite.setOrigin(getCenter());
}

/**
 * @brief Pure virtual function to update brick.
 * Color level will determine transparanty of the brick color.
 *
 */
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

/**
 * @brief Pure virtual function to draw brick
 * @param window: window to draw
 *
 */
void brick::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}
