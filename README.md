# DynaVerse Engine

DynaVerse is a versatile and powerful 2D/3D physics and collision detection engine designed to empower game developers. Built in C++, DynaVerse aims to provide a robust and efficient solution for simulating realistic physical interactions and behaviors within game environments.

## Key Features

- **2D & 3D Physics Simulation:** Simulates realistic physical interactions and behaviors for both 2D and 3D objects.
- **Collision Detection:**  Efficiently detects collisions between various geometric shapes, including circles, AABBs, and more complex shapes (planned).
- **Collision Response:**  Resolves collisions using impulse-based methods to prevent interpenetration and create believable interactions.
- **Modular Design:**  Organized into clear modules (math, dynamics, collision, etc.) for easy maintainability and extensibility.
- **C++ Implementation:**  Leverages the performance and flexibility of C++ for optimal efficiency and control.

## Goals

- **Versatility:** Provide a unified solution that handles both 2D and 3D physics seamlessly.
- **Efficiency:** Optimize performance for real-time game simulations.
- **Ease of Use:**  Offer a clear and intuitive API for game developers to integrate DynaVerse into their projects.
- **Extensibility:**  Enable developers to add custom features and behaviors to suit their specific game requirements.

## Current Status

- **2D Physics:**  Core 2D physics engine with basic rigid body dynamics, gravity, and circle-circle collision detection/response.
- **3D Physics:**  Initial structure in place, with `Vector3D` and `RigidBody3D` classes defined.
- **Collision Detection:**  Basic AABB collision detection implemented.

## Future Plans

- **Expand Collision Detection:** Add support for more complex shapes and collision detection algorithms.
- **Implement 3D Physics:**  Complete the 3D physics engine with full rigid body dynamics, quaternions, and collision handling
- **Optimize Performance:** Profile and optimize critical areas for real-time game performance.
- **Add Visualization:** Integrate with a graphics library to visualize the physics simulations.
- **Extensive Documentation:**  Provide detailed documentation and examples to guide developers in using DynaVerse effectively

## Getting Started

- **Prerequisites:**  A C++ compiler and a build system (e.g., CMake)
- **Build Instructions:**  Detailed build instructions will be added soon.

## Contributing

Contributions are welcome! Please read the CONTRIBUTING.md file for guidelines on how to contribute to DynaVerse

## License

DynaVerse is currently unlicensed. A suitable open-source license will be added soon

Let's build amazing games together with DynaVerse!
