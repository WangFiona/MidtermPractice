//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class clist
{
   public:
   		//These functions are already written
   		clist();			//supplied
   		~clist();		//supplied
   		void build();	//supplied
   		void display();	//supplied

	/* *****************YOUR TURN! ********************* */
	//Write your function prototype here:
  node* returnRear();
  void removeGreater7(node* current, node* previous);
  void copyNot2(node* current, node* ogRear, node* copyCurr, node* head);
  void evenSum(node* current, int & sum);
  void duplicate2(node* current);


	private:
		node * rear;
};
