#include <iostream>
#include <fstream>

using namespace std;

int n, m, gr, A[100][100];
int x, y, viz[100];

void parc_ad(int nod) {
    cout << nod << " ";
    viz[nod] = 1;
    for(int i = 1; i <= n; i++) {
        if(A[nod][i] == 1 && viz[i] == 0)
            parc_ad(i);
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
        if(viz[i] == 0)
            parc_ad(i);
    }


    return 0;
}
