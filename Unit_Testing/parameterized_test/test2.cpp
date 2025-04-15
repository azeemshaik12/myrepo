#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest.h>


/*method 1
sorting a vector 
{1,2,8,3}
{2,39,77,66}
{7,4,5,6}

*/
TEST(case1,testing){
    auto a= std::vector<int> {1,2,8,3};
    auto i=a;
    std::sort(a.begin(),a.end());
    
    EXPECT_EQ(a,i);
}
TEST(case2,testing){
    auto a= std::vector<int> {2,39,77,66};
    auto i=a;
    std::sort(a.begin(),a.end());
    EXPECT_EQ(a,i);
}
TEST(case3,testing){
    auto a= std::vector<int> {7,4,5,6};
    auto i=a;
    std::sort(a.begin(),a.end());
    EXPECT_EQ(a,i);
}

//method 2 decreasing common code

class azeem:public ::testing::Test{
public:
void SetUp()override{
 //don't wrie in setup
}
void TearDown()override{
  i=a;
    std::sort(a.begin(),a.end());
    EXPECT_EQ(a,i);     

}
 std::vector<int>a;
 std::vector<int>i;
};
TEST_F(azeem,testing1){
    a= std::vector<int> {1,2,8,3};
}
TEST_F(azeem,testing2){
    a= std::vector<int> {2,39,77,66};
   
}
TEST_F(azeem,testing3){
     a= std::vector<int> {7,4,5,6};  
}

//method 3 all inputs in a sinle test
TEST(allinone,testing){
    std::vector<std::vector<int>> x{{1,2,3},{7,4,5,6},{2,39,77,66}}; 
    for(int j=0;j<x.size();j++){
       auto a= x[j];
       auto i=a; 
       std::sort(a.begin(),a.end());
       EXPECT_EQ(a,i);
    } 
}

/*method 4 parameterized test
class name :public test::TestWithParam<param type >{}

TEST_P(test suitename,test casename)

INSTANTIATE_TEST_SUITE_P{any name, test site name,params}

}
*/
class paramsclass:public testing::TestWithParam<std::vector<int> >{
void SetUp()override{
 std::cout<<"-----------size is "<<GetParam().size()<<"-----------------\n";
}
void TearDown()override{
 
}
};

TEST_P(paramsclass,test_casename){
    auto a= GetParam();
    auto i=a;
    std::sort(a.begin(),a.end());
    EXPECT_EQ(a,i);
}
//first way 
INSTANTIATE_TEST_SUITE_P (
sorting,paramsclass,
testing::Values(
std::vector<int> {1,2,3},
std::vector<int> {7,4,5,6},
std::vector<int> {2,39,77,66})
);
//second way
std::vector<std::vector<int>> a{
{1,2,3},{7,4,5,6},{2,39,77,66}
};
INSTANTIATE_TEST_SUITE_P(sorting1,paramsclass,testing::ValuesIn(a),
[](const testing::TestParamInfo<paramsclass::ParamType> &info){
return std::to_string(info.param[0]); //returns string only
});



//method 5 same like 4 but with clear output 

std::vector<std::pair<std::string, std::vector<int>>> b={
{"azeem",{1,2,3}},
{"anu",{7,4,5,6}},
{"arr",{2,39,77,66}}
};

class paramsclass1:public testing::TestWithParam< std::pair<std::string, std::vector<int> > >  {
};

TEST_P(paramsclass1,test_casename1){
    auto a= GetParam().second;
    auto i=a;
    std::sort(a.begin(),a.end());
    EXPECT_EQ(a,i);
}

 INSTANTIATE_TEST_SUITE_P(sorting2,paramsclass1,testing::ValuesIn(b),
 [](const testing::TestParamInfo<paramsclass1::ParamType> &info){
 return info.param.first; //returns string only
 });



int main(){
   ::testing::InitGoogleTest();
   return RUN_ALL_TESTS();
}
