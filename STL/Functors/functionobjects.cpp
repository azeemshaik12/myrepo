#include<iostream>
#include<functional>
//https://en.cppreference.com/w/cpp/utility/functional

int main(){
  auto x=std::plus{};//x became addition function
  std::cout<<x(1,2)<<"\n";
  
  auto y=std::minus{}; //y became subtraction function
  std::cout<<y(5,2)<<"\n";
  
  auto z=std::multiplies{}; //z became multiplication function
  std::cout<<z(5,2)<<"\n";
  
  auto a=std::divides{}; //a became division function
  std::cout<<a(5,2)<<"\n";
  
  auto b=std::modulus{}; //b became modules function
  std::cout<<b(5,2)<<"\n";
  
  auto c=std::negate{}; //c became -ve function makes +ve to -ve viseversa
  std::cout<<c(5)<<"\n";
  
  auto d=std::equal_to{}; //d became == function
  std::cout<<d(5,5)<<"\n";
  
  auto e=std::not_equal_to{}; //e became != function
  std::cout<<e(5,2)<<"\n";
  
  auto f=std::greater{}; //e became > function
  std::cout<<f(5,2)<<"\n";//5>2=1
  
  auto g=std::less{}; //g became < function
  std::cout<<g(5,2)<<"\n";//5<2=0
  
  auto h=std::greater_equal{}; //h became >= function
  std::cout<<h(5,2)<<"\n";//5>=2=1
  
  auto i=std::less_equal{}; //i became <= function
  std::cout<<i(5,5)<<"\n";//5<=5=1
  
  std::cout<<std::boolalpha;
  auto j=std::logical_and{}; //j became && function
  std::cout<<j(true,true)<<"\n"; // both true = ture
  
  auto k=std::logical_or{}; //k became || function
  std::cout<<k(true,false)<<"\n"; // any one true true = ture
  
  auto l=std::logical_not{}; //l became ! function
  std::cout<<l(true)<<"\n"; 
  
  auto m=std::bit_and{};  // m became & (x&y)
  std::cout<<m(2,3)<<"\n";
  
  auto n=std::bit_or{};  // n became | (x|y)
  std::cout<<m(8,7)<<"\n";
  
  auto o=std::bit_xor{};  // o became ^ (x^y)
  std::cout<<o(8,7)<<"\n";
  
  auto p=std::bit_not{};  // p became ~ (~x)
  std::cout<<p(8)<<"\n";
  
 return 0;   
}
