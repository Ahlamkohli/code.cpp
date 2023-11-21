#include <iostream>

using namespace std;
struct temp
{
    int info;
    temp *next;
};
bool isfound(temp *debut, int y);
void add_before(temp *debut,int val,int x);
int main()
{
    temp* head = new temp;
    head->info = 5;
    head->next = NULL;

    add_before(head, 5, 10); // Example usage: add 10 before the value 5
    add_before(head, 4, 8); // Example usage: tries to add 8 before the value 4 (not present in the list)


    return 0;
}
bool isfound(temp *debut, int y)
{
    temp *courant=debut;
    while(courant!=NULL)
    {
        if(courant->info==y)
        {
            return true;
        }
        courant=courant->next;
    }
    return false;

}
void add_before(temp *debut,int val,int x)
{
    if (isfound(debut,val))
    {
        temp *p=debut;
        temp *current=new temp;
        current->info=x;
    if (p->info == val) {
            current->next = p;
            debut = current;
            return;
        }

       while (p->next != NULL) {
            if (p->next->info == val) {
                current->next = p->next;
                p->next = current;
                return;
            }
            p = p->next;
        }
    } else {
        cout << "Sorry, value not found!" << endl;
    }
}
