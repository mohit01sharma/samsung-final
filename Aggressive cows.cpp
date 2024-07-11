#include <bits/stdc++.h>

using namespace std;

bool isEnough(int arr[], int x, int c, int n)
{
    int cnt = 1;
    int leftmost = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[leftmost] >= x)
        {
            leftmost = i;
            cnt++;
        }
    }
    return cnt >= c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int l = 0;
        int r = arr[n - 1] - arr[0] + 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if(isEnough(arr,m,c,n){
                ans = m;
                l = m + 1;
			} else{
                h = m - 1;
			}
        }
        cout << ans;
    }
}