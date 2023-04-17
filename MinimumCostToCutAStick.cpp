class Solution {
public:
    int dp[101][101];
    
    int f(int i,int j,int l,int r,vector<int>& c)
    {
        if(i>j)return 0;//if no more partitions to be done 
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++)
            ans=min(ans,r-l+f(i,k-1,l,c[k],c)+f(k+1,j,c[k],r,c));
			//r - l is the current cost of the cutt and do it for the left partition and right partition individuallty 
        return dp[i][j]=ans;
    }
    
    int minCost(int len, vector<int>& c) {
        sort(c.begin(),c.end());
        //we need to sort this so that we ensure there is no dependecny of the subproblems in there and they can be solved independently 1 3 4 5 cut at 4 then (1 3) and (5) if 1 3 4 5 2 and cut at 4 then (1 3) (5 2) dependecy of right on left as 2 h toh so we sort and then do the cut process to ensure no dependeancy of subproblems on each other 
        memset(dp,-1,sizeof(dp));
        return f(0,c.size()-1,0,len,c);
        //0 is the leftmost cut and len is the rightmost cut 0 and length assigned 
    }
};

https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
