#include <iostream>
using namespace std;

struct node {
  int data;
  node *next;
};

node *head, *tail;

void buatLinkedList() {
  head = NULL;
  tail = NULL;
}

void sisipNode(int dataBaru) {
  node *nodeBaru = new node();
  nodeBaru->data = dataBaru;
  nodeBaru->next = NULL;

  if (head == NULL && tail == NULL) { // sisip saat kosong
    head = nodeBaru;
    tail = nodeBaru;
  } else if (nodeBaru->data < head->data) { // kondisi sisip dari depan
    nodeBaru->next = head;
    head = nodeBaru;
  } else if (nodeBaru->data > tail->data) { // kondisi sisip dari belakang
    tail->next = nodeBaru;
    tail = nodeBaru;
  } else { // kondisi sisip di tengah
    node *temp = head;
    while (temp->next != NULL && nodeBaru->data > temp->next->data) {
      temp = temp->next;
    }
    nodeBaru->next = temp->next;
    temp->next = nodeBaru;
  }
}

void hapusNode(int dataHaous) {
  // jika linked list masih kosong
  if (head == NULL) {
    return;
  }

  // jika headnya yang dihapus
  if (head->data == dataHaous) {
    node *hapus = head;
    head = head->next;
    if (head == NULL) {
      tail = NULL;
    }
    delete hapus;
    return;
  }

  node *temp = head;
  while (temp->next != NULL && temp->next->data != dataHaous) {
    temp = temp->next;
  }

  // jika ynag tail dihapus
  if (temp->next != NULL) {
    node *hapus = temp->next;
    temp->next = hapus->next;
    if (hapus == tail) {
      tail = temp;
    }
    delete hapus;
  }
}

void printLinkedList() {
  node *temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  buatLinkedList();
  sisipNode(800);
  sisipNode(10);
  sisipNode(5);
  sisipNode(117);
  for (int i = 5; i < 10; i++) {
    sisipNode(i);
  }
  printLinkedList();
  hapusNode(5);
  printLinkedList();
  return 0;
}
