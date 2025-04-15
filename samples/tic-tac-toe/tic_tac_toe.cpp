#include <iostream>
#include <unistd.h>
char ptr[9]={'1','2','3','4','5','6','7','8','9'};
char p1='O',p2='X';
int color[4]={96,93,97,91};

void SetColor(int textColor)
{
    std::cout << "\033[" << textColor << "m";
}
char value(int pos){
  if(ptr[pos]==p1)
  {
      SetColor(color[0]);
  }
  else if(ptr[pos]==p2){
     SetColor(color[1]); 
  }
  else{
    SetColor(color[2]);   
  }
   return ptr[pos]; 
}
std::string fun(int x=0){
    if(!x){
    SetColor(color[2]);
    return " | ";
    }
    else if(x==1){
    SetColor(color[2]);
     return "---|---|---\n";  
    }
    return " ";
    
}
void draw(){
    SetColor(color[2]);
    std::cout << " " << value(0) << fun() << value(1) << fun()<< value(2) << "\n";
    std::cout <<fun(1);
    std::cout << " " << value(3) << fun() << value(4) << fun() << value(5) << "\n";
    std::cout <<fun(1);
    std::cout << " " << value(6) << fun() << value(7) << fun() << value(8) << "\n";
}

void player1(){
    int pos;
    std::cout<<"player 1( symbol = "<<p1<< " )enter position from 1 to 9\n";
    std::cin>>pos;
    if(pos>9){
      std::cout<<"out of boundary \n";
        player1();  
    }
    else{
    if(ptr[pos-1]!=p1&&ptr[pos-1]!=p2){
       ptr[pos-1]=p1; 
    }else{
        std::cout<<"already filled try again\n";
        player1();
    }
    }
}
void player2(){
    int pos;
   std::cout<<"player 2( symbol = "<<p2<< " )enter position from 1 to 9\n";
    std::cin>>pos;
    if(pos>9){
      std::cout<<"out of boundary \n";
        player2();  
    }
    else{
    if(ptr[pos-1]!=p1&&ptr[pos-1]!=p2){
       ptr[pos-1]=p2; 
    }else{
        std::cout<<"already filled try again\n";
        player2();
    }
    }
}
void play(){
    static int i=0;
    if(i%2==0){
        i++;
    SetColor(color[0]);
      player1();  
    }
    else{
        i++;
        SetColor(color[1]);
        player2();  
    }
}
int main() {
     draw();
     bool condition;
     int i=0;
     while(i<9){
     play();
     sleep(1);
     system("clear");
     draw();
     condition=((ptr[0]==ptr[1])&&(ptr[1]==ptr[2])) ||
                ((ptr[3]==ptr[4])&&(ptr[4]==ptr[5]))||
                ((ptr[6]==ptr[7])&&(ptr[7]==ptr[8]))||
                ((ptr[0]==ptr[4])&&(ptr[4]==ptr[8]))||
                ((ptr[2]==ptr[4])&&(ptr[4]==ptr[6]))||
                ((ptr[0]==ptr[3])&&(ptr[3]==ptr[6]))||
                ((ptr[1]==ptr[4])&&(ptr[4]==ptr[7]))||
                ((ptr[2]==ptr[5])&&(ptr[5]==ptr[8]));
     if(condition){
      if(i%2==0){
      
          SetColor(color[0]);
          std::cout<<"\n---------player1 is winner----------\n";
      }
      if(i%2!=0){
          SetColor(color[1]);
          std::cout<<"\n---------player2 is winner----------\n";
      }
     break;
     }
     i++;
     }
     if(!condition){
     SetColor(color[3]);
     std::cout<<"---------Draw match----------\n";
     }
    return 0;
}
