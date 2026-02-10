/*
lets do it in 2 ways-- one with normal and other with double pointer--make it perfect
also lets do normal with struct and other with class
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class stack_cls
{
public:
    Node* push(struct Node* h, int x)
    {
        struct Node* n = new Node;
        n->data = x;
        if(!h)
            n->next = NULL;
        else
            n->next = h;
        return n;
    }

    Node* pop(struct Node* h)
    {
        if(!h)
        {
            cout<<"NULL1"<<endl;
            return NULL;
        }
        struct Node* t = h->next;
        delete h;
        return t;
    }

    void traverse(struct Node* h)
    {
        if(!h)
        {
            cout<<"NULL"<<endl;
            return;
        }
        struct Node* t = h;
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<endl;
    }

};

int main()
{
    struct Node* h = NULL;
    stack_cls s;

    h = s.push(h, 10);
    h = s.push(h, 20);
    h = s.push(h, 30);
    h = s.push(h, 40);
    h = s.push(h, 50);

    s.traverse(h);

    h = s.pop(h);
    h = s.pop(h);
    h = s.pop(h);

    s.traverse(h);
    
}