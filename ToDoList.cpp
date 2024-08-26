//
// Created by stefa on 26/08/2024.
//

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