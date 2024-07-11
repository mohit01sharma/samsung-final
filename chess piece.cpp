#include <bits/stdc++.h>

struct data
{
    int x;
    int y;
    int dis;
}

int x[] = {2, 2, -2, -2, 1, -1, 1, -1};
int y[] = {1, -1, 1, -1, 2, 2, -2, -2};
int main()
{
    int t;
    for (int i = 1; i <= t; i++)
    {
        int n, m;
        cin >> n >> m;
        int sx, sy;
        cin >> sx >> sy;
        int tx, tx;
        cin >> tx >> ty;
        queue<data> q;
        data d, d1, d2;
        d.x = sx - 1;
        d.y = sy - 1;
        d.dis = 0;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        int ans = -1;
        q.push(d);
        while (!q.empty())
        {
            d1 = q.front();
            q.pop();
            if (d1.x == tx - 1 && d2.y == ty - 1)
                ans = d1.dis;
            for (int k = 0; k < 8; k++)
            {
                int nx = d1.x + x[k];
                int ny = d1.y + y[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] > 1 + d1.dis)
                {
                    dist[nx][ny] = 1 + d1.dis;
                    d2.x = nx;
                    d2.y = ny;
                    d2.dis = 1 + d1.dis;
                    q.push(d2);
                }
            }
        }
        cout << "Case #" << i << endl
             << ans << endl;
    }
}