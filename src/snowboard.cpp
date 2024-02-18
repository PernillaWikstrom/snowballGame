#include "snowboard.hpp"

const static float zeroSpeed(0.f);

sf::Texture snowboard::texture;

/**
 * @brief Constructor of snowbard object.
 * @param x: position of width
 * @param y: position of height
 *
 */
snowboard::snowboard(float x, float y) : moving_entity()
{
	if (texture.loadFromFile("figures/snowboard.jpg"))
	{
		sprite.setTexture(texture);
	}

	sprite.setPosition(x, y);
	sprite.setOrigin(getCenter());
}

/**
 * @brief Pure virtual function to update snowboard object
 * on keyboard press.
 *
 */
void snowboard::update()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !(x() < config::snowboardWidth))
	{
		sprite.move(-config::snowboardSpeed, zeroSpeed);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !(x() > config::windowWidth - config::snowboardWidth))
	{
		sprite.move(config::snowboardSpeed, zeroSpeed);
	}
}

/**
 * @brief Pure virtual function to draw background
 * @param window: window to draw
 *
 */
void snowboard::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

/**
 * @brief Moves entity nowhere since snowboard only moves sideways
 *
 */
void snowboard::moveUp() noexcept
{
	// Do nothing
}

/**
 * @brief Moves entity nowhere since snowboard only moves sideways
 *
 */
void snowboard::moveDown() noexcept
{
	// Do nothing
}

/**
 * @brief Moves entity left
 *
 */
void snowboard::moveLeft() noexcept
{
	velocity.x = -config::snowboardSpeed;
}

/**
 * @brief Moves entity right
 *
 */
void snowboard::moveRight() noexcept
{
	velocity.x = config::snowboardSpeed;
}
