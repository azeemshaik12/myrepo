#include<iostream>
using namespace std;

class employee
{
    protected:
    int id;
    string name;
    float sal;
    public:
    employee()=default;
    employee(int id, string name, float sal)
    {
        this->id=id;
        this->name= name;
        this->sal=sal;
        cout<<"Employee ID  : "<<id<<endl;
        cout<<"Employee Name: "<<name<<endl;
        cout<<"Employee Sal : "<<sal<<endl<<endl;
    }
     employee(employee &obj)
    {
        this->id=obj.id;
        this->name=obj.name;
        this->sal=obj.sal;
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
    manager()=default;
    manager(int id, string name, float sal): employee(id, name, sal)
    {
        this->id=id;
        this->name= name;
        this->sal=sal;
        cout<<"Manager ID  : "<<id<<endl;
        cout<<"Manager Name: "<<name<<endl;
        cout<<"Manager Sal : "<<sal<<endl<<endl;
    }
    manager(int id, string name, float sal,int id1, string name1, float sal1): employee(id1, name1, sal1)
    {
        this->id=id;
        this->name= name;
        this->sal=sal;
        cout<<"Manager ID  : "<<id<<endl;
        cout<<"Manager Name: "<<name<<endl;
        cout<<"Manager Sal : "<<sal<<endl<<endl;
    }
      manager(const manager &obj,employee &eobj):employee(eobj)
    {
        this->id=obj.id;
        this->name=obj.name;
        this->sal=obj.sal;
        cout<<"Manager ID  : "<<id<<endl;
        cout<<"Manager Name: "<<name<<endl;
        cout<<"Manager Sal : "<<sal<<endl<<endl;
    }
     manager(const manager &obj)
    {
        this->id=obj.id;
        this->name=obj.name;
        this->sal=obj.sal;
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
    head()=default;
    head(int id, string name, float sal):manager(id, name, sal)
    {
        this->id=id;
        this->name= name;
        this->sal=sal;
        cout<<"Delivery-Head ID  : "<<id<<endl;
        cout<<"Delivery-Head Name: "<<name<<endl;
        cout<<"Delivery-Head Sal : "<<sal<<endl<<endl;
    }
     head(int id, string name, float sal,int id1, string name1, float sal1,int id2, string name2, float sal2)
     :manager(id1, name1, sal1,id2,name2,sal2)
    {
        this->id=id;
        this->name= name;
        this->sal=sal;
        cout<<"Delivery-Head ID  : "<<id<<endl;
        cout<<"Delivery-Head Name: "<<name<<endl;
        cout<<"Delivery-Head Sal : "<<sal<<endl<<endl;
    }
     head(int id, string name, float sal,manager mobj,employee eobj)
     :manager(mobj,eobj)
    {
        this->id=id;
        this->name= name;
        this->sal=sal;
        cout<<"Delivery-Head ID  : "<<id<<endl;
        cout<<"Delivery-Head Name: "<<name<<endl;
        cout<<"Delivery-Head Sal : "<<sal<<endl<<endl;
    }
    
};
int main()
{
//  employee employee(111,"Harvard",5678.78);
//	manager manager(222,"Manager",8888.56,22222,"sss",99.0);
//	head h1(333,"Delivery-Head",9999.99,222,"manager",55.5,666,"emp",44.5);
    head h2(33,"azeem",7.77,{55,"riyaz",33.55},{556,"wwww",9807.0});
	return 0;
}
