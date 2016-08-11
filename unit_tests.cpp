#include "LinkedList.h"

TEST(testAppend, appendIntToEmptyList) {
    LinkedList<int> list;
    list.append(1);

    ASSERT_EQ(1, list[0]);
}

TEST(testAppend, appendDoubleToEmptyList) {
    LinkedList<double> doubleList;
    doubleList.append(1.618);
    ASSERT_EQ(1.618, doubleList[0]);
}

TEST(testAppend, appendCharToEmptyList) {
    LinkedList<char> charList;
    charList.append('a');
    ASSERT_EQ('a', charList[0]);
}

TEST(testAppend, appendBoolToEmptyList) {
    LinkedList<bool> boolList;
    boolList.append(true);
    ASSERT_EQ(true, boolList[0]);
}

TEST(testAppend, appendSecondInt) {
    LinkedList<int> list;
    list.append(1);
    list.append(2);

    ASSERT_EQ(1, list[0]);
    ASSERT_EQ(2, list[1]);
}

TEST(testAppend, appendMultipleInts) {
    LinkedList<int> list;

    for (int i = 0; i < 100; i++) {
        list.append(i);
    }

    bool neq = false;
    for (size_t i = 0; i < list.size(); i++) {
        if (list[i] != i) {
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

    ASSERT_EQ(0, list.size());
}

TEST(testRemove, removeFromOneDoubleList) {
    LinkedList<double> list;
    list.append(1.618);
    list.remove(1.618);

    ASSERT_EQ(0, list.size());
}

TEST(testRemove, removeFromOneCharList) {
    LinkedList<char> list;
    list.append('a');
    list.remove('a');

    ASSERT_EQ(0, list.size());
}

TEST(testRemove, removeFromOneBoolList) {
    LinkedList<bool> list;
    list.append(true);
    list.remove(true);

    ASSERT_EQ(0, list.size());
}

TEST(testRemove, removeSecondFromTwoElementList) {
    LinkedList<int> list;
    list.append(1);
    list.remove(1);
}

TEST(testRemove, removeFirstFromTwoElementList) {

}

TEST(testRemove, removeMiddleFromThreeElementList) {

}

TEST(testRemove, removeMultipleElements) {

}

TEST(testRemove, removeFromEmptyList) {

}

TEST(testRemove, removeNonexistentElement) {

}

TEST(testRemove, removeDuplicates) {

}

