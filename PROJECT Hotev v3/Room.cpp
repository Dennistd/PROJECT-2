//
//  Room.cpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 17.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#include "Room.hpp"

void Room:: Free(){
    delete[] this->note;
}


void Room::SetNumber(int number){
    if(number>0 && number<=1000){
        this->number=number;
    }
    else{
        throw "Enter a valid room number:";
    }
}
void Room::SetBeds(int beds){
    if(beds>=0&&beds<20){
        this->beds=beds;
    }
    else{
        throw "Enter a valid number of beds";
    }
}
void Room::SetStart(const Date& start){
    this->start=start;
}
void Room::SetFinish(const Date& finish){
    this->finish=finish;
}
void Room:: SetNote(const char* note){
    this->note= new char[strlen(note)+1];
    strcpy(this->note,note);
    
    this->len=strlen(note);
}
void Room:: CopyFrom(const Room& other){
    SetBeds(other.beds);
    SetNumber(other.number);
    
    IsTaken = other.IsTaken;
    
    SetGuests(other.guests);
    
    SetNote(other.note);
}



Room::Room():start(),finish(){
    SetBeds(1);
    SetNumber(1);
    
    IsTaken=false;
    
    SetGuests(0);
    
    SetNote("None");
    
}
Room::Room(int number, int beds):start(),finish(){
    SetNumber(number);
    SetBeds(beds);
    
    IsTaken=false;
    
    SetGuests(0);
    
    SetNote("None");
}
Room:: Room(int number,int beds,int guests,const Date& start,const Date& end,const char* note):start(start),finish(end){
    
    SetBeds(beds);
    SetNumber(number);
    
    IsTaken=true;
    
    SetGuests(guests);
    
    SetNote(note);
}
Room:: Room(int number,int beds,const Date& start,const Date& end,const char* note):start(start),finish(end){
    SetBeds(beds);
    SetNumber(number);
    
    IsTaken=true;
    
    
    SetGuests(beds);
    
    SetNote(note);
}
Room:: Room(const Room& other):start(other.start),finish(other.finish){ //fix{
    CopyFrom(other);
}
Room& Room::operator=(const Room& other){
    if(this != &other){
        Free();
        CopyFrom(other);
        
        start=other.GetStart();
        finish=other.GetFinish();
    }
    return *this;
}
Room::~Room(){
    Free();
}

int Room:: GetNumber()const{
    return number;
}
int Room:: GetBeds()const{
    return beds;
}
int Room:: GetGuests()const{
    return guests;
}
bool Room:: GetIsTaken()const{
    return IsTaken;
}
Date Room:: GetStart()const{
    return start;
}

Date Room:: GetFinish()const{
    return finish;
}
const char* Room:: GetNote()const{
    return note;
}

void Room:: SetGuests(int guests){
    
    if(guests<=this->beds)
        this->guests=guests;
}



void Room:: checkin(const Date& from,const Date& to,const char* note){
    IsTaken=true;
    SetStart(from);
    SetFinish(to);
    SetNote(note);
}
void Room:: checkin(const Date& from,const Date& to,const char* note,int guests){
    IsTaken=true;
    SetStart(from);
    SetFinish(to);
    SetNote(note);
    SetGuests(guests);
}
void Room:: makeEmpty(){
    IsTaken=false;
    
    
    
    SetGuests(0);
    
    SetNote("None");
    this->start=this->finish;
}

bool Room:: IsTakenOn(const Date& date)const{
    return GetIsTaken() && (GetStart()>=date) && (GetFinish()<=date);
}

void Room:: print()const{
    std::cout<<"Room|"<<number<<"| "<<"with " <<beds<<" beds"<<std::endl;
} //to be continued

bool Room:: isAvailable(const Date& from,const Date& to)const{
    if(from>to){
        return false;
    }
    
   // return !GetIsTaken() || from>=GetFinish() || to<=GetStart();
     
    return !GetIsTaken() || (GetStart()>=to || GetFinish()<=from);
} //check again
// all the days in this period are continius and ordered


void Room:: makeUnavailable(const Date& from,const Date& to, const char* note){
    IsTaken=true;
    this-> start=from;
    this->finish=to;
    
    SetNote(note);
}

int Room::countDays(const Date& date){
    Date copy(date);
    int res=0;
    if(date <= GetFinish()){
        while(date<GetStart()){
            res++;
            copy--;
        }
    }
    return res;
}

bool Room:: IsUsed(const Date& from,const Date& to)const{
    return from>=GetStart() && to<=GetFinish();
}


bool Room:: canBeChanged(int beds)const{
    return GetIsTaken() && GetBeds()>=beds;
}
bool Room:: canBeChanged(int beds,const Date& from,const Date& to)const{
    return !isAvailable(from, to) && GetBeds()>=beds;
}

std::ostream& operator<<(std::ostream& stream, const Room& r){
    if(r.GetIsTaken()){
        stream << r.GetNumber()<<' '<<r.GetBeds()<<' '<<r.GetStart()<<' '<<r.GetFinish()<<r.GetNote()<<std::endl;
        
    }
    else
        stream<<r.GetNumber()<<' '<<r.GetBeds()<<std::endl;
    
    return stream;
}
std::istream& operator>>(std::istream& stream, Room& r){
    
    int newNumber;
    stream>>newNumber;
    r.SetNumber(newNumber);
    
    int newBeds;
    stream>>newBeds;
    r.SetBeds(newBeds);
    
    return stream;
    
}
