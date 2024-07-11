#include <bits/stdc++.h>
using namespace std;

int ans;
void solve(int target, unordered_map<int, int> mp, vector<int> working, int o, vector<int> signs)
{
    if (working.size() == 0)
        return;
    for (int i = 0; i < working.size(); i++)
    {
        int curr_ele = working[i];
        working.erase(working.begin() + i);
        unordered_map<int, int> nmp;
        nmp[curr_ele] = 1;
        for (auto x : mp)
        {
            int val = x.first;
            int freq = x.second;
            if (signs[0])
            {
                int num = val + curr_ele;
                int new_freq = freq + 3;
                if (nmp.find(num) == nmp.end())
                {
                    nmp[num] = new_freq;
                }
                else if (nmp[num] > new_freq)
                {
                    nmp[num] = new_freq;
                }
                if (num == target && new_freq <= o)
                {
                    ans = min(ans, new_freq);
                }
            }
            if (signs[1])
            {
                int num = abs(val - curr_ele);
                int new_freq = freq + 3;
                if (nmp.find(num) == nmp.end())
                {
                    nmp[num] = new_freq;
                }
                else if (nmp[num] > new_freq)
                {
                    nmp[num] = new_freq;
                }
                if (num == target && new_freq <= o)
                {
                    ans = min(ans, new_freq);
                }
            }
            if (signs[2])
            {
                int num = val * curr_ele;
                int new_freq = freq + 3;
                if (nmp.find(num) == nmp.end())
                {
                    nmp[num] = new_freq;
                }
                else if (nmp[num] > new_freq)
                {
                    nmp[num] = new_freq;
                }
                if (num == target && new_freq <= o)
                {
                    ans = min(ans, new_freq);
                }
            }
            if (signs[3])
            {
                if (val != 0 && curr_ele >= val)
                {
                    if (curr_ele % val == 0)
                    {
                        int num = curr_ele / val;
                        int new_freq = freq + 3;
                        if (nmp.find(num) == nmp.end())
                        {
                            nmp[num] = new_freq;
                        }
                        else if (nmp[num] > new_freq)
                        {
                            nmp[num] = new_freq;
                        }
                        if (num == target && new_freq <= o)
                        {
                            ans = min(ans, new_freq);
                        }
                    }
                }
                else
                {
                    if (curr_ele != 0 && val % cur_ele == 0)
                    {
                        int num = val / cur_ele;
                        int new_freq = freq + 3;
                        if (nmp.find(num) == nmp.end())
                        {
                            nmp[num] = new_freq;
                        }
                        else if (nmp[num] > new_freq)
                        {
                            nmp[num] = new_freq;
                        }
                        if (num == target && new_freq <= o)
                        {
                            ans = min(ans, new_freq);
                        }
                    }
                }
            }
            string one = to_string(curr_ele);
            string two = to_string(val);
            int num = stoi(one + two);
            int new_freq = freq + 1;
            if (nmp.find(num) == nmp.end())
            {
                nmp[num] = new_freq;
            }
            else if (nmp[num] > new_freq)
            {
                nmp[num] = new_freq;
            }
            if (num == target && new_freq <= o)
            {
                ans = min(ans, new_freq);
            }
            num = stoi(two + one);
            if (nmp.find(num) == nmp.end())
            {
                nmp[num] = new_freq;
            }
            else if (nmp[num] > new_freq)
            {
                nmp[num] = new_freq;
            }
            if (num == target && new_freq <= o)
            {
                ans = min(ans, new_freq);
            }
        }
        for (auto x : mp)
        {
            int num = x.first;
            int new_freq = x.second;
            if (nmp.find(num) == nmp.end())
            {
                nmp[num] = new_freq;
            }
            else if (nmp[num] > new_freq)
            {
                nmp[num] = new_freq;
            }
        }
        solve(target, nmp, working, o, signs);
        working.insert(working.begin() + i, curr_ele);
    }
}

int main()
{
    int t;
    cin t;
    while (t--)
    {
        int n, m, o;
        cin >> n >> m >> o;
        vector<int> working(n);
        for (int i = 0; i < n; i++)
            cin >> working[i];
        vector<int> signs(4);
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            signs[x - 1] = 1;
        }
        int target;
        cin >> target;
        ans = INT_MAX;
        unordered_map<int, int> mp;
        solve(target, mp, working, o, signs);
        cout << ans;
    }
}