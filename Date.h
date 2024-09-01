//
// Created by stefa on 26/08/2024.
//

#ifndef TODOLIST_DATE_H
#define TODOLIST_DATE_H

class Date {
    public:
        Date(int day, int month, int year);
        Date() : day(0), month(0), year(0) {}

        int getDay() const;
        void setDay(int day);

        int getMonth() const;
        void setMonth(int month);

        int getYear() const;
        void setYear(int year);

        bool operator==(const Date &date) const;

    private:
        int day;
        int month;
        int year;

        bool validYear(int year);
        bool validMonth(int month);
        bool validDay(int day, int month, int year) const;
        bool validDate(int day, int month, int year);

        int getDaysOfMonth(int month, int year) const;

        bool isLeap(int year) const;
};

#endif //TODOLIST_DATE_H
