//
// Created by stefa on 05/09/2024.
//
#include "gtest/gtest.h"
#include "../ToDoList.h"

TEST(ToDoListTest, ConstructorTest) {
    ToDoList toDoList("My todolist");
    EXPECT_EQ(toDoList.getTitle(), "My todolist");
    EXPECT_TRUE(toDoList.getToDoList().empty());
}

TEST(ToDoListTest, AddTodoTest) {
    ToDoList toDoList("My todolist");
    toDoList.addActivity(Activity(Date(11, 9, 2024), "Finire il lab di programmazione"));
    EXPECT_EQ(toDoList.getToDoList().size(), 1);
    EXPECT_EQ(toDoList.getToDoList().front().getDescription(), "Finire il lab di programmazione");
}