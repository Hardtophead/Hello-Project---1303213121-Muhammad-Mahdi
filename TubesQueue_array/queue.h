#ifndef QUEUE_H_INCLUDED

#define QUEUE_H_INCLUDED



#include <iostream>

#include <string>

using namespace std;



#define info(P) (P)->info

#define next(P) (P)->next

#define prev(P) (P)->prev

#define head(Q) (Q).head

#define tail(Q) (Q).tail



// Data dasar Antrian karcis

struct karcisParkir {

    string nama, tujuan;

    char level_akses; // A = Admin, P = Petugas/Pegawai, U = Umum

};



typedef karcisParkir infotype;

typedef struct antrian *adr;



struct antrian {

    infotype info;

    adr next;

    adr prev;

};



struct queue {

    adr head;

    adr tail;

};



adr buat_antrian(infotype info);

infotype input_antrian();

void enqueue(queue &Q, adr x);

void dequeue(queue &Q, adr &p);

adr cari_antrian(queue Q, string cari);

void tampilkan_semua_antrian(queue Q);

void tampilkan_antrian_tertentu(queue Q);

queue sort_antrian_prioritas(queue Q);

queue sort_antrian_umum(queue Q);

void menu();



#endif // QUEUE_H_INCLUDED
