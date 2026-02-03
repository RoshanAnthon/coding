//tired, lets do it with single ll and finish

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class linkedlist
{
private:
    Node* top;

public:
    linkedlist() : top(nullptr) {}

    void push(int d)
    {
        Node* n = new Node(d);
        cout<<"pushed :"<<n->data<<endl;
        if(!top)
        {
            top = n;
            return;
        }
        n->next = top;
        top = n;
        
    }

    void pop()
    {
        if(!top)
        {
            cout<<"STACK IS EMPTY\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout<<"popped :"<<temp->data<<endl;
        delete temp;
    }

    void traverse()
    {
        Node* temp = top;
        for(Node* temp = top ; temp != nullptr ; temp = temp->next)
            cout<<temp->data<<" ";
        cout<<endl;
    }
};

int main()
{
    linkedlist l;
    l.push(10);
    l.pop();
    l.pop();

    l.traverse();

    l.push(20);
    l.push(30);
    l.push(40);

    l.traverse();
    l.pop();
    l.traverse();
    return 0;
}