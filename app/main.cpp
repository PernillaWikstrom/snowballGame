#include <iostream>
#include "entityManager.hpp"

#include "projectConfig.hpp"

int main()
{
	std::cout << project_name << " v" << project_version << '\n';
	gameManager game;
	game.reset();
	game.run();
}