#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp> 

class CelestialBody {
    public:
        //Constructors, destructors
        CelestialBody();
        virtual ~CelestialBody();

        //Functions
        void setProtoPlanet(const sf::RenderTarget*);
        void setProtoStar(const sf::RenderTarget*);

        void forceBetweenBodies(CelestialBody, double);
        
        void updateBody(double);
        void renderBody(sf::RenderTarget*);

        friend class Simulation;

    private:
        //Variables
        double x, y; // coordinates in space
        double vel_x, vel_y; //velocity in the specified direction (km/s)
        double force_x, force_y;
        double distanceToStar;
        double mass; // kg
        double radius; // km, scale 1px = 10 000 km

        double const G = 6.6743 * pow(10, -11);
        double const AU = 150 * pow (10, 6) * 1000;
        double const SCALE = 250 / AU;

        std::string type;
        sf::CircleShape shape;


};