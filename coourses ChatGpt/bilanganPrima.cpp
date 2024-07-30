#include <iostream>
using namespace std;

int main() {
    int bilangan;
    bool prima = true;

    cout << "Masukkan sebuah bilangan bulat positif: ";
    cin >> bilangan;

    if (bilangan <= 1) {
        prima = false;
    } else {
        for (int i = 2; i * i <= bilangan; ++i) {
            if (bilangan % i == 0) {
                prima = false;
                break;
            }
        }
    }

    if (prima) {
        cout << bilangan << " adalah bilangan prima." << endl;
    } else {
        cout << bilangan << " bukan bilangan prima." << endl;
    }

    return 0;
}
