//
// Created by afro on 17.12.15.
//

#include "AdditiveBackoff.h"
#include <ctime>


using namespace std;

/***************CSTR & DSTR***********************/
AdditiveBackoff::AdditiveBackoff(long long size, unsigned long long amount) :
        SimulationClass(size), amountOfNodes(amount), numberOfRounds(1), numberOfConflicts(0), timeOfRunning(0.0)
{
    //nodes.resize(amount);

    for(long long i = 0; i < amountOfNodes; ++i)
        nodes.push_back(new NodeClass(i));
}

AdditiveBackoff::~AdditiveBackoff()
{
    for(int i = 0; i<nodes.size(); ++i)
        delete nodes[i];
}
/***************CSTR & DSTR***********************/


/***************GETTERS***********************/
unsigned long long AdditiveBackoff::getAmountOfNodes()
{
    return amountOfNodes;
}

void AdditiveBackoff::showNodes()
{
    for(auto i : nodes)
    {
        //cout << i.getId() << " " << i.getEnergyPoints() << " "
        //<< i.getNumberofConflicts() << " " << i.getSendingStatus() << std::endl;
    }
}

long long AdditiveBackoff::getRounds()
{
    return numberOfRounds;
}

unsigned int AdditiveBackoff::countEnergyPoints()
{
    auto energyPoints = 0;
    for(auto i : nodes)
    {
        energyPoints += i->getEnergyPoints();
    }
    return energyPoints;
}

unsigned long long AdditiveBackoff::getRunningTime()
{
    return timeOfRunning;
}
/***************GETTERS***********************/

/***************SIMULATION FUNCT***********************/
void AdditiveBackoff::startSimulation()
{
    /*for(long long i = 0; i<nodes.size(); ++i)
    {
        nodes[i].addEnergyPoints(i);
        nodes[i].addConflict(i+1);
        nodes[i].changeStatus();
    }*/
    clock_t s, f;
    srand((unsigned int) time( NULL ));
    unsigned long randSlot = 0;  // random slot
    unsigned long tempSize = 0; // temporary W size
    s = clock();
    while(!checkNodes())
    {
        //cout << endl << "ROUND: " << numberOfRounds << endl;
        for(auto i : nodes)
        {
            if(!i->getSendingStatus()) // true if sending status is false; the package was not sent
            {
                randSlot = rand() % W->size();
                //cout <<"NodeID :" << i.getId() << " RandomSlot: " << randSlot << endl;//" W.size() = " << W->size() << endl;
                nodes[i->getId()]->addEnergyPoints();
                if(W->at(randSlot) != -1)  // if true, we have conflict
                {
                    //cout << "Conflict on slot " << randSlot << endl;
                    nodes[i->getId()]->addConflict();
                    W->at(randSlot) = -2;
                    numberOfConflicts++;
                }
                else  // no conflict, assign node id to slot
                {
                    W->at(randSlot) = i->getId();
                }
            }
        }
        for(int i = 0; i<W->size(); ++i)
        {
            if(W->at(i) != -2 && W->at(i) != -1)
                nodes[W->at(i)]->changeStatus();
        }
        numberOfRounds++;
        tempSize = W->size();
        W->clear();
        W->resize(tempSize+1, -1);
    }
    f = clock();
    //cout << endl << endl;
    //cout << "End of the simulation." << endl;
    timeOfRunning = f-s;
}

bool AdditiveBackoff::checkNodes()
{
    for(auto i : nodes)
        if(!i->getSendingStatus())
            return false;
    return true;
}
/***************SIMULATION FUNCT***********************/