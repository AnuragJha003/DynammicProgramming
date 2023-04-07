int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp,int n){
    if(i==n-1){
        return triangle[n-1][j];//END ROW M AAGYA SO RETURN THAT POINT/ELEMNT HERE THERE IS MULTIPLE END POINTS POSSIBLE SO 
    }
    if(dp[i][j]!=-1) return dp[i][j]; 
    int d=triangle[i][j]+f(i+1,j,triangle,dp,n);
    int dg=triangle[i][j]+f(i+1,j+1,triangle,dp,n);
    return dp[i][j]=min(d,dg);
                        
}//VARIABLE ENDING POINT FIXED STARTIN GPOINT 
//ONLY RECURSION WILL GIVE TLE 


int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
   // vector<vector<int>> dp(n,vector<int>(n,-1));
    //return f(0,0,triangle,dp,n);

   vector<vector<int> > dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }
    
    return dp[0][0];
}//time complexity is O(N*N)

https://leetcode.com/problems/triangle/
