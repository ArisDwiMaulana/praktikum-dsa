#include <iostream>
#include <iterator>
using namespace std;

struct Node {
  int data;
  Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

bool listKosong() { return head == nullptr; }

void sisipNode(int dataBaru) {
  Node *newNode = new Node;
  newNode->data = dataBaru;
  newNode->next = nullptr;

  if (listKosong()) {
    head = newNode;
    tail = newNode;
    newNode->next = head;
  } else if (dataBaru < head->data) { // sisip dari depan
    newNode->next = head;
    head = newNode;
    tail->next = head;
  } else if (dataBaru >= tail->data) { // sisip dari belakang
    tail->next = newNode;
    tail = newNode;
    tail->next = head;
  } else {
    Node *temp = head;
    while (temp->next != head && temp->next->data <= dataBaru) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void hapusNode(int dataHapus) {
  if (listKosong()) {
    cout << "List kosong, tidak ada yang bisa dihapus." << endl;
    return;
  }
  Node *temp = tail;
  Node *hapus = head;
  do {
    if (hapus->data == dataHapus) {
      if (head == tail) {
        head = tail = nullptr;
      } else {
        temp->next = hapus->next;
        if (hapus == head) {
          head = hapus->next;
        }

        if (hapus == tail) {
          tail = temp;
        }
      }
      delete hapus;
      cout << "Node dengan data " << dataHapus << " berhasil dihapus." << endl;
      return;
    }
    temp = hapus;
    hapus = hapus->next;
  } while (hapus != head);
  cout << "Node dengan data " << dataHapus << " tidak ditemukan." << endl;
}

void printNode() {
  if (listKosong()) {
    cout << "List kosong." << endl;
    return;
  }
  Node *temp = head;
  do {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != head);
  cout << endl;
}

int main() {
  sisipNode(2);
  sisipNode(1);
  sisipNode(9);
  sisipNode(11);
  printNode();
  hapusNode(9);
  printNode();
  hapusNode(100);
  return 0;
}
