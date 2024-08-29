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

        /*le funzioni per verificare giorni, mesi e anni validi sono private
        perché non vengono utilizzate al di fuori della classe*/
        bool validYear(int year);
        bool validMonth(int month);
        bool validDay(int day, int month, int year) const;
        bool validDate(int day, int month, int year);

        /*la funzione per verificare se una data è valida è privata perché non
        viene utilizzata al di fuori della classe*/
        int getDaysOfMonth(int month, int year) const;

        /*la funzione per verificare se un anno è bisestile è privata perché non
        viene utilizzata al di fuori della classe*/
        bool isLeap(int year) const;
};

#endif //TODOLIST_DATE_H
