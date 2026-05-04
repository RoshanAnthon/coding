#include <iostream>
#include <vector>
using namespace std;

class graph
{
    int v;
    vector<vector<int>> edges;

public:
    graph(int n) : v(n), edges(n) {}

    void addedge(int v1, int v2)
    {
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }

    void DFS(int start, vector<int>& visited)
    {
        cout<<start;
        visited[start] =1;

        for(int x: edges[start])
            if(!visited[x])
                DFS(x, visited);

    }

    void BFS(int start)
    {
        vector<int> visited(v, 0);
        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            cout<<front;         

            for(int x: edges[front])
            {
                if(!visited[x])
                {
                    q.push(x);
                    visited[x]=1;
                }
            }
        }
    }
};



int main()
{
    graph g(4);

    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(2,3);

    vector<int> visited(4, 0);
    for(int i=0; i<4; i++)
    {
        if(!visited[i])
            g.DFS(0, visited);
    }

    cout<<endl;
    g.BFS(0);

    /*
    cout<<endl;

    graph g2(8);
    vector<vector<int>> a = {
        {1, 2},     // 0
        {0, 3, 4},  // 1
        {0, 5},     // 2
        {1},        // 3
        {1, 6},     // 4
        {2, 7},     // 5
        {4},        // 6
        {5}         // 7 
    };
    */
}