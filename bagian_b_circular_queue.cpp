#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int KAPASITAS = 5;
    int data[KAPASITAS];
    int frontIndex;
    int rearIndex;
    int jumlah;

public:
    CircularQueue() : frontIndex(0), rearIndex(-1), jumlah(0) {}

    bool isEmpty() const {
        return jumlah == 0;
    }

    bool isFull() const {
        return jumlah == KAPASITAS;
    }

    void enqueue(int nilai) {
        if (isFull()) {
            cout << "Circular queue penuh. Data tidak bisa ditambahkan.\n";
            return;
        }

        rearIndex = (rearIndex + 1) % KAPASITAS;
        data[rearIndex] = nilai;
        jumlah++;
        cout << nilai << " berhasil ditambahkan.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular queue kosong. Tidak ada data yang bisa dihapus.\n";
            return;
        }

        cout << "Data yang dihapus: " << data[frontIndex] << '\n';
        frontIndex = (frontIndex + 1) % KAPASITAS;
        jumlah--;

        // Mengembalikan indeks ke kondisi awal ketika antrean kosong
        if (jumlah == 0) {
            frontIndex = 0;
            rearIndex = -1;
        }
    }

    void peek() const {
        if (isEmpty()) {
            cout << "Circular queue kosong.\n";
        } else {
            cout << "Data paling depan: " << data[frontIndex] << '\n';
        }
    }

    void tampilkan() const {
        if (isEmpty()) {
            cout << "Circular queue kosong.\n";
            return;
        }

        cout << "Isi antrean (depan ke belakang): ";
        for (int i = 0; i < jumlah; i++) {
            int indeks = (frontIndex + i) % KAPASITAS;
            cout << data[indeks] << ' ';
        }
        cout << "\nJumlah data: " << jumlah << "/" << KAPASITAS << '\n';
    }
};

int main() {
    CircularQueue antrean;
    int pilihan, nilai;

    do {
        cout << "\n=== BAGIAN B: CIRCULAR QUEUE ===\n"
             << "Kapasitas antrean: 5\n"
             << "1. Enqueue (tambah data)\n"
             << "2. Dequeue (hapus data terdepan)\n"
             << "3. Peek (lihat data terdepan)\n"
             << "4. Tampilkan antrean\n"
             << "5. Cek penuh/kosong\n"
             << "0. Keluar\n"
             << "Pilihan: ";

        if (!(cin >> pilihan)) {
            cout << "Input harus berupa angka.\n";
            return 1;
        }

        switch (pilihan) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> nilai;
                antrean.enqueue(nilai);
                break;
            case 2:
                antrean.dequeue();
                break;
            case 3:
                antrean.peek();
                break;
            case 4:
                antrean.tampilkan();
                break;
            case 5:
                cout << (antrean.isEmpty() ? "Antrean sedang kosong.\n" : "Antrean tidak kosong.\n");
                cout << (antrean.isFull() ? "Antrean sedang penuh.\n" : "Antrean belum penuh.\n");
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak tersedia.\n";
        }
    } while (pilihan != 0);

    return 0;
}
