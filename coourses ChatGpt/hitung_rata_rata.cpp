#include <iostream>

using namespace std;

int jumlahNilai;
const int Max_nilai =100;
int nilai[Max_nilai];
float rata_rata;
float total = 0;

int main(){
    cout << "Masukan berapa nilai yang ingin diinputkan : ";
    cin >> jumlahNilai;

    for (int i = 0; i < jumlahNilai; i++)
    {
        cout << "Masukan Nilai ke " << i + 1 << " : ";
        cin >> nilai[i]; 
        total += nilai[i];
    }
    cout << "Jumlah nilainya adalah "<< total << endl;

    rata_rata = total/jumlahNilai;
    cout <<"Nilai rata ratanya adalah "<< rata_rata;
    
    

    return 0;
}