#include <iostream>
using namespace std;

void generateFibonacci(int n){
    int t1 = 1, t2 = 1, nextTerm;
    cout << "Fibonacci Series : ";
    for (auto i = 1; i <= n; i++){
        cout << t1 << " ";
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}


int main(){
    int n;
    cout << "enter the number of terms : ";
    cin >> n;
    generateFibonacci(n);
    return 0;
}