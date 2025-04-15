#include"azeemstring.h"
String::String(){
     len =0;c=new char[1];  
   } //default constructor
String::String(const char *ptr){
       int i=0;const char *q=ptr;
      while(*ptr!='\0'){
        i++;ptr++;
      } 
      len =i;c=new char[len];
      for(i=0;i<len;i++){
          c[i]=q[i];
      }
   } //parametreized constructor

String::String(String &obj){
       c=new char[obj.len];
       int i=0;
       for(i=0;i<obj.size();i++){
          c[i]=obj.c[i];
      }
      len=len+i;
   } //copy constructor
String::String(int num,char ch){
      c=new char[num];
      for(int i=0;i<num;i++){
          c[i]=ch;
      }
      len=num;
   }//parameterized constructor with single letter pushing n times
String::~String(){
     delete [] c;  
   }//destructor
String String::operator=(const char *ptr){
     int i=0;const char *q=ptr;
      while(*ptr!='\0'){
        i++;ptr++;
      } 
      int size=i;
       for(i=0;i<size;i++){
          c[len+i]=q[i];
      }
      len=len+i;
      return String(ptr);
  } //= operator for csting assignment
 void String::operator=(String &obj){
    for(int i=0;i<obj.size();i++){
          c[i]=obj.c[i];
      }
   len=obj.len; 
  }//= operatior for String object assignment

void String::append(const char *ptr){
      int i=0;const char *q=ptr;
      while(*ptr!='\0'){
        i++;ptr++;
      } 
      int size=i;
       for(i=0;i<size;i++){
          c[len+i]=q[i];
      }
      len=len+i;
   } //appending c string without size

void String::append(String &obj){
       int i=0;
       for(i=0;i<obj.size();i++){
          c[len+i]=obj.c[i];
      }
      len=len+i;
   }//appending String object without size
void String::append(const char *ptr,int end){
       for(int i=0;i<end;i++){
          c[len+i]=ptr[i];
      }
      len=len+end;
   }//appending c string with fixed size

void String::append(const String &obj,int end){
       for(int i=0;i<end;i++){
          c[len+i]=obj.c[i];
      }
      len=len+end;
   }//appending String object with fixed size
void String::append(const char *ptr,int start,int end){
       int j=0;
       for(int i=start;i<=end;i++){
          c[len+j]=ptr[i];
          j++;
      }
      len=len+end-start+1;
   }//appending cstring within limits

 void String::append(const String &obj,int start,int end){
       int j=0;
       for(int i=start;i<=end;i++){
          c[len+j]=obj.c[i];
          j++;
      }
      len=len+end-start+1;
   }//appending stringobject within limits
int String::length()const{
       return len;
   }//length fun
int String::size()const{
       return len;
   }//size fun
void String::push_back(char ch){
       c[len]=ch;
       len++;
   }//pushback fun
void String::pop_back(){
       c[len-1]='\0';
       len--;
   }//pop back fun
char String::at(int index)const{
       return c[index];
   }//at function to return index
void String::erase(int start){
       for(int i=start;i<len;i++){
           c[i]='\0';
       }
    len=0;
   }//erasing all elements
void String::erase(int start,int count){
       for(int i=start;i<len;i++){
           c[i]=c[i+count];
       }
    if(count>=len||(start-(len-count))>=0)
    len=start;
    else{
       len=start+len-(count+start);
        }
   }//erase desired amount of elements
void String::clear(){
   for(int i=0;i<len;i++){
           c[i]='\0';
       }
    len=0;
}//return back element
char& String::back()const{
    return c[len-1];
}
char& String::front()const{
    return c[0];
}//returns front element
String String::reverse(){
    char temp;
    for(int i=0;i<len/2;i++){
         temp=c[i];
         c[i]=c[len-i-1];
         c[len-i-1]=temp;
        
    }
   
    return *this;
}//reverse function
char String::operator [](int index)const{
      return c[index]; 
   }//[] index operator 
String String::operator+( String &obj){
     char *ch=new char[len+obj.len];
     for(int i=0;i<len;i++){
         ch[i]=c[i];
     }
     for(int i=0;i<obj.len;i++){
         ch[len+i]=obj.c[i];
     }
     
     return String(ch);
  }//+ concatination operator
