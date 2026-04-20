/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2 Data Manipulation & EXternala File
 *   Hari dan Tanggal    : 20 April 2025
 *   Nama (NIM)          : Audrin Naufal Fikri Frederick (13224044)
 *   Nama File           : tiga peti kargo.c
 *   Deskripsi           : Sistem akan diberikan input berupa n elemen yang merupakan berat, 
 *                         kemudian jumlah suku elemen akan dibagi menjadi tiga bagian dengan 
 *                         2 titik potong yang menyebabkaan ketiga bagian memiliki berat yang 
 *                         sama (minimum). Sistem akan mengeluarkan output berupa selisih minimum 
 *                         antara bagian dengan berat maksimum dan bagian dengan berat minimum,
 *                         serta titik potong yang menyebabkan selisih minimum tersebut.
 * 
 *                        
 */


 #include <stdio.h>
 #include <string.h>

int main() {
//Masukan array
// penulisan array (n, elemen 1, elemen 2, ..., elemen n)
  int n, i, j, k;
  scanf("%d", &n);
  
  int arr[n];
  for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
  }
// menentukan 2 titik potong yang menyebabkan ketiga bagian memiliki selisih minimum
// min_diff = selisih minimum antara bagian dengan berat maksimum dan bagian dengan berat minimum
    int min_diff = 1000000; // inisialisasi selisih minimum dengan nilai yang sangat besar
    int cut1 = 0, cut2 = 0; // inisialisasi titik potong
    
    for (i = 1; i < n-1; i++) { // titik potong pertama
        for (j = i+1; j < n; j++) { // titik potong kedua
            int sum1 = 0, sum2 = 0, sum3 = 0;
            for (k = 0; k < i; k++) {
                sum1 += arr[k]; // bagian pertama
            }
            for (k = i; k < j; k++) {
                sum2 += arr[k]; // bagian kedua
            }
            for (k = j; k < n; k++) {
                sum3 += arr[k]; // bagian ketiga
            }
            int max_sum = sum1 > sum2 ? (sum1 > sum3 ? sum1 : sum3) : (sum2 > sum3 ? sum2 : sum3); // mencari nilai maksimum dari ketiga bagian
            int min_sum = sum1 < sum2 ? (sum1 < sum3 ? sum1 : sum3) : (sum2 < sum3 ? sum2 : sum3); // mencari nilai minimum dari ketiga bagian
            int diff = max_sum - min_sum; // menghitung selisih antara nilai maksimum dan minimum
            
            if (diff < min_diff) { // jika selisih lebih kecil dari selisih minimum sebelumnya
                min_diff = diff; // update selisih minimum
                cut1 = i; // update titik potong pertama
                cut2 = j; // update titik potong kedua
            }
        }
    }
    printf("\nMIN_DIFF %d\n", min_diff);

//Titik i & j yang menyebabkan selisih minimum
    printf("CUT %d", cut1);
    printf(" %d\n", cut2);
    return 0;

}


