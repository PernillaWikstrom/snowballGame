#include "background.hpp"
#include <iostream>

sf::Texture background::texture;

/**
 * @brief Constructor of the background object
 *
 */
background::background(float x, float y) : entity()
{

	if (texture.loadFromFile("figures/background.jpg"))
	{
		sprite.setTexture(texture);
	}

	sprite.setPosition(x, y);
}

/**
 * @brief Pure virtual function to update the background.
 *
 */
void background::update()
{
	// Nothing to do here
}

/**
 * @brief Pure virtual function to draw background
 * @param window: window to draw
 *
 */
void background::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}
