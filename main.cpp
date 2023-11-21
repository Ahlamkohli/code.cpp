#include <iostream>
using namespace std;

struct maliste
{
    int x;
    struct maliste* next;
};

maliste* ajoute(maliste* tete, int val)
{
    maliste* elem = new maliste;
    if (elem == NULL)
    {
        exit(0);
    }
    elem->x = val;
    elem->next = tete;
    tete = elem;
    return tete;
}

void affiche(maliste* tete)
{
    maliste* t;
    t = tete;
    while (t != NULL)
    {
        cout << t->x << " ";
        t = t->next;
    }
    cout << endl;
}

maliste* sup(maliste* tete, int m)
{
    if (tete == NULL)
    {
        cout << "Liste vide" << endl;
        return tete;
    }

    if (m == 1)
    {
        maliste* p = tete;
        tete = tete->next;
        delete (p);
    }
    else
    {
        maliste* p = tete;
        maliste* l = NULL;
        int i = 1;
        while (p != NULL && i != m)
        {
            l = p;
            p = p->next;
            i = i + 1;
        }
        if (i == m && p != NULL)
        {
            l->next = p->next;
            delete (p);
        }
        else
        {
            cout << "Position n'existe pas" << endl;
        }
    }
    return tete;
}

int main()
{
    maliste* tete = NULL;
    int a, b, c, d, k;

    cout << "Entrez les valeurs que vous voulez ajouter :" << ;
    cin >> a >> b >> c >> d;

    tete = ajoute(tete, a);
    tete = ajoute(tete, b);
    tete = ajoute(tete, c);
    tete = ajoute(tete, d);

    cout << "L'affichage :" << endl;
    affiche(tete);

    cout << "Entrez la position de suppression :";
    cin >> k;
    tete = sup(tete, k);

    cout << "Nouvel affichage :" << endl;
    affiche(tete);

    return 0;
}
