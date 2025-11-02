
#include "gtest/gtest.h"
#include "stack.h"

TEST(TStackTest, DefaultAndPushPop) {
    TStack<int> s(3);
    EXPECT_TRUE(s.IsEmpty());
    s.Push(10);
    s.Push(20);
    EXPECT_EQ(s.Pop(), 20);
    EXPECT_EQ(s.Pop(), 10);
    EXPECT_TRUE(s.IsEmpty());
}

TEST(TStackTest, OverflowUnderflow) {
    TStack<int> s(1);
    s.Push(1);
    EXPECT_THROW(s.Push(2), int);
    EXPECT_EQ(s.Pop(), 1);
    EXPECT_THROW(s.Pop(), int);
}

TEST(TStackTest, CopyAndMove) {
    TStack<int> a(3);
    a.Push(1);
    a.Push(2);
    TStack<int> b = a;
    EXPECT_EQ(b.Pop(), 2);
    EXPECT_EQ(b.Pop(), 1);

    TStack<int> c = std::move(a);
    EXPECT_EQ(c.Pop(), 2);
    EXPECT_EQ(c.Pop(), 1);
}

TEST(TStackTest, ExternalDataConstructor) {
    int** arr = new int*[4];
    arr[0] = new int(7); arr[1] = new int(8); arr[2]=0; arr[3]=0;
    TStack<int> s(arr,4);
    EXPECT_EQ(s.Pop(), 8);
    EXPECT_EQ(s.Pop(), 7);
    delete [] arr;
}
