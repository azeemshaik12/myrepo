// worst sorting method
#include <iostream>
void swap(int &a,int &b){
    int dummy=a;
    a=b;
    b=dummy;
}
void sort(int *ptr,int size){
    int x=0;//time complexity O(n2) 
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(ptr[i]>ptr[j]){
                swap(ptr[i],ptr[j]);
            }
            x++;
        }
    }
  std::cout<<"no.of iterations :"<<x<<"\n";
}
void print(int *ptr,int size){
    for(int i=0;i<size;i++)
    std::cout<<ptr[i]<<" ";
    std::cout<<"\n";
}
int main() {
  int v[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,17,18,19}; 
  print(v,19);
  sort(v,19);
  print(v,19);
  return 0;
}
