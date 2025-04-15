#include<iostream>
#include "class.h"

azeem::azeem():m_id(0),m_grade('F'),m_name(""){
    
}
azeem::azeem(int id,char grade,std::string name ):m_id(id),m_grade(grade),m_name(name){
    
}
void azeem::print(){
  std::cout<<"name : "<<m_name<<" garade : "<<m_grade<<" id :"<<m_id<<"\n";
}
void azeem::set(int id,char grade,std::string name ){
    m_grade=grade;
    m_id=id;
    m_name=name;
}
int azeem::get_id(){
  return m_id;
}
char azeem::get_grade(){
  return m_grade;
}
std::string azeem::get_name(){
  return m_name;
}
