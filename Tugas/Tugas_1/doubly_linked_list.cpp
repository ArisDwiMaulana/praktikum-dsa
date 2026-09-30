#include <iostream>
using namespace std;

struct NodeLagu{
    string judul;
    float durasi;
    NodeLagu *next;
    NodeLagu *prev;
};

NodeLagu *head = nullptr;
NodeLagu *tail = nullptr;

void tambah(int kondisi){ // 1 untuk akhir, 2 untuk awal
    string judul;
    float durasi;
    if (kondisi == 1) {
        cout<<"Tambah lagu di akhir: ";
    }else if (kondisi == 2) {
        cout<<"Tambah lagu di awal: ";
    }
    getline(cin, judul);
    cout<<"Durasi (menit): ";
    cin>>durasi;

    NodeLagu *newNode = new NodeLagu();
    newNode->judul = judul;
    newNode->durasi = durasi;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (head == nullptr) {
        head = tail = newNode;
    }else if(kondisi == 1) {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }else if(kondisi == 2){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void tampilkan(int kondisi){ // 1 untuk depan -> belakang, 2 untuk belakang -> depan
    if (head == nullptr) {
        cout<<"Playlist kosong!"<<endl;
        return;
    }else if(kondisi == 1){
        NodeLagu *temp = head;
        int nomor = 1;
        cout<<"Playlist (depan -> belakang): "<<endl;
        while(temp != nullptr){
            cout<<nomor<<". "<<temp->judul<<" ("<<temp->durasi<<" menit)"<<endl;
            temp = temp->next;
            nomor++;
        }
    } else if (kondisi == 2) {
        NodeLagu *temp = tail;
        int nomor = 1;
        cout<<"Playlist (belakang -> depan): "<<endl;
        while(temp != nullptr){
            cout<<nomor<<". "<<temp->judul<<" ("<<temp->durasi<<" menit)"<<endl;
            temp = temp->prev;
            nomor++;
        }
    }
}

int main(){
    int pilihan;
    cout<<"=== Playlist (Doubly Linked LIst) ==="<<endl;
    cout<<"1. Tambah Akhir"<<endl;
    cout<<"2. Tambah Awal"<<endl;
    cout<<"3. Tampilkan Playlist (depan -> belakang)"<<endl;
    cout<<"4. Tampilkan Playlist (belakang -> depan)"<<endl;
    cout<<"5. Keluar"<<endl;
    do {
        cout<<"Pilihan: ";
        cin>>pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                tambah(1);
                break;
            case 2:
                tambah(2);
                break;
            case 3:
                tampilkan(1);
                break;
            case 4:
                tampilkan(2);
                break;
            case 5:
                break;
            default:
                cout<<"Pilihan tidak valid!"<<endl;
        }
        cout<<endl;
    }while (pilihan != 5);

    return 0;
}
