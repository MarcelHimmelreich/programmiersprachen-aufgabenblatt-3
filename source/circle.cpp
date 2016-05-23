#include "circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle():
rad{1}
{}

Circle::Circle(float rad_):
rad{rad_}
{}

void Circle::set_radius(double r)
{
	rad=r;
}      

double Circle::get_radius() const //const
{
	return rad;
}

bool Circle::operator<(Circle const& i) const
{
	return rad < i.rad;
}
bool Circle::operator>(Circle const& i) const
{
	return rad > i.rad;
}
bool Circle::operator==(Circle const& i) const
{
	return rad== i.rad;
}
