//
// Created by stefa on 26/08/2024.
//

#include "Date.h"

Date::Date(int day, int month, int year)
    : day(day), month(month), year(year) {}

int Date::getDay() const {
    return day;
}
void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}
void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}
void Date::setYear(int year) {
    Date::year = year;
}


bool Date::validYear(int year) {
    if(year > 2000 && year < 2100)
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