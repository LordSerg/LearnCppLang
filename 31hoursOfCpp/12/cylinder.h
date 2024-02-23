#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"
class Cylinder
{
    public:
        Cylinder() = default;
        Cylinder(double rad, double hght);
        double volume();
        void set_radius(double);
        void set_height(double);

        double get_radius();
        double get_height();

    private:
        double height{1};
        double radius{1};
};

#endif