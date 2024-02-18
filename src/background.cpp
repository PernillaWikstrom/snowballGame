#include "background.hpp"
#include <iostream>

sf::Texture background::texture;

background::background(float x, float y) : entity()
{

	if (texture.loadFromFile("figures/background.jpg"))
	{
		sprite.setTexture(texture);
	}

	sprite.setPosition(x, y);
}

void background::update()
{
	// Nothing to do here
}

void background::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}
