class Solution {
public:
    int helper(int inx1, int inx2, string &s1, string &s2, vector<vector<int>> &memo){
        if(inx1 == s1.size() || inx2 == s2.size()){
            return s2.size() + s1.size() - inx2 - inx1;
        }
        
        if(memo[inx1][inx2] != -1) return memo[inx1][inx2];
        
        if(s1[inx1] == s2[inx2]){
            return helper(inx1+1, inx2+1, s1, s2, memo);
        }
        
        int dels1 = 1 + helper(inx1+1, inx2, s1, s2, memo);
        int dels2 = 1 + helper(inx1, inx2+1, s1, s2, memo);
        
        return memo[inx1][inx2] = min(dels1, dels2);
    }
    int minDistance(string word1, string word2) {
        int s1 = word1.length(), s2 = word2.length();
        vector<vector<int>> memo(s1, vector<int>(s2, -1));
        return helper(0, 0, word1, word2, memo);
    }
};
https://leetcode.com/problems/delete-operation-for-two-strings/
