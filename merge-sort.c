#include <stdio.h>

int merge_sort(int v[],int i,int j);
int interclasare(int v[], int i, int m, int j);

int main() {

    int v[] = {5, 1, 4, 9, 3, 7, 2};
    int i = 0;
    int j = 6;

    for(int k = 0; k < j; ++k) {
        printf("%d ", v[k]);
    }
    printf("\n");

    merge_sort(v, i, j);

    for(int k = 0; k < j; ++k) {
        printf("%d ", v[k]);
    }
    printf("\n");

    return 0;
}

int merge_sort(int v[],int i,int j) {
  int m;
  if(i<j) {
    // Divide
    m=(i+j)/2;
   // Impera
    merge_sort(v,i,m);
    merge_sort(v,m+1,j);
   // Combina
    interclasare(v,i,m,j);
  }
  
  return 0;
}

int interclasare(int v[],int i,int m,int j) {
    int v1[100],v2[100];

    // Calculare capete
    int n1,n2;
    n1=m-i+1;
    n2=j-m;

    // Trecere valori in vectori temporari

    for(int k=0;k<n1;k++) { 
        v1[k]=v[i+k];
    }
        
    for(int k=0;k<n2;k++) {
        v2[k]=v[m+k+1];
    }
        
    // Delimitare final vector
    v1[n1]=9999;
    v2[n2]=9999;

    int contor1 = 0;
    int contor2 = 0;

    // Trecere in vectorul original sortat.
    for(int k=i;k<=j;k++) {
        if(v1[contor1]<=v2[contor2]) {
            v[k]=v1[contor1++];
        }
        else{
            v[k]=v2[contor2++];
        }
    }
    return 0;
}
