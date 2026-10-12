#include <iostream>
using namespace std;

// Node untuk menyimpan data dan alamat node berikutnya
struct Node {
    int data;
    Node* next;
    Node(int nilai) : data(nilai), next(nullptr) {}
};

class Queue {
private:
    Node* frontNode;
    Node* rearNode;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return frontNode == nullptr;
    }

    // Menambahkan data ke bagian belakang antrean
    void enqueue(int nilai) {
        Node* nodeBaru = new Node(nilai);

        if (isEmpty()) {
            frontNode = rearNode = nodeBaru;
        } else {
            rearNode->next = nodeBaru;
            rearNode = nodeBaru;
        }

        cout << nilai << " berhasil ditambahkan ke antrean.\n";
    }

    // Menghapus data paling depan
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrean kosong, tidak ada data yang bisa dihapus.\n";
            return;
        }

        Node* sementara = frontNode;
        cout << "Data yang dihapus: " << sementara->data << '\n';
        frontNode = frontNode->next;

        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete sementara;
    }

    // Melihat data paling depan tanpa menghapusnya
    void peek() const {
        if (isEmpty()) {
            cout << "Antrean kosong.\n";
        } else {
            cout << "Data paling depan: " << frontNode->data << '\n';
        }
    }

    void tampilkan() const {
        if (isEmpty()) {
            cout << "Antrean kosong.\n";
            return;
        }

        cout << "Isi antrean (depan ke belakang): ";
        Node* bantu = frontNode;
        while (bantu != nullptr) {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << '\n';
    }
};

int main() {
    Queue antrean;
    int pilihan, nilai;

    do {
        cout << "\n=== BAGIAN A: QUEUE LINKED LIST ===\n"
             << "1. Enqueue (tambah data)\n"
             << "2. Dequeue (hapus data terdepan)\n"
             << "3. Peek (lihat data terdepan)\n"
             << "4. Cek isEmpty\n"
             << "5. Tampilkan antrean\n"
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
                cout << (antrean.isEmpty() ? "Antrean kosong.\n" : "Antrean tidak kosong.\n");
                break;
            case 5:
                antrean.tampilkan();
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
