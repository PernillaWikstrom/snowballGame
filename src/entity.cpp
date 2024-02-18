#include "entity.hpp"

sf::FloatRect entity::getBoundingBox() const noexcept
{
	return sprite.getGlobalBounds();
}

sf::Vector2f entity::getCenter() const noexcept
{
	sf::FloatRect box = getBoundingBox();
	return {box.width * 0.5f, box.height * 0.5f};
}

float entity::x() const noexcept
{
	return sprite.getPosition().x;
}

float entity::y() const noexcept
{
	return sprite.getPosition().y;
}

float entity::left() const noexcept
{
	auto box = getBoundingBox();
	return x() - box.width * 0.5f;
}

float entity::right() const noexcept
{
	auto box = getBoundingBox();
	return x() + box.width * 0.5f;
}

float entity::bottom() const noexcept
{
	auto box = getBoundingBox();
	return y() + box.height * 0.5f;
}

float entity::top() const noexcept
{
	auto box = getBoundingBox();
	return y() - box.height * 0.5f;
}

void entity::destroy() noexcept
{
	_destroyed = true;
}

bool entity::isDestroyed() const noexcept
{
	return _destroyed;
}
