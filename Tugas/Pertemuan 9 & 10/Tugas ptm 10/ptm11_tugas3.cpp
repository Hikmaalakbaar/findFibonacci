#include <iostream>
using namespace std;

void HitungLuasSegitiga()
{
    int alas;
    int tinggi;
    float a = 0.5;
    float luas;
    cout << "Masukkan Alas segitiga dalam ukuran cm" << endl;
    cin >> alas;
    cout << "Masukkan tinggi segitiga dalam uuran cm" << endl;
    cin >> tinggi;
    luas = a * alas * tinggi;
    cout << "Luas segitiga anda adalah" << luas << " cm"<<endl;
}

void HitungLuasPersegiPanjang()
{
    int Luas, Panjang, Lebar;
    cout << "Masukkan Panjang Bangun" << endl;
    cin >> Panjang;
    cout << "Masukkan Lebar Bangun" << endl;
    cin >> Lebar;
    Luas = Panjang*Lebar;
    cout << "Luas Persegi Panjang Anda adalah " << Luas <<" cm" << endl;
}

void HitungLuasLingkaran()
{
    float JariJari;
    float luas, Phi = 3.14;
    cout << "Masukkan Jari Jari Lingkaran" << endl;
    cin >> JariJari;
    luas = JariJari*Phi;
    cout << " Luas Lingkaran Anda adalah " << luas << " cm"<< endl;
}
int main()
{
    int pilihan;
    do
    {


    
cout << "Menu Hitung luas Bangun"<<  endl;
cout << "1. Menghitung Luas Segitiga" << endl;
cout << "2. Menghitung Luas Persegi Panjang" << endl;
cout << "3. Menghitung Luas Lingkaran"  << endl;
cout << "4. Keluar dari Menu";
cin >> pilihan;
switch (pilihan)
{
case 1:
    HitungLuasSegitiga();
    break;
case 2:
    HitungLuasPersegiPanjang();
    break;
case 3:
    HitungLuasLingkaran();
    break;
case 4:
    cout <<"Anda keluar dari Menu" <<endl;
    break;
default:
    cout << "Inputan yang anda masukan tidak valid";
    break;
}
    } while (pilihan != 4);

    return 0;
}