#include <iostream>
using namespace std;

struct NodeMhs{
    int NIM;
    string nama;
    float IPK;
    NodeMhs *next;
};

NodeMhs *head = nullptr;
NodeMhs *tail = nullptr;

void tambahData(int nim, string nama, float ipk){
    NodeMhs *newNode = new NodeMhs();
    newNode->NIM = nim;
    newNode->nama = nama;
    newNode->IPK = ipk;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void menuTambahData(){
    int nim;
    string nama;
    float ipk;

    cout<<"Masukan NIM: ";
    cin>>nim;
    cin.ignore();
    cout<<"Masukan Nama: ";
    getline(cin, nama);
    cout<<"Masukan IPK: ";
    cin>>ipk;
    tambahData(nim, nama, ipk);
}

void hapusData(int nim){
    // jika linked list masih kosong
    if (head == NULL) {
      return;
    }

    string nama;
    // jika headnya yang dihapus
    if (head->NIM == nim) {
      nama = head->nama;
      NodeMhs *hapus = head;
      head = head->next;
      if (head == NULL) {
        tail = NULL;
      }
      delete hapus;
      cout<<"NIM "<<nim<<" ("<<nama<<") berhasil dihapus"<<endl;
      return;
    }

    bool berhasil = false;
    NodeMhs *temp = head;
    while (temp->next != NULL && temp->next->NIM != nim) {
      temp = temp->next;
    }

    // jika ynag tail dihapus
    if (temp->next != NULL) {
      nama = temp->next->nama;
      NodeMhs *hapus = temp->next;
      temp->next = hapus->next;
      if (hapus == tail) {
        tail = temp;
      }
      delete hapus;
      berhasil = true;
    }

    if(berhasil){
        cout<<"NIM "<<nim<<" ("<<nama<<") berhasil dihapus"<<endl;
    }else {
        cout<<"NIM "<<nim<<" tidak ditemukan"<<endl;
    }
}

void menuHapusData(){
    if (head == nullptr) {
        cout<<"Data masih kosong !!!"<<endl;
        return;
    }
    int nim;
    cout<<"Masukan NIM yang akan dihapus: ";
    cin>>nim;
    hapusData(nim);
}

void tampilkanData(){
    NodeMhs *temp = head;
    if (temp == nullptr) {
        cout<<"Data masih kosong !!!"<<endl;
        return;
    }
    int nomor = 1;
    while (temp != nullptr) {
        cout<<"["<<nomor<<"] "<<temp->NIM<<" - "<<temp->nama<<" - IPK "<<temp->IPK<<endl;
        temp = temp->next;
        nomor++;
    }
}

int main(){
    int pilihan;
    cout<<"=== Program Data Mahasiswa (Singly Linked LIst) ==="<<endl;
    cout<<"1. Tambah Data"<<endl;
    cout<<"2. Hapus Data"<<endl;
    cout<<"3. Tampilkan Data"<<endl;
    cout<<"0. Keluar"<<endl;
    do {
        cout<<"Pilihan: ";
        cin>>pilihan;
        switch (pilihan) {
            case 1:
                menuTambahData();
                break;
            case 2:
                menuHapusData();
                break;
            case 3:
                cout<<"Isi list saat ini: "<<endl;
                tampilkanData();
                break;
            case 0:
                break;
            default:
                cout<<"Pilihan tidak valid!"<<endl;
        }
        cout<<endl;
    }while (pilihan != 0);
    return 0;
}
