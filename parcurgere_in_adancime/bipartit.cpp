#include <iostream>
#include <fstream>

using namespace std;

int n, m, gr, A[100][100];
int x, y, viz[100], v[100], cc;

int k = 1;
int as;
int ev;

int bipartit;

void parc_ad(int nod, int k) {
    viz[nod] = k;
    for(int i = 1; i <= n; i++) {
        if(A[nod][i] == 1) {
            if(viz[nod] == viz[i]) {
                bipartit = 1;
            }
            if(viz[i] == 0)
                parc_ad(i, -k);
        }
    }
}

int main() {
    ifstream fin("graf.in");
    fin>>n>>m;

    for(int i = 1; i <= m; i++) {
        fin >> x >> y;
        A[x][y] = A[y][x] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(viz[i] == 0) {
            parc_ad(i, 1);
        }
    }

    if(bipartit == 0)
        cout << "BIPARTIT";
    else
        cout << "NU";

    return 0;
}
