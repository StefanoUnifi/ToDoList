//
// Created by stefa on 26/08/2024.
//

#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H

#include "Date.h"
#include <string>
#include <sstream>

class Activity {
public:
    Activity(const Date &date, const std::string &description, bool completed = false) :
            date(date), description(description), completed(completed) {}

    const std::string &getDescription() const {
        return description;
    }
    void setDescription(const std::string &description) {
        Activity::description = description;
    }

    bool isCompleted() const {
        return completed;
    }
    void setCompleted(bool completed) {
       if(!isCompleted())
           this->completed = true;
       else
           this->completed = false;
    }

    std::string getDate() const {
        std::stringstream s;
        if(date.getDay() != 0)
            s << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
        return s.str();
    }
    void setDate(const Date &date) {
        Activity::date = date;
    }

    bool operator==(const Activity &act) const {
        if(this->description == act.description this->date == act.date)
            return true;
        return false;
    }

private:
    std::string description;
    bool completed;

    Date date;
};

#endif //TODOLIST_ACTIVITY_H