void swap(String &obj1,String &obj2){
       char *ptr=obj1.c;
       obj1.c=obj2.c;
       obj2.c=ptr;
       int size=obj1.len;
       obj1.len=obj2.len;
       obj2.len=size;
   }//swap fun  friend function
std::ostream& operator<<(std::ostream &os, String &obj){
       os<<obj.c;
       return os;
   }//cout function overloading  friend function

std::istream& operator>>(std::istream &is, String &obj){
     is>>obj.c;
   obj.len= obj.find_size();
    return is;
    };
std::istream& getline (std::istream& is, String& obj){
      is>>obj.c; 
    obj.len= obj.find_size();
      return is;   
  }
std::istream& getline (std::istream& is, String& obj,char ch){
      is>>obj.c;
    int i=0,index=0;
    for(i=0;i<obj.find_size();i++){
       if(obj.c[i]==ch) 
       { index=i;
           }
    }
    
     if(index!=0) obj.c[index]='\0';
    obj.len= obj.find_size();
      return is;   
  }

int String::strcmp(const String&obj){
    if(len!=obj.len) return 0;
    for(int i=0;i<len;i++){
        if(c[i]!=obj.c[i])
            return 0;
     }
    return 1;
}

int String::find_size(){
    int i=0;
    while(c[i]!='\0'){
        i++;
   }
    return i;
}
String String::assign(const String &obj){
   if(strcmp(obj))return *this;
    else this->clear();
   for(int i=0;i<obj.size();i++){
          c[i]=obj.c[i];
      }
   len=find_size(); 
  return *this;  
}//assign the object of same class 
String  String::assign(const String& obj,int start,int end){
    if(end==0)end=obj.len;
     if(strcmp(obj)){     
      for(int i=0;i<end;i++){
          c[i]=c[i+start];
        }
         if(end<len){
           for(int i=end;i<len;i++){
          c[i]='\0';
          }  
         }
         len=find_size(); 
         }
    else{
    this->clear();
    for(int i=0;i<end;i++){
          c[i]=obj.c[i+start];
      }
       len=find_size(); 
    }
   return *this;  
}//assign the object of the same sting with limts
String String::assign(int num,char ch){
  this->clear();
    len=num;
  for(int i=0;i<num;i++){
      c[i]=ch;
  }
     return *this;  
}//assign the given char num times
String String::insert(int index,String &obj,int end){
    if(strcmp(obj)) return " ";
    int size=len+obj.len-end;
    String dummy(size,'c');int i=0;
     for( i=0;i<index;i++){
         dummy.c[i]=c[i];
      } 
      for(i=0;i<obj.len-end;i++){
        dummy.c[i+index]=obj.c[end+i];
      }
      for(int i=0;i<len-index;i++){ //to be the tgdthtdhb question
          dummy.c[index+obj.len+i-end]=c[index+i];
      } 
    return dummy;
}
String String::insert(int index,const char *ch,int end){
     int i=0;
    if(end==0)
    for(i=0;ch[i]!='\0';i++);
    else i=end;
    int size=i+len;
    String dummy(size,'c');
     for( i=0;i<index;i++){
         dummy.c[i]=c[i];
      } 
      for(i=0;i<size-len;i++){
        dummy.c[i+index]=ch[i];
      }
      for(int i=0;i<len-index;i++){ 
          dummy.c[index+size-len+i]=c[index+i];
      } 
    return dummy;
}
String String::insert(int index,const char* ch,int start,int end){
   int size=len+end,i=0; String dummy(size,'c');
   for( i=0;i<index;i++){
         dummy.c[i]=c[i];
      }
  for(i=0;i<end;i++){
        dummy.c[i+index]=ch[start+i];
      }
  for(int i=0;i<len-index;i++){ 
          dummy.c[end+index+i]=c[index+i];
      }
    return dummy;
}
int String::copy(char *ptr,int count,int index){
    if(index>len){
      
        std::cout<<"std::out_of_range\n";
        return 0;}
    for(int i=0;i<count;i++){
        ptr[i]=c[index+i];
    }
      
    return len-index;
}
     