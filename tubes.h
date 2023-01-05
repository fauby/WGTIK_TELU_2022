#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <string.h>
using namespace std;
#define first(L) ((L).first)
#define infoP(P) (P)->infoP
#define infoC(P) (P)->infoC
#define nextP(P) (P)->nextP
#define nextC(P) (P)->nextC
#define child(P) (P)->child

struct dataPembeli {
    string nama;
    string noTelp;
    string email;
    int jumlahTiket;
};
struct dataTiket {
    string kodeUnik, tipeTiket;
};
typedef struct dataPembeli infotypeP;
typedef struct dataTiket infotypeC;
typedef struct elmParent *adrP;
typedef struct elmChild *adrC;
struct elmParent {
    infotypeP infoP;
    adrC child;
    adrP nextP;

};
struct elmChild {
    infotypeC infoC;
    adrC nextC;

};

struct List {
    adrP first;
};

void createList(List &L);
adrP newParent(string nama, string noTelp, string email, int jumlahTiket);
adrC newChild (string kodeUnik, string tipeTiket);
void insertLastP(List &L, adrP p);
void insertFirstP(List &L, adrP p);
void deleteFirstP(List &L, adrP &p);
void insertLastC(List &L, string noTelp, adrC c);
void insertFirstC(List &L, string noTelp, adrC c);
adrC deleteFirstC(List &L, adrP &p);
adrC deleteLastC(List &L,adrP &p);
adrP findP(List L, string noTelp);
adrC findC(List L, string kodeUnik, adrP &p);
void showTiket(List L, string kodeUnik);
void showAllTiket(List &L);
void showParent (List &L);
void showJumlahTiket(List&L);
int selectMenu();
void selectMenu2(int &pilihan);
void hapusTipe(List &L, adrP &p, string kodeUnik);



#endif // TUBES_H_INCLUDED
