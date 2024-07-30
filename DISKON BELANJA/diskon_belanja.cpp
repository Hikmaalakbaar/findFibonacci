#include <iostream>

using namespace std;

int main(){
    system("cls");
    const double hargaBajuKoko = 100000, hargaCelanaKoko = 60000, hargaSepatuAdidas = 700000;
        char beliLagi;
        int jumlahBajuKoko = 0, jumlahCelanaKoko = 0, jumlahSepatuAdidas = 0;


        long hargaAwal;
    do
    {
        system("cls");
        int pilihan, jumlahItem;
        cout << "      Toko Baju Hikmal     " << endl;
        cout << "---------------------------" << endl;
        cout << "1. Baju Koko   Rp. 100.0000" << endl;
        cout << "2. Celana Koko   Rp. 60.000" << endl;
        cout << "3. Sepatu Adidas Rp.700.000" << endl;
        cout << "---------------------------" << endl;
        cout << "Masukan pilihan anda (1-3): " << endl;
        cin >> pilihan;
        cout << "Berapa jumlah item yang anda beli : ";
        cin >> jumlahItem;
        switch (pilihan)
        {
        case 1:
            jumlahBajuKoko = jumlahItem;
            break;
        case 2:
            jumlahCelanaKoko = jumlahItem;
            break;
        case 3:
            jumlahSepatuAdidas = jumlahItem;
        default:
            cout <<"Inputan Anda tidak Valid";
            break;
        }
        cout << "Apakah anda ingin membeli lagi (Y/N)  : ";
        cin >> beliLagi;


    } while (beliLagi == 'Y' || beliLagi == 'y');

    hargaAwal = (jumlahBajuKoko*hargaBajuKoko)+
                (jumlahCelanaKoko*hargaCelanaKoko)+
                (jumlahSepatuAdidas*hargaSepatuAdidas);
    float diskon;
    if (hargaAwal > 200000 && hargaAwal <= 500000)
    {
        diskon = 0.1;
    }else if (hargaAwal > 500000 && hargaAwal <= 700000)
    {
        diskon = 0.15;
    }else if(hargaAwal > 700000){
        diskon = 0.5;
    }else{
        diskon = 0;
    }
    double hargaTotal;
    hargaTotal = hargaAwal-(hargaAwal*diskon);
    cout << endl;
    cout <<"Pembayaran anda adalah : Rp"<<hargaAwal<<endl;
    cout <<"Diskon yang anda peroleh adalah :" << diskon*100 <<"%"<< endl;
    cout <<"Total yang harus anda bayar adalah : Rp." << hargaTotal << endl;

    return 0;
}