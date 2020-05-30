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

///Основния ни клас хотел
///
///Представлява масив от стаи
class Hotel{
    Tuple* hotel;
    size_t size; //размер в момента
    size_t capacity; //капацитет
    
    void CopyFrom(const Hotel& other);
    void Free();
    void Resize();
    
public:
    
    Hotel();
    Hotel(const Hotel& other);
    Hotel& operator=(const Hotel& other);
    ~Hotel();
    
    int GetIndex(const Room& room ); //намира индекс по дадена стая
    int GetIndex(int roomNumber); //намира индекс по даден номер на стая;
    Tuple at(int index)const; //стая на зададена позиция
    size_t GetSize()const;
    
    ///Добавя стая към хотела
   // void addRoom(const Room& rooom);
    void addRoom(const Tuple& tuple);
    
    void checkin(const Room& room,const Date& from,const Date& to,const char* note);
    
    void availability(const Date& date)const; //информация за заетост
    
    ///Освобождава стая в хотела;
    void checkout(Room room);
    
    void report(const Date& from,const Date& to);
    
    bool find(int beds,const Date& from,const Date& to);
    void findVIP(int beds,const Date& from,const Date& to);
    
    void unavailable(Room room,const Date& from,const Date& to,const char* note);
    
    friend std::ostream& operator<<(std::ostream& stream, const Hotel& h);
    friend std::istream& operator>>(std::istream& stream, Hotel& h);
    
    void print()const; //test
    
};
#endif /* Hotel_hpp */
