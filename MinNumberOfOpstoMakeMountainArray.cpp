class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
       int n = arr.size();
        vector<int> dp(n, 1), dp2(n, 1);
        int ans = 0;
        for (int ind=0; ind<n; ind++) {
            for (int prev=0; prev<ind; prev++) {
                if (arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind]) {
                    dp[ind] = 1 + dp[prev];
                }
            }
        }
        for (int ind=n-1; ind>=0; ind--) {
            for (int prev=n-1; prev>ind; prev--) {
                if (arr[prev] < arr[ind] && 1 + dp2[prev] > dp2[ind]) {
                    dp2[ind] = 1 + dp2[prev];
                }
            }
        }
        for (int i=0; i<n; i++) {
            if (dp[i] > 1 && dp2[i] > 1) {
                ans = max(dp[i] + dp2[i] - 1, ans);
            }
        }
        return n - ans;
    }
};
https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
