#include <iostream>
#include <fstream>

using namespace std;

int n, m, gr, A[100][100];
int x, y, viz[100], cc;

void parc_ad(int nod, int k) {
    viz[nod] = k;
    for(int i = 1; i <= n; i++) {
        if(A[nod][i] == 1 && viz[i] == 0)
            parc_ad(i, k);
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
