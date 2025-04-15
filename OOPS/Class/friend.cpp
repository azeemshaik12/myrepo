// Friend function


#include<iostream>
using namespace std;

class student
{

private:
	int money1= 100;

protected:
	int money2=200;

public:
	int money3= 300;

	friend void show();

	friend class master;


};


class master
{

private:
	int fee1= 111;

protected:
	int fee2=222;

public:
	int fee3= 333;

	void display()
	{
		student s3;
		cout<<"s3 money3: "<<s3.money3<<endl;
		cout<<"s3 money2: "<<s3.money2<<endl;
		cout<<"s3 money1: "<<s3.money1<<endl;
	}
	friend class student;
};



void show()
{
	student s1;
	cout<<"s1 money3: "<<s1.money3<<endl;
	cout<<"s1 money2: "<<s1.money2<<endl;
	cout<<"s1 money1: "<<s1.money1<<endl<<endl;
}


int main()
{
	student s1;
	show();

	master m1;
	m1.display();


}















