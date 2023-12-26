#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n,m,x,y;
    cin >> n >> m>>x>>y;
    vector<int> adj[n+1];
    vector<int> visited(n + 1, 0);

    for (int i = 0; i < m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }




    return 0;
}
