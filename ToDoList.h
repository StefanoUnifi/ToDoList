//
// Created by stefa on 26/08/2024.
//

#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include "Activity.h"
#include <list>

class ToDoList {
    public:
        explicit ToDoList(std::string title);
        ToDoList() = default;

        const std::list<Activity> &getToDoList() const;

        const std::string &getTitle() const;
        void setTitle(const std::string &title);

        void addActivity(const Activity &activity);

        void removeActivity(const std::string &description);

        void removeActivities();


    private:
        std::list<Activity> toDoList;
        std::string title;
        int nOfAct{0}; // number of activities

        Activity &helperFindActivity(const std::string &parameter);
};
#endif //TODOLIST_TODOLIST_H
