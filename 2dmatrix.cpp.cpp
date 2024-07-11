#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	char arr[n][n];
	pair<int,int> dp[n][n];
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            dp[i][j].first = 0;
            dp[i][j].second = 0;
        }
    }
    arr[0][0]='0';
    arr[n-1][n-1]='0';
    for(int i=n-2;i>=0;i--){
        if(arr[i][n-1]=='x'){
            for(int j=i;j>=0;j--){
                dp[j][n-1].first=dp[j][n-1].second=INT_MIN;
            }
            break;
        }
        else{
            dp[i][n-1].first=dp[i+1][n-1].first+arr[i][n-1]-'0';
            dp[i][n-1].second=1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(arr[n-1][i]=='x'){
            for(int j=i;j>=0;j--){
                dp[n-1][j].first=dp[n-1][j].second=INT_MIN;
            }
            break;
        }
        else{
            dp[n-1][i].first=dp[n-1][i+1].first+arr[n-1][i]-'0';
            dp[n-1][i].second=1;
        }
    }
    bool noPath=false;
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(arr[i][j]=='x'){
                dp[i][j].first=dp[i][j].second=INT_MIN;
            }else{
                int maxi=max({dp[i+1][j].first,dp[i+1][j+1].first,dp[i][j+1].first});
                int path=0;
                if(dp[i+1][j].first==maxi) path+=dp[i+1][j].second;
                if(dp[i+1][j+1].first==maxi) path+=dp[i+1][j+1].second;
                if(dp[i][j+1].first==maxi) path+=dp[i][j+1].second;
                if(path==0){
                    noPath=true;
                    break;
                }
                dp[i][j].first=maxi+arr[i][j]-'0';
                dp[i][j].second=path;
            }
        }
    }
    if(noPath) cout<<"0 0"<<endl;
    cout<<dp[0][0].first<<" "<<dp[0][0].second<<endl;
}
