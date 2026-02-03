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

class binarytree
{
private:
    Node* root;

    void inorder(Node* node) const
    {
        if (!node) return;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }

    void preorder(Node* node) const
    {
        if (!node) return;
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) const
    {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }

    void dfs(Node* n) const
    {
        if (!n) return;

        cout << n->data;   // preorder
        dfs(n->left);
        cout << n->data;   // inorder
        dfs(n->right);
        cout << n->data;   // postorder
    
    }

public:
    binarytree() : root(nullptr) {}

    Node* getroot() const
    {
        return root;
    }

    void setroot(Node* r)
    {
        root = r;
    }

    void inorder() const
    {
        inorder(root);
        cout<<endl;
    }

    void preorder() const
    {
        preorder(root);
        cout<<endl;
    }

    void postorder() const
    {
        postorder(root);
        cout<<endl;
    }
    void dfs() const
    {
        dfs(root);
        cout<<endl;
    }
};

int main()
{
    binarytree tree;

    // Manually build tree
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    tree.setroot(root);

    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.dfs(); // comment based on what you need
}