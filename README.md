# 🌌 N-Body Simulator in C++

A professional-grade 3D gravitational N-body simulation engine written in modern C++.

## 🚀 Overview

This project simulates the gravitational interaction between multiple celestial bodies. It serves as a practical implementation of **Object-Oriented Programming (OOP)** and **Numerical Physics** in C++.

## 🛠️ Key Technical Features

- **3D Physics**: Full support for X, Y, and Z coordinates[cite: 6].
- **Leapfrog Integration**: Uses a symplectic integrator (Leapfrog) to ensure better energy conservation compared to simple Euler methods[cite: 1].
- **Numerical Stability**: Implements a "Softening" parameter to prevent singularities during close particle encounters[cite: 1].
- **Modern C++**: Utilizes `std::vector` for memory management and `<random>` for scientific-grade random data generation[cite: 2].

## 🧱 Project Structure

- `include/`: Header files (.hpp) defining the class interfaces.
- `src/`: Implementation files (.cpp) with the simulation logic.
- `CMakeLists.txt`: Build configuration for cross-platform support[cite: 5].

## ▶️ Build and Run
```bash
mkdir build && cd build
cmake ..
make
./nbody
```