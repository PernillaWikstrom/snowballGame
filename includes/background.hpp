#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "config.hpp"
#include "entity.hpp"

class background : public entity
{
	static sf::Texture texture;

public:
	background(float x, float y);

	// Implement the pure virtual functions
	void update() override;
	void draw(sf::RenderWindow &window) override;
};

#endif // BACKGROUND_H