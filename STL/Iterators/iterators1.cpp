#include<iostream>
#include<vector>
int main(){
/*iterator decleration
type::iterator name;

https://www.geeksforgeeks.org/iterators-c-stl/
https://en.cppreference.com/w/cpp/iterator/reverse_iterator

*/
    std::vector<int> a{1,2,3,4,5,6,7,8,9,10};
    std::vector<int>::iterator x=a.begin();
    std::vector<int>::reverse_iterator y=a.rbegin();
    //Iterator operations
    for(x=a.begin();x!=a.end();x++){
        std::cout<<*x<<",";
    }std::cout<<"\n";
    for(x=--a.end();x>=a.begin();x--){
        std::cout<<*x<<",";
    }std::cout<<"\n";
    
    for(y=a.rbegin();y<a.rend();y++){
        std::cout<<*y<<",";
    }std::cout<<"\n";
    
    for(y=--a.rend();y>=a.rbegin();y--){
        std::cout<<*y<<",";
    }std::cout<<"\n";
    
    //std::advance(itr,postion_to_move);
    //Advances an iterator by a specific number of positions.
    for(x=a.begin();x!=a.end();std::advance(x,2)){
        std::cout<<*x<<",";
    }std::cout<<"\n";
   
    for(y=a.rbegin();y<a.rend();std::advance(y,2)){
        std::cout<<*y<<",";
    }std::cout<<"\n";
    
    //itr=std::next(itr,postion_to_move);
    //Returns the iterator that is a specified number of positions ahead of the given iterator.
    for(x=a.begin();x<=a.end();x=std::next(x,3)){
        std::cout<<*x<<",";
    }std::cout<<"\n";
   
    for(y=a.rbegin();y<=a.rend();y=std::next(y,3)){
        std::cout<<*y<<",";
    }std::cout<<"\n";
    
    //itr=std::prev(itr,postion_to_move);
   // Returns the iterator that is a specified number of positions behind the given iterator.
    for(x=--a.end();x>=a.begin();x=std::prev(x,2)){
        std::cout<<*x<<",";
    }std::cout<<"\n";
   
    for(y=--a.rend();y>=a.rbegin();y=std::prev(y,2)){
        std::cout<<*y<<",";
    }std::cout<<"\n";
    
    //std::distance(itr1,itr2);
    //Returns the number of elements between two iterators.
    std::cout<<std::distance(a.begin(),a.end())<<"\n";
    std::cout<<std::distance(std::next(a.begin(),2),a.end())<<"\n";
    std::cout<<std::distance(std::next(a.begin(),2),std::prev(a.end(),3))<<"\n";
    return 0;
}
