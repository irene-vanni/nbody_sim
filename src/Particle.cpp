#include "Particle.hpp"

Particle::Particle(double x, double y, double vx, double vy, double m)
    : mass(m) {
    position = {x, y};
    velocity = {vx, vy};
}

void Particle::update(double dt) {
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
}

void Particle::print() const {
    std::cout << "Pos: (" << position.x << ", " << position.y << ") "
              << "Vel: (" << velocity.x << ", " << velocity.y << ")" << std::endl;
}