#include <iostream> 
#include <fstream> 
#include <string>


using namespace std; 

const int MAX_TUGAS = 100;
const int MAX_PANJANG_TUGAS = 50; 


struct Tugas {
    string nama; 
    bool prioritas; 
    bool dilaksanakan;
};


void tambahTugas(Tugas toDoList[MAX_TUGAS], int &jumlahTugas) { 
    Tugas tugasBaru; 
    cout << "Masukkan nama tugas baru: "; 


    cin.ignore();  
    getline(cin, tugasBaru.nama);


    char pilihanPrioritas; 
    do {
        cout << "Apakah tugas ini memiliki prioritas? (y/n): "; 
        cin >> pilihanPrioritas;
        if (pilihanPrioritas == 'y' || pilihanPrioritas == 'Y') {
            tugasBaru.prioritas = true;
        } else if (pilihanPrioritas == 'n' || pilihanPrioritas == 'N') {
            tugasBaru.prioritas = false;
        } else {
            cout << "Input tidak valid. Silakan masukkan 'y' atau 'n'." << endl;
        }
    } while (pilihanPrioritas != 'y' && pilihanPrioritas != 'Y' && pilihanPrioritas != 'n' && pilihanPrioritas != 'N');


    if (jumlahTugas < MAX_TUGAS) {
    
        if (tugasBaru.prioritas) {
            int posisiMasuk = 0;

            
            while (posisiMasuk < jumlahTugas && toDoList[posisiMasuk].prioritas) {
                posisiMasuk++;
            }

            for (int i = jumlahTugas; i > posisiMasuk; --i) {
                toDoList[i] = toDoList[i - 1];
            }

            toDoList[posisiMasuk] = tugasBaru;  
        } else {
        
            toDoList[jumlahTugas] = tugasBaru;
        }

        jumlahTugas++;
        cout << "Tugas berhasil ditambahkan!" << endl;
        system("pause");
    } else {
        cout << "Maaf, to-do list penuh." << endl;
    }
}




void tampilkanToDoList(const Tugas toDoList[MAX_TUGAS], int jumlahTugas) {
	
    if (jumlahTugas == 0) {
        cout << "To-do list kosong." << endl;
    } else {
        system ("cls");
        cout << "*-----------------------------*" <<endl;
		cout << "|          TO DO LIST         |" <<endl;
		cout << "*-----------------------------*" <<endl;
        for (int i = 0; i < jumlahTugas; ++i) {
            cout << i + 1 << ". ";
            if (toDoList[i].prioritas) {
                cout << "[Urgent] ";
            } else {                              
                cout << "[Biasa] ";
            }
            if (toDoList[i].dilaksanakan) {
                cout << "[Selesai] ";  
            } else {
                cout << "[ ] ";  
            }
            cout << toDoList[i].nama << endl;
        }

        
        char konfirmasi;
        cout << "Apakah Anda ingin mencetak to-do list ke file? (y/n): ";
        cin >> konfirmasi;

        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            ofstream file("to_do_list.docs");

            if (file.is_open()) {
                file << "*-----------------------------*" <<endl;
				file << "|          TO DO LIST         |" <<endl;
				file << "*-----------------------------*" <<endl;
                for (int i = 0; i < jumlahTugas; ++i) {
                    file << i + 1 << ". ";
                    if (toDoList[i].prioritas) {
                        file << "[Urgent] ";
                    } else {
                        file << "[Biasa] ";
                    }
                    if (toDoList[i].dilaksanakan) {
                        file << "[Selesai] ";  
                    } else {
                        file << "[ ] "; 
                    }
                    file << toDoList[i].nama << endl;
                }
                file.close();
                cout << "To-do list berhasil dicetak ke file to_do_list.docs" << endl;
                system ("pause");
            } else {
                cout << "Gagal membuka file untuk mencetak." << endl;
            }
        }
    }
}


void tandaiTugasSelesai(Tugas toDoList[MAX_TUGAS], int jumlahTugas) {
    int nomorTugas;
    
    system ("cls");
    cout << "*-----------------------------*" <<endl;
	cout << "|          TO DO LIST         |" <<endl;
	cout << "*-----------------------------*" <<endl;
        for (int i = 0; i < jumlahTugas; ++i) {
            cout << i + 1 << ". ";
            if (toDoList[i].prioritas) {
                cout << "[Urgent] ";
            } else {
                cout << "[Biasa] ";
            }
            if (toDoList[i].dilaksanakan) {
                cout << "[Selesai] "; 
            } else {
                cout << "[ ] "; 
            }
            cout << toDoList[i].nama << endl;
    	}
    cout << endl;
    cout << "Masukkan nomor tugas yang sudah selesai: ";
    cin >> nomorTugas;

    if (nomorTugas >= 1 && nomorTugas <= jumlahTugas) {
        toDoList[nomorTugas - 1].dilaksanakan = true;
        cout << "Tugas berhasil ditandai sebagai selesai!" << endl;
    } else {
        cout << "Nomor tugas tidak valid." << endl;
    }
}

int main() {
    Tugas toDoList[MAX_TUGAS];
    int jumlahTugas = 0;
    int pilihan;

    do {
        system("cls");
        cout << "*------------------------------*" <<endl;
        cout << "|    PROGRAM C++ TO DO LIST    |" <<endl;
        cout << "*------------------------------*" <<endl;
        cout << "| 1. Tambah Tugas              |\n";
        cout << "| 2. Tampilkan To-do List      |\n";
        cout << "| 3. Tandai Tugas Selesai      |\n";
        cout << "| 4. Keluar                    |\n";
        cout << "*------------------------------*" <<endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahTugas(toDoList, jumlahTugas);
                break;
            case 2:
                tampilkanToDoList(toDoList, jumlahTugas);
                break;
            case 3:
                tandaiTugasSelesai(toDoList, jumlahTugas);
                break;
            case 4:
                cout << "Program selesai. Selamat tinggal!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}


