//
//  main.cpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 17.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#include "Test.hpp"
using namespace std;

int main() {
    
    ///Simple example of the system workings
   
    //char command[COMMAND_MAX_SIZE];
    
    
    Hotel Trivago;
    
    //Filling the hotel
   Date start(2020,1,1);
   Date end(2020,3,13);
//    start.printDate();
    
    Room firstFloor(4,5,start,end,"Needs cleaning");
    Room secondFloor(1,2,start,end,"Expecting room servise");

    
    Tuple tu(firstFloor);
    //Tuple sec(secondFloor);
    
    Trivago.addRoom(tu);
    Trivago.addRoom(secondFloor);

    
    Trivago.print();

    

    
    
    //FileManager f("Output.txt",Trivago);
    //f.write();
    
//    Test HotelTest(Trivago,command);
//    HotelTest.FileCommand();
    
    
    
}
