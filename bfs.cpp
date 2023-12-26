#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    vector<int> bfs;//This stores the order of breadth first traversal
    queue<int> q;//This temporarily stores the vertices to which we're travelling

    int vertices,edges;
    cin >>vertices >>edges;

    int visited[vertices+1]={0};//Visiting array,marks down if a vertex is visited once.
    vector<int> adj[vertices+1];//AdjacencyList
    
    int n,m;//For storing edges inputted
    for(int i=0;i<edges;i++)
    {
        cin >>n>>m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }
    cout<<"Adjacency List : "<<endl;
    for(int i=1;i<=vertices;i++)//Printing adjacency list
    {
        cout<<i<<" : ";
        for(auto x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    q.push(1); //Assume that 1 is starting node
    visited[1-1]=1;
    while(!q.empty())
    {
        int first=q.front();
        q.pop();
        bfs.push_back(first);
        for(auto x:adj[first])
        {
            if(visited[x-1]==0)
            {
              visited[x-1]=1;
              q.push(x);
            }
        }
    }
    cout<<"BFS Traversal : "<<endl;
    for(auto x:bfs)
    cout <<x<<" ";
    
    return 0;

}