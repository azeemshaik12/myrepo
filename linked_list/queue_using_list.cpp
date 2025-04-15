#include<iostream>
#include <vector>
#include <string>
template<typename T>
class node{
    public:
    node *prev,*next;
    T data;
    node(T value){
        prev=nullptr;
        next=nullptr;
        data=value;
    }
};
template<typename T>
class queue{
    node<T> *m_front,*m_back;
    int m_size;
    public:
    queue(){
        m_front=nullptr;
        m_back=nullptr;
        m_size=0;
    }
    queue(std::initializer_list<T> init){
        m_front=nullptr;
        m_back=nullptr;
        m_size=0;auto ptr=init.begin();
        for(int i=0;i<init.size();i++){
            this->push(*ptr);
            ptr++;
        }
    }
    bool empty(){
        return (m_front==nullptr)?true:false;
    }
    int size(){
        return m_size;
    }
    void push(T value){
        if(m_front==nullptr){
            m_front=new node<T>(value);
            m_size++;
            m_back=m_front;
        }
        else{
            node<T> *newnode=new node<T>(value);
            m_back->next=newnode;
            newnode->prev=m_back;
            m_back=newnode;
            m_size++;
        }
    }
    void emplace(T value){
        if(m_front==nullptr){
            m_front=new node<T>(value);
            m_size++;
            m_back=m_front;
        }
        else{
            node<T> *newnode=new node<T>(value);
            m_back->next=newnode;
            newnode->prev=m_back;
            m_back=newnode;
            m_size++;
        }
    }
    void pop(){
        if(m_front==nullptr&&m_size<=0){
            std::cout<<"queue is empty unable to pop\n";
            m_front==nullptr;
        }
        else if(m_size==1){
         delete m_front;
         m_front->next=nullptr;
         m_size--;
        }
        else{
          node<T> *dummy=m_front; 
          m_front=dummy->next;
          m_front->prev=nullptr;
          delete dummy;
          m_size--;
        }
    }
    void print(){
        if(m_size<=0){
          std::cout<<"queue is empty unable to print\n";
        }
        else{
        node<T> *dummy=m_front;
        while(dummy!=nullptr){
            std::cout<<dummy->data<<", ";
            dummy=dummy->next;
        }
        std::cout<<"\nsize of the queue "<<m_size<<"\n";
    }
    }
    T& front(){
      static T return_value;
      if(m_front==nullptr||m_size<=0){
           std::cout<<"queue is empty\n";
           return return_value;
      }
      else{
          return m_front->data;
      }
    }
    T& back(){
      static T return_value;
      if(m_front==nullptr||m_size<=0){
           std::cout<<"queue is empty\n";
           return return_value;
      }
      else{
          return m_back->data;
      }
    }
    void swap(queue<T> &obj){
        queue<T> dummy=obj;
        obj=*this;
        *this=dummy;
        
    }
    ~queue(){
        node<T> *dummy=m_front,*du;
         while(dummy!=nullptr) { 
             du=dummy;
             dummy=dummy->next;
             delete du;
        }
    }
};
int main(){
  queue<int> a{1,2,3,4};
  a.print();
  queue<std::vector<std::string>> s;
  s.pop();
  s.emplace({"dfgdrgdr"});
  s.emplace({"sfgndjrkg"});
  s.emplace({"lkfgjkrtderge"});
  s.push({"azeem"});
  s.front()={"azeem shaik","dsfwefw shaik"};
  std::cout<<s.front().size()<<"\n"<<s.size()<<"\n";

    return 0;
}