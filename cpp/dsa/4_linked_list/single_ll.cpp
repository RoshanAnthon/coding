#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }

    void insertval(int val)
    {
        Node* temp = this;
        Node* newnode = new Node(val);

        while( temp->next != nullptr)
            temp=temp->next;
        temp->next = newnode;
    }

    void traverse()
    {
        Node* temp = this;
        while(temp != nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    Node* head = new Node(0);
    head->insertval(1);
    head->insertval(2);
    head->insertval(3);
    head->insertval(4);
    head->insertval(5);

    head->traverse();
    return 0;
}