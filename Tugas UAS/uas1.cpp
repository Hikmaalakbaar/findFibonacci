#include <iostream>
#include <string>

using namespace std;


void hitungKaryawan(int banyakKaryawan){

int jamKerja[banyakKaryawan], jamLembur[banyakKaryawan], gajiLembur[banyakKaryawan], gajiTotal[banyakKaryawan];

string namaKaryawan[banyakKaryawan], tipeKaryawan[banyakKaryawan];

int gajiNormal[banyakKaryawan];

    for (int i = 0; i < banyakKaryawan; i++){
        cout << "Masukan nama karyawan : ";
        cin.ignore();
        getline(cin, namaKaryawan[i]);
        cout << "Masukan tipe karyawan : ";
        cin.ignore();
        getline(cin, tipeKaryawan[i]);
        cout << "Masukan Jam Kerja : ";
        cin >> jamKerja[i];
        cout << endl;

        
        if (tipeKaryawan[i] == "A" || tipeKaryawan[i] == "a")
        {
            if (jamKerja[i] <= 48)
            {
                gajiNormal[i] = jamKerja[i] * 50000;
                gajiTotal[i] = gajiNormal[i];
            }
                jamLembur[i] = jamKerja[i] - 48;
                gajiNormal[i] = jamKerja[i] * 50000;
                gajiLembur[i] = jamLembur[i] * 15000;
                gajiTotal[i] = gajiNormal[i] + gajiLembur[i];
            }
            
        else if (tipeKaryawan[i] == "B" || tipeKaryawan[i] == "b")
        {
            if (jamKerja[i] <= 48)
            {
                gajiNormal[i] = jamKerja[i] * 35000;
                gajiTotal[i] = gajiNormal[i];
            }
                jamLembur[i] = jamKerja[i] - 48;
                gajiNormal[i] = jamKerja[i] * 35000;
                gajiLembur[i] = jamLembur[i] * 10000;
                gajiTotal[i] = gajiNormal[i] + gajiLembur[i];
            
        }else if (tipeKaryawan[i] == "C" || tipeKaryawan[i] == "c")
        {
            if (jamKerja[i] <= 48)
            {
                gajiNormal[i] = jamKerja[i] * 20000;
                gajiTotal[i] = gajiNormal[i];
            }
                jamLembur[i] = jamKerja[i] - 48;
                gajiNormal[i] = jamKerja[i] * 20000;
                gajiLembur[i] = jamLembur[i] * 5000;
                gajiTotal[i] = gajiNormal[i] + gajiLembur[i];
            
        }
    }
    for (int i = 0; i < banyakKaryawan; i++)
    {
        cout << gajiTotal[i];
        cout << i + 1 << ". "<< namaKaryawan[i] << " TIPE " << tipeKaryawan[i] << endl;
        cout << "Dengan Jam Kerja " << jamKerja[i] << endl;
        cout << "Mendaapatkan Gaji " << "Rp. " << gajiTotal[i];
    }
}



int main(){
    int banyakKaryawan;

    cout << "Masukan Banyak Karyawan : ";
    cin >> banyakKaryawan;

    hitungKaryawan(banyakKaryawan);
    


    return 0;
}