#include <algorithm>

#include "entityManager.hpp"
#include "interactions.hpp"

/**
 * @brief Scan all entities and clean up the destroyed ones
 *
 */
void entityManager::refresh()
{
	// We must clean up the alias pointers first, to avoid dangling pointers
	// We simply remove them from their vector
	for (auto &[type, alias_vector] : groupedEntities)
	{
		// remove_if takes an iterator range and a predicate
		// All the elements for which the predicate is true are moved to the back
		// It returns an iterator to the first moved element
		// erase takes an iterator range and deletes all the elements in the range
		alias_vector.erase(remove_if(begin(alias_vector), end(alias_vector),
									 [](const auto &p)
									 { return p->isDestroyed(); }),
						   end(alias_vector));
	}

	// Now we can safely destroy the objects, now that there are no aliases to them
	allEntities.erase(remove_if(begin(allEntities), end(allEntities),
								[](const auto &p)
								{ return p->isDestroyed(); }),
					  end(allEntities));
}

/**
 * @brief Destroy all entities, starting by cleaning up the alias pointers.
 *
 */
void entityManager::clear()
{
	groupedEntities.clear();
	allEntities.clear();
}

/**
 * @brief Pure virtual function to make all the entities update themselves
 *
 */
void entityManager::update()
{
	for (auto &e : allEntities)
	{
		e->update();
	}
}

/**
 * @brief Pure virtual function to make all the entities draw themselves
 * @param window: window to draw
 *
 */
void entityManager::draw(sf::RenderWindow &window)
{
	for (auto &e : allEntities)
	{
		e->draw(window);
	}
}

/**
 * @brief Constructor of the game Manager object
 *
 */
gameManager::gameManager()
{
	game_window.setFramerateLimit(config::frameRate);

	_verdana.loadFromFile("/usr/share/fonts/truetype/msttcorefonts/verdana.ttf");
	// verdana.loadFromFile("C:/Windows/fonts/Verdana.ttf");

	_textState.setFont(_verdana);
	_textState.setPosition(config::windowWidth * 0.5f - 125.0f, config::windowHeight * 0.5f - 100.0f);
	_textState.setCharacterSize(35);
	_textState.setFillColor(sf::Color::White);

	_textLives.setFont(_verdana);
	_textLives.setPosition(1.0f, config::windowHeight - 50.0f);
	_textLives.setCharacterSize(35);
	_textLives.setFillColor(sf::Color::White);
	_textLives.setString("Lives: " + std::to_string(_lives));
}

/**
 * @brief Resets the game manager to its initial state
 *
 */
void gameManager::reset()
{
	_state = gameStates::INACTIVE;
	_lives = config::lives;

	_entityManager.clear();

	_entityManager.create<background>(0.0f, 0.0f);
	_entityManager.create<snowball>(config::windowWidth * 0.5f, config::windowHeight * 0.5f);
	_entityManager.create<snowboard>((config::windowWidth - config::snowboardWidth) * 0.5, config::windowHeight - config::snowboardHeight);

	for (int i = 0; i < config::brickColumns; ++i)
	{
		for (int j = 0; j < config::brickRows; ++j)
		{
			_entityManager.create<brick>(config::bricksOffset + (i + 1) * config::brickWidth, (j + 1) * config::brickHeight);
		}
	}
	game_window.setFramerateLimit(config::frameRate);
}

/**
 * @brief Updates the game status when the pause key is pressed
 *
 */
void gameManager::updateStatus()
{
	if (!_pressedPause)
	{
		switch (_state)
		{
		case gameStates::INACTIVE:
			_state = gameStates::ACTIVE;
			break;
		case gameStates::ACTIVE:
			_state = gameStates::INACTIVE;
			break;
		default:
			break;
		}

		_pressedPause = true;
	}
}

/**
 * @brief Run the game manager as long as the game window is open
 *
 */
void gameManager::run()
{

	while (game_window.isOpen())
	{
		game_window.clear(sf::Color::Black);

		// Check for any events since the last loop iteration
		sf::Event event;

		// If the user pressed "Escape", or clicked on "close", we close the window
		// This will terminate the program
		while (game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				game_window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			break;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
		{
			updateStatus();
		}
		else
		{
			_pressedPause = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
		{
			reset();
		}

		switch (_state)
		{
		case gameStates::ACTIVE:
		{
			// If there are no remaining balls on the screen
			if (_entityManager.getAll<snowball>().empty())
			{
				// Spawn a new one and reduce the player's remaining lives
				_entityManager.create<snowball>(config::windowWidth * 0.5f, config::windowHeight * 0.5f);
				--_lives;

				_state = gameStates::INACTIVE;
			}

			if (_entityManager.getAll<brick>().empty())
			{
				_state = gameStates::WON;
			}

			if (_lives <= 0)
			{
				_state = gameStates::GAME_OVER;
			}

			_textLives.setString("Lives: " + std::to_string(_lives));

			_entityManager.update();

			// For every ball, call a function which
			//    For every brick, call a function which
			//         Calls handle_collision with the ball and the brick as arguments
			_entityManager.applyAll<snowball>([this](auto &snowball)
											  { _entityManager.applyAll<brick>([&snowball](auto &brick)
																			   { handleCollision(snowball, brick); }); });

			_entityManager.applyAll<snowball>([this](auto &snowball)
											  { _entityManager.applyAll<snowboard>([&snowball](auto &snowboard)
																				   { handleCollision(snowball, snowboard); }); });
			_entityManager.refresh();
			_entityManager.draw(game_window);
			_textState.setString("");
			game_window.draw(_textState);
			break;
		}
		case gameStates::INACTIVE:
		{
			_entityManager.draw(game_window);
			_textState.setString("  Paused  ");
			_textLives.setString("Lives: " + std::to_string(_lives));
			break;
		}
		case gameStates::GAME_OVER:
		{
			_textState.setString("Game Over!");
			_textLives.setString("");
			break;
		}
		case gameStates::WON:
		{
			_entityManager.draw(game_window);
			_textState.setString(" You Won! ");
			break;
		}
		default:
			break;
		}

		game_window.draw(_textState);
		game_window.draw(_textLives);
		game_window.display();
	}
}
