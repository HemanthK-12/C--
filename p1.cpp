#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int length;
    cin >>length;

    vector<int> deg;
    queue<int> q;
    int a;
    for(int i = 0; i < length; i++)
    {
        cin >>a;
        deg.push_back(a);
        q.push(deg[i]);
    }

    while (!q.empty())
    {
        int max = q.front();
        q.pop();
        if (max < 0 || max > q.size())
        {
            cout <<"NO"<<endl;
            return 0;
        }
        for (int i = 0; i < max; i++)
        {
            int next = q.front();
            q.pop();
            q.push(next - 1);
        }
    }

    cout<<"YES"<<endl;

    return 0;
}


