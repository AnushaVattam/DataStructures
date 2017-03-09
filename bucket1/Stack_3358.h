//stack_3358




#ifndef STACK_3358_H
#define STACK_3358_H

#include <cstdlib>  // Provides size_t
#include <cassert>
using namespace std;

template<class ItemType>
class Stack_3358 {

public:

    // typedef int value_type;
    typedef size_t size_type;


    // Default constructor. Creates an empty stack.
    Stack_3358();

    //Copy constructor
    Stack_3358(const Stack_3358 & src);

    //Preconditions: None.
    //Postconditions: Destroys the list, cleaning up all resources associated with the object.
    ~Stack_3358();

    /****************************
    makeEmpty

    Method: Removes all the items from the stack.
    Preconditions: Stack has been initialized
    Postconditions: All the items have been removed
    *****************************/
    void makeEmpty();

    /****************************
    isEmpty

    Method: Checks to see if there are any items on the stack.
    Preconditions: Stack has been initialized
    Postconditions: Returns true if there are no items on the stack, else false.
    *****************************/
    bool isEmpty() const;

    /****************************
    isFull

    Method: Determines if you have any more room to add items to the stack
    Preconditions: Stack has been initialized
    Postconditions: Returns true if there is no more room to add items, else false
    *****************************/
    bool isFull() const;

    /****************************
    push

    Method: Adds newItem to the top of the stack.
    Preconditions: Stack has been initialized and is not full.
    Postconditions: newItem is at the top of the stack.
    *****************************/
    void push(const ItemType &);

    /****************************
    pop

    Method: Removes topItem from stack and returns it.
    Preconditions: Stack has been initialized and is not empty.
    Postconditions: Top element has been removed from stack and item is a copy of the removed element.
    *****************************/
    ItemType pop();
 void display();

private:
    struct Node {
        ItemType value;
        Node *next;
    };

    Node *head;
};

/*******************************
/ Function implementations
********************************/
template<class ItemType>
 Stack_3358<ItemType>::Stack_3358()
{
head = NULL;
}
template<class ItemType>
Stack_3358<ItemType>::Stack_3358(const Stack_3358 & src)
{
  head = NULL ;
  Node *ptr = src.head;
  while(ptr!= NULL)
  {
      push(ptr-> value);
      ptr= ptr-> next;
  }
}
//***************************************************
 // Destructor *
 //***************************************************
template<class ItemType>
Stack_3358<ItemType>::~Stack_3358()
 {
    Node  *p= head;
    while(head!=NULL){
        head=head->next;
        delete p;
    }
    }
//*************************************************************
 // Member function push pushes the argument onto *
 // the stack. *
 //*************************************************************
template<class ItemType>
void Stack_3358<ItemType>::push(const ItemType & num)
 {
  Node *newNode; // Pointer to a new node

 // Allocate a new node and store num there.
newNode = new Node;
newNode->value = num;
newNode->next=NULL;
// If there are no nodes in the list
// make newNode the first node.
if (head==NULL)
{
newNode->next=head;
head =newNode;
}
 else // Otherwise, insert NewNode before top.
 {
newNode->next = head;
head = newNode;
 }
}

//*************************************************************
 // Member function pop pops the value at the top *
// of the stack off, and copies it into the variable *
 // passed as an argument. *
 //*************************************************************
template<class ItemType>
ItemType Stack_3358<ItemType>:: pop()
{
    ItemType num;
if(isEmpty())
    {
    return 0;
    }
else{
        num = head-> value;
    Node * temp;
     temp=head;
     head =head->next;
     delete temp;
}
return num;
}
 template<class ItemType>
void Stack_3358<ItemType>:: makeEmpty(){
Node *p=head ;
Node *n;
while(p)
    {
        n=p;
        p=p->next;
        delete n;
}
}
 //*************************************************************
// Member function isEmpty returns true if the stack *
 // is empty, or false otherwise. *
 //*************************************************************
 template<class ItemType>
 bool Stack_3358<ItemType>::isEmpty() const
 {
    if (head == NULL)
        return true;
    else{
        return false;
    }
}
template<class ItemType>
bool Stack_3358<ItemType>::isFull() const
{
    //We assume that a linked list never gets full
    return false;
}
 template<class ItemType >
void  Stack_3358< ItemType>::display()
{
    Node *ptr;
  ptr = head;
  while(ptr)
{
    cout << ptr-> value << endl;
    ptr=ptr->next;
}
  cout << endl;
}
#endif // STACK_3358_H_INCLUDED

