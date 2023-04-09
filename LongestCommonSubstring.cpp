int lcs(string &s, string &t){
    int n=s.size();int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //return f(n-1,m-1,s,t,dp);
    //TABULATION CODE
    //f()())()()()()()()()()
    //()()()()*T&)(G)(&)()H()(H)(7_)(*HN)()()()
    
    int ans=0;
    for(int j=0;j<m;j++) dp[0][j]=0;//,...
    for(int i=0;i<n;i++) dp[i][0]=0;//ALL UNUSED WALE INITILIASED WITH 0

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){//IF MATCH HOGYA COMMON SUBSTRING 
                dp[i][j]=1+dp[i-1][j-1];//ADD 1 TOO THE LENGHT OF SUNSTIRNG STORED IN DP 
                //ADDING 1 TO THE PREVIOUS CONSECUTIVE
                ans=max(ans,dp[i][j]);//MAX LENGHT STORE KR RHA AS CONSECUTIVE HONA CHAHIYE SO LIKE THIS  
            }//ADD 1 TO THE LENGHT OF THE SUBSTRING ONLY IF PREVIOUS IS MATCHING ELSE GIVE IT 0 AS NO MORE A LAREGER COMMON SUBSTRING 
            else dp[i][j]=0;//ELSE INITILASED WITH 0 AGAR SAME NHI H AS SUBSTIRNG NEEDS TO BE CONSECUTIVE UNLIKE SUBSEQUENCE 
        }
    }
    return ans;
}
https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
