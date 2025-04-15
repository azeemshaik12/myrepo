#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fun(int &x)
{
	return x+=10;
}

int main()
{
	vector<int> v = { 10, 20, 30, 40,50, 60, 70 };


	for_each(v.begin(),v.end(),[](int &x) {
		return x=x+1;
	});

	for_each_n(v.begin(),3,fun); // fun will work for first three elemnts from begin

	for(auto i : v)

		cout<<" "<<i;

	cout<<endl;

	for_each(v.begin(),v.end(),[](int a) {
		cout<<" "<<a;
	});


}
