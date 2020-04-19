#include <iostream>
using namespace std;

/*	Struct DataBarang
	Barang[5] -> variabel bertipe array dari struct DataBarang
*/
struct DataBarang {
	char nama[35];
	int stok;
} Barang[5];

/*	Prosedur untuk tukar posisi
	Disimpan ke alamat memori variabel
	Biar bisa dicetak di main() dengan data sudah urut
*/
void tukarPosisi(DataBarang* Brg_1, DataBarang* Brg_2) {
	DataBarang temp = *Brg_1;
	*Brg_1 = *Brg_2;
	*Brg_2 = temp;
}

// function buat bagian untuk data yang belum urut dan udah urut
int bagian(DataBarang barang[], int min, int max) {
	// Ambil stok awal sebagai acuan
	int acuan = barang[max].stok;
	int index_min = min - 1;

	for (int i = min; i <= max - 1; i++)
	{
		// Cek stok barang lebih kecil dari acuan atau tidak
		if (barang[i].stok < acuan)
		{
			// Tambah index_min untuk cek selanjutnya
			index_min++;

			// Tukar stok yg kecil
			tukarPosisi(&barang[index_min], &barang[i]);
		}

		// Tukar stok max
		tukarPosisi(&barang[index_min + 1], &barang[max]);

		// Return untuk posisi index baru untuk pengurutan berikutnya
		return index_min + 1;
	}
}

void quickSort(DataBarang barang[], int min, int max) {
	// Pengecekan stok
	if (min < max) {
		int bag = bagian(barang, min, max);

		// Pembagian kedalam 2 bagain, sebelum diurutkan dan sesudah
		quickSort(barang, min, bag - 1);
		quickSort(barang, bag + 1, max);
	}
}

int main() {
	// Input data barang manual
	Barang[0] = {"Beras", 8};
	Barang[1] = {"Gula", 5};
	Barang[2] = {"Sabun", 12};
	Barang[3] = {"Handuk", 16};
	Barang[4] = {"Garam", 9};

	// Banyak barang
	int n = 5;

	// Cetak data barang
	cout << "-> Data barang awal :\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "Barang " << i << " : " << Barang[i].nama << ", " << Barang[i].stok;
		cout << endl;
	}
	cout << endl;

	// Pengurutan data
	quickSort(Barang, 0, n - 1);

	// Cetak data setelah urut
	cout << "Data setelah urut :\n";

	for (int i = 0; i < 5; i++)
	{
		cout << "Barang " << i << " : " << Barang[i].nama << ", " << Barang[i].stok;
		cout << endl;
	}
}







//struct stack
//{
//    char barang[10];
//    int top, data[MAX];
//} tumpukan;
//
//void init()
//{
//    tumpukan.top = -1;
//}
//
//bool isEmpty()
//{
//    return tumpukan.top < 0;
//}
//
//bool isFull()
//{
//    return tumpukan.top == MAX - 1;
//}
//
//void push()
//{
//    if (isFull())
//    {
//        cout << "\nTumpukan barang mencapai batas maksimal (penuh)";
//    }
//    else
//    {
//        tumpukan.top++;
//        cout << "Masukkan barang  : ";
//        cin >> tumpukan.barang[tumpukan.top];
//        cout << endl << tumpukan.barang[tumpukan.top] << " masuk kedalam tumpukan";
//    }
//}
//
//void pop()
//{
//    if (isEmpty())
//    {
//        cout << "\nTumpukan barang mencapai batas minimum (kosong)";
//    }
//    else
//    {
//        cout << endl << tumpukan.barang[tumpukan.top] << " diambil dari tumpukan";
//        tumpukan.top--;
//    }
//}
//
//void view(int n)
//{
//    if (tumpukan.top > 0)
//    {
//        cout << "\nBerikut adalah urutan tumpukan : \n";
//        for (int e = n; e >= 0; e--)
//        {
//            cout << "   " << tumpukan.barang[e] << endl;
//        }
//    }
//    else
//        cout << "\nTidak ada barang yang tersimpan (kosong)";
//}
//
//void clear()
//{
//    tumpukan.top = -1;
//}
//
//int main()
//{
//    int pilihan;
//    tumpukan.top = 0;
//    init();
//    do
//    {
//        cout << "\n==========================================================\n"
//            << "1. Memasukkan data   (push)\n"
//            << "2. Mengeluarkan data (pop)\n"
//            << "3. Melihat data      (view)\n"
//            << "4. Menghapus data    (clear)\n"
//            << "5. Keluar            (quit)\n"
//            << "Masukkan pilihan : "; cin >> pilihan;
//        switch (pilihan)
//        {
//        case 1:
//            push();
//            break;
//        case 2:
//            pop();
//            break;
//        case 3:
//            view(tumpukan.top);
//            break;
//        case 4:
//            clear();
//            break;
//        }
//    } while (pilihan == 1 || 2 || 3 || 4);
//}
