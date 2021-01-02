#include <iostream>
using namespace std;

// Juan Carlos Juárez

struct Node{
  int value;
  Node* next;
  Node(): value(0), next(nullptr){}
  Node(int v): value(v), next(nullptr){}
};

Node* reverseLinkedList(Node* head, int k){
  if(head==nullptr) return head;
  Node* curr=head;
  Node* prev=nullptr;
  Node* next=nullptr;
  while(curr!=nullptr && k>0){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    k--;
  }
  return prev;
}

int main() {
  Node* head= new Node();
  Node* curr=head;
  for(int i=1; i<11; i++){
    curr->next= new Node(i);
    curr=curr->next;
  }
  curr=head->next;
  while(curr!=nullptr){
    cout << curr->value << " ";
    curr=curr->next;
  }
  cout << endl;
  Node* h=head->next;
  int k=4;
  Node* newHead=reverseLinkedList(h,k);
  while(newHead!=nullptr){
    cout << newHead->value << " ";
    newHead=newHead->next;
  }
  return 0;
}

//1100
//0101
