#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama;
    int prioritas; // Angka lebih kecil berarti prioritas lebih tinggi
    int urutanDatang;
    Pasien* next;

    Pasien(string n, int p, int u)
        : nama(n), prioritas(p), urutanDatang(u), next(nullptr) {}
};

class PriorityQueue {
private:
    Pasien* head;
    int nomorUrut;

public:
    PriorityQueue() : head(nullptr), nomorUrut(0) {}

    ~PriorityQueue() {
        while (head != nullptr) {
            Pasien* hapus = head;
            head = head->next;
            delete hapus;
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    // Urut berdasarkan prioritas; prioritas sama tetap FIFO.
    void enqueue(const string& nama, int prioritas) {
        Pasien* baru = new Pasien(nama, prioritas, nomorUrut++);

        if (head == nullptr || prioritas < head->prioritas) {
            baru->next = head;
            head = baru;
        } else {
            Pasien* bantu = head;

            // Pakai <= agar pasien dengan prioritas sama masuk setelah pasien
            // berprioritas sama yang sudah datang lebih dahulu (FIFO).
            while (bantu->next != nullptr &&
                   bantu->next->prioritas <= prioritas) {
                bantu = bantu->next;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }

        cout << "Pasien " << nama << " berhasil masuk antrean.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrean pasien kosong.\n";
            return;
        }

        Pasien* hapus = head;
        cout << "Pasien yang dilayani: " << hapus->nama
             << " (prioritas " << hapus->prioritas << ")\n";
        head = head->next;
        delete hapus;
    }

    void peek() const {
        if (isEmpty()) {
            cout << "Antrean pasien kosong.\n";
        } else {
            cout << "Pasien berikutnya: " << head->nama
                 << " (prioritas " << head->prioritas << ")\n";
        }
    }

    void tampilkan() const {
        if (isEmpty()) {
            cout << "Antrean pasien kosong.\n";
            return;
        }

        cout << "\nUrutan antrean pasien:\n";
        Pasien* bantu = head;
        while (bantu != nullptr) {
            cout << "- " << bantu->nama
                 << " | Prioritas: " << bantu->prioritas
                 << " | Urutan datang: " << bantu->urutanDatang + 1 << '\n';
            bantu = bantu->next;
        }
    }
};

int main() {
    PriorityQueue antrean;
    int pilihan, prioritas;
    string nama;

    do {
        cout << "\n=== BAGIAN C1: PRIORITY QUEUE LINKED LIST ===\n"
             << "Prioritas: 1 = kritis, 2 = darurat, 3 = ringan\n"
             << "1. Tambah pasien\n"
             << "2. Layani pasien berikutnya\n"
             << "3. Lihat pasien berikutnya\n"
             << "4. Tampilkan antrean\n"
             << "0. Keluar\n"
             << "Pilihan: ";

        if (!(cin >> pilihan)) {
            cout << "Input pilihan harus berupa angka.\n";
            return 1;
        }

        switch (pilihan) {
            case 1:
                cout << "Nama pasien (tanpa spasi): ";
                cin >> nama;
                cout << "Prioritas (1-3): ";
                cin >> prioritas;
                if (prioritas < 1 || prioritas > 3) {
                    cout << "Prioritas harus 1, 2, atau 3.\n";
                } else {
                    antrean.enqueue(nama, prioritas);
                }
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
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak tersedia.\n";
        }
    } while (pilihan != 0);

    return 0;
}
