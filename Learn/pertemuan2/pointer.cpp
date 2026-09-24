#include <iostream>
using namespace std;

struct mahasiswa {
  string nama;
  int umur;
  float tinggi;
};

void bonus(int *nilaiptr) { *nilaiptr += 80; }

int main() {
  int nilai = 80;

  // int *ptr = &nilai;                   // inisialisasi pointer
  // cout << "nilai = " << nilai << endl; // cetak value nilai
  // cout << &nilai << endl;              // cetak alamat niali
  // cout << *ptr << endl;                // ambil nilai via alamat
  // cout << ptr << endl;
  //
  // *ptr = 90;
  // cout << nilai << endl;

  // PENGECEKAN NULL POINTER
  // int *ptr = nullptr;
  // if (ptr != nullptr) {
  //   cout << *ptr << endl;
  // }

  // POINTER STRUCT
  // mahasiswa mhs;
  // mahasiswa *ptr = &mhs;
  // ptr->nama = "Agus";
  // ptr->umur = 20;
  // ptr->tinggi = 170.5;
  //
  // cout << mhs.nama << " " << mhs.umur << " " << mhs.tinggi << endl;

  // POINTER SEBAGAI PARAMETER FUNGSI
  bonus(&nilai);
  cout << nilai << endl;

  return 0;
}
