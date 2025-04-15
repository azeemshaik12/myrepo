// heirarchical_inheritance.cpp

#include<iostream>
using namespace std;

class manager // base class
{

protected:
	string name;
	int id;
	double sal;
public:
	manager(string name, int id, double sal)
	{
		this->name=name;
		this->id=id;
		this->sal=sal;
	}

	virtual void info()
	{
		cout<<"Employee Name : "<<name<<endl;
		cout<<"Employee ID   : "<<id<<endl;
		cout<<"Employee Sal  : "<<sal<<endl<<endl;
	}

};


class employee1: public manager // derived class
{
public:
	employee1(string name, int id, double sal):manager( name,  id,  sal)
	{

	}

	void info() override
	{
		cout<<"Employee1 info: "<<endl;
		manager::info();
	}
	

};

class employee2: public manager // derived class
{
public:
	employee2(string name, int id, double sal):manager( name,  id,  sal)
	{

	}

	void info() override
	{
		cout<<"Employee2 info: "<<endl;
		manager::info();
	}

};


int main()
{
manager m("Manager",123,90000);

m.info();

employee1 e1("Employee1",111,45000);
e1.info();

employee2 e2("Employee2",222,56769);
e2.info();

}







