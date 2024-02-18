#include "snowball.hpp"

const static float swapSign(-1.f);

sf::Texture snowball::texture;

snowball::snowball(float x, float y) : moving_entity()
{

	if (texture.loadFromFile("figures/snowball.jpg"))
	{
		sprite.setTexture(texture);
	}

	sprite.setPosition(x, y);
	velocity = {config::snowballSpeed, config::snowballSpeed};
}

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

void snowball::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void snowball::moveUp() noexcept
{
	velocity.y = -config::snowballSpeed;
}

void snowball::moveDown() noexcept
{
	velocity.y = config::snowballSpeed;
}

void snowball::moveLeft() noexcept
{
	velocity.x = -config::snowballSpeed;
}

void snowball::moveRight() noexcept
{
	velocity.x = config::snowballSpeed;
}
