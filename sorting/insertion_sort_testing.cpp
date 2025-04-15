// insertion sort
#include <iostream>
void swap(int &a,int &b){
    int dummy=a;
    a=b;
    b=dummy;
}
void sort(int *ptr,int size){
    for(int i=1;i<size;i++){
      int c=ptr[i],j=i-1;
        for(;(ptr[j]>c) &&j>=0;j--){
          ptr[j+1]=ptr[j];
        }
        ptr[j+1]=c;
    }
}
void print(int *ptr,int size){
    for(int i=0;i<size;i++)
    std::cout<<ptr[i]<<" ";
    std::cout<<"\n";
}
int main() {
  int size=6;
  int v[]={12,45,23,51,19,18}; 
  print(v,size);
  sort(v,size);
  print(v,size);
  return 0;
}
