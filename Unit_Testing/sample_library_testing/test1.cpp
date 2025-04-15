#include <gtest/gtest.h>
#include "converter.h"

//g++ test1.cpp libconvert.so -lgtest -lgtest_main -lpthread &&./a.out

TEST(Test1,decimal_to_binary){
    ASSERT_EQ(101,decimal_to_binary(5));
}
TEST(Test2,decimal_to_octal){
    ASSERT_EQ(12,decimal_to_octal(10));
}
TEST(Test3,decimal_to_hex){
    ASSERT_EQ("4C",decimal_to_hex(76));
}
TEST(Test4,binary_to_decimal){
    ASSERT_EQ(9,binary_to_decimal("1001"));
}

TEST(Test5,binary_to_octal){
    ASSERT_EQ("043",binary_to_octal("100011"));
}
TEST(Test6,binary_to_hex){
    ASSERT_EQ("2A",binary_to_hex("101010"));
}
TEST(Test7,octal_to_decimal){
    ASSERT_EQ(1523,octal_to_decimal("2763"));
}
TEST(Test8,octal_to_binary){
    ASSERT_EQ("010111110011",octal_to_binary("2763"));
}
TEST(Test9,octal_to_hex){
    ASSERT_EQ("053",octal_to_hex("123"));
}
TEST(Test10,hex_to_decimal){
    ASSERT_EQ(90,hex_to_decimal("5A"));
}
TEST(Test11,hex_to_binary){
    ASSERT_EQ("01101010",hex_to_binary("6A"));
}
TEST(Test12,hex_to_octal){
    ASSERT_EQ("174",hex_to_octal("7C"));
}
int main() {
  ::testing::InitGoogleTest();
 return RUN_ALL_TESTS();
}
