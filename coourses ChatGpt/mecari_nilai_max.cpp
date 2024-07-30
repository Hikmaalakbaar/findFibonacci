#include <iostream>

using namespace std;

const int MAX_NILAI = 100;
int array[MAX_NILAI];
int nilaiArray;

int main(){

    cout << "Masukan berapa nilai yang ingin diinputkan : ";
    cin >> nilaiArray;
    for (int i = 0; i < nilaiArray; i++)
    {
        cout <<"Masukan Nilai Array yang ke- " << i+1 << " : ";
        cin >> array[i];
    }

    int max = 0;
    for (int i = 0; i < nilaiArray; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        
    }
    cout << "Nilai paling besar yang anda masukan dalam array adalah : " << max;
    



    return 0;
}