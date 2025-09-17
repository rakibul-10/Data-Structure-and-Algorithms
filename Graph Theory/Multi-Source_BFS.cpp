

//1st approach->Add all the nodes you want to BFS from into the initial queue and run it.


#include <bits/stdc++.h>
using namespace std;

const int N = 1005;  // adjust according to constraints
int grid[N][N], vis[N][N], dis[N][N];
int dx[] = {1,-1,0,0,-1,1,1,-1};
int dy[] = {0,0,1,-1,1,1,-1,-1};
int n, m;

void reset() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            vis[i][j] = 0;
            dis[i][j] = -1;
        }
    }
}

bool isvalid(int x, int y) {
    return (x>=0 && y>=0 && x<n && y<m && vis[x][y]==0);
}

void solve() {
    cin >> n >> m;
    int mx = 0;
    reset();

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
            mx = max(mx, grid[i][j]);
        }
    }

    queue<pair<int,int>> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == mx) {
                q.push({i,j});
                vis[i][j] = 1;
                dis[i][j] = 0;
            }
        }
    }

    int ans = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isvalid(nx, ny)) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
                dis[nx][ny] = dis[x][y] + 1;
                ans = max(ans, dis[nx][ny]);
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}


/// 2nd Approach->Another way to think about multiple sources that's potentially nicer to code is to add a fake source with edges to all the real sources, then BFS as normal, then subtract 1 from all the distances.

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;   // n nodes, m edges

    vector<vector<int>> adj(n + 2);  // +1 for fake source

    // read graph edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    int k;
    cin >> k;   // number of real sources
    vector<int> sources(k);
    for (int i = 0; i < k; i++) {
        cin >> sources[i];
    }

    int fake = n + 1; // fake source node id

    // connect fake source to all real sources
    for (int s : sources) {
        adj[fake].push_back(s);
        adj[s].push_back(fake);
    }

    vector<int> dist(n + 2, INF);
    queue<int> q;

    // normal BFS from fake source
    dist[fake] = 0;
    q.push(fake);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // print distances (subtract 1 to remove fake source step)
    for (int i = 1; i <= n; i++) {
        int d = (dist[i] == INF ? -1 : dist[i] - 1);
        cout << "dist(" << i << ") = " << d << "\n";
    }
}

