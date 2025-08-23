//Breadth First Search (BFS) is a graph traversal algorithm. It starts from a source node and explores all neighbors first (level by //level) before moving to the next level.

#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
const int N = 1e5 + 9;
vector<int>g[N];
bool vis[N];
int dis[N], par[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    dis[1] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v: g[u])
        {
            if (!vis[v])
            {
                q.push(v);
                par[v] = u;
                dis[v] = dis[u] + 1;
                vis[v] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<"Distance of "<<i<<" from root node: "<<dis[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        cout<<"Parent "<<i<<": "<<par[i]<<endl;
    }

}
int32_t main()
{
    fio;
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T = 1;
    //cin >> T;
    for (int __ = 1; __ <= T; __++)
    {
        // cout << "Case " << __ << ": ";
        solve();
    }
    return 0;
}


//Time & Space Complexity
//O(V + E) for adjacency list
//O(V²) for adjacency matrix
