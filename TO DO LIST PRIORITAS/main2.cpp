#include <iostream> 
#include <fstream> 
#include <string>
#include <ctime> // Untuk mengatur waktu tugas dimasukkan

using namespace std; 

const int MAX_PANJANG_TUGAS = 50; 

// Node untuk linked list
struct Node {
    string nama; 
    bool prioritas; 
    bool dilaksanakan;
    time_t waktu; // Waktu tugas dimasukkan
    Node* next;
};

// Kelas LinkedList untuk mengatur linked list
class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Menambahkan tugas ke linked list
    void tambahTugas(string nama, bool prioritas) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->prioritas = prioritas;
        newNode->dilaksanakan = false;
        newNode->waktu = time(nullptr); // Mengambil waktu saat ini
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            if (prioritas) { // Jika tugas memiliki prioritas
                newNode->next = head;
                head = newNode;
            } else { // Jika tugas biasa
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    // Mencetak semua tugas dalam linked list
    void tampilkanTugas() {
        Node* current = head;
        int nomorTugas = 1;

        cout << "*-----------------------------*" << endl;
        cout << "|          TO DO LIST         |" << endl;
        cout << "*-----------------------------*" << endl;
        while (current != nullptr) {
            cout << nomorTugas << ". ";
            if (current->prioritas) {
                cout << "[Urgent] ";
            } else {                              
                cout << "[Biasa] ";
            }
            if (current->dilaksanakan) {
                cout << "[Selesai] ";  
            } else {
                cout << "[ ] ";  
            }
            cout << current->nama;
            cout << " (Ditambahkan pada: " << ctime(&current->waktu) << ")";
            cout << endl;

            current = current->next;
            nomorTugas++;
        }
    }

    // Tandai tugas sebagai selesai
    void tandaiTugasSelesai(int nomorTugas) {
        Node* current = head;
        int nomor = 1;

        while (current != nullptr && nomor != nomorTugas) {
            current = current->next;
            nomor++;
        }

        if (current != nullptr) {
            current->dilaksanakan = true;
            cout << "Tugas berhasil ditandai sebagai selesai!" << endl;
        } else {
            cout << "Nomor tugas tidak valid." << endl;
        }
    }

    // Mengembalikan jumlah tugas dalam linked list
    int getJumlahTugas() {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Mengembalikan pointer ke head
    Node* getHead() {
        return head;
    }

    // Mencari tugas berdasarkan nama
    void cariTugas(string namaTugas) {
        Node* current = head;
        bool found = false;
        int nomorTugas = 1;

        cout << "*-----------------------------*" << endl;
        cout << "|       HASIL PENCARIAN       |" << endl;
        cout << "*-----------------------------*" << endl;
        while (current != nullptr) {
            if (current->nama.find(namaTugas) != string::npos) {
                found = true;
                cout << nomorTugas << ". ";
                if (current->prioritas) {
                    cout << "[Urgent] ";
                } else {                              
                    cout << "[Biasa] ";
                }
                if (current->dilaksanakan) {
                    cout << "[Selesai] ";  
                } else {
                    cout << "[ ] ";  
                }
                cout << current->nama;
                cout << " (Ditambahkan pada: " << ctime(&current->waktu) << ")";
                cout << endl;
            }
            current = current->next;
            nomorTugas++;
        }

        if (!found)
            cout << "Tidak ditemukan tugas dengan nama \"" << namaTugas << "\"" << endl;
    }

    // Destructor untuk menghapus linked list
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }
};

// Fungsi untuk menambah tugas ke linked list
void tambahTugas(LinkedList &toDoList) { 
    string namaTugas; 
    bool prioritas;

    cout << "Masukkan nama tugas baru: "; 
    cin.ignore();
    getline(cin, namaTugas);

    char pilihanPrioritas; 
    do {
        cout << "Apakah tugas ini memiliki prioritas? (y/n): "; 
        cin >> pilihanPrioritas;
        if (pilihanPrioritas == 'y' || pilihanPrioritas == 'Y') {
            prioritas = true;
        } else if (pilihanPrioritas == 'n' || pilihanPrioritas == 'N') {
            prioritas = false;
        } else {
            cout << "Input tidak valid. Silakan masukkan 'y' atau 'n'." << endl;
        }
    } while (pilihanPrioritas != 'y' && pilihanPrioritas != 'Y' && pilihanPrioritas != 'n' && pilihanPrioritas != 'N');

    toDoList.tambahTugas(namaTugas, prioritas);

    cout << "Tugas berhasil ditambahkan!" << endl;
    system("pause");
}

// Fungsi untuk menampilkan to-do list dari linked list
void tampilkanToDoList(LinkedList &toDoList) {
    int jumlahTugas = toDoList.getJumlahTugas();

    if (jumlahTugas == 0) {
        cout << "To-do list kosong." << endl;
    } else {
        toDoList.tampilkanTugas();

        char konfirmasi;
        cout << "Apakah Anda ingin mencetak to-do list ke file? (y/n): ";
        cin >> konfirmasi;
        cin.ignore(); // Membersihkan buffer input

        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            ofstream file("to_do_list.txt");

            if (file.is_open()) {
                toDoList.tampilkanTugas();
                file.close();
                cout << "To-do list berhasil dicetak ke file to_do_list.txt" << endl;
                system("pause");
            } else {
                cout << "Gagal membuka file untuk mencetak." << endl;
            }
        }

        cout << "Apakah Anda ingin mencari tugas? (y/n): ";
        cin >> konfirmasi;
        cin.ignore(); // Membersihkan buffer input

        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            string namaTugas;
            cout << "Masukkan nama tugas yang ingin dicari: ";
            cin.ignore(); // Membersihkan buffer input
            getline(cin, namaTugas);
            toDoList.cariTugas(namaTugas);
        }
    }
}

// Fungsi untuk menandai tugas sebagai selesai
void tandaiTugasSelesai(LinkedList &toDoList) {
    int nomorTugas;
    int jumlahTugas = toDoList.getJumlahTugas();

    if (jumlahTugas == 0) {
        cout << "To-do list kosong." << endl;
    } else {
        toDoList.tampilkanTugas();

        cout << "Masukkan nomor tugas yang sudah selesai: ";
        cin >> nomorTugas;

        if (nomorTugas >= 1 && nomorTugas <= jumlahTugas) {
            toDoList.tandaiTugasSelesai(nomorTugas);
        } else {
            cout << "Nomor tugas tidak valid." << endl;
        }
    }
}

int main() {
    LinkedList toDoList;
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
                tambahTugas(toDoList);
                break;
            case 2:
                tampilkanToDoList(toDoList);
                break;
            case 3:
                tandaiTugasSelesai(toDoList);
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
