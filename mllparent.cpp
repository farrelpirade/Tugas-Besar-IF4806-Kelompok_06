#include "mll.h"

void createListParent(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
}

addressParent createElmParent(infotypeParent data) {
    addressParent P = new elmParent;
    P->info = data;
    P->next = NULL;
    P->prev = NULL;
    P->firstChild = NULL;
    return P;
}
void insertFirstParent(ListParent &L, addressParent P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastParent(ListParent &L, addressParent P) {
    if (L.first == NULL) {
        insertFirstParent(L, P);
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfterParent(ListParent &L, addressParent Prec, addressParent P) {
    P->next = Prec->next;
    P->prev = Prec;
    Prec->next->prev = P;
    Prec->next = P;
}

void insertParentSorted(ListParent &L, addressParent P) {
    if (L.first == NULL || P->info.tahunRilis < L.first->info.tahunRilis) {
        insertFirstParent(L, P);
    } else {
        addressParent Q = L.first;
        while (Q->next != NULL && Q->next->info.tahunRilis <= P->info.tahunRilis) {
            Q = Q->next;
        }
        
        if (Q->next == NULL) {
            insertLastParent(L, P);
        } else {
            insertAfterParent(L, Q, P);
        }
    }
}

void deleteFirstParent(ListParent &L, addressParent &P) {
    P = L.first;
    if (L.first != NULL) {
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = L.first->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
    }
}

void deleteLastParent(ListParent &L, addressParent &P) {
    P = L.last;
    if (L.first != NULL) {
        if (L.first == L.last) {
            deleteFirstParent(L, P);
        } else {
            L.last = L.last->prev;
            L.last->next = NULL;
            P->prev = NULL;
        }
    }
}

void deleteAfterParent(ListParent &L, addressParent Prec, addressParent &P) {
    P = Prec->next;
    if (P != NULL) {
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteSpecificParent(ListParent &L, string idFilm) {
    addressParent P = findParent(L, idFilm);
    if (P != NULL) {
        if (P == L.first) {
            deleteFirstParent(L, P);
        } else if (P == L.last) {
            deleteLastParent(L, P);
        } else {
            addressParent Temp;
            deleteAfterParent(L, P->prev, Temp);
            P = Temp;
        }
        delete P; 
    }
}

void deleteParentByCondition(ListParent &L, double minRating) {
    addressParent P = L.first;
    addressParent nextNode;
    
    while (P != NULL) {
        nextNode = P->next;
        
        if (P->info.ratingFilm < minRating) {
            addressParent Temp;
            if (P == L.first) {
                deleteFirstParent(L, Temp);
            } else if (P == L.last) {
                deleteLastParent(L, Temp);
            } else {
                deleteAfterParent(L, P->prev, Temp);
            }
            delete Temp;
        }
        
        P = nextNode;
    }
}

addressParent findParent(ListParent L, string judulAtauID) {
    addressParent P = L.first;
    while (P != NULL) {
        if (P->info.id == judulAtauID || P->info.judul == judulAtauID) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void printAllParents(ListParent L) {
    addressParent P = L.first;
    cout << "================ DAFTAR FILM ================" << endl;
    if (P == NULL) {
        cout << "List Kosong." << endl;
    }
    while (P != NULL) {
        cout << "ID      : " << P->info.id << endl;
        cout << "Judul   : " << P->info.judul << endl;
        cout << "Genre   : " << P->info.genre << endl;
        cout << "Tahun   : " << P->info.tahunRilis << endl;
        cout << "Studio  : " << P->info.studio << endl;
        cout << "Rating  : " << P->info.ratingFilm << "/10" << endl;
        cout << "Revenue : $" << P->info.revenue << endl;
        cout << "---------------------------------------------" << endl;
        P = P->next;
    }
    cout << endl;
}