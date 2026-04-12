#include <bits/stdc++.h>
using namespace std;
int n,m;
using state=pair<int,int>;
vector<vector<char>> arr;
vector<vector<int>> vis;

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

bool inside(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m) return 1;
    else return 0;
}

vector<state> neighbour(state s){
    vector<state> ans;
    for(int i=0;i<4;i++){
        state temp=make_pair(s.first+dx[i],s.second+dy[i]);
        if(inside(temp.first,temp.second)){
            if(arr[temp.first][temp.second]=='1'){
                ans.push_back(temp);
            }
        }
    }
    return ans;

}
void dfs(state st){
    vis[st.first][st.second]=1;
    for(auto it:neighbour(st)){
        if(!vis[it.first][it.second]){
            dfs(it);
        }
    }
}


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        arr=grid;
        n=grid.size();
        m=grid[0].size();
        vis.assign(n, vector<int>(m, 0));
        int islands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && arr[i][j]=='1'){
                    dfs({i,j});
                    islands++;
                }
            }
        }
        return islands;

        
    }
};
