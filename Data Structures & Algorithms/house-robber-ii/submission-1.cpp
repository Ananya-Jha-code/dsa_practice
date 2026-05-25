class Solution {
    vector<vector<int>> dp;
public:
    int f(int level,bool flag,vector<int>& nums){
        int n = nums.size();
        //pruning
        //basecase
        if(level>=n) return 0;
        //started from1 then we cannot take n-1
        if(level==n-1&&flag) return 0;
        //cache check
        if(dp[level][flag]!=-1) return dp[level][flag];

        //transition
        //not take
        int ans=0;
        ans = max(ans,f(level+1,flag,nums));
        //take
        ans = max(ans,nums[level] + f(level + 2,flag,nums));
        //save and return
        return dp[level][flag]=ans;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(nums.size(),vector<int>(2,-1));
        if(n==1) return nums[0];
        return max(f(0,1,nums),f(1,0,nums));
    }
};
