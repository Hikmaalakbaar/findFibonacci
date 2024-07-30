#include <iostream>
using namespace std;

int main() {
    int i = 1, bil;
    cout << "Masukan nilai terbesar rentang bilang : ";
    cin >> bil;

    while (i <= bil) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
        i++;
    }


    return 0;
}
