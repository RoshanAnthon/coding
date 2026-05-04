#include <iostream>
using namespace std;

vector<vector<int>> graph;

void addedges(int v1, int v2)
{
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}

void dfs_traverse(int node, vector<int>& visited)
{
    cout<<node<<" ";
    visited[node]=1;
    
    for(int x: graph[node])
        if(!visited[x])
            dfs_traverse(x, visited);
}

void bfs_traversal(int node, vector<int>& visited)
{
    //cout<<node<<" "
    queue<int> q;
    q.push(node);
    visited[node] =1;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        cout<<front<<" ";
        for(int x: graph[front])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}

int main()
{
    int v=4;
    graph.resize(v);
    vector<int> visited(v,0);
    
    addedges(0,1);
    addedges(0,2);
    addedges(1,3);
    addedges(2,3);

    for(int i=0; i<4; i++)
        if(!visited[i])
            dfs_traverse(i, visited);

    visited.assign(v,0);

    cout<<endl;

    for(int i=0; i<4; i++)
        if(!visited[i])
            bfs_traversal(i, visited);
    

}