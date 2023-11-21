#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
struct list{//templet
int val ;
list *next;
};

//list malist;
//list *tete=NULL;// debut
//ajouter a debut
list *ajout(list *tete,int valeur){
  list*elem=new list;                //(list*)malloc(sizeof(list));
  if (elem==NULL)
     exit(0);
  elem->val=valeur;
  elem->next=tete;
  tete=elem;
  return tete;
}
// ajouter a la fin
list *ajouter(list *debut,int valeur){
 list *b=new list;
 //b=(list*)malloc(sizeof(list));
 b->val=valeur;
 b->next=NULL;
 if (debut==NULL)
     debut=b;
 else{
     list *c=debut;
     while(c->next!=NULL){
          c=c->next;
     }
     c->next=b;
 }
      return debut;
}
//affichage
void afichage(list *n){
  while(n!=NULL){
     cout<<n->val <<"  ";
     n=n->next;
  }
 cout<< "\n";
}
int main()
{   list t1,t2,t3;
    list *tete;
    t1.val=1;
    t2.val=2;
    t3.val=3;
    t1.next=&t2;
    t2.next=&t3;
    t3.next=NULL;
    tete=&t1;
    afichage(tete);
    tete = ajout(tete, 15);
    tete = ajouter(tete, 39);
    afichage(tete);
    return 0;
}
