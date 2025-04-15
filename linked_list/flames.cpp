// flames
//g++ flames.cpp -std=c++17 -o flames   (for linux build)
// x86_64-pc-nto-qnx7.1.0-g++ -std=gnu++17 flames.cpp -o flames  (for Qnx build)
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <unistd.h>
template<typename T>
class node{
    public:
    node *prev;
    T data;
    node *next;
    node(T value){
        prev=nullptr;
        next=nullptr;
        data=value;
    }
};
template<typename T>
class cd_list{
    node<T> * head,*tail;int m_size;
    public:
    cd_list(){
        head=nullptr;
        tail=nullptr;
        m_size=0;
    }
    cd_list(std::initializer_list<T> init){
      head=nullptr,tail=nullptr;m_size=0;
      auto ptr=init.begin();
       for(int i=0;i<init.size();i++){
           
           this->push_back(*(ptr));
           ptr++;
       }
      
    }
    
 void push_back(T value){
     if(head==nullptr){
         head=new node<T>(value);
         head->next=head;
         head->prev=head;
         tail=head;
         m_size++;
     }
     else{
         node<T> *newnode=new node<T>(value);
         newnode->next=head;
         head->prev=newnode;
         tail->next=newnode;
         newnode->prev=tail;
         tail=newnode;
         m_size++;
     }
 }
  void push_front(T value){
     if(head==nullptr){
         head=new node<T>(value);
         head->next=head;
         head->prev=head;
         tail=head;
         m_size++;
     }
     else{
         node<T> *newnode=new node<T>(value);
         newnode->next=head;
         head->prev=newnode;
         head=newnode;
         head->prev=tail;
         tail->next=head;
         m_size++;
     }
 }
 void pop_front(){
     node<T> *dummy=head;
     head=head->next;
     head->prev=tail;
     tail->next=head;
     delete dummy;
     m_size--;  
 }
  void pop_back(){
     node<T> *dummy=tail;
     tail=tail->prev;
     tail->next=head;
     head->prev=tail;
     delete dummy;
     m_size--;  
 }
 int size(){
     return m_size;
 }
void rprint_list(){
      node<T> *dummy=tail;
      do{
         std::cout<<dummy->data<<",";
         dummy=dummy->prev;

      }while(dummy!=tail);
      std::cout<<"\nsize_of_list_is:"<<this->size()<<"\n";
  }
  
 T getfront_index(int index){
     int i=0;node<T> *dummy=head;
     while(i<index){
         dummy=dummy->next;
         i++;
     }
     std::cout<<dummy->data<<"\n";
     return dummy->data;
 }
  T getback_index(int index){
     int i=0;node<T> *dummy=tail;
     while(i<index){
         dummy=dummy->prev;
         i++;
     }
     std::cout<<dummy->data<<"\n";
     return dummy->data;
 }
 void add_at_back(int pos,T value){
    if(pos>m_size||pos<0){
        std::cout<<"out of boundery\n";
    } 
    else if(pos==0){
      this->push_back(value); 
    }
    else if(pos==m_size){
      this->push_front(value); 
    }
    else{
        int i=0;node<T> *dummy=tail;
        while(i<pos){
            dummy=dummy->prev;
            i++;
        }
     node<T> *newnode=new node<T>(value);
     newnode->next=dummy->next;
     newnode->prev=dummy;
     (dummy->next)->prev=newnode;
     dummy->next=newnode;
      m_size++;

    }
    }
    void add_at_front(int pos,T value){
    if(pos>m_size||pos<0){
        std::cout<<"out of boundery\n";
    } 
    else if(pos==0){
      this->push_front(value); 
    }
    else if(pos==m_size){
      this->push_back(value); 
    }
    else{
        int i=1;node<T> *dummy=head;
    while(i<pos){
        dummy=dummy->next;
        i++;
    }
     node<T> *newnode=new node<T>(value);
     newnode->next=dummy->next;
     newnode->prev=dummy;
     (dummy->next)->prev=newnode;
     dummy->next=newnode;
     m_size++;
    }
    }
    
    void remove_at_front(int pos){
    if(pos>m_size||pos<0){
        std::cout<<"out of boundery\n";
    } 
    else if(pos==0){
      this->pop_front(); 
    }
    else if(pos==m_size){
      this->pop_back(); 
    }
    else{
        int i=0;node<T> *dummy=head;
    while(i<pos){
        dummy=dummy->next;
        i++;
    }
    (dummy->prev)->next=dummy->next;
    (dummy->next)->prev=dummy->prev;
    delete dummy;
    m_size--;
    }
    }
  
