#include "Particle.hpp"
#include <cmath>

const double G = 1.0; // Gravitational constant
const double SOFTENING = 1e-3; // "Softening" factor to prevent singularities in force calculations

Particle::Particle(double x, double y, double z, double vx, double vy, double vz, double m)
    : mass(m) {
    position = {x, y, z};
    velocity = {vx, vy, vz};
    acceleration = {0.0, 0.0, 0.0};
}

// In Leapfrog, position is updated using the current velocity and acceleration, then velocity is updated using the new acceleration
void Particle::updatePosition(double dt) {
    position.x += velocity.x * dt + 0.5 * acceleration.x * dt * dt;
    position.y += velocity.y * dt + 0.5 * acceleration.y * dt * dt;
    position.z += velocity.z * dt + 0.5 * acceleration.z * dt * dt;
}

void Particle::updateVelocity(double dt) {
    // Questo verrà chiamato dopo aver aggiornato l'accelerazione
    velocity.x += acceleration.x * dt;
    velocity.y += acceleration.y * dt;
    velocity.z += acceleration.z * dt;
}

void Particle::resetAcceleration() {
    acceleration = {0.0, 0.0, 0.0};
}


void Particle::print() const {
    std::cout << "Pos: (" << position.x << ", " << position.y << ", " << position.z << ") "
              << "Vel: (" << velocity.x << ", " << velocity.y << ", " << velocity.z << ")" << std::endl;
}


void Particle::addForce(const Particle& other) {
    double dx = other.position.x - position.x;
    double dy = other.position.y - position.y;
    double dz = other.position.z - position.z;

    // 3D distance with "softening" for numerical stability
    double distSq = dx*dx + dy*dy + dz*dz + SOFTENING;
    double dist = std::sqrt(distSq);

    double force = (G * mass * other.mass) / distSq;

    // Acceleration a = F / m = (G * m_other) / r^2
    double invDist = 1.0 / dist;
    acceleration.x += force * (dx * invDist) / mass;
    acceleration.y += force * (dy * invDist) / mass;
    acceleration.z += force * (dz * invDist) / mass;
}