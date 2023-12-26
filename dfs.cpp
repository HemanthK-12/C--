#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main()
{
    int vertices,edges;
    cin >>vertices>>edges;
    vector<int> dfs;
    vector<int> visited(vertices+1,0);
    vector<int> adj[vertices+1];
    stack<int> s;

    for(int i=0;i<edges;i++)
    {
        int n,m;
        cin>>n>>m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }

    int start;
    cin>>start;

    s.push(start);
    visited[start]=1;

    while(!s.empty())
    {
        int first=s.top();
        s.pop();
        dfs.push_back(first);
        for(auto x:adj[first])
        {
            if(visited[x]==0)
            {
                visited[x]=1;
                s.push(x);
            }
        }
    }

    for(auto i:dfs)
    cout << i<<" ";
}