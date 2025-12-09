#include "mll.h"

// Mengalokasikan memori untuk node Child baru dan mengisi datanya.
addressChild createElmChild(infotypeChild data) {
    addressChild C = new elmChild;
    C->info = data;
    C->next = NULL;
    return C;
}

// Menyisipkan node Child baru di awal list Child milik Parent P.
void insertFirstChild(addressParent P, addressChild C) {
    if (P->firstChild == NULL) {
        P->firstChild = C;
    } else {
        C->next = P->firstChild;
        P->firstChild = C;
    }
}

// Menyisipkan node Child baru di akhir list Child milik Parent P.
void insertLastChild(addressParent P, addressChild C) {
    if (P->firstChild == NULL) {
        insertFirstChild(P, C);
    } else {
        addressChild Q = P->firstChild;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = C;
    }
}

// Menyisipkan node Child baru setelah node Prec.
void insertAfterChild(addressChild Prec, addressChild C) {
    C->next = Prec->next;
    Prec->next = C;
}

// Menyisipkan Child jika nama aktor/karakter belum ada (unik), insert di akhir.
void insertChildUnique(addressParent P, addressChild C) {
    addressChild Q = P->firstChild;
    bool found = false;
    while (Q != NULL) {
        if (Q->info.namaAktor == C->info.namaAktor || Q->info.namaKarakter == C->info.namaKarakter) {
            found = true;
        }
        Q = Q->next;
    }

    if (!found) {
        insertLastChild(P, C);
    } else {
        cout << "Gagal Insert: Aktor atau Karakter sudah ada dalam film ini." << endl;
    }
}

// Menghapus node Child pertama dari Parent P.
void deleteFirstChild(addressParent P, addressChild &C) {
    C = P->firstChild;
    if (P->firstChild != NULL) {
        P->firstChild = P->firstChild->next;
        C->next = NULL;
    }
}

// Menghapus node Child terakhir dari Parent P.
void deleteLastChild(addressParent P, addressChild &C) {
    if (P->firstChild != NULL) {
        if (P->firstChild->next == NULL) {
            deleteFirstChild(P, C);
        } else {
            addressChild Q = P->firstChild;
            while (Q->next->next != NULL) {
                Q = Q->next;
            }
            C = Q->next;
            Q->next = NULL;
        }
    } else {
        C = NULL;
    }
}

// Menghapus node Child yang berada setelah node Prec.
void deleteAfterChild(addressChild Prec, addressChild &C) {
    C = Prec->next;
    if (C != NULL) {
        Prec->next = C->next;
        C->next = NULL;
    }
}

// Mencari dan menghapus node Child tertentu berdasarkan ID Aktor.
void deleteSpecificChild(addressParent P, string idAktor) {
    addressChild C = P->firstChild;
    addressChild Prec = NULL;
    bool found = false;

    while (C != NULL && !found) {
        if (C->info.idAktor == idAktor) {
            found = true;
        } else {
            Prec = C;
            C = C->next;
        }
    }

    if (found) {
        addressChild Temp;
        if (Prec == NULL) {
            deleteFirstChild(P, Temp);
        } else {
            deleteAfterChild(Prec, Temp);
        }
        delete Temp;
    }
}

// Menghapus semua node Child yang memiliki tipe peran tertentu (misal: Cameo).
void deleteChildByCondition(addressParent P, string tipePeran) {
    addressChild C = P->firstChild;
    addressChild Prec = NULL;
    
    while (C != NULL) {
        if (C->info.tipePeran == tipePeran) {
            addressChild Temp;
            if (Prec == NULL) {
                deleteFirstChild(P, Temp);
                C = P->firstChild; 
            } else {
                deleteAfterChild(Prec, Temp);
                C = Prec->next; 
            }
            delete Temp;
            cout << "Data child dengan peran " << tipePeran << " berhasil dihapus." << endl;
        } else {
            Prec = C;
            C = C->next;
        }
    }
}

// Mencari alamat node Child berdasarkan nama aktor atau ID aktor.
addressChild findChild(addressParent P, string namaAktor) {
    addressChild C = P->firstChild;
    while (C != NULL) {
        if (C->info.namaAktor == namaAktor || C->info.idAktor == namaAktor) {
            return C;
        }
        C = C->next;
    }
    return NULL;
}

// Menampilkan semua data Child yang terhubung ke Parent P.
void printChildrenUnique(addressParent P) {
    addressChild C = P->firstChild;
    if (C == NULL) {
        cout << "   (Belum ada data aktor)" << endl;
    } else {
        while (C != NULL) {
            cout << "   -> [" << C->info.tipePeran << "] " << C->info.namaAktor 
                 << " as " << C->info.namaKarakter << endl;
            cout << "      Gaji: $" << C->info.gaji << " | Rating: " << C->info.ratingAkting << endl; 
            C = C->next;
        }
    }
}

// Menghitung total gaji seluruh aktor dalam satu film (Parent).
double hitungTotalGaji(addressParent P) {
    double total = 0;
    addressChild C = P->firstChild;
    while (C != NULL) {
        total = total + C->info.gaji;
        C = C->next;
    }
    return total;
}

// Mencari aktor dengan gaji tertinggi dalam satu film (Parent).
addressChild findAktorTermahal(addressParent P) {
    addressChild C = P->firstChild;
    addressChild MaxNode = NULL;
    double maxGaji = -1;

    while (C != NULL) {
        if (C->info.gaji > maxGaji) {
            maxGaji = C->info.gaji;
            MaxNode = C;
        }
        C = C->next;
    }
    return MaxNode;
}