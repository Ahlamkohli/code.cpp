#include <iostream>
using namespace std;

struct temp
{
    int data;
    temp* next;
};


void swapData(temp* a, temp* b)
{
    int x = a->data;
    a->data = b->data;
    b->data = x;
}

void isfound(temp* head, int t)
{
    temp* fox = head;
    bool found = false;

    while (fox != NULL)
    {
        if (fox->data == t)
        {
            found = true;
            break;
        }

        fox = fox->next;
    }

    if (found)
    {
        cout << "The element '" << t << "' exists in your linked list. " << endl ;
    }
    else
    {
        cout << "Sorry, the element '" << t << "' is not existing in your linked list." <<endl  ;
    }
}


temp* add(temp* head, int d)
{
    temp *current=new temp;
    current->data=d;
    current->next=NULL;
    if(head==NULL)
        head=current;
    else
    {
        current->next=head;
        head=current;
    }
    return head;
}

temp *Sort(temp* head)
{
    temp *y,*p;
    if (head != NULL)
    {
        for(y=head; y->next!=NULL; y=y->next)
            for(p=y->next; p!=NULL; p=p->next)
            {
                if(p->data<y->data)
                    swapData(p,y);
            }

    }
    return head;
}

void printList(temp* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int conte(temp* node , int v)
{   int i=0;
    while (node != NULL)
    {
        if(node->data==v)
        i=i+1;
        node = node->next;
    }
    return i;
}

int max(temp* node )
{   int max=node->data;
    while (node != NULL)
    {   
        if(max<node->data)
        max=node->data;
        node = node->next;
    }
    return max;
}


int min(temp* node )
{   int min=node->data;
    while (node != NULL)
    {   
        if(min>node->data)
        min=node->data;
        node = node->next;
    }
    return min;
}

temp* sup(temp* head, int m)
{
    if (head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return head;
    }

    if (m == 1)
    {
        temp* p = head;
        head = head->next;
        delete (p);
    }
    else
    {
        temp* p = head;
        temp* l = NULL;
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
            cout << "Position is not existing in your Linked List!" << endl;
        }
    }
    return head;
}

int main()
{
    temp *box=NULL;
    int n,i,nbr,v;
    cout<<"Enter the number of elements in your linked list: ";
    cin>>nbr;

    for(i=0; i<nbr; i++)
    {
        cout<<"Enter the element number 0"<<i+1<<" : ";
        cin>>n;
        box=add(box,n);
    }

    cout << "Linked List Original: ";
    printList(box);

    cout<<"Enter the element that are you looking for: ";
    cin>>v;

    isfound(box,v);

    int k=conte(box,v);
    cout << "The element '" << v << "' appeared in your linked list '"<< k <<"' time(s)."<< endl;
    int p;
     do {
        cout << "Do you want to add a new element (1) or delete an element (0)? Enter (1/0): ";
        cin >> p;
        if (p == 1) {
            int t;
            cout << "Enter the element that you want to add: ";
            cin >> t;
            box = add(box, t);
        } else if (p == 0) {
            int y;
            cout << "Enter the element that you want to delete: ";
            cin >> y;
            box = sup(box, y);
        }

        cout << "Do you want to continue? Enter '(1) for yes' or '(0) for no' (1/0): ";
        cin >> p;
    } while (p == 1);

    cout<<"Your Linked List:      ";
    printList(box);
    
    Sort(box);

    cout << "Linked List Sorted:   ";
    printList(box);

    int mini,maxi;
    mini=min(box);
    maxi=max(box);
    cout<<"The maximum element in your linked list is:  "<<maxi <<endl ;
    cout<<"The minimum element in your linked list is:  "<<mini;
    delete box;
}
