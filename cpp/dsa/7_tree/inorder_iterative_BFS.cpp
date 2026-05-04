//without using recusrsion, using stacks

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

void inorder_iterative(Node* root)
{
    Node* curr = root;
    stack<Node*> st;

    while( curr != nullptr || !st.empty())
    {
        while( curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        
        curr = st.top();
        cout<<curr->data<<" ";
        st.pop();
        curr = curr->right;

    }

}

void BFS(Node* root) 
{
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main()
{
     /*
            10
           / \
          20   30
         / \
        40   50

    */
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    inorder_iterative(root);
    cout<<endl;
    BFS(root);
}


