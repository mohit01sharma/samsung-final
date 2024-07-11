#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> mp;
    for (int i = 0; i < n;i++){
        string s = "";
        for (int j = 0; j < m;j++){
            int ch;
            cin >> ch;
            s += to_string(ch);
        }
        mp[s]++;
    }
    int ans = 0;
    for(auto i:mp){
        string s = i.first;
        int munZeroes = 0;
        for (int i = 0; i < s.size();i++){
            if(s[i]=='0')
                numZeroes++;
        }
        if((k-numZeroes)%2==0 && k>=numZeroes)
            ans += i.second;
    }
    cout << ans;
}