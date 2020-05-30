//
//  Room.hpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 17.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#include <stdio.h>

#include "Date.hpp"

const int DEFAULT_CAPACITY=8;
///Class for the room unit
///
///It is described by its number of beds and if it is taken or not
class Room{
    
    int number; //room number #
    int beds; //count of beds
    
    bool IsTaken; //taken or nor
    
    int guests; //count of people residing in the room
    
    ///  Period of usage for the room
    Date start;
    Date finish;
    
    
    char* note; //Side note given for discription
    size_t len;
    
    void Free();
    void CopyFrom(const Room& other);
    
public:
    
    //BIG 4
    Room();
    Room(int number, int beds);
    Room(int number,int beds,int guests,const Date& start,const Date& end,const char* note);
    Room(int number,int beds,const Date& start,const Date& end,const char* note);
    Room(const Room& other);
    Room& operator=(const Room& other);
    ~Room();
    
    
    void SetNumber(int number);
    void SetBeds(int beds);
    void SetStart(const Date& start);
    void SetFinish(const Date& finish);
    void SetNote(const char* note);
    void SetGuests(int guests);
    
    
    int GetNumber()const;
    int GetBeds()const;
    int GetGuests()const;
    bool GetIsTaken()const;
    Date GetStart()const;
    Date GetFinish()const;
    const char* GetNote()const;
    
    
    ///Function for making a reservation
    void checkin(const Date& from,const Date& to,const char* note);
    void checkin(const Date& from,const Date& to,const char* note,int guests);
    
    ///Function for checking out of the room
    void makeEmpty();
    
    ///checks if the guests in the room can be moced to another
    bool canBeChanged(int beds)const;
    bool canBeChanged(int beds,const Date& from,const Date& to)const;
    
    bool IsTakenOn(const Date& date)const;
    
    bool isAvailable(const Date& from,const Date& to)const; //if the room is available in the given period
    
    int countDays(const Date& date);
    bool IsUsed(const Date& from,const Date& to)const;
    
    void print()const; //orints in a stylised format
    
    /// the room is set to be unavailable for a given period and the reason why
    void makeUnavailable(const Date& from,const Date& to, const char* note);
    
    ///Operators for working with files
    friend std::ostream& operator<<(std::ostream& stream, const Room& r);
    friend std::istream& operator>>(std::istream& stream, Room& r);
    
};

#endif /* Room_hpp */
