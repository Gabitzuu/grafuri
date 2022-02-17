// cititi un graf orientat. memorati graful folosind listele de adiacenta. afisati nodurile izolate urmate de acele noduri pentru
// care gradul intern este mai mare decat gradul extern.

#include <iostream>
#include <fstream>

using namespace std;

int n, m, x, y;

int gi[100], ge[100];

struct nod {
    int nr;
    nod *urm;
} *liste[100];

void creare(nod *&prim, int nr) {
    prim = new nod;
    prim->nr = nr;
    prim->urm = NULL;
}

void ad_dupa(nod *&prim, int nr) {
    nod *p = new nod, *q;
    p->urm = NULL;
    p->nr = nr;
    q = prim;

    while(q->urm != NULL) {
        q = q->urm;
    }

    q->urm = p;
}

void afisare(int nr, nod *prim) {
    nod *p = prim;

    cout << "NOD " << nr << ": ";

    while (p != NULL) {
        cout << p->nr << " ";
        p = p->urm;
    }
    cout << endl;
}

int grade(nod *n) {
    int k = 0;
    while (n != NULL) {
        k++;
        gi[n->nr]++;
        n = n->urm;
    }
    return k;
}

int main() {
    ifstream fin("graf.in");
    fin >> n >> m;

    for(int i = 1; i <= m; i++) {
        fin >> x >> y;
        if(liste[x] == NULL)
            creare(liste[x], y);
        else
            ad_dupa(liste[x], y);
    }

    for(int i = 1; i <= n; i++) {
        ge[i] = grade(liste[i]);
    }

    cout << "Nodurile izolate sunt: ";
    for(int i = 1; i <= n; i++) {
        if(ge[i] == 0 && gi[i] == 0) {
            cout << i << " ";
        }
    }

    cout << endl << "Nodurile de la 2: ";

    for(int i = 1; i <= n; i++) {
        if(gi[i] > ge[i]) {
            cout << i << " ";
        }
    }


    return 0;
}
