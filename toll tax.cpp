#include <iostream>
#include <algorithm>
using namespace std;

int n;   // Number of toll booths
int ans; // To store the minimum cost

struct tolls
{
    int men;  // Number of men required at the toll booth
    int cost; // Cost to pass through the toll booth
} toll[100];  // Array to store toll booths information

void solve(int cur_pos, int total_men, int cost)
{
    // Optimization: if current cost exceeds the minimum found so far, return
    if (cost > ans)
        return;

    // Base case: when all toll booths are covered
    if (cur_pos == n)
    {
        ans = min(ans, cost);
        return;
    }

    // Option 1: Pay the toll
    solve(cur_pos + 1, total_men, cost + toll[cur_pos].cost);

    // Option 2: Pay double to hire all the men at the current toll booth
    solve(cur_pos + 1, total_men + toll[cur_pos].men, cost + 2 * toll[cur_pos].cost);

    // Option 3: Use available men to avoid paying the toll
    if (total_men > toll[cur_pos].men)
    {
        solve(cur_pos + 1, total_men - toll[cur_pos].men, cost);
    }
}

int main()
{
    int t;
    cin >> t; // Number of test cases

    while (t--)
    {
        cin >> n; // Number of toll booths

        for (int i = 0; i < n; i++)
            cin >> toll[i].men >> toll[i].cost;

        ans = 99999;    // Initialize ans with a large value
        solve(0, 0, 0); // Start solving from the first toll booth

        cout << ans << endl; // Output the minimum cost for the current test case
    }
    return 0;
}
