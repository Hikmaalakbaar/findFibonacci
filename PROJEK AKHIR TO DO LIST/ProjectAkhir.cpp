#include <iostream> //untuk input output
#include <fstream> // untuk operasi file
#include <vector> // untuk menggunakan vector
#include <string> // untuk menggunakan string
#include <algorithm> // untuk menggunakan sort

using namespace std; // agar tidak menulis std kembali

struct Task { // struct definition
    string description;
    bool isCompleted;
    int importance;
}; //ini mendefinisikan struktur Task, yang memiliki dua anggota: description (deskripsi tugas) dan isCompleted (status apakah tugas sudah selesai atau belum).

void saveTasksToFile(const vector<Task>& tasks, const string& filename) { // Funcution 'saveTasksToFile
    ofstream file(filename);
    if (file.is_open()) {
        for (const Task& task : tasks) {
            file << task.description << "|" << task.isCompleted << endl;
        }
        file.close();
    } else {
        cout << "Gagal membuka file." << endl;
    }
} //Fungsi ini menyimpan vektor tugas ke dalam file dengan format deskripsi|status. Jika file dapat dibuka, setiap tugas ditulis ke dalam file. Jika tidak, pesan kesalahan ditampilkan.

void loadTasksFromFile(vector<Task>& tasks, const string& filename) { // function 'loadTasksFromFile
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Task task;
            size_t pos = line.find('|');
            task.description = line.substr(0, pos);
            task.isCompleted = (line.substr(pos + 1) == "1");
            tasks.push_back(task);
        }
        file.close();
    } else {
        cout << "Gagal membuka file." << endl;
    }
} //Fungsi ini memuat tugas dari file ke dalam vektor. Setiap baris dari file dipecah menjadi deskripsi dan status, dan kemudian sebuah objek Task baru dibuat dan ditambahkan ke vektor tugas.

int main() { // Main Function
    vector<Task> toDoList;
    const string filename = "tasks.txt";

    loadTasksFromFile(toDoList, filename);

    int choice;

    while (true) {
        cout << "======== Program To-Do List =========" << endl;
        cout << "============ KELOMPOK 10 ============" << endl;
        cout << "\n       YOSI - HIKMAL - FIKKY       \n" << endl;
        cout << "=====================================" <<endl;
        cout << "| 1. Tambahkan tugas                |" << endl;
        cout << "| 2. Tampilkan daftar tugas         |" << endl;  
        cout << "| 3. Tandai tugas sebagai selesai   |" << endl;
        cout << "| 4. Hapus Tugas                    |" << endl;
        cout << "| 5. Keluar                         |" << endl;
        cout << "=====================================" << endl;
        cout << "Pilih opsi (1/2/3/4):";
        cin >> choice;

        switch (choice) {
            case 1: {
                Task task;
                cout << "Masukkan tugas: ";
                cin.ignore();
                getline(cin, task.description);
                cout << "Masukkan tingkat kepentingan (1-5, 1 paling rendah, 5 paling tinggi): ";
                cin >> task.importance;
                task.isCompleted = false;
                toDoList.push_back(task);
// Urutkan vektor berdasarkan tingkat kepentingan secara descending
                sort(toDoList.begin(), toDoList.end(), [](const Task& a, const Task& b) {
                return a.importance > b.importance;
                });
                saveTasksToFile(toDoList, filename);
                cout << "Tugas ditambahkan ke daftar." << endl;
            break;
            }

            case 2: {
                cout << "===== Daftar Tugas =====" << endl;
    // Tampilkan tugas berdasarkan tingkat kepentingan
                for (size_t i = 0; i < toDoList.size(); i++) {
                cout << i + 1 << ". " << (toDoList[i].isCompleted ? "[X] " : "[ ] ")
                << "Kepentingan: " << toDoList[i].importance << " - " << toDoList[i].description << endl;
                }
            break;
            }

            case 3: {
                int index;
                cout << "Masukkan nomor tugas yang selesai: ";
                cin >> index;
                if (index >= 1 && index <= toDoList.size()) {
                    toDoList[index - 1].isCompleted = true;
                    saveTasksToFile(toDoList, filename);
                    cout << "Tugas ditandai sebagai selesai." << endl;
                } else {
                    cout << "Nomor tugas tidak valid." << endl;
                }
                break;
            }
            case 4:{
                int index;
                cout << " Masukkan nomor tugass yang ingin dihapus";
                cin >> index;
                if (index >= 1 && toDoList.size()) {
                    toDoList.erase(toDoList.begin() + index - 1);
                    saveTasksToFile(toDoList, filename);
                    cout << "Tugas berhasil dihapus." << endl;
                }
                break;
            }
                
            case 5:
                cout << "Terima kasih! Keluar dari program." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    }

    return 0;
}
//Program utama dimulai dengan memuat tugas dari file. Kemudian, ada loop utama yang terus berjalan sampai pengguna memilih untuk keluar. Dalam loop ini, pengguna diminta untuk memilih opsi, dan switch statement digunakan untuk memproses pilihan tersebut. Opsi termasuk menambahkan tugas baru, menampilkan daftar tugas, menandai tugas sebagai selesai, atau keluar dari program