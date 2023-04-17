/*class Solution {
public:
    bool ispal(int i,int j,string s){
        bool f=true;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    int f(int i,string s,vector<int>& dp){
        if(i==s.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int n=s.size();
        int mn=INT_MAX;
        for(int j=i;j<n;j++){
            //trying all possible partitions 
            if (ispal(i,j,s)){
                int cost=1+f(j+1,s,dp);
                mn=min(mn,cost);
            }
        }
        return dp[i]=mn;
    }
    
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return f(0,s,dp)-1;
    }
};*/
class Solution {
    bool isPal(string &s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int dfs(int i, int n, string &s, vector<int> &dp) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        string t;
        int ans = 1e9;
        for(int j=i; j<n; j++) {//trying partition at all indexs ahead from i to n and if it is palindrome then u cna do else no 
            t += s[j];
            if(isPal(t)) ans = min(ans, 1 + dfs(j + 1, n, s, dp));
        }
        return dp[i] = ans;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return dfs(0, n, s, dp) - 1;
    }
};
/*
class Solution {
    bool isPal(string &s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1);

        for(int i=n-1; i>=0; i--) {
            string t;
            int ans = 1e9;
            for(int j=i; j<n; j++) {
                t += s[j];
                if(isPal(t)) ans = min(ans, 1 + dp[j + 1]);
            }
            dp[i] = ans;
        }
        return dp[0] - 1;
    }
};*/

https://leetcode.com/problems/palindrome-partitioning-ii/
