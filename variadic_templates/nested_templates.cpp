#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <set>
#include <deque>
#include <forward_list>
#include <unordered_set>
#include <queue>
//nested templates
//link : https://stackoverflow.com/questions/20373466/nested-c-template-parameters-for-functions
//https://youtu.be/SZOabH-l51E?si=L5DbDg_tb8dgwOy2
template<typename T,template <typename> class V>
    std::ostream & operator<<(std::ostream &os,V<T> &a){
    if constexpr (std::is_same<V<T>,std::list<T>>::value){
        std::cout<<"list               elements are : ";
    }
    else if constexpr (std::is_same<V<T>,std::vector<T>>::value){
        std::cout<<"vector             elements are : ";
    }
    else if constexpr (std::is_same<V<T>,std::set<T>>::value){
        std::cout<<"set                elements are : ";
    }
    else if constexpr (std::is_same<V<T>,std::deque<T>>::value){
        std::cout<<"deque              elements are : ";
    }
     else if constexpr (std::is_same<V<T>,std::forward_list<T>>::value){
        std::cout<<"forward_list       elements are : ";
    }
     else if constexpr (std::is_same<V<T>,std::multiset<T>>::value){
        std::cout<<"multiset           elements are : ";
    }
     else if constexpr (std::is_same<V<T>,std::unordered_set<T>>::value){
        std::cout<<"unordered_set      elements are : ";
    }
     else if constexpr (std::is_same<V<T>,std::unordered_multiset<T>>::value){
        std::cout<<"unordered_multiset elements are : ";
    }
    std::accumulate(a.begin(),a.end(),0,[&](T x,T y){
    std::cout<<y<<" , ";
    return y;
    });
    return os;
} 


int main() {
 std::vector<int> a{1,2,34,5,6,7};
 std::vector<float> b{1.6,2.9,34.9,5.9,6.0,7.99};
 std::list<int> x{2,3,45,6,7,88};
 std::set<int> s{2,3,45,6,7,88};
 std::deque<char> dq{'A','B','C','D','E'};
 std::forward_list<char> fl{'A','B','C','D','E'};
 std::multiset<int> ms{2,3,45,6,7,88};
 std::unordered_set<double> us{1.6,2.9,34.9,5.9,6.0,7.99};
 std::unordered_multiset<double> ums{1.6,2.9,34.9,5.9,6.0,7.99};
 
 std::cout<<a<<"\n"<<b<<"\n"<<x<<"\n"<<s<<"\n"<<dq<<"\n"<<fl<<"\n"
          <<ms<<"\n"<<us<<"\n"<<ums<<"\n";
 return 0;   
}
