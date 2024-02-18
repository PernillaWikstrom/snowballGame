#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "snowball.hpp"
#include "snowboard.hpp"
#include "brick.hpp"

bool isColliding(const entity &e1, const entity &e2);

void handleCollision(snowball &snowball, const snowboard &snowboard);

void handleCollision(snowball &snowball, brick &brick);

#endif // INTERACTIONS_H