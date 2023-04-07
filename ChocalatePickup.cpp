int f(int i,int j1,int j2,int r,int c, vector<vector<int>> &grid ,vector<vector<vector<int>>> &dp){
    if(j1<0 || j1>=c || j2<0 || j2>=c){
        return -1e8;
    }//edge case for out of bounds i or rows of both them toh handled by the base case 
    if(i==r-1){//reached till end 
        if(j1==j2) return grid[i][j1];//if both r in the same col
        else{
            return grid[i][j1]+grid[i][j2];//return sum of both the chocaltes takem 
        }
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int maxi=-1e8;//
   //i walwats +1 j1 alice +1 -1 0 correspondingly simulatneously j2 bob ka +1 -1 0 
    for(int dj1=-1;dj1<=1;dj1++){//j1 is for alice 
        for(int dj2=-1;dj2<=1;dj2++){//j2 is for bob 
            //i always goes+1 
            int value=0;
            if(j1==j2) value=grid[i][j1];//same col m h initially
            else value=grid[i][j1]+grid[i][j2];//else add up to the initial value before recurssive call 
            value+=f(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
            maxi=max(maxi,value);
        }
    }
    return dp[i][j1][j2]=maxi;
} //RECURRSION ONLY WILL GIVE TLE 
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));//3D DP IS IN HERE i j1 and j2 are the changing parameters
    return f(0,0,c-1,r,c,grid,dp);
}

https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
