//
//  Date.hpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 17.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp
#include <iostream>
#include <fstream>
#include <stdio.h>

/// Клас за дата
///
/// Приема вида гггг/мм/дд
class Date{
    int year;
    int month;
    int day;
    
    bool IsLeapYear(); //проверява дали годината е високосна
public:
    
    /// Конструктори с и без параметри
    Date(int year,int month,int day);
    Date();
    
    ///Мутатори
    void SetYear(int);
    void SetMonth(int);
    void SetDay(int);
    ///Селектори
    int GetYear()const;
    int GetMonth()const;
    int GetDay()const;
    
   bool isValid()const;

    
    
    void printDate()const; //Отпечатва годината във зададения формат
    
    ///Оператори за сравнение
    friend bool operator>(const Date& lhs,const Date& rhs);
    friend bool operator>=(const Date& lhs,const Date& rhs);
    friend bool operator<(const Date& lhs,const Date& rhs);
    friend bool operator<=(const Date& lhs,const Date& rhs);
    friend bool operator==(const Date& lhs,const Date& rhs);
    ///Оператори за работа с файл
    friend std::ostream& operator<<(std::ostream& os,const Date& date);
    friend std::istream& operator>>(std::istream& is,Date& date);
    
    Date operator ++();
    Date operator ++(int);
    Date operator --();
    Date operator --(int); 
};

#endif /* Date_hpp */
