//
//  Tuple.cpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 17.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#include "Tuple.hpp"

Tuple:: Tuple(): room(){
    freeBeds=0;
}

Tuple:: Tuple(const Room& _room): room(_room){
   this-> freeBeds= _room.GetBeds() - _room.GetGuests();
};
Room Tuple::GetRoom()const{
    return room;
}
int Tuple:: GetFreeBeds()const{
    return freeBeds;
}

void Tuple:: print()const{
    room.print();
    std::cout<<"has "<<freeBeds<<" free beds"<<std::endl;
}

void Tuple::makeEmpty(){
    room.makeEmpty();
    freeBeds=room.GetBeds();
}
void Tuple::makeUnavailable(const Date& from,const Date& to, const char* note){
    room.makeUnavailable(from, to, note);
    freeBeds=0;
}

void Tuple::checkin(const Date& from,const Date& to,const char* note){
    room.checkin(from,to,note);
}
void Tuple:: checkin(const Date& from,const Date& to,const char* note,int guests){
    room.checkin(from,to,note,guests);
}
