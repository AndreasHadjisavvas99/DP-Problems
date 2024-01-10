#include <iostream>
/* 
Problem:
    Coin Change
    
    Given an unlimited supply of coins of given 
    denominations?(1,3,5,10), find the [total number of ways
    to make a change of size n] 
    F(n) = F(n-1) + F(n-3) + F(n-5) + F(n-10)
*/
using namespace std;
int numChanges(int n) {
    int dp[n + 1] = {0};
    
    dp[0] = 1;
    
    for(int i=1; i<=n; i++){
        if (i>=1) {
            dp[i] = dp[i-1];
        }
        if (i>=3) {
            dp[i] = dp[i-1] + dp[i-3];
        }
        if (i>=5) {
            dp[i] = dp[i-1] + dp[i-3] + dp[i-5];
        }
        if (i>=10) {
            dp[i] = dp[i-1] + dp[i-3] + dp[i-5] + dp[i-10];
        }
    }
    return dp[n];  
}

int main() {
    int n = 4;
    int ans = numChanges(n);
    cout << "Number of ways to change the coin: " << ans;
    return 0;
}