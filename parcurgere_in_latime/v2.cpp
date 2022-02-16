// varianta din clasa

void parc_lat(int nod) {
    int i;
    c[vf] = nod;
    viz[nod] = 1;
    while(poz <= vf) {
        for(i = 1; i <= n; i++) {
            if(A[c[poz]][i] == 1 && viz[i] == 0) {
                vf++;
                c[vf] = i;
                viz[i] = 1;
            }
        }
        poz++;
    }
}

// Parcurgerea se realizeaza pentru componentele conexe din care face parte nodul.
