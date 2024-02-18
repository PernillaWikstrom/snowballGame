#ifndef SNOWBOARD_H
#define SNOWBOARD_H

#include "config.hpp"
#include "entity.hpp"

class snowboard : public moving_entity
{
	static sf::Texture texture;

public:
	snowboard(float x, float y);

	// Implement the pure virtual functions
	void update() override;
	void draw(sf::RenderWindow &window) override;

	void moveUp() noexcept override;
	void moveLeft() noexcept override;
	void moveRight() noexcept override;
	void moveDown() noexcept override;
};

#endif // SNOWBOARD_H
