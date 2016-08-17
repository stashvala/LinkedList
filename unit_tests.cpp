#include "LinkedList.h"

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

TEST(testAppend, appendSecondInt) {
    LinkedList<int> list;

    list.append(1);
    list.append(2);

    ASSERT_EQ(list.size(), 2);
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

TEST(testPrint, printOneIntList) {
    LinkedList<int> list;
    list.append(1);

    ASSERT_EQ(list.print(), "1");
}

TEST(testPrint, printOneDoubleList) {
    LinkedList<double> list;
    list.append(1.618);

    ASSERT_EQ(list.print(), "1.618");
}

TEST(testPrint, printOneCharList) {
    LinkedList<char> list;
    list.append('a');

    ASSERT_EQ(list.print(), "a");
}

TEST(testPrint, printTwoIntList) {
    LinkedList<int> list;
    list.append(1);
    list.append(2);

    ASSERT_EQ(list.print(), "1 -> 2");
}

TEST(testPrint, printThreeIntList) {
    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    ASSERT_EQ(list.print(), "1 -> 2 -> 3");
}

TEST(testPrint, printMultipleIntList) {
    LinkedList<int> list;
    std::ostringstream os;

    for (int i = 0; i < 100; i++) {
        list.append(i);
        os << i;
        if (i == 99) break;

        os << " -> ";
    }

    ASSERT_EQ(list.print(), os.str());
}

TEST(testPrint, printEmptyList) {
    LinkedList<int> list;

//    ASSERT_EQ(list.print(), "");
    ASSERT_THROW(list.print(), std::out_of_range);
}