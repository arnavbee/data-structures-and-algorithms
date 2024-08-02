# Dynamic Programming

## Fibonacci


## Climbing Stairs

Approach 1:

`class Solution {
public:

    int dp[46];

    int solve(int n){

        if(n < 0) return 0;
        if(n == 0) return 1;

        if(dp[n] != -1){
            return dp[n];
        } 

        int one_step = solve(n-1);
        int two_step = solve(n-2);

        return dp[n] = one_step + two_step;
    }
    int climbStairs(int n) {

        memset(dp, -1,sizeof(dp));

        return solve(n);
        

        
    }
};`


Approach 2: Bottoms Up

`#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        std::vector<int> dp(n + 1, -1); // Initialize vector with -1

        dp[0] = 0; // Although not necessary for the climb stairs logic
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};`



