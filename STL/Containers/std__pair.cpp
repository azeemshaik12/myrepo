#include <iostream>
#include <vector>

namespace anu{
template<typename A,typename B>
struct pair{
  A first;
  B second;
  pair(A _first=0,B _second='\0'):first(_first),second(_second){
     std::cout<<"custom pair created\n";
  }
  template<int num>
  auto& get(){
      if constexpr (num==0){
          return first;
      }
    else if constexpr (num==1){
        return second;
    }
    else{
      static_assert(num<1, "Index out of bounds");
      //return second;
    }
    }
};
}

struct azeem{
  int first;
  char second;
  double third;
};
int main(){
    std::pair< int, int > a(1,2);
    std::pair< int, int > b=std::make_pair(100,200);
    std::cout<<std::get<0>(a)<<"   "<<std::get<1>(a)<<"\n"; 
    std::cout<<b.first<<" "<<b.second<<"\n";
 //------------------------------------------------------------
    std::pair< std::vector<int>, std::vector<char> > o;
    o.first.push_back(10);
    o.first.push_back(20);
    o.first.push_back(33);
    o.first.push_back(44);
    
    o.second.push_back('A');
    o.second.push_back('B');
    o.second.push_back('C');
    o.second.push_back('D');
    
    std::cout<<std::get<0>(o).size()<<"   "<<std::get<1>(o).size()<<"\n";
    
    for(auto i:o.first){
        std::cout<<i<<",";
    }
    std::cout<<"\n";
    for(auto i:o.second){
        std::cout<<i<<",";
    }
     std::cout<<"\n";
  //------------------------------------------------------------   
    std::pair< std::pair<int,char> , std::pair<int,char> > x;
    
    x.first.first =10;
    x.second.first =23;
    x.first.second ='A';
    x.second.second ='D';
    
std::cout<< std::get<0>(std::get<0> (x)) <<","<<std::get<1>(std::get<0> (x))<<"\n";
   
std::cout<< std::get<0>(std::get<1> (x)) <<","<<std::get<1>(std::get<1> (x))<<"\n";
 //------------------------------------------------------------   
    std::pair<azeem,azeem> l;
    
    l.first.first=20;
    l.first.second='a';
    l.first.third=22.3;
    
    l.second.first=40;
    l.second.second='A';
    l.second.third=44.6;
    
 std::cout<<std::get<0>(l).first<<" , "<<std::get<0>(l).second<<" , "
           <<std::get<0>(l).third<<"\n";
 
 std::cout<<l.second.first<<" , "<<l.second.second<<" , "<<l.second.third<<"\n";
 
//------------------------------------------------------------ 
   anu::pair<int,char> d;
   std::cout<<d.first<<" , "<<d.second<<"\n";
   d.get<0>()=99;
   d.get<1>()='A';
   std::cout<<d.get<0>()<<" , "<<d.second<<"\n";
//------------------------------------------------------------ 
   anu::pair< anu::pair<int,int> , anu::pair<char,char> > t;
   
   t.get<0>().get<0>()=100;
   t.get<0>().get<1>()=200;
   
   t.get<1>().get<0>()='A';
   t.get<1>().get<1>()='B';
   
   std::cout<<t.first.first<<" , "<<t.first.second<<"\n";
   std::cout<<t.second.first<<" , "<<t.second.second<<"\n";
//------------------------------------------------------------      
    return 0;
}
