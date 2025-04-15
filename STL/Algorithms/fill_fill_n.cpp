
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    std::vector<int> a1{9,10,1,6,7,2,5,8,3,1};
    std::vector<int> a2{8,7,6,5,11,3,4,5,2,1};
	
// copy-assigns the given value to every element in a range

     fill(a2.begin(),a2.end(),77);;

     cout<<"a2 fill-values: ";
     for(auto i: a2)
     {
         cout<<" "<<i;
     }
   
   // copy-assigns the given value to N elements in a range
    fill_n(a1.begin()+5,5,88);;

     cout<<"\na1 fill_n-values: ";
     for(auto i: a1)
     {
         cout<<" "<<i;
     }
  
}
