#include "simulation.h"

//Functions

void Simulation::pollEvents() {
    //Event polling
    while (this->window->pollEvent(this->event)) {
        
        switch(this->event.type){

            case sf::Event::Closed : {
                this->window->close();
                break;
            }

            case sf::Event::KeyPressed : {
                if(this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break; 
            }
        }
    }
}

void Simulation::update() {

    for(int i = 0; i < maxBodies; i++) {

        for(int j = 0; j <= maxBodies; j++){
            bodies[i].forceBetweenBodies(bodies[j], STEP);
        }
        bodies[i].updateBody(STEP);
    }

    this->pollEvents();

}

void Simulation::render() {

    //Clear old frame
    this->window->clear();

    //Draw frame
    for (auto &body : this->bodies){
        this->window->draw(body.shape);
    }


    //Display frame in window
    this->window->display();
}

//Accessors

const bool Simulation::getWindowIsOpen() const {
    return this->window->isOpen();
}

//Private functions

void Simulation::initVariable() {

    this->window = nullptr;
    this->maxBodies = 7;
    this->STEP = 3600 * 24; // 1 day in seconds
 
}

void Simulation::initWindow() {

    this->videoMode.height = 800;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Gravity Simulator", sf::Style::Titlebar | sf::Style::Close );
    this->window->setFramerateLimit(60);
}

void Simulation::initObjects() {

    for(int i = 0; i < maxBodies; i++){
        this->celBody.setProtoPlanet(this->window);
        bodies.emplace_back(celBody);
    }
    
    this->celBody.setProtoStar(this->window);
    bodies.emplace_back(celBody);

}


//Constructors, destructors

Simulation::Simulation() {

    this->initVariable();
    this->initWindow();
    this->initObjects();

}

Simulation::~Simulation() {

    delete this->window;

}