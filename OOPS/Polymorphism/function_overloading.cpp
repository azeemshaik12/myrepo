// Function Overloading “Function” name should be the same and the arguments should be different.

#include<iostream>
using namespace std;

void student(int id)
{
    cout<<"student Id:    "<<id<<endl;
}

void student(double fees,string name)
{
    cout<<"student Fees:  "<<fees<<endl;
    cout<<"student Name:  "<<name<<endl;
}

void student(char grade,string rank)
{
    cout<<"student Grade: "<<grade<<endl;
    cout<<"student Rank:  "<<rank<<endl;
}


int main()
{
    student(127);
    student(55002.0,"Azeem");
    student('A',"First-Rank");
    
}
