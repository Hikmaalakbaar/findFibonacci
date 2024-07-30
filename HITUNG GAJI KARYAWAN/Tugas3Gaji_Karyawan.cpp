#include <iostream>
using namespace std;

int main() {
    int jumlahKaryawan;
    cout << "Masukkan jumlah karyawan: ";
    cin >> jumlahKaryawan;

    const int gajiPerJam = 300000;
    const int batasJamNormal = 120;
    const double lemburRate = 0.5;
    const double kurangJamRate = 0.75;

    int totalGaji = 0;

    for (int i = 1; i <= jumlahKaryawan; ++i) {
        int jamKerja;
        cout << "Masukkan jam kerja karyawan ke-" << i << ": ";
        cin >> jamKerja;

        if (jamKerja > batasJamNormal) {
            // Hitung lembur
            int jamNormal = batasJamNormal;
            int jamLembur = jamKerja - batasJamNormal;

            double gajiLembur = jamLembur * gajiPerJam * lemburRate;
            double gajiNormal = jamNormal * gajiPerJam;

            totalGaji += static_cast<int>(gajiNormal + gajiLembur);
        } else {
            // Hitung gaji dengan rate kurangJamRate
            double gajiKurangJam = jamKerja * gajiPerJam * kurangJamRate;
            totalGaji += static_cast<int>(gajiKurangJam);
        }
    }

    cout << "Total pengeluaran gaji perusahaan: Rp. " << totalGaji << endl;

    return 0;
}
