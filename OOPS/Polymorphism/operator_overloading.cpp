#include<iostream>
using namespace std;
class student {
public:
   int mark1, mark2, mark3;

   student(int i, int j, int k) : mark1(i), mark2(j), mark3(k) {}

   student() : mark1(0), mark2(0), mark3(0){}
   
   student operator+(const student& obj) // "+" operator overloaded
   {
       student res; 
       res.mark1 = mark1 + obj.mark1;
       res.mark2 = mark2 + obj.mark2;
       res.mark3 = mark3 + obj.mark3;
       return res;
   }

   void display() {
       cout << "Mark 1: " << mark1 << " Mark 2: " << mark2 << " Mark 3: " << mark3 << endl;
   }
};
int main() {
   student s1(87, 45, 76);  
   student s2(80, 55, 90);  
 
   student s3 = s1 + s2;
   
   cout << "Marks after addition: " << endl;
   s3.display();
   return 0;
}
