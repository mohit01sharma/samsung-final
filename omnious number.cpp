#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = a; i <= b;i++){
        int digit[10]={0};
        int temp = i;
        while(temp){
            digit[temp % 10]++;
            temp / 10;
        }
        int cntk = 0;
        for (int i = 0; i < n;i++){
            cntk += digit[arr[i]];
        }
        if(cntk<k)
            cnt++;
    }
    cout << cnt;
}