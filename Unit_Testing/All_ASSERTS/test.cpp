#include "assert.h"
#include <gtest/gtest.h>

TEST(year_2024,2024){
 ASSERT_TRUE(is_leapyear(2024));
 EXPECT_TRUE(is_leapyear(2024));  
}
TEST(year_2023,2023){
 ASSERT_FALSE(is_leapyear(2023)); 
 EXPECT_FALSE(is_leapyear(2023));   
}

TEST(sq_10,equal){
  ASSERT_EQ(100,sq(10)); 
  EXPECT_EQ(100,sq(10)); 
}
TEST(sq_10,not_equal){
  ASSERT_NE(105,sq(10)); 
  EXPECT_NE(105,sq(10)); 
}
TEST(sq_10,greater_than_equal){
  ASSERT_GE(100,sq(10));
  EXPECT_GT(105,sq(10));  
}
TEST(sq_10,less_than_equal){
  ASSERT_LE(100,sq(10));
  EXPECT_LT(88,sq(10)); 
}

TEST(revese_string,string_eq){
  ASSERT_STREQ("MEEZA",reverse("AZEEM").c_str()); //this will take only cstring so converting std::string to cstring
  EXPECT_STREQ("MEEZA",reverse("AZEEM").c_str()); //this will take only cstring so converting std::string to cstring
}
TEST(revese_string,string_noteq){
  ASSERT_STRNE("AZEEM",reverse("AZEEM").c_str()); //this will take only cstring so converting std::string to cstring
  EXPECT_STRNE("AZEEM",reverse("AZEEM").c_str()); //this will take only cstring so converting std::string to cstring
}
TEST(revese_string,string_eq_case){
  ASSERT_STRCASEEQ("meeza",reverse("AZEEM").c_str()); //this will take only cstring so converting std::string to cstring
  EXPECT_STRCASEEQ("MEEZA",reverse("AZEEM").c_str()); //this will take only cstring so converting std::string to cstring
}
TEST(revese_string,string_noteq_case){
  ASSERT_STRCASENE("azeem",reverse("AZEEM").c_str()); //this will take only cstring so converting std::string to cstring
  EXPECT_STRCASENE("AZEEM",reverse("AZEEM").c_str()); //this will take only cstring so converting std::string to cstring
}

TEST(add,float_eq){
  ASSERT_FLOAT_EQ(2.7f,add(2.4f,0.3f));
  EXPECT_FLOAT_EQ(2.77,add(2.45,0.32));
}
TEST(add,double_eq){
  ASSERT_DOUBLE_EQ(2.7,add(2.4,0.3));
  EXPECT_DOUBLE_EQ(2.77,add(2.45,0.32));
}
TEST(add,near){
  EXPECT_NEAR(2.77,add(2.45,0.3289),0.06); //2.756 - 2.7 = 0.056 >=0.06 
  ASSERT_NEAR(2.7,add(2.4,0.356),0.056);  //2.756 - 2.7 = 0.056 >=0.56
}



int main(){
::testing::InitGoogleTest();
return RUN_ALL_TESTS();
}
