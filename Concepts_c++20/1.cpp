#include<iostream>

//concepts
template<typename T>
requires std::integral<T>
T add(T a,T b){
    std::cout<<"method 1: ";
    return a+b;
}
//typetraits 
template<typename T>
requires std::is_integral_v<T>
T addd(T a,T b){
    std::cout<<"method 2: ";
    return a+b;
}
//3rd method
template<std::integral T>
T adds(T a,T b){
    std::cout<<"method 3: ";
    return a+b;
}
//using auto
auto addv(std::integral auto a,std::integral auto b){
    std::cout<<"method 4: ";
    return a+b;
}
//5th method
template<typename T>
T addx(T a,T b) requires std::integral<T> {
    std::cout<<"method 5: ";
    return a+b;
}
int main(){
    std::cout<<add(1,2)<<"\n";//this is integral
    std::cout<<addd(1,2)<<"\n";//this is integral
    std::cout<<adds(1,2)<<"\n";//this is integral
    std::cout<<addv(1,2)<<"\n";//this is integral
    std::cout<<addx(1,2)<<"\n";//this is integral
    //float or double will give compilation error 
    // std::cout<<addd(1.0f,2.0f)<<"\n";//this is not integral
    // std::cout<<add(1.5,2.8)<<"\n";//this is not integral
    
    return 0;
}
