#pragma once 
//particle of the simulation
class ball
{
    //coordinates [0:width , 0:height]
    int _x{},_y{};
    //where ball goes next
    int _dx{},_dy{};
public:
    void move();
    ball(int x, int y):_x(x),_y(y){}
    ball(int x, int y, int dx, int dy):_x(x),_y(y),_dx(dx),_dy(dy){}
};