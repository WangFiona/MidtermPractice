#include "clist.h"

clist::clist() {
  rear = NULL;
}

clist::~clist() {
  node* temp = rear;
  rear = rear->next;
  temp->next = NULL;
  while (rear->next != NULL) {
    temp = rear;
    rear = rear->next;
    delete temp;
  }
  rear->next = NULL;
  delete rear;
}

void clist::build() {
  srand((unsigned)time(0));
  node* current = new node();
  current->data = (rand()%10 + 1);
  rear = current;
  node* previous = current;
  int additionalValues = (rand()%5);
  for (int a = 0; a < 15+additionalValues; a++) {
    current = new node();
    previous->next = current;
    current->data = (rand()%10 + 1);
    previous = current;
  }
  current->next = rear;
}

void clist::display() {
  node* current = rear->next;
  while (current != rear) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << rear->data << " ";
  cout << endl;
}

node* clist::returnRear(){
  return rear;
}

void clist::removeGreater7(node* current, node* previous){
  bool deleted = true;
  if(rear->next == current && current->data > 7){
    node* temp = current;
    rear->next = current->next;
    previous = rear;
    delete temp;
  }
  else if(current == rear && current->data > 7){
    node* temp = current;
    previous->next = rear->next;
    rear=previous;
    delete temp;
  }
  else if(current->data > 7){
    node* temp = current;
    previous->next = temp->next;
    delete temp;
  }
  else{
    if(current!=rear){
      removeGreater7(current->next, current);
      deleted = false;
    }
  }

  if(current != rear && deleted == true){
    removeGreater7(previous->next, previous);
  }
}
