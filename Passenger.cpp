//
// Created by menes on 28.10.2018.
//

#include "Passenger.h"

Passenger::Passenger(int AT, int BT, int LT, int ST, string V, string L) {
    Arrive_time = AT;
    Board_time = BT;
    Luggage_time = LT;
    Security_time = ST;
    Wait_time = 0;
    if (V == "V")
        vip = true;
    else
        vip = false;
    if (L == "L")
        luggage = true;
    else
        luggage = false;
}
