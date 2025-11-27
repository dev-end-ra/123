#include <bits/stdc++.h>
using namespace std;

int n;                               // number of cities
int distMat[10][10];                 // distance matrix
bool visited[10];                    // to mark visited cities
int minCost = INT_MAX;               // to store minimum travelling cost

void tsp(int currentCity, int count, int cost) {
    // If all cities are visited and we can return to starting city (0)
    if (count == n && distMat[currentCity][0] > 0) {
        minCost = min(minCost, cost + distMat[currentCity][0]);
        return;
    }

    // Try all next possible cities
    for (int nextCity = 0; nextCity < n; nextCity++) {
        if (!visited[nextCity] && distMat[currentCity][nextCity] > 0) {
            visited[nextCity] = true;     // mark as visited
            tsp(nextCity, count + 1, cost + distMat[currentCity][nextCity]);
            visited[nextCity] = false;    // backtracking (undo step)
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> distMat[i][j];

    // Start from city 0
    visited[0] = true;
    tsp(0, 1, 0);

    cout << "\nMinimum cost to visit all cities and return to start = " << minCost;
    return 0;
}
