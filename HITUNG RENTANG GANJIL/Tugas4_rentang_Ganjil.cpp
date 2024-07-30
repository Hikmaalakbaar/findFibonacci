#include <iostream>

int main() {
    // Deklarasi variabel
    int batasBawah, batasAtas;

    // Input batas rentang dari pengguna
    std::cout << "Masukkan batas bawah rentang: ";
    std::cin >> batasBawah;

    std::cout << "Masukkan batas atas rentang: ";
    std::cin >> batasAtas;

    // Validasi rentang
    if (batasBawah > batasAtas) {
        std::cout << "Batas bawah harus kurang dari atau sama dengan batas atas." << std::endl;
        return 1; // Keluar dari program dengan kode error
    }

    // Hitung jumlah bilangan ganjil dalam rentang
    int jumlahGanjil = 0;
    for (int i = batasBawah; i <= batasAtas; ++i) {
        if (i % 2 != 0) {
            // Bilangan ganjil
            jumlahGanjil++;
        }
    }

    // Output hasil
    std::cout << "Jumlah bilangan ganjil dalam rentang ";
    std::cout << batasBawah << " sampai " << batasAtas << " adalah: ";
    std::cout << jumlahGanjil << std::endl;

    return 0;
}
