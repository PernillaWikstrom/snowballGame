#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class entity
{
protected:
	sf::Sprite sprite;
	bool _destroyed{false};

public:
	// Pure virtual functions
	// Concrete graphical entities must implement these functions
	// The update member function will compute the new position, appearance, etc of the object
	// The draw member function will cause the updated object to be displayed in the game window
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow &window) = 0;

	// noexcept for functions that cannot throw

	// Returns bounding rectangle for the sprite
	sf::FloatRect getBoundingBox() const noexcept;
	// Returns the center of the sprite
	sf::Vector2f getCenter() const noexcept;

	// Get x position
	float x() const noexcept;
	// Get y position
	float y() const noexcept;

	float left() const noexcept;
	float right() const noexcept;
	float bottom() const noexcept;
	float top() const noexcept;

	void destroy() noexcept;
	bool isDestroyed() const noexcept;

	// Virtual destructor
	virtual ~entity() {}
};

class moving_entity : public entity
{
protected:
	// SFML vector to store the object's velocity
	sf::Vector2f velocity;

public:
	virtual void moveUp() noexcept = 0;
	virtual void moveLeft() noexcept = 0;
	virtual void moveRight() noexcept = 0;
	virtual void moveDown() noexcept = 0;
};

#endif // ENTITY_H