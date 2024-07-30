#include <iostream>

using namespace std;

int n;
float total;

int main(){
    cout << "Masukan nilai n untuk mencari nilai faktorialnya : ";
    cin >> n;
    total = 1;
    for (int i = n; i >= 1; i--)
    {
        total = total * i;
    }
    cout << "Nilai faktorial n adalah "<< total;



    return 0;
}