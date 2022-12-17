#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node():data(0), next(nullptr) {} //default sets data to 0, and points to nullptr
    Node(int data): data(data), next(nullptr) {} //sets int data, and points to nullptr
    Node(int data, Node *next): data(data), next(next) {} //sets data and points to next

};

class Stack
{
    private:
    Node *top;

    public:
    Stack(): top(nullptr) {}
    ~Stack(); //destroys the stack

    void push(int data); //inserts to the top of the stack
    bool pop(); //removes the item at the top of the stack
    bool peek(int &data); //returns the item at the top of the stack
    void display(ostream &os);
    
    friend ostream &operator<<(ostream &os, Stack &right);
    
};