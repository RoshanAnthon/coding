// enough of practicing stuff, lets do it now
// thing to remember here, no next or prev pointer is null! -- unless there is not even a head!
// in single head, next is also head, previous is also head!
// sentinel node - using a dummy node which will eleminate most null checks. why? 
// cos no matter list there or not, this dummy link always be there

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
    Node sentinel;

public:
    linkedlist() : sentinel(0) {}
    /*
    {
        sentinel.next = &sentinel;
        sentinel.prev = &sentinel;
    }
        */

    bool empty() const
    {
        return sentinel.next == &sentinel;
    }
    void push_back(int d)
    {
        Node* n = new Node(d);

        n->prev = sentinel.prev;
        n->next = &sentinel;

        sentinel.prev->next = n;
        sentinel.prev = n;
    }

    void pop_back()
    {
        if (empty())
            return;
        Node* temp = sentinel.prev;
        //sentinel.prev->prev->next = &sentinel;
        //sentinel.prev = sentinel.prev->prev;
        temp->prev->next = &sentinel;
        sentinel.prev = temp->prev;
        delete temp;
    }

    void push_head(int d)
    {
        Node* n = new Node(d);

        n->prev = &sentinel;
        n->next = sentinel.next;

        sentinel.next->prev = n;
        sentinel.next = n;

    }

    void pop_head()
    {
        if(empty())
            return;
        
        Node* temp= sentinel.next;
        sentinel.next = sentinel.next->next;
        sentinel.next->prev = &sentinel;
        delete temp;
        
    }

    void changehead(int d)
    {
        if(empty())
            return;

        Node* temp = sentinel.next;
        while( temp != &sentinel && temp->data != d)
            temp = temp->next;
        if(temp != &sentinel)
        {
            sentinel.prev->next = sentinel.next;
            sentinel.next->prev = sentinel.prev;

            temp->prev->next = &sentinel;

            sentinel.prev = temp;
            sentinel.next = temp;

        }
    }

    void traverse()
    {
        Node* temp = sentinel.next;
        while(temp != &sentinel)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
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

    list.push_head(80);
    list.traverse();

    list.pop_head();
    list.traverse();

    list.changehead(40);
    list.traverse();
    
}