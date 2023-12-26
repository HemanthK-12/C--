#include<iostream>
#include<vector>
#include<queue>

int main()
{
    int start=1,c=1;
    int vertices;
    cin>>vertices;

    queue<int> q;
    vector<int> bfs;
    vector<int> visited(vertices+1,0);
    vector<int> adj[vertices+1];

    for(int i=0;i<vertices;i++)
    {
        int a,b;
        cin >>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= vertices;i++)
    {
        if (visited[i]==0)
        {
            q.push(i);
             visited[i]=1;
            while(!q.empty())
            {
              int first=q.front();
              q.pop();
              for(auto x:adj[first])
              {
                if(visited[x]==0)
               { 
                visited[x]=1;
                q.push(x);
               }
              }
            }
            c++;
        }
    
    }
    cout<<c<<endl;
    return 0;
}
