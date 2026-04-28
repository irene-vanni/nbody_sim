#include <iostream>
#include <vector>
#include "Particle.hpp"

int main() {
    std::cout << "--- Inizio Simulazione N-Body ---" << std::endl;

    std::vector<Particle> particles;

    particles.emplace_back(0.0, 0.0, 0.1, 0.0, 1.0);
    particles.emplace_back(1.0, 1.0, -0.1, 0.0, 1.0);

    double dt = 0.1;

    for (int step = 0; step < 10; ++step) {
        std::cout << "Step " << step << ":" << std::endl;
        for (auto& p : particles) {
            p.update(dt);
            p.print();
        }
        std::cout << "-----------------------" << std::endl;
    }

    return 0;
}