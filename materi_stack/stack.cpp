#include <iostream>
#define MAX_STACK 10

using namespace std;

struct STACK{
    int top;
    char data[10];
};

STACK tumpuk;

void inisialisasi(){
    tumpuk.top = -1;
}

int isFull(){
    if(tumpuk.top == MAX_STACK-1)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(tumpuk.top == -1)
        return 1;
    else
        return 0;
}

void push(char d){
    tumpuk.top++;
    tumpuk.data[tumpuk.top]=d;
}

void pop(){
    cout <<"Data yang terambil = %\n" <<tumpuk.data[tumpuk.top];
}

void tampilStack(){
    for(int i = tumpuk.top; i >= 0; i--){
        cout <<"Data : \n" <<tumpuk.data[i];
    }
}

int main(){
    int pilih;
    do
    {
    cout <<"Menu : "<<endl;
    cout <<"1. Tambahkan Data "<<endl;
    cout <<"2. Ambil data "<<endl;
    cout <<"3. Cek isi Data "<<endl;
    cout <<"4. Cek data kosong "<<endl;
    cout <<"5. Cek data penuh "<<endl;
    cout <<"6. Keluar"<<endl;
    cout <<"Pilih : ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        push(1);
        break;
    case 2:
        pop();
        break;
    case 3:
        tampilStack();
        break;
    case 4:
        isEmpty();
        break;
    case 5:
        isFull();
        break;
    case 6:
        cout <<"Anda Keluar dari Program";
        break;
    default:
        cout <<"Inputann yang anda masukann tidak valid";
        break;
    }

    } while (pilih == 6);
    
}