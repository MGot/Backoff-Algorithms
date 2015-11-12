//
// Created by afro on 18.10.15.
//

#include "NodeClass.h"


NodeClass::NodeClass(long long id) : id(id), energyPoints(0), sendingStatus(false), numberOfConflicts(0)
{

}

NodeClass::~NodeClass()
{

}

/***************GETTERS***********************/
long long NodeClass::getEnergyPoints()
{
    return energyPoints;
}

long long NodeClass::getId()
{
    return id;
}

long long NodeClass::getNumberofConflicts()
{
    return numberOfConflicts;
}
bool NodeClass::getSendingStatus()
{
    return sendingStatus;
}
/***************GETTERS***********************/


/***************SETTERS***********************/
void NodeClass::addConflict()
{
    numberOfConflicts++;
}

void NodeClass::addEnergyPoints(long long numberOf)
{
    energyPoints += numberOf;
}

void NodeClass::changeStatus()
{
    sendingStatus = true;
}
/***************SETTERS***********************/