#include <iostream>
using namespace std;

// Struktur node untuk linked list
struct Node {
    string nama;
    Node* next;
};

// Inisialisasi head dan tail antrian
Node* front = nullptr;
Node* rear = nullptr;

// Fungsi untuk menambahkan ke antrian (enqueue)
void enqueue(string nama) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->next = nullptr;

    if (rear == nullptr) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << nama << " telah masuk ke antrian.\n";
}

// Fungsi untuk menghapus dari antrian (dequeue)
void dequeue() {
    if (front == nullptr) {
        cout << "Antrian kosong!\n";
        return;
    }

    Node* hapus = front;
    cout << hapus->nama << " telah dipanggil dari antrian.\n";
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete hapus;
}

// Fungsi untuk menampilkan antrian
void tampilkanAntrian() {
    if (front == nullptr) {
        cout << "Antrian kosong!\n";
        return;
    }

    Node* temp = front;
    cout << "Daftar antrian:\n";
    while (temp != nullptr) {
        cout << "- " << temp->nama << endl;
        temp = temp->next;
    }
}

int main() {
    int pilihan;
    string nama;

    do {
        cout << "\n=== ANTRIAN LOKET TIKET ===\n";
        cout << "1. Tambah antrian\n";
        cout << "2. Panggil antrian\n";
        cout << "3. Lihat antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                enqueue(nama);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                tampilkanAntrian();
                break;
            case 4:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while(pilihan != 4);

    return 0;
}
