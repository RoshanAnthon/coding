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
        while(temp->next != nullptr)
            temp = temp->next;
        temp->next = new Node(val);
    }

    Node* poptail()
    {
        Node* temp = this;
        if(temp == nullptr)
            return this;
        if(temp->next == nullptr)
        {
            cout<<"head has no family -- suiciding";
            delete temp;
            return nullptr;
        }
        while(temp->next->next != nullptr)
            temp = temp->next;
        //Node* freemem = temp->next;
        //temp->next =nullptr;
        //delete freemem;
        delete temp->next;
        temp->next = nullptr;
        return this;
    }

    Node* removeval(int val)
    {
        Node* temp = this;
        if(temp == nullptr)
        {
            cout<<"head is null";
            return this;
        } 
        if(temp->data == val)
        {
            cout<<"removing head, orphan family ...sad\n";
            Node* freeval = temp;
            Node* return_node = temp->next;
            delete freeval;
            return return_node;
        }
        while((temp->next != nullptr) && (temp->next->data != val))
            temp = temp->next;
        
        if(temp->next != nullptr)
        {
            cout<<"found the value "<<temp->next->data<<" removing it from the linked list";
            Node* freeval = temp->next;
            temp->next = freeval->next;
            delete freeval;
            return this;
        } 
        return this;

    }

    void traverse()
    {
        //Node* temp = this;
        //while(temp != nullptr)
        for( Node* temp = this ; temp != nullptr ; temp = temp->next)
        {
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }

    ~Node() = default;
    //delete next;
    
};

int main()
{
    Node* head = new Node(0);
    
    //lets test single head case
    head = head->poptail();

    //i made it null linked list
    if (head == nullptr)
        head = new Node(1);
    
    //test it for couple
    head->insertval(2);

    head = head->poptail();
    for(int i=10;i<101;i+=10)
    {
        head->insertval(i);
    }

    head->traverse();
    head = head->poptail();
    head = head->poptail();
    head->traverse();
    cout<<endl;
    head = head->removeval(30);
    cout<<endl;
    head->traverse();

    //lets try to remove head
    head = head->removeval(1);
    head->traverse();

    //delete head;
}