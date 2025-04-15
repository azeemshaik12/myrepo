#include <iostream>
class azeem{
  int a,arr[5];  
  public:
  //defaulted constructor
  azeem()=default;
  //initializer_list constructor
  azeem(int a,std::initializer_list<int> b){
    this->a=a;auto in=b.begin();
    for(int i=0;i<b.size();i++){
        arr[i]=*in;
        in++;
    }
  }
  //deleted constructor
  azeem(azeem &&obj)=delete;
  void display(){
      std::cout<<"a: "<<a<<"\narray is: ";
      for(int i=0;i<5;i++){
         std::cout<<arr[i]<<", ";  
      }
      std::cout<<"\n";
  }
};

int main() {
    azeem obj(3,{1,2,3,4,5});
    obj.display();
    return 0;
}
