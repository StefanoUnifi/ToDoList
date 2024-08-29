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
        if (deletedAct.isCompleted())
            this->nOfComplAct--;
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
    this->nOfComplAct = 0;
}

void ToDoList::modifyActivity(const std::string &desc, const std::string &newDesc, const Date &newDate) {
    Activity &modAct = helperFindActivity(desc);

    if (!modAct.getDescription().empty() || !modAct.getDate().empty()) {
        if(!newDesc.empty())
            modAct.setDescription(newDesc);
        else if(!newDate.operator==(Date()))
            modAct.setDate(newDate);
        else
            modAct.setCompleted();
    } else
        std::cout << "Sorry there's not an activity with description: " << desc << std::endl;
}

void ToDoList::setActivityCompleted(const std::string &description) {
    Activity &setAct = helperFindActivity(description);

    if (!setAct.isCompleted()){
        setAct.setCompleted();
        this->nOfComplAct++;
    }
}