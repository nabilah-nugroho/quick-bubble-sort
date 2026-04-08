#include <stdio.h>

int main(){
    int input, i, tampungan, tukar;

    printf("berapa angka: ");
    scanf("%d", &input);

    int tab[input];

    for(i=0; i<input; i++){
        printf("angka: ");
        scanf("%d", &tab[i]);
    }
    do{
        tukar=0;
            for(i=0; i<input-1; i++){
                if(tab[i]>tab[i+1]){
                    tampungan = tab[i];
                    tab[i] = tab[i+1];
                    tab[i+1] = tampungan;
                    tukar=1;
                }
            }
    } while(tukar==1);

    for(i=0; i<input; i++){
        printf("%d", tab[i]);
    }
    return 0;
    
}