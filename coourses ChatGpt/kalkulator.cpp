#include <iostream>
#include <cstring>

using namespace std;

int bil1, bil2;
float total;
char tanda;

int main(){
    cout <<"Masukan bilangan bulat pertama : ";
    cin >>bil1;
    cout <<"Masukan bilangan bulat kedua : ";
    cin >>bil2;
    cout << "Masukan operator yang ingin digunakan (+, -, *, /) : ";
    cin >> tanda;

    switch (tanda)
    {
    case '+':
        total = bil1 + bil2;
        break;
    case '-':
        total = bil1 - bil2;
        break;
    case '*':
        total = bil1 * bil2;
        break;
    case '/':
        total = bil1 / bil2;
        break;
    default:
        cout <<"Operator yang anda masukan tidak valid ";
        break;
    }
    cout <<"Totalnya adalah " << total;
    return 0;
}