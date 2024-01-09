#include <iostream>
/* 
Problem:
    Paint Fence with 2 colors
    
    There is a fence with n posts, each post can be painted with either green ori blue color
    You have to paint all the posts such that no more than two adjacent fence posts have the same color.
    Return the total number of ways you can paint the fence    
*/
using namespace std;
int numWays(int n) {
    int dp[n + 1][2];
    //green = 1
    //blue = 0
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[2][0] = 2;   // 10,00
    dp[2][1] = 2;   // 11,01
    for(int i=3; i<=n; i++){
        for(int j=0; j<=1; j++){
            dp[i][j] = dp[i-1][1-j] + dp[i-2][1-j];        
        }
    }
    return dp[n][0] + dp[n][1];

}

int main() {
    // Call the function
    int n = 5;
    int ans = numWays(n);
    cout << "Number of ways to paint: " << ans;
    return 0;
}
