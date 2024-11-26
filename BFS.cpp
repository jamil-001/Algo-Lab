#include <iostream>
#include <queue>
#include <vector>
#define MAX 100000
using namespace std;
int dist[MAX];
int visit[MAX];
vector <int> vv[MAX];

void bfs(int src)
{
    int temp, node;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        temp = q.front(); q.pop();
        for(int i=0;i<vv[temp].size();i++)
        {
            int node = vv[temp][i];
            if(visit[node] == 0)
            {
                visit[node]=1;
                dist[node] = dist[temp] + 1;
                q.push(node);
            }
        }
    }
}
int main()
{
    int n, e, src, target;
    cout << "Enter nodes <space> edges" << endl;
    cin >> n >> e;
    for(int i=1;i<=e;i++)
    {
        //cout << "Enter which nodes " << i << " is connecting to or are connecting to it" << endl;
        int u, v;
        cin >> u >> v;
        vv[u].push_back(v);
        vv[v].push_back(u);
    }
    cout << "Enter source <space> target" << endl;
    cin >> src >> target;
    bfs(src);
    cout << dist[target];
}
/*
10 13
1 2
1 3
1 4
2 6
3 8
3 7
4 7
6 10
9 10
9 7
8 7
8 5
5 10

10 14
1 2
1 3
1 4
2 6
3 8
3 7
4 7
4 10
6 10
9 10
9 7
8 7
8 5
5 10

*/