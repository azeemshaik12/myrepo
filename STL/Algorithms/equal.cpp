
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    std::vector<int> a1{2,10,8,2,4,6,8,10,12,14,2,2};
	std::vector<int> b1{2,10,8,2,4,6,8,10,12,14,2,2};
    std::vector<int> c1{66,1,3,5,7,9};
   
   
   
   equal(a1.begin(),a1.end(),b1.begin(),b1.end())?
   
   cout<<"Both are equal \n":
   cout<<"Both are not equal: \n";
   
   
   equal(a1.begin(),a1.end(),c1.begin())?
   
   cout<<"Both are equal \n":
   cout<<"Both are not equal: \n";
   
     
}
