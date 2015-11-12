//
// Created by afro on 18.10.15.
//

#include "SimulationClass.h"
#include <iostream>


SimulationClass::SimulationClass(long long size)
{
    W->resize(size, -1);
}

SimulationClass::~SimulationClass()
{
    delete W;
}

void SimulationClass::showW()
{
    for(auto i = 0; i< W->size(); ++i)
    {
        std::cout << "W[" << i << "] = " << W->at(i) << "\t";
    }
    std::cout << std::endl;
}