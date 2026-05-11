#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "Particle.hpp"


int main() {

    int n_particles;// Number of particles
    bool random_particles = false; // Whether to initialize particles with random positions and velocities
    
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

    // Opening a CSV file to save the simulation data
    std::ofstream outFile("simulation_data.csv");
    outFile << "step,id,x,y,z\n"; // Header 

    double dt = 0.01; // Reduced time step for better stability in Leapfrog integration
    int n_steps = 500; // Total number of simulation steps

    for (int step = 0; step < n_steps; ++step) {
        // 1. Position Update (Leapfrog Step 1)
        for (auto& p : particles) p.updatePosition(dt);

        // 2. Force Calculation (N^2)
        for (auto& p : particles) p.resetAcceleration();
        for (size_t i = 0; i < particles.size(); ++i) {
            for (size_t j = 0; j < particles.size(); ++j) {
                if (i != j) particles[i].addForce(particles[j]);
            }
        }

        // 3. Velocity Update and CSV Saving (Leapfrog Step 2)
        for (size_t i = 0; i < particles.size(); ++i) {
            particles[i].updateVelocity(dt);
            
            // Saving the current state of each particle to the CSV file
            outFile << step << "," << i << "," 
                    << particles[i].position.x << "," 
                    << particles[i].position.y << "," 
                    << particles[i].position.z << "\n";
        }
    }

    outFile.close();
    std::cout << "Simulation completed. Data saved to simulation_data.csv" << std::endl;

    return 0;
}