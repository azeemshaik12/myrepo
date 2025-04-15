#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v1= {10,20,20,20,30,40,40,50,60,60,70,80,90};
	vector<int> v2= {11,22,33,44,55,66,77,88,99};

	cout<<"unque: ";
	auto u = unique(v1.begin(),v1.end());

	v1.resize(distance(v1.begin(), u));

	for(auto i : v1)
	{
		cout<<" "<<i;
	}

	cout<<"\nunique_copy: ";
	auto uc = unique_copy(v1.begin()+2, v1.end(),v1.begin());

	v1.resize(distance(v1.begin(), uc));

	for(auto i : v1)
	{
		cout<<" "<<i;
	}


	return 0;
}
