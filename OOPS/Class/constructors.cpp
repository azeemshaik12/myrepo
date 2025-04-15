#include<iostream>
using namespace std;

class employee
{
	int a;
	char c;
	string s;
public:

	//Default constructor
	employee()
	{
		a =10;
		c='A';
		s="Azeem";
		cout<<"Default constructor\n"
		    <<"ID   : "<<a
		    <<"\nGrad : "<<c
		    <<"\nName : "<<s<<endl;
	}


	//Parameter constructor
	employee(int id, char grad, string name)
	{

		a=id;
		c=grad;
		s=name;
		cout<<"\nParameter constructor\n"
		    <<"ID   : "<<a
		    <<"\nGrad : "<<c
		    <<"\nName : "<<s<<endl;
	}

	void show()
	{
		cout<<"\nShow: \n"
		    <<"ID   : "<<a
		    <<"\nGrad : "<<c
		    <<"\nName : "<<s<<endl;

	}
// copy constructor
	employee(const employee &obj)
	{
		a=obj.a;
		c=obj.c;  // shallow copy
		s=obj.s;

		cout<<"\nCopy constructor\n"
		    <<"ID   : "<<a
		    <<"\nGrad : "<<c
		    <<"\nName : "<<s<<endl;
	}

//Move constructor
	employee( employee &&obj)
	{


		a=std::move(obj.a);
		c=std::move(obj.c);
		s=std::move(obj.s);


		cout<<"\nMove constructor\n"
		    <<"ID   : "<<a
		    <<"\nGrad : "<<c
		    <<"\nName : "<<s<<endl;
	}

// conversion constructor

	operator int() const
	{
		return a;
	}

	operator char() const
	{
		return c;
	}
	operator string() const
	{
		return s;
	}


};


int main()
{
	employee e1; // default constructor

	employee e2(123,'B',"Shubham"); // Parameter cons

	employee e3(e2); // copy constructors

	employee e4(std::move(e3)); // move constructor

	e3.show();
	
	// conversion constructor

	int a=e1;
	char c=e1;
	string s=e2;
    
    cout<<"\nconversion constructor: \n";
	cout<<"e1 of a: "<<a
	    <<"\ne1 of c: "<<c
	    <<"\ne1 of s: "<<s;



	return 0;
}

