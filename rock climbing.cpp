#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int dr[4]={1,0,-1,0};
int dc[4]={0,1,0,-1};
int main() {
    int n,m; cin >> n >> m;
    int destx,desty;
    vector<vector<int>>nums(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> nums[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nums[i][j]==3){
                destx=i;
                desty=j;
                nums[i][j]=1;
            }
            
        }
    }
    //vector<vector<int>>&vis(n,vector<int>(m,0));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<vector<int>>ans(n,vector<int>(m,2000));
    pq.push({0,{n-1,0}});
    ans[n-1][0]=0;
    while(!pq.empty()){
        auto it=pq.top();
        int maxjump=it.first;
        int row=it.second.first;
        int col=it.second.second;
        //cout << maxjump << " ";
        pq.pop();
        if(col+1<m && maxjump<ans[row][col+1]&& nums[row][col+1]==1 ){
            ans[row][col+1]=maxjump;
            pq.push({ans[row][col+1],{row,col+1}});
        }
        if(col-1>=0 && maxjump<ans[row][col-1] && nums[row][col-1]==1){
            ans[row][col-1]=maxjump;
            pq.push({ans[row][col-1],{row,col-1}});
        }
        int x=row-1;
        while(x>=0 && nums[x][col]==0){
            x--;
        }
        if(x>=0 && max(maxjump,abs(x-row))<ans[x][col]){
            ans[x][col]=max(maxjump,abs(x-row));
            pq.push({ans[x][col],{x,col}});
        }
        int y=row+1;
        while(y<n && nums[y][col]==0){
            y++;
        }
        if(y<n && max(maxjump,abs(y-row))<ans[y][col]){
            ans[y][col]=max(maxjump,abs(y-row));
            pq.push({ans[y][col],{y,col}});
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans[destx][desty];
    return 0;
}