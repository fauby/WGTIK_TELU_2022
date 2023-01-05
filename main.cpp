#include "tubes.h"

#include <string.h>
#include <iostream>
using namespace std;

int main()
{
    List L;
    createList(L);
    int pilihan;
    pilihan = selectMenu();
    while (pilihan != 0) {
        if (pilihan == 1) {
            cout << "===== MENU PEMBELIAN TIKET PELANGGAN BARU =====" << endl << endl;
            string nama, noTelp, email;
            int jumlahTiket;
            cout << "Masukan Nama Pembeli: ";
            cin >> nama;

            cout << "Masukan Nomor Telepon: ";
            cin >> noTelp;

            cout << "Masukan Email: ";
            cin >> email;

            cout << "Masukan Jumlah Tiket Yang Dibeli: ";
            cin >> jumlahTiket;
            //cout << endl;

            adrP P = newParent(nama,noTelp,email,jumlahTiket);
            insertLastP(L,P);
            int i = 1;
            while (i <= infoP(P).jumlahTiket) {
                string kodeUnik, tipeTiket;
                cout << "Tiket ke-" << i << endl;
                cout << "Tipe tiket : ";
                cin >> tipeTiket;
                kodeUnik = tipeTiket +"-"+ infoP(P).noTelp.substr(infoP(P).noTelp.length() - 4, infoP(P).noTelp.length()) + to_string(i);
                adrC c = newChild(kodeUnik, tipeTiket);
                insertLastC(L, infoP(P).noTelp, c);
                cout << "Kode Unik Tiket: " << infoC(c).kodeUnik << endl <<endl;
                i++;
            }
            selectMenu2(pilihan);
        } else if (pilihan == 2) {

            cout << "===== MENU PEMBELIAN TIKET PELANGGAN LAMA =====" << endl << endl;
            string noTelp;
            int jumlahTiket;
            cout << "Masukan Nomor Telepon: ";
            cin >> noTelp;
            cout << endl;
            adrP P = findP(L, noTelp);
            if (P != NULL) {
                cout << "Masukan Jumlah Tiket Yang Dibeli: ";
                cin >> jumlahTiket;
                cout << endl;
                int i = infoP(P).jumlahTiket + 1;
                infoP(P).jumlahTiket += jumlahTiket;
                while (i <= infoP(P).jumlahTiket) {
                    string kodeUnik, tipeTiket;
                    cout << "Tiket ke-" << i << endl;
                    cout << "Tipe tiket : ";
                    cin >> tipeTiket;
                    kodeUnik = tipeTiket +"-"+ infoP(P).noTelp.substr(infoP(P).noTelp.length() - 4, infoP(P).noTelp.length()) + to_string(i);
                    adrC c = newChild(kodeUnik, tipeTiket);
                    insertLastC(L, infoP(P).noTelp, c);
                    cout << "Kode Unik Tiket: " << infoC(c).kodeUnik << endl << endl;
                    i++;
                }
                selectMenu2(pilihan);
            } else {
                cout << "No Telepon tidak ditemukan!" << endl << endl;
                selectMenu2(pilihan);
            }

        } else if(pilihan == 3){

            cout << "======== MENU PEMBATALAN TIKET ========" << endl;
            string KodeUnik;
            cout << endl;
            string noTelp;
            cout << "Masukan Nomor Telepon: ";
            cin >> noTelp;
            cout << endl;
            adrP P = findP(L, noTelp);
            /*
            deleteLastC(L,P);
            adrC c = child(P);
            while(c != NULL){
                cout << infoC(c).kodeUnik << endl;
                c = nextC(c);
            }
            */
            if (P != NULL) {
                cout << "Kode Unik pada tiket anda: ";
                cin >> KodeUnik;
                hapusTipe(L,P, KodeUnik);
                cout << "Tiket Berhasil Dibatalkan!" << endl << endl;
                adrC c = child(P);
                cout << "Tiket Yang Anda Miliki: " << endl;
                if(c == NULL){
                    cout << "Anda Tidak Memiliki Tiket!" << endl;
                }else{
                    int i = 1;
                    while(c != NULL){
                        cout << "Tiket Ke-" << i << endl;
                        cout << infoC(c).kodeUnik << endl;
                        c = nextC(c);
                        i++;
                    }
                }
            }else{
                cout << "No Telepon tidak ditemukan!" << endl << endl;
            }
            selectMenu2(pilihan);
        }else if (pilihan == 4) {

            cout << "===== MENU MENAMPILKAN TIKET =====" << endl << endl;
            string kodeUnik;
            cout << "Masukan Kode Unik : ";
            cin >> kodeUnik;
            cout << endl;
            showTiket(L, kodeUnik);
            selectMenu2(pilihan);
        } else if(pilihan == 5) {

            cout << "===== MENU MENAMPILKAN SEMUA TIKET =====" << endl << endl;
            showAllTiket(L);
            selectMenu2(pilihan);
        } else if (pilihan == 6) {

            cout << "===== MENU MENAMPILKAN DATA PELANGGAN =====" << endl << endl;
            showParent(L);
            selectMenu2(pilihan);
        } else if (pilihan == 7) {

            cout << "===== MENU MENAMPILKAN JUMLAH TIKET TERJUAL =====" << endl << endl;
            showJumlahTiket(L);
            selectMenu2(pilihan);
        }
    }
    cout << "Anda telah keluar dari program!" << endl;
    return 0;

}
