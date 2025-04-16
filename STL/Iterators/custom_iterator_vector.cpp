#include<iostream>
#include<algorithm>
#include<numeric>
template<typename T>
class vector{
    T* ptr=nullptr;
    int m_size=0;
    public:
    vector()=default;
    vector(T value){
      this-> push_back(value); 
    }
    vector(int size,T value){
        for(int i=0;i<size;i++)
         this-> push_back(value); 
    }
    vector(std::initializer_list<T> a){
        auto ptr=a.begin();
       for(int i=0;i<a.size();i++)
        this-> push_back(*ptr++); 
    }
    vector(vector<T> &obj){
       for(int i=0;i<obj.size();i++){
           this->push_back(obj[i]);
       }
        
    }
   vector<T> operator=(vector<T> &obj){
       for(int i=0;i<obj.size();i++){
           this->push_back(obj[i]);
       }
     return *this;   
    }
     vector<T> operator=(vector<T> &&obj){
       ptr=obj.ptr;
       m_size=obj.size();
       obj.ptr=nullptr;
       obj.m_size=0;
       
     return *this;   
    }
    vector(vector<T> &&obj){
       ptr=obj.ptr;
       m_size=obj.size();
       obj.ptr=nullptr;
       obj.m_size=0;
    }
    void push_back(T data){
        if(ptr==nullptr){
            ptr =new T(data);
            m_size++;
        }
        else{
          T* p=new T[m_size+1];
          for(int i=0;i<m_size;i++)
            p[i]=ptr[i];
          
          if(m_size==1) 
          delete ptr;
          else
          delete [] ptr;
         
          ptr=p;
          ptr[m_size]=data;
          m_size++; 
        }
    }
    void pop_back(){
        if(ptr==nullptr){
          m_size=0;  
        }
        else{
         T* p=new T[m_size-1];
          for(int i=0;i<m_size-1;i++)
            p[i]=ptr[i];
          
          if(m_size==1){
            delete ptr;
            ptr=nullptr;
            m_size=0;
          } 
          else{
          delete [] ptr;
          ptr=p;
          m_size--; 
          }
        }   
        }
    
    int size(){
        return m_size;
    }
    void print(){
        for(int i=0;i<m_size;i++){
            std::cout<<ptr[i]<<" , ";
        }
        std::cout<<"\n";
    }
    ~vector(){
        if(ptr!=nullptr){
        if(m_size==1) 
        delete ptr;
        else
        delete [] ptr; 
        }
        ptr=nullptr;
        m_size=0;
    }
    T& at(int index){
        return ptr[index];
    }
    T& operator[](int index){
        return ptr[index];
    }
    bool empty(){
        return !m_size;
    }
    void clear(){
       if(ptr!=nullptr){
        if(m_size==1) 
        delete ptr;
        else
        delete [] ptr; 
        }
        ptr=nullptr;
        m_size=0;
    }
    void swap(vector<T> &obj){
        
        T *ptrs=obj.ptr;
        obj.ptr=ptr;
        ptr=ptrs;
        
        int d_size=obj.size();
        obj.m_size=m_size;
        m_size=d_size;
        
    }
    
    //-----------------------------------------------------------------------
    class Iterator{
      public:  
     using itertor_category =std::random_access_iterator_tag;
     using difference_type=std::ptrdiff_t;
     using value_type =T;
     using pointer_type=T *;
     using reference_type=T &;
     Iterator()=default;
     Iterator(pointer_type ptr):m_ptr(ptr){}
     
     reference_type operator *()const{
         return *m_ptr;
     } 
     pointer_type operator ->(){
         return &m_ptr->data;
     }
     Iterator & operator++(int){
        Iterator tmp=*this;
        ++(*this);
         return tmp;
     }
     Iterator & operator++(){
         m_ptr++;
         return *this;
     }
     Iterator & operator--(int){
        
        Iterator tmp=*this;
        --(*this);
         return tmp;
     }
     Iterator & operator--(){
         
        m_ptr--;
         return *this;
     }
     friend bool operator==(const Iterator&a,const Iterator&b){
         return a.m_ptr==b.m_ptr;
     }
      friend bool operator!=(const Iterator&a,const Iterator&b){
         return a.m_ptr!=b.m_ptr;
     }
     
     //random access not working 
    Iterator &operator+=(const difference_type offset){
        m_ptr+=offset;
        return *this;
    }
    Iterator &operator+(const difference_type offset){
        Iterator tmp=*this;
        return tmp+=offset;
    }
    Iterator &operator-=(const difference_type offset){
        return *this+=-offset;
    }
    Iterator &operator-(const difference_type offset){
        Iterator tmp=*this;
        return tmp-=offset;
    }
   
    difference_type operator-(const Iterator& right){
        return m_ptr-right.m_ptr;
    }
 

        friend bool operator<(const Iterator& a, const Iterator& b) {
            return a.m_ptr < b.m_ptr;
        }

        friend bool operator<=(const Iterator& a, const Iterator& b) {
            return a.m_ptr <= b.m_ptr;
        }

        friend bool operator>(const Iterator& a, const Iterator& b) {
            return a.m_ptr > b.m_ptr;
        }

        friend bool operator>=(const Iterator& a, const Iterator& b) {
            return a.m_ptr >= b.m_ptr;
        }

   
    private:
    pointer_type m_ptr; 
    };
   //----------------------------------------------------------------------------------
   
   Iterator begin(){
       return Iterator(&ptr[0]);
   }
    Iterator end(){
       return Iterator(&ptr[m_size]);
   }
   
};
int main(){
    vector<int>::Iterator obj;
    vector<int> a{1,2,3,4},b{13,45,67,88,1};
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    std::cout<<a.size()<<"\n";
    a.pop_back();
    std::cout<<a.size()<<"\n";
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.print();
    a.swap(b);
    a.print();
    b.print();
    std::cout<<a.empty();
    std::cout<<"\n";
    std::cout<<std::accumulate(a.begin(),a.end(),1,std::multiplies{});
    std::cout<<"\n";
    std::sort(a.begin(),a.end());
    
    for(auto i:a){
        std::cout<<i<<" , ";
    }
    return 0;
}
