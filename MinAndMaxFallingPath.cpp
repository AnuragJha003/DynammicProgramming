MAX FALLING PATH SUM 

int f(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    if(j<0 || j>=matrix[0].size()) return -1e8;//OUT OF BOUNDARY CONDITION 
    if(i==0) return matrix[0][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int u=matrix[i][j]+f(i-1,j,matrix,dp);
    int ld=matrix[i][j]+f(i-1,j-1,matrix,dp);
    int rd=matrix[i][j]+f(i-1,j+1,matrix,dp);
    return dp[i][j]=max(u,max(ld,rd));
}
//ONLY RECURSSION WILL GIVE TEL 

//MEMOIZATION WORKS 
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    //int maxi=-1e8;
    //for(int j=0;j<m;j++){
        //maxi=max(maxi,f(n-1,j,matrix,dp));
    //DONE BCZ OF VARIABLE STARTING POINT AS WELL AS ENDING POINT TOH MANY TIME RECURANCE CALL KRNA HOGA 
    //return maxi; 
    for(int j=0;j<m;j++) dp[0][j]=matrix[0][j];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
         int u=matrix[i][j]+dp[i-1][j];
    int ld=matrix[i][j];
           if(j-1>=0) ld+=dp[i-1][j-1];
           else ld+=-1e8; 
    int rd=matrix[i][j];
            if(j+1<m) rd+=dp[i-1][j+1];
            else rd+=-1e8;
            dp[i][j]=max(u,max(ld,rd));
    }
    }
        int maxi=-1e8;
    for(int j=0;j<m;j++){
        maxi=max(maxi,dp[n-1][j]);
    }//DONE BCZ OF VARIABLE STARTING POINT AS WELL AS ENDING POINT TOH MANY TIME RECURANCE CALL KRNA HOGA 
    return maxi; 
    //  Write your code here.
}
https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

MIN FALLING PATH SUM 
class Solution {
public:
    
    int minsum(vector<vector<int>>& matrix, int n, int row, int col,  vector<vector<int>>& dp){
        
        if(row >=n || col >=n || row <0 || col <0)
            return 10000001;//if row or column goes out of bound 
        
        if(row == n-1)//if we reach the last row 
            return matrix[row][col];
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
            int below = matrix[row][col] + minsum(matrix,n,row+1,col,dp); 
            int left  = matrix[row][col] + minsum(matrix,n,row+1,col-1,dp);
            int right = matrix[row][col] + minsum(matrix,n,row+1,col+1,dp);//taking all the 3 options in here 
        
        dp[row][col] = min(below,min(left,right));//storing it in the minimum index 
        return dp[row][col];//return dp[row][col]
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 10000000;//minimum assigned to 
        vector<vector<int>>dp(101,vector<int>(101,-1));//as size 100 given 
        for(int i = 0; i<n; i++){
            int temp_ans = minsum(matrix,n,0,i,dp);//recurance is called for all the cols of the last row and minimum is taken 
            ans = min(ans,temp_ans);//and storing the minimum 
        }
        return ans;
    }
};

https://leetcode.com/problems/minimum-falling-path-sum/
