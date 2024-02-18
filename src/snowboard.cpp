#include "snowboard.hpp"

const static float zeroSpeed(0.f);

sf::Texture snowboard::texture;

snowboard::snowboard(float x, float y) : moving_entity()
{
	if (texture.loadFromFile("figures/snowboard.jpg"))
	{
		sprite.setTexture(texture);
	}

	sprite.setPosition(x, y);
	sprite.setOrigin(getCenter());
}

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

void snowboard::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void snowboard::moveUp() noexcept
{
	// Do nothing as the snowboard only moves sideways
}

void snowboard::moveDown() noexcept
{
	// Do nothing as the snowboard only moves sideways
}

void snowboard::moveLeft() noexcept
{
	velocity.x = -config::snowboardSpeed;
}

void snowboard::moveRight() noexcept
{
	velocity.x = config::snowboardSpeed;
}
