#include <bits/stdc++.h>
using namespace std;
int dist[1000], visit[1000];
vector <int> vv[1000];
void dfs(int src)
{
    visit[src] = 1;
    for(int i=0; i<vv[src].size(); i++)
    {
        int node = vv[src][i];
        if(visit[node] == 0)
        {
            dist[node] = dist[src]+1;
            dfs(node);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++)
    {
        int from, to;
        cin >> from >> to;
        vv[from].push_back(to);
        vv[to].push_back(from);
    }
    int src, target;
    cin >> src >> target;
    dfs(src);
    cout << dist[target] <<endl;
}
/*
6 7
1 2
1 3
2 4
2 5
3 5
4 6
5 6
1 6
*/

