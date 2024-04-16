#pragma once
#include "ball.hpp"
#include "cell.hpp"
#include "grid.hpp"
#include <vector>
class simulation
{
    /// @brief particles of the simulation
    std::vector<ball>balls;
    /// @brief endpoint cells, where particles eventually fall
    std::vector<cell>cells;
    /// @brief triangular grid, distributor
    grid g;
public:
    simulation();
    simulation (int number_of_balls, int balls_per_sec);
    /// @brief move every particle by one step
    void moveBalls();
    /// @brief check every particle for collision and move, if nesessary
    void checkCollision();
    /// @brief show whole simulation in GLwindow with GLFW
    void draw();
};