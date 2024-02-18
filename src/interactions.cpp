#include "interactions.hpp"

/**
 * @brief Checks if two entites intersects
 * @param e1: entity object
 * @param e2: entity object
 * @return true if intersection occur, otherwise false
 *
 */
bool isColliding(const entity &e1, const entity &e2)
{
	auto box1 = e1.getBoundingBox();
	auto box2 = e2.getBoundingBox();

	return box1.intersects(box2);
}

/**
 * @brief Moves the snowball on collision with snowboard
 * @param snowball: movable entity object
 * @param snowboard: entity object that may collide with moving entity
 *
 */
void handleCollision(snowball &snowball, const snowboard &snowboard)
{
	if (isColliding(snowball, snowboard))
	{
		snowball.moveUp();

		if (snowball.x() < snowboard.x())
		{
			snowball.moveLeft();
		}
		else
		{
			snowball.moveRight();
		}
	}
}

/**
 * @brief Moves the snowball on collision with brick.
 * If the ball hit the left or right side of the brick, change its horizontal direction,
 * else if the ball hit the top or bottom of the brick, change its vertical direction.
 * @param snowball: movable entity object
 * @param brick: entity object that changes color level on collision
 *
 */
void handleCollision(snowball &snowball, brick &brick)
{
	if (isColliding(snowball, brick))
	{
		brick.degradeColorLevel();

		if (brick.isColorLevelTooLow())
		{
			brick.destroy();
		}

		float leftOverlap = snowball.right() - brick.left();
		float rightOverlap = brick.right() - snowball.left();
		float topOverlap = snowball.bottom() - brick.top();
		float bottomOverlap = brick.bottom() - snowball.top();

		bool fromLeft = std::abs(leftOverlap) < std::abs(rightOverlap);
		bool fromTop = std::abs(topOverlap) < std::abs(bottomOverlap);

		float minHorizontalOverlap = fromLeft ? leftOverlap : rightOverlap;
		float minVerticalOverlap = fromTop ? topOverlap : bottomOverlap;

		if (std::abs(minHorizontalOverlap) < std::abs(minVerticalOverlap))
		{
			if (fromLeft)
				snowball.moveLeft();
			else
				snowball.moveRight();
		}
		else
		{
			if (fromTop)
				snowball.moveUp();
			else
				snowball.moveDown();
		}
	}
}