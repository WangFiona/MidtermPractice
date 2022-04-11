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

void clist::copyNot2(node* current, node* ogRear, node* copyCurr, node* head){
  if(current->data != 2){
    node* newNode = new node();
    newNode->data = current->data;

    if(rear==NULL){
      newNode->next = newNode;
      rear = newNode;
      head = rear;
    }
    else{
      copyCurr->next = newNode;
      rear = newNode;
      newNode->next = head;
    }
    copyCurr = newNode;
  }

  if(current != ogRear){
    copyNot2(current->next, ogRear, copyCurr, head);
  }
}

void clist::evenSum(node* current, int & sum){
  if(current->data % 2 == 0){
    sum += current->data;
  }
  if(current != rear){
    evenSum(current->next, sum);
  } else{
    cout << sum << endl;
  }
}

void clist::duplicate2(node* current){
  bool duplicated = true;
  node* duplicate = new node();
  if(current->data == 2){
    duplicate->data = current->data;
    
    if(rear == current){ //insert at end
      node* head = rear->next;
      current->next = duplicate;
      rear = duplicate;
      duplicate->next = head;
    }
    else{
      node* temp = current->next;
      current->next = duplicate;
      duplicate->next = temp;
    }
  }
  else{
    if(current != rear){
      duplicate2(current->next);
      duplicated = false;
    }
    else{
      return;
    }
  }

  if(duplicate != rear && duplicated == true){
    duplicate2(duplicate->next);
  }
}
