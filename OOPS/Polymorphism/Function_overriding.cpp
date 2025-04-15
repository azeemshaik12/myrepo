// Function overriding 
// -> inheritence should be there if we are using function overriding 
// in a function same name with same parameters 


#include <iostream>
using namespace std;

class math
{
  public:
  
  void add(int a, int b) // fun name "add"
  {
      cout<<"Sum of two numbers is: "<<a+b<<endl;
  }
};

class math1:public math
{
  public:
  
  void add(int a, int b)  // same fun name "add" , arguments also same 
  {
      cout<<"Mul of two numbers is: "<<a*b;
  }
};
int main()
{
    math m1;
    math1 m2;
    m1.add(11,23);
    m2.add(11,23);
    
    return 0;
}



