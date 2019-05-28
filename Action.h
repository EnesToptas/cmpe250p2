//
// Created by menes on 28.10.2018.
//

#ifndef ACTION_H
#define ACTION_H

#include <string>
#include "Passenger.h"


using namespace std;

class Action {
public:
    Action (Passenger* passenger,string type,int TIME);
    Passenger* passenger;
    string action_type; // can be arrival, lcounter, scounter
    int time;
};


#endif //ACTION_H
