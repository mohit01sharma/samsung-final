#include <iostream>

using namespace std;

int D, E, F, d, e;
int n;
int w[10][4], ans;

void solve(int s, int cnt, int val, int D, int E, int F)
{
    if (s == n || cnt == 3)
    {
        int x = val + d * D + e * E;
        if (x > ans)
            ans = x;
        return;
    }
    solve(s + 1, cnt, val, D, E, F);
    int i = 1;
    while (true)
    {
        if (D - w[s][0] * i >= 0 && E - w[s][1] >= 0 && F - w[s][2] >= 0)
        {
            solve(s + 1, cnt + 1, val + w[s][3] * i, D - w[s][0] * i, E - w[s][1] * i, F - w[s][2] * i);
            i++;
        }
        else
            break;
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        int D, E, F, d, e;
        int n;
        cin >> D >> E >> F >> d >> e;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> w[i][j];
            }
        }
        ans = INT_MIN;
        solve(0, 0, 0, D, E, F);
        cout << "Case #" << p << endl
             << ans << endl;
    }
}