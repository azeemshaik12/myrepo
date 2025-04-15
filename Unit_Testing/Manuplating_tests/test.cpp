#include "class.h"
#include <gtest/gtest.h>
#include <iostream>

class somename : public ::testing::Test { //skipping all tests of a test fixture
protected:
    static int count;
    static void SetUpTestSuite(){
       std::cout<<"=====------------called before first test case------------------=====\n";
    }
    static void TearDownTestSuite(){
        std::cout<<"=====-----------called after last test case---------------------=====\n"; 
    }
     somename(){  //constructor
        std::cout<<"ctr\n";
     }
     ~somename(){ //destructor
        std::cout<<"dtr\n";
     }
    void SetUp() override { 
        GTEST_SKIP()<<"skipping all the test cases from test fixture\n";
        count++;
        std::cout << "Test case " << count << " started\n";
    }

    void TearDown() override {
        std::cout << "Test case " << count << " ended\n";
    }
};
int somename::count = 0;

TEST_F(somename, default_constructor) { 
    azeem a;
    ASSERT_EQ(a.get_id(), 0);
    ASSERT_EQ(a.get_grade(), 'F');
    ASSERT_EQ(a.get_name(), "");
}

TEST_F(somename, parameterized_constructor) {
    azeem a(100,'A',"Azeem");
    ASSERT_EQ(a.get_id(), 100);
    ASSERT_EQ(a.get_grade(), 'A');
    ASSERT_EQ(a.get_name(), "Azeem");
}
TEST_F(somename, setfunction) {
    azeem a(100,'A',"Azeem");
    a.set(101,'B',"anu");
    ASSERT_EQ(a.get_id(), 101);
    ASSERT_EQ(a.get_grade(), 'B');
    ASSERT_EQ(a.get_name(), "anu");
}



class DISABLED_somename : public ::testing::Test { //disabling all tests of a test fixture
protected:
    static int count;
    static void SetUpTestSuite(){
       std::cout<<"=====------------called before first test case------------------=====\n";
    }
    static void TearDownTestSuite(){
        std::cout<<"=====-----------called after last test case---------------------=====\n"; 
    }
     DISABLED_somename(){  //constructor
        std::cout<<"ctr\n";
     }
     ~DISABLED_somename(){ //destructor
        std::cout<<"dtr\n";
     }
    void SetUp() override { 
        count++;
        std::cout << "Test case " << count << " started\n";
    }

    void TearDown() override {
        std::cout << "Test case " << count << " ended\n";
    }
};

int DISABLED_somename::count = 0;
TEST(azeem,skipping_test){ //skipping single test case
    GTEST_SKIP()<<"skipping test\n";
    ASSERT_EQ(0, 0); 
}
TEST(azeem,DISABLED_CASE){ //disable single test case
    ASSERT_EQ(0, 0); 
}

TEST_F(DISABLED_somename, default_constructor) { 
    azeem a;
    ASSERT_EQ(a.get_id(), 0);
    ASSERT_EQ(a.get_grade(), 'F');
    ASSERT_EQ(a.get_name(), "");
}

TEST_F(DISABLED_somename, parameterized_constructor) {
    azeem a(100,'A',"Azeem");
    ASSERT_EQ(a.get_id(), 100);
    ASSERT_EQ(a.get_grade(), 'A');
    ASSERT_EQ(a.get_name(), "Azeem");
}
TEST_F(DISABLED_somename, setfunction) {
    azeem a(100,'A',"Azeem");
    a.set(101,'B',"anu");
    ASSERT_EQ(a.get_id(), 101);
    ASSERT_EQ(a.get_grade(), 'B');
    ASSERT_EQ(a.get_name(), "anu");
}
TEST_F(DISABLED_somename, get_id) {
    azeem a(100,'A',"Azeem");
    ASSERT_EQ(a.get_id(), 100);
}
TEST_F(DISABLED_somename, get_grade) {
    azeem a(100,'B',"sita");
    ASSERT_EQ(a.get_grade(), 'B');
}
TEST_F(DISABLED_somename, get_name) {
    azeem a(100,'B',"sita");
    ASSERT_EQ(a.get_name(), "sita");
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
