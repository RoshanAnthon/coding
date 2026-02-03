// its actually waste to write this, vector already works with stack
/* for knowledge there is one more data type which works with stacks

#include <stack>

stack<int> s;
s.push(10);
s.pop();
s.top();
s.empty();

*/



#include <iostream>
using namespace std;

class stacks
{
private:
    vector<int> a;

public:

    bool isempty() const
    {
        return a.empty();
    }

    void push(int d)
    {
        a.push_back(d);
    }

    void pop()
    {
        if(isempty())
        {
            cout<<" STACK IS EMPTY\n";
            return;
        }
        a.pop_back();
    }

    void traverse()
    {
        if(isempty())
        {
            cout<<" STACK IS EMPTY\n";
            return;
        }
        for(int i=0; i<a.size() ; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    stacks s;
    s.push(10);
    s.pop();
    s.pop();

    s.traverse();

    s.push(10);
    s.push(20);
    s.push(30);

    s.traverse();

    return 0;
}