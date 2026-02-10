/* remember vector is not an array, its a class

Solving it two ways, one with ppinter and one just by address pass -- just for your reference
Only difference it makes is v-> or v. ... accessing function of a pointer class

lets use * in push, and & in pop, dont want to spend time in creating new files
*/

#include <iostream>
#include <vector>
using namespace std;

// there is no full for vector, cos its dynamic, but lets limit
const int MAX = 10;

void push_element(vector<int> *v, int x)
{
    if(v->size() == MAX)
    {
        cout<<"FULL";
        return;
    }

    v->push_back(x);
}

void pop_element(vector<int> &v)
{
    if (v.empty())
    {
        cout<<"Empty";
        return;
    }
    v.pop_back();
}

void traverse(vector<int> *v)
{
    for(int x: *v)
        cout<<x<<" ";
    
    cout<<endl;
}

int main()
{
    vector<int> v;

    push_element(&v, 10);
    push_element(&v, 20);
    push_element(&v, 30);

    traverse(&v);

    pop_element(v);

    traverse(&v);

    pop_element(v);
    pop_element(v);
    pop_element(v);

    //prints nothing
    traverse(&v);


}