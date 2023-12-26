#include<bits/stdc++.h>
using namespace std;

bool dfs(int par,int i,vector<int> adj[],vector<int> vis,vector<int> parent,vector<int> cycle)
{
    vis[i]=true;
    for(auto x: adj[i])
    {
        if(!vis[x])
        {
            if(dfs(i,x,adj,vis,parent,cycle))
            {
                return true;
            }
        }
        else if(x!=parent[i])
        {
            int current=i;
            while(current!=x)
            {
                cycle.push_back(current);
                current=parent[current];
            }
            cycle.push_back(x);
            return true;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<bool> vis(n+1,false);
    vector<int> parent(n+1,0);
    vector<int> cycle;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&dfs(0,i,adj,vis,parent,cycle))
        {
            for(int i:cycle)
            cout<<i<<" ";
            return 0;
        }
    }
    cout<<"-1";
}
