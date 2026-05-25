class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> dp2;
    int palindrome(int i, int j, string &s){
        //base case
        if(i == j || i > j)return true;

        if(dp[i][j] != -1)return dp[i][j];

        return dp[i][j] = (s[i] == s[j] && palindrome(i + 1,j - 1,s));
    }
    int f(int i,int j,string &s){
        //pruning
        //basecase
        //cache check
        if(dp2[i][j] != -1)return dp2[i][j];
        //transition
        int ans = 0;
        if(s[i] == s[j]) {
            if(palindrome(i,j,s)) {
                ans = max(ans,(j - i + 1));
                return ans;
            }
        }
        ans = max({ans,f(i + 1,j,s),f(i,j - 1,s)});
        //save and
        return dp2[i][j] = ans;
    }
    string longestPalindrome(string s) {
        dp.resize(1001,vector<int>(1001,-1));
        dp2.resize(1001,vector<int>(1001,-1));
        int n = s.size();
        int l = f(0,n - 1,s);
        for(int i = 0;i < n;i++) {
            int r = i + l - 1;
            if(palindrome(i,r,s)) {
                string ans;
                for(int j = i;j <= r;j++) {
                    ans.push_back(s[j]);
                }
                return ans;
            }
        }
        
    }
};
