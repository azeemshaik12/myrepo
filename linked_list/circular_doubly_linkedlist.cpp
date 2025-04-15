// circular doubly linkedlist
#include<iostream>
#include<vector>
#include<string>
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
      if(head==nullptr||m_size<=0){
          std::cout<<"list is empty unable to pop\n";
      }
      else{
     node<T> *dummy=head;
     head=head->next;
     head->prev=tail;
     tail->next=head;
     delete dummy;
     m_size--;
      }
 }
  void pop_back(){
       if(head==nullptr||m_size<=0){
          std::cout<<"list is empty unable to pop\n";
      }
      else{
     node<T> *dummy=tail;
     tail=tail->prev;
     tail->next=head;
     head->prev=tail;
     delete dummy;
     m_size--; 
     }
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
    if(m_size){
    tail->next=nullptr;head->prev=nullptr;
    node<T> *dummy=head;
    while(dummy!=nullptr){
      node<T> *dummy2=dummy->next;
     // std::cout<<"deleting "<<dummy->data<<"\n";
      delete dummy;
      dummy=dummy2;
    }
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
         std::cout<<dummy->data<<",";
         dummy=dummy->next;

      }while(dummy!=head);
      std::cout<<"\nsize_of_list_is:"<<this->size()<<"\n";
      }
    }
  }
    
};
int main(){
    cd_list<std::vector<std::string>> k{
       {"rgege","sjdhfsd"},{"1,2,3,4","azeem","ajsdie"},{"erwer","wrw","ajsdie"}
    };
    std::cout<<k.size()<<"\n";
    k[2].push_back("eeeee");
    k.print_list();
    cd_list<int> l{20,30,40};
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_front(400);
    l.push_front(566);
    l.pop_front();
    l.pop_back();
    l.print_list();
    l.add_at_front(7,111);
    l.remove_at_back(1);
    l.print_list();
    l.reverse();
    l.print_list();
    l.getfront_index(12);
    l.getback_index(12);
    std::cout<<l[2];
    return 0;
}