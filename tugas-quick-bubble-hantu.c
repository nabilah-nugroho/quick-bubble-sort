//NAMA  : NABILAH NUR AISYAH NUGROHO
//NIM   : 2510514020

//1. PENJELASAN ALGORITMA SECARA KESELURUHAN
//    1. program menerima input jumlah elemen hantu (m) dan jumlah total elemen (n)
//    2. Program menerima input nilai elemen hantu
//    3. Program menerima input seluruh data angka
//    4. Data angka diurutkan secara ascending menggunakan algoritma QuickSort (rekursif)
//    5. Data angka kemudian diurutkan kembali secara descending menggunakan algoritma Bubble Sort (iteratif)
//    6. Saat proses pencetakan hasil Bubble Sort, elemen yang termasuk angka hantu tidak ditampilkan

//2. bagaimana cara program ini melakukan ascending dengan quicksort (rekursif)
//    1. Program memilih elemen terakhir sebagai pivot.
//    2. program mengatur ulang array sehingga angka yang lebih kecil dari pivot pindah ke kiri
//        dan yang lebih besar ke kanan (fungsi tungs sebagai fungsi partitioning)
//    3. dengan rekursif, fungsi quickSort memanggil dirinya sendiri untuk bagian kiri dan kanan pivot 
//       secara terus-menerus sampai sub-array hanya berisi satu elemen (yang berarti sudah terurut).
//    4. Kondisi if (low < high) adalah base case. kalau indeks bawah sudah melampaui atau sama dengan indeks atas, rekursi berhenti.

//3. mengapa pencetakan quicksort dengan rekursif dipisah dengan fungsi quicksortnya
//   sedangkan fungsi pencetakan dan fungsi bubblesort dengan for loop digabung
//   1. saya sempat mencoba menggabungkan fungsi pencetakan dengan quicsort,
//      output tercetak berkali-kali karena fungsi tersebut dipanggil berulang selama proses rekursi.
//   2. oleh karena itu, fungsi pencetakan saya pisahkan ke fungsi cetakQS agar hasil hanya ditampilkan
//      satu kali setelah seluruh proses QuickSort selesai.
//   3. sedangkan pada Bubble Sort, proses sorting menggunakan perulangan (iteratif) dan hanya berjalan
//      satu kali dari awal sampai akhir fungsi, sehingga pencetakan hasil bisa langsung digabung
//      dalam fungsi yang sama tanpa menyebabkan output berulang.
//            pada quicksort, proses sorting dilakukan secara REKURSIF, sehingga fungsi quickSort
//      akan dipanggil berkali-kali untuk sub-array kiri dan kanan pivot.

//4. bagaimana cara program ini melakukan descending dengan bubble sort (for loop)
//     1. Program membandingkan dua elemen yang berdekatan (angka[j] dan angka[j+1]).
//     2. Karena ingin mengurutkan dari besar ke kecil, kondisinya adalah if(angka[j] < angka[j+1]). 
//        Jika angka di kiri lebih kecil dari angka di kanan, mereka ditukar (tuker).
//     3. Dalam setiap satu putaran outer loop (i), angka terkecil akan tenggelam ke posisi paling kanan, 
//        sehingga putaran berikutnya tidak perlu mengecek posisi tersebut lagi (size-1-i).

//5. bagaimana cara program ini mendeteksi elemen hantu
//     1. menggunakan Linear Search, Fungsi ini menerima sebuah ang ka x, 
//       lalu melakukan perulangan dari indeks 0 sampai m-1 pada array hantu[].
//     2. Jika x ditemukan di dalam array hantu, fungsi langsung mengembalikan nilai 1 (true). 
//        Jika sampai akhir loop tidak ketemu, ia mengembalikan 0 (false).
//     3. Saat proses cetak di dalam bubbleSort, program memanggil fungsi ini. 
//        Jika hasilnya 1, maka printf("  ") dijalankan alih-alih mencetak angkanya.

//6. bagaimana cara program ini menghandle memori sehingga tidak segmentation fault di beberapa bagian kritis
//     1. penggunaan #define serem 10 dan array angka[100] memberikan batas yang jelas di memori.
//     2. Di dalam main(), terdapat pengecekan:
//          if (m < 10 && m > 0 && n <= 100 && n > 0 && m < n)
//       Ini memastikan bahwa user tidak memasukkan n > 100 (yang akan menjebol array angka) atau m > 10 (yang akan menjebol array hantu). 
//       Jika input melanggar batas, program tidak akan menjalankan proses sorting yang berisiko segmentation fault.

