#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle 
{
public:
Circle();
Circle(float rad);

void set_radius(double r);      
double get_radius() const;            


bool operator<(Circle const& c) const;
bool operator>(Circle const& c) const;
bool operator==(Circle const& c) const;

private:
float rad;
    
};


#endif
