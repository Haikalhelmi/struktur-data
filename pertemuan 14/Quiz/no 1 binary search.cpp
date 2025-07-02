#include <iostream>
using namespace std;

int cariBiner(int arr[], int panjang, int nilaiCari) {
    int kiri = 0;
    int kanan = panjang - 1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (arr[tengah] == nilaiCari) {
            return tengah;
        } else if (arr[tengah] < nilaiCari) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    return -1;
}

int main() {
    int angka[] = {11, 22, 33, 44, 55, 66, 77};
    int jumlahElemen = sizeof(angka) / sizeof(angka[0]);

    int dicari;
    cout << "Masukkan angka yang dicari: ";
    cin >> dicari;

    int hasil = cariBiner(angka, jumlahElemen, dicari);

    if (hasil != -1) {
        cout << "Angka " << dicari << " ditemukan di indeks ke-" << hasil << endl;
    } else {
        cout << "Angka tidak ditemukan dalam data." << endl;
    }

    return 0;
}

