/* waste of time---
why do i even need to do double pointer when i can just manage top in the class private?

just read double pointer from my old c code, practice if needed
*/


#include <iostream>
using namespace std;

class Node
{
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class my_stack
{
private:
    Node* top;

public:
    my_stack() : top(nullptr) {}


};

int main()
{
    my_stack s;
    s.push()
}