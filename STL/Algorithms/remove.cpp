
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    std::vector<int> a1{9,10,1,6,7,2,5,8,3,1};
    std::vector<int> a2{8,7,6,5,11,3,4,5,2,1};
	

    auto a = remove(a2.begin(),a2.end(),1);
    
    a2.erase(a,a2.end());

     cout<<"a2 remove-values: ";
     for(auto i: a2)
     {
         cout<<" "<<i;
     }
   
   cout<<"\na1 remove_if values:";
   auto ne = remove_if(a1.begin(), a1.end(),
                        [](int x) {
                          return x % 2 == 0;
                        });
    a1.erase(ne, a1.end());

    for (auto i : a1)
        cout << i << " ";
  
}
