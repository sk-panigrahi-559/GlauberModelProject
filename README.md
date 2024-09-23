# Glauber Model of Heavy Ion Collisions

## Overview

This project implements the **Glauber Model**, a geometric approach used to simulate and understand heavy-ion collisions. The Glauber model is widely applied in high-energy nuclear physics to describe the number of participants (nucleons involved in the collision) and the number of binary collisions in a collision between two heavy nuclei.

The purpose of this project is to compute essential properties of nuclear collisions, such as the impact parameter, number of participants, and the distribution of collisions using a Monte Carlo approach.

## Project Structure

├── main.cpp
├── MyLibraries
│   ├── Collision.cpp
│   ├── Collision.h
│   ├── Nucleon.cpp
│   ├── Nucleon.h
│   ├── Nucleus.cpp
│   ├── Nucleus.h
│   ├── mathematicalfunctions.cpp
│   ├── mathematicalfunctions.h
└── Builds
    ├── Makefile
    ├── GlauberModel (target executable)
    ├── *.o (object files)

## Files and Directories:

- main.cpp: Contains the main entry point of the program and controls the flow of the simulation.

- MyLibraries/: This directory holds the following components:
Collision: Handles the collision process, calculating impact parameters and interactions between nuclei.
Nucleon: Represents an individual nucleon within a nucleus.
Nucleus: Manages the entire nucleus, including the distribution of nucleons and their positions.

- mathematicalfunctions: Provides various helper functions for calculations, such as geometric distributions and random number generation.

- Builds/: Contains the compiled object files and the final executable (GlauberModel). The Makefile is also located here, which automates the compilation process.
