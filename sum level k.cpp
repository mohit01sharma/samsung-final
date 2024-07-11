#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < s.size()-1;i++){
        if(s[i]=='(')
            cnt++;
        else if(s[i]==')')
            cnt--;
        int temp = 0;
        if(cnt==k+1 && s[i+1]>='0' && s[i+1]<='9'){
            while (i < s.size() - 1 && s[i + 1] >= '0' && s[i + 1] <= '9'){
                temp = temp * 10 + s[i + 1] - '0';
                i++;
            }
            i--;
        }
        ans += temp;
    }
    cout << ans;
}