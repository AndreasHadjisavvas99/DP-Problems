#include <iostream>
/* 
Problem:
    Coin Change 2
    
    Given an unlimited supply of coins of given 
    denominations?(1,2,3,5), find the [total number of ways
    to make a change of size n], by using exactly t coins
    F(i,t) = F(t-1, t-1) + F(i-2, t-1) + F(i-3, t-1) + F(i-5, t-1)
*/
const int MAX_N = 1000;  // Adjust the maximum value of n as needed
const int MAX_T = 100;   // Adjust the maximum value of t as needed

int coinChangeExactlyTCoins(int n, int t, int coins[], int numCoins) {
    int dp[MAX_N + 1][MAX_T + 1] = {0};

    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            if (i > 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }

            for (int k = 0; k < numCoins; k++) {
                int coin = coins[k];
                if (i - coin >= 0) {
                    dp[i][j] += dp[i - coin][j - 1];
                }
            }
        }
    }

    return dp[n][t];
}

int main() {
    int n = 7;  // example amount
    int t = 3;   // example number of coins
    int coins[] = {1, 2, 3, 5};  // example coin denominations
    int numCoins = sizeof(coins) / sizeof(coins[0]);  // calculate the number of coins

    int result = coinChangeExactlyTCoins(n, t, coins, numCoins);

    std::cout << "Number of ways to make change: " << result << std::endl;

    return 0;
}
