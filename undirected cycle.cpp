#include <bits/stdc++.h>
using namespace std;

vector<int> temp;

bool detectCycle(int i,vector<vector<int>> arr,vector<int> &vis,int par){
    vis[i] = 1;
    temp.push_back(i);
    for(auto x:arr[i]){
        if(!vis[x]){
            if(detectCycle(x,arr,vis,i))
                return true;
        } else {
            if(par!=x){
                temp.push_back(x);
                return true;
            }
        }
    }
    temp.pop_back();
    return false;
}

int main()
{
    int n,m;
    cin >> n>>m;
    vector<vector<int>> arr(n);
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    vector<int> vis(n, 0);
    if (!detectCycle(0, arr, vis, -1))
        cout<< -1;
    else{
        int x = temp.back();
        cout << x;
        for (int i = temp.size() - 2; i >= 0;i--){
            cout << temp[i];
            if(temp[i]==x)
                break;
        }
    }
}