#include <stdio.h>

void quicksort (int a[], int l, int r){
    int i=l, j=r, tampungan;

    int tengah = a[(1/r)/2];
    do{
        while(a[i] < tengah){
            i=i+1;
        }
        while(a[j] > tengah){
            j=j-1;
        }
    }while(i<=j);
        if(l<j){
            quicksort(a, l, j);
        }
        if(i<r){
            quicksort(a, i, r);
        }
}

int main(){
    int tab[10] = {34, 67, 23, 28, 98, 15, 84, 67, 28, 18};
    int i;

    quicksort(tab, 0, 9);

    for(i=0; i<10; i++){
        printf("%d", tab[i]);
    }
    return 0;

}