// class Solution {
// public:
//     int dp[301];
//     int n;

//     unordered_set<string> wordSet;

//     bool solve(int idx, string& s) {
//         if (idx >= n) {
//             return true;
//         }

//         if (dp[idx] != -1)
//             return dp[idx];

//         for (int l = 1; l <= n ; l++) {
//             string temp = s.substr(idx, l);
//             if (wordSet.find(temp) != wordSet.end() && solve(idx + l, s)) {
//                 return dp[idx] = true;
//             }
//         }

//         return dp[idx] = false;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         n = s.length();

//         wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());

//         memset(dp, -1, sizeof(dp));

//         return solve(0, s);
//     }
// };
