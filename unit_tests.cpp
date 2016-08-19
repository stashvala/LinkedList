#include "LinkedList.h"

TEST(testAppend, appendElementToEmptyList) {
    LinkedList<int> list;

    list.append(1);

    ASSERT_EQ(list[0], 1);
}

TEST(testAppend, appendSecondElement) {
    LinkedList<int> list;

    list.append(1);
    list.append(2);

    ASSERT_EQ(list.size(), 2);
}

TEST(testAppend, appendMultipleElements) {
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

TEST(testRemove, removeFromOneElementList) {
    LinkedList<int> list;

    list.append(1);
    list.remove(1);

    ASSERT_EQ(list.size(), 0);
}

TEST(testRemove, removeSecondFromTwoElementList) {
    LinkedList<int> list;

    list.append(1);
    list.append(2);
    list.remove(2);

    ASSERT_EQ(list.size(), 1);
    ASSERT_TRUE(list[0] == 1);
}

TEST(testRemove, removeFirstFromTwoElementList) {
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

TEST(testRemove, removeMultipleElements) {
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

TEST(testRemove, removeNonexistentElement) {
    LinkedList<int> list;
    list.append(1);
    list.append(2);

    ASSERT_THROW(list.remove(3), std::out_of_range);
}

TEST(testPrint, printOneElementList) {
    LinkedList<int> list;
    list.append(1);

    ASSERT_EQ(list.print(), "1");
}

TEST(testPrint, printTwoElementList) {
    LinkedList<int> list;
    list.append(1);
    list.append(2);

    ASSERT_EQ(list.print(), "1 -> 2");
}

TEST(testPrint, printMultipleElementList) {
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

    ASSERT_EQ(list.print(), "");
}

TEST(testSort, sortElementListAscending) {
    LinkedList<int> list;

    for (int i = 99; i >= 0; i--) {
        list.append(i);
    }

    list.sort(true);

    bool neq = false;
    for (size_t i = 0; i < list.size(); i++) {
        if (list[i] != (int) i) {
            neq = true;
            break;
        }
    }

    ASSERT_FALSE(neq);
}

TEST(testSort, sortElementListDescending) {
    LinkedList<int> list;

    for (int i = 0; i < 100; i++) {
        list.append(i);
    }

    list.sort(false);

    bool neq = false;
    for (size_t i = 0; i < list.size(); i++) {
        if (list[i] != (int) (list.size() - 1 - i)) {
            neq = true;
            break;
        }
    }

    ASSERT_FALSE(neq);
}

TEST(testSort, sortOneElementList) {
    LinkedList<int> list;
    list.append(1);

    ASSERT_NO_THROW(list.sort());
    ASSERT_EQ(list[0], 1);
}

TEST(testSort, sortEmptyList) {
    LinkedList<int> list;

    ASSERT_THROW(list.sort(), std::out_of_range);
}