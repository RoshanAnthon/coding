#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // write it myself in C programming way
    vector<int> v={1,3,5,2,7,9,4,3};
    int n=v.size();
    cout<<"enter the element to search\n";
    int key;
    cin>>key;
    bool found=false;

    // linear search
    for (int i=0;i<n;i++)
    {
        if (v[i]==key)
        {
            found=true;
            cout<<"element found at index "<<i<<"\n";
            break;
        }
    }
    if (!found)
    {
        cout<<"element not found\n";
    }

    // binary search can be implemented only on sorted arrays or vectors
    // so first we sort the vector
    sort(v.begin(),v.end());
    cout<<"sorted vector is \n";
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\nenter the element to search using binary search\n";
    cin>>key;
    found=false;
    int left=0;
    int right=n-1;
    while (left<=right)
    {
        int mid=left+(right-left)/2;
        if (v[mid]==key)
        {
            found=true;
            cout<<"element found at index "<<mid<<"\n";
            break;
        }
        else if (v[mid]<key)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    if (!found)
    {
        cout<<"element not found\n";
    }

    // BST search can be implemented using recursion
    // hash table search can be implemented using unordered_map in C++
    // Graph search can be implemented using BFS or DFS algorithms
    // pathfinding search can be implemented using Dijkstra's or A* algorithms
    // trie search can be implemented using trie data structure
    // KMP search can be implemented using KMP algorithm for pattern matching

    // ALL above are most asked in interviews
    return 0;


    
}
