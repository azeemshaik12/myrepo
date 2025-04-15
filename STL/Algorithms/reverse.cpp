#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v1= {10,20,30,40,50,60,70,80,90};
	vector<int> v2= {11,22,33,44,55,66,77,88,99};

	cout<<"reverse: ";
    reverse(v1.begin(),v1.end());

	for(auto i : v1)
	{
		cout<<" "<<i;
	}
	
	cout<<"\nreverse range : ";
    reverse(v2.begin()+5,v2.end()-2);

	for(auto i : v2)
	{
		cout<<" "<<i;
	}

	cout<<"\nreverse_copy: ";
	
	reverse_copy(v2.begin()+3, v2.end(),v2.begin());

	for(auto i : v2)
	{
		cout<<" "<<i;
	}

	return 0;
}
