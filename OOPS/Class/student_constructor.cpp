#include<iostream>
using namespace std;
class student
{
private:
	string name;
	int id;
	char rank;
public:

	// default constructor
	student()
	{

	}
	//  Parameterized constructor
	student(string n, int i, char r)
	{
		name = n;
		id = i;
		rank = r;

		cout << "Employee Name: " << name << endl;
		cout << "Employee Id : " << id << endl;
		cout << "Employee Rank: " << rank << endl;
		cout << "\n";
	}
	// Copy constructor
	student(const student& other) {
		name = other.name;
		id = other.id;
		rank = other.rank;
		cout << "Copy Constructor Called" << endl;
	}
	// Move constructor (using r-value reference)
	student(student&& other)
	{
		name = std::move(other.name);             // Move the string resource
		id = std::move(other.id);                 // Move the integer (just copy here, no resource)
		rank =std::move(other.rank);             // Move the char (just copy here, no resource)

		cout << "Move Constructor Called" << endl;
	}

	//Destructor
	~student()
	{
		cout<<"\n Destructor called \n";
	}
	// Function to show student details
	void show()
	{
		cout<<"\n";
		cout << "Employee Name: " << name << endl;
		cout << "Employee Id: " << id << endl;
		cout << "Employee Rank: " << rank << endl;
	}

};
int main()
{

	student s1("RUBIC", 40041096, 'A');
	student s2("APARS", 40041097, 'C');

	student s3(std::move(s2));
	s3.show();

	s2.show();

	return 0;
}
