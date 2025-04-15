#include<iostream>
#include<string>
#include<vector>
class azeem{
    
};
template <typename T>
void fun(T data){
    if constexpr(std::is_same<T,int>::value)
    std::cout<<"int fun\n";
    else if constexpr(std::is_same<T,char>::value)
    std::cout<<"char fun\n";
    else if constexpr(std::is_same<T,double>::value)
    std::cout<<"double fun\n";
    else if constexpr(std::is_same<T,float>::value)
    std::cout<<"float fun\n";
    else if constexpr(std::is_same<T,std::string>::value)
    std::cout<<"std::string fun\n";
    else if constexpr(std::is_same<T,std::vector<int>>::value)
    std::cout<<"std::vector<int> fun\n";
    else if constexpr(std::is_same<T,azeem>::value)
    std::cout<<"class azeem fun\n";
}
int main(){
    fun<int>(10);
    fun<char>(10);
    fun<double>(10);
    fun<float>(10);
    fun<std::string>("10");
    fun<std::vector<int>>({1,2,3,4});
    azeem x;
    fun<azeem>(x);
    
    return 0;
}
