//
//  FileManager.cpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 18.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#include "FileManager.hpp"

FileManager::FileManager(const char* name,Hotel& other){
    SetFileName(name);
    this->hotel=other;
}

void FileManager:: SetFileName(const char* fileName){
    this->len=strlen(fileName);
    this->fileName=new char[len+1];
    strcpy(this->fileName,fileName);
}

void FileManager:: write(){
    std::ofstream file(fileName);
    if(file.fail()){
        std::cout<<"Error while opening this file"<<std::endl;
        return;
    }
    file << this->hotel;
    
}
void FileManager:: read(){
    std::ifstream file(fileName);
    
    if(file.fail()){
        std::cout<<"Error while opening this file"<<std::endl;
        return;
    }
    
    Hotel buffer;
    file>>buffer;
    this->hotel=buffer;
}

void FileManager:: writeTo(const char* otherName){
    std::ofstream other(otherName);
    
    if(other.fail()){
        std::cout<<"Error while opening this file"<<std::endl;
        return;
    }
    
    other<<this->hotel;
}
