#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) : data(d), next(this), prev(this) {}
};

class linkedlist
{
private:
    Node* head;
    Node* tail;

public:
    linkedlist() : head(nullptr), tail(nullptr) {}

    void push_back(int d)
    {
        Node* n = new Node(d);
        if(!head)
        {
            head = tail = n;
            return;
        }
        n->next = head;
        n->prev = tail;
        tail->next = n;
        tail = n;
    }

    void pop_back()
    {
        if(!head)
            return;
        
        if(head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = tail;
        tail->prev->next = head;
        tail = tail->prev;
        delete temp;
    }

    void push_head(int d)
    {
        Node* n = new Node(d);
        if(!head)
        {
            head = tail = n;
            return;
        }
        n->next = head;
        n->prev = tail;
        head->prev = n;
        head = n;
        tail->next = head;
    }

    void pop_head()
    {
        if(!head)
            return;
        
        if(head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }

    void traverse()
    {
        if(!head)
            return;
        
        Node* temp = head;
        while(temp->next != head)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        } cout<<temp->data<<endl;
    }

    void traverse_back()
    {
        if(!head)
            return;
        
        Node* temp = tail;
        while(temp->prev != tail)
        {
            cout<<temp->data<<" ";
            temp = temp->prev;
        } cout<<temp->data<<endl;
    }

    void changehead(int d)
    {
        if(!head)
            return;
        Node* temp = head;
        while(temp->next != head && temp->data != d )
            temp = temp->next;

        if(temp->next != head || temp->data == d) // without second condition if tail element given logic dont work
        {
            head = temp;
            tail = head->prev;
        }
    }
};

int main()
{
    linkedlist list;

    list.push_back(0);
    for (int i = 10; i <= 100; i += 10)
        list.push_back(i);

    list.traverse();

    list.pop_back();
    list.pop_back();
    list.traverse();

    list.push_head(1);
    //list.removeval(30);
    list.traverse();

    list.pop_head();
    //list.removeval(0);
    list.traverse();
    list.traverse_back();

    list.changehead(40);
    list.traverse();

    list.changehead(30);
    list.traverse();

    list.changehead(30);
    list.traverse();
}