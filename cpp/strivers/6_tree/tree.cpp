/* very basic concept, not using classes, objects etc
next level, use class encapsulation, maintain the tree node, and do all these operations
for now this looks like a basic C programming implementation
*/

#include <cstddef>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

void inorder_rec( Node* curr)
{
    if(!curr) return;

    inorder_rec(curr->left);
    cout<<curr->data<<" ";
    inorder_rec(curr->right);
}

void preorder_rec(Node* curr)
{
    if(!curr) return;

    cout<<curr->data<<" ";
    preorder_rec(curr->left);
    preorder_rec(curr->right);
}

void postorder_rec(Node* curr)
{
    if(!curr) return;

    postorder_rec(curr->left);
    postorder_rec(curr->right);
    cout<<curr->data<<" ";
}


void inorder_iterative(Node* curr)
{
    if(!curr) return;
    stack<Node*> s;

    while(curr || !s.empty())
    {
        while(curr)
        {
            s.push(curr);
            curr=curr->left;
        }

        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }

}

void preorder_iterative(Node* curr)
{
    if(!curr) return;
    stack<Node*> s;

    while(curr || !s.empty())
    {
        while(curr)
        {
            cout<<curr->data<<" ";
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        curr = curr->right;
    }

}

//re do when you get time

void postoder_iterative_dual_stack(Node* curr)
{
    if(!curr) return;

    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(curr);

    while(!s1.empty())
    {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left)
            s1.push(curr->left);
        if(curr->right)
            s1.push(curr->right);
    }

    while(!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

void postorder_iterative(Node* curr)
{
    //postoder_iterative_dual_stack(curr);
    if(!curr) return;
    stack<Node*> s;
    Node* lastvisited=nullptr;

    while(curr || !s.empty())
    {
        if(curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        else 
        {
            Node* top = s.top();
            if(top->right && top->right != lastvisited)
            {
                curr = top->right;
            }
            else 
            {
                cout<<top->data<<" ";
                lastvisited = top;
                s.pop();
            }
        }
    }


}

void level_order(Node* curr)
{
    if(!curr) return;
    queue<Node*> q;
    q.push(curr);

    while(!q.empty())
    {
        cout<<q.front()->data<<" ";

        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right) q.push(q.front()->right);

        q.pop();

    }

}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node( 11);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node( 13);

    
    //DFS
    inorder_rec(root);
    cout<<endl;
    preorder_rec(root);
    cout<<endl;
    postorder_rec(root);
    cout<<endl;

    inorder_iterative(root);
    cout<<endl;

    preorder_iterative(root);
    cout<<endl;
    
    postorder_iterative(root);
    cout<<endl;

    //BFS
    level_order(root);

    //operations?



    return 0;
}