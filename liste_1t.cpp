#include <iostream>
using namespace std;
// Structure for a list node
struct Node {
    int value;
    Node* next;
};

Node* add(Node*& head, int d)
{
    Node *current=new Node;
    current->value=d;
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

// Function to insert list D2 into list D1 after the element with value 'val'
bool insererApresElement(Node*& D1, Node*& D2, int val) {
    Node* current = D1;

    // Search for the element with the value 'val'
    while (current != nullptr && current->value != val) {
        current = current->next;
    }

    // If the element with the value 'val' is found, insert list D2 after this element
    if (current != nullptr) {
        Node* temp = current->next; // Save the rest of list D1
        current->next = D2;         // Connect the end of the current element to the head of list D2

        // Find the end of list D2
        while (D2 != nullptr && D2->next != nullptr) {
            D2 = D2->next;
        }

        // Connect the rest of list D1 to the end of list D2
        if (D2 != nullptr) {
            D2->next = temp;
        }

        // Reset the head of list D2
        D2 = nullptr;

        return true; // Operation succeeded
    }

    return false; // The element with the value 'val' was not found
}

// Function to display a list
void afficherListe(Node* list) {
    while (list != nullptr) {
        std::cout << list->value << " ";
        list = list->next;
    }
    std::cout << std::endl;
}

// Function to free the memory allocated for a list
void libererListe(Node*& list) {
    while (list != nullptr) {
        Node* next = list->next;
        delete list;
        list = next;
    }
}

int main() {
    // Example usage
    Node* D1 = NULL;
    Node* D2 = NULL;
    int n,m,j,i,nbr1,nbr2;
    cout<<"Enter the number of elements in your first linked list: ";
    cin>>nbr1;

    for(i=0; i<nbr1; i++)
    {
        cout<<"Enter the element number 0"<<i+1<<" : ";
        cin>>n;
        D1=add(D1,n);
    }

    cout<<"Enter the number of elements in your second linked list: ";
    cin>>nbr2;

    for(j=0; j<nbr2; j++)
    {
        cout<<"Enter the element number 0"<<j+1<<" : ";
        cin>>m;
        D2=add(D2,m);
    }

    cout << "List D1 before insertion: ";
    afficherListe(D1);

    cout << "List D2 before insertion: ";
    afficherListe(D2);

    int val;
    cout<<"enter the value To Insert After: ";
    cin>>val;
    // Call the function to insert D2 into D1 after the element with value 'valueToInsertAfter'
    if (insererApresElement(D1, D2, val)) {
        cout << "Insertion successful." << endl;
    } else {
        cout << "The element with value " << val << " was not found." << endl;
    }

    cout << "List D1 after insertion: ";
    afficherListe(D1);

    cout << "List D2 after insertion: ";
    afficherListe(D2);

    // Free the memory allocated for the lists
    libererListe(D1);
    libererListe(D2);

    return 0;
}
