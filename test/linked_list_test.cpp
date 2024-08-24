#include <gtest/gtest.h>
#include "LinkedList.h"
/*
get
insert
remove
remove at
replace
length
isEmpty
isFull
*/
using namespace jordan;
LinkedList<int> list = LinkedList<int>();
// Demonstrate some basic assertions.
TEST(LinkedList, AddElement) {
  list.insert(1);
  list.insert(2);
  std::cout<<list;
  EXPECT_EQ(2, list.length());
}

TEST(LinkedList, GetElement){
  EXPECT_EQ(1,list.get(0));
  EXPECT_EQ(1,list.get(0));
}


TEST(LinkedList,RemoveElement){
  list.remove(2);
  std::cout<<list;
  EXPECT_EQ(1,list.length());
  EXPECT_EQ(-1,list.get(2));
}


TEST(LinkedList,replaceOneElement){
  for (int i = 0; i < 10;i ++){
    list.insert(i);
  }
  std::cout<<list;
  EXPECT_EQ(12,list.length());

}
