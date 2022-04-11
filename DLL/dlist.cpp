#include "dlist.h"

dlist::dlist() {
  head = NULL;
  tail = NULL;
}

dlist::~dlist() {
  while (head != NULL) {
    node* temp = head;
    head = head->next;
    delete temp;
  }
}

node* dlist::getHead(){
  return head;
}

void dlist::build() {
  srand((unsigned)time(0));
  node* current = new node();
  current->data = (rand()%10 + 1);
  head = current;
  current->previous = NULL;
  node* previous = current;
  int additionalValues = (rand()&5);
  for (int a = 0; a < 15+additionalValues; a++) {
    current = new node();
    previous->next = current;
    current->previous = previous;
    current->data = (rand()%10 + 1);
    previous = current;
  }
  tail = current;
  current->next = NULL;
}

void dlist::display() {
  node* current = head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

void dlist::removeGreater7(node* current, node* prev){
  if(head->data > 7){
    head = head->next;
    head->previous = NULL;
  }
  else if(current->data > 7){
    node* temp2 = current;
    prev->next = temp2->next;
    current = prev;
    delete temp2;
  }
  if(current->next){
    removeGreater7(current->next, current);
  }
}

void dlist::removeFirstLast(){
  if(head){
    node* temp = head;
    head = head->next;
    delete temp;
    head->previous = NULL;

    node* temp2 = tail;
    tail = tail->previous;
    tail->next = NULL;
    delete temp2;
  }
}

void dlist::copyNot2(node* current, node* copy){
  if(current->data != 2){
    node* newNode = new node();
    newNode->data = current->data;
    newNode->next = NULL;
    newNode->previous = NULL;

    if(head == NULL){
      head = newNode;
      tail = newNode;
      copy = head;
    }
    else{
      copy->next = newNode;
      newNode->previous = copy;
      tail = newNode;
    }
    copy = newNode;
  }
  if(current->next){
    copyNot2(current->next, copy);
  }
}

void dlist::returnEvenSum(node* current, int &sum){
  if(current->data % 2 == 0){
    sum+=current->data;
  }
  if(current->next){
    returnEvenSum(current->next, sum);
  } else{
    cout << sum << endl;
  }
}
