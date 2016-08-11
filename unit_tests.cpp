#include "LinkedList.h"

TEST(testAppend, appendIntToEmptyList){
  LinkedList<int> list;
  list.append(1);
  
  ASSERT_EQ(1, list._head->getVal());
}

TEST(testAppend, appendSecondInt){
  LinkedList<int> list;
  list.append(1);
  list.append(2);
  
  ASSERT_EQ(1, list[0]);
  ASSERT_EQ(2, list[1]);
}

TEST(testAppend, appendMultipleInts){
  LinkedList<int> list;
  
  for(int i = 0; i < 100; i++){
    list.append(i);
  }

  bool neq = false;
  for(int i = 0; i < list.size(); i++){
    if(list[i] != i){
      neq = true;
      break;
    }
  }
  
  ASSERT_FALSE(neq);
}

TEST(testAppend, appendDouble){
  LinkedList<double> doubleList;
  doubleList.append(5.0);
  ASSERT_EQ(5.0, doubleList[0]);
  
  
  
  LinkedList<bool> boolList;
  boolList.append(true);
  ASSERT_EQ(true, boolList[0]);
}

TEST(testAppend, appendChar){
  LinkedList<char> charList;
  charList.append('a');
  ASSERT_EQ('a', charList[0]);
}

TEST(testAppend, appendBool){
  
}

TEST(testAppend, appendDuplicate){
  LinkedList<int> list;
  list.append(1);
  list.append(1);
  
  ASSERT_EQ(list[0], list[1]);
}
