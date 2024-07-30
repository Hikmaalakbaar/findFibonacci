#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Struktur data untuk menyimpan jadwal pelajaran
struct Schedule {
    string subject;
    string teacher;
    string className;
    int day;
    int hour;

    // Konstruktor
    Schedule(string sub, string tea, string cls, int d, int h) 
        : subject(sub), teacher(tea), className(cls), day(d), hour(h) {}
};

// Fungsi untuk mengecek apakah ada konflik dalam jadwal
bool isScheduleConflict(const vector<Schedule>& schedules, const Schedule& newSchedule) {
    for (const Schedule &schedule : schedules) {
        if (schedule.day == newSchedule.day && schedule.hour == newSchedule.hour) {
            if (schedule.teacher == newSchedule.teacher || schedule.className == newSchedule.className) {
                return true; // Ada konflik
            }
        }
    }
    return false; // Tidak ada konflik
}

// Fungsi untuk menampilkan jadwal
void printSchedule(const vector<Schedule>& schedules) {
    cout << "Jadwal Pelajaran Sekolah" << endl;
    cout << "-------------------------" << endl;
    cout << "Hari\tJam\tMata Pelajaran\tGuru\tKelas" << endl;
    for (const auto& schedule : schedules) {
        cout << schedule.day << "\t" << schedule.hour << "\t" << schedule.subject << "\t\t" << schedule.teacher << "\t" << schedule.className << endl;
    }
}

int main() {
    // Vector untuk menyimpan jadwal pelajaran
    vector<Schedule> schedules;

    // Map untuk menyimpan guru berdasarkan mata pelajaran
    map<string, string> subjectTeacher = {
        {"Matematika", "Budi"},
        {"Bahasa Inggris", "Ani"},
        {"Bahasa Indonesia", "Candra"},
        {"IPA", "Dewi"},
        {"IPS", "Fajar"}
    };

    // Map untuk menyimpan kelas berdasarkan mata pelajaran
    map<string, string> subjectClass = {
        {"Matematika", "X IPA"},
        {"Bahasa Inggris", "X IPA"},
        {"Bahasa Indonesia", "X IPA"},
        {"IPA", "X IPA"},
        {"IPS", "X IPS"}
    };

    // Loop untuk memasukkan jadwal pelajaran
    char input;
    do {
        string subject;
        string teacher;
        string className;
        int day;
        int hour;

        // Memasukkan data jadwal
        cout << "Masukkan Mata Pelajaran: ";
        cin >> subject;

        // Memilih guru berdasarkan mata pelajaran
        teacher = subjectTeacher.at(subject);
        className = subjectClass.at(subject);

        cout << "Masukkan Hari (1-5): ";
        cin >> day;
        cout << "Masukkan Jam (1-8): ";
        cin >> hour;

        // Membuat objek jadwal baru
        Schedule newSchedule(subject, teacher, className, day, hour);

        // Mengecek apakah jadwal bentrok
        if (isScheduleConflict(schedules, newSchedule)) {
            cout << "Jadwal bentrok! Silahkan masukkan jadwal lain.\n";
        } else {
            schedules.push_back(newSchedule);
            cout << "Jadwal berhasil ditambahkan.\n";
        }

        cout << "Tambah jadwal lagi? (y/n): ";
        cin >> input;
    } while (input == 'y' || input == 'Y');

    // Menampilkan jadwal
    printSchedule(schedules);

    return 0;
}
