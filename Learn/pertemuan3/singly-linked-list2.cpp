#include <iostream>
using namespace std;

struct Node {
  int num;
  Node *next;
};

void tambah_data(Node *&head, int nilai) {
  Node *nodeBaru = new Node();
  nodeBaru->num = nilai;
  nodeBaru->next = head;
  head = nodeBaru;
}

void tampilkan_value(Node *head) {
  Node *temp = head;
  if (temp == nullptr) {
    cout << "linked list kosong" << endl;
  }
  while (temp != nullptr) {
    cout << temp->num << " " << endl;
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  Node *head = nullptr;
  for (int i = 0; i < 10; i++) {
    tambah_data(head, i);
  }
  tampilkan_value(head);

  // cout << head << endl;
  return 0;
}
