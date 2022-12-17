#include "Stack.h"

void Stack::push(int data)
{
    Node *tmp = new Node(data); //create a new node and sets the data to data
    tmp->next = top; //sets the next pointer to top
    top = tmp; //set the new top to tmp
}

bool Stack::pop()
{
    Node *tmp = top; //store the top of the stack
    if (top ==nullptr) //if the stack is empty, return failure
    {
        return false;
    }
    top = top->next; //set top to the node beneath it
    delete tmp; //delete the original top node
    return true; //return success
}

bool Stack::peek(int &data)
{
    if (top == nullptr) //if the stack is empty return failure
    {
        return false;
    }
    data = top->data; //set data to the data stored at the top
    return true; //return success
} 
void Stack::display(ostream &os)
{
    Node *tmp = top; //set the current temporary node to the top
    while(tmp != nullptr) // loop while temporary is still in the list
    {
        os << tmp->data << " "; //output the data stored in the current node
        
        if (tmp->data == 5) //I noticed 5 was at the end of each line
        {
            cout << endl;
        }
        tmp = tmp->next; //move the temporary node to the next node
        
    }
}
ostream &operator<<(ostream &os, Stack &right)
    {
        right.display(cout); //calls the display method for the Stack
        return os; //returns the updated ostream
    }
Stack::~Stack()
{
    Node *tmp = top; //stores the top in tmp

    while (tmp != nullptr) //while the stack is not empty
    {
        top = top->next; //move to the next node
        delete tmp; //delete the current node
        tmp = top; //set the current node to the next node
    }
}