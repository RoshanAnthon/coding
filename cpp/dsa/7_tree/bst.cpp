#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

class bst
{
private:
    Node* root;

    Node* push(Node* n, int val)
    {
        if(!n)
            return new Node(val);
        if(val < n->data)
            n->left = push(n->left, val);
        else
            n->right = push(n->right, val);
        return n;
    }

    void inorder(Node* node) const
    {
        if (!node) return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }

    bool search(Node* n, int val)
    {
        if(!n)
            return false;
        if(val == n->data)
            return true;
        else if(val< n->data)
            return search(n->left, val);
        else
            return search(n->right, val);
        return false;
    }

    Node* findMin(Node* node)
    {
        while (node->left)
            node = node->left;
        return node;
    }

    Node* remove(Node* node, int val)
    {
        if (!node)
            return nullptr;

        if (val < node->data)
            node->left = remove(node->left, val);

        else if (val > node->data)
            node->right = remove(node->right, val);

        else
        {
            // Case 1 & 2: 0 or 1 child
            if (!node->left)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: two children
            Node* succ = findMin(node->right);
            node->data = succ->data;
            node->right = remove(node->right, succ->data);
        }
        return node;
    }



public:
    bst(): root(nullptr) {}

    void push(int val)
    {
        root = push(root, val);
    }

    void inorder() const
    {
        inorder(root);
        cout<<endl;
    }

    void search(int val)
    {
        if(search(root, val))
            cout<<"found"<<endl;
        else
            cout<<"didnt find"<<endl;
    }

    void remove(int val)
    {
        remove(root, val);
    }

};

int main()
{
    bst t;
    //50, 30, 70, 20, 40, 60, 80
    /* 
        50
       /  \
     30    70
    / \    / \
  20  40  60  80
    
    */

    int a[] = {50, 30, 70, 20, 40, 60, 80 };

    for( int x : a)
    {
        t.push(x);
    }
    t.inorder();

    t.search(60);
    t.search(100);

    t.remove(60);

    t.inorder();
}