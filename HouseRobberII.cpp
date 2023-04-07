class Solution {
public:
    long long int solve(vector<int>&v){
    int n = v.size();
    if(n==0)return 0;
    if(n==1)return v[0];
    if(n==2)return max(v[0],v[1]);
    vector<long long>dp(n+1,0);
    dp[0]=0;
    dp[1] = v[0];
    dp[2] = max(v[0],v[1]);//BASE CASES INITIALSED IN TABULATION FORM 
    for(int i=3;i<=n;i++){//3RD SE END TAK TRAVERSE 
        int val = v[i-1];//VALUE PASSED IN THE REFRENCE 
        dp[i] = max(dp[i-1],dp[i-2]+val);//NP DP[I-1] AND PICK DP[I-2]+VAL ADD KRDOGE USS INDEX KA 
    }
    return dp[n];
}
    int rob(vector<int>& valueInHouse) {
        int n = valueInHouse.size();
    if(n==0)return 0;
    if(n==1)return valueInHouse[0];
    if(n==2)return max(valueInHouse[0],valueInHouse[1]);
    vector<int>a;
    vector<int>b;
    //SINCE FIRST AND LAST R ADJACENT CIRCULAR TOH SO WE CHECK FROM THE 2ND TO THE LAST INDEX AND FROM THE 1ST TO THE 2ND LAST INDEX
    for(int i=0;i<n-1;i++){
        a.push_back(valueInHouse[i]);
    }//PUSHED BACK FROM 1ST TO 2ND LAS T 
    for(int i=1;i<n;i++){
        b.push_back(valueInHouse[i]);
    }//PUSHED BACK FROM 2ND TO THE LAST ELMNT 
    return max(solve(a),solve(b));//MAX SOLVE OF THE 2 FUNCTION 
    }
};

https://leetcode.com/problems/house-robber-ii/
