#include "assert.h"
#include <iostream>
bool is_leapyear(int year){
     return (year<0)?false:((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))?true:false);
}
int sq(int val){
    return val*val;
}
std::string reverse(std::string a){
    int siz=a.size();char dummy;
    for(int i=0;i<=siz/2;i++){
       dummy=a[i];
       a[i]=a[siz-i-1];
       a[siz-i-1]=dummy;
    }
    return a;
}
double add(double x,double y){
    return x+y;
}
float add(float x,float y){
    return x+y;
}
