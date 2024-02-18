#ifndef BRICK_H
#define BRICK_H

#include "config.hpp"
#include "entity.hpp"

class brick : public entity
{
	static sf::Texture texture;
	int _colorLevel{config::brickColorLevels};

public:
	brick(float x, float y);

	void degradeColorLevel() noexcept;
	bool isColorLevelTooLow() const noexcept;

	// Implement the pure virtual functions
	void update() override;
	void draw(sf::RenderWindow &window) override;
};

#endif // BRICK_H
