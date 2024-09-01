//
// Created by stefa on 26/08/2024.
//

#include <stdexcept>
#include "Date.h"

Date::Date(int day, int month, int year){
    if(!validDate(day, month, year))
        throw std::out_of_range("Date not valid!");
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay() const {
    return day;
}
void Date::setDay(int day) {
    if(validDay(day, this->month, this->year))
        Date::day = day;
    else
        throw std::out_of_range("Day not valid!");
}

int Date::getMonth() const {
    return month;
}
void Date::setMonth(int month) {
    if(validMonth(month)) {
        if(validDay(this->day, month, this->year))
            Date::month = month;
        else
            throw std::out_of_range("Day not valid for the month!");
    }else
        throw std::out_of_range("Month not valid!");
}

int Date::getYear() const {
    return year;
}
void Date::setYear(int year) {
    if(validYear(year)) {
        if(validDay(this->day, month, this->year))
            Date::year = year;
        else
            throw std::out_of_range("Day not valid for the year!");
    }else
        throw std::out_of_range("Year not valid!");
}


bool Date::validYear(int year) {
    if(year > 2000)
        return true;
    return false;
}

bool Date::validMonth(int month) {
    if(month > 0 && month < 13)
        return true;
    return false;
}

bool Date::isLeap(int year) const {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0)
                return true;
            else
                return false;
        }else
            return true;
    }
    return false;
}

int Date::getDaysOfMonth(int month, int year) const {
    if(month == 2) {
        if(isLeap(year))
            return 29;
        return 28;
    }
    if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    return 31;
}

bool Date::validDay(int day, int month, int year) const {
    int daysOfMonth = getDaysOfMonth(month, year);
    if(day > 0 && day <= daysOfMonth)
        return true;
    return false;
}

bool Date::validDate(int day, int month, int year) {
    if(validDay(day, month, year) && validMonth(month) && validYear(year))
        return true;
    else
        return false;
}

bool Date::operator==(const Date &date) const {
    if(this->day == date.day && this->month == date.month && this->year == date.year)
        return true;
    return false;
}