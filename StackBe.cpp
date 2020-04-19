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
