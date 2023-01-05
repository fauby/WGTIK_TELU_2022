#include "tubes.h"

void createList(List &L){
    first(L) = NULL;
}

adrP newParent(string nama, string noTelp, string email, int jumlahTiket) {
    adrP p = new elmParent;
    infotypeP x;
    x.nama = nama;
    x.noTelp = noTelp;
    x.email = email;
    x.jumlahTiket = jumlahTiket;
    infoP(p) = x;
    nextP(p) = NULL;
    return p;
};

adrC newChild (string kodeUnik, string tipeTiket) {
    adrC p = new elmChild;
    infotypeC x;
    x.kodeUnik = kodeUnik;
    x.tipeTiket = tipeTiket;
    infoC(p) = x;
    nextC(p) = NULL;
    return p;
};

void insertLastP(List &L, adrP p) {
    if (first(L) == NULL){
        first(L) = p;
    }else{
        adrP q = first(L);
        while(nextP(q) != NULL){
            q = nextP(q);
        }
        nextP(q) = p;
    }
};

void insertFirstP(List &L, adrP p) {
    if(first(L) == NULL){
        first(L) = p;
    }else{
        adrP q = first(L);
        while(nextP(q) != NULL){
            q = nextP(q);
        }
        nextP(q) = p;
    }
}

void deleteFirstP(List &L, adrP &p) {
    if (nextP(first(L)) == NULL) {
        p = first(L);
        first(L) = NULL;
    } else {
        p = first(L);
        first(L) = nextP(p);
        nextP(p) = NULL;
    }
};

void insertLastC(List &L, string noTelp, adrC c){
    adrP p = findP(L, noTelp);
    if (p != NULL) {
        if (child(p) != NULL) {
            adrC q = child(p);
            while (nextC(q) != NULL) {
                q = nextC(q);
            }
            nextC(q) = c;
        } else {
            child(p) = c;
        }
    } else {
        cout << "Parent tidak ditemukan!" << endl;
    }
};

void insertFirstC(List &L, string noTelp, adrC c){
    adrP p = findP(L,noTelp);
    if (p != NULL){
        c = child(p);
        child(p) = c;
    }else{
        cout << "Parent tidak ditemukan!" << endl;
    }
}

adrC deleteFirstC(List &L, adrP &p){
    adrC c;
    if(next(child(p)) == NULL){
        c = child(p);
        child(p) = NULL;
    }else{
        c = child(p);
        child(p) = nextC(c);
        nextC(c) = NULL;
    }
    return c;
}

adrC deleteLastC(List &L,adrP &p){
    adrC c = child(p);
    while (nextC(nextC(c)) != NULL){
        c = nextC(c);
    }
    nextC(c) = NULL;
    return c;
}

adrP findP(List L, string noTelp) {
    adrP p = first(L);
    while (p != NULL){
        if (infoP(p).noTelp == noTelp) {
            return p;
        }
        p = nextP(p);
    }
    return NULL;
}

adrC findC(List L, string kodeUnik, adrP &p) {
    adrP m = first(L);
    while (m != NULL){
        adrC n = child(m);
        while (n != NULL){
            if (infoC(n).kodeUnik == kodeUnik) {
                p = m;
                return n;
            }
            n = nextC(n);
        }
        m = nextP(m);
    }
    return NULL;
}

void showTiket(List L, string kodeUnik) {
    adrP q = NULL;
    adrC p = findC(L, kodeUnik, q);
    if (p != NULL) {
        cout << "Tiket dengan Kode Unik : " << kodeUnik << endl;
        cout << "Nama : " << infoP(q).nama << endl;
        cout << "No telepon : " << infoP(q).noTelp << endl;
        cout << "Alamat Email : " << infoP(q).email << endl;
        cout << "Tipe tiket : " << infoC(p).tipeTiket << endl << endl;
    } else {
        cout << "Tiket Tidak Ditemukan!" << endl << endl;
    }
}

void showAllTiket(List &L){
    int i = 1;
    adrP p = first(L);
    if(p != NULL){
        while (p != NULL){
            adrC c = child(p);
            while (c != NULL){
                cout << "Tiket Ke: " << i << endl;
                cout << "Tiket dengan Kode Unik : " << infoC(c).kodeUnik << endl;
                cout << "Nama : " << infoP(p).nama << endl;
                cout << "No telepon : " << infoP(p).noTelp << endl;
                cout << "Alamat Email : " << infoP(p).email << endl;
                cout << "Tipe tiket : " << infoC(c).tipeTiket << endl << endl;
                c = nextC(c);
                i++;
            }
    //        cout << "Nama : " << infoP(p).nama << endl;
    //        cout << "No telepon : " << infoP(p).noTelp << endl;
    //        cout << "Alamat Email : " << infoP(p).email << endl;
            p = nextP(p);
        }
    }else{
        cout << "Tiket Tidak Ditemukan!" << endl << endl;
    }
}

void showParent (List &L) {
    adrP p = first(L);
    int i = 1;
    if(p == NULL){
        cout << "Data Pelanggan Tidak Ditemukan!" << endl << endl;
    }else{
        while (p != NULL) {
            cout << "Data Pembeli ke-" << i << endl;
            cout << "Nama : " << infoP(p).nama << endl;
            cout << "No telepon : " << infoP(p).noTelp << endl;
            cout << "Alamat Email : " << infoP(p).email << endl;
            cout << "Jumlah Tiket : " << infoP(p).jumlahTiket << endl << endl;
            p = nextP(p);
            i++;
        }
    }
}

void showJumlahTiket(List&L){
    int jumREG, jumVIP;
    jumREG = 0; jumVIP = 0;
    adrP p = first(L);
    while(p != NULL){
        adrC c = child(p);
        while(c != NULL){
            if(infoC(c).tipeTiket == "REG"){
                jumREG += 1;
            }else if(infoC(c).tipeTiket == "VIP"){
                jumVIP += 1;
            }
            c = nextC(c);
        }
        p = nextP(p);
    }
    cout << "Tiket Reguler: " << jumREG << endl;
    cout << "Tiket VIP: " << jumVIP << endl;
    cout << endl;
}

void hapusTipe(List &L, adrP &p, string kodeUnik){
    adrC c = child(p);
    if (infoC(c).kodeUnik == kodeUnik){
        deleteFirstC(L,p);
    }else{
        while(infoC(nextC(c)).kodeUnik != kodeUnik){
            c = nextC(c);
        }
        adrC d = nextC(c);
        if (nextC(d) == NULL){
            deleteLastC(L,p);
        }else{
            nextC(c) = nextC(d);
            d = NULL;
        }
    }
    infoP(p).jumlahTiket--;
}


int selectMenu() {
    cout << "====== MENU UTAMA =======" << endl << endl;
    cout << "1. Pelanggan Baru" << endl;
    cout << "2. Pelanggan Yang Sudah Terdaftar" << endl;
    cout << "3. Pembatalan Tiket" << endl;
    cout << "4. Menampilkan Tiket" << endl;
    cout << "5. Menampilkan Semua Tiket" << endl;
    cout << "6. Menampilkan Data Pelanggan" << endl;
    cout << "7. Menampilkan Jumlah Tiket Terjual" << endl;
    cout << "0. EXIT" << endl;
    int input;
    cout << "Masukkan menu : ";
    cin >> input;
    return input;
}

void selectMenu2(int &pilihan) {
    cout << "Kembali Ke Menu Utama? (Y/N) : ";
    char input;
    cin >> input;

    if (input == 'Y' || input == 'y') {
        pilihan = selectMenu();
    } else if (input == 'N' || input == 'n') {
        pilihan = 0;
    }
};
