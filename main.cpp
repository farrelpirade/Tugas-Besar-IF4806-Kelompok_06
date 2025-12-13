#include <iostream>
#include "mll.h"

using namespace std;

void menuProducer(ListParent &L) {
    int choice = -1;
    while (choice != 0) {
        cout << "\n==========================================" << endl;
        cout << "        MENU PRODUCER (ADMIN MODE)        " << endl;
        cout << "==========================================" << endl;
        cout << "1. Registrasi Film Baru" << endl;
        cout << "2. Hapus Film Tertentu Menggunakan ID" << endl;
        cout << "3. Bersihkan Film Flop dengan Rating < 5" << endl;
        cout << "4. Casting Peran Aktor Baru" << endl;
        cout << "5. Pecat Aktor Tertentu Menggunakan ID" << endl;
        cout << "6. Hapus Semua Orang dengan Peran Cameo" << endl;
        cout << "7. Lihat Database Lengkap" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << ">> Pilih: "; 
        cin >> choice;

        if (choice == 1) {
            infotypeParent data;
            cout << "NOTE: Gunakan underscore (_) pengganti spasi" << endl;
            cout << "ID Film : "; 
            cin >> data.id;
            cout << "Judul   : "; 
            cin >> data.judul;
            cout << "Genre   : "; 
            cin >> data.genre;
            cout << "Studio  : "; 
            cin >> data.studio;
            cout << "Tahun   : "; 
            cin >> data.tahunRilis;
            cout << "Rating  : "; 
            cin >> data.ratingFilm;
            cout << "Revenue : "; 
            cin >> data.revenue;
            insertParentSorted(L, createElmParent(data));
            cout << "Status: Film berhasil didaftarkan!" << endl;

        } else if (choice == 2) {
            string id;
            cout << "Masukkan ID Film yg ingin dihapus: "; 
            cin >> id;
            addressParent P = findParent(L, id);
            if (P != NULL) {
                deleteSpecificParent(L, id);
                cout << "Status: Film ID " << id << " berhasil dihapus." << endl;
            } else {
                cout << "Error: Film tidak ditemukan." << endl;
            }

        } else if (choice == 3) {
            char yakin;
            cout << "PERINGATAN: Semua film dengan rating < 5.0 akan dihapus.\nLanjutkan? (y/n): "; 
            cin >> yakin;
            if (yakin == 'y' || yakin == 'Y') {
                deleteParentByCondition(L, 5.0);
            }

        } else if (choice == 4) {
            string judul;
            cout << "Target Film (Judul/ID): "; 
            cin >> judul;
            addressParent P = findParent(L, judul);
            if (P != NULL) {
                infotypeChild c;
                cout << "NOTE: Gunakan underscore (_) pengganti spasi!" << endl;
                cout << "ID Aktor      : "; 
                cin >> c.idAktor;
                cout << "Nama Aktor    : "; 
                cin >> c.namaAktor;
                cout << "Nama Karakter : "; 
                cin >> c.namaKarakter;
                cout << "Tipe Peran    : [Main/Support/Cameo] "; 
                cin >> c.tipePeran;
                cout << "Gaji ($Juta)  : "; 
                cin >> c.gaji;
                cout << "Rating Akting : "; 
                cin >> c.ratingAkting;
                cout << "Screentime    : "; 
                cin >> c.screentime;
                insertChildUnique(P, createElmChild(c));
            } else {
                cout << "Error: Film tidak ditemukan!" << endl;
            }

        } else if (choice == 5) {
            string judul, idAktor;
            cout << "Target Film (Judul/ID): "; 
            cin >> judul;
            addressParent P = findParent(L, judul);
            if (P != NULL) {
                cout << "Masukkan ID Aktor yang dipecat: "; 
                cin >> idAktor;
                deleteSpecificChild(P, idAktor); 
                cout << "Status: Proses pemecatan selesai (jika ID valid)." << endl;
            } else {
                 cout << "Error: Film tidak ditemukan!" << endl;
            }

        } else if (choice == 6) {
            string judul;
            cout << "Target Film untuk Efisiensi: "; 
            cin >> judul;
            addressParent P = findParent(L, judul);
            if (P != NULL) {
                deleteChildByCondition(P, "Cameo");
            } else {
                cout << "Error: Film tidak ditemukan!" << endl;
            }

        } else if (choice == 7) {
            addressParent P = L.first;
            cout << "\n========== DATABASE LENGKAP ==========" << endl;
            if (P == NULL) {
                cout << "Database kosong." << endl;
            }
            while (P != NULL) {
                cout << "[FILM] " << P->info.judul << " (" << P->info.tahunRilis << ")" << endl;
                cout << "       Rating: " << P->info.ratingFilm << " | Revenue: $" << P->info.revenue << endl;
                printChildrenUnique(P);
                cout << "--------------------------------------" << endl;
                P = P->next;
            }
            cout << "======================================" << endl;
        }
    }
}

