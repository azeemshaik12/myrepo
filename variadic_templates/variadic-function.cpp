#include <iostream>
#include <string>
template<typename T>
auto fun(T a){
     if constexpr(std::is_same<T, const char*>::value){
        return atoi(a);
    }
    else{
    return a;
    }
}
template<typename T,typename ...args>
auto fun(T a,args ...A){
    
    return a*fun(A...);
}

int main() {
std::cout<<fun(1,2,3,66,28,"102");
    return 0;
}
