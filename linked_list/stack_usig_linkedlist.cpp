#include<iostream>
#include<string>
#include<vector>
template<typename T>
class node{
    public:
    T data;
    node *prev,*next;
    node(T value){
        prev=nullptr;
        next=nullptr;
        data=value;
    }
};
template<typename T>
class stack{
    node<T> * m_top;int m_size;
    public:
     stack(){
        m_top=nullptr;m_size=0;
    }
    stack(std::initializer_list<T> init){
        m_top=nullptr;m_size=0;
        auto ptr=init.begin();
        for(int i=0;i<init.size();i++){
            this->push(*ptr);
            ptr++;
        }
    }
    bool empty(){
     return (m_top==nullptr)?true:false;   
    }
    void push(T value){
        if(m_top==nullptr){
          m_top=new node(value);
          m_size++;
        }
        else{
            node<T> *newnode=new node<T>(value);
            m_top->next=newnode;
            newnode->prev=m_top;
            m_top=newnode;
             m_size++;
        }
    }
    void emplace(T value){
        if(m_top==nullptr){
          m_top=new node<T>(value);
          m_size++;
        }
        else{
            node<T> *newnode=new node<T>(value);
            m_top->next=newnode;
            newnode->prev=m_top;
            m_top=newnode;
             m_size++;
        }
    }
    void pop(){
        if(m_top==nullptr||m_size<=0){
            m_top==nullptr;
            std::cout<<"stack is empty unable to pop\n";
        }
        else if(m_size==1){
          delete m_top;
           m_top==nullptr;
           m_size--;
        }
        else{
        node<T> *dummy=m_top;
        m_top=m_top->prev;
        m_top->next=nullptr;
        delete dummy;
        m_size--;
        }
    }
    int size(){
        return m_size;
    }
    T& top(){
        static T return_value;
        if(m_top!=nullptr)
        return m_top->data;
        else{
            std::cout<<"stack is empty\n";
            return return_value;
        }
    }
    void print(){
        if(m_top==nullptr||m_size<=0){
            std::cout<<"stack is empty unable to print\n";
        }
        else{
        node<T> * dummy=m_top;
        while(dummy!=nullptr){
            std::cout<<dummy->data<<", ";
            dummy=dummy->prev;
        }
        std::cout<<"\nsize of stack is "<<m_size<<"\n";
        }
    }
    void swap(stack &obj){
        stack<T> dummy=*this;
        *this=obj;
        obj=dummy;
    }
    ~stack(){
        if(m_size){
            node <T> *dummy=m_top,*du;
            while(dummy!=nullptr){
               du=dummy;
               dummy=dummy->prev;
              // std::cout<<"deleting   "<<du->data<<"\n";
               delete du;
            }
        }
    }
};
int main(){
  stack<std::vector<std::string>> s;
  s.pop();
  s.emplace({"dfgdrgdr"});
  s.emplace({"sfgndjrkg"});
  s.emplace({"lkfgjkrtderge"});
  s.push({"azeem"});
  s.top()={"azeem shaik","dsfwefw shaik"};
  std::cout<<s.top().size()<<"\n"<<s.size()<<"\n";
}