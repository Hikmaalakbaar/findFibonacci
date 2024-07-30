#include<iostream>
using namespace std;
int main(){
int angka;
float harus;
cout << "Masukan angka: " << endl;
cin >> angka;

harus = (angka > 5) ? 5 : 1;

cout << harus;


    return 0;
}