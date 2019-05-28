//
// Created by menes on 28.10.2018.
//

#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <queue>
#include "Action.h"
#include "Passenger.h"
#include <string>

using namespace std;


class EventQueue {
struct CompareAction{
    bool operator()(Action & a1, Action & a2){
        if (a1.time < a2.time)
            return false;
        else if (a1.time == a2.time){
            if (a1.action_type == a2.action_type){
                if (a1.passenger->Arrive_time < a2.passenger->Arrive_time)
                    return false;
                else
                    return true;
            }
            if (a1.action_type == "scounter")
                return false;
            if (a2.action_type == "scounter")
                return true;
            if (a1.action_type == "lcounter" && a2.action_type == "arrival")
                return false;
            if (a1.action_type == "arrival" && a2.action_type == "lcounter")
                return true;
        }
        else
            return true;
    return true;
    }
};
struct ComparisonForQueues {
    bool operator()(Passenger *a1, Passenger *a2) {
        if (a1->Board_time < a2->Board_time)
            return false;
        else if (a1->Board_time == a2->Board_time){
            if (a1->Arrive_time < a2->Arrive_time)
                return false;
            else
                return true;
        }
        else
            return true;
    }
};
struct counter{
    bool isEmpty = true;
    Passenger* passenger;
    int busyTime = 0;
};
public:

    priority_queue<Action,vector<Action>,CompareAction> Events;
    void addPerson(Passenger* passenger);
    void LCounterEmpty(Passenger* passenger);
    void SCounterEmpty(Passenger* passenger);
    void createCounter(int N,string W);
    void pop(bool vipCheck, bool lugCheck);
    void popfifo(bool vipCheck, bool lugCheck);
    double waiting_time = 0;
    int TIME = 0;
    int get_in = 0;
    int missed = 0;
    vector<counter> counters;
    vector<counter> scounters;
    priority_queue<Passenger*,vector<Passenger*>,ComparisonForQueues> luggagequeue;
    priority_queue<Passenger*,vector<Passenger*>,ComparisonForQueues> securityqueue;
    queue<Passenger*> lqfifo;
    queue<Passenger*> sqfifo;
};


#endif //EVENTQUEUE_H
