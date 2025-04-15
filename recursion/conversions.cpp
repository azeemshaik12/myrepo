#include <iostream>
#include <string>
#include <cmath>

//--------------------------------------------------------------
std::string hexconvert(int num){
 switch(num){
      case 10:
      return "A";break;
      case 11:
      return "B";break;
      case 12:
      return "C";break;
      case 13:
      return "D";break;
      case 14:
      return "E";break;
      case 15:
      return "F";break;
   } 
   return std::to_string(num);
}

char oct(std::string num){
  std::string a=std::string(num.end()-3,num.end());
  if(a=="000")
      return '0';
  else if(a=="001")
  return '1';
  else if(a=="010")
  return '2';
   else if(a=="011")
  return '3';
   else if(a=="100")
  return '4';
   else if(a=="101")
  return '5';
  else if(a=="110")
  return '6';
  else
  return '7';
}

char hex(std::string num){
  std::string a=std::string(num.end()-4,num.end());
  if(a=="0000")
      return '0';
  else if(a=="0001")
  return '1';
  else if(a=="0010")
  return '2';
   else if(a=="0011")
  return '3';
   else if(a=="0100")
  return '4';
   else if(a=="0101")
  return '5';
  else if(a=="0110")
  return '6';
  else if(a=="0111")
  return '7';
  else if(a=="1000")
  return '8';
  else if(a=="1001")
  return '9';
  else if(a=="1010")
  return 'A';
  else if(a=="1011")
  return 'B';
  else if(a=="1100")
  return 'C';
  else if(a=="1101")
  return 'D';
  else if(a=="1110")
  return 'E';
  else 
  return 'F';
} 

std::string ocb(char c){
   switch(c){
       case '0':
       return "000";
       break;
       case '1':
       return "001";
       break;
       case '2':
       return "010";
       break;
       case '3':
       return "011";
       break;
       case '4':
       return "100";
       break;
       case '5':
       return "101";
       break;
       case '6':
       return "110";
       break;
       case '7':
       return "111";
       break;
   } 
   return "";
}

std::string hex_b(char p){
    switch(p){
        case '0':
        return "0000";
        case '1':
        return "0001";
        case '2':
        return "0010";
        case '3':
        return "0011";
        case '4':
        return "0100";
        case '5':
        return "0101";
        case '6':
        return "0110";
        case '7':
        return "0111";
        case '8':
        return "1000";
        case '9':
        return "1001";
        case 'A':
        return "1010";
        case 'B':
        return "1011";
        case 'C':
        return "1100";
        case 'D':
        return "1101";
        case 'E':
        return "1110";
        case 'F':
        return "1111";
    }
    return "";
}
//------------------------------------------------------------------
bool is_binary(std::string a){
    for(int i=0;i<a.size();i++){
        if(a[i]!='0'&&a[i]!='1'){
            return false;
        }
    }
    return true;
}

bool is_octal(std::string a){
    for(auto i:a){
    if(i>='0'&&i<='7'){
        
    }
    else
    return false;
    
    }
    return true;
}

bool is_hex(std::string a){
    for(auto i:a){
    if((i>='0'&&i<='9')||(i>='A'&&i<='F')){
        
    }
    else
    return false;
    
    }
    return true;
}

//-----------------------------------------------------------------
//----------------------decimal------------------------------- 
int decimal_to_binary(int num,std::string result=""){//1
   if(num==0){
       return atoi(result.c_str());
   }
   result=std::to_string(num%2)+result;
   return  decimal_to_binary(num/2,result);  
}

int decimal_to_octal(int num,std::string result=""){//2
   if(num<8){
       result=std::to_string(num)+result;
       return atoi(result.c_str());
   }
   result=std::to_string(num%8)+result;
   return  decimal_to_octal(num/8,result);  
}


std::string decimal_to_hex(int num,std::string result=""){//3
   if(num<16){
       result=hexconvert(num)+result;
       return result;
   }
   result=hexconvert(num%16)+result;
   return  decimal_to_hex(num/16,result);  
}


//-------------------------------binary------------------------------- 

int binary_to_decimal(std::string num,int result=0){ //4
   if(!is_binary(num)){
       std::cout<<"is not a valid binary number\n";
       return 0;
   }
   if(num==""){
       return result;
   }
   if(num[0]!='0')
   result=pow(2,num.size()-1)+result;
return binary_to_decimal(&num[1],result);    
}


