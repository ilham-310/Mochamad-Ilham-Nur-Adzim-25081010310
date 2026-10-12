#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Pasien {
    string nama;
    int prioritas;
    int nomorKedatangan;
};

// priority_queue mengambil elemen dengan prioritas "terbesar" menurut
// pembanding. Prioritas angka kecil harus didahulukan; jika sama,
// nomor kedatangan lebih kecil (datang lebih awal) didahulukan.
struct BandingPasien {
    bool operator()(const Pasien& a, const Pasien& b) const {
        if (a.prioritas != b.prioritas) {
            return a.prioritas > b.prioritas;
        }
        return a.nomorKedatangan > b.nomorKedatangan;
    }
};

int main() {
    priority_queue<Pasien, vector<Pasien>, BandingPasien> antrean;
    int pilihan;
    int nomorKedatangan = 0;

    do {
        cout << "\n=== BAGIAN C2: SIMULASI ANTREAN IGD (STL) ===\n"
             << "Prioritas: 1 = kritis, 2 = darurat, 3 = ringan\n"
             << "1. Daftarkan pasien\n"
             << "2. Layani pasien berikutnya\n"
             << "3. Lihat pasien berikutnya\n"
             << "4. Jumlah pasien dalam antrean\n"
             << "0. Keluar\n"
             << "Pilihan: ";

        if (!(cin >> pilihan)) {
            cout << "Input pilihan harus berupa angka.\n";
            return 1;
        }

        switch (pilihan) {
            case 1: {
                Pasien p;
                cout << "Nama pasien (tanpa spasi): ";
                cin >> p.nama;
                cout << "Prioritas (1-3): ";
                cin >> p.prioritas;

                if (p.prioritas < 1 || p.prioritas > 3) {
                    cout << "Prioritas harus 1, 2, atau 3.\n";
                    break;
                }

                p.nomorKedatangan = nomorKedatangan++;
                antrean.push(p);
                cout << "Pasien " << p.nama << " berhasil didaftarkan.\n";
                break;
            }
            case 2:
                if (antrean.empty()) {
                    cout << "Belum ada pasien dalam antrean.\n";
                } else {
                    Pasien p = antrean.top();
                    antrean.pop();
                    cout << "Melayani pasien: " << p.nama
                         << " (prioritas " << p.prioritas << ")\n";
                }
                break;
            case 3:
                if (antrean.empty()) {
                    cout << "Belum ada pasien dalam antrean.\n";
                } else {
                    const Pasien& p = antrean.top();
                    cout << "Pasien berikutnya: " << p.nama
                         << " (prioritas " << p.prioritas << ")\n";
                }
                break;
            case 4:
                cout << "Jumlah pasien menunggu: " << antrean.size() << '\n';
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
