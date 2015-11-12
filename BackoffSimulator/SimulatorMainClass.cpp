#include <iostream>
#include "SimulationClass.h"
#include "Backoff options/StaticSimulationClass.h"

using namespace std;

int main() {
    cout << "Welcome!" << endl;
    cout << "Today we'll simulate backoff algorithms." << endl;
    SimulationClass* simulation = new StaticSimulationClass(2,10);

    simulation->showNodes();
    simulation->startSimulation();
    simulation->showNodes();
    simulation->showW();

    delete simulation;

    return 0;
}