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
}



//maximum will be delete all from s1(n) and add them to s2(m) n+m
//minimum will be to keep the longest common subsequence intact 
//for minimum operations in here  
//n-lcs + m-lcs=====(n+m)-2*lcs


int canYouMake(string &str, string &ptr)
{
    int n=str.size();int m=ptr.size();
    return n+m-2*lcs(str,ptr);
    // Write your code here.
}
https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
