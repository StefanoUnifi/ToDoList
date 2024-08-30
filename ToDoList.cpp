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
    this->displayAllActivities();
}

void ToDoList::removeActivity(const std::string &description) {
    Activity deletedAct = helperFindActivity(description);

    if (!deletedAct.getDescription().empty() || !deletedAct.getDate().empty()) {
        toDoList.remove(deletedAct);
        this->nOfAct--;
        if (deletedAct.isCompleted())
            this->nOfComplAct--;
        this->displayAllActivities();
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

        this->displayAllActivities();
    } else
        std::cout << "Sorry there's not an activity with description: " << desc << std::endl;
}

void ToDoList::setActivityCompleted(const std::string &description) {
    Activity &setAct = helperFindActivity(description);

    if (!setAct.isCompleted()){
        setAct.setCompleted();
        this->nOfComplAct++;
    }
    this->displayAllActivities();
}

void ToDoList::displayAllActivities() {
    std::cout << "\nList of all activities from '" << this->title << "': " << std::endl;

    for (auto &act: toDoList) {
        std::cout << "Description: " << act.getDescription() << " - ";
        if(!act.isCompleted())
            std::cout << "To be completed in " << act.getDate() << "\n";
        else
            std::cout << "Already done!" << std::endl;
    }

    if (getNumberOfActivities() == 1)
        std::cout << "\nYou have " << nOfAct << " activity and " << nOfComplAct << " completed" << std::endl;
    else if (nOfAct > 1)
        std::cout << "\nYou have " << nOfAct << " activities and " << nOfComplAct << " completed" << std::endl;
    else
        std::cout << "\nThere are no activities at the moment!" << std::endl;
}

void ToDoList::displayUncompletedActivities() {
    std::cout << "\nList of uncompleted activities:" << std::endl;

    for (auto &act: toDoList) {
        if (!act.isCompleted())
            std::cout << "Description: " << act.getDescription() << " - " << act.getDate() << std::endl;
    }

    if (nOfAct == 1)
        std::cout << "\nYou have 1 activity complete" << std::endl;
    else if (nOfAct > 1)
        std::cout << "\nYou have " << getNumberOfUncompletedActivities() << " activities to complete" << std::endl;
    else
        std::cout << "\nThere are no activities to complete at the moment!" << std::endl;
}

int ToDoList::getNumberOfActivities() const {
    return nOfAct;
}

int ToDoList::getNumberOfUncompletedActivities() const {
    return this->nOfAct - this->nOfComplAct;
}