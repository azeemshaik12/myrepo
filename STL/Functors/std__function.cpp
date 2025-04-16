#include<iostream>
#include<functional>
//https://en.cppreference.com/w/cpp/utility/functional
void fun(){
    std::cout<<"void fun()\n";
}
void funt(int x){
    std::cout<<"void fun("<<x<<")\n";
}
class azeem{
  int x;
   public:
   int y;
  azeem(int _x):x(_x){
    y=x+10;  
  }
  int getx(){
      return x;
  }
  void setx(int _x){
      x=_x;
  }
  int fun(int _x,int _y){
      x=_x;y=_y;
      return x+y;
  }
  int operator()(){
      return x;
  }
  int operator()(int _x,int _y){
      return x+_x+y+_y;
  }
};
int add(int x,int y){
    return x+y;
}
//-----------------------------------------------------------
int main(){
   
  //store a free function
  
  void (*fc)()=fun; //c style 
  fc();
  
  std::function<void()> a=fun; //a became function pointer of fun
  a(); //fun() called 
  
  void (*f)(int)=funt; //c style 
  f(10);
 
  std::function<void(int x)> b=funt; //a became function object of fun()
  b(20); //fun() called 
  
  //--------------------------------------------------------------------
  //stores a lambda function
  std::function<void()>c=[](){
      std::cout<<"lamda function void()\n";
  };
  c();
  
  std::function<void()>d=[&](){
      funt(100);
      f(30);
      std::cout<<"calling other function in lamda function void()\n";
  };
  d();
  
  std::function<void(int x)>e=[](int x){
      std::cout<<"lamda void("<<x<<")\n";
  };
  e(10);
  
  std::function<int(int x)>g=[](int x){
      std::cout<<"lamda int("<<x<<")\n";
      return x;
  };
  std::cout<<g(44)<<" :returned \n";
  //--------------------------------------------------------------------
  // store a call to a member function of  struct or class 
  //normal way 
  azeem obj(100);
  obj.setx(200);
  std::cout<<"normal "<<obj.getx()<<"\n";
  //using std::function
  std::function<void(azeem&,int x)>n=&azeem::setx;
  std::function<int(azeem&)>o=&azeem::getx;
  azeem obj2(1);
  n(obj2,10000);
  std::cout<<"std::function "<<o(obj2)<<"\n";
  //--------------------------------------------------------------------
  // store a call to a data member accessor (member variable)
  //normal way for public variable
  azeem obj3(333);
  std::cout<<"normal "<<obj3.y<<"\n";
  //std::function
  std::function<int(azeem const &)>p=&azeem::y;
  std::cout<<"std::function "<<p(obj3)<<"\n";
 //---------------------------------------------------------------------
   // store a call to a member function and object
   azeem obj4(32);
   // normal call
   std::cout<<"normal call : "<<obj4.fun(10,20)<<"\n";
   //using std::function
   using std::placeholders::_1;//first argument
   using std::placeholders::_2;//second argument 
   std::function<int(int,int)>q=std::bind(&azeem::fun,&obj4,_1,_2);
   std::cout<<"std::function call : "<<q(10,20)<<"\n";
   
   std::function<int(int,int)>r=std::bind(&azeem::fun,obj4,_1,_2);
   std::cout<<"std::function call : "<<r(10,7)<<"\n";
  //-------------------------------------------------------------------
  
  // store a call to a function object (functor)
  std::function<int()> s=azeem(100);
  
  std::cout<<"functor called void :"<<s()<<"\n";
  
  std::function<int(int,int)> t=azeem(20);
  
  std::cout<<"functor called int int :"<<t(1,0)<<"\n";
  //-------------------------------------------------------------------
  
  //auto 
  auto u=fun;
  u();
  
  auto v=[](int x){
      return x*x;
  };
  std::cout<<"10 sqr is: "<<v(10)<<"\n";
  //-------------------------------------------------------------------
  // store the result of a call to std::bind
   std::function<int()> result = std::bind(add, 190,23);
    std::cout<<"stored result : "<<result();
  //-------------------------------------------------------------------
  
 return 0;   
}
