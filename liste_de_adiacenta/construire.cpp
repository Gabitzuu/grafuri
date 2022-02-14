#include <iostream>
#include <fstream>

using namespace std;

int n, m, x, y;

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
    q=prim;
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

int main() {
    ifstream fin("graf.in");
    fin >> n >> m;

    // citire si construire
    for(int i = 1; i <= m; i++) {
        fin >> x >> y;
        if(liste[x] == NULL)
            creare(liste[x], y);
        else
            ad_dupa(liste[x], y);

        if(liste[y] == NULL)
            creare(liste[y], x);
        else
            ad_dupa(liste[y], x);
    }
    for(int i = 1; i <= n; i++) {
        afisare(i, liste[i]);
    }

    return 0;
}
