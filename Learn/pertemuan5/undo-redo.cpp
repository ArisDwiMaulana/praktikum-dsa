#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

struct Stack {
    Node* top;
};

void push(Stack& s, string data) {
    Node* baru = new Node;
    baru->data = data;
    baru->next = s.top;
    s.top = baru;
}

string pop(Stack& s) {
    Node* hapus = s.top;
    string hasil = hapus->data;
    s.top = s.top->next;
    delete hapus;
    return hasil;
}

void tampil(string judul, Stack s) {
    Node* bantu = s.top;
    cout << judul << ": ";
    while (bantu != NULL) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

int main() {
    Stack undo;
    Stack redo;
    undo.top = NULL;
    redo.top = NULL;

    int pilih;
    string kata;

    do {
        cout << "\n1. Tulis kata" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Redo" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Kata: ";
            cin >> kata;
            push(undo, kata);
        } else if (pilih == 2) {
            if (undo.top == NULL) {
                cout << "Undo kosong" << endl;
            } else {
                kata = pop(undo);
                push(redo, kata);
            }
        } else if (pilih == 3) {
            if (redo.top == NULL) {
                cout << "Redo kosong" << endl;
            } else {
                kata = pop(redo);
                push(undo, kata);
            }
        }

        tampil("Undo", undo);
        tampil("Redo", redo);

    } while (pilih != 0);

    return 0;
}
