//
// Created by afro on 18.10.15.
//

#include "StaticSimulationClass.h"
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

/***************CSTR & DSTR***********************/
StaticSimulationClass::StaticSimulationClass(long long size, long long amount)
        : SimulationClass(size), amountOfNodes(amount), numberOfRounds(1), numberOfConflicts(0)
{
    //nodes.resize(amount);

    for(long long i = 0; i < amountOfNodes; ++i)
        nodes.push_back(NodeClass(i));
}

StaticSimulationClass::~StaticSimulationClass()
{

}
/***************CSTR & DSTR***********************/


/***************GETTERS***********************/
long long StaticSimulationClass::getAmountOfNodes()
{
    return amountOfNodes;
}

void StaticSimulationClass::showNodes()
{
    for(auto i : nodes)
    {
        cout << i.getId() << " " << i.getEnergyPoints() << " "
        << i.getNumberofConflicts() << " " << i.getSendingStatus() << std::endl;
    }
}

long long StaticSimulationClass::getRounds()
{
    return numberOfRounds;
}

unsigned int StaticSimulationClass::countEnergyPoints()
{
    auto energyPoints = 0;
    for(auto i : nodes)
    {
        energyPoints += i.getEnergyPoints();
    }
    return energyPoints;
}
/***************GETTERS***********************/

/***************SIMULATION FUNCT***********************/
void StaticSimulationClass::startSimulation()
{
    /*for(long long i = 0; i<nodes.size(); ++i)
    {
        nodes[i].addEnergyPoints(i);
        nodes[i].addConflict(i+1);
        nodes[i].changeStatus();
    }*/
    srand((unsigned int) time( NULL ));
    unsigned long randSlot = 0;  // random slot
    unsigned long tempSize = 0; // temporary W size
    while(!checkNodes())
    {
        cout << endl << "ROUND: " << numberOfRounds << endl;
        for(auto i : nodes)
        {
            if(!i.getSendingStatus()) // true if sending status is false; the package was not sent
            {
                randSlot = rand() % W->size();
                cout <<"NodeID :" << i.getId() << " RandomSlot: " << randSlot << endl;//" W.size() = " << W->size() << endl;
                i.addEnergyPoints(1);
                if(W->at(randSlot) != -1)  // if true, we have conflict
                {
                    cout << "Conflict on slot " << randSlot << endl;
                    nodes[randSlot].addConflict();
                    W->at(randSlot) = -2;
                    numberOfConflicts++;
                }
                else  // no conflict, assign node id to slot
                {
                    W->at(randSlot) = i.getId();
                }
            }
        }
        for(auto i : *W)
        {
            if(i != -2)
                nodes[i].changeStatus();
        }
        numberOfRounds++;
        tempSize = W->size();
        W->clear();
        W->resize(2*tempSize, -1);
    }
    cout << endl << endl;
    cout << "End of the simulation." << endl;
    saveSimulationData();
}

bool StaticSimulationClass::checkNodes()
{
    for(auto i : nodes)
        if(!i.getSendingStatus())
            return false;
    return true;
}

void StaticSimulationClass::saveSimulationData()
{
    /*
     *   Data file structure:
     *
     *   size of W
     *   number of nodes
     *   number of energy points
     *   number of rounds
     *   total number of conflicts
     *   number of conflicted slots
     */

    cout << "Saving datas to file..." << endl;
    fstream file;
    try
    {
        file.open("/home/afro/ClionProjects/BackoffSimulator/simulation_datas.txt", ios::out | ios::trunc);
        file << W->size() << endl;
        file << nodes.size() << endl;
        file << countEnergyPoints() << endl;
        file << numberOfRounds << endl;
        //file << total number of conflicts << endl;
        //file << numberOfConflicts;
        file.close();
    }
    catch(string str)
    {
        cout << "Error: " << str << endl;
    }
    cout << "End of saving" << endl;
}
/***************SIMULATION FUNCT***********************/