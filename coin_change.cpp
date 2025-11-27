#include <bits/stdc++.h>
using namespace std;

bool found = false;                 // to stop after first valid solution
vector<int> answer;

// backtracking function
void solve(vector<int>& coins, int target, int index, vector<int>& used) {
    if (target == 0) {              // solution found
        found = true;
        answer = used;
        return;
    }

    if (index == coins.size() || target < 0)   // no solution in this path
        return;

    // choice 1: take this coin
    used.push_back(coins[index]);
    solve(coins, target - coins[index], index + 1, used);
    if (found) return;              // stop after first valid solution

    // choice 2: do NOT take this coin
    used.pop_back();
    solve(coins, target, index + 1, used);
}

int main() {
    int n, target;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> used;
    solve(coins, target, 0, used);

    if (!found) {
        cout << "Not possible to make the target sum";
    } else {
        cout << "Possible to make the target sum\n";
        cout << "Coins used: ";
        for (int c : answer) cout << c << " ";
        cout << "\nMinimum coins = " << answer.size();
    }
}
