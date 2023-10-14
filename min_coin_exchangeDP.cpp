#include <iostream>
#include <climits>

using namespace std;

int minCoinsDP(int coins[], int n, int sum) {
    int dp[sum + 1];
    dp[0] = 0;

    for (int i = 1; i <= sum; ++i) {
        dp[i] = INT_MAX;

        for (int j = 0; j < n; ++j) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[sum];
}

int main() {
    int coins[] = {1, 2, 3};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum;
    cout << "Enter the sum: ";
    cin >> sum;

    int minCoinCount = minCoinsDP(coins, n, sum);
    cout << "Minimum number of coins needed: " << minCoinCount << endl;

    return 0;
}
