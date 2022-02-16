// versiunea de pe pbinfo

int parc_lat(int start)
{
  int i,k,st,dr;
  //initializez coada
  st=dr=1;
  x[1]=start;
  v[start]=1;//vizitez varful initial
  while(st<=dr)//cat timp coada nu este vida
  {
    k=x[st];//preiau un element din coada
    for(i=1;i<=n;i++)//parcurg varfurile
      if(v[i]==0 && a[k][i]==1)//daca i este vecin cu k si nu este vizitat
      {
        v[i]=1;//il vizitez
        x[++dr]=i;//il adaug in coada
      }
    st++;//sterg din coada
  }
  return dr;//returnam numarul de varfuri vizitate
}
