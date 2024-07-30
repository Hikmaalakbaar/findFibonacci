#include <iostream>

void hitungBiayaParkir(int jenisKendaraan, int waktuParkir) {
    int biayaAwal;
    int biayaPerJam;

    // Tentukan biaya awal dan biaya per jam berdasarkan jenis kendaraan
    if (jenisKendaraan == 1) { // Mobil
        biayaAwal = 2000;
        biayaPerJam = 1000;
    } else if (jenisKendaraan == 2) { // Motor
        biayaAwal = 1000;
        biayaPerJam = 500;
    } else {
        std::cout << "Jenis kendaraan tidak valid." << std::endl;
        return;
    }

    // Hitung biaya total
    int biayaTotal = biayaAwal + biayaPerJam * (waktuParkir - 1);

    // Output hasil
    std::cout << "Biaya parkir untuk kendaraan jenis ";
    std::cout << (jenisKendaraan == 1 ? "mobil" : "motor") << " adalah: ";
    std::cout << biayaTotal << " rupiah." << std::endl;
}

int main() {
    int jenisKendaraan;
    int waktuParkir;

    // Input jenis kendaraan
    std::cout << "Pilih jenis kendaraan (1 untuk mobil, 2 untuk motor): ";
    std::cin >> jenisKendaraan;

    // Input waktu parkir
    std::cout << "Masukkan waktu parkir (dalam jam): ";
    std::cin >> waktuParkir;

    // Hitung biaya parkir
    hitungBiayaParkir(jenisKendaraan, waktuParkir);

    return 0;
}
