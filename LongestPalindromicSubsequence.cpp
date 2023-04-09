class Solution {
public:
    
int lcs(string s, string t)
{
    int n=s.size();int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //return f(n-1,m-1,s,t,dp);
    //TABULATION CODE 
    for(int j=0;j<m;j++) dp[0][j]=0;
    for(int i=0;i<n;i++) dp[i][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][m];
    
    //Write your code here
}//THIS IS THE LONGEST COMMON SUBSEQUENCE TABULATION CODE IN HERE 

    
    int longestPalindromeSubseq(string s) {
          string t=s;
        //LONGEST PALINDROMIC SUBSEQUENCE OF S WILL BE LCS OF S AND REVERSE OF S 
    reverse(t.begin(),t.end());
    return lcs(s,t);
        
    }
};

https://leetcode.com/problems/longest-palindromic-subsequence/
