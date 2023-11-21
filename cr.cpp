#include <iostream>
#include<cstdlib>
using namespace std;
struct temp {
int data;
temp *next;
};

void afichage(temp *n);
int main()
{
   //way1
   /*temp *tete= (temp*)malloc(sizeof(temp));
    temp *second=(temp*)malloc(sizeof(temp));
    temp *third = (temp*)malloc(sizeof(temp));

    tete->data=1;
    tete->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;
    afichage(tete);*/
    //way2
    temp t1,t2,t3;
    temp *tete;
    t1.data=1;
    t2.data=2;
    t3.data=3;
    t1.next=&t2;
    t2.next=&t3;
    t3.next=NULL;
    tete=&t1;
    afichage(&t1);
    return 0;
}
void afichage(temp *n){
  while(n!=NULL){
     cout<<n->data <<"  ";
     n=n->next;
  }
}
