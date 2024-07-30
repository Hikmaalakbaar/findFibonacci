import os
# mengambil library os untuk bisa menghapus buffer input

os.system("cls" if os.name == "nt" else "clear")
# fungsi cls, untuk menghapus buffer input
harga_baju_koko = 100000 #pendeklarasian variabel
harga_celana_koko = 60000 #pendeklarasian variabel
harga_sepatu_adidas = 700000 #pendeklarassian variabel

jumlah_baju_koko = 0 #pendeklarasian variabel
jumlah_celana_koko = 0
jumlah_sepatu_adidas = 0

harga_awal = 0

while True:
    #looping while tak terbatas hingga diberikan perintah break
    os.system("cls" if os.name == "nt" else "clear")
    print("      Toko Baju Hikmal     ")
    print("---------------------------")
    print("1. Baju Koko   Rp. 100.0000")
    print("2. Celana Koko   Rp. 60.000")
    print("3. Sepatu Adidas Rp.700.000")
    print("---------------------------")
    pilihan = int(input("Masukkan pilihan anda (1-3): "))
    #ouput dan input dan juga pengisian nilai variabel pilihan
    jumlah_item = int(input("Berapa jumlah item yang anda beli : "))
    
    if pilihan == 1:
        #pengkondisian pada variabel pilihan
        jumlah_baju_koko = jumlah_item
    elif pilihan == 2:
        jumlah_celana_koko = jumlah_item
    elif pilihan == 3:
        jumlah_sepatu_adidas = jumlah_item
    else:
        print("Inputan Anda tidak Valid")
        break
    #selesai dari pengkondisian if else
    
    beli_lagi = input("Apakah anda ingin membeli lagi (Y/N)  : ")
    if beli_lagi.lower() != 'y':
#lower adalah loweccase, yaitu untuk menjadikan semua nilai yang di berikan user
# adalah huruf kecil semua
        break
    #selessai dari pengulangan while tak terbatas

harga_awal = (jumlah_baju_koko * harga_baju_koko) + \
             (jumlah_celana_koko * harga_celana_koko) + \
             (jumlah_sepatu_adidas * harga_sepatu_adidas)

diskon = 0
if harga_awal > 200000 and harga_awal <= 500000:
    #pengkondisian variabel harga_awal
    diskon = 0.1
    #inisialisasi variabel diskon
    
elif harga_awal > 500000 and harga_awal <= 700000:
    diskon = 0.15
elif harga_awal > 700000:
    diskon = 0.5

harga_total = harga_awal - (harga_awal * diskon)

print("\nPembayaran anda adalah : Rp", harga_awal)
print("Diskon yang anda peroleh adalah :", diskon * 100, "%")
print("Total yang harus anda bayar adalah : Rp.", harga_total)
