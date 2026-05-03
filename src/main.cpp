#include <iostream>
#include <vector>
#include <random>
#include "Particle.hpp"


int main() {

    int n_particles;// Number of particles
    bool random_particles = true; // Whether to initialize particles with random positions and velocities
    
    std::cout << "--- Starting N_Body Simulation (3D Leapfrog) ---" << std::endl;
    std::vector<Particle> particles;

    if (random_particles) {
        n_particles = 10; 
        std::cout << "Initializing with random positions and velocities for " << n_particles << " particles." << std::endl;
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> dist(0.0, 0.5); 
        std::normal_distribution<> vel_dist(0.0, 0.1);

        for (int i = 0; i < n_particles; ++i) {
            particles.emplace_back(dist(gen), dist(gen), dist(gen), 
                                   vel_dist(gen), vel_dist(gen), vel_dist(gen), 1.0);
        }
    } else {
        std::cout << "Initializing with predefined particles (2-body system)." << std::endl;
        n_particles = 2;
        particles.emplace_back(0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 1.0);
        particles.emplace_back(1.0, 1.0, 0.0, -0.1, 0.0, 0.0, 1.0);
    }

    double dt = 0.01; // Reduced time step for better stability in Leapfrog integration

    for (int step = 0; step < 100; ++step) {
        // 1. Position Update (Leapfrog Step 1)
        for (auto& p : particles) p.updatePosition(dt);

        // 2. Force Calculation (N^2)
        for (auto& p : particles) p.resetAcceleration();
        for (size_t i = 0; i < particles.size(); ++i) {
            for (size_t j = 0; j < particles.size(); ++j) {
                if (i != j) particles[i].addForce(particles[j]);
            }
        }

        // 3. Velocity Update and Print (Leapfrog Step 2)
        if (step % 10 == 0) std::cout << "Step " << step << ":" << std::endl;
        for (auto& p : particles) {
            p.updateVelocity(dt);
            if (step % 10 == 0) p.print();
        }
    }

    return 0;
}