#include "LinkedList.h"

TEST(testAppend, createEmptyList) {
    LinkedList<int> list;

    ASSERT_EQ(list.size(), 0);
}

TEST(testAppend, appendIntToEmptyList) {
    LinkedList<int> list;

    list.append(1);

    ASSERT_EQ(list[0], 1);
}

TEST(testAppend, appendDoubleToEmptyList) {
    LinkedList<double> doubleList;

    doubleList.append(1.618);
    ASSERT_EQ(doubleList[0], 1.618);
}

TEST(testAppend, appendCharToEmptyList) {
    LinkedList<char> charList;

    charList.append('a');
    ASSERT_EQ(charList[0], 'a');
}

TEST(testAppend, appendBoolToEmptyList) {
    LinkedList<bool> boolList;

    boolList.append(true);
    ASSERT_EQ(boolList[0], true);
}

TEST(testAppend, appendSecondInt) {
    LinkedList<int> list;

    list.append(1);
    list.append(2);

    ASSERT_EQ(list[0], 1);
    ASSERT_EQ(list[1], 2);
}

TEST(testAppend, appendMultipleInts) {
    LinkedList<int> list;

    for (int i = 0; i < 100; i++) {
        list.append(i);
    }

    bool neq = false;
    for (size_t i = 0; i < list.size(); i++) {
        if (list[i] != (int) i) {
            neq = true;
            break;
        }
    }

    ASSERT_FALSE(neq);
}

TEST(testAppend, appendDuplicate) {
    LinkedList<int> list;

    list.append(1);
    list.append(1);

    ASSERT_EQ(list[0], list[1]);
}

TEST(testRemove, removeFromOneIntList) {
    LinkedList<int> list;

    list.append(1);
    list.remove(1);

    ASSERT_EQ(list.size(), 0);
}

TEST(testRemove, removeFromOneDoubleList) {
    LinkedList<double> list;

    list.append(1.618);
    list.remove(1.618);

    ASSERT_EQ(list.size(), 0);
}

TEST(testRemove, removeFromOneCharList) {
    LinkedList<char> list;

    list.append('a');
    list.remove('a');

    ASSERT_EQ(list.size(), 0);
}

TEST(testRemove, removeFromOneBoolList) {
    LinkedList<bool> list;

    list.append(true);
    list.remove(true);

    ASSERT_EQ(list.size(), 0);
}

TEST(testRemove, removeSecondFromTwoIntList) {
    LinkedList<int> list;

    list.append(1);
    list.append(2);
    list.remove(2);

    ASSERT_EQ(list.size(), 1);
    ASSERT_TRUE(list[0] == 1);
}

TEST(testRemove, removeFirstFromTwoIntList) {
    LinkedList<int> list;

    list.append(1);
    list.append(2);
    list.remove(1);

    ASSERT_EQ(list.size(), 1);
    ASSERT_EQ(list[0], 2);
}

TEST(testRemove, removeMiddleFromThreeElementList) {
    LinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.remove(2);

    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list[0], 1);
    ASSERT_EQ(list[1], 3);
}

TEST(testRemove, removeMultipleInts) {
    LinkedList<int> list;

    for (int i = 0; i < 100; i++) {
        list.append(i);
    }

    for (int i = 0; i < 100; i++) {
        list.remove(i);
    }

    ASSERT_EQ(list.size(), 0);
}

TEST(testRemove, removeFromEmptyList) {
    LinkedList<int> list;

    ASSERT_THROW(list.remove(1), std::out_of_range);
}

TEST(testRemove, removeNonexistentInt) {
    LinkedList<int> list;
    list.append(1);
    list.append(2);

    ASSERT_THROW(list.remove(3), std::out_of_range);
}

TEST(testRemove, removeDuplicates) {
    LinkedList<int> list;
    list.append(1);
    list.append(1);
    list.remove(1);

    ASSERT_EQ(list.size(), 1);
}

