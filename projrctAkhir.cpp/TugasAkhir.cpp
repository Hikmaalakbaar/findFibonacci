#include <iostream> //Library untuk Input dan Output cin...
#include <fstream> 
#include <string> //Library untuk type dataa String
// #include <conio.h>
using namespace std; //untuk tidak menampilkan std kembali

const int MAX_TUGAS = 100; //Deklarasi Variabel MAX_TUGAS
const int MAX_PANJANG_TUGAS = 50; //Deklarasi Variabel MAX_PANJANG_TUGAS

// Struktur untuk menyimpan informasi tugas
struct Tugas { //Membuat type data baru yang dapat menggabungkan berbagai jenis type data kedalam satu entitas yang disebut struktur 
    string nama; //ini merupakana anggota (field) dari struct bertipe data string dan dinamakan nama berfungsi untuk menyimpan informasi tentang nama tugas
    bool prioritas; //anggota struct bertipe data bool dan dinamakn prioritas. anggota inni digunakan untuk menentukan apakah suatu tugas memiliki suatu prioritas atau tidak
    bool dilaksanakan; //ini adalah anggota struct bertipe data bool dan dinamakan dilaksanakan. anggota ini digunakan untuk menandai apakah suatu tugas sudah dilaksanakan atau belum. jika bernilai true aka sudah, jika bernilai false maka belum
};
// Fungsi untuk menambahkan tugas ke dalam to-do list
void tambahTugas(Tugas toDoList[MAX_TUGAS], int &jumlahTugas) { //ini adalah definisi fungsi 'tambahTugas'. Fungsi ini menerima dua parameter, yaitu sebuah array 'toDoList'  berisi tugas tugas dan sebuah variabel 'jumlahTugas' yang menyimpan jumlah tugas saat ini. Fungsi ini tidak mengembalikan nilai 'void'
    Tugas tugasBaru; // membuat variabel 'tugasBaru' dengan tipe data 'Tugas'. ini digunakan untuk menyimpan informasi tentang tugas baru yang akan ditambahkan
    cout << "Masukkan nama tugas baru: "; //menampilkan pesan ke layar meminta pengguna atau user untuk memasukkan nama tugas baru.
    cin.ignore();  // Membersihkan Buffer input. ini berguna untuk menghindari masalah bacaan yang tidak diinginkan karena masih ada karakter newline (\n) atau carriage return (\r) dalam buffer setelah pengguna memberikan input sebelumnya.
    getline(cin, tugasBaru.nama); //Menggunakan 'getline' untuk membaca satu baris teks input pengguna dan menyimpannya ke dalam anggota 'nama' dari variabel 'tugasBaru'.
    //Fungsi ini pada dasarnya meminta pengguna untuk memasukkan nama tugas baru, membersihkan Buffer input, dan kemudian menggunakan 'getline' untuk membaca input pengguna (sebagai nama tugas) dan menyimpannya dalam variabel 'tugasBaru.nama'

    // Meminta input untuk prioritas
    char pilihanPrioritas; // Mendekllarasi variabel 'pilihanPrioritas' sebagai tipe data char. Variabel ini digunakan untuk menyimpan pilihan pengguna apakah tugas memiliki prioritas atau tidak.
    do { // Memulai konstruksi loop 'do-while'. ini berarti blok kode di dalamnya akan dijalankan setidaknya satu kali, dan kemudian akan diulang selama kondisi di bagian 'while' bernilai true.
        cout << "Apakah tugas ini memiliki prioritas? (y/n): "; // Menampilkan pesan ke layar meminta pengguna untuk memilih apakah tugas memiliki prioritas atau tidak.
        cin >> pilihanPrioritas; // Membaca input pengguna dan menyimpannya ke dalam variabel 'pilihanPrioritas'
        if (pilihanPrioritas == 'y' || pilihanPrioritas == 'Y') { // Mengevaluasi apakah pengguna memilih 'y' atau 'Y' (ya) untuk menetapkan prioritas tugas.
            tugasBaru.prioritas = true; // Jika pengguna memilih 'y' atau 'Y', maka variabel 'prioritas' pada 'tugasBaru' diatur menjadi true.
        } else if (pilihanPrioritas == 'n' || pilihanPrioritas == 'N') { // Jika pengguna memilih 'n' atau 'N' (tidak) untuk prioritas tugas.
            tugasBaru.prioritas = false; //Jika engguna memilih 'n' atau 'N' , maka variabel 'prioritas' pada 'tugasBaru' diatur menjaddi 'false'.
        } else { // Bagian ini menangani kondisi jika input pengguna tidak valid, yaitu jika bukan 'y' atau 'n'
            cout << "Input tidak valid. Silakan masukkan 'y' atau 'n'." << endl; // Menampilkan pesan kesalahan jika input tidak valid.
        }
    } while (pilihanPrioritas != 'y' && pilihanPrioritas != 'Y' && pilihanPrioritas != 'n' && pilihanPrioritas != 'N'); //Melanjutkan Loop 'do-while' sampai pengguna memasukkan input yang valid, yaitu 'y' 'Y' 'n' 'N'. Jika input masih tidak valid, loop akan terus diulang.

    // Menambahkan tugas baru ke dalam to-do list
    if (jumlahTugas < MAX_TUGAS) { // Mengavulasi apakah jumlah tugas saat ini ('jumlahTugas') lebih kecil dari batasan maksimum tugas ('MAX_TUGAS'). Ini memeriksa apakah masih ada temmpat untuk menambahkan tugas baru dalam array 'toDoList'.
        // Menggeser tugas yang ada jika tugas baru memiliki prioritas urgent
        if (tugasBaru.prioritas) { // Mengevaluasi apakah tugas baru memiliki prioritas (urgent). Jika iya, maka blok kodde di dalamnya akan dijalankan.
            int posisiMasuk = 0; //Mendeklarasi variabel 'posisiMasuk' dan menginisialisasinya dengan nilai 0. Variabel ini akan digunakan untuk menentukan posisi masuk tugas baru dengan prioritas urgent.
            // Mencari posisi masuk yang tepat untuk tugas baru dengan prioritas urgent
            while (posisiMasuk < jumlahTugas && toDoList[posisiMasuk].prioritas) { // Membuat Loop while unttuk mencari posisi masuk yang tepat untuk tugas baru dengan prioritas urgent. loop ini akan terus berjalan selama 'posisiMasuk' kurang dari 'jumlahTugas' dan tugas pada posisi tersebut memiliki prioritas.
                posisiMasuk++; // Menaikan nilai 'posisiMasuk' untuk melanjutkan pencarian posisi masuk.
            }

            // Menggeser tugas yang ada untuk memberikan tempat pada tugas baru
            for (int i = jumlahTugas; i > posisiMasuk; --i) { // Membuat Loop for untuk menggeser tugas yang sudah ada ke posisi yang lebih tinggi dalam array, memberikan ruang untuk tugas baru dengan prioritas urgent.
                toDoList[i] = toDoList[i - 1]; // Menggeser tugas ke posisi yang lebih tinggi.
            }

            toDoList[posisiMasuk] = tugasBaru;  // Menempatkan tugas baru dengan prioritas urgent pada posisi yang tepat.
        } else { // Bagian ini akan dijalankan jika tugas baru tidak memiliki prioritas urgent.
            // Jika tidak urgent, tambahkan ke akhir
            toDoList[jumlahTugas] = tugasBaru; // Menambahkan tugas baru ke ahir Array 'toDoList'.
        }

        jumlahTugas++; // Menaikkan nilai 'jumlahTugas' untuk mencerminkan penambahan tugas baru.
        cout << "Tugas berhasil ditambahkan!" << endl; // Menampikan pesan ke layar bahwa tugas berasil ditambahkan.
        system("pause"); // Menahan esekusi program sehingga pesan bisa terlihat sebelum program selesai.
    } else { // Bagian ini akan dijalankan jika jumlah tugas sudah mencapai batas maksimum
        cout << "Maaf, to-do list penuh." << endl; // Menampilkan pesan ke layar bahwa to-do list sudah penuh.
    }
}




