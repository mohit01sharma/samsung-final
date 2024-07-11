#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    int ans = 1;

    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int f = q.front();
                q.pop();
                for (int j = 0; j < n; j++)
                {
                    if (arr[f][j] == 1)
                    {
                        if (color[j] == -1)
                        {
                            color[j] = !color[f];
                            q.push(j);
                        }
                        else
                        {
                            if (color[j] == color[f])
                                ans = -1;
                        }
                    }
                }
            }
        }
    }
    if (ans == -1)
        cout << -1;
    else
        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)
                cout << i;
        }
}