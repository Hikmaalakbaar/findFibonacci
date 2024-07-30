#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int nomor = 1; 
int banyakData;

char perhitungan(double nilaiUAS, double nilaiUTS) {
    double nilaiHasil = (nilaiUAS * 0.4) + (nilaiUTS * 0.6);

    if (nilaiHasil >= 80) {
        return 'A';
    } else if (nilaiHasil >= 70) {
        return 'B';
    } else if (nilaiHasil >= 56) {
        return 'C';
    } else if (nilaiHasil >= 47) {
        return 'D';
    } else {
        return 'E';
    }
}

int main() {
    cout << "Masukkan banyak data: ";
    cin >> banyakData;

    string namaMahasiswa[banyakData];
    double nilaiUTS[banyakData];
    double nilaiUAS[banyakData];

    for (int i = 0; i < banyakData; i++) {
        cout << "Masukkan nama mahasiswa " << i + 1 << ": ";
        cin.ignore();
        getline(cin, namaMahasiswa[i]);
        cout << "Masukkan nilai UTS untuk " << namaMahasiswa[i] << ": ";
        cin >> nilaiUTS[i];
        cout << "Masukkan nilai UAS untuk " << namaMahasiswa[i] << ": ";
        cin >> nilaiUAS[i];
        cout << endl;
    }

    cout << "-------------------------------------------------------------------------\n";
    cout << "No | Nama Mahasiswa | Nilai UTS | Nilai UAS | Nilai Akhir | Nilai Huruf |\n";
    cout << "-------------------------------------------------------------------------\n";

    for (int i = 0; i < banyakData; i++) {
        double nilaiAkhir = (nilaiUAS[i] * 0.4) + (nilaiUTS[i] * 0.6);
        char nilaiHuruf = perhitungan(nilaiUAS[i], nilaiUTS[i]);

        cout << setw(2) << nomor++ << ". ";
        cout << left << setw(5) << " ";
        cout << left << setw(5) << namaMahasiswa[i];
        cout << right << setw(15) << nilaiUTS[i] << setw(13) << nilaiUAS[i] << setw(13) << nilaiAkhir << setw(10) << nilaiHuruf << endl;
    }

    
    cout << "-------------------------------------------------------------------------\n";

    return 0;
}