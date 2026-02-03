#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class LinkedList
{
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(int val)
    {
        Node* newnode = new Node(val);
        if(!head)
        {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
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
        Node* tmp = tail;
        tail->prev->next = nullptr;
        tail = tail->prev;
        delete tmp;
    }

    void removeval(int val)
    {
        if(!head)
            return;
        if(head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* tmp = head;
        while(tmp->next != nullptr && tmp->data != val)
            tmp = tmp->next;
        if(tmp->data == val)
        {
            if( tmp == head)
            {
                tmp->next->prev = nullptr;
                head = tmp->next;
                delete tmp;
                return;
            }
            if(tmp == tail)
            {
                //tmp->prev->next = nullptr;
                //tail = tmp;
                tail = tail->prev;
                tail->next = nullptr;
                delete tmp;
                return;
            }
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev; 
            delete tmp;
        }

    }

    // trying something new
    void add(int val, int pos)
    {
        Node* newnode = new Node(val);
        if(!head)
        {
            head = tail = newnode;
            return;
        }
        if(pos == 0)
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            return;
        }
        Node* tmp = head; 
        int count = 0;
        while(tmp && count < pos)
        {
            tmp = tmp->next;
            count++;
        }
        //for( count = 0 ; tmp->next != nullptr && count != pos ; tmp = tmp->next, count++)
        //{}
        if (!tmp)
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            return;
        }
        newnode->next = tmp;
        newnode->prev = tmp->prev;
        tmp->prev->next = newnode;
        tmp->prev = newnode;       
    }

    void traverse() const
    {
        Node* tmp = head;
        for(Node* tmp = head ; tmp ; tmp = tmp->next)
            cout<<tmp->data<<" ";
        cout<<endl;
    }

    void traverse_back()
    {
        for(Node* tmp = tail ; tmp ; tmp = tmp->prev)
            cout<<tmp->data<<" ";
        cout<<endl;
    }
};

int main()
{
    LinkedList list;

    list.push_back(0);
    for (int i = 10; i <= 100; i += 10)
        list.push_back(i);

    list.traverse();

    list.pop_back();
    list.pop_back();
    list.traverse();

    list.removeval(30);
    list.traverse();

    list.removeval(0);
    list.traverse();

    list.removeval(80);
    list.traverse();

    list.removeval(70);
    list.traverse();
   
    list.add(30, 2);
    list.traverse();

    list.traverse_back();

}