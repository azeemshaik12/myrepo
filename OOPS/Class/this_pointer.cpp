// this pointer :
// this is a keyword that refers to the current instance of the class.

#include<iostream>
using namespace std;

class employee
{
public:
	int id;
	string name;
	float salary;

	employee(int id, string name, float salary)
	{
		this->id=id;
		this->name=name;
		this->salary=salary;
	}


	void show()
	{
		cout<<"Employee ID     : "<<id<<endl;
		cout<<"Employee Name   : "<<name<<endl;
		cout<<"Employee Salary : "<<salary<<endl<<endl;
	}

};


int main()
{
	employee e1(12345,"Engineer-3",56789.89);
	employee e2(98742,"Engineer-5",36489.25);

	e1.show();
	e2.show();

}

