class Schedule:
    def __init__(self, subject, teacher, class_name, day, hour):
        self.subject = subject
        self.teacher = teacher
        self.class_name = class_name
        self.day = day
        self.hour = hour

# Fungsi untuk mengecek apakah ada konflik dalam jadwal
def is_schedule_conflict(schedules, new_schedule):
    for schedule in schedules:
        if schedule.day == new_schedule.day and schedule.hour == new_schedule.hour:
            if schedule.teacher == new_schedule.teacher or schedule.class_name == new_schedule.class_name:
                return True  # Ada konflik
    return False  # Tidak ada konflik

# Fungsi untuk menampilkan jadwal
def print_schedule(schedules):
    print("Jadwal Pelajaran Sekolah")
    print("-------------------------")
    print("Hari\tJam\tMata Pelajaran\tGuru\tKelas")
    for schedule in schedules:
        print(f"{schedule.day}\t{schedule.hour}\t{schedule.subject}\t\t{schedule.teacher}\t{schedule.class_name}")

def main():
    # List untuk menyimpan jadwal pelajaran
    schedules = []

    # Memasukkan jumlah hari masuk madrasah
    num_days = int(input("Masukkan jumlah hari masuk madrasah: "))

    # Memasukkan jumlah jam dalam sehari madrasah
    num_hours = int(input("Masukkan jumlah jam dalam satu hari madrasah: "))

    # Memasukkan jumlah kelas
    num_classes = int(input("Masukkan jumlah kelas: "))

    # Dictionary untuk menyimpan data mata pelajaran dan guru
    subject_teacher = {}
    for _ in range(num_classes):
        class_name = input(f"Masukkan nama kelas ke-{_+1}: ")
        for _ in range(num_days):
            day = _ + 1
            for _ in range(num_hours):
                hour = _ + 1
                subject = input(f"Masukkan Mata Pelajaran untuk kelas {class_name}, hari {day}, jam {hour}: ")
                teacher = input(f"Masukkan Guru pengajar untuk mata pelajaran {subject} di kelas {class_name}: ")
                subject_teacher[(class_name, day, hour)] = (subject, teacher)

    # Membuat jadwal berdasarkan data yang dimasukkan
    for key, value in subject_teacher.items():
        class_name, day, hour = key
        subject, teacher = value
        new_schedule = Schedule(subject, teacher, class_name, day, hour)
        schedules.append(new_schedule)

    # Menampilkan jadwal
    print_schedule(schedules)

if __name__ == "__main__":
    main()
