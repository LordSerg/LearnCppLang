#pragma once
#include "ball.hpp"
#include <vector>
//class that represents static points for collision
class grid
{

public:
    static void generate();
    static void checkCollision(std::vector<ball> balls);
};
//grid is a part of simulation, where every barier-point is 2*2 pixel in checkers order:
/*
11    11    11    11    11    11    11
    11    11    11    11    11    11    11
11    11    11    11    11    11    11
    11    11    11    11    11    11    11
11    11    11    11    11    11    11
    11    11    11    11    11    11    11
11    11    11    11    11    11    11
    11    11    11    11    11    11    11
11    11    11    11    11    11    11
    11    11    11    11    11    11    11
*/