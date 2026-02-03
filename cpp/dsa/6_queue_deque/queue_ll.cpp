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
    Node* front;
    Node* rear;

public:
    linkedlist() : front(nullptr), rear(nullptr) {}

    void push(int d)
    {
        Node* n = new Node(d);
        if(!front)
        {
            front = rear = n;
            return;
        }
        rear->next = n;
        rear = n;
        
    }

    void pop()
    {
        if(!front)
        {
            cout<<"QUEUE IS EMPTY\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    void traverse()
    {
        Node* temp = front;
        while( temp != nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
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