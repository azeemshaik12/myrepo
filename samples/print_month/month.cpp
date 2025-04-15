
namespace year{
enum month{
    jan=1, feb,mar, apr, may, jun, jul, aug, sep, oct, nov,dec
};
}
std::string print_month(int &month){
 switch(month){
        case 1:return "Jan"; break;
        case 2:return "Feb"; break;
        case 3:return "Mar"; break; 
        case 4:return "Apr"; break; 
        case 5:return "May"; break;
        case 6:return "Jun"; break;
        case 7:return "Jul"; break;
        case 8:return "Aug"; break; 
        case 9:return "Sep"; break;
        case 10:return "Oct"; break; 
        case 11:return "Nov"; break; 
        case 12:return "Dec"; break; 
     }  
    return " ";
}
enum mon{
    jan=31,feb=28,mar=31, apr=30, may=31, jun=30, jul=31, aug=31, sep=30, oct=31, nov=30, dec=31
};
namespace chart{
    enum month{
      jan=0, feb=3,mar=3, apr=6, may=1, jun=4, jul=6, aug=2, sep=5, oct=0, nov=3,dec=5  
    };
}
bool is_leap(const int year){
   return  ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)? true: false;
}
int century_code(int &year){
    switch(year/100){
        case 23:return 0; break;
        case 22:return 2; break;
        case 21:return 4; break; 
        case 20:return 6; break; 
        case 19:return 0; break;
        case 18:return 2; break;
        case 17:return 4; break;
        case 16:return 6; break; 
        case 15:return 0; break;
        case 14:return 2; break;            
     }
    return 0;
}

int set_index(const int &mont,const int &year,int &monthcode){
  
    switch(mont){
            case (year::month::jan):
            monthcode=chart::month::jan;
            return jan;break;
            case (year::month::feb):
            monthcode=chart::month::feb;
            if(is_leap(year)) return 29; 
            return feb;break;
             case (year::month::mar):
            monthcode=chart::month::mar;
            return mar;break;
             case (year::month::apr):
            monthcode=chart::month::apr;
            return apr;break;
             case (year::month::may):
            monthcode=chart::month::may;
            return may;break;
             case (year::month::jun):
            monthcode=chart::month::jun;
             return jun;break;
             case (year::month::jul):
            monthcode=chart::month::jul;
            return jul;break;
             case (year::month::aug):
            monthcode=chart::month::aug;
            return aug;break;
             case (year::month::sep):
            monthcode=chart::month::sep;
            return sep;break;
             case (year::month::oct):
            monthcode=chart::month::oct;
            return oct;break;
             case (year::month::nov):
            monthcode=chart::month::nov;
            return nov;break;
             case (year::month::dec):
            monthcode=chart::month::dec;
            return dec;break;
     }
     return 0;
}
 void print_month(int mont,int year){
     std::cout<<"           "<<print_month(mont)<<"  "<<year<<"\n";
     std::cout<<"Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n"; 
     int monthcode=0;int spaces=0;
     int index=set_index(mont,year,monthcode);
     int start_day= 1+monthcode+century_code(year)+(year%100)+((year%100)/4);
     start_day=start_day%7;
     if(is_leap(year)&&(mont==1||mont==2)){start_day=start_day-1;}
     switch(start_day){
         case 1:std::cout<<"     "; spaces=1;break;
         case 2:std::cout<<"          ";spaces=2;break;
         case 3:std::cout<<"               ";spaces=3;break;
         case 4:std::cout<<"                    ";spaces=4;break;
         case 5:std::cout<<"                         ";spaces=5;break;
         case 6:std::cout<<"                              ";spaces=6;break;    
     } 
     
   for(int i=spaces;i<index+spaces;i++){
       
       if(i%7==0&&i!=0){
        std::cout<<"\n";   
       }
       if(i<9+spaces)      
           std::cout<<" "<<i-spaces+1<<"   ";
       if(i>=9+spaces)    
       std::cout<<" "<<i-spaces+1<<"  ";
      }
    std::cout<<"\n";
     if(mont<1||mont>12)std::cout<<"month is invalid\n";
     std::cout<<"------------------------------------\n"; 
 }
void print_year(int year){
std::cout<<"-------------------<( year "<<year<<" starts )>-------------------\n";
  for(int i=1;i<=12;i++){
     print_month(i,year);
   }
std::cout<<"-------------------<( year "<<year<<" ends   )>-------------------\n";
}
void print_decade(int years){
  for(int i=1;i<=10;i++){
      
     print_year(years);
     
        years++;
   }  
}