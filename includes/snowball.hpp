#ifndef SNOWBALL_H
#define SNOWBALL_H

#include "config.hpp"
#include "entity.hpp"

class snowball : public moving_entity
{
	static sf::Texture texture;

public:
	snowball(float x, float y);

	// Implement the pure virtual functions
	void update() override;
	void draw(sf::RenderWindow &window) override;

	void moveUp() noexcept override;
	void moveLeft() noexcept override;
	void moveRight() noexcept override;
	void moveDown() noexcept override;
};

#endif // SNOWBALL_H