std::string binary_to_octal(std::string num,std::string result=""){ //5
  if(!is_binary(num)){
       std::cout<<"is not a valid binary number\n";
       return "";
   }
  if(num==""){
      return result;
  }
   if(num.size()==6||num.size()==1)num="00"+num;
   if(num.size()==5||num.size()==2)num="0"+num;
   result=oct(num)+result;
return binary_to_octal(std::string(num.begin(),num.end()-3),result);    
}


std::string binary_to_hex(std::string num,std::string result=""){ //6
 if(!is_binary(num)){
       std::cout<<"is not a valid binary number\n";
       return "";
   }
if(num==""){
      return result;
  }
   if(num.size()==5||num.size()==1)num="000"+num;
   if(num.size()==6||num.size()==2)num="00"+num;
   if(num.size()==7||num.size()==3)num="0"+num;
   result=hex(num)+result;
return binary_to_hex(std::string(num.begin(),num.end()-4),result);  
}


//------------------------------octal--------------------------- 

int octal_to_decimal(std::string num,int result=0){ //7
   if(!is_octal(num)){
       std::cout<<"is not a valid octal number\n";
       return 0;
   }
   if(num==""){
       return result;
   }
   if(num[0]!='0')
   result=(num[0]-48)*pow(8,num.size()-1)+result;
   
return octal_to_decimal(&num[1],result);    
}


std::string octal_to_binary(std::string num,std::string result =""){ //8
    if(!is_octal(num)){
       std::cout<<"is not a valid octal number\n";
       return 0;
   }
    if(num==""){
        return result;
    }
    result=result+ocb(num[0]);
    return octal_to_binary(&num[1],result);
}

std::string octal_to_hex(std::string num,std::string result=""){ //9
   if(!is_octal(num)){
       std::cout<<"is not a valid octal number\n";
       return "";
   }
   result=octal_to_binary(num);
   result=binary_to_hex(result); 
   return result;
}

//------------------------------hexadecimal----------------------------
int hex_to_decimal(std::string num,int result=0){  //10
if(!is_hex(num)){
    std::cout<<"is not a valid hex number\n";
    return 0;
}
 if(num==""){
       return result;
   }
  result+=((num[0]>='A'&&num[0]<='F')?((num[0]-'A')+10):(num[0]-'0'))*pow(16,num.size()-1);
return hex_to_decimal(&num[1],result);      
}

std::string hex_to_binary(std::string num,std::string result=""){ //11
   if(!is_hex(num)){
    std::cout<<"is not a valid hex number\n";
    return "";
    } 
    if(num==""){
        return result;
    }
    result+=hex_b(num[0]);
  return hex_to_binary(&num[1],result);  
}

std::string hex_to_octal(std::string num,std::string result=""){ //12
    if(!is_hex(num)){
    std::cout<<"is not a valid hex number\n";
    return "";
    }
    result=hex_to_binary(num);
    result=binary_to_octal(result);
    return result;
}
//------------------------------------------------------------------
/*
1.int decimal_to_binary(int num,std::string result="")
2.int decimal_to_octal(int num,std::string result="")
3.std::string decimal_to_hex(int num,std::string result="")
4.int binary_to_decimal(std::string num,int result=0)
5.std::string binary_to_octal(std::string num,std::string result="")
6.std::string binary_to_hex(std::string num,std::string result="")
7.int octal_to_decimal(std::string num,int result=0)
8.std::string octal_to_binary(std::string num,std::string result ="")
9.std::string octal_to_hex(std::string num,std::string result="")
10.int hex_to_decimal(std::string num,int result=0)
11.std::string hex_to_binary(std::string num,std::string result="")
12.std::string hex_to_octal(std::string num,std::string result="")
*/
int main() {
    std::cout<<decimal_to_binary(101)<<"\n";
    std::cout<<decimal_to_octal(101)<<"\n";
    std::cout<<decimal_to_hex(101)<<"\n";
    std::cout<<binary_to_decimal("101")<<"\n";
    std::cout<<binary_to_octal("101")<<"\n";
    std::cout<<binary_to_hex("101")<<"\n";
    std::cout<<octal_to_decimal("101")<<"\n";
    std::cout<<octal_to_binary("101")<<"\n";
    std::cout<<octal_to_hex("101")<<"\n";
    std::cout<<hex_to_decimal("101")<<"\n";
    std::cout<<hex_to_binary("101")<<"\n";
    std::cout<<hex_to_octal("101")<<"\n";
    return 0;
}
