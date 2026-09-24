#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node *head, *tail = nullptr;

bool listKosong(){
    return head == nullptr;
}

void sisipNode(int dataBaru){
    Node *newNode = new Node();
    newNode->data = dataBaru;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if(listKosong()){
        head = tail = newNode;
    } else if(dataBaru < head->data){ // sisip di awal
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if(dataBaru >= tail->data) {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }else{
        Node *temp = head;
        while(temp->next != nullptr && temp->next->data < dataBaru){
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void printLinkedList(){
    if(listKosong()){
        cout<<"List masih kosong"<<endl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void hapusNode(int hapusData){
    if (listKosong()) {
        cout<<"List masih kosong"<<endl;
        return;
    }

    if (hapusData == head->data) {
        Node *hapus = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete hapus;
        cout<<"Node "<<hapusData<<" berhasil dihapus"<<endl;
        return;
    }

    // mencari node
    Node *temp = head->next;
    while (temp != nullptr && temp->data != hapusData) {
        temp = temp->next;
    }

    if(temp != nullptr){
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp == tail) {
            tail = temp->prev;
        }
        delete temp;
        cout<<"Node "<<hapusData<<" berhasil dihapus"<<endl;
    } else {
        cout<<"Node "<<hapusData<<" tidak ditemukan"<<endl;
    }

}

int main(){
    sisipNode(7);
    sisipNode(2);
    sisipNode(10);
    printLinkedList();
    hapusNode(7);
    printLinkedList();
    return 0;
}
