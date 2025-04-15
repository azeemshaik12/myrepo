#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v1= {10,20,30,40,50,60,70,80,90};
	vector<int> v2= {11,22,33,44,55,66,77,88,99};

	cout<<"rotate: ";
    rotate(v1.begin(),v1.begin()+3,v1.end());

	for(auto i : v1)
	{
		cout<<" "<<i;
	}
	
	cout<<"\nrotate range : ";
    rotate(v2.begin(),v2.begin()+5,v2.end());

	for(auto i : v2)
	{
		cout<<" "<<i;
	}
	
	
	cout<<"\nrotate_copy: ";
	
	rotate_copy(v1.begin()+5, v1.begin() + 5, v1.begin()+5 , v1.end()); 

	for(auto i : v1)
	{
		cout<<" "<<i;
	}

	return 0;
}
