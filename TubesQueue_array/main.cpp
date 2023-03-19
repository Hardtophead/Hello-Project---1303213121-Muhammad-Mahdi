#include "queue.h"



int main()

{

    queue antrianGedung; // Queue antrian antrianGedung

    adr x; // Elemen antrian

    string c; // variabel yg digunakan untuk mencari data antrian berdasarkan input user

    infotype info; // Data antrian

    int pilihan = 0; // Pilihan menu untuk memilih menu

    int n; // jumlah data untuk digunakan di enqueue



    head(antrianGedung) = NULL;

    tail(antrianGedung) = NULL;



    while (pilihan >= 0 && pilihan < 8) {

        menu(); // Tampilkan menu pada setiap perulangan

        // Pilih menu

        cout << "Pilih menu: ";

        cin >> pilihan;

        cout << endl;



        // Pilih menu sesuai dengan pilihan menu

        if (pilihan == 1) {

            int i = 1;



            // input jumlah data yang akan diinput

            cout << "Masukan jumlah masukkan data: ";

            cin >> n;

            cout << endl;



            // input data antrian sebanyak jumlah data

            while(i <= n){

                cout << "Antrian ke-" << i << endl;

                info = input_antrian();

                x = buat_antrian(info);

                enqueue(antrianGedung, x);

                cout << "Data berhasil dimasukkan" << endl;



                i++;

            }

        } else if (pilihan == 2) {

            dequeue(antrianGedung, x);

            cout << "Data " << info(x).nama << " berhasil dihapus" << endl;

        } else if (pilihan == 3) {

            // tampilkan semua data antrian

            tampilkan_semua_antrian(antrianGedung);

        } else if (pilihan == 4) {

            tampilkan_antrian_tertentu(antrianGedung);

        } else if (pilihan == 5) {

            cout << "Masukan nama yang akan dicari: ";

            getline(cin >> ws, c);

            cout << endl;



            x = cari_antrian(antrianGedung, c);

            if (x != NULL) {

                cout << "Data ditemukan" << endl;

                cout << "Nama: " << info(x).nama << endl;

                cout << "Tujuan: " << info(x).tujuan << endl;

                cout << "Level Akses: " << info(x).level_akses << endl;

            } else {

                cout << "Data tidak ditemukan" << endl;

            }

        } else if (pilihan == 6) {

            queue prioritas = sort_antrian_prioritas(antrianGedung);

            tampilkan_semua_antrian(prioritas);

        } else if (pilihan == 7) {

            queue umum = sort_antrian_umum(antrianGedung);

            tampilkan_semua_antrian(umum);

        } else {

            // break: keluar dari perulangan dan keluar dari program

            break;

        }

    }



    cout << endl;

    cout << "Program telah selesai" << endl;



    return 0;

}

