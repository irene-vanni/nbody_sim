# N-Body Simulator in C++

Simple 2D N-body simulation written in modern C++.

## 🚀 Project Overview

This project implements a basic particle simulation where objects move in 2D space.
The goal is to build a modular and extensible simulation engine, starting from simple motion and evolving toward full gravitational interaction.

## 🧱 Current Features

- Particle class with position, velocity, and mass
- Time integration using simple Euler method
- Multiple particles handled via `std::vector`
- Console-based output

## 🛠️ Technologies

- C++17
- CMake (build system)

## ▶️ How to Build and Run

```bash
mkdir build
cd build
cmake ..
make
./nbody