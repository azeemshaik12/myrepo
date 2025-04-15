#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
#include <valarray>
#include <type_traits>
#include <algorithm>
class azeem{
    public:
    azeem(){
        std::cout<<"ctor\n";
    }
    void fun(){
        std::cout<<"normal fun\n";
    }
    void fun() const {
        std::cout<<"const fun\n";
    }
    void fun() volatile {
        std::cout<<"volatile fun\n";
    }
    void fun() const volatile {
        std::cout<<"const volatile fun\n";
    }
};
int main(){
    
  //-----------------------------all_off ,none_off, any_off <algorithm>-------------------------------------------------
   std::vector<int> a1{1,2,3,4,55,66,77};
   std::vector<int> b1{2,4,6,8,10,12,14};
   std::vector<int> c1{1,3,5,7,9};
   if(std::all_of(b1.begin(),b1.end(),[](int val){ return val%2==0;})){
       std::cout<<"all are even \n";
   }
   
   if(std::any_of(a1.begin(),a1.end(),[](int val){ return val%2==0;})){
       std::cout<<"any one is even \n";
   } 
  
   if(std::none_of(c1.begin(),c1.end(),[](int val){ return val%2==0;})){
       std::cout<<"none of them is even \n";
   }  
 //--------------------------------add__ <type_traits>-------------------------------------------------------------------   
   azeem{}.fun();
   std::add_const<azeem>::type{}.fun();     
   std::add_volatile<azeem>::type{}.fun();     
   std::add_cv<azeem>::type{}.fun();
   
   azeem obj;
   obj.fun();
   const azeem obj1;
   obj1.fun();
   volatile azeem obj2;
   obj2.fun();
   const volatile azeem obj3;
   obj3.fun();

    using a=int;
   
    auto h=std::is_rvalue_reference_v<a>;   
    std::cout<< std::boolalpha<<h<<"\n";
    using b = std::add_rvalue_reference_t<a>;
    h=std::is_rvalue_reference_v<b>; 
    a z=100;
    std::cout<<h;

 //--------------------abs <cmath>--------------------------------------------------------------------
   std::cout<<std::abs(-1)<<"\n"; //1 
   std::cout<<std::abs(-88.88)<<"\n";//88.88
    
    std::valarray<int> v{1, -2, 3, -4, 5, -6, 7, -8};
    std::valarray<int> v2 = std::abs(v);
    for (auto n : v2)
        std::cout << n << ' ';
    std::cout << '\n'; //1 2 3 4 5 6 7 8  
    

 //-------------------------------accumulate <numeric>------------------------------------------------
    std::vector<int> a{1,3,4,67,77};
    
     std::cout<<"addition :"<<std::accumulate(a.begin(),a.end(),0)<<"\n";
        
     std::cout<<"multiplication :"<<std::accumulate(a.begin(),a.end(),1,
         [](int a,int b){ return a*b;  } )<<"\n";
    
     std::cout<<"is assending :"<<std::accumulate(a.begin(),a.end(),0,
         [](int a,int b){ return a<b;  } )<<"\n";
    
     std::cout<<"is decending :"<<std::accumulate(a.begin(),a.end(),0,
         [](int a,int b){ return a>b;  } )<<"\n";
         
 //--------------------------------------------------------------------------------------------------       
         
  
    return 0;
}
