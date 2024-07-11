#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s += "0";
    }

    priority_queue<pair<int, int>> pq;
    pq.push({n, 0});
    for (int i = 0; i < n; i++)
    {
        pair<int, int> front = pq.top();
        pq.pop();
        int indx = (front.first - 1) / 2 + front.second;
        s[indx] = '1';
        cout << s << endl;
        pq.push({indx - front.second, front.second});
        pq.push({front.first / 2, indx + 1});
    }
    return 0;
}