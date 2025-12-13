#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

//ADT Parent
struct elmChild;
typedef struct elmChild *addressChild;

struct infotypeParent {
    string id;
    string judul;
    string genre;
    int tahunRilis;
    string studio;
    double ratingFilm;
    double revenue;
};
 
typedef struct elmParent *addressParent;
 
struct elmParent {
    infotypeParent info;
    addressParent next;
    addressParent prev;
    addressChild firstChild;
};
 
struct ListParent {
    addressParent first;
    addressParent last;
};

//ADT Child
struct infotypeChild {
    string idAktor;
    string namaAktor;
    string namaKarakter;
    string tipePeran;
    double gaji;
    float ratingAkting;
    int screentime;
};

struct elmChild {
    infotypeChild info;
    addressChild next;
};

void createListParent(ListParent &L);
addressParent createElmParent(infotypeParent data);
 
void insertParentSorted(ListParent &L, addressParent P);
void insertFirstParent(ListParent &L, addressParent P);
void insertLastParent(ListParent &L, addressParent P);
void insertAfterParent(ListParent &L, addressParent Prec, addressParent P);
 
void deleteParentByCondition(ListParent &L, double minRating);
void deleteFirstParent(ListParent &L, addressParent &P);
void deleteLastParent(ListParent &L, addressParent &P);
void deleteAfterParent(ListParent &L, addressParent Prec, addressParent &P);
void deleteSpecificParent(ListParent &L, string idFilm);
 
addressParent findParent(ListParent L, string judulAtauID);
void printAllParents(ListParent L);

addressChild createElmChild(infotypeChild data);

void insertChildUnique(addressParent P, addressChild C);
void insertFirstChild(addressParent P, addressChild C);
void insertLastChild(addressParent P, addressChild C);
void insertAfterChild(addressChild Prec, addressChild C);

void deleteChildByCondition(addressParent P, string tipePeran);
void deleteFirstChild(addressParent P, addressChild &C);
void deleteLastChild(addressParent P, addressChild &C);
void deleteAfterChild(addressChild Prec, addressChild &C);
void deleteSpecificChild(addressParent P, string idAktor);

addressChild findChild(addressParent P, string namaAktor);
void printChildrenUnique(addressParent P);

double hitungTotalGaji(addressParent P);
addressChild findAktorTermahal(addressParent P);

#endif