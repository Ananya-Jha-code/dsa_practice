class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>res;
        for(auto& s: strs){
            string sortres= s;
            sort(sortres.begin(), sortres.end());
            res[sortres].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto& t:res){
            ans.push_back(t.second);
        }
        return ans;
        
    }
};
