#include <bits/stdc++.h>
using namespace std;

struct Siswa {
    string nSiswa; // Nama Siswa
    int absen;
    Siswa *next;
    Siswa *prev;
};

struct Antrian {
    string nSiswa; // Nama Siswa
    int absen;
    Antrian *next;
};

Siswa *top = NULL;
Siswa *bottom = NULL;

Antrian *depan = NULL, *belakang = NULL;

bool stackKosong() {
    return top == NULL;
}

void push(string nSiswa, int absen) {
    Siswa *siswaBaru = new Siswa();
    siswaBaru->nSiswa = nSiswa;
    siswaBaru->absen = absen;
    siswaBaru->next = NULL;
    siswaBaru->prev = NULL;

    if (stackKosong()) {
        top = siswaBaru;
        bottom = siswaBaru;
    } else {
        top->next = siswaBaru;
        siswaBaru->prev = top;
        top = siswaBaru;
    }
    cout << "Siswa \"" << nSiswa << "\" berhasil ditambahkan!\n";
}

void pop() {
    if (stackKosong()) {
        cout << "Stack kosong! Tidak ada data siswa yang bisa dihapus.\n";
    } else {
        Siswa *hapus = top;
        top = top->prev;
        if (top != NULL) {
            top->next = NULL;
        } else {
            bottom = NULL;
        }
        delete hapus;
    }
}

void tampilkanSiswa() {
    if (stackKosong()) {
        cout << "Tidak ada data siswa di dalam stack.\n";
    } else {
        cout << "===============================\n";
        cout << "Data Siswa:\n";
        Siswa *bantu = top;  
        while (bantu != NULL) {
            cout << "[" << bantu->nSiswa << ", " << bantu->absen << "]\n";
            bantu = bantu->prev; 
        }
        cout << "===============================\n";
    }
}


void editSiswa(string nSiswaCari) {
    if (stackKosong()) {
        cout << "Stack kosong! Tidak ada data untuk diedit.\n";
        return;
    }

    Siswa *bantu = bottom;
    while (bantu != NULL && bantu->nSiswa != nSiswaCari) {
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "Data siswa tidak ditemukan!\n";
    } else {
        cout << "Mengedit data siswa: " << bantu->nSiswa << "\n";
        cout << "Masukkan nSiswa baru: ";
        getline(cin, bantu->nSiswa);
        cout << "Masukkan nomor absen baru: ";
        cin >> bantu->absen;
        cin.ignore();
        cout << "Data siswa berhasil diupdate!\n";
    }
}

// Fungsi-fungsi queue
bool queueKosong() {
    return depan == NULL;
}

void enqueue(string nSiswa, int absen) {
    Antrian *baru = new Antrian();
    baru->nSiswa = nSiswa;
    baru->absen = absen;
    baru->next = NULL;

    if (queueKosong()) {
        depan = baru;
        belakang = baru;
    } else {
        belakang->next = baru;
        belakang = baru;
    }
}

void dequeue() {
    if (queueKosong()) {
        cout << "Antrian kosong, tidak ada siswa yang dilayani.\n";
    } else {
        Antrian *hapus = depan;
        cout << "Melayani siswa \"" << hapus->nSiswa << "\" dengan absen " << hapus->absen << ".\n";
        depan = depan->next;
        delete hapus;
    }
}

void cetakQueue() {
    if (queueKosong()) {
        cout << "Antrian kosong.\n";
    } else {
        cout << "===============================\n";
        cout << "Data Antrian:\n";
        Antrian *bantu = depan;
        while (bantu != NULL) {
            cout << "[" << bantu->nSiswa << " | " << bantu->absen << "]\n";
            bantu = bantu->next;
        }
        cout << "===============================\n";
    }
}

// Fungsi input data
void inputData() {
    int jumlahSiswa;
    cout << "===============================\n";
    cout << "Jumlah Siswa: ";
    cin >> jumlahSiswa;
    cin.ignore();

    for (int i = 1; i <= jumlahSiswa; i++) {
        string nSiswa;
        int absen;
        cout << "Siswa-" << i << "\n";
        cout << "Masukkan Nama Siswa: ";
        getline(cin, nSiswa);
        cout << "Masukkan Absen: ";
        cin >> absen;
        cin.ignore();
        push(nSiswa, absen);
    }
}

void masukkanSemuaKeAntrian() {
    while (!stackKosong()) {
        enqueue(top->nSiswa, top->absen);
        pop();
    }
    cout << "+==============================+\n";
    cout << "| Semua data dari stack telah  |\n";
    cout << "| dimasukkan ke dalam antrian! |\n";
    cout << "+==============================+\n";
}

int main() {
    int pilihan;
    do {
        cout << "+==============================+\n";
        cout << "|            MENU              |\n";
        cout << "+==============================+\n";
        cout << "| 1. Input Data                |\n";
        cout << "| 2. Lihat Data                |\n";
        cout << "| 3. Hapus Data                |\n";
        cout << "| 4. Edit Data                 |\n";
        cout << "| 5. Masukkan ke Dalam Antrian |\n";
        cout << "| 6. Lihat Antrian             |\n";
        cout << "| 7. Layani Antrian            |\n";
        cout << "| 8. Keluar                    |\n";
        cout << "+==============================+\n";
        cout << "Pilihan Menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: 
                inputData(); 
                break;
            case 2: 
                tampilkanSiswa(); 
                break;
            case 3: 
                pop(); 
                break;
            case 4: {
                string nSiswaCari;
                cout << "Masukkan Nama Siswa yang akan diedit: ";
                getline(cin, nSiswaCari);
                editSiswa(nSiswaCari);
                break;
            }
            case 5: 
                masukkanSemuaKeAntrian(); 
                break;
            case 6: 
                cetakQueue(); 
                break;
            case 7: 
                dequeue(); 
                break;
            case 8: 
                cout << "+=================================================+\n";
                cout << "|Senang sekali Anda mau mencoba program ini!      |\n";
                cout << "|Kami berharap program ini memenuhi harapan Anda, |\n";
                cout << "|dan masukan Anda akan sangat berharga bagi kami. |\n";
                cout << "+=================================================+\n";
                break;
            default: 
                cout << "Pilihan tidak valid! Coba lagi.\n";
                break;
        }
    } while (pilihan != 8);
    return 0;
}
