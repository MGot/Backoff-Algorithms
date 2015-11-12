//
// Created by afro on 18.10.15.
//

#ifndef BACKOFFSIMULATOR_STATICSIMULATIONCLASS_H
#define BACKOFFSIMULATOR_STATICSIMULATIONCLASS_H

#include "../SimulationClass.h"
#include "NodeClass.h"

#include <vector>

class StaticSimulationClass : public SimulationClass {
public:
    // CSTR % DSTR
    StaticSimulationClass(long long, long long); // arguments: size of W, amount of nodes
    virtual ~StaticSimulationClass();

    // GETTERS
    long long getAmountOfNodes();  // returns number of threads
    long long getRounds(); // returns number of conducted rounds

    // INHERITED
    void showNodes();  // showing fields of every node
    void startSimulation();  // starting simulation
    bool checkNodes(); // true if every node sent otherwise false
    unsigned int countEnergyPoints(); // counting energy points for all of the nodes

private:
    long long amountOfNodes;  // amount of running threads (stations)
    std::vector<NodeClass> nodes;
    long long numberOfRounds;  // number of conducted rounds
    long long numberOfConflicts;  // number of conflicts in simulation
    void saveSimulationData();
};


#endif //BACKOFFSIMULATOR_STATICSIMULATIONCLASS_H
