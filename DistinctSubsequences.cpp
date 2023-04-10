int mod = 1e9+7;
//i is the pointer to the text and j is the pointer to the string s
//looking for subsequence of text whcih equals s and count them 
int countSubsequence(int i, int j, string t, string s, vector<vector<int>> &dp) {
    if(j == 0) return 1;
    if(i == 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    
    if(t[i - 1] == s[j - 1])
        return dp[i][j] = (countSubsequence(i - 1, j - 1, t, s, dp) + countSubsequence(i - 1, j, t, s, dp)) % mod;
    else
        return dp[i][j] = countSubsequence(i - 1, j, t, s, dp) % mod;
}

int subsequenceCounting(string &t, string &s, int m, int n) {
    // Write your code here.
    int mod = 1e9+7;
    
    //------------RECURSION + MEMOIZATION---------------
    /*vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    return countSubsequence(m, n, t, s, dp);*/
    
    
    //---------TABULATION (2D ARRAY)----------
    /*vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    for(int i = 0; i <= m; i++) dp[i][0] = 1;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(t[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i-1][j - 1] + dp[i-1][j];
                dp[i][j] %= mod;
            }
            else {
                dp[i][j] = dp[i-1][j];
                dp[i][j] %= mod;
            }
        }
    }
    return dp[m][n];*/
 https://leetcode.com/problems/distinct-subsequences/
