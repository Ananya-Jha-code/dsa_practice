#include<bits/stdc++.h>
using namespace std;

int n,m;
using state =pair<int,int>;
vector<vector<int>> arr;
vector<vector<int>> vispac;
vector<vector<int>> visatl;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

bool inside(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m) return 1;
    return 0;
}

vector<state> neighbour(state st){
    vector<state> ans;
    for(int i=0;i<4;i++){
        state temp=make_pair(st.first+dx[i],st.second+dy[i]);
        if(inside(temp.first,temp.second)){
            if(arr[temp.first][temp.second]>=arr[st.first][st.second]){
                ans.push_back(temp);
            }
        }
    }
    return ans;
}

void dfs(state st, vector<vector<int>>&vis){
    vis[st.first][st.second]=1;
    for(auto v:neighbour(st)){
        if(!vis[v.first][v.second]){
            dfs(v,vis);
        }
    }
}

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        arr=heights;
        n=heights.size();
        m=heights[0].size();
        vispac.assign(n,vector<int>(m,0));
        visatl.assign(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    if(!vispac[i][j]) dfs({i,j},vispac);
                }
                if(i==n-1||j==m-1){
                    if(!visatl[i][j]) dfs({i,j},visatl);
                }
            }
        }
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vispac[i][j] && visatl[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
        
    }
};
