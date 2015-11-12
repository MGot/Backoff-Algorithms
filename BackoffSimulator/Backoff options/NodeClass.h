//
// Created by afro on 18.10.15.
//

#ifndef BACKOFFSIMULATOR_NODECLASS_H
#define BACKOFFSIMULATOR_NODECLASS_H


class NodeClass {

public:

    //CSTR & DSTR
    explicit NodeClass() {};
    NodeClass(long long); // arguments: id
    virtual ~NodeClass();

    // GETTERS
    long long getEnergyPoints();  // returns number of energy points receivd by thread
    long long getId();  // returns Id of thread
    long long getNumberofConflicts(); // returns number of conflicts for node
    bool getSendingStatus(); // returns sending status (true = was sent; false = waiting for sending)


    //SETTERS
    void addConflict();  // add specific number of conflicts
    void addEnergyPoints(long long);  // add specific number of energy points
    void changeStatus();  // changes sendingStatus to true

private:
    long long id; // id of thread
    long long energyPoints;  // number of energy points received by thread
    bool sendingStatus;  // sending status (true = was sent; false = waiting for sending)
    long long numberOfConflicts; // saving number of conflicts
};


#endif //BACKOFFSIMULATOR_NODECLASS_H
