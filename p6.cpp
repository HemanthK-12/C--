#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int vertices;
    cin >> vertices;

    vector<int> graph[vertices+1];
    vector<int> prereq(vertices+1, 0);//stores number of pre-requisites for every course

    for (int i = 1; i <= vertices;i++)
    {
        int k;
        cin >> k;//number of prerequisites
        for (int j = 0; j < k;j++)
        {
            int a;
            cin >> a;
            graph[a].push_back(i);
        }
        prereq[i]=k;
    }

    vector<int> toposort;
    queue<int> q;

    // Enqueue courses with in-degree 0
    for (int i = 1; i <= vertices; i++)
    {
        if (prereq[i] == 0)
            q.push(i);
        //pushing courses with no prerequisites first so that they'll be covered for the other courses first
    }

    while (!q.empty())
    {
        int first = q.front();
        q.pop();
        toposort.push_back(first);

        for (auto x : graph[first])
        {
            // Reduce in-degree of neighbors
            prereq[x]--;//reducing no.of prereq of corresponding elements as it is covered now
            if (prereq[x] == 0)//if in this process,prereq of any course becomes zero,push it to queue
            {
                q.push(x);
            }
        }
    }
    if (toposort.size() == vertices)
    {
        // Print the valid order
        for (int course : toposort)
        {
            cout << course << " ";
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
