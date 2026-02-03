/*
Dont panic, graph is very simple if understood. 
1----2
|.   |
3----4

so here adjuststancy matric if we prepare
1 = {2,3}
2 = {1,4}
3 = {1,4}
4 = {2,3}

if have to display it by BFS without repeat -> 1,2,3,4

how do we list it or maintain in
nodes we can store in a vector as visited matrix
adjustancy list by double vector

lets start

*/





#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class graph
{
private:
    int V;
    vector<vector<int>> adj;

public:
    graph(int v) : V(v), adj(v) {}

    void addedge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            cout<<node<<" ";
            for(int n : adj[node])
            {
                if(!visited[n])
                {
                    visited[n] = true;
                    q.push(n);
                }
            }
        }
    }

    void DFS(int node, vector<bool> &visited2)
    {
        visited2[node] = true;
        cout<<node<<" ";

        for(int nbr : adj[node])
            if(!visited2[nbr])
                DFS(nbr, visited2);

    /* for disconnected nodes like below-- interviewers favt 
        0--1   2--3
        */
        for (int i = 0; i < V; i++)
            if (!visited2[i])
                DFS(i, visited2);
    }
/* to avoid passing visited from main, can use one wrapper --- interviewers prefer this
    void DFSUtil(int node, vector<bool>& visited)
    {

    }
    void DFS(int start)
    {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
        */
};

int main()
{
    graph g(4);

    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(2,3);

    g.BFS(0);

    // lets try DFS logic
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

    for(int u = 0 ; u< a.size(); u++)
    {
        for( int v: a[u])
        {
             if (u < v) // to avoid duplicate elements, can skip, but better to have
                g2.addedge(u,v);
        }
            
    }

    
    vector<bool> visited2(8, false);

    g2.DFS(0, visited2);

}

/* BSF logic

1. define a visited vector for 4 (total) nodes, assign it to false
2. define a queue

start with first node 0
push 0 to queue, and mark visited of 0 as true

start a loop till queue is empty

define a node to point to front of node & pop the queue ( in first que now is empty)
print that node ( printed 0)

now starte a for loop to go through every adjustant list of node (0)
check if that node is already marked as visited, if not then proceed, mark it as visited and push it into the queue

Thats it!!


*/


// things to do, BFS, DFS without using recursion - stacks, queue ( check trees)