#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>g;
vector<int> col;
bool isCycle=0;
vector<int> parent;

void dfs(int node, int par){
    parent[node]=par;
    col[node]=2;
    for(auto v:g[node]){
        if(col[v]==1){
            dfs(v,node);
        }
        else if(col[v]==2){
            if(isCycle==0) isCycle=1;
        }
    }
    col[node]=3;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        col.assign(n+1,1);
        parent.assign(n+1,0);
        isCycle=0;
        g.assign(n+1,vector<int>());
        for(auto p:prerequisites){
            g[p[1]].push_back(p[0]);
        }
        for(int i=0;i<n;i++){
            if(col[i]==1) dfs(i,0);
        }
        return isCycle==0;


    }
};