  void remove_at_back(int pos){
    if(pos>m_size||pos<0){
        std::cout<<"out of boundery\n";
    } 
    else if(pos==0){
      this->pop_back(); 
    }
    else if(pos==m_size){
      this->pop_front(); 
    }
    else{
        int i=0;node<T> *dummy=tail;
    while(i<pos){
        dummy=dummy->prev;
        i++;
    }
    (dummy->prev)->next=dummy->next;
    (dummy->next)->prev=dummy->prev;
    delete dummy;
    m_size--;
    }
    }  
    
void reverse(){
node<T> * dummy,*dtail=tail;int i=0;node<T> *du=head;
while(i<m_size){
    dummy=dtail->next;
    dtail->next=dtail->prev;
    dtail->prev=dummy;
    dtail=dtail->next;
    i++;
}
head=tail;
tail=du;
head->prev =tail;
tail->next=head;
}

~cd_list(){
    tail->next=nullptr;head->prev=nullptr;
    node<T> *dummy=head;
    while(dummy!=nullptr){
      node<T> *dummy2=dummy->next;
      //std::cout<<"deleting "<<dummy->data<<"\n";
      delete dummy;
      dummy=dummy2;
    }
}
T& at(int index){
    if(index>=m_size||index<0){
        std::cout<<"out of boundary\n";
        return head->data;
    }
    else{
        int i=0;node<T> *dummy=head;
        while(i<index){
            dummy=dummy->next;
            i++;
        }
        return dummy->data;
    }
  }
  T& rat(int index){
    if(index>=m_size||index<0){
        std::cout<<"out of boundary\n";
        return head->data;
    }
    else{
        int i=0;node<T> *dummy=tail;
        while(i<index){
            dummy=dummy->prev;
            i++;
        }
        return dummy->data;
    }
  }
   T& operator[](int index){
    if(index>=m_size||index<0){
        std::cout<<"out of boundary\n";
        return head->data;
    }
    else{
        int i=0;node<T> *dummy=head;
        while(i<index){
            dummy=dummy->next;
            i++;
        }
        return dummy->data;
    }
  }
void print_list(){
       if constexpr (std::is_same<T, std::vector<std::string>>::value) {
         int j=0; node<T> *dummy=head;
         do{
         int i=0;
         std::cout<<"{";
         while(i<(dummy->data).size()){
           std::cout<<(dummy->data)[i]<<", ";
           i++;
         }
         dummy=dummy->next;
         std::cout<<"},";
         j++;
         }while(j<m_size);
         std::cout<<"\n";
      }
      else{
      node<T> *dummy=head;
      do{
         std::cout<<dummy->data<<",";
         dummy=dummy->next;

      }while(dummy!=head);
      std::cout<<"\nsize_of_list_is:"<<this->size()<<"\n";
      }
  }
  
void remove_circle(int pos){
        int i=1;node<T> *dummy=head;
    while(i<pos){
        dummy=dummy->next;
        i++;
    }
    head=dummy->next;
    tail=dummy->prev;
    head->prev=tail;
    tail->next=head;
    delete dummy;
    m_size--;
    }
    
  //end of class  
};




int mark(std::string &n1,std::string &n2){
    int count=0;
   for(int i=0;i<n1.size();i++){
       for(int j=0;j<n2.size();j++){
           if((n1[i]==n2[j])&&(n1[i]!='/')&&(n2[j]!='/')){
               n1[i]='/';
               n2[j]='/';
           }
       }
   }
   for(int i=0;i<n1.size();i++){
       if(n1[i]=='/'){
           continue;
       }
       else{
        count++;   
       }
   }
    for(int i=0;i<n2.size();i++){
       if(n2[i]=='/'){
           continue;
       }
       else{
        count++;   
       }
   }
   return count;
}
int flames(){
 cd_list<char> l{'F','L','A','M','E','S'};
    std::string name1,name2;
    std::cout<<"Note: Don't use spaces between name\nEnter First Name\n";
    std::cin>>name1;
    std::cout<<"Enter Second Name\n";
    std::cin>>name2;
    transform(name1.begin(), name1.end(), name1.begin(), ::tolower); 
    transform(name2.begin(), name2.end(), name2.begin(), ::tolower);
    int a=mark(name1,name2);
   // std::cout<<name1<<"\n"<<name2<<"\ncount is:";
  //  std::cout<<a<<"\n";
    if(a==0){
        std::cout<<"No common letters both names may be same\n";
        return 0;
    }
    while(l.size()!=1){
     l.remove_circle(a);
    }
    std::cout<<"\n\n";
    sleep(1);
    switch(l[0]){
        case 'F':
        std::cout<<"<---- Friend ------>\n"; break;
        case 'L':
        std::cout<<"<----- Love ------>\n"; break;
        case 'A':
        std::cout<<"<--- Attraction --->\n"; break;
        case 'M':
        std::cout<<"<---- Marriage ----->\n"; break;
        case 'E':
        std::cout<<"<----- Enemy ------->\n"; break;
        case 'S':
        std::cout<<"<---- Sister ------->\n"; break;
    } 
    std::cout<<"\n\n";
    return 0;
}
int main(){
    while(1){
      flames(); 
      sleep(1);
      system("clear");//use for linux and windows 
      //system("printf'\033c'");   //use for Qnx
    }
    return 0;
}