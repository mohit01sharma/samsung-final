#include<bits/stdc++.h>
using namespace std;

int n[] = {-1, 0, 1, 0};
int m[] = {0, -1, 0, 1};

void solve(int i, int j,int num, int tx, int ty, vector<vector<int>> arr, vector<vector<int>> &vis, vector<vector<int>> &dis){
    queue<pair<int, pair<int,int>>> q;
    q.push({0,{i,j}});
    vis[i][j] = 1;
    while(!q.empty()){
        int lvl = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        for (int k = 0; k < 4;k++){
            int nx = x + n[k];
            int ny = y + m[k];
            if(nx>=0 && nx<num && ny>=0 && ny<num && vis[nx][ny]==0 && arr[nx][ny]==1){
                vis[nx][ny] = 1;
                if(nx==x)
                    dis[nx][ny] = 1 + dis[x][y];
                else if(ny==y)
                    dis[nx][ny] = dis[x][y];
                q.push({dis[nx][ny], {nx, ny}});
            }
        }
    }
    if(vis[tx][ty])
        cout << dis[tx][ty];
    cout << -1;
}

    int main()
{
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(n));
    vector<vector<int>> dis(n, vector<int>(n));
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    solve(sx, sy, tx, ty, arr,vis,dis);
}