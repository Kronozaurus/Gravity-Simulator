#include "celestial_body.h"

//Functions

void CelestialBody :: setProtoStar (const sf::RenderTarget* target) {

    this->type = "Star";
    //this->radius = static_cast<double>(rand() % 500000 + 100000); //radius between 300k km and 800k km
    //this->mass = static_cast<double>(rand() % 45 + 90 ) * pow(10, 27);
    
    this->radius = 10;
    this->mass = 2 * pow(10, 12);

    this->shape.setRadius(radius); //scaled, 1px = 10 000 km
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setOutlineColor(sf::Color::Yellow);
    this->shape.setOutlineThickness(2.f);
    this->shape.setOrigin( //scaled, 1px = 10 000 km
        radius,
        radius 
    );
    this->shape.setPosition (
        (target->getSize().x / 2), 
        (target->getSize().y / 2) 
    );

    this->x = this->shape.getPosition().x;
    this->y = this->shape.getPosition().y;
    //std::cout << x << " " << y << " " << mass << std::endl;
}

void CelestialBody :: setProtoPlanet (const sf::RenderTarget* target) {

    this->type = "Planet";

    this->radius = static_cast<double>(rand() % 5 + 1); //radius between 1k km and 20k km
    this->mass = static_cast<double>(rand() % 100 + 1) * pow(10, 4);
    

    this->shape.setRadius(radius); //scaled, 1px = 10 000 km
    this->shape.setFillColor(sf::Color::Blue);
    this->shape.setOutlineColor(sf::Color::White);
    this->shape.setOutlineThickness(2.f);
    this->shape.setOrigin( //scaled, 1px = 10 000 km
        radius,
        radius 
    );
    this->shape.setPosition (
        static_cast<float> (rand() % static_cast<int>(target->getSize().x)),
        static_cast<float> (rand() % static_cast<int>(target->getSize().y))
    );
    

    this->x = this->shape.getPosition().x;
    this->y = this->shape.getPosition().y;

    if(this->shape.getPosition().y < target->getSize().y / 2 )
        this->vel_y = 10000;
    else
        this->vel_y = -10000;


    //std::cout << x << " " << y << " " << mass << std::endl;

}

void CelestialBody :: forceBetweenBodies (CelestialBody toCalc, double STEP) {

    double force = 0;

    double distance_x = toCalc.x - this->x;
    double distance_y = toCalc.y - this->y;
    //calculate the root of the distance between celestial bodies
    double distance = distance_x * distance_x + distance_y * distance_y;

    if(distance == 0) return;

    //if(toCalc.type == "Star") distanceToStar = distance;

    //calculate the force of gravity between bodies 
    //(mass of this body is obsolete, cause it negates itself later on)

    force = (G * toCalc.mass) / distance;
    std::cout << toCalc.mass << " " << force << std::endl;


    //calculate the angle and force components in the x and y direction
    //then increase the velocity by force a = F/m (where m was negated, so a = F)
    double angle = atan2(distance_y, distance_x);
    std::cout << angle << cos(angle) << std::endl;
    this->vel_x += cos(angle) * force * STEP;
    this->vel_y += sin(angle) * force * STEP;

}

void CelestialBody :: updateBody (double STEP) {
    this->x += this->vel_x * SCALE * STEP;
    this->y += this->vel_y * SCALE * STEP;
    std::cout << x  << " " << vel_x << " " << y << " " << vel_y << std::endl;
    shape.setPosition(x, y);
}

void CelestialBody :: renderBody (sf::RenderTarget* target) {

}

//Private Functions

//Construstors, dectructors

CelestialBody :: CelestialBody ()  {
    this->distanceToStar = 0;
    this->x = 0;
    this->y = 0;
    this->vel_x = 0;
    this->vel_y = 0;
    this->mass = 0;
    this->radius = 0;
}

CelestialBody :: ~CelestialBody () {

}