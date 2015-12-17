//
// Created by afro on 18.10.15.
//

#ifndef BACKOFFSIMULATOR_SIMULATIONCLASS_H
#define BACKOFFSIMULATOR_SIMULATIONCLASS_H

#include <vector>

class SimulationClass {
public:

    //DSTR
    virtual ~SimulationClass();

    // BASE FUNCTIONS
    virtual void startSimulation() = 0;
    virtual void showNodes() = 0;
    virtual bool checkNodes() = 0;
    virtual unsigned long long getRunningTime() = 0;
    virtual unsigned long long getAmountOfNodes() = 0;

    virtual unsigned int countEnergyPoints() = 0;
    void showW(); // showing all slots

protected:
    SimulationClass(long long); // CSTR
    std::vector<long long> *W = new std::vector<long long>;  // backoff algorithm window
};


#endif //BACKOFFSIMULATOR_SIMULATIONCLASS_H
