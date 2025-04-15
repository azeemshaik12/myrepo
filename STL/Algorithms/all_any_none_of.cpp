
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fun(int &x)
{
	return x+=100;
}

int main()
{
	vector<int> v = { 10, 20, 30, 40,50, 60, 70 };
	vector<int> v1 = { 10, 20, 30, 40,50, 60, -70 };
	vector<int> v2 = { -10, -20, -30, -40,-50, -60, 70 };
	
	// all_of- all condition should be satisfy
	all_of(v.begin(),v.end(),[](int x)
	{
	    return x>0;
	    
	}
	)?
	
	cout<<"all are positive values: \n":
	cout<<"all are not positive values \n";
	
// any_of- atleast one condition should be satisfy
	any_of(v1.begin(),v1.end(),[](int x)
	{
	    return x<0;
	    
	}
	)?
	
	cout<<"atleast one negative value: \n":
	cout<<"all are positive: \n";
	
	
	none_of(v2.begin(),v2.end(),[](int x)
	{
	    return x>0;
	    
	}
	)?
	
	cout<<"No positive values \n":
	cout<<"positive values are prsent: \n";
return 0;

}
