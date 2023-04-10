class Solution {
public:
    bool recur(string &pattern,string &text,int i,int j,vector<vector<bool>>& dp)
{
    if(i<0 && j<0) return true;//if both exhausted comparison done together
    if(i<0 && j>=0) return false;//if s1 exhausted and s2 is there thhen false
    if(j<0 && i>=0)//if s2 is exhausted pattern s1 is presnt
    {
        //if first string is left it has to be all stars then it has to be stars fr empty string 
        for(int q=0;q<=i;q++)//all have to be star as they map to an empty sequence
        {
            if(pattern[q]!='*') return false;//if not equal to * then false
        }
        return true;//ekse true
    }
    if(dp[i][j])return dp[i][j];
    if(pattern[i]==text[j] || pattern[i]=='?') return dp[i][j]=recur(pattern,text,i-1,j-1,dp);
    if(pattern[i]=='*')
    {
        return dp[i][j]=recur(pattern,text,i-1,j,dp) || recur(pattern,text,i,j-1,dp);
        //either the * representrs empty i-1 and j or the star represents 1 or more char
        //i and j-1 
    }
    return dp[i][j]=false;
    
}
    bool isMatch(string text, string pattern) {
       /* int n=pattern.size(),m=text.size();
   vector<vector<bool>> dp(n,vector<bool>(m,false));
    return recur(pattern,text,n-1,m-1,dp);//rect m dp  */ 
         int n=pattern.size(),m=text.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,false));
    dp[0][0]=true;
    for(int q=1;q<=m;q++) dp[0][q]=false;
    for(int ii=1;ii<=n;ii++)
    {
        int flag=true;
        for(int iq=1;iq<=ii;iq++)
        {
            if(pattern[iq-1]!='*')
            {
                flag=false;
                break;
            }
        }
        dp[ii][0]=flag;
    }
        //this is for all the base cases accumulated during tabulation in here 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(pattern[i-1]==text[j-1] || pattern[i-1]=='?')
                dp[i][j]=dp[i-1][j-1];
            else if(pattern[i-1]=='*')
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            else
                dp[i][j]=false;
        }
    }
    return dp[n][m];
    }
};

https://leetcode.com/problems/wildcard-matching/
