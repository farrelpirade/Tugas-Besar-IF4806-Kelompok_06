#ifndef FILM_ARTIS_H
#define FILM_ARTIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int idArtis;
    char nama[50];
    char agensi[50];
} infotypeArtis;

typedef struct elmArtis *addressArtis;
struct elmArtis {
    infotypeArtis info;
    addressArtis next;
};

typedef struct {
    addressArtis first;
} ListArtis;



typedef struct elmRelasi *addressRelasi;
struct elmRelasi {
    addressArtis child;
    char namaPeran[50];
    int ratingPerforma;
    addressRelasi next;
};

typedef struct {
    int idFilm;
    char judul[100];
    char genre[30];
    int tahunRilis;
} infotypeFilm;

typedef struct elmFilm *addressFilm;
struct elmFilm {
    infotypeFilm info;
    addressRelasi firstRelasi;
    addressFilm next;
};

typedef struct {
    addressFilm first;
} ListFilm;


void createListFilm(ListFilm *L);
void createListArtis(ListArtis *L);

addressFilm alokasiFilm(infotypeFilm data);
addressArtis alokasiArtis(infotypeArtis data);
addressRelasi alokasiRelasi(addressArtis PArtis, char *peran, int rating);

void insertFilm(ListFilm *L, addressFilm P);
void deleteFilm(ListFilm *L, int idFilm);
addressFilm findFilm(ListFilm L, int idFilm);
void printListFilm(ListFilm L);

void insertArtis(ListArtis *L, addressArtis P);
void deleteArtis(ListArtis *LA, ListFilm *LF, int idArtis);
addressArtis findArtis(ListArtis L, int idArtis);
void printListArtis(ListArtis L);


void addCast(ListFilm *LF, ListArtis LA, int idFilm, int idArtis, char *peran, int ratingAwal);


void removeCast(ListFilm *LF, int idFilm, int idArtis);


void updatePerforma(ListFilm *LF, int idFilm, int idArtis, int ratingBaru);

void printFilmDetails(ListFilm L, int idFilm);

void printArtisFilmography(ListFilm LF, ListArtis LA, int idArtis);

#endif
