// multiple Inheritance

#include<iostream>
using namespace std;

class sum
{
protected:
	int a,b;
public:
	sum(int i, int j):a(i),b(j)
	{
		cout<<"sum  of two numbers: "<<i+j<<endl;
	}

};

class mul
{
protected:
	int a,b;
public:
	mul(int i, int j):a(i),b(j)
	{
		cout<<"mul  of two numbers: "<<a*b<<endl;
	}

};
class sub
{
protected:
	int a,b;
public:
	sub(int i, int j):a(i),b(j)
	{
		cout<<"sub  of two numbers: "<<a-b<<endl;
	}

};

class math:public sum, public mul, public sub
{

protected:
	int a,b;
public:
	math(int i, int j):sum(i,j),mul(i,j),sub(i,j)
	{
		cout<<"math of two numbers: "<<(i+j+2)<<endl;
	}

};

int main()
{
	int a,b;
	cout<<"Enter two numbers: ";
	cin>>a>>b;

	math m1(a,b);

	return 0;
}


/* Output:
Enter two numbers: 15 10
sum  of two numbers: 25
mul  of two numbers: 150
sub  of two numbers: 5
math of two numbers: 27*/
