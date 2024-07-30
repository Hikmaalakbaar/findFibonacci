#include <iostream>
#include <iomanip>

int main() {
    system("cls");
    // Daftar menu kopi dan harga
    const int hargaKopiSusu = 7500;
    const int hargaKopiHitam = 5000;
    const int hargaCappucino = 13000;
    const int hargaKopiLuwak = 15000;
    const int hargaCaffeLatte = 13000;

    // Inisialisasi variabel
    int pilihanMenu, jumlahKopiSusu = 0, jumlahKopiHitam = 0, jumlahCappucino = 0, jumlahKopiLuwak = 0, jumlahCaffeLatte = 0;
    char beliLagi;

    do {
        // Menampilkan menu kopi
        std::cout << "Menu Kopi:" << std::endl;
        std::cout << "1. Kopi Susu      Rp.7500" << std::endl;
        std::cout << "2. Kopi Hitam     Rp.5000" << std::endl;
        std::cout << "3. Cappucino      Rp.13000" << std::endl;
        std::cout << "4. Kopi Luwak     Rp.15000" << std::endl;
        std::cout << "5. Caffe Latte    Rp.13000" << std::endl;

        // Input pilihan menu
        std::cout << "Pilih menu kopi (1-5): ";
        std::cin >> pilihanMenu;

        // Input jumlah kopi yang ingin dibeli
        std::cout << "Masukkan jumlah kopi yang ingin dibeli: ";
        int jumlahPembelian;
        std::cin >> jumlahPembelian;

        // Menghitung jumlah kopi yang dibeli
        switch (pilihanMenu) {
            case 1:
                jumlahKopiSusu + jumlahPembelian;
                break;
            case 2:
                jumlahKopiHitam + jumlahPembelian;
                break;
            case 3:
                jumlahCappucino += jumlahPembelian;
                break;
            case 4:
                jumlahKopiLuwak += jumlahPembelian;
                break;
            case 5:
                jumlahCaffeLatte += jumlahPembelian;
                break;
            default:
                std::cout << "Pilihan tidak valid." << std::endl;
                break;
        }

        // Menanyakan apakah pengguna ingin membeli kopi lagi
        std::cout << "Apakah Anda ingin membeli kopi lagi? (Y/N): ";
        std::cin >> beliLagi;
    } while (beliLagi == 'Y' || beliLagi == 'y');

    // Menghitung total harga pembelian
    int totalHarga = (jumlahKopiSusu * hargaKopiSusu) +
                     (jumlahKopiHitam * hargaKopiHitam) +
                     (jumlahCappucino * hargaCappucino) +
                     (jumlahKopiLuwak * hargaKopiLuwak) +
                     (jumlahCaffeLatte * hargaCaffeLatte);

    // Diskon jika total pembelian melebihi Rp. 40000
    double diskon = (totalHarga > 40000) ? 0.1 : 0.0;
    double totalSetelahDiskon = totalHarga - (totalHarga * diskon);

    // Input uang yang diberikan oleh pengguna
    double uangDiberikan;
    std::cout << "Masukkan jumlah uang yang diberikan: ";
    std::cin >> uangDiberikan;

    // Menghitung kembalian
    double kembalian = uangDiberikan - totalSetelahDiskon;

    // Menampilkan struk pembayaran
    std::cout << std::fixed << std::setprecision(2); // Mengatur presisi desimal
    std::cout << "\n===== Struk Pembayaran =====" << std::endl;
    std::cout << "Kopi Susu     : " << jumlahKopiSusu << " x " << hargaKopiSusu << " = " << jumlahKopiSusu * hargaKopiSusu << std::endl;
    std::cout << "Kopi Hitam    : " << jumlahKopiHitam << " x " << hargaKopiHitam << " = " << jumlahKopiHitam * hargaKopiHitam << std::endl;
    std::cout << "Cappucino     : " << jumlahCappucino << " x " << hargaCappucino << " = " << jumlahCappucino * hargaCappucino << std::endl;
    std::cout << "Kopi Luwak    : " << jumlahKopiLuwak << " x " << hargaKopiLuwak << " = " << jumlahKopiLuwak * hargaKopiLuwak << std::endl;
    std::cout << "Caffe Latte   : " << jumlahCaffeLatte << " x " << hargaCaffeLatte << " = " << jumlahCaffeLatte * hargaCaffeLatte << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Total Harga   : " << totalHarga << std::endl;
    std::cout << "Diskon        : " << (diskon * 100) << "%" << std::endl;
    std::cout << "Total Bayar   : " << totalSetelahDiskon << std::endl;
    std::cout << "Uang Diberikan: " << uangDiberikan << std::endl;
    std::cout << "Kembalian     : " << kembalian << std::endl;
    std::cout << "=============================" << std::endl;

    return 0;
}
