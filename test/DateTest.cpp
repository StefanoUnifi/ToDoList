//
// Created by stefa on 05/09/2024.
//
#include "gtest/gtest.h"
#include "../Date.h"

TEST(DateTest, ConstructorTest) {
    Date date(6, 9, 2024);
    EXPECT_EQ(date.getDay(), 6);
    EXPECT_EQ(date.getMonth(), 9);
    EXPECT_EQ(date.getYear(), 2024);
}

TEST(DateTest, DefaultConstructorTest) {
    Date date;
    EXPECT_EQ(date.getDay(), 0);
    EXPECT_EQ(date.getMonth(), 0);
    EXPECT_EQ(date.getYear(), 0);
}

TEST(DateTest, IsLeapTest) {
    Date date(6, 9, 2024);
    date.setMonth(2);
    date.setDay(29);
    ASSERT_EQ(date.getDay(), 29);
    Date date2(6, 2, 2023);
    EXPECT_THROW(date2.setDay(29), std::out_of_range);
}

TEST(DateTest, GetDaysOfMonthTest) {
    Date date(6, 9, 2024);
    date.setDay(30);
    ASSERT_EQ(date.getDay(), 30);
    EXPECT_THROW(date.setMonth(2), std::out_of_range);
    date.setMonth(1);
    date.setDay(31);
    ASSERT_EQ(date.getDay(), 31);
    date.setYear(2023);
    date.setDay(28);
    date.setMonth(2);
    ASSERT_EQ(date.getDay(), 28);
}

TEST(DateTest, EqualityOperatorTest) {
    Date d1(6, 9, 2024);
    Date d2(6, 9, 2024);

    ASSERT_TRUE(d1 == d2);
    d2.setDay(7);
    ASSERT_FALSE(d1 == d2);
}

TEST(DateTest, InvalidDateTest) {
    EXPECT_THROW(Date date(30, 2, 2024), std::out_of_range);
    EXPECT_THROW(Date date(31, 4, 2024), std::out_of_range);
    EXPECT_THROW(Date date(33, 6, 2024), std::out_of_range);
    EXPECT_THROW(Date date(0, 7, 2024), std::out_of_range);
    EXPECT_THROW(Date date(10, 0, 2024), std::out_of_range);
    EXPECT_THROW(Date date(10, 9, 1900), std::out_of_range);
}