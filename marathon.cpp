#include<iostream>
using namespace std;

int d, e;
int a[5][2];
int dp[1001][1001];
int solve(int d,int e){
    if(d==0)
        return 0;
    if(dp[d][e]!=-1)
        return dp[d][e];
    int ans = INT_MIN;
    for (int i = 0; i < 5;i++){
        if(e>=a[i][1]){
            int temp = a[i][0] + solve(d - 1, e-a[i][1]);
            ans = max(ans, temp);
        }
    }
    return dp[d][e] = ans;
}

int main(){
    cin>>d>>e;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 5;i++){
        cin >> a[i][0] >> a[i][1];
    }
    cout<<solve(d, e);
}
