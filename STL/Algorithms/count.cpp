
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    std::vector<int> a1{2,10,8,2,4,6,8,10,12,14,2,2};
	std::vector<int> b1{6,2,3,4,55,66,77};
    std::vector<int> c1{66,1,3,5,7,9};  
   
   cout<<"No of 2's: "<<count(a1.begin(),a1.end(),2);
   
   
   cout<<"\nNo of Even numbers: "<<count_if(a1.begin(),a1.end(),[](int x){return x%2==0;});
   
   
     
}
