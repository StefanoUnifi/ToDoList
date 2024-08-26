//
// Created by stefa on 26/08/2024.
//

#include "Date.h"

//todo: implementare funzioni che verificano giorni, mesi e anni validi
//todo: implementare funzione che verifica se una data è valida
//todo: implementare funzione che verifica se un anno è bisestile
//todo: implementare funzione che "prende" giorni di un mese

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