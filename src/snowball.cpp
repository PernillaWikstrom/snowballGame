#include "snowball.hpp"

const static float swapSign(-1.f);

sf::Texture snowball::texture;

/**
 * @brief Constructor of snowball object.
 * @param x: position of width
 * @param y: position of height
 *
 */
snowball::snowball(float x, float y) : moving_entity()
{

	if (texture.loadFromFile("figures/snowball.jpg"))
	{
		sprite.setTexture(texture);
	}

	sprite.setPosition(x, y);
	velocity = {config::snowballSpeed, config::snowballSpeed};
}

/**
 * @brief Pure virtual function to update snowball object.
 * Make sure that the snowball is withing the expected window
 * size.
 *
 */
void snowball::update()
{
	sprite.move(velocity);

	if (x() < 0 || x() > config::windowWidth)
	{
		velocity.x *= swapSign;
	}

	if (y() < 0)
	{
		velocity.y *= swapSign;
	}
	else if (y() > config::windowHeight)
	{
		destroy();
	}
}

/**
 * @brief Pure virtual function to draw background
 * @param window: window to draw
 *
 */
void snowball::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

/**
 * @brief Moves entity upwards
 *
 */
void snowball::moveUp() noexcept
{
	velocity.y = -config::snowballSpeed;
}

/**
 * @brief Moves entity downwards
 *
 */
void snowball::moveDown() noexcept
{
	velocity.y = config::snowballSpeed;
}

/**
 * @brief Moves entity left
 *
 */
void snowball::moveLeft() noexcept
{
	velocity.x = -config::snowballSpeed;
}

/**
 * @brief Moves entity right
 *
 */
void snowball::moveRight() noexcept
{
	velocity.x = config::snowballSpeed;
}
