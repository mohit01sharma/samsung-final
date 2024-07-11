#include<iostream>
#include<queue>

using namespace std;

int x[4] = {-1, 0, 1, 0};
int y[4] = {0, -1, 0, 1};

int main(){
    int n, m;
    cin >> n >> m;
    int a[m + 1][n + 1];
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> a[i][j];
        }
    }
    queue<pair<int, pair<int, int>>> q;
    int r, c;
    cin >> r >> c;
    q.push({0, {r, c}});
    a[r][c] = 2;
    int final;
    while(!q.empty()){
        int lvl = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        for (int k = 0; k < 4;k++){
            int nx = i + x[k];
            int ny = j + y[k];
            final = lvl + 1;
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(a[nx][ny]==1){
                    q.push({lvl + 1, {nx, ny}});
                    a[nx][ny] = 2;
                }
            }
        }
    }
    cout << final - 1;
}