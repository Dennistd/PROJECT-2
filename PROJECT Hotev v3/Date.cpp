//
//  Date.cpp
//  PROJECT Hotev v3
//
//  Created by Dennis Dimitrov on 17.05.20.
//  Copyright © 2020 Dennis Dimitrov. All rights reserved.
//

#include "Date.hpp"


Date::Date(int year ,int month,int day){
    SetYear(year);
    SetMonth(month);
    SetDay(day);
    
}
Date::Date(){
    SetYear(1970);
    SetMonth(1);
    SetDay(1);
}

void Date::SetYear(int year){
    if(year>=1970){
        this->year=year;
    }
}
void Date::SetMonth(int month){
    if(month>=1&&month<=12){
        this->month=month;
    }
}
bool Date:: IsLeapYear(){
    if((this->year%4)==0){
        if((this->year%100)==0){
            if((this->year%400)==0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }
    }
    return false;
}
void Date::SetDay(int day){
    if(this->month==2){
        if(IsLeapYear()){
            if(day>=1&&day<=29){
                this->day=day;
            }
        }
        if(day>=1&&day<=28){
            this->day=day;
        }
        else{
            throw "Invalid date for February";
        }
    }
    
    else if((month==2||month==4||month==6||month==9||month==11)){
        if(day>=1 && day<=30){
            this->day=day;
        }
        else{
            throw "This month does not have 31 days!";
        }
    }
    else{
        if(day>=1 && day<=31){
            this->day=day;
        }
        else{
            throw "Enter a valid date: ";
        }
    }
    
}
int Date:: GetYear()const{
    return this->year;
}
int Date:: GetMonth()const{
    return this->month;
}
int Date:: GetDay()const{
    return this->day;
}
bool operator>(const Date& lhs,const Date& rhs){
    
    if(lhs.GetYear()>rhs.GetYear())
        return true;
    else if(lhs.GetYear()==rhs.GetYear()){
        
        if(lhs.GetMonth()>rhs.GetMonth())
            return true;
        else if(lhs.GetMonth()==rhs.GetMonth()){
            
            if(lhs.GetDay()>rhs.GetDay())
                return true;
        }
    }
    return false;
}

bool operator<(const Date& lhs,const Date& rhs){
    if(lhs.GetYear()<rhs.GetYear())
        return true;
    else if(lhs.GetYear()==rhs.GetYear()){
        
        if(lhs.GetMonth()<rhs.GetMonth())
            return true;
        else if(lhs.GetMonth()==rhs.GetMonth()){
            
            if(lhs.GetDay()<rhs.GetDay())
                return true;
        }
    }
    return false;
    
}

bool operator>=(const Date& lhs,const Date& rhs){
    return lhs>rhs || lhs==rhs;
}

bool operator<=(const Date& lhs,const Date& rhs){
    return lhs<rhs || lhs==rhs;
}
bool operator==(const Date& lhs,const Date& rhs){
    return lhs.GetYear()==rhs.GetYear() && lhs.GetMonth()==rhs.GetMonth() && lhs.GetDay()==rhs.GetDay();
}
void Date::printDate()const{//fix 0
    std::cout<<year<<"/";
    if(this->month<10){
       std::cout<<0<<month<<"/";
    }
    else{
        std::cout<<month<<"/";
    }
    if(this->day<10){
         std::cout<<0<<month<<"/";
    }
    else{
        std::cout<<month<<"/";
    }
    std::cout<<std::endl;
}

bool Date:: isValid()const{
    
    if (year <0)
        return false;
    
    if (month >12 || month <1)
        return false;
    
    if (day >31 || day <1)
        return false;
    
    if ((day ==31 && (month==2||month==4||month==6||month==9||month==11))){
        return false;
    }
    if(day==30&&month==2){
        return false;
    }
    if(year<2000){
        if((day==29&&month==2) && !((year-1900)%4==0)){
            return false;
        }
    }
        if(year>2000){
            if((day==29&&month==2) && !((year-2000)%4==0)){
                      return false;
        }
    }
        return true;
}
    
Date next(const Date& date){
    Date newDate;
    if(!newDate.isValid()){
        return newDate;
    }
    newDate=Date(date.GetYear(),date.GetMonth(),(date.GetDay()+1));
    if(newDate.isValid()){
        return newDate;
    }
    newDate=Date(date.GetYear(),(date.GetMonth()+1),1);
    if(newDate.isValid()){
        return newDate;
    }
    newDate=Date((date.GetYear()+1),1,1);
    return newDate;
}
Date  previous(const Date& date){
    Date newDate;
      if(!newDate.isValid()){
          return newDate;
      }
      newDate=Date(date.GetYear(),date.GetMonth(),(date.GetDay()-1));
      if(newDate.isValid()){
          return newDate;
      }
    newDate=Date(date.GetYear(),(date.GetMonth()-1),31);
         if(newDate.isValid()){
             return newDate;
         }
    newDate=Date(date.GetYear(),(date.GetMonth()-1),30);
    if(newDate.isValid()){
        return newDate;
    }
    newDate=Date(date.GetYear(),(date.GetMonth()-1),29);
    if(newDate.isValid()){
        return newDate;
    }
    newDate=Date(date.GetYear(),(date.GetMonth()-1),28);
    if(newDate.isValid()){
        return newDate;
    }
    newDate=Date(31,12,(date.GetYear()-1));
    return newDate;
    
}

Date Date:: operator ++(){ // prefix
    *this=next(*this);
    return *this;
}
Date Date:: operator ++(int){ // postfix
    Date date=*this;
    *this=next(date);
    return date;
}
Date Date:: operator --(){ // prefix
  *this=previous(*this);
    return *this;
}
Date Date:: operator --(int){  // postfix
    Date date=*this;
       *this=previous(date);
       return date;
} 

std::istream& operator>>(std::istream& is,Date& date){
    int newYear;
    int newMonth;
    int newDay;
    is>>newYear;
    date.SetYear(newYear);
    is>>newMonth;
    date.SetMonth(newMonth);
    is>>newDay;
    date.SetDay(newDay);
    return is;
}
std::ostream& operator<<(std::ostream& os,const Date& date){
    os<<date.GetYear()<<" ";
    os<<date.GetMonth()<<" ";
    os<<date.GetDay()<<" ";
    os<<std::endl;
    return os;
}
