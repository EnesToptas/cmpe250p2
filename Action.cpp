//
// Created by menes on 28.10.2018.
//

#include <iostream>
#include "Action.h"


Action::Action(Passenger* passenger, string type,int TIME) {
    this->passenger = passenger;
    this->action_type = type;
    if (action_type == "arrival"){
        time = passenger->Arrive_time;
    }
    if (action_type == "lcounter"){
        time = TIME + passenger->Luggage_time;
    }
    if (action_type == "scounter"){
        time = TIME + passenger->Security_time;
    }

}


