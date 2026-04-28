#include <iostream>
#include <vector>
#include <cmath>


// 2D vector struct to represent position and velocity
struct Vector2D {
    double x, y;
};

// Class Particle: the heart of our simulator
class Particle {
public:
    Vector2D position;
    Vector2D velocity;
    double mass;

    Particle(double x, double y, double vx, double vy, double m) 
        : mass(m) {
        position = {x, y};
        velocity = {vx, vy};
    }

    // Method to update the position based on velocity (Simple Euler)
    void update(double dt) {
        position.x += velocity.x * dt;
        position.y += velocity.y * dt;
    }

    void print() const {
        std::cout << "Pos: (" << position.x << ", " << position.y << ") "
                  << "Vel: (" << velocity.x << ", " << velocity.y << ")" << std::endl;
    }
};

int main() {
    std::cout << "--- Inizio Simulazione N-Body ---" << std::endl;

    // Creiamo una "lista" di particelle usando il container standard del C++: std::vector
    std::vector<Particle> particles;
    
    // Aggiungiamo due particelle di prova
    particles.emplace_back(0.0, 0.0, 0.1, 0.0, 1.0);  // Particella 1
    particles.emplace_back(1.0, 1.0, -0.1, 0.0, 1.0); // Particella 2

    double dt = 0.1; // Passo temporale

    // Simuliamo 10 step temporali
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