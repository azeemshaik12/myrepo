// insertion sort
#include <iostream>
#include <vector>
#include <deque>
template <typename T>
void swap(T &a,T &b){
    T dummy=a;
    a=b;
    b=dummy;
}
template <typename T>
void sort(T *ptr,int size=0){
    if(size==0){
        size=ptr->size();
    }
   for(int i=1;i<size;i++){
       for(int j=0;j<size-i;j++){
          if((*ptr)[j] > (*ptr)[j+1]){
            swap((*ptr)[j],(*ptr)[j+1]);
          }
       }
   }
}
template <typename T>
void print(T *ptr,int size=0){
    if(size==0){
        size=ptr->size();
    }
    for(int i=0;i<size;i++)
    std::cout<<(*ptr)[i]<<" ";
    std::cout<<"\n";
}
int main() {
 std::vector<int> a{9,3,4,2,16,7,8};
 sort(&a);
 print(&a);
 std::deque<int> b{9,3,4,2,16,7,8};
 sort(&b);
 print(&b);
  return 0;
}
