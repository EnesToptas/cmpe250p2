//
// Created by menes on 28.10.2018.
//

#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
using namespace std;

class Passenger {
public:
    int Arrive_time;
    int Board_time;
    int Luggage_time;
    int Security_time;
    int Got_in_queue;
    bool vip;
    bool luggage;
    int Wait_time;

    Passenger(int AT, int BT, int LT, int ST, string V, string L);
};


#endif //PASSENGER_H