// Fungsi untuk menampilkan seluruh to-do list dan mencetak ke file
// fungsi tampilkanToDoList
void tampilkanToDoList(const Tugas toDoList[MAX_TUGAS], int jumlahTugas) { // Ini adalah deklarasi fungsi 'tampilkanToDoList'. Fungsi ini menerima dua parameter Array 'toDoList' yang berisi tugas tugas dan jumlah tugas saat ini ('jumlahTugas'). Fungsi ini tidak mengembalikan nilai ('void') dan ditandai sebagai konstan ('const'), yang berarti fungsi ini tidak akan mengubah nilai parameter 'toDoList'.
	
    if (jumlahTugas == 0) { // Memeriksa apakah jumlah tugas saat ini adalah 0, yang berarti tidak ada tugas dalam to-do list.
        cout << "To-do list kosong." << endl; // Menampilkan pesan ke layar bahwa to-do list kosong jika tidak ada tugas.
    } else { // Blok ini akan dijalankan jika ada tugas dalam to-do list.
    	system ("cls"); // Membersihkan layar. Ini digunakan untuk memberikan tampilan yang bersih sebelum menampilkan to-do list. harap dicatat bahwa penggunaan 'system("cls")' bersifat sisem-dependent dan mungkin tidak berfungsi pada semua platform.
        cout << "\t\t\t*-----------------------------*" <<endl; // Menampilkan Baris Pemisah
		cout << "\t\t\t|          TO DO LIST         |" <<endl; 
		cout << "\t\t\t*-----------------------------*\n\n" <<endl;
        for (int i = 0; i < jumlahTugas; ++i) { // Membuat Loop 'for' untuk mengiterasi melalui setiap tugas dalam array 'toDoList'.
            cout << i + 1 << ". "; // Menampilakn nomor urutan tugas, dimulai dari 1.
            if (toDoList[i].prioritas) { // Mengevaluasi apakah tugas memiliki prioritas atau tidak.
                cout << "[Urgent] "; // Jika tugas memiliki prioritas, Maka akan menampilkan label "[Urgent]".
            } else { // Blok ini akan dijalankan jika tugas tidak memiliki prioritas.
                cout << "[Biasa] "; // Menampilkan label "[Biasa]" untuk menandai bahwa tugas belum dilaksanakan.
            }
            if (toDoList[i].dilaksanakan) { // Mengevaluasi apakah tugas sudah dilaksanakan atau belum.
                cout << "[Selesai] ";  // Tandai sebagai sudah dilaksanakan
            } else { // Blok ini akan dijalankan jika tugas belum dilaksanakan 
                cout << "[ ] ";  // Tandai sebagai belum dilaksanakan
            }
            cout << toDoList[i].nama <<"\n"<< endl; // Menampilkan nama tugas
        } 

        // Meminta konfirmasi untuk mencetak ke file
        char konfirmasi; // emndeklarassi variabel yang bernama konfirmasi. Variabel ini akan digunakan untuk menyimpan konfirmasi pengguna apakah ingin mencetak to-do list ke file atau tidak
        cout << "Apakah Anda ingin mencetak to-do list ke file? (y/n): "; // Menampilkan pssan ke layar meminta konfirmasi pengguna.
        cin >> konfirmasi; // Membaca input pengguna dan menyimpannya kedalam variabel 'konfirmasi'.

        if (konfirmasi == 'y' || konfirmasi == 'Y') { // Mengevaluasi apakah pengguna mengkonfirmasi untuk mencetak to-do list ke file. Jika ya, blok kode di dalamnya akan dijalankan.
            ofstream file("to_do_list.txt"); // Membuka file dengan nama "to_do_list.txt" untuk penulisan. Jia file tidak ada, akan dibuat file baru.

            if (file.is_open()) { // Memeriksa apakah file berhasil dibuka 
                file << "*-----------------------------*" <<endl;
				file << "|          TO DO LIST         |" <<endl;
				file << "*-----------------------------*" <<endl;
                for (int i = 0; i < jumlahTugas; ++i) { // Membuat Loop 'for' untuk menulisskan setiap tugas dalam to-do list ke dalam file.
                	file << i + 1 << ". "; // Menuliskan urutan tugas ke dalam file.
                    // (file << ) Mirip dengan output ke layar dalam fungsi 'tampilkanToDoList', Pernyataan pernyataan ini menuliskan informasi tugas ke dalam file.
                    if (toDoList[i].prioritas) {
                        file << "[Urgent] ";
                        } else {
                        file << "[Biasa] ";
                    }
                    if (toDoList[i].dilaksanakan) {
                		file << "[Selesai] ";  // Tandai sebagai sudah dilaksanakan
                    } else {
                		file << "[ ] ";  // Tandai sebagai belum dilaksanakan
                    }
                    file << toDoList[i].nama << endl;
                }
                file.close(); // Menutup file setelah selesai menuliskan to-do list kedalamnya.
                cout << "To-do list berhasil dicetak ke file to_do_list.txt" << endl; // Menampilkan pesan ke layar bahwa to-do list berhasil dicetak ke dalam file. 
                system ("pause"); // Menahan eksekusi program sehingga pesan bisa terlihat sebelum program selesai
            } else { // Blok ini akan dijalankan jika file tidak berhasil dibuka.
                cout << "Gagal membuka file untuk mencetak." << endl; // Menampilkan pesan ke layar bahwa program gagal membuka file untuk mencetak.
            }
        } // dengan cara ini, blok program ini meminta konfirmasi dari pengguna untuk mencetak to-do list ke file. Jika konfirmasi positif, program membuka file untuk penulisan, menuliskan informasi to-do list ke dalamnya, dan kemudian menutup file. Jika gagal membuka file, program memberikan pesan kesalahan.
    }
}

