#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <memory>
#include <typeinfo>
#include <vector>

#include "entity.hpp"
#include "background.hpp"
#include "config.hpp"
#include "snowball.hpp"
#include "snowboard.hpp"
#include "brick.hpp"

// Use aliases to simplify the code
using entityVector = std::vector<std::unique_ptr<entity>>;
using entityAliasVvector = std::vector<entity *>;

class entityManager
{
	// All the entities in the game (all brick objects, background, ball, paddle)
	entityVector allEntities;

	// A map to store the entities grouped by type
	// We can iterate over this to get a vector of all brick objects, then a vector of all ball objects, etc
	// The vector will contain non-owning pointers to the objects
	// Do not delete these pointers!
	// Do not use them after the objects they point to have been destroyed!
	std::map<size_t, entityAliasVvector> groupedEntities;

public:
	// Function to create an entity object of type T using args as the constructor arguments
	// We use a variadic template to pass any number of arguments
	// Perfect forwarding to avoid any unnecessary copying of the arguments
	template <typename T, typename... Args>
	T &create(Args &&...args)
	{
		// Check that the type parameter is derived from the entity base class
		static_assert(std::is_base_of<entity, T>::value,
					  R"("T" type parameter in create() must be derived from "entity")");

		// Create a unique_ptr to the entity
		// Forward the arguments to the entity's constructor
		auto ptr{std::make_unique<T>(std::forward<Args>(args)...)};

		// Make an alias pointer to the allocated memory
		// This will be stored in the entity_type_vector
		auto ptr_alias = ptr.get();

		// Get the hash code for the entity object's type
		auto hash = typeid(T).hash_code();

		// Insert the alias pointer into the map
		groupedEntities[hash].emplace_back(ptr_alias);

		// Insert the object's pointer into the entities vector
		allEntities.emplace_back(std::move(ptr));

		// Return the new object
		return *ptr_alias;
	}

	// Function to scan all entities and clean up the destroyed ones
	void refresh();

	// Function to destroy all entities
	void clear();

	// Function to retrieve all the objects of a given type
	template <typename T>
	auto &getAll()
	{
		return groupedEntities[typeid(T).hash_code()];
	}

	// Apply a function to all entities of a given type
	template <typename T, typename Func>
	void applyAll(const Func &func)
	{
		auto &entity_group{getAll<T>()};

		for (auto ptr : entity_group)
			func(*dynamic_cast<T *>(ptr));
	}

	// Function to update all the entities
	void update();

	// Function to make all the entities draw themselves
	void draw(sf::RenderWindow &window);
};

class gameManager
{
	sf::RenderWindow game_window{
		{config::windowWidth, config::windowHeight},
		"Snowball game",
	};

	enum class gameStates
	{
		INACTIVE,
		ACTIVE,
		GAME_OVER,
		WON
	};

	sf::Font _verdana;
	sf::Text _textState, _textLives;

	entityManager _entityManager;

	gameStates _state{gameStates::INACTIVE};
	int _lives{config::lives};

	bool _pressedPause{false};
	void updateStatus();

public:
	gameManager();
	void run();
	void reset();
};

#endif // ENTITY_MANAGER_H