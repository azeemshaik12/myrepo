
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    std::vector<int> a1{2,4,6,8,10,12,14};
	std::vector<int> b1{6,2,3,4,55,66,77};
    std::vector<int> c1{66,1,3,5,7,9};
   
     auto it=  find(a1.begin(),a1.end(),10);
     cout<<"Find position: "<<it - a1.begin();
     cout<<endl;
     
     
      auto b =  find_if(b1.begin(),b1.end(),[](int x)
      {
          return x % 2 == 0 && x % 3 == 0;
      }
      );
      
     cout<<"Find_if : "<<*b;
     
    auto c =  find_if_not(c1.begin(),c1.end(),[](int x)
      {
          return x % 2 == 0 && x % 3 == 0;
           
      }
      );
           cout<<"\nFind_if_not : "<<*c;
}
