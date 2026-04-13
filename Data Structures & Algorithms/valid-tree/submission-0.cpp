//valid tree when number of edges are exactly n-1 and no cycles
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>g;
vector<int> col;
void dfs(int node, int par){
    col[node]=2;
    for(auto it:g[node]){
        if(it==par) continue;
        if(col[it]==1){
            dfs(it,node);
        }
        else if(col[node]==2){
            col[0]=-1;
        }
        
    }
    col[node]=3;
}

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        g.assign(n+1,vector<int>());
        col.assign(n+1,1);
        for(auto& p:edges){
            g[p[1]].push_back(p[0]);
            g[p[0]].push_back(p[1]);
        }
        dfs(0,-1);
        for(int i=0;i<n;i++){
            if(col[i]==1) return false;
        }
        if(col[0]==-1) return false;
    return true;
    }
};
