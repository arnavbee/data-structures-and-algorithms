// ## House Robber

// ### Approach 1: Recursion + Memoisation

// class Solution {
// public:
//     int dp[101];

//     int solve(vector<int>& nums, int i, int n){
        

//         if(i>=n) return 0;

//         if(dp[i] != -1) return dp[i];

//         int steal = nums[i] + solve(nums, i+2, n);
//         int skip = solve(nums, i+1, n);

        

//         return dp[i] = max(steal,skip);
//     }
//     int rob(vector<int>& nums) {

//         int n = nums.size();

//         memset(dp, -1, sizeof(dp));

        

//         return solve(nums, 0, n);
        
//     }
// };



// ### Approach 2: Bottoms Up

// class Solution {
// public:

//     int rob(vector<int>& nums) {

//         int n = nums.size();

//         if(n == 1){
//             return nums[0];
//         }

//         vector<int> dp(n + 1, 0);

//         dp[0] = 0;
//         dp[1] = nums[0];

//         int steal, skip;

        

//         for(int i = 2; i<=n; i++){
//             steal = nums[i -1] + dp[i -2];
//             skip = dp[i-1];

//             dp[i] = max(steal, skip);

//         }

//         return dp[n];
        
//     }
// };