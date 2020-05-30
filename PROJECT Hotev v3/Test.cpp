//
//  Test.cpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 18.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#include "Test.hpp"
Date dateInit(){
    int fromYear; // check
    std::cin>>fromYear;
    int fromMonth;
    std::cin>>fromMonth;
    int fromDay;
    std::cin>>fromDay;
    Date from(fromYear,fromMonth,fromDay);
    return from;
}


Test:: Test(Hotel hotel,const char* command){
    this->h=hotel; //we have an operator =
    this->SetCommand(command);
}

void  Test:: SetCommand(const char* command){
    
    this->len=strlen(command);
    this->command=new char[len+1];
    strcpy(this->command,command);
}

void Test:: Command(){
    
    //while
    
    if(strcmp(command,"checkin")==0){
        
        int roomNumber;
        std::cout<<"Enter the room number: "<<std::endl;
        std::cin>>roomNumber;
        
        char note[LENGTH];
        std::cin>>note;
        
        int fromYear; // check
        std::cin>>fromYear;
        int fromMonth;
        std::cin>>fromMonth;
        int fromDay;
        std::cin>>fromDay;
        Date from(fromYear,fromMonth,fromDay);
        
        int toYear; // check
        std::cin>>toYear;
        int toMonth;
        std::cin>>toMonth;
        int toDay;
        std::cin>>toDay;
        Date to(toYear,toMonth,toDay);
        
        int guests;
        std::cin>>guests;
        
        int index=h.GetIndex(roomNumber);
        
        if(index!=-1)
            h.at(index).checkin(from, to, note, guests);
    }
    
   else if(strcmp(command,"availability")==0){
        Date date=dateInit();
        
        h.availability(date);
        
    }
    
   else if(strcmp(command,"chekout")==0){
        int roomNumber;
        std::cin>>roomNumber;
        
        int index=h.GetIndex(roomNumber);
        Room room = h.at(index).GetRoom();
        h.checkout(room);
    }
    
   else if(strcmp(command,"report")==0){
        std::cout<<"Enter the starting date: "<<std::endl;
        Date from=dateInit();
        std::cout<<"Enter the last date: "<<std::endl;
        Date to=dateInit();
        
        h.report(from, to);
    }
   else  if(strcmp(command,"find")==0){
        int beds;
        std::cout<<"Enter the number of wanted beds: "<<std::endl;
        std::cin>>beds;
        
        std::cout<<"Enter the starting date: "<<std::endl;
        Date from=dateInit();
        std::cout<<"Enter the last date: "<<std::endl;
        Date to=dateInit();
        
        h.find(beds, from, to);
    }
   else  if(strcmp(command,"find!")==0){
        int beds;
        std::cout<<"You are a VIP guest of ours, enjoy your stay"<<std::endl;
        std::cout<<"Enter the number of wanted beds: "<<std::endl;
        std::cin>>beds;
        
        std::cout<<"Enter the starting date: "<<std::endl;
        Date from=dateInit();
        std::cout<<"Enter the last date: "<<std::endl;
        Date to=dateInit();
        
        h.findVIP(beds, from, to);
    }
   else  if(strcmp(command,"unavailable")==0){
        int numberRoom;
        std::cout<<"Enter the number of your room: "<<std::endl;
        std::cin>>numberRoom;
        
        std::cout<<"Enter the starting date: "<<std::endl;
        Date from=dateInit();
        std::cout<<"Enter the last date: "<<std::endl;
        Date to=dateInit();
        
        char note [LENGTH];
        
        std::cout<<"Enter a note : "<<std::endl;
        
        std::cin>>note;
        //FIX
        int index= h.GetIndex(numberRoom);
        Room room=h.at(index).GetRoom();
        
        h.unavailable(room, from, to, note);
    }
    
   else{
       std::cout<<"Invalid command for the hotel"<<std::endl;
   }
}
void Test:: FileCommand(){
    
    char fileName[LENGTH];
    
    std::cout<<"Enter the file name and its path: "<<std::endl;
    std::cin>>fileName;
    
    FileManager f(fileName,this->h);
    
    while (strcmp(this->command ,"exit")!=0){
        
//        char command [COMMAND_MAX_SIZE];
//        
//        std::cout<<"Enter a command for your Hotel Manager: "<<std::endl;
//        std::cin>>command;
        
        if(strcmp(command,"open")){
            f.read();
            
            char innerCommand[COMMAND_MAX_SIZE];
            std::cin>>innerCommand;
            
            
            SetCommand(innerCommand);
            
            while((strcmp(innerCommand,"saveas")!=0) && (strcmp(innerCommand,"save")!=0) && (strcmp(innerCommand,"close")!=0) && (strcmp(innerCommand,"exit")!=0)){
                
                Command();
                
                std::cin >>innerCommand;
            }
        }
        
        else if(strcmp(command,"close")==0){
            this->h=Hotel();
        }
        
        else if(strcmp(command,"save")==0){
            
            
            f.write();
        }
        
        else if(strcmp(command,"saveas")==0){
            
            char fileName[LENGTH];
            
            std::cout<<"Enter the file name and its path: "<<std::endl;
            std::cin>>fileName;
            
            f.writeTo(fileName);
        }
        else if(strcmp(command,"help")==0){
            std::cout<<"The following commands are supported:"<<std::endl;
            std::cout<<"open <file>    opens <file> "<<std::endl;
            std::cout<<"close            closes currently opened file "<<std::endl;
            std::cout<<"save            saves the currently open file "<<std::endl;
            std::cout<<"saveas <file>    saves the currently open file in <file> "<<std::endl;
            std::cout<<"help            prints this information "<<std::endl;
            
        }
        
        else if(strcmp(command,"exit")==0){
            std::cout<<"Exiting this sesion ..."<<std::endl;
            return;
        }
        
        
        else{
            std::cout<<"Error! Enter a valid commad: "<<std::endl;
        }
        
        std::cin>>command;
        SetCommand(command);
    }
}
