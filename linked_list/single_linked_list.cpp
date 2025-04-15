// single linked list 
#include <iostream>
#include<string>
#include<vector>
template<typename T>
class node{
  public:
  T data;
  node * next;
  node(T value){
      data=value;
      next=nullptr;
  }
};
template<typename T>
class list{
  node <T> *head,*tail;
  int m_size;
  public:
  list(){
     head =nullptr; 
     tail =nullptr; 
     m_size=0;
  }
  list(std::initializer_list<T>init){
     head =nullptr; 
     tail =nullptr; 
     m_size=0;auto ptr=init.begin();
     for(int i=0;i<init.size();i++){
         this->push_back(*ptr);
         ptr++;
     }
  } 
  void push_back(T value){
      if(head==nullptr){
          head=new node<T>(value);
          tail=head;
          m_size++;
      }
      else{
          node<T> *dummy=new node<T>(value);
          tail->next=dummy;
          tail=dummy;
          m_size++;
      }
  }
  void push_front(T value){
      if(head==nullptr){
          head=new node<T>(value);
          tail=head;
          m_size++;
      }
      else{
          node<T> *dummy=new node<T>(value);
          dummy->next=head;
          head=dummy;
          m_size++;
      }
     
  }
 
   int size(){
          return m_size;
      }
  void pop_back(){
      if(head==nullptr||m_size<=0){
         tail =nullptr; 
          std::cout<<"list is empty unable to pop\n";
      }
      else if(m_size==1){
          delete tail;
          tail->next=nullptr;
           m_size--;
      }
      else{
          node <T>*dummy=head;int i=1;
          while(i<m_size-1){
           dummy=dummy->next;  
           i++;
          }
           dummy->next=nullptr;
           delete tail;
           tail=dummy;
           m_size--;
      }
  
  }
  void pop_front(){
       if(head==nullptr||m_size<=0){
            head=nullptr;
          std::cout<<"list is empty unable to pop\n";
      }
      else if(m_size==1){
          delete head;
          head->next=nullptr;
           m_size--;
      }
      else{
          node<T> *dummy=head;
          dummy=dummy->next;
          delete head;
          head=dummy;
           m_size--;
      }
  
  }
 void reverse() {
        tail=head;
        node <T>* prev = nullptr;
        node <T>* current = head;
        node <T>* next = nullptr;
        
        while (current != nullptr) {
            next = current->next; 
            current->next = prev; 
            prev = current;       
            current = next;
        }
        
        head = prev; 
    }
  T& at(int index){
      node<T> *dummy=head;int i=0;
      if(index>=m_size){
          std::cout<<"out of the boundary\n";
          return dummy->data;
      }
     while(i<index){
           dummy=dummy->next;  
           i++;
          } 
          return dummy->data;
  }
  T& operator[] (int index){
     node<T> *dummy=head;int i=0;
      if(index>=m_size){
          std::cout<<"out of the boundary\n";
          return dummy->data;
      }
     while(i<index){
           dummy=dummy->next;  
           i++;
          } 
          return dummy->data; 
  }
  void add_at(int pos,T value){
     node<T> *dummy=head;int i=0;
      if(pos>=m_size){
          std::cout<<"out of the boundary\n";
       return;  
      }
     while(i<pos-1){
           dummy=dummy->next;  
           i++;
          }  
          node<T> *dummynode=new node<T> (value);
         dummynode->next= dummy->next;
         dummy->next=dummynode;
         m_size++;
  
  }
  void remove_at(int pos){
     node<T> *dummy=head;int i=0;
      if(pos>=m_size){
          std::cout<<"out of the boundary\n";
       return ;  
      }
     while(i<pos-1){
           dummy=dummy->next;  
           i++;
          }  
         node<T> *newnode=dummy->next;
         dummy->next=newnode->next;
         delete newnode;
          m_size--;
  }
  
  ~list() { 
      if(m_size){
      node<T> *current = head;
      while (current != nullptr) {
          node<T> *nextNode = current->next; 
          delete current;  
          current = nextNode;  
      }
      }
  }
  void swap(T &n1,T &n2){
         T dummy_data=n1;
         n1=n2;
         n2=dummy_data;
  }
  void sort(int d=0){
      for(int i=0;i<m_size;i++){
           for(int j=0;j<m_size;j++){
        if((d)?(this->at(i)>this->at(j)):(this->at(i)<this->at(j))){
                 swap(this->at(i),this->at(j));
             }  
           }
      }
      
  }
   void print_list(){
       if constexpr (std::is_same<T, std::vector<int>>::value){
           for(int i=0;i<m_size;i++){
               for(int j=0;j<this->at(i).size();j++){
                   std::cout<<this->at(i)[j]<<",";
               }
               std::cout<<"\n";
           }
       }
       else{
      if(m_size<=0){
        std::cout<<"list is empty unable to print\n";  
      }
      else{
      node <T> *dummy=head;
      do{
         std::cout<<dummy->data<<",";
         dummy=dummy->next;
         
      }while(dummy!=nullptr);
      std::cout<<"\n";
      }
       }
  }
};
int main() {
    list<std::string> l;
    l.push_back("dfgdt");
    l.push_back("erte");
    l.push_back("ete5");
    l.push_back("te5t");
    l.add_at(2,"fdrgerge");
    l.print_list();
    l.sort();
    l.print_list();
    std::cout<<l.size()<<"\n";
    list<int> s{3,4,2,1,66,77,90,-1,56,33};
    s.swap(s[0],s[1]);
    s.sort();
    s.print_list();
    list<std::vector<int> > a;
    a.push_back({3,4,6,78,99});
    a.push_back({99,4});
    a.push_back({1,2,3,4});
    a.sort();
    a.print_list();
    return 0;
}
