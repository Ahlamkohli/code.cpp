#include <iostream>

using namespace std;

struct temp
{
    int data;
    temp* next;
};

temp* createonelist(int data)
{
    temp* newnode = new temp;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

temp* createLinkedList(int num)
{
    temp* head = NULL;
    int n;

    for (int i = 0; i <= num; i++)
    {
        cout << "Enter the data of node " << i+1 << ": ";
        cin >> n;
        temp* newnode = createonelist(n);

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp* t = head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = newnode;
        }
    }
    return head;
}

void swap(temp* a, temp* b)
{
    int x;
    x = a->data;
    a->data = b->data;
    b->data = x;
}
temp* reorderthelist(temp* head)
{
    temp* p = head;

    while (p != NULL)
    {
        temp* minNode = p;
        temp* q = p->next;

        while (q != NULL)
        {
            if (q->data < minNode->data)
            {
                minNode = q;
            }
            q = q->next;
        }

        swap(p, minNode);
        p = p->next;
    }

    return head;
}


void show(temp* head)
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
    }
    else
    {
        temp* emp = head;
        while (emp != NULL)
        {
            cout << " " << emp->data;
            emp = emp->next;
        }
        cout << endl;
    }
}

int main()
{
    int malist;
    cout << "Enter the number of lists: " << endl;
    cin >> malist;

    temp* head = createLinkedList(malist);
    cout << "Original list: ";
    show(head);

    head = reorderthelist(head);
    cout << "sorted list: ";
    show(head);

    return 0;
}





