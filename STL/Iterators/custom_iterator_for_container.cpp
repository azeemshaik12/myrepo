// double linked list
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

template <typename T>
class node{
  public:
  T data;
  node *next;
  node *prev;
  node(T value){
      data=value;
      next=nullptr;
      prev=nullptr;
  }
};
template <typename T>
class d_list{
    node<T> *head,*tail;
    int m_size;
    public:
    
    d_list(){
      head=nullptr,tail=nullptr;
      m_size=0;
    }
d_list(std::initializer_list<T> init){
      head=nullptr,tail=nullptr;
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
      node<T> * dummy=new node<T>(value);
       tail->next=dummy;
      dummy->prev=tail;
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
      node<T> * dummy=new node<T>(value);
      head->prev=dummy;
      dummy->next=head;
      head=dummy;
       m_size++;
  }
}
void print_list(){
     if(m_size<=0){
          std::cout<<"list is empty unable to print\n";
      }
      else{
      node<T> *dummy=head;
      do{
         std::cout<<dummy->data<<",";
         dummy=dummy->next;

      }while(dummy!=nullptr);
      std::cout<<"\n";
      }
  }
void rprint_list(){
    if(m_size<=0){
          std::cout<<"list is empty unable to print\n";
      }
      else{
      node<T> *dummy=tail;
      do{
         std::cout<<dummy->data<<",";
         dummy=dummy->prev;

      }while(dummy!=nullptr);
      std::cout<<"\n";
      }
  }
int size(){
    return m_size;
}
void pop_back(){
   if(head==nullptr||m_size<=0){
          std::cout<<"list is empty unable to pop\n";
      }
      else if(m_size==1){
        delete tail;
        tail->next=nullptr;
        tail->prev=nullptr;
        m_size--;
      }
   else{
    node<T>* dummy;
    dummy=tail;
    tail=tail->prev;
    tail->next=nullptr;
    delete dummy;
    m_size--;
    }
}
void pop_front(){
   if(head==nullptr||m_size<=0){
          std::cout<<"list is empty unable to pop\n";
      }
      else if(m_size==1){
        delete head;
        head->next=nullptr;
        head->prev=nullptr;
        m_size--;
      }
    else{
    node<T> * dummy;
    dummy=head;
    head=head->next;
    head->prev=nullptr;
    delete dummy;
    m_size--;
    }
}
int at(int index){
    if(index>=m_size){
          std::cout<<"out of the boundary\n";
          return -1;
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
int rat(int index){
    if(index>=m_size){
          std::cout<<"out of the boundary\n";
          return -1;
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
int operator[](int index){
  if(index>=m_size){
          std::cout<<"out of the boundary\n";
          return -1;
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
void reverse(){
    node<T> * dtail=tail,*dummy,*dummy2=head;int i=0;
    while(i<m_size-1){
        dummy=dtail->prev;
        dtail->prev=dtail->next;
        dtail->next=dummy;
        dtail=dummy;
        i++;
   }
    head=tail;
    tail=dummy2;
    head->prev=nullptr;
    tail->next=nullptr;

}
void add_at_front(int pos,T value){
    if(pos>m_size||pos<0){
        std::cout<<"out of boundary\n";
        return;
    }
    else if(pos==0){
        this->push_front(value);
    }
    else if(pos==m_size){
       this->push_back(value);
    }
    else{
     node<T> *dummy=head;int i=0;
     while(i<pos-1){
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
    void add_at_back(int pos,T value){
    if(pos>m_size||pos<0){
        std::cout<<"out of boundary\n";
        return;
    }
    else if(pos==0){
        this->push_back(value);
    }
     else if(pos==m_size){
      this->push_front(value);
    }
    else{
     node<T> *dummy=tail;int i=0;
     while(i<pos){
         dummy=dummy->prev;
         i++;
     }
     node<T> * newnode=new node<T>(value);
     newnode->next=dummy->next;
     newnode->prev=dummy;
     (dummy->next)->prev=newnode;
     dummy->next=newnode;
      m_size++;
    }
}
void remove_at_front(int pos){
  if(pos>=m_size||pos<0){
        std::cout<<"out of boundary\n";
        return;
    }
    else if(pos==0){
        this->pop_front();
    }
    else{
     node<T> *dummy=head;int i=0;
     while(i<pos){
         dummy=dummy->next;
         i++;
     }
     (dummy->next)->prev=dummy->prev;
     (dummy->prev)->next=dummy->next;
     delete dummy;
     m_size--;
    }
}
void remove_at_back(int pos){
  if(pos>=m_size||pos<0){
        std::cout<<"out of boundary\n";
        return;
    }
    else if(pos==0){
        this->pop_back();
    }
    else{
     node<T> *dummy=tail;int i=0;
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
~d_list(){
    if(m_size){
    node<T> *dummy=head;
    while(dummy!=nullptr){
      node<T> *dummy2=dummy->next;
      //std::cout<<"deleting "<<dummy->data<<"\n";
      delete dummy;
      dummy=dummy2;
    }
}
}
 class Iterator{
     public:
     using itertor_category =std::input_iterator_tag;
     using difference_type=std::ptrdiff_t;
     using value_type =node<T>;
     using pointer_type=node<T>  *;
     using reference_type=T &;
     Iterator()=default;
     Iterator(pointer_type ptr):m_ptr(ptr){}
     reference_type operator *()const{
         return (m_ptr->data);
     } 
     pointer_type operator ->(){
         return m_ptr;
     }
     Iterator & operator++(int){
        Iterator tmp=*this;
        ++(*this);
         return tmp;
     }
     Iterator & operator++(){
         m_ptr=m_ptr->next;
         return *this;
     }
     friend bool operator==(const Iterator&a,const Iterator&b){
         return a.m_ptr==b.m_ptr;
     }
      friend bool operator!=(const Iterator&a,const Iterator&b){
         return a.m_ptr!=b.m_ptr;
     }
     private:
     pointer_type m_ptr;
    };
    
    Iterator begin(){
        return Iterator(head);
    }
    Iterator end(){
        return Iterator(tail->next);
    }
};
int main(){
    d_list<int> l,j{1,2,3,4,5,6,7}; 
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_front(7);
    l.print_list();
    l.add_at_front(7,100);
    l.remove_at_back(0);
    l.reverse();
    l.print_list();
    
    for(auto i:l){
        std::cout<<i<<",";
    } //ranged for loop  working
     std::cout<<"\n";
     std::for_each(l.begin(),l.end(),[](auto a){std::cout<<a<<",";});
     std::cout<<"\n";
     std::ranges::for_each(l,[](auto a){std::cout<<a<<",";});
     std::cout<<"\nprint j before copy ";
     std::for_each(j.begin(),j.end(),[](auto a){std::cout<<a<<",";});
     std::copy(l.begin(),l.end(),j.begin());
     //for each working 
    std::cout<<"\nprint j after copy ";
    std::for_each(j.begin(),j.end(),[](auto a){std::cout<<a<<",";});
    std::cout<<"\n";
    std::cout<< std::accumulate(j.begin(),j.end(),0); // accumulate working
     //std::sort(j.begin(),j.end());
     
     
     
    return 0;
}


