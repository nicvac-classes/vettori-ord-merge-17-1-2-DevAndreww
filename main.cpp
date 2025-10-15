#include <iostream>
#include <ctime>

using namespace std;


int main() {
    srand(time(0));  
    int n, m, i, t, j, k;
    bool scambio;

    cout << "Valore di N?" << endl;
    cin >> n;
    cout << "Valore di M?" << endl;
    cin >> m;
    i = 0;
    j = 0;
    k = 0;
    int v1[n];
    int v2[m];

    while (i < n && j < m) {
        v1[i] = rand() % (n + 1);
        v2[j] = rand() % (m + 1);
        i = i + 1;
        j = j + 1;
    }
    i = 0;
    j = 0;
    scambio = true;
    while (i <= n - 1 && scambio) {
        scambio = false;
        j = 0;
        while (j <= n - 2 - i) {
            if (v1[j] > v1[j + 1]) {
                t = v1[j];
                v1[j] = v1[j + 1];
                v1[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    t = 0;
    i = 0;
    j = 0;
    scambio = true;
    while (j <= n - 1 && scambio) {
        scambio = false;
        i = 0;
        while (i <= n - 2 - j) {
            if (v2[i] > v2[i + 1]) {
                t = v2[i];
                v2[i] = v2[i + 1];
                v2[i + 1] = t;
                scambio = true;
            }
            i = i + 1;
        }
        j = j + 1;
    }
    int v3[m + n];

    k = 0;
    i = 0;
    j = 0;
    while (i <= n - 1 && j <= m - 1) {
        if (v1[i] <= v2[j]) {
            v3[k] = v1[i];
            i = i + 1;
        } else {
            v3[k] = v2[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i <= n - 1) {
        v3[k] = v1[i];
        k = k + 1;
        i = i + 1;
    }
    while (j <= m - 1) {
        v3[k] = v2[j];
        k = k + 1;
        j = j + 1;
    }
    k = 0;
    while (k < n) {
        cout << v3[k] << endl;
        k = k + 1;
    }
    int valore;

    cout << "Inserisci il valore da cercare" << endl;
    cin >> valore;

    // ricerca binaria
    int numControlli, inizio, fine, medio, indice;

    numControlli = 0;
    indice = (int) (-1);
    inizio = 0;
    fine = n - 1;
    while (inizio <= fine && indice == -1) {
        medio = (int) ((double) (inizio * (fine - inizio)) / 2);
        numControlli = numControlli + 1;
        if (valore == v3[medio]) {
            indice = medio;
        } else {
            numControlli = numControlli + 1;
            if (valore > v3[medio]) {
                inizio = medio + 1;
            } else {
                fine = medio - 1;
            }
        }
    }
    cout << "Controlli eseguiti: " << numControlli << endl;
    cout << "Il valore è stato trovato nella cella " << indice << endl;
    
}


