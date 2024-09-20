//
// Created by stefa on 05/09/2024.
//
#include "gtest/gtest.h"
#include "../ToDoList.h"

class ToDoListFixture : public ::testing::Test {
protected:
    void SetUp() override {
        todolist.addActivity(Activity(Date(6, 9, 2024), "Scrivere lo unit test delle classi"));
        todolist.addActivity(Activity(Date(9, 9, 2024), "Scrivere mail al professore"));
    }

    void TearDown() override {
        todolist.removeActivities();
    }

    ToDoList todolist{"My todolist"};
};

TEST_F(ToDoListFixture, RemoveActivityTest) {
    todolist.removeActivity("Scrivere lo unit test delle classi");
    EXPECT_EQ(todolist.getToDoList().size(), 1);

    testing::internal::CaptureStdout();
    todolist.removeActivity("Scrivere ciao al professore");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sorry there's not an activity with description: Scrivere ciao al professore\n");
    EXPECT_EQ(todolist.getToDoList().size(), 1);
}

TEST_F(ToDoListFixture, RemoveActivitiesTest) {
    todolist.removeActivities();
    ASSERT_EQ(todolist.getToDoList().size(), 0);
}

TEST_F(ToDoListFixture, SetActivityCompletedTest) {
    todolist.setActivityCompleted("Scrivere lo unit test delle classi");
    ASSERT_TRUE(todolist.getToDoList().front().isCompleted());
}

TEST_F(ToDoListFixture, ModifyActivityTest) {
    Date date;
    todolist.modifyActivity("Scrivere lo unit test delle classi","", Date(9, 9, 2024));
    EXPECT_EQ(todolist.getToDoList().front().getDate(), "9/9/2024");

    todolist.modifyActivity("Scrivere lo unit test delle classi","Scrivere lo unit test delle classi rimanenti", date);
    EXPECT_EQ(todolist.getToDoList().front().getDescription(), "Scrivere lo unit test delle classi rimanenti");

    testing::internal::CaptureStdout();
    todolist.modifyActivity("Scrivere arrivederci al professore","Scrivere buongiorno al professore", date);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sorry there's not an activity with description: Scrivere arrivederci al professore\n");
}

TEST_F(ToDoListFixture, DisplayUncompletedActivitiesTest) {
    todolist.setActivityCompleted("Scrivere lo unit test delle classi");

    testing::internal::CaptureStdout();
    todolist.displayUncompletedActivities();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "\nList of uncompleted activities:\nDescription: Scrivere mail al professore - 9/9/2024\n";
    EXPECT_EQ(output, expected);
}

TEST_F(ToDoListFixture, SaveAndLoadFileTest) {
    std::string fileName = "test.txt";
    todolist.saveToFile(fileName);

    ToDoList newList;
    ToDoList::loadFromFile(fileName, newList);

    EXPECT_EQ(newList.getTitle(), "My todolist");
    EXPECT_EQ(newList.getToDoList().size(), 2);
    EXPECT_EQ(newList.getToDoList().front().getDescription(), "Scrivere lo unit test delle classi");
    EXPECT_EQ(newList.getToDoList().front().getDate(), "6/9/2024");

    std::remove(fileName.c_str());
}