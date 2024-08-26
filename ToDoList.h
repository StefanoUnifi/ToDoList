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


    private:
        std::list<Activity> toDoList;
        std::string title;
};
#endif //TODOLIST_TODOLIST_H
