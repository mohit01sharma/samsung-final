#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;

int main()
{
    int n, sx, sy, tx, ty;
    cin >> n, sx, sy, tx, ty;
    vector<vector<int>> w(n, vector<int>(5));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> w[i][j];
        }
    }
    unordered_map<pair<int, int>, int> mp;
    mp[{sx, sy}] = 0;
    mp[{tx, ty}] = INT_MAX;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {sx, sy}});
    while(!pq.empty()){
        int lvl = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(x==tx && y==ty)
            cout<< lvl;
        if(mp[{tx,ty}]>lvl+abs(tx-x)+abs(y-ty)){
            mp[{tx, ty}] = lvl + abs(tx - x) + abs(ty - y);
            pq.push({mp[{tx, ty}], {tx, ty}});
        }
        for (int i = 0; i < n;i++){
            if (mp.find({w[i][0], w[i][1]}) == mp.end() || mp[{w[i][0], w[i][1]}] > lvl + abs(w[i][2] - x) + abs(w[i][3] - y)+w[i][4]){
                mp[{w[i][0], w[i][1]}] = lvl + abs(w[i][2] - x) + abs(w[i][3] - y) + w[i][4];
                int val = lvl + abs(w[i][2] - x) + abs(w[i][3] - y) + w[i][4];
                pq.push({val, {w[i][0], w[i][1]}});
            }
            if (mp.find({w[i][2], w[i][3]}) == mp.end() || mp[{w[i][2], w[i][3]}] > lvl + abs(w[i][0] - x) + abs(w[i][1] - y) + w[i][4])
            {
                mp[{w[i][2], w[i][3]}] = lvl + abs(w[i][0] - x) + abs(w[i][1] - y) + w[i][4];
                int val = lvl + abs(w[i][0] - x) + abs(w[i][1] - y) + w[i][4];
                pq.push({val, {w[i][2], w[i][3]}});
            }
        }
    }
    cout << -1;
}