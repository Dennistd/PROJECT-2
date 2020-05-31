//
//  Hotel.hpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 17.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#ifndef Hotel_hpp
#define Hotel_hpp

#include <stdio.h>
#include "Tuple.hpp"

///Class for Hotel Manager
///
///described as an array of pairs of rooms
class Hotel{
    Tuple* hotel;
    size_t size; //current size
    size_t capacity; //the maximum capacity
    
    void CopyFrom(const Hotel& other);
    void Free();
    void Resize();
    
public:
    
    Hotel();
    Hotel(const Hotel& other);
    Hotel& operator=(const Hotel& other);
    ~Hotel();
    
    int GetIndex(const Room& room ); //finds the index by a given date
    int GetIndex(int roomNumber); //finds the index by a given room number
    Tuple at(int index)const; //The pair on a given position
    Tuple& at(int index);
    size_t GetSize()const;
    
    ///adds another pait with its room to the hotel
    void addRoom(const Room& rooom);
    void addRoom(const Tuple& tuple);
    
    void checkin(const Room& room,const Date& from,const Date& to,const char* note);
    
    void availability(const Date& date)const; //gives information about the status of the rooms
    
    ///checks out the rooms in the hotel
    void checkout(Room room);
    
    void report(const Date& from,const Date& to);
    
    bool find(int beds,const Date& from,const Date& to);
    void findVIP(int beds,const Date& from,const Date& to);
    
    bool CanBeFuond(int beds,const Room& room,const Date& from,const Date& to,int& count);
    
    void unavailable(Room room,const Date& from,const Date& to,const char* note);
    
    friend std::ostream& operator<<(std::ostream& stream, const Hotel& h);
    friend std::istream& operator>>(std::istream& stream, Hotel& h);
    
    void print()const; //test
    
};
#endif /* Hotel_hpp */
