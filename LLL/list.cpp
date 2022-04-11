#include "list.h"

void build(node * & head) {
  srand((unsigned)time(0));
  node* current = new node();
  current->data = (rand()%10 + 1);
  head = current;
  node* previous = current;
  int additionalValues = (rand()&5);
  for (int a = 0; a < 15+additionalValues; a++) {
    current = new node();
    previous->next = current;
    current->data = (rand()%10 + 1);
    previous = current;
  }
  current->next = NULL;
}

void display_all(node * head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

void removeGreater7(node * & head, node* current, node* previous){
  if(head->data > 7){
    node* temp = head;
    head = head->next;
    delete temp;
  }
  else if(current->data > 7){
    node* temp = current;
    previous->next = temp->next;
    current = previous;
    delete temp;
  }
  if(current->next){
      removeGreater7(head, current->next, current);
  }
}
