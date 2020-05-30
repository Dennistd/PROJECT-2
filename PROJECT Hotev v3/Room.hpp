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

///Клас за стая
///
///Описва се от номера си, броя легла с които разполага и в зависимост от това дали е заета се описва с различни данни
class Room{
    
    int number; //Номер
    int beds; //Брой легла
    
    bool IsTaken; //Заета или не
    
    int guests; //Брой гости, който са настанени
    
    ///  Период на използване
    Date start;
    Date finish;
    
    
    char* note; //Бележка
    size_t len;
    
    void Free();
    void CopyFrom(const Room& other);
    
public:
    
    /// Конструктори с различни параметри
    Room();
    Room(int number, int beds);
    Room(int number,int beds,int guests,const Date& start,const Date& end,const char* note);
    Room(int number,int beds,const Date& start,const Date& end,const char* note);
    Room(const Room& other);
    Room& operator=(const Room& other);
    ~Room();
    
    //Мутатори
    void SetNumber(int number);
    void SetBeds(int beds);
    void SetStart(const Date& start);
    void SetFinish(const Date& finish);
    void SetNote(const char* note);
    void SetGuests(int guests);
    
    //Селектори
    int GetNumber()const;
    int GetBeds()const;
    int GetGuests()const;
    bool GetIsTaken()const;
    Date GetStart()const;
    Date GetFinish()const;
    const char* GetNote()const;
    
    
    ///Функциии за резервация
    void checkin(const Date& from,const Date& to,const char* note);
    void checkin(const Date& from,const Date& to,const char* note,int guests);
    
    ///Функция за освобождаване
    void makeEmpty();
    
    ///Проверява дали гостите от стаята могат да бъдат преместени в посочена друга
    bool canBeChanged(int beds)const;
    bool canBeChanged(int beds,const Date& from,const Date& to)const;
    
    bool IsTakenOn(const Date& date)const;
    
    bool isAvailable(const Date& from,const Date& to)const; //Дали стаята е свободна в посочения период
    
    int countDays(const Date& date);
    bool IsUsed(const Date& from,const Date& to)const;
    
    void print()const; //Принтира на конзолата информация за стаята в подходящ формат
    
    /// Прави стаята недостъпна за определен период
    void makeUnavailable(const Date& from,const Date& to, const char* note);
    
    //Оператори за работа с файл
    friend std::ostream& operator<<(std::ostream& stream, const Room& r);
    friend std::istream& operator>>(std::istream& stream, Room& r);
    
};

#endif /* Room_hpp */
