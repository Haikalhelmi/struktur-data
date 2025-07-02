#include <iostream>
#include <string>
using namespace std;

struct Data {
    string nama;
    int angka;
};

class Queue {
private:
    Data queue[5];  
    int front;      
    int rear;       
    int size;       
    const int MAX_SIZE = 5;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(string nama, int angka) {
        if (size == MAX_SIZE) {
            cout << "Queue penuh. Tidak bisa enqueue.\n";
            return;
        }

        rear = (rear + 1) % MAX_SIZE; 
        queue[rear].nama = nama;
        queue[rear].angka = angka;
        size++;

        cout << "Enqueued: " << nama << " - " << angka << endl;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue kosong. Tidak bisa dequeue.\n";
            return;
        }

        cout << "Dequeued: " << queue[front].nama << " - " << queue[front].angka << endl;
        front = (front + 1) % MAX_SIZE; 
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "Queue kosong.\n";
            return;
        }

        cout << "Isi Queue:\n";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % MAX_SIZE;
            cout << "- " << queue[index].nama << " : " << queue[index].angka << endl;
        }
    }
};

int main() {
    Queue q;
    int choice;
    string nama;
    int angka;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue (Tambah Data)\n";
        cout << "2. Dequeue (Hapus Data)\n";
        cout << "3. Tampilkan Queue\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;
        cin.ignore(); // Membersihkan buffer

        switch (choice) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, nama);
                cout << "Masukkan angka: ";
                cin >> angka;
                q.enqueue(nama, angka);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (choice != 0);

    return 0;
}

