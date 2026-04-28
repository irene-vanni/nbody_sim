#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <iostream>

// 2D vector struct
struct Vector2D {
    double x, y;
};

class Particle {
public:
    Vector2D position;
    Vector2D velocity;
    double mass;

    Particle(double x, double y, double vx, double vy, double m);

    void update(double dt);
    void print() const;
};

#endif