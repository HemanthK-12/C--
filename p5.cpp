#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n+1];
    int color[n+1]={0};
    queue<int> q;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            color[i] = 1;
            q.push(i);
            while (!q.empty())
            {
                int first = q.front();
                q.pop();
                for (auto x : graph[first])
                {
                    if (color[x] == 0)//if not coloured
                    {
                        color[x] = 3 - color[first];//switching colour between the two colors,here it changes from 1 to 2 and from 2 to 1
                        q.push(x);
                    }
                    else if (color[x] == color[first])//if coloured same as neighbouring vertices
                    {
                       cout << "NO" << endl;
                       return 0;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
