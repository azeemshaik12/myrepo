
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    std::vector<int> a1{9,10,1,6,7,2,5,8,3,1};
    std::vector<int> a2{8,7,6,5,11,3,4,5,2,1};
	
	// swaps the values of two objects
     swap(a1,a2);

     cout<<"a2 copy-values: ";
     for(auto i: a2)
     {
         cout<<" "<<i;
     }
   
   
  // swaps two ranges of elements //
  
  swap_ranges(a1.begin() + 3, a1.end(), a2.begin()); 
  
  cout<<"\na1 swap_ranges-values: ";
     for(auto i: a1)
     {
         cout<<" "<<i;
     }
}
