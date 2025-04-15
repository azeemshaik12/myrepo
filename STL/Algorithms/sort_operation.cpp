#include <iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;

int main()
{
	vector<int> v1= {7,5,4,9,1,3,2,6,8};
	vector<int> v2= {8,3,2,6,7,5,4,9,1};
	vector<int> v3= {8,9,2,3,4,6,1,7,1,9,1};
	vector<int> v = { 10, 45, 60, 78, 23, 21, 3 };
    vector<int> v5 = { 100, 45, 78, 23, 220 };
    vector<int> v6(5);
    
    
	cout<<"Before sort: ";
	for(auto i : v1)
		cout<<" "<<i;


// sorting
	sort(v1.begin(), v1.end());  
	cout<<"\nAfter  sort: ";
	for(auto i : v1)
	{
		cout<<" "<<i;
	}
	
// range sorting
	cout<<"\nAfter  range_sort: ";
	sort(v2.begin()+2,v2.begin()+9);
	for(auto i : v2)

		cout<<" "<<i;

//stable_sort
	cout<<"\nAfter  stable_sort: ";
	stable_sort(v3.begin(),v3.end());
	for(auto i : v3)
	{
		cout<<" "<<i;
	}
// Using std::partial_sort
	std::partial_sort(v.begin(), v.begin() + 3, v.end());
	cout << "\npartial_sort = ";
	for (auto i = 0; i < 7; ++i)
	{
		cout << v[i] << " ";
	}
	
	//partial_sort_copy

   std::partial_sort_copy(v5.begin(), v5.end(), v6.begin(), v6.end()); 
   
   cout<<"\npartial_sort_copy: ";
	for(auto i : v6)
	{
		cout<<" "<<i;
	}
   
  
  if (std::is_sorted(v.begin(),v.end())) 
  {
        std::cout << "\nSorted in the range : " << std::endl;
    } else {
        std::cout << "\nNot Sorted in the range : " <<  std::endl;
    }
    
    
    
    is_sorted_until(v.begin(),v.end());
    
    cout<< "\nthe list and the first unsorted element is " << *v.begin();
    
	return 0;
}