// Fungsi untuk menandai tugas yang sudah dilaksanakan
void tandaiTugasSelesai(Tugas toDoList[MAX_TUGAS], int jumlahTugas) { // Ini adalah deklarasi fungsi 'tandaiTugasSelesai'. Fungsi ini menerima 2 parameter : Array 'toDoList' yang berisi tugas tugas dan jumlah tugas saat ini {'jumlahTugas'}. Fungsi ini tidak mengembalikan nilai ('void').
    int nomorTugas; // Mendeklarasikan variabel 'nomorTuggas' yang akan digunakan untuk menyimpan nomor tugas yang akan ditandai sebagai selesai.
    
    system ("cls"); // Membersihkan layar untuk memberikan tampilan yang bersih sebelum menampilkan to-do list.
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
                cout << "[Selesai] ";  // Tandai sebagai sudah dilaksanakan
            } else {
                cout << "[ ] ";  // Tandai sebagai belum dilaksanakan
            }
            cout << toDoList[i].nama << endl;
        }
    cout << endl;
    cout << "Masukkan nomor tugas yang sudah selesai: ";
    cin >> nomorTugas;

    if (nomorTugas >= 1 && nomorTugas <= jumlahTugas) { // Mengevaluasi apakah nomor tugas yang dimasukan leh pengguna valid, yaitu antara 1 dan jumlah tugas saat ini.
        toDoList[nomorTugas - 1].dilaksanakan = true; // Jika nomor tugas valid, menetapkan nilai 'true' ke anggota 'dilaksanakan' dari tugas yang dipilih, menandai tugas tersebut sebagai sudah dilaksanakan.
        cout << "Tugas berhasil ditandai sebagai selesai!" << endl;
    } else { // Blok ini akan dijalankan jika nomor tugas tidak valid.
        cout << "Nomor tugas tidak valid." << endl;
    }
}

