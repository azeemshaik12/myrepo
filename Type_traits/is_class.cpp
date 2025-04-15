#include<iostream>
class azeem{
    
};
int main(){
    azeem obj;
    std::cout<<std::boolalpha<<std::is_class<azeem>::value<<"\n";
    std::cout<<std::boolalpha<<std::is_class<int>::value;
    return 0;
}
