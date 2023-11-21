#include <iostream>

struct Node {
    int exponent;
    double coefficient;
    Node* next;

    Node(int exp, double coef) : exponent(exp), coefficient(coef), next(nullptr) {}
};

Node* addTerm(Node* result, int exponent, double coefficient) {
    Node* newNode = new Node(exponent, coefficient);
    newNode->next = result;
    return newNode;
}

Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = nullptr;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->exponent > p2->exponent) {
            result = addTerm(result, p1->exponent, p1->coefficient);
            p1 = p1->next;
        } else if (p1->exponent < p2->exponent) {
            result = addTerm(result, p2->exponent, p2->coefficient);
            p2 = p2->next;
        } else {
            double sum = p1->coefficient + p2->coefficient;
            if (sum != 0.0) {
                result = addTerm(result, p1->exponent, sum);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != nullptr) {
        result = addTerm(result, p1->exponent, p1->coefficient);
        p1 = p1->next;
    }

    while (p2 != nullptr) {
        result = addTerm(result, p2->exponent, p2->coefficient);
        p2 = p2->next;
    }

    return result;
}

void printPolynomial(Node* poly) {
    while (poly != nullptr) {
        std::cout << poly->coefficient << "x^" << poly->exponent;
        if (poly->next != nullptr) {
            std::cout << " + ";
        }
        poly = poly->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* p = new Node(2, 3.0);
    p->next = new Node(3, -6.0);
    p->next->next = new Node(1, 5.5);

    Node* q = new Node(3, 2.5);
    q->next = new Node(3, 2.0);
    q->next->next = new Node(2, -1.0);

    std::cout << "Polynôme N1 : ";
    printPolynomial(p);

    std::cout << "Polynôme N2 : ";
    printPolynomial(q);

    Node* sum = addPolynomials(p, q);

    std::cout << "LA Somme des polynômes est : ";
    printPolynomial(sum);

    
    

    return 0;
}
