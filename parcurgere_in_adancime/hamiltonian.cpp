#include <iostream>
#include <fstream>

using namespace std;

int n, m, gr, A[100][100];
int x, y, viz[100], v[100], cc;

int k = 1;
int as;
int ev;

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

    v[1] = 0;

    while(k > 0) {
        do {
            as = 0;
            ev = 1;
            v[k]++;
            if(v[k] <= n) {
                as = 1;
            }
            for(int i = 1; i <= k - 1; i++) {
                if(v[i] == v[k]) {
                    ev = 0;
                }
            }
        } while (as == 1 && ev == 0);

        if(as == 1) {
            if (n == k) {
                x = 0;
                for(int i = 2; i <= n; i++) {
                    if(A[v[i]][v[i-1]] == 0) {
                        x = 1;
                    }
                }
                if(A[v[1]][v[n]] == 0) {
                    x = 1;
                }
                if(x == 0) {
                    cout << "HAMILTONIAN";
                    return 0;
                }
            } else {
                k++;
                v[k] = 0;
            }
        } else k--;
    }
    cout << "nu este hamiltonian";

    return 0;
}
