//
//  Tuple.hpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 17.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#ifndef Tuple_hpp
#define Tuple_hpp

#include <stdio.h>
#include "Room.hpp"

///Клас наредена двойка
///
/// приема вида <брой стободни легла ; стая>
class Tuple{
    
    int freeBeds;
    Room room;
    
public:
    Tuple();
    Tuple(const Room& room);
    
    Room GetRoom()const;
    int GetFreeBeds()const;
    
    //Резервира стаята в двойката
    void checkin(const Date& from,const Date& to,const char* note);
    void checkin(const Date& from,const Date& to,const char* note,int guests);
    
    void makeEmpty();
    void makeUnavailable(const Date& from,const Date& to, const char* note);
    
    void print()const;
    
    
};
#endif /* Tuple_hpp */
