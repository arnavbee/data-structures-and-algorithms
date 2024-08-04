# Dynamic Programming

Dynamic programming, like the divide-and-conquer method, solves problems by combining the solutions to subproblems.

A dynamic-programming algorithm solves each subsubproblem just once and then saves its answer in a table, thereby avoiding the work of recomputing the answer every time it solves each subsubproblem.

We typically apply dynamic programming to optimization problems. Such prob- lems can have many possible solutions. Each solution has a value, and we wish to find a solution with the optimal (minimum or maximum) value.

When developing a dynamic-programming algorithm, we follow a sequence of four steps:

1. Characterize the structure of an optimalsolution.
2. Recursively define the value of an optimalsolution.
3. Compute the value of an optimal solution,typically in a bottom-up fashion.
4. Construct an optimal solution from computed information.

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



Approach 3: 

`

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)
        return n;

        int a = 1;
        int b = 2;
        int c;

        for(int i = 3; i<=n;i++){
            c = a + b;
            a = b;
            b = c;
        }

        return c;
        
    }
};

`


## House Robber

### Approach 1: Recursion + Memoisation

class Solution {
public:
    int dp[101];

    int solve(vector<int>& nums, int i, int n){
        

        if(i>=n) return 0;

        if(dp[i] != -1) return dp[i];

        int steal = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        

        return dp[i] = max(steal,skip);
    }
    int rob(vector<int>& nums) {

        int n = nums.size();

        memset(dp, -1, sizeof(dp));

        

        return solve(nums, 0, n);
        
    }
};



### Approach 2: Bottoms Up

class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = nums[0];

        int steal, skip;

        

        for(int i = 2; i<=n; i++){
            steal = nums[i -1] + dp[i -2];
            skip = dp[i-1];

            dp[i] = max(steal, skip);

        }

        return dp[n];
        
    }
};