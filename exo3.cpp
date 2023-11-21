#include <iostream>
using namespace std;

void remplir(int a[], int n) {
    cout<<"remplir le  tableau  " <<endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int trouvmax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int trouvmin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return ;
}

void affich(int a[], int n) {
    cout << "tableau: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void trier(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                int val = a[i];
                a[i] = a[j];
                a[j] = val;
            }
        }
    }
}

int main() {
    int s;

    int a[100];
      cout << "enter n :" << endl;
    cin >>s;
    remplir(a,s);
    int max = trouvmax(a,s);
    int min = trouvmin(a,s);

    cout << "tableau 01 : " << endl;
    affich(a,s);

    trier(a,s);

    cout << "tableau 02 : " << endl;
    affich(arr,s);

    cout << "Maximum valeur: " << max << endl;
    cout << "Minimum valeur: " << min << endl;

    return 0;
}