void menuAuditor(ListParent &L) {
    int choice = -1;
    while (choice != 0) {
        cout << "\n==========================================" << endl;
        cout << "        MENU AUDITOR (ANALYST MODE)       " << endl;
        cout << "==========================================" << endl;
        cout << "1. Cari Data Film" << endl;
        cout << "2. Validasi Aktor di Film" << endl;
        cout << "3. Laporan Beban Gaji Film" << endl;
        cout << "4. Cari 'Star Actor' Menggunakan Gaji Maksimum" << endl;
        cout << "5. Lihat Daftar Film Saja" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << ">> Pilih: "; 
        cin >> choice;

        if (choice == 1) {
            string key;
            cout << "Cari Judul/ID: "; 
            cin >> key;
            addressParent P = findParent(L, key);
            if (P != NULL) {
                cout << "Found: " << P->info.judul << " (" << P->info.tahunRilis << ")" << endl;
                cout << "Studio: " << P->info.studio << " | Rating: " << P->info.ratingFilm << endl;
            } else {
                cout << "Not Found." << endl;
            }

        } else if (choice == 2) {
            string fKey, aKey;
            cout << "Nama Film: "; 
            cin >> fKey;
            addressParent P = findParent(L, fKey);
            if (P != NULL) {
                cout << "Nama Aktor: "; 
                cin >> aKey;
                addressChild C = findChild(P, aKey);
                if (C != NULL) {
                    cout << "Valid: " << C->info.namaAktor << " berperan sebagai " << C->info.namaKarakter << endl;
                } else {
                    cout << "Aktor tidak ditemukan di film ini." << endl;
                }
            } else {
                cout << "Film tidak ditemukan." << endl;
            }

        } else if (choice == 3) {
            string key;
            cout << "Pilih Film: "; 
            cin >> key;
            addressParent P = findParent(L, key);
            if (P != NULL) {
                double total = hitungTotalGaji(P);
                cout << ">> Total Budget Gaji Cast: $" << total << " Juta" << endl;
            } else {
                cout << "Film tidak ditemukan." << endl;
            }

        } else if (choice == 4) {
            string key;
            cout << "Pilih Film: "; 
            cin >> key;
            addressParent P = findParent(L, key);
            if (P != NULL) {
                addressChild rich = findAktorTermahal(P);
                if (rich != NULL) {
                    cout << ">> STAR ACTOR: " << rich->info.namaAktor << endl;
                    cout << ">> GAJI      : $" << rich->info.gaji << " Juta" << endl;
                } else {
                    cout << "Belum ada data aktor." << endl;
                }
            } else {
                cout << "Film tidak ditemukan." << endl;
            }

        } else if (choice == 5) {
            addressParent P = L.first;
            cout << "--- MOVIE LIST ---" << endl;
            while (P != NULL) {
                cout << "- " << P->info.judul << " [" << P->info.tahunRilis << "]" << endl;
                P = P->next;
            }
        }

    }
}

int main() {
    ListParent L;
    createListParent(L);

    int mainChoice = -1;
    while (mainChoice != 0) {
        cout << "\n##########################################" << endl;
        cout << "    APLIKASI MANAJEMEN ARTIS & FILM       " << endl;
        cout << "##########################################" << endl;
        cout << "1. PRODUCER Mode (Admin)" << endl;
        cout << "2. AUDITOR Mode (User Standard)" << endl;
        cout << "0. Keluar" << endl;
        cout << ">> Pilih Role: "; 
        cin >> mainChoice;

        if (mainChoice == 1) {
            menuProducer(L);
        } else if (mainChoice == 2) {
            menuAuditor(L);
        }
    }

    cout << "Terima kasih." << endl;
    return 0;
}