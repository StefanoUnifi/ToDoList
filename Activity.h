//
// Created by stefa on 26/08/2024.
//

#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H

#include <string>

class Activity {
public:
    Activity( const std::string &description, bool completed = false) :
        description(description), completed(completed) {}

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


private:
    std::string description;
    bool completed;
};

#endif //TODOLIST_ACTIVITY_H
