#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    // Base case
    if (idx == 0 || W == 0) return 0;

    // Already calculated
    if (dp[idx][W] != -1) return dp[idx][W];

    // Option 1: skip item
    int notTake = solve(idx - 1, W, wt, val, dp);

    // Option 2: take item (if fits)
    int take = 0;
    if (wt[idx - 1] <= W)
        take = val[idx - 1] + solve(idx - 1, W - wt[idx - 1], wt, val, dp);

    // Store result
    return dp[idx][W] = max(take, notTake);
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);
    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++) cin >> wt[i];
    cout << "Enter values:\n";
    for(int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter capacity: ";
    cin >> W;

    // 🔹 DP declared in main (initialized with -1, no memset)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    cout << "Maximum value = " << solve(n, W, wt, val, dp);
    return 0;
}
