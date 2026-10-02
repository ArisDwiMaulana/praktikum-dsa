#include <iostream>
using namespace std;

struct Node{
    int data;
   Node *next;
};

struct linkedStack{
    Node *top;
};

linkedStack stack;

void buatStack(){
    stack.top = nullptr;
}

bool isEmpty(){
    return stack.top == nullptr;
}

void push(int dataBaru){
    Node *newNode = new Node();
    newNode->data = dataBaru;
    newNode->next = stack.top; // sambungkan node baru ke top saat ini
    stack.top = newNode; // pindahkan top ke node baru

    cout<<"Berhasil menambahkan "<<dataBaru<<endl;
}

void pop(){
    if (isEmpty()) {
        cout<<"Stack masih kosong"<<endl;
        return;
    }
    Node *hapus = stack.top;
    cout<<"Berhasil menghapus "<<hapus->data<<endl;
    stack.top = stack.top->next; // geser top ke node di bawahnya
    delete hapus;
}

void peek(){
    if (isEmpty()) {
        cout<<"Stack masih kosong"<<endl;
        return;
    }
    cout<<"Data paling atas di staxk adalah "<<stack.top->data<<endl;
}

void printStack(){
    if (isEmpty()) {
        cout<<"Stack masih kosong"<<endl;
        return;
    }
    cout<<"Data stack (atas ke bawah):";
    Node *temp = stack.top;
    while (temp != nullptr) {
        cout<<temp->data;
        if (temp->next == nullptr) {
            cout<<endl;
        } else {
            cout<<", ";
        }
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    buatStack();
    for (int i = 1; i < 3; i++) {
        push(i + i*10);
    }
    printStack();
    pop();
    printStack();
    peek();
    printStack();
    pop();
    peek();
    return 0;
}
