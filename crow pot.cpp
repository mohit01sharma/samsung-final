#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr,int k){
    int cnt = 0;
    for (int i = n - 1; i > 0;i--){
        arr[i] = max(0, arr[i] - arr[i - 1]);
    }
    for (int i = 0; i < k;i++){
        cnt += arr[i]*(n-i);
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k
    sort(arr.begin(), arr.end());
    int x = solve(arr,l);
    cout << x;
}