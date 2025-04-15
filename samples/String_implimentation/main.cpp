#include<iostream>
#include"azeemstring.h"

String to_String(int num){
   String p;
    int i=0;
    while(num!=0){
        p.c[i]=(num%10)+48;
        num=num/10;
        i++;
    }
    p.len=i;
    p.reverse();
    
  return p;  
}// to_string friend function
int Atoi(String obj){
    int result=0;
    for(int i=0;i<obj.len;i++){
        if(obj.c[i]>='0'&&obj.c[i]>'9') return result;
       result =(obj.c[i]-'0')+result*10;
        
    }
return result;
}// atoi friend function
int main() {
  // String str="to be question";//to be the tgdthtdhb
  // String str2="the tgdthtdhb ";
  // String str3=str.insert(6,"the tgdthtdhb ",2,7); 
  //   std::cout<<str3;
    String name;
    getline (std::cin,name,'c');
  std::cout << name<<" \n";
    return 0;
    
}

