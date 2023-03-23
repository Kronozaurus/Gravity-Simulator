#pragma once

#include <iostream>
#include <vector>
#include <sstream>

#include "celestial_body.h"

class Simulation {
    public:
        //Constructors, destructors
        Simulation();
        virtual ~Simulation();

        //Functions

        void pollEvents();

        void update();
        void render();
        

        //Accessors
        const bool getWindowIsOpen() const;

    private:
        //Variables
        sf::RenderWindow* window; //dynamic allocation - we want to delete it when we need to
        sf::VideoMode videoMode;
        sf::Event event;

        std::vector<CelestialBody> bodies;

        //Simulation variables
        int maxBodies;
        double totalForce_x, totalForce_y;
        double STEP;

        //Simulation objects
        CelestialBody celBody;

        //Functions
        void initVariable();
        void initWindow();
        void initObjects();
};