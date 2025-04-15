#include <iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;

int main()
{
	vector<int> v1= {10,20,30,40,50,60,70,80,90};
	vector<int> v2= {11,22,33,44,55,66,77,88,99};


	cout<<"Before shuffle: ";

	for(auto i : v1)

		cout<<" "<<i;

	std::random_device rd;
	std::mt19937 g(rd());

	shuffle(v1.begin(), v1.end(),g);

	cout<<"\nAfter  shuffle: ";
	for(auto i : v1)

		cout<<" "<<i;
	return 0;
}
