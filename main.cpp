#include <iostream>

#include "simulation.h"


int main() {

    //Random init
    srand(static_cast<unsigned>(time(NULL)));

    Simulation mySimulation;

    //Simulation loop
    while (mySimulation.getWindowIsOpen()) {

        //Update
        mySimulation.update();

        //Render
        mySimulation.render();

    }

    return 0;
}