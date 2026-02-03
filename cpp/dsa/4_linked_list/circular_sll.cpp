#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int d) : data(d), next(this) {}
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
            //head->next = head;
            return;
        }
        //n->next = tail->next;
        n->next = head;
        tail->next = n;
        tail = n;
        return;
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
        Node* temp = head;
        while(temp->next != tail)
            temp = temp->next;
        
        delete tail;
        temp->next = head;
        tail = temp;  
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
        head = n;
        tail->next = head;
        return;

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
        tail->next = head;
        delete temp;
    }

    void traverse()
    {
        if(!head)
            return;

        Node* temp = head;

        //cout<<tail->next->data;
        while(temp->next != head)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        } cout<<temp->data;
        /*
        while( temp != tail)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        } */
        cout<<endl;
            
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
}