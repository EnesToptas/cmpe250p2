#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>
#include "EventQueue.h"
using namespace std;


template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}


int main(int argc, char* argv[]) {

    EventQueue eventQueue;

    if (argc != 3) {
        cout << "Run the code with the following command: ./project2 [input_file] [output_file]" << endl;
        return 1;
    }


    ifstream infile(argv[1]);
    string line;
    // process first line
    getline(infile, line);
    vector<Passenger> passenger;
    vector<string> first;
    split1(line,first);
    int N = stoi(first[0]);
    eventQueue.createCounter(stoi(first[1]),"l");
    eventQueue.createCounter(stoi(first[2]),"s");

    for (int i=0; i<N; i++) {
        getline(infile, line);

        vector<string> words;
        split1(line,words);
        int a= stoi(words[0]);
        int b= stoi(words[1]);
        int c= stoi(words[2]);
        int d= stoi(words[3]);

        passenger.push_back(*(new Passenger(a,b,c,d,words[4],words[5])));

    }


    ofstream myfile;
    myfile.open(argv[2]);

    //case 1
    for (int z=0; z<N; z++) {
        eventQueue.addPerson(&passenger[z]);

    }

    while(not eventQueue.Events.empty()){
        eventQueue.popfifo(0,0);
    }

    myfile << eventQueue.waiting_time/N << " " <<  eventQueue.missed << endl;

    eventQueue.waiting_time = eventQueue.missed = 0;

    //case 2
    for (int z=0; z<N; z++) {
        eventQueue.addPerson(&passenger[z]);

    }

    while(not eventQueue.Events.empty()){
        eventQueue.pop(0,0);
    }

    myfile << eventQueue.waiting_time/N << " " <<  eventQueue.missed << endl;

    eventQueue.waiting_time = eventQueue.missed = 0;

    //case 3
    for (int z=0; z<N; z++) {
        eventQueue.addPerson(&passenger[z]);

    }

    while(not eventQueue.Events.empty()){
        eventQueue.popfifo(1,0);
    }

    myfile << eventQueue.waiting_time/N << " " <<  eventQueue.missed << endl;

    eventQueue.waiting_time = eventQueue.missed = 0;

    //case 4
    for (int z=0; z<N; z++) {
        eventQueue.addPerson(&passenger[z]);

    }

    while(not eventQueue.Events.empty()){
        eventQueue.pop(1,0);
    }

    myfile << eventQueue.waiting_time/N << " " <<  eventQueue.missed << endl;

    eventQueue.waiting_time = eventQueue.missed = 0;

    //case 5
    for (int z=0; z<N; z++) {
        eventQueue.addPerson(&passenger[z]);

    }

    while(not eventQueue.Events.empty()){
        eventQueue.popfifo(0,1);
    }

    myfile << eventQueue.waiting_time/N << " " <<  eventQueue.missed << endl;

    eventQueue.waiting_time = eventQueue.missed = 0;

    //case 6
    for (int z=0; z<N; z++) {
        eventQueue.addPerson(&passenger[z]);

    }

    while(not eventQueue.Events.empty()){
        eventQueue.pop(0,1);
    }

    myfile << eventQueue.waiting_time/N << " " <<  eventQueue.missed << endl;

    eventQueue.waiting_time = eventQueue.missed = 0;

    //case 7
    for (int z=0; z<N; z++) {
        eventQueue.addPerson(&passenger[z]);

    }

    while(not eventQueue.Events.empty()){
        eventQueue.popfifo(1,1);
    }

    myfile << eventQueue.waiting_time/N << " " <<  eventQueue.missed << endl;

    eventQueue.waiting_time = eventQueue.missed = 0;

    //case 8
    for (int z=0; z<N; z++) {
        eventQueue.addPerson(&passenger[z]);

    }

    while(not eventQueue.Events.empty()){
        eventQueue.pop(1,1);
    }

    myfile << eventQueue.waiting_time/N << " " <<  eventQueue.missed << endl;

    eventQueue.waiting_time = eventQueue.missed = 0;

    myfile.close();


}