#include <stdio.h>

#define serem 10
int m, n; // m = jumlah angka hantu, n = jumlah total angka
int hantu[serem]; //array untuk menyimpan angka hantu
int angka[100]; //array untuk menyimpan seluruh data angka

//fungsi prototype untuk hantuIni (dideklarasikan sebelum digunakan)
int hantuIni(int x);

//fungsi untuk menukar dua elemen dengan menampung
void tuker(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//fungsi partition untuk quicksort agar bisa membagi array menjadi dua bagian
// kiri = elemen lebih kecil dari pivot
// kanan = elemen lebih besar dari pivot
int tungs(int angka[], int low, int high) {
    int pivot = angka[high]; //memilih angka terakhir sebagai pivot
    int i = (low - 1); //i untuk indeks elemen yang lebih kecil dari pivot

    for (int j = low; j < high; j++) { //proses membandingkan setiap elemen dengan pivot
        // ascending
        if (angka[j] < pivot) {
            i++;
            tuker(&angka[i], &angka[j]);
        }
    }
    tuker(&angka[i + 1], &angka[high]); //menempatkan pivot pada posisi seharusnya
    return (i + 1); //mengembalikan indeks pivot
}

// fungsi quicksort saya coba menggunakan metode rekursif
// membagi array menjadi sub-array kiri dan kanan pivot
void quickSort(int angka[], int low, int high) {
    if (low < high) { //base condition: jika low >= high maka tidak perlu sorting lagi
        int pi = tungs(angka, low, high);

        quickSort(angka, low, pi - 1);  // bagian kiri pivot
        quickSort(angka, pi + 1, high); // bagian kanan pivot
    }
}

//mencetak hasil quicksort
void cetakQS(int angka[], int n){
    printf("\nhasil sorting quick sort (asc+hantu): \n");
    for(int i = 0; i < n; i++){ //angka yang termasuk angka hantu tidak ditampilkan
        if(hantuIni(angka[i])){
            printf("  ");
        }
        else{ // angka normal
            printf("%d ", angka[i]);
        }
    }
    printf("\n");
}

// linear search untuk mendeteksi apakah suatu angka termasuk angka hantu
// return
// 1 = jika angka ditemukan
// 0 = jika angka tidak ditemukan
int hantuIni(int x){
    for(int i=0; i<m; i++){ //mencari x dalam array hantu[]
        if(x==hantu[i])return 1;
    }
    return 0;
}

//fungsi bubblesort descending
// dan memproses angka hantu
void bubbleSort(int angka[], int size){
    int temp, i, j;
    for(i=0; i<size-1; i++){ //proses desc bub sort
        for(j=0; j<size-1-i; j++){ //setiap iterasi akan memindahkan elemen terkecil ke posisi paling kanan
            if(angka[j]<angka[j+1]){ //descending
                tuker(&angka[j], &angka[j+1]);    
            }
        }
    }

    //proses pencetakkan hasil sorting
    printf("hasil sorting bubble (desc+hantu): \n");
    for(int i = 0; i < n; i++){ //angka yang termasuk angka hantu tidak ditampilkan
        if(hantuIni(angka[i])){
            printf("  ");
        }
        else{ // angka normal
            printf("%d ", angka[i]);
        }
    }
}

// loop validasi input agar program terus meminta input ulang sampai nilai m dan n memenuhi batas array yang tersedia
int main() {
    do{
        printf("masukkan total angka hantu dan total angka yang ada (m n): "); scanf("%d %d", &m, &n);
        printf("\n");

        if (m < 10 && m > 0 && n <= 100 && n > 0 && m < n){ // validasi input untuk mencegah segmentation fault
            for(int i = 0; i < m; i++){
                printf("angka hantu ke-%d: ", i+1); scanf("%d", &hantu[i]);
            }
            for(int i = 0; i < n; i++){
                printf("angka ke-%d: ", i+1); scanf("%d", &angka[i]);
            }
            quickSort(angka, 0, n-1);
            cetakQS(angka, n);
            bubbleSort(angka, n);
            break;
            }
        else {
            printf("tidak valid, silakan coba kembali\n");
            }
        } while(1);
        return 0;
    }