#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Pegawai {
public:
    string nama;
    int jamKerja;
    int honor;
    int honorLembur;
    int totalHonor;
    string tanggal;

    Pegawai() {
        nama = "";
        jamKerja = 0;
        honor = 25000;
        honorLembur = 0;
        totalHonor = 0;
        tanggal = "";
    }

    void input(int nomor) {
        cout << "Data ke-" << nomor << endl;
        cout << "Masukkan nama pegawai: ";
        cin >> nama;
        cout << "Masukkan jam kerja: ";
        cin >> jamKerja;
        cout <<"\n\n";
    }

    void hitungHonor() {
        honorLembur = jamKerja - 8;
        if (honorLembur > 0) {
            honorLembur *= 1500;
        }
        totalHonor = honor * jamKerja + honorLembur;
    }

    void cetak(int nomor) {
        cout << setw(5) << nomor << setw(15) << nama << setw(15) << honor << setw(15) << jamKerja << setw(20) << honorLembur << setw(15) << totalHonor << endl;
    }
};

int main() {
    // Membaca jumlah pegawai dan tanggal input
    int jumlahPegawai;
    string tanggalInput;

    cout << "PT. Meriang Gembira\n\n";
    cout << "Jumlah         : ";
    cin >> jumlahPegawai;
    cout << "Tanggal Input  : ";
    cin >> tanggalInput;
    cout <<"-----------------------------------------------------------\n";

    // Membaca data pegawai
    Pegawai* pegawai = new Pegawai[jumlahPegawai];
    for (int i = 0; i < jumlahPegawai; i++) {
        pegawai[i].input(i + 1);

    }

    // Menghitung total gaji pegawai
    int totalHonorPegawai = 0;
    for (int i = 0; i < jumlahPegawai; i++) {
        pegawai[i].hitungHonor();
        totalHonorPegawai += pegawai[i].totalHonor;
    }

    cout << "PT. Meriang Gembira\n";
    cout << "Tanggal Input  : " <<tanggalInput;
    cout << "\n\n";
    // Mencetak header
    cout << "======================================================================================\n";
    cout << setw(5) << "Nomor" << setw(15) << "Nama Pegawai" << setw(15) << "Honor" << setw(15) << "Jam Kerja" << setw(20) << "Honor Lembur" << setw(15) << "Total Honor" << endl;
    cout << "======================================================================================\n";
    // Mencetak data pegawai
    for (int i = 0; i < jumlahPegawai; i++) {
        pegawai[i].cetak(i + 1);
    }

    // Mencetak total gaji pegawai
    cout << "======================================================================================\n";
    cout << "Total Honor Pegawai Sebesar " << setw(57) << totalHonorPegawai << endl;

    // Menghapus array pegawai
    delete[] pegawai;

    return 0;
}