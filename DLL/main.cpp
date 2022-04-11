#include "dlist.h"


int main()
{
    dlist object;
    object.build();
    object.display();

    node* head = object.getHead();

    dlist copyList;
    node* copyNode = copyList.getHead();
    //PLEASE PUT YOUR CODE HERE to call the function assigned

    //object.removeGreater7(head, head);
    //object.removeFirstLast();
    //copyList.copyNot2(head, copyNode);
    //copyList.display();
    int sum = 0;
    //object.returnEvenSum(head, sum);

    //object.duplicate2(head);
    object.insertAtBeginning();
    
    object.display();
    
    return 0;
}
