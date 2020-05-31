//
//  FileManager.hpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 18.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#ifndef FileManager_hpp
#define FileManager_hpp

#include <stdio.h>

#include "Hotel.hpp"
///Class for working with files
///
///It represents the link to the file and the data without having interest in its format
class FileManager{
    char* fileName; //the name of the file and its path
    size_t len;
    
    Hotel hotel; //Object of type hotel which would be modified or derived data from
    
public:
    FileManager(const char* name,Hotel& h);
    void SetFileName(const char* fileName); //sets the name of the working file or its path
    
    void write(); //saves the current hotel in the file
    void writeTo(const char* otherName); //saves the current hotel in a file with given name
    void read(); ////opens the file derives information from it puts it in the current hotel
  
};

#endif /* FileManager_hpp */
