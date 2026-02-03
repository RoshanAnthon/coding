#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class hash_basic
{
    
    int count;
    vector<vector<int>> table;

public:
    hash_basic(int size)
    {
        count=size;
        table.resize(count);
    }

    void insert(int k)
    {
        int i=hashlogic(k);
        //table[i] = k;
        table[i].push_back(k);
    }

    void remove(int k)
    {
        int i=hashlogic(k);
        auto it=find(table[i].begin(),table[i].end(),k);

        if(it!=table[i].end())
            table[i].erase(it);
    }

    void display()
    {
        for(int i=0;i<count;i++)
        {
            cout<<i<<" -> ";
            for(auto x:table[i])
                cout<<x<<" ";
            cout<<endl;
        }
    }

    private:
    int hashlogic(int k)
    {
        return k%count;
    }
};

int main()
{
    vector<int> key={10,20,15,7,32,9,4,12,6,5};
    hash_basic h(10);

    for(auto x:key)
        h.insert(x);
    
    h.remove(9);
    h.display();

    return 0;
}