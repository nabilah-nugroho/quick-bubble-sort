#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[10];
} data;

int main(){
    int input, i, tukar;
    char tampungan[100];

    printf("berapa angka: ");
    scanf("%d", &input);

    data mahasiswa[input];

    for(i=0; i<input; i++){
        printf("nama: ");
        scanf("%s", &mahasiswa[i].nama);
    }
    do{
        tukar=0;
            for(i=0;i<input-1;i++){
                if((strcmp(mahasiswa[i].nama, mahasiswa[i+1].nama)<0)){
                    strcpy(tampungan, mahasiswa[i].nama);
                    strcpy(mahasiswa[i].nama, mahasiswa[i+1].nama);
                    strcpy(mahasiswa[i+1].nama, tampungan);
                    tukar=1;
                }
            }
    }while(tukar==1);
    printf("\n");

    for(i=0; i<input; i++){
        printf("%s \n", mahasiswa[i].nama);

    }
    return 0;
}