#include "class.h"
#include <gtest/gtest.h>
#include <iostream>

class somename : public ::testing::Test {
protected:
    static int count;
    static void SetUpTestSuite(){
       std::cout<<"------------called before first test case------------------\n";
    }
    static void TearDownTestSuite(){
        std::cout<<"-----------called after last test case---------------------\n"; 
    }
     somename(){  //constructor
        std::cout<<"ctr\n";
     }
     ~somename(){ //destructor
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
TEST_F(somename, get_id) {
    azeem a(100,'A',"Azeem");
    ASSERT_EQ(a.get_id(), 100);
}
TEST_F(somename, get_grade) {
    azeem a(100,'B',"sita");
    ASSERT_EQ(a.get_grade(), 'B');
}
TEST_F(somename, get_name) {
    azeem a(100,'B',"sita");
    ASSERT_EQ(a.get_name(), "sita");
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
