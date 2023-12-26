#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int vertices;
    cin >>vertices;
    int edges=vertices-1;//since it is tree

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
    int start,end;
    cin>>start>>end;

    q.push(start);
    visited[start]=1;

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
    int current = end;
    while (current != 0)
    {
        path.push_back(current);
        current = parent[current];
    }

    cout << path.size() << endl;
    for (int j = 0; j < path.size(); j++)
        cout << path[path.size()-j-1] << " ";
   

    return 0;
}