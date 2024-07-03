#include <iostream>
#include <iomanip>  
#include <string>
#include <conio.h>  

using namespace std;

// Menampilkan nama dan harga barang dalam bentuk tabel
void displayAvailableItems(const string nama[], const int hrg[], int size) {
    cout << "\t\t\t-----------------------------------------\n";
    cout << "\t\t\t| No | Nama Barang     |  Harga         |\n";
    cout << "\t\t\t-----------------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << "\t\t\t| " << setw(2) << i << " | " << setw(14) << nama[i] << " | Rp. " << setw(10) << hrg[i] << " |\n";
    }
    cout << "\t\t\t-----------------------------------------\n";
}

// Menu login
bool login() {
    string username, password;
    const string correctUsername = "ahmad";
    const string correctPassword = "ridwan";

    cout << "\t\t\t===========================================\n";
    cout << "\t\t\t|                LOGIN MENU               |\n";
    cout << "\t\t\t===========================================\n";

    cout << "\t\t\tUsername: ";
    cin >> username;

    cout << "\t\t\tPassword: ";
    char ch;
    ch = _getch(); // Get character without echo
    while (ch != 13) { // Character 13 is enter
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    cout << endl;

    if (username == correctUsername && password == correctPassword) {
        cout << "\t\t\tSelamat datang di toko kami!" << endl;
        return true;
    } else {
        cout << "\t\t\tLogin gagal. Coba ulangi lagi." << endl;
        return false;
    }
}

int main() {
    const int SIZE = 5;
    string availableItems[SIZE] = {"Beras", "Gula", "Minyak Goreng", "Telur", "Susu"};
    int prices[SIZE] = {12000, 15000, 20000, 22000, 25000};

    string nama[100];
    int hrg[100], jmlh[100], ttlhrg[100];
    int brng, pmbyr, kmbl, k2, tsh;
    string p, buyerName;

    // Jika login gagal, meminta ulang
    while (!login()) {}

    cout << "\t\t\t===========================================\n";
    cout << "\t\t\t|               RRRRRRRRR                 |\n";
    cout << "\t\t\t|               R       RR                |\n";
    cout << "\t\t\t|               R      RR                 |\n";
    cout << "\t\t\t|               R     RR                  |\n";
    cout << "\t\t\t|               R    R                    |\n";
    cout << "\t\t\t|               R       RR                |\n";
    cout << "\t\t\t|               R         RR              |\n";
    cout << "\t\t\t-------------------------------------------\n";
    cout << "\t\t\t================= RIDWAN ================\n";
    cout << "\t\t\t-------------------------------------------\n";
    cout << "\t\t\t|           PROGRAM STRUK TOKO            |\n";
    cout << "\t\t\t-------------------------------------------\n";

    cout << "\t\t\t Masukkan nama pembeli: ";
    cin.ignore();  // 
    getline(cin, buyerName);

    do {
        tsh = 0;
        cout << "\t\t\t Masukkan banyak barang: ";
        cin >> brng;
        
        displayAvailableItems(availableItems, prices, SIZE);

        for (int i = 0; i < brng; i++) {
            int idx;
            cout << "\t\t\t Masukkan nomor barang ke-" << i + 1 << ": ";
            cin >> idx;
            if (idx < 0 || idx >= SIZE) {
                cout << "\t\t\t Nomor barang tidak valid. Ulangi.\n";
                i--;
                continue;
            }
            cout << "\t\t\t Masukkan jumlah barang\t\t: ";
            cin >> jmlh[i];
            nama[i] = availableItems[idx];  
            hrg[i] = prices[idx];    
            cout << endl;
        }

        for (int i = 0; i < brng; i++) {
            ttlhrg[i] = jmlh[i] * hrg[i];
            tsh += ttlhrg[i];
        }
        cout << "\t\t\t Total harga keseluruhan\t: Rp. " << tsh << endl;
        cout << "\t\t\t Masukkan jumlah pembayaran\t: Rp. ";
        cin >> pmbyr;
        kmbl = pmbyr - tsh;

        cout << "\t\t\t=========================================\n";
        cout << "\t\t\t Nama Pembeli: " << buyerName << endl;
        cout << "\t\t\t Daftar belanja anda:\n";
        cout << "\t\t\t-----------------------------------------\n";
        cout << "\t\t\t| No | Nama Barang     | Jumlah |  Harga   |\n";
        cout << "\t\t\t-----------------------------------------\n";
        for (int i = 0; i < brng; i++) {
            cout << "\t\t\t| " << setw(2) << i + 1 << " | " << setw(14) << nama[i] << " | " << setw(6) << jmlh[i] << " | Rp. " << setw(6) << hrg[i] << " |\n";
        }
        cout << "\t\t\t-----------------------------------------\n";

        if (pmbyr >= tsh) {
            cout << "\t\t\t\tTotal harga\t\t: Rp. " << tsh << endl;
            cout << "\t\t\t\tPembayaran\t\t: Rp. " << pmbyr << endl;
            cout << "\t\t\t\tKembalian\t\t: Rp. " << kmbl << endl;
            cout << "\t\t\t|=================================|\n";
            cout << "\t\t\t|          Terimakasih            |\n";
            cout << "\t\t\t|       Telah berbelanja          |\n";
            cout << "\t\t\t|            Di Toko              |\n";
            cout << "\t\t\t|           SERBA ADA             |\n";
        } else {
            k2 = -1 * kmbl;
            cout << "\t\t\tTotal harga\t: Rp. " << tsh << endl;
            cout << "\t\t\tPembayaran\t: Rp. " << pmbyr << endl;
            cout << "\t\t\tKekurangan\t: Rp. " << k2 << endl;
        }
        cout << "\t\t\t===================================\n";

        cout << "\nUlangi (y/t): ";
        cin >> p;
        cin.ignore(); // To ignore the newline character left by cin
    } while (p == "y" || p == "Y");

    cout << "\t\t\t Anda akan keluar dari program ini...\n";
    return 0;
}

//OUTPUT
  ===========================================
                        |                LOGIN MENU               |
                        ===========================================
                        Username: ahmad
                        Password: ******
                        Selamat datang di toko kami!
                        ===========================================
                        |               RRRRRRRRR                 |
                        |               R       RR                |
                        |               R      RR                 |
                        |               R     RR                  |
                        |               R    R                    |
                        |               R       RR                |
                        |               R         RR              |
                        -------------------------------------------
                        ================= RIDWAN ================
                        -------------------------------------------
                        |           PROGRAM STRUK TOKO            |
                        -------------------------------------------
                         Masukkan nama pembeli: ahmad ridwan
                         Masukkan banyak barang: 2
                        -----------------------------------------
                        | No | Nama Barang     |  Harga         |
                        -----------------------------------------
                        |  0 |          Beras | Rp.      12000 |
                        |  1 |           Gula | Rp.      15000 |
                        |  2 |  Minyak Goreng | Rp.      20000 |
                        |  3 |          Telur | Rp.      22000 |
                        |  4 |           Susu | Rp.      25000 |
                        -----------------------------------------
                         Masukkan nomor barang ke-1: 2
                         Masukkan jumlah barang         : 1

                         Masukkan nomor barang ke-2: 2
                         Masukkan jumlah barang         : 1

                         Total harga keseluruhan        : Rp. 40000
                         Masukkan jumlah pembayaran     : Rp. 50000
                        =========================================
                         Nama Pembeli: ahmad ridwan
                         Daftar belanja anda:
                        -----------------------------------------
                        | No | Nama Barang     | Jumlah |  Harga   |
                        -----------------------------------------
                        |  1 |  Minyak Goreng |      1 | Rp.  20000 |
                        |  2 |  Minyak Goreng |      1 | Rp.  20000 |
                        -----------------------------------------
                                Total harga             : Rp. 40000
                                Pembayaran              : Rp. 50000
                                Kembalian               : Rp. 10000
                        |=================================|
                        |          Terimakasih            |
                        |       Telah berbelanja          |
                        |            Di Toko              |
                        |           SERBA ADA             |
                        ===================================

Ulangi (y/t):
