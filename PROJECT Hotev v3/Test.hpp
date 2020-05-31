//
//  Test.hpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 18.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#ifndef Test_hpp
#define Test_hpp

#include <stdio.h>
#include "FileManager.hpp"

const int COMMAND_MAX_SIZE=30;

///Class whicj collects data from the user  (user interface)
///
///  Works with data from the console and from a user provided file
/// Takes care of the commands
class Test{
    char* command; //user provided command
    size_t len;
    Hotel h; //object of type hotel
    
public:
    Test(Hotel hotel,const char* command);
    
    void SetCommand(const char* command);
    
    void Command(); //by the given string it runs the hotel functions
    void FileCommand(); //by the given string it runs the file functions
};

#endif /* Test_hpp */
