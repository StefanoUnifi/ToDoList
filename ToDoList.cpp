//
// Created by stefa on 26/08/2024.
//

#include <iostream>
#include <fstream>
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
    nOfAct++;
    nOfComplAct++;
    displayAllActivities();
}

void ToDoList::removeActivity(const std::string &description) {
    Activity deletedAct = helperFindActivity(description);

    if (!deletedAct.getDescription().empty() || !deletedAct.getDate().empty()) {
        toDoList.remove(deletedAct);
        nOfAct--;
        if (deletedAct.isCompleted())
            nOfComplAct--;
        displayAllActivities();
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
    nOfAct = 0;
    nOfComplAct = 0;
}

void ToDoList::modifyActivity(const std::string &desc, const std::string &newDesc, const Date &newDate) {
    Activity &modAct = helperFindActivity(desc);

    if (!modAct.getDescription().empty() || !modAct.getDate().empty()) {
        if(!newDesc.empty())
            modAct.setDescription(newDesc);
        else if(!newDate.operator==(Date()))
            modAct.setDate(newDate);

        this->displayAllActivities();
    } else
        std::cout << "Sorry there's not an activity with description: " << desc << std::endl;
}

void ToDoList::setActivityCompleted(const std::string &description) {
    Activity &setAct = helperFindActivity(description);

    if (!setAct.isCompleted()){
        setAct.setCompleted();
        nOfComplAct++;
    }
    displayAllActivities();
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
}

void ToDoList::displayUncompletedActivities() {
    std::cout << "\nList of uncompleted activities:" << std::endl;

    for (auto &act: toDoList) {
        if (!act.isCompleted())
            std::cout << "Description: " << act.getDescription() << " - " << act.getDate() << std::endl;
    }
}

void ToDoList::saveToFile(const std::string &fileName) const {
    std::ofstream file(fileName);

    if (file.is_open()) {
        file << title << std::endl;
        for (const auto &act: toDoList) {
            file << act.getDescription() << "- " << act.getDate() << " - ";
            if (act.isCompleted())
                file << "completed." << std::endl;
            else
                file << "uncompleted." << std::endl;
        }
        file.close();
    } else
        throw (std::runtime_error) "Sorry, the file could not be saved!";
}

void ToDoList::loadFromFile(const std::string &fileName, ToDoList &newList) {
    std::ifstream file(fileName);

    if (file.is_open()) {
        std::string line;
        std::getline(file, newList.title);

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string desc, dateString, completed;
            std::getline(ss, desc, '-');
            std::getline(ss, dateString, '-');
            std::getline(ss, completed, '.');
            bool isCompleted = (completed == "completed") ? true : false;
            Date dueDate = Activity::getDateFromString(dateString);
            newList.toDoList.emplace_back(dueDate, desc, isCompleted);
        }
        file.close();
    } else
        throw (std::runtime_error) "Sorry, the file could not be loaded!";
}