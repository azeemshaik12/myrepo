// multilevel_inheritance

#include<iostream>
using namespace std;

class employee
{
    protected:
    int id;
    string name;
    float sal;
    public:
    employee(int id, string name, float sal)
    {
        this->id=id;
        this->name= name;
        this->sal=sal;
        cout<<"Employee ID  : "<<id<<endl;
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Employee Sal : "<<sal<<endl<<endl;
    }
    
};

class manager :public employee
{
    protected:
    int id;
    string name;
    float sal;
    public:
    manager(int id, string name, float sal): employee(id, name, sal)
    {
        this->id=id;
        this->name= name;
        this->sal=sal;
        cout<<"Manager ID  : "<<id<<endl;
        cout<<"Manager Name: "<<name<<endl;
        cout<<"Manager Sal : "<<sal<<endl<<endl;
    }
    
};

class head :public manager
{
    protected:
    int id;
    string name;
    float sal;
    public:
    head(int id, string name, float sal) :manager(id, name, sal)
    {
        cout<<"Delivery-Head ID  : "<<id<<endl;
        cout<<"Delivery-Head Name: "<<name<<endl;
        cout<<"Delivery-Head Sal : "<<sal<<endl<<endl;
    }
    
};
int main()
{
	head employee(111,"Harvard",5678.78);
	head manager(222,"Manager",8888.56);
	head h1(333,"Delivery-Head",9999.99);
	
	return 0;
}


/*
Employee ID  : 111
Employee Name: Harvard
Employee Sal : 5678.78

Manager ID  : 111
Manager Name: Harvard
Manager Sal : 5678.78

Delivery-Head ID  : 111
Delivery-Head Name: Harvard
Delivery-Head Sal : 5678.78 */
