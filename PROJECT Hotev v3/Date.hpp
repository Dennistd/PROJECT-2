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

/// Class for the date
///
/// HAs the form of yyyy/mm/dd
class Date{
    int year;
    int month;
    int day;
    
    bool IsLeapYear();
public:
    
   
    Date(int year,int month,int day);
    Date();
    
    
    void SetYear(int);
    void SetMonth(int);
    void SetDay(int);
    
    int GetYear()const;
    int GetMonth()const;
    int GetDay()const;
    
   bool isValid()const; //checks all the conditions for the format of the date

    
    
    void printDate()const; //Prints the date in a stylised format
    
    ///Operators for comparing
    friend bool operator>(const Date& lhs,const Date& rhs);
    friend bool operator>=(const Date& lhs,const Date& rhs);
    friend bool operator<(const Date& lhs,const Date& rhs);
    friend bool operator<=(const Date& lhs,const Date& rhs);
    friend bool operator==(const Date& lhs,const Date& rhs);
    ///Operators for working with a file
    friend std::ostream& operator<<(std::ostream& os,const Date& date);
    friend std::istream& operator>>(std::istream& is,Date& date);
    
    //operators for iteration
    Date operator ++();
    Date operator ++(int);
    Date operator --();
    Date operator --(int); 
};

#endif /* Date_hpp */
