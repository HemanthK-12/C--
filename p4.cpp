#include<iostream>
#include<vector>
#include<queue>

using namespace std;
//same as last question but start=1,end=vertices and finally ,parent.size()-1 as length of path.
int main()
{
    int vertices,edges;
    cin >>vertices>> edges;

    vector<int> parent(vertices + 1, 0);
    vector<int> visited(vertices+1,0);
    vector<int> adjacency[vertices+1];
    queue<int> q;

    int a,b;
    for(int i=0;i<edges;i++)
    {
        cin>>a>>b;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }

    q.push(1);
    visited[1]=1;

    while(!q.empty())
    {
        int first=q.front();
        q.pop();
        for(auto i:adjacency[first])
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                q.push(i);
                parent[i]=first;
            }
        }
    }

    vector<int> path;
    int current = vertices;
    while (current != 0)
    {
        path.push_back(current);
        current = parent[current];
    }

    cout << (path.size()-1) << endl;
    for (int j = 0; j < path.size(); j++)
        cout << path[path.size()-j-1] << " ";
   

    return 0;
}