//
// Created by stefa on 02/09/2024.
//
#include "gtest/gtest.h"
#include "../Activity.h"

TEST(ActivityTest, ConstructorTest) {
    Activity activity(Date(17, 9, 2024), "Festeggia il compleanno");
    EXPECT_EQ(activity.getDate(), "17/9/2024");
    EXPECT_EQ(activity.getDescription(), "Festeggia il compleanno");
    EXPECT_FALSE(activity.isCompleted());
}

TEST(ActivityTest, SetCompletedTest) {
    Activity activity(Date(11, 9, 2024), "Finire il laboratorio di programmazione");
    activity.setCompleted();
    EXPECT_TRUE(activity.isCompleted());
    activity.setCompleted();
    EXPECT_FALSE(activity.isCompleted());
}

TEST(ActivityTest, EqualityOperatorTest) {
    Activity activity1(Date(17, 9, 2024), "Festeggia il compleanno");
    Activity activity2(Date(17, 9, 2024), "Festeggia il compleanno");
    ASSERT_TRUE(activity1 == activity2);
}

TEST(ActivityTest, GetDateFromStringTest) {
    Date date = Activity::getDateFromString("6/9/2024");
    EXPECT_EQ(date.getDay(), 6);
    EXPECT_EQ(date.getMonth(), 9);
    EXPECT_EQ(date.getYear(), 2024);
}