//
//  Hotel.cpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 17.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#include "Hotel.hpp"


void Hotel:: CopyFrom(const Hotel& other){
    
    size=other.size;
    capacity=other.capacity;
    hotel=new Tuple[other.capacity];
    this->hotel=new Tuple[other.capacity];
    for(int i=0;i<other.size;i++){
        hotel[i]=other.hotel[i];
    }
}
void Hotel:: Free(){
    delete [] hotel;
}
void Hotel::Resize(){
    this->capacity*=2;
    Tuple* buffer= new Tuple[this->capacity];
    for(int i=0;i<this->size;i++){
        buffer[i]=this->hotel[i];
    }
    delete[] this->hotel;
    this->hotel=buffer;
}



Hotel::Hotel(){
    size=0;
    capacity=DEFAULT_CAPACITY;
    hotel=new Tuple[capacity];
}
Hotel::Hotel(const Hotel& other){
    CopyFrom(other);
}
Hotel& Hotel:: operator=(const Hotel& other){
    if(this != &other){
        Free();
        CopyFrom(other);
    }
    return *this;
}
Hotel::~Hotel(){
    Free();
}

size_t Hotel:: GetSize()const{
    return size;
}

void Hotel::addRoom(const Room& room){
    Tuple tu(room);
    
    
    if(size==capacity){
        Resize();
    }
    
    
    hotel[size]=tu;
    this->size++;
}
void Hotel:: addRoom(const Tuple& tuple){
    if(size==capacity){
        Resize();
    }
    
    hotel[size]=tuple;
    this->size++;
}

int Hotel:: GetIndex(const Room& room ){
    for(int i=0;i<size;i++){
        if(room.GetNumber()==hotel[i].GetRoom().GetNumber())
            return i;
    }
    return -1;
}
int Hotel:: GetIndex(int roomNumber){
    for(int i=0;i<size;i++){
        if(roomNumber==hotel[i].GetRoom().GetNumber()){
            return i;
        }
    }
    std::cout<<"There is no room with such number!"<<std::endl;
    return -1;
}
Tuple Hotel:: at(int index)const{
    return hotel[index];
}
Tuple& Hotel:: at(int index){
    return hotel[index];
}

void Hotel:: availability(const Date& date)const{
    for(int i=0;i<size;i++){
        if(hotel[i].GetRoom().IsTakenOn(date)){
            hotel[i].print();
        }
    }
}

void Hotel:: checkout(Room room){
    int index=GetIndex(room);
    hotel[index].makeEmpty();
}

void Hotel:: checkin(const Room& room,const Date& from,const Date& to,const char* note){
    int index=GetIndex(room);
    at(index).checkin(from, to, note);
    
}


void Hotel:: report(const Date& from,const Date& to){
    if(to<from){
        std::cout<<""<<std::endl;
        return;
    }
    for(int i=0;i<GetSize();i++){
        if(hotel[i].GetRoom().IsUsed(from, to)){
            
            hotel[i].GetRoom().print();
            std::cout<<"Has been taken for "<<hotel[i].GetRoom().countDays(from)<<" days"<<std::endl;
        }
    }
}

bool Hotel:: find(int beds,const Date& from,const Date& to){
    
    if(to<from){
        std::cout<<"Enter a valid date range!"<<std::endl;
        return false;
    }
    
    for(int i=0;i<size;i++){
        if( hotel[i].GetFreeBeds()>=beds && hotel[i].GetRoom().isAvailable(from, to)){
            hotel[i].print();
            return true;
        }
    }
    return false;
}

bool Hotel:: CanBeFuond(int beds,const Room& room,const Date& from,const Date& to,int& count){
    if(room.canBeChanged(beds, from, to)){
        if(count<=2){
            room.print();
        }
        return true;
    }
    
    bool found=false;
    count++;
    
    for(int i=0;i<GetSize() && !found && count<=2;i++){ 
        if( !hotel[i].GetRoom().isAvailable(from, to)){
            found = found || CanBeFuond(beds, hotel[i].GetRoom(), from, to, count);
        }
    }
    return found;
}

void Hotel:: findVIP(int beds,const Date& from,const Date& to){
    
    int count=0;
    for(int i=0;i<GetSize();i++){
        if(!hotel[i].GetRoom().GetIsTaken()){
            if(CanBeFuond(beds, hotel[i].GetRoom(), from, to, count) && count<=2){
                std::cout<<"Found a room! "<<std::endl;
            }
        }
    }
}

void Hotel::  unavailable(Room room,const Date& from,const Date& to,const char* note){
    int index=GetIndex(room);
    at(index).makeUnavailable(from, to, note);
    
}

std::ostream& operator<<(std::ostream& stream, const Hotel& h){
    size_t size =h.GetSize();
    for(int i=0;i<size;i++){
        stream<< h.at(i).GetRoom()<<std::endl;
    }
    return stream;
}

std::istream& operator>>(std::istream& stream, Hotel& h){
    int count;
    stream>>count;
    
    for(int i=0;i<count;i++){
        Room elem;
        stream >> elem;
        
        h.addRoom(elem);
    }
    
    return stream;
}

void Hotel:: print()const{
    std::cout<<"HOTEL INFORMATION:"<<std::endl;
    for(int i=0;i<GetSize();i++){
        at(i).print();
    }
}


