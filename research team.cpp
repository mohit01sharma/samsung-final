#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n, r;
        vector<pair<int, int>> v(r);
        for (int i = 0; i < r; i++)
        {
            int x1, y1;
            cin >> x1 >> y1;
            v[i] = {x1, y1};
        }
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        int ans = INT_MAX;
        int ans_x, ans_y;

        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, -1, 0, 1};

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = INT_MIN;
                for (int k = 0; k < n; k++)
                {
                    int tx = v[k].first;
                    int ty = v[k].second;
                    queue<pair<int, pair<int, int>>> q;
                    vector<vector<int>> vis(n, vector<int>(n, 0));
                    q.push({0, {i, j}});
                    while (!q.empty())
                    {
                        int lvl = q.front().first;
                        int fx = q.front().second.first;
                        int fy = q.front().second.second;
                        q.pop();
                        if (fx == tx && fy == ty)
                        {
                            temp = max(temp, lvl);
                            break;
                        }
                        for (int a = 0; a < 4; a++)
                        {
                            int nx = fx + x[a];
                            int ny = fy + y[a];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                            {
                                if (vis[nx][ny] == 0 && arr[nx][ny] == 1)
                                {
                                    vis[nx][ny] = 1;
                                    q.push({lvl + 1, {nx, ny}});
                                }
                            }
                        }
                    }
                }
                ans = min(ans, temp);
            }
        }
    }
}

void floodfill(ll xnode, ll ynode, vector<vector<ll>> &dist, int delx[], int dely[], ll n, vector<vector<ll>> &grid)
{
    queue<pair<ll, ll>> q;
    vector<vector<ll>> vis(n, vector<ll>(n));
    q.push({xnode, ynode});
    vis[xnode][ynode] = 1;
    while (!q.empty())
    {
        ll x = q.front().first;
        ll y = q.front().second;
        q.pop();
        for (ll i = 0; i < 4; i++)
        {
            ll newx = x + delx[i];
            ll newy = y + dely[i];
            if (newx >= 0 && newx < n && newy >= 0 && newy < n && vis[newx][newy] == 0 && grid[newx][newy] == 1)
            {

                vis[newx][newy] = 1;
                dist[newx][newy] = 1 + dist[x][y];
                q.push({newx, newy});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, ll>> cds(m);
        for (ll i = 0; i < m; i++)
        {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            cds[i] = {a, b};
        }
        vector<vector<ll>> grid(n, vector<ll>(n));
        vector<vector<ll>> dist_grid(n, vector<ll>(n));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        for (ll i = 0; i < m; i++)
        {
            int delx[4] = {-1, 0, 1, 0};
            int dely[4] = {0, 1, 0, -1};
            vector<vector<ll>> dist(n, vector<ll>(n));
            floodfill(cds[i].first, cds[i].second, dist, delx, dely, n, grid);
            for (ll j = 0; j < n; j++)
            {
                for (ll k = 0; k < n; k++)
                {
                    dist_grid[j][k] = max(dist_grid[j][k], dist[j][k]);
                }
            }
        }
        ll mini = 1e9;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    mini = min(mini, dist_grid[i][j]);
                }
            }
        }
        cout << mini << endl;
    }
}