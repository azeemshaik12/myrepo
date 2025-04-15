#ifndef SINGLETON_H  //header gaurd
#define SINGLETON_H
/*
1.make constructor private to privent object creation
2.create a static pointer of the class and static function which returns the pointer of same class 
3.delete copy constructor and copy assignment opertators, move and move assignment constructors(optional)
4.create a static mutex variable to lock the object 
5.use shared_ptr for first object pointer if possible otherwise delete the object at end to prevent memory leaks.

*/
#include<iostream>
#include<mutex>
class singleton{
int m_var;
static singleton *ptr;
static std::mutex m;
singleton();
public:
  singleton(singleton& obj)=delete; // delete copy constructor
  singleton& operator=(singleton& obj)=delete; 
  singleton(singleton&& obj)=delete; //
  singleton& operator=(singleton&& obj)=delete; //
  static singleton * getobject();
  void set_var(int x);
  int get_var();
  ~singleton();
};

#endif
