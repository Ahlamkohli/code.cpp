#include <iostream>

using namespace std;
void permuter1(int *a,int *b){//passage par adress
      int c=*a;
      *a=*b;
      *b=c;
     }

void permuter2(int &a,int &b){//passage par reference
   int c=a;
   a=b;
   b=c;
}
int main()
{    int x=9,y=8;
     cout<<"x= " << x <<"--y= "<<y<<endl;
     //permuter1(&x,&y);
     permuter2(x,y);
     cout<<"x= " << x <<"--y= "<<y<<endl;
     //reference: 2eme nom
     int i=5;
     int &val=i;
     cout<<"i= " << i <<"--val= "<<val<<endl;
     i=48;
     cout<<"i= " << i <<"--val= "<<val<<endl;
     val=66;
     cout<<"i= " << i <<"--val= "<<val<<endl;
     //allocation dynamique : espace libre
     int *p=new int;
     *p=10;
     cout<<"p="<< *p << endl;
     delete p;p=NULL;
     return 0;
}
