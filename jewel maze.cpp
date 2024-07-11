#include <bits/stdc++.h>
using namespace std;

int ans = INT_MIN;
int x[] = {1, 0, -1, 0};
int y[] = {0, 1, 0, -1};
void dfs(int sx, int sy, int coins, vector<vector<int>> vis, vector<vector<int>> path, vector<vector<int>> v){
    if(sx==n-1 && sy==n-1){
        if(coins>=ans){
            ans = coins;
            for (int i = 0; i < n;i++){
                for (int j = 0; j < n;j++){
                    if(vis[i][j])
                        path[i][j] = 3;
                    else
                        path[i][j] = v[i][j];
                }
            }
        }
        return;
    }
    for (int i = 0; i < 4;i++){
        int nx = sx + x[i];
        int ny = sy + y[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(vis[nx][ny]==0 && v[nx][ny]==0){
                vis[nx][ny] = 1;
                dfs(nx, ny, coins, vis, path, v);
                vis[nx][ny] = 0;
            }
            if (vis[nx][ny] == 0 && v[nx][ny] == 2)
            {
                vis[nx][ny] = 1;
                dfs(nx, ny, coins+1, vis, path, v);
                vis[nx][ny] = 0;
            }
        }
    }
}


int main()
{
    int t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                cin >> v[i][j];
            }
        }
        vector<vector<int>> vis(n, vector<int>(n,0));
        vector<vector<int>> path(n, vector<int>(n, 0));
        int sx = 0, sy = 0;
        vis[sx][sy] = 1;
        if(v[sx][sy]==0)
            solve(sx, sy, 0, vis, path, v);
        if(v[sx][sy]==2)
            solve(sx, sy, 1, vis, path, v);
        cout << ans<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << path[i][j] << " ";
            cout << endl;
        }
    }
}