int main() {
    Tugas toDoList[MAX_TUGAS]; // Membuat Array 'toDoList' yang dapat menyimpan maksimal 'MAX_TUGAS' tugas. Array ini digunakan untuk menyimpan informasi setiap tugas dalam to-do list.
    int jumlahTugas = 0;
    int pilihan;

    do { // Memulai konstruksi Loop 'do-while'. Ini berarti blok kode didalamnya
        // Menampilkan menu
        system("cls");
        cout << "\t\t\t *----------------------------*" <<endl;
        cout << "\t\t\t |    PROGRAM C++ TO DO LIST  |" <<endl;
        cout << "\t\t\t |         Hikmal Akbar       |" <<endl;
        cout << "\t\t\t |        Fiky Aldiansyah     |" <<endl;
        cout << "\t\t\t |             Yosi           |" <<endl;
        cout << "\t\t\t*------------------------------*" <<endl;
        cout << "\t\t\t| 1. Tambah Tugas              |\n";
        cout << "\t\t\t| 2. Tampilkan To-do List      |\n";
        cout << "\t\t\t| 3. Tandai Tugas Selesai      |\n";
        cout << "\t\t\t| 4. Keluar                    |\n";
        cout << "\t\t\t*------------------------------*\n\n" <<endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        // Melakukan aksi sesuai pilihan menu
        switch (pilihan) { // Memulai konstruksi switch untuk memilih aksi berdasarkan pilihan menu yang dimasukan oleh pengguna.
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
    } while (pilihan != 4); // Melanjutkan Loop 'do-while' selama pengguna tidak memilih menu keluar
// getch();
    return 0; // Mengembalikan nlai 0 sebagai indikasi
}


























































































































































































































































































































