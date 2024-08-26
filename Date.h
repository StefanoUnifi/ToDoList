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

    private:
        int day;
        int month;
        int year;
};

#endif //TODOLIST_DATE_H
