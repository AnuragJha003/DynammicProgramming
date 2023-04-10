class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        // Write your code here.
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
    }//DP ARRAY FOR LCS
    //ANSWER BASICALLY IS THE LONGEST SUBSEQUENCE+THE REMAINING CHARACTERS THAT IS LENGTH IS N+M-LCS... 
    string ans="";
    int i=n;int j=m;
    while(i>0 && j>0){//PRINTING USING DP TABLE AS IN LCS WE SAW
        if(s[i-1]==t[j-1]){
            ans+=s[i-1];
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            ans+=s[i-1];i--;
        }
        else{
            ans+=t[j-1];j--;
        }
    }//printing the longest common subsequence of the two strings in the 
    while(i>0){//I KA KUCH BACH GYA 
        ans+=s[i-1];i--;
    }//adding what is left of s
    while(j>0){//J KA KUCH BACH GYA 
        ans+=t[j-1];j--;
    }//adding what is left of j 
    reverse(ans.begin(),ans.end());//RVERSEING THE ANSWER STRIGN 
    return ans;
    
    
    }
};

https://leetcode.com/problems/shortest-common-supersequence/
