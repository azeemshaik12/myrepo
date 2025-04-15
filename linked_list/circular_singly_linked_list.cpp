// circular singly linked list 

/* 
void fun(){
//return different types of data type from funmction according to template type
 if constexpr (std::is_integral<T>) {
        std::cout << "The value is an integer: "  << std::endl;
    }
}
*/

// for Qnx compilation use this "x86_64-pc-nto-qnx7.1.0-g++ -std=gnu++17 circular.cpp -o output"

#include<iostream>
#include<string>
#include<vector>

std::string a="out of boundary";
template<typename T>
class node{
  public:
  T data;
  node *next;
  node(T value){
      data=value;
      next=nullptr;
  }
};
template<typename T>
class cs_list{
node<T> * head,* tail;int m_size;
  public:
  cs_list(){
      head=nullptr,tail=nullptr;m_size=0;
  }
   cs_list(std::initializer_list<T> init){
      head=nullptr,tail=nullptr;m_size=0;auto ptr=init.begin();
       for(int i=0;i<init.size();i++){
           
           this->push_back(*(ptr));
           ptr++;
       }
   }
  void push_back(T value){
      if(head==nullptr){
          head=new node<T>(value);m_size++;
          head->next=head;
          tail=head;
      }
      else{
        node<T> *newnode =new node<T>(value);
        tail->next=newnode;
        newnode->next=head;
        tail=tail->next;m_size++;
      }
  }
  void push_front(T value){
      if(head==nullptr){
          head=new node<T>(value);m_size++;
          head->next=head;
          tail=head;
      }
      else{
        node<T> *newnode =new node<T>(value);
        newnode->next=head;
        head=newnode;
        tail->next=newnode;
        m_size++;
      }
  }
  void pop_back(){
      if(head==nullptr||m_size<=0){
          std::cout<<"list is empty unable to pop\n";
      }
      else{
      node<T>* dummy=head;int i=1;
      while(i<m_size-1){
          dummy=dummy->next;
          i++;
      }
      delete tail;
      tail=dummy;
      tail->next=head;
      m_size--;
    }
  }
  void pop_front(){
      if(head==nullptr||m_size<=0){
          std::cout<<"list is empty unable to pop\n";
      }
      else{
      node<T>* dummy=head;int i=1;
      head=dummy->next;
      tail->next=head;
      delete dummy;
      m_size--;
    }
  }
int size(){
    return m_size;
}

void add_at(int pos,int value){
    if(pos>m_size){
        std::cout<<"out of the boundary\n";
    }
    else if(pos==0){
       this->push_front(value); 
    }
    else if(pos==m_size){
       this->push_back(value); 
    }
    else{
        node<T> *dummy=head;int i=1;
        while(i<pos){
            dummy=dummy->next;
            i++;
        }
        node<T> *newnode=new node<T>(value);
        newnode->next=dummy->next;
        dummy->next=newnode;
        m_size++;
    }
} 
void remove_at(int pos){
  if(pos>=m_size){
        std::cout<<"out of the boundary\n";
    }
    else if(pos==0){
       this->pop_front(); 
    }
    else if(pos==m_size-1){
       this->pop_back(); 
    }
    else{
        node<T> *dummy=head;int i=0;
        while(i<pos-1){
            dummy=dummy->next;
            i++;
        }
        node<T> *newnode=dummy->next;
        dummy->next=newnode->next;
        delete newnode;
        m_size--;
    }  
}
void reverse(){
    node<T> *pre=nullptr;
    node<T> *cur=head;
    node<T> *nxt=nullptr;int i=0;
    while(i<m_size){
        nxt=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nxt;
        i++;
    }
    cur=tail;
    tail=head;
    head=cur;
}
~cs_list(){
    if(m_size){
    tail->next=nullptr;
    node<T> *dummy=head,*dum;
    while(dummy!=nullptr){
        dum=dummy->next;
       // std::cout<<"deleting "<<dummy->data<<"\n";
        delete dummy;
        dummy=dum;
    }
    }
}
T& at(int index){
    if(index>=m_size){
        std::cout<<"out of boundary\n";
        return head->data;
    }
    else{
       node<T> *dummy=head;int i=0;
       while(i<index){
         dummy=dummy->next; 
         i++;
       }
       return dummy->data;
    }
}
T&  operator[](int index){
    if(index>=m_size){
        std::cout<<"out of boundary\n";
        return head->data;
    }
    else{
       node<T> *dummy=head;int i=0;
       while(i<index){
         dummy=dummy->next; 
         i++;
       }
       return dummy->data;
    }
}
void print_list(){
      if(m_size<=0){
          std::cout<<"list is empty unable to print\n";
      }
      else{
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
         std::cout<<dummy->data<<", "; 
         dummy=dummy->next;
      }while(dummy!=tail->next);
      std::cout<<"\nsize_of_list_is:"<<m_size<<"\n";
      }
  }
}
};
int main(){
    cs_list<std::vector<std::string>> k{
       {"rgege","sjdhfsd"},{"1,2,3,4","azeem","ajsdie"},{"erwer","wrw","ajsdie"}
    };
    std::cout<<k.size()<<"\n";
    k[2].push_back("eeeee");
    k.print_list();
    //testing 
    cs_list<std::string> x; cs_list<int> l;
    x.push_back("azeem");
    x.push_back("wekdhje");
    x.push_back("wejdhwe");
    x.push_back("wlejkedhkweq");
    x[3]="Azeem";
    std::cout<<x.at(3)<<"\n";
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_front(5);
    l.push_front(4);
    l.print_list();
    l.pop_back();
    l.push_back(99);
    l.print_list();
    l.pop_front();
    l.push_front(77);
    l.print_list();
    l.remove_at(4);
    l.print_list();
    l.reverse();
    l.push_back(100);
    l.push_front(55);
    l.push_back(88);
    l.push_front(90);
    l.print_list();
    l.pop_back();
    l.pop_front();
    l.print_list();
    l.push_back(88);
    l.push_front(90);
    l.print_list();
    
   return 0;
}