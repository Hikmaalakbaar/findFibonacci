#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel
    string jenis_kendaraan;
    float waktu_parkir;

    // Ketentuan biaya parkirmobil
    
    float biaya_pertama_mobil = 2000;
    float biaya_selanjutnya_mobil = 1000;
    float biaya_pertama_motor = 1000;
    float biaya_selanjutnya_motor = 500;

    // Input jenis kendaraan
    cout << "Masukkan jenis kendaraan (mobil/motor): ";
    cin >> jenis_kendaraan;

    // Input waktu parkir
    cout << "Masukkan waktu parkir (jam): ";
    cin >> waktu_parkir;

    // Hitung biaya parkir
    float biaya_total;
    if (jenis_kendaraan == "mobil") {
        biaya_total = biaya_pertama_mobil + biaya_selanjutnya_mobil * (waktu_parkir - 1);
    } else if (jenis_kendaraan == "motor") {
        biaya_total = biaya_pertama_motor + biaya_selanjutnya_motor * (waktu_parkir - 1);
    } else {
        cout << "Jenis kendaraan tidak valid." << endl;
        return 1; // Keluar dari program dengan status error
    }

    // Cetak hasil biaya parkir
    cout << "Biaya parkir untuk " << jenis_kendaraan << " selama " << waktu_parkir << " jam adalah Rp. " << biaya_total << endl;

    return 0; // Program berakhir tanpa error
}
