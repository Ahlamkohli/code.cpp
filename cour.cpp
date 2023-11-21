#include <iostream>

using namespace std;

struct prod{
 int code;
 float prix;
 float poid;
};
void remplisage(int n,prod a[]);
void affichage(int n,prod a[]);
void augmantation(int n,prod a[],float taux);
float prix_t(int n,prod a[]);// float prix_t(int n,prod a[], float *pt) //float prix_t(int n,prod a[], float &pt)
int main()
{   int n;
    prod a[100];
    float taux=0.1;
    cout << "donner la valeur de n : "  ;
    cin >> n;
    remplisage(n,a);
    affichage(n,a);
    augmantation(n,a,taux);
    cout<<"le prix totale est : "<<  prix_t(n,a) <<" da";//prix_t(n,a,&pt)
    return 0;
}
void remplisage(int n,prod a[]){
 for (int i=0;i<n;i++){
  cout<<"donner le code de " << i+1 << " produit : ";
  cin >> a[i].code;
  cout<<"donner le prix de " << i+1 << " produit : ";
  cin >> a[i].prix;
  cout<<"donner le poid de " << i+1 << " produit : ";
  cin >> a[i].poid;
  }
}
void affichage(int n,prod a[]){
  for (int i=0;i<n;i++){
     cout<< "0"<<i+1 << " produit '" << "le code: "<<a[i].code<<" est le prix : "<<a[i].prix<< " est le poid : "<<a[i].poid <<"'" << endl;
  }
}

void augmantation(int n,prod a[],float taux){
  for (int i=0;i<n;i++){
  a[i].prix=a[i].prix+(a[i].prix)*taux;
}
}

float prix_t(int n,prod a[]){//void prix_t(int n,prod a[],float *pt) // void prix_t(int n,prod a[],float &pt)
     int pt=0;
 for (int i=0;i<n;i++){
  pt=pt+a[i].prix;           //*pt=*pt+a[i].prix;
  return pt;
}
}
