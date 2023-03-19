#include "queue.h"



adr buat_antrian(infotype info) {

    adr p = new antrian;

    info(p) = info;

    next(p) = NULL;

    prev(p) = NULL;

    return p;

};



infotype input_antrian() {

    infotype info;

    cout << "Nama: ";

    getline(cin >> ws, info.nama);

    cout << endl;

    cout << "Level akses(A = Admin, P = Petugas/Pegawai, U = Umum): ";

    cin >> info.level_akses;

    cout << endl;



    // Jika level akses adalah admin dan pegawai, maka tidak perlu input tujuan

    if (info.level_akses == 'U' || info.level_akses == 'u') {

        cout << "Tujuan: ";

        getline(cin >> ws, info.tujuan);

        cout << endl;

    }



    return info;

};



void enqueue(queue &Q, adr x) {

    if (head(Q) == NULL) {

        head(Q) = x;

        tail(Q) = x;

    } else {

        next(tail(Q)) = x;

        prev(x) = tail(Q);

        tail(Q) = x;

    }

};



void dequeue(queue &Q, adr &antrianHapus) {

    if (head(Q) == NULL) {

        cout<<"queue kosong"<< endl;

    } else if (head(Q) == tail(Q)) {

        antrianHapus = head(Q);

        head(Q) = NULL;

        tail(Q) = NULL;

    } else {

        antrianHapus = head(Q);

        head(Q) = next(head(Q));

        prev(head(Q)) = NULL;

        next(antrianHapus) = NULL;

    }

};



adr cari_antrian(queue Q, string cari) {

    adr p = head(Q);

    while (p != NULL) {

        if (info(p).nama == cari) {

            return p;

        }

        p = next(p);

    }

    return NULL;

};



void tampilkan_semua_antrian(queue Q) {

    adr p = head(Q);

    while (p != NULL) {

        cout << "Nama: " << info(p).nama << endl;

        cout << "Level akses: " << info(p).level_akses << endl;

        if (info(p).level_akses == 'U' || info(p).level_akses == 'u') {

            cout << "Tujuan: " << info(p).tujuan << endl;

        }

        cout << endl;

        p = next(p);

    }

};



void tampilkan_antrian_tertentu(queue Q) {

    adr p = head(Q);

    while (p != NULL) {

        if (info(p).level_akses == 'A' || info(p).level_akses == 'a' || info(p).level_akses == 'P' || info(p).level_akses == 'p') {

            cout << "Nama: " << info(p).nama << endl;

            cout << "Level akses: " << info(p).level_akses << endl;

            if (info(p).level_akses == 'U' || info(p).level_akses == 'u') {

                cout << "Tujuan: " << info(p).tujuan << endl;

            }

            cout << endl;

        }

        p = next(p);

    }

};



queue sort_antrian_prioritas(queue Q) {

    queue antrian_prioritas;



    head(antrian_prioritas) = NULL;

    tail(antrian_prioritas) = NULL;



    adr p = head(Q);

    while (p != NULL) {

        if (info(p).level_akses == 'A' || info(p).level_akses == 'a' || info(p).level_akses == 'P' || info(p).level_akses == 'p') {

            adr x = buat_antrian(info(p));

            enqueue(antrian_prioritas, x);

        }

        p = next(p);

    }



    return antrian_prioritas;

};



queue sort_antrian_umum(queue Q) {

    queue antrian_umum;



    head(antrian_umum) = NULL;

    tail(antrian_umum) = NULL;



    adr p = head(Q);

    while (p != NULL) {

        if (info(p).level_akses == 'U' || info(p).level_akses == 'u') {

            adr x = buat_antrian(info(p));

            enqueue(antrian_umum, x);

        }

        p = next(p);

    }



    return antrian_umum;

};



void menu() {

    cout << "===========================" << endl;
    cout << "1. Buat Antrian (enqueue)" << endl;
    cout << "2. Hapus Antrian (dequeue)" << endl;
    cout << "3. Tampilkan semua antrian" << endl;
    cout << "4. Tampilkan semua antrian prioritas" << endl;
    cout << "5. Cari Antrian" << endl;
    cout << "6. Prioritaskan antrian berdasarkan level akses tinggi" << endl;
    cout << "7. Prioritaskan antrian berdasarkan level akses rendah" << endl;

};

