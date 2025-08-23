
/*DFS stands for Depth-First Search, an algorithm for traversing or searching graphs and trees
by exploring as far as possible along each branch before backtracking.
It uses a stack data structure to keep track of the next node to visit when a dead-end is reached.*/

#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
const int N = 2e5 + 9;
vector<int> graph[N];
bool visited[N];

// -------- Iterative Preorder (visit on pop) ----------
void dfs_iterative_pre(int s) {
    stack<int> S;
    S.push(s);
    visited[s] = true;

    while (!S.empty()) {
        int v = S.top(); S.pop();
        cout << v << " ";  // Preorder: visit before children

        // push neighbors (optional: reverse to get small-first if sorted)
        for (int w : graph[v]) {
            if (!visited[w]) {
                visited[w] = true;
                S.push(w);
            }
        }
    }
}

// -------- Iterative Postorder (two stacks) ----------
void dfs_iterative_post(int s) {
    stack<int> S1, S2;
    S1.push(s);
    visited[s] = true;

    while (!S1.empty()) {
        int v = S1.top(); S1.pop();
        S2.push(v);
        for (int w : graph[v]) {
            if (!visited[w]) {
                visited[w] = true;
                S1.push(w);
            }
        }
    }
    // Postorder: print after all children explored
    while (!S2.empty()) {
        cout << S2.top() << " ";
        S2.pop();
    }
}

// -------- Recursive Preorder ----------
void dfs_recursive_pre(int v) {
    cout << v << " ";        // visit before recursion
    visited[v] = true;
    for (int w : graph[v]) {
        if (!visited[w]) dfs_recursive_pre(w);
    }
}

// -------- Recursive Postorder ----------
void dfs_recursive_post(int v) {
    visited[v] = true;
    for (int w : graph[v]) {
        if (!visited[w]) dfs_recursive_post(w);
    }
    cout << v << " ";        // visit after recursion
}

void solve() {

    int n, m;
    cin >> n >> m;
    // clear graph & visited
    for (int i = 1; i <= n; ++i) {
        graph[i].clear();
        visited[i] = false;
    }

    // read edges (undirected)
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    // Run all four traversals from source = 1

    cout << "DFS Iterative Preorder: ";
    memset(visited, false, sizeof(visited));
    dfs_iterative_pre(1);
    cout << endl;

    cout << "DFS Iterative Postorder: ";
    memset(visited, false, sizeof(visited));
    dfs_iterative_post(1);
    cout << endl;

    cout << "DFS Recursive Preorder: ";
    memset(visited, false, sizeof(visited));
    dfs_recursive_pre(1);
    cout <<endl;

    cout << "DFS Recursive Postorder: ";
    memset(visited, false, sizeof(visited));
    dfs_recursive_post(1);
    cout <<endl;
}

int32_t main() {
    fio;
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}

/*input:
5 4
1 3
1 2
2 5
2 4
output:
DFS Iterative Preorder: 1 2 4 5 3
DFS Iterative Postorder: 3 5 4 2 1
DFS Recursive Preorder: 1 3 2 5 4
DFS Recursive Postorder: 3 5 4 2 1

why DFS iterative preorder and recursive preorder are different ?

Because
-->Recursive DFS uses the call stack, which naturally explores neighbors in left-to-right order (first neighbor first).
-->Iterative DFS with a stack explores last neighbor first unless you push neighbors in reverse order.*/
