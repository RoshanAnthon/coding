// lets try it without any help
#include <iostream>
#include <vector>
#include <algorithm>

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
};

int main()
{
    Node* h = new Node(10);
    h->next = new Node(20);
    h->next->next = new Node(30);
    h->next->next->next = new Node(40);

    while(h != nullptr)
    {
        cout<<h->data<<" ";
        h = h->next;
    }
    cout<<endl;
    return 0;
}