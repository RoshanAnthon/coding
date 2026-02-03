#include <iostream>
using namespace std;

class stacks
{
private:
    int *arr;
    int top;
    int size;

public:
    stacks(int m) : top(-1), size(m) 
    {
        arr = new int[size];
    }

    bool isempty() const
    {
        return top == -1;
    }

    bool isfull() const
    {
        return top == size-1;
    }

    void push(int d)
    {
        if(isfull())
        {
            cout << "STACK IS FULL\n";
            return;
        }
        arr[++top] = d;
    }

    void pop()
    {
        if(isempty())
        {
            cout << "STACK IS EMPTY\n";
            return;
        }
        --top;
    }

    void traverse()
    {
        if(isempty())
        {
            cout << "STACK IS EMPTY\n";
            return;
        }
        for(int i=0; i<=top; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    ~stacks()
    {
        delete[] arr;
    }

};

int main()
{
    stacks s(10);
    s.push(10);
    s.pop();
    s.pop();

    for(int i=20; i<150 ; i+=10)
        s.push(i);

    s.traverse();
    s.pop();
    s.traverse();
    
    return 0;
}
