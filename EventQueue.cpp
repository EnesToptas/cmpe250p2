//
// Created by menes on 28.10.2018.
//

#include <iostream>
#include "EventQueue.h"



void EventQueue::addPerson(Passenger* passenger) {
    Events.push(*new Action(passenger,"arrival",TIME));
}
void EventQueue::pop(bool vipCheck, bool lugCheck) {
    const Action &top = Events.top();
    if (top.action_type == "arrival") {
        TIME = top.time;
        if (lugCheck) {
            if (top.passenger->luggage) {
                luggagequeue.push(top.passenger);
            } else {
                if (vipCheck) {
                    if (top.passenger->vip) {
                        top.passenger->Wait_time = TIME - top.passenger->Arrive_time;
                        waiting_time += top.passenger->Wait_time;
                        if (TIME <= top.passenger->Board_time)
                            get_in++;
                        else
                            missed++;
                    } else
                        securityqueue.push(top.passenger);
                } else {
                    securityqueue.push(top.passenger);
                }
            }
        } else
            luggagequeue.push(top.passenger);
    } else if (top.action_type == "lcounter") {
        for (int i = 0; i < counters.size(); i++) {
            if (&(*counters[i].passenger) == &(*top.passenger)) {
                TIME = top.time;
                counters[i].passenger = nullptr;
                counters[i].isEmpty = true;
                counters[i].busyTime = 0;
                if (vipCheck) {
                    if (top.passenger->vip) {
                        top.passenger->Wait_time = TIME - top.passenger->Arrive_time;
                        waiting_time += top.passenger->Wait_time;
                        if (TIME <= top.passenger->Board_time)
                            get_in++;
                        else
                            missed++;
                    } else
                        securityqueue.push(top.passenger);
                } else {
                    securityqueue.push(top.passenger);
                }
            }
        }
    } else {
        for (int i = 0; i < scounters.size(); i++) {
            if (&(*scounters[i].passenger) == &(*top.passenger)) {
                TIME = top.time;
                scounters[i].isEmpty = true;
                scounters[i].busyTime = 0;
                scounters[i].passenger->Wait_time = TIME - scounters[i].passenger->Arrive_time;
                waiting_time += scounters[i].passenger->Wait_time;
                scounters[i].passenger = nullptr;
                if (TIME <= top.passenger->Board_time)
                    get_in++;
                else
                    missed++;
            }
        }
    }
    if (luggagequeue.size() != 0) {
        for (int i = 0; i < counters.size(); i++) {
            if (counters[i].isEmpty) {
                if (luggagequeue.size() != 0) {
                    counters[i].passenger = luggagequeue.top();
                    counters[i].isEmpty = false;
                    counters[i].busyTime = counters[i].passenger->Luggage_time;
                    luggagequeue.pop();
                    LCounterEmpty(counters[i].passenger);
                }
            }
        }
    }
    if (securityqueue.size() != 0) {
        for (int i = 0; i < scounters.size(); i++) {
            if (scounters[i].isEmpty) {
                if (securityqueue.size() != 0) {
                    scounters[i].passenger = securityqueue.top();
                    scounters[i].isEmpty = false;
                    scounters[i].busyTime = scounters[i].passenger->Security_time;
                    securityqueue.pop();
                    SCounterEmpty(scounters[i].passenger);
                }
            }
        }
    }
    Events.pop();
}
void EventQueue::popfifo(bool vipCheck, bool lugCheck) {
    const Action &top = Events.top();
    if (top.action_type == "arrival") {
        TIME = top.time;
        if (lugCheck) {
            if (top.passenger->luggage) {
                lqfifo.push(top.passenger);
            } else {
                if (vipCheck) {
                    if (top.passenger->vip) {
                        top.passenger->Wait_time = TIME - top.passenger->Arrive_time;
                        waiting_time += top.passenger->Wait_time;
                        if (TIME <= top.passenger->Board_time)
                            get_in++;
                        else
                            missed++;
                    } else
                        sqfifo.push(top.passenger);
                } else {
                    sqfifo.push(top.passenger);
                }
            }
        } else
            lqfifo.push(top.passenger);
    } else if (top.action_type == "lcounter") {
        for (int i = 0; i < counters.size(); i++) {
            if (&(*counters[i].passenger) == &(*top.passenger)) {
                TIME = top.time;
                counters[i].passenger = nullptr;
                counters[i].isEmpty = true;
                counters[i].busyTime = 0;
                if (vipCheck) {
                    if (top.passenger->vip) {
                        top.passenger->Wait_time = TIME - top.passenger->Arrive_time;
                        waiting_time += top.passenger->Wait_time;
                        if (TIME <= top.passenger->Board_time)
                            get_in++;
                        else
                            missed++;
                    } else
                        sqfifo.push(top.passenger);
                } else {
                    sqfifo.push(top.passenger);
                }
            }
        }
    } else {
        for (int i = 0; i < scounters.size(); i++) {
            if (&(*scounters[i].passenger) == &(*top.passenger)) {
                TIME = top.time;
                scounters[i].isEmpty = true;
                scounters[i].busyTime = 0;
                scounters[i].passenger->Wait_time = TIME - scounters[i].passenger->Arrive_time;
                waiting_time += scounters[i].passenger->Wait_time;
                scounters[i].passenger = nullptr;
                if (TIME <= top.passenger->Board_time)
                    get_in++;
                else
                    missed++;
            }
        }
    }
    if (lqfifo.size() != 0) {
        for (int i = 0; i < counters.size(); i++) {
            if (counters[i].isEmpty) {
                if (lqfifo.size() != 0) {
                    counters[i].passenger = lqfifo.front();
                    counters[i].isEmpty = false;
                    counters[i].busyTime = counters[i].passenger->Luggage_time;
                    lqfifo.pop();
                    LCounterEmpty(counters[i].passenger);
                }
            }
        }
    }
    if (sqfifo.size() != 0) {
        for (int i = 0; i < scounters.size(); i++) {
            if (scounters[i].isEmpty) {
                if (sqfifo.size() != 0) {
                    scounters[i].passenger = sqfifo.front();
                    scounters[i].isEmpty = false;
                    scounters[i].busyTime = scounters[i].passenger->Security_time;
                    sqfifo.pop();
                    SCounterEmpty(scounters[i].passenger);
                }
            }
        }
    }
    Events.pop();
}
void EventQueue::LCounterEmpty(Passenger *passenger) {
    Events.push(*new Action(passenger,"lcounter",TIME));
}
void EventQueue::SCounterEmpty(Passenger *passenger) {
    Events.push(*new Action(passenger,"scounter",TIME));
}
void EventQueue::createCounter(int N, string W) {
    if (W == "l"){
        for (int i = 0; i<N ; i++){
            counters.push_back(*new counter);
        }
    }
    else
        for (int i = 0; i<N ; i++){
            scounters.push_back(*new counter);
        }
}




