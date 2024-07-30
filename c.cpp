#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Struktur data untuk menyimpan pembayaran
struct Payment {
    string name;
    string className;
    string paymentType;
    string description;
    double amount;
    time_t timestamp;
};

// Fungsi untuk menambahkan pembayaran ke file
void addPaymentToFile(const Payment& payment) {
    ofstream file("payments.txt", ios::app);
    if (file.is_open()) {
        file << payment.name << "," << payment.className << "," << payment.paymentType << "," << payment.description << "," << payment.amount << "," << payment.timestamp << endl;
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Fungsi untuk membaca pembayaran dari file
vector<Payment> readPaymentsFromFile() {
    vector<Payment> payments;
    ifstream file("payments.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Payment payment;
            stringstream ss(line);
            getline(ss, payment.name, ',');
            getline(ss, payment.className, ',');
            getline(ss, payment.paymentType, ',');
            getline(ss, payment.description, ',');
            ss >> payment.amount;
            ss.ignore();
            ss >> payment.timestamp;
            payments.push_back(payment);
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
    return payments;
}

// Fungsi untuk menampilkan pembayaran
void displayPayments(const vector<Payment>& payments) {
    cout << "===============================================================================" << endl;
    cout << setw(20) << "Nama Santri" << setw(15) << "Kelas" << setw(15) << "Jenis" << setw(25) << "Keterangan" << setw(15) << "Nominal" << setw(25) << "Waktu Input" << endl;
    cout << "===============================================================================" << endl;
    for (size_t i = 0; i < payments.size(); ++i) {
        const Payment& payment = payments[i];
        struct tm * timeinfo = localtime(&payment.timestamp);
        char buffer[80];
        strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
        cout << setw(20) << i+1 << setw(15) << payment.name << setw(15) << payment.className << setw(15) << payment.paymentType << setw(25) << payment.description << setw(15) << payment.amount << setw(25) << buffer << endl;
    }
    cout << "===============================================================================" << endl;
}

// Fungsi untuk menghapus pembayaran dari file berdasarkan indeks
void deletePaymentFromFile(vector<Payment>& payments, int index) {
    if (index >= 0 && index < payments.size()) {
        payments.erase(payments.begin() + index);

        ofstream file("payments.txt");
        if (file.is_open()) {
            for (const Payment& payment : payments) {
                file << payment.name << "," << payment.className << "," << payment.paymentType << "," << payment.description << "," << payment.amount << "," << payment.timestamp << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    } else {
        cout << "Invalid index." << endl;
    }
}

int main() {
    vector<Payment> payments = readPaymentsFromFile();

    int choice;
    do {
    	system("cls");
        cout << "====================================================" << endl;
        cout << "                  SISTEM PENCATATAN BENDAHARA" << endl;
        cout << "====================================================" << endl;
        cout << "Menu:" << endl;
        cout << "1. Tambah Pembayaran" << endl;
        cout << "2. Tampilkan Pembayaran" << endl;
        cout << "3. Hapus Pembayaran" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Payment payment;
                cout << "Masukkan nama santri: ";
                cin >> ws;
                getline(cin, payment.name);
                cout << "Masukkan kelas santri: ";
                cin >> payment.className;
                cout << "Pilih jenis pembayaran (Pesantren/SMP/SMA): ";
                cin >> payment.paymentType;
                cout << "Masukkan keterangan pembayaran: ";
                cin >> ws;
                getline(cin, payment.description);
                cout << "Masukkan nominal pembayaran: ";
                cin >> payment.amount;
                payment.timestamp = time(nullptr);
                addPaymentToFile(payment);
                payments.push_back(payment);
                cout << "Pembayaran berhasil ditambahkan." << endl;
                break;
            }
            case 2:
                displayPayments(payments);
                break;
            case 3: {
                int index;
                cout << "Masukkan nomor pembayaran yang ingin dihapus: ";
                cin >> index;
                deletePaymentFromFile(payments, index - 1);
                cout << "Pembayaran berhasil dihapus." << endl;
                break;
            }
            case 4:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 4);

    return 0;
}