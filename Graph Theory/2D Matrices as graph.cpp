
//////////Number of Islands(leetcode)////////

#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
const int N = 2e5 + 9;
vector<int> graph[N];
int color[N];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<vector<int>>grid;
vector<vector<int>>vis;
int m,n;
bool isvalid(int x,int y){
    return (x>=0 && x<m && y>=0 && y<n && vis[x][y]==0 && grid[x][y]==1);
}
void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(isvalid(nx,ny)){
            dfs(nx,ny);
        }
    }
}
void solve()
{
    int cnt=0;
    cin>>m>>n;
    grid.assign(m,vector<int>(n));
    vis.assign(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int k=0;k<n;k++){
            cin>>grid[i][k];
        }
    }
    for(int i=0;i<m;i++){
        for(int k=0;k<n;k++){
            if(!vis[i][k] && grid[i][k]==1){
                dfs(i,k);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;

}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}

