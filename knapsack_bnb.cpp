#include <bits/stdc++.h>
using namespace std;

struct Node {
    int level;      // which item index
    int profit;     // current profit
    int weight;     // current weight
    int bound;      // max possible profit from this branch
};

// very simple bound function
int getBound(Node u, int n, int W, vector<int>& wt, vector<int>& val) {
    if (u.weight > W) return 0;   // overweight → invalid

    int bound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    // try taking remaining items fully (no fractional)
    while (j < n && totalWeight + wt[j] <= W) {
        totalWeight += wt[j];
        bound += val[j];
        j++;
    }

    return bound;
}

int knapsackBnB(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    queue<Node> q;

    Node u, v;
    v.level = -1;
    v.weight = 0;
    v.profit = 0;
    v.bound = getBound(v, n, W, wt, val);
    q.push(v);

    int maxProfit = 0;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        // if this branch cannot beat best so far, skip it
        if (v.bound <= maxProfit) continue;

        // option 1 → take item
        u.level = v.level + 1;
        u.weight = v.weight + wt[u.level];
        u.profit = v.profit + val[u.level];

        if (u.weight <= W && u.profit > maxProfit)
            maxProfit = u.profit;

        u.bound = getBound(u, n, W, wt, val);
        if (u.bound > maxProfit)
            q.push(u);

        // option 2 → don't take item
        u.weight = v.weight;
        u.profit = v.profit;
        u.bound = getBound(u, n, W, wt, val);
        if (u.bound > maxProfit)
            q.push(u);
    }

    return maxProfit;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);
    cout << "Enter weights: ";
    for(int i=0; i<n; i++) cin >> wt[i];

    cout << "Enter profits: ";
    for(int i=0; i<n; i++) cin >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "\nMaximum profit = " << knapsackBnB(W, wt, val);
    return 0;
}
