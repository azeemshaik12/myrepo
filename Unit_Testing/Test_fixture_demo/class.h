#ifndef CLASS_H
#define CLASS_H
#include <string>
class azeem{
int m_id;char m_grade; std::string m_name;
public:
azeem();
azeem(int id,char grade,std::string name);
void print();
void set(int id,char grade,std::string name);
int get_id();
char get_grade();
std::string get_name();
};
#endif
