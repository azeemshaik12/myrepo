// selection sort
#include <iostream>
void swap(int &a,int &b){
    int dummy=a;
    a=b;
    b=dummy;
}
void sort(int *ptr,int size,int flag=0){
    int x=0;//time complexity O(n2) or (n*(n-1))/2
    char p='<';
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if( (flag) ? (ptr[j] > ptr[i]) : (ptr[j] < ptr[i]) ){
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
  int v[]={12,45,23,51,19,18}; 
  print(v,6);
  sort(v,6,1);
  print(v,6);
  
  sort(v,6);
  print(v,6);
  return 0;
}
