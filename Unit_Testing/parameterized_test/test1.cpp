#include <iostream>
#include <string>
#include <gtest/gtest.h>
class azeem{
    public:
    int m_x;char m_y;

azeem(int x,char y):m_x(x),m_y(y){

}
bool operator==(const azeem &obj)const {
   return (m_x==obj.m_x&&m_y==obj.m_y);
}
std::string print(){
    return ("m_x is: "+std::to_string(m_x)+" m_y is: "+m_y+"\n");
}
};


TEST(test1,testing_objects_fail){
   azeem o1(1,'A');
   azeem o2(2,'B');
   EXPECT_EQ(o1.m_x,o2.m_x);
   EXPECT_EQ(o1.m_y,o2.m_y);
}
TEST(test2,testing_objects_pass){
   azeem o1(1,'A');
   azeem o2(1,'A');
   EXPECT_EQ(o1,o2);
}
TEST(test3,testing_objects_fail_s){
   azeem o1(1,'A');
   azeem o2(1,'G');
   EXPECT_EQ(o1,o2)<<o1.print()<<o2.print();
}

int main(){
   ::testing::InitGoogleTest();
   return RUN_ALL_TESTS();
}
   
