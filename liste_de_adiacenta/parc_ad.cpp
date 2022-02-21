// cititi un graf orientat. memorati graful folosind listele de adiacenta. afisati nodurile izolate urmate de acele noduri pentru
// care gradul intern este mai mare decat gradul extern.

#include <iostream>
#include <fstream>

using namespace std;

int n, m, x, y;
int viz[100], cc;

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

void parc_ad(int nd, int k) {
    nod *p = liste[nd];
    viz[nd] = k;
    while(p != NULL) {
        if(viz[p->nr] == 0) {
            parc_ad(p->nr, k);
        }
        p = p->urm;
    }
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
        if(viz[i] == 0) {
            cc++;
            parc_ad(i, cc);
        }
    }

    if(cc == 1) {
        cout << "Graful este conex.";
    } else {
        cout << "Graful NU este conex. Are " << cc << " componente conexe." << endl;
        for(int i = 1; i <= cc; i++) {
            cout << "Componenta "<< i << ": ";
            for(int j = 1; j <= n; j++) {
                if(viz[j] == i) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }


    return 0;
}
