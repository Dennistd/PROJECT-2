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
    
    char command[COMMAND_MAX_SIZE];
    std::cout<<"Enter a command for your hotel manager: "<<std::endl;
    
    Hotel Trivago;
    Test HotelTest(Trivago,command);
    HotelTest.FileCommand();
    
}
