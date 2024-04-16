#include "simulation.hpp"

void simulation::moveBalls(){}

void simulation::checkCollision(){}

void simulation::draw(){}

simulation::simulation()
{
    //assume, that number_of_balls = 500 and bps = 20
    g=grid();
    balls = std::vector<ball>();
    cells = std::vector<cell>();
}

simulation::simulation(int number_of_balls, int bps)
{
    g=grid();
    balls = std::vector<ball>();
    cells = std::vector<cell>();
}