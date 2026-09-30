#include <iostream>
using namespace std;

struct NodePemain{
    string nama;
    NodePemain *next;
};

NodePemain *head = nullptr;
NodePemain *tail = nullptr;

void tambahPemain(){
    string nama;
    cout<<"Masukkan Pemain : ";
    getline(cin, nama);

    NodePemain *newNode = new NodePemain();
    newNode->nama = nama;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = tail = newNode;
        tail->next = head;
    }else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void tampilkanPemain(){
    if (head == nullptr) {
        cout<<"Data Pemain Masih Kosong !!!"<<endl;
        return;
    }

    NodePemain *temp = head;
    cout<<"Pemain: ";
    do {
        cout<<temp->nama<<" - ";
        temp = temp->next;
    }while (temp != head);
    cout<<"(kembali ke "<<head->nama<<")"<<endl;
}

void putarPemain(){
    if (head == nullptr) {
        cout<<"Data Pemain Masih Kosong !!!"<<endl;
        return;
    }

    NodePemain *temp = head;
    int putaran;
    int noGiliran = 1;
    cout<<"Mau berapa putaran : ";
    cin>>putaran;
    if (putaran < 1) {
        cout<<"Putaran harus lebih dari 0 !!!"<<endl;
        return;
    }else {
        cout<<"Putaran giliran ("<<putaran<<"x keliling) : "<<endl;
    }
    do {
        cout<<"Giliran "<<noGiliran<<" : "<<temp->nama<<endl;
        temp = temp->next;
        if (temp == head) {
            putaran--;
        }
        noGiliran++;
    }while (putaran > 0);
}

void keluarkanPemain(){
    if (head == nullptr) {
        cout<<"Data Pemain Masih Kosong !!!"<<endl;
        return;
    }

    string nama;
    cout<<"Siapa yang ingin dikelluarkan : ";
    getline(cin,nama);

    NodePemain *bantu = tail, *hapus = head;
    do {
        if (hapus->nama == nama) {
            if (head == tail) {
                head = tail = nullptr;
            }else {
                bantu->next = hapus->next;
                if (hapus == head) {
                    head = hapus->next;
                }
                if (hapus == tail) {
                    tail = bantu;
                }
            }
            delete hapus;
            cout<<"Pemain "<<nama<<" telah dikeluarkan !!!"<<endl;
            return;
        }
        bantu = hapus;
        hapus = hapus->next;
    }while (hapus != head);
    cout<<"Pemain "<<nama<<" tidak ditemukan !!!"<<endl;
}

int main(){
    int pilihan;
    cout<<"=== Program Estafet Giliran (Circular Linked LIst) ==="<<endl;
    cout<<"1. Masukkan Pemain"<<endl;
    cout<<"2. Tampilkan Pemain"<<endl;
    cout<<"3. Putar"<<endl;
    cout<<"4. Keluarkan Pemain"<<endl;
    cout<<"5. Keluar"<<endl;
    do {
        cout<<"Pilihan: ";
        cin>>pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                tambahPemain();
                break;
            case 2:
                tampilkanPemain();
                break;
            case 3:
                putarPemain();
                break;
            case 4:
                keluarkanPemain();
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
