#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <iostream>

// 3D vector struct
struct Vector3D {
    double x, y, z;
};


class Particle {
public:
    Vector3D position;
    Vector3D velocity;
    Vector3D acceleration;
    double mass;

    Particle(double x, double y, double z, double vx, double vy, double vz, double m);

    void updatePosition(double dt);
    void updateVelocity(double dt);
    void print() const;
    void resetAcceleration();
    void addForce(const Particle& other);
};

#endif