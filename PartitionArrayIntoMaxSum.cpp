class Solution {
public:
    int f(int i,vector<int>& arr,int k,vector<int>& dp){
        if(i==arr.size())return 0;//if i reached till end no more partition 
        if(dp[i]!=-1)return dp[i];
        int len=0;//taking the size of the partition initilaly as 0 
        int mx=INT_MIN;//max elmnt of the partition till now 
        int ans=INT_MIN;//storing the max sum of such parition 
        int n=arr.size();
        for(int ind=i;ind< min(n,i+k);ind++){ //partitions being made  as size k so we go from i to i+k and min taken so no out of bound happens 
            len++;//increment the size of the parititon 
            mx=max(mx,arr[ind]);//storing max elemnt till the partition 
            int sum=len*mx +f(ind+1,arr,k,dp);//AS CURRENT PARTITION IS FILLED WITH THE MAX SO LEN*MX AND + THE RECURSSIVE CALL FOR THE SUM ON FURTHER PARTITIONS RIGHT HAND SIDE F(IND+1)
            ans=max(ans,sum);//STORE THE MAX OF ALL THE LARGE SUMS POSSIBLE IN HERE 
        }
        return dp[i]=ans;//STORE IT 
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(0,arr,k,dp);//O(N*N) FOR THE PARIIOTNS TO BE MADE 
        //i is the startig index fro the traversal i==0 and arr and k is the size of the subarray
    }
};

https://leetcode.com/problems/partition-array-for-maximum-sum/
