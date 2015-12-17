#include <iostream>
#include <fstream>
#include <memory>
#include "SimulationClass.h"
#include "Backoff options/StaticSimulationClass.h"

using namespace std;

void saveSimulationData(int option, SimulationClass &s);


int main() {
    cout << "Welcome!" << endl;
    cout << "Today we'll simulate backoff algorithms." << endl;
    fstream file;
    int nodes = 100000;
    unsigned int numberOfRounds = 100;
    // SIMULATION 1
    file.open("/home/afro/Dokumenty/Praca Inżynierska/Kody/eP_t.txt", ios::out | ios::trunc);
    file << numberOfRounds << endl;
    file.close();

    for(int i = 0; i < numberOfRounds; ++i)
    {
        unique_ptr<SimulationClass> simulation(new StaticSimulationClass(2, nodes));
        simulation->startSimulation();
        saveSimulationData(0, *simulation);
        simulation.reset(nullptr);
    }

    //SIMULATION 2 & 3
    /*file.open("/home/afro/Dokumenty/Praca Inżynierska/Kody/t_N.txt", ios::out | ios::trunc);
    file << nodes << endl;
    file.close();

    file.open("/home/afro/Dokumenty/Praca Inżynierska/Kody/eP_N.txt", ios::out | ios::trunc);
    file << nodes << endl;
    file.close();
    for(int i = 1; i <= nodes; ++i)
    {
        unique_ptr<SimulationClass> simulation(new StaticSimulationClass(2, i));
        simulation->startSimulation();
        saveSimulationData(1, *simulation);
        saveSimulationData(2, *simulation);
        simulation.reset(nullptr);
    }*/

    cout << "End of simulation" << endl;

    return 0;
}


void saveSimulationData(int option, SimulationClass &s)
{
    fstream file;
    switch(option)
    {
        case 0:
            /*
             *   Data file structure:
             *
             *   time of running
             *   number of energy points
             */
            try
            {
                file.open("/home/afro/Dokumenty/Praca Inżynierska/Kody/eP_t.txt", ios::out | ios::app);
                file << s.countEnergyPoints() << endl;
                file << s.getRunningTime() << endl;
                file.close();
            }
            catch(string str)
            {
                cout << "Error: " << str << endl;
            }
            break;

        case 1:
            /*
             *   Data file structure:
             *
             *   time of running
             *   number of nodes
             */
            try
            {
                file.open("/home/afro/Dokumenty/Praca Inżynierska/Kody/t_N.txt", ios::out | ios::app);
                file << s.getRunningTime() << endl;
                file << s.getAmountOfNodes() << endl;
                file.close();
            }
            catch(string str)
            {
                cout << "Error: " << str << endl;
            }
            break;

        case 2:
            /*
             *   Data file structure:
             *
             *   number of energy points
             *   number of nodes
             */
            try
            {
                file.open("/home/afro/Dokumenty/Praca Inżynierska/Kody/eP_N.txt", ios::out | ios::app);
                file << s.countEnergyPoints() << endl;
                file << s.getAmountOfNodes() << endl;
                file.close();
            }
            catch(string str)
            {
                cout << "Error: " << str << endl;
            }
            break;
    }
}