//
// Created by stefa on 26/08/2024.
//

#include <iostream>
#include "ToDoList.h"

ToDoList::ToDoList(std::string title) : title(std::move(title)) {}

const std::list<Activity> &ToDoList::getToDoList() const {
    return toDoList;
}

const std::string &ToDoList::getTitle() const {
    return title;
}
void ToDoList::setTitle(const std::string &title) {
    ToDoList::title = title;
}

void ToDoList::addActivity(const Activity &a) {
    toDoList.push_back(a);
    this->nOfAct++;
}

void ToDoList::removeActivity(const std::string &description) {
    Activity deletedAct = helperFindActivity(description);

    if (!deletedAct.getDescription().empty() || !deletedAct.getDate().empty()) {
        toDoList.remove(deletedAct);
        this->nOfAct--;
    } else
        std::cout << "Sorry there's not an activity with description: " << description << std::endl;
}

Activity &ToDoList::helperFindActivity(const std::string &parameter) {
    static Activity emptyAct(Date(), "");

    for (auto &it : toDoList) {
        if (it.getDescription() == parameter || it.getDate() == parameter)
            return it;
    }
    return emptyAct;
}

void ToDoList::removeActivities() {
    toDoList.clear();
    this->nOfAct = 0;
}