/* after researching online, this is the best way we should be coding
what was wrong with my earlier code?
1. i used node itself as linked list, which is not recommended, even though it works. better write 2 classes, 
one for node ( like we have struct in C) other for functions
2. maintain head and tail pointers, so you can optimise time complexity
3. write a descructor which is useful and cleans entire linked list
4. use initialyzer list style to look good 
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    //list style
    Node(int d) : data(d), next(nullptr) {}
};

class Linkedlist
{
private:
    Node* head;
    Node* tail;

public:
    Linkedlist() : head(nullptr), tail(nullptr) {}

    void push_back(int val)
    {
        Node* newnode = new Node(val);
        if(!head)
        {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
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

        Node* temp = head;
        while(temp->next != tail)
            temp = temp->next;
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    void removeval(int val)
    {
        if(!head)
            return;
        
        if(head->data == val)
        {
            Node* temp = head;
            head = head->next;
            if (temp == tail)
                tail = head;
            delete temp;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr && temp->next->data != val)
            temp = temp->next;
        if(temp->next)
        {
            Node* t = temp->next;
            temp->next = t->next;
            if (t == tail)
                tail = temp;
            delete t;
        }
    }

    // const makes sure it just traverses, we cant change head tail etc due to this
    // equivivalent to C void traverse(const struct LinkedList* list);
    void traverse() const
    {
        for (Node* t = head; t; t = t->next)
            cout << t->data << " ";
        cout << endl;
    }

    ~Linkedlist()
    {
        while (head) {
            Node* t = head;
            head = head->next;
            delete t;
        }
    }
};


int main()
{
    Linkedlist list;

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
}