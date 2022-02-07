#include <iostream>
#include <fstream>

using namespace std;

int n, m, gr, A[100][100];
int x, y;

int main() {
    ifstream fin("graf.in");
    fin >> n >> m;

    for(int i = 1; i <= m; i++) {
        fin >> x >> y;
        A[x][y] = 1;
    }

    cout << "Matricea de adiacenta este urmatoarea: " << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Gradele sunt: " << endl;

    for(int i = 1; i <= n; i++) {
        gr = 0;
        for(int j = 1; j <= n; j++) {
            gr = gr + A[i][j];
        }
        cout << "Nodul " << i << " are gradul extern " << gr << endl;
    }

    for(int j = 1; j <= n; j++) {
        gr = 0;
        for(int i = 1; i <= n; i++) {
            gr = gr + A[i][j];
        }
        cout << "Nodul " << j << " are gradul intern " << gr << endl;
    }
    return 0;
}
