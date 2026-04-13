#include <bits/stdc++.h>
using namespace std;

int n;
int comp=0;
vector<vector<int>>g;
vector<int>vis;

void dfs(int node){
    vis[node]=1;
    for(auto it:g[node]){
        if(!vis[it]){
            dfs(it);
        }
    }

}
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        g.assign(n+1,vector<int>());
        vis.assign(n+1,0);
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp++;
                dfs(i);
            }
        }
        return comp;
    }
};
