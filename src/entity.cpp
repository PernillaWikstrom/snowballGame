#include "entity.hpp"

/**
 * @brief Get the entity 2D axis aligned rectangles
 * @return bounding rectangle for the sprite
 *
 */
sf::FloatRect entity::getBoundingBox() const noexcept
{
	return sprite.getGlobalBounds();
}

/**
 * @brief Get vector with the center of the sprite
 * @return vector with x,y position elements
 *
 */
sf::Vector2f entity::getCenter() const noexcept
{
	sf::FloatRect box = getBoundingBox();
	return {box.width * 0.5f, box.height * 0.5f};
}

/**
 * @brief Get the position of the rectangle's top-left corner x element.
 * @return float
 *
 */
float entity::x() const noexcept
{
	return sprite.getPosition().x;
}

/**
 * @brief Get the position of the rectangle's top-left corner y element.
 * @return float
 *
 */
float entity::y() const noexcept
{
	return sprite.getPosition().y;
}

/**
 * @brief Get the left most position sprite.
 * @return float
 *
 */
float entity::left() const noexcept
{
	auto box = getBoundingBox();
	return x() - box.width * 0.5f;
}

/**
 * @brief Get the right most position sprite.
 * @return float
 *
 */
float entity::right() const noexcept
{
	auto box = getBoundingBox();
	return x() + box.width * 0.5f;
}

/**
 * @brief Get the bottom position of the sprite.
 * @return float
 *
 */
float entity::bottom() const noexcept
{
	auto box = getBoundingBox();
	return y() + box.height * 0.5f;
}

/**
 * @brief Get the top position of the sprite.
 * @return float
 *
 */
float entity::top() const noexcept
{
	auto box = getBoundingBox();
	return y() - box.height * 0.5f;
}

void entity::destroy() noexcept
{
	_destroyed = true;
}

/**
 * @brief Get the position of the rectangle's top-left corner.
 * @return true if destroyed, otherwise false
 *
 */
bool entity::isDestroyed() const noexcept
{
	return _destroyed;
}
