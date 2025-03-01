//question link -- https://leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define vs              vector<string>
#define vc              vector<char>
#define vvi             vector<vector<int>>
#define vvs             vector<vector<string>>
#define vvc             vector<vector<char>>
#define mkp             make_pair<int,int>
#define umpii           unordered_map<int,int>
#define maxheap         priority_queue<int>
#define minheap         priority_queue<int, vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define in_arr(A,n)     loop(i,0,n) cin>>A[i];
#define p_arr(A,n)      loop(i,0,n) cout<<A[i];
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
#define take_vi         vi(n);loop(i,0,n) cin>>arr[i];
#define take_vs         vs(n);loop(i,0,n) cin>>arr[i];
  
const int mod= 1e9+7;
const int inf= 1e15;
 


void dfs(int row,int col,vvi &vis,vvc &grid,int delrow[],int delcol[]){
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    loop(i,0,4){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 'O'){
            dfs(nrow,ncol,vis,grid,delrow,delcol);
        }
    }
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    vvc grid(n, vc(m));
    loop(i,0,n){
        loop(j,0,m){
            cin>>grid[i][j];
        }
    }
    int delrow[] = {-1,0,+1,0};
    int delcol[] = {0,+1,0,-1};
    vvi vis(n,vi(m,0));
    loop(j,0,m){
        if(!vis[0][j] && grid[0][j] == 'O'){
            dfs(0,j,vis,grid,delrow,delcol);
        }
        if(!vis[n-1][j] && grid[n-1][j] == 'O'){
            dfs(n-1,j,vis,grid,delrow,delcol);
        }
    }
    loop(i,0,n){
        if(!vis[i][0] && grid[i][0] == 'O'){
            dfs(i,0,vis,grid,delrow,delcol);
        }
        if(!vis[i][m-1] && grid[i][m-1] == 'O'){
            dfs(i,m-1,vis,grid,delrow,delcol);
        }
    }
    loop(i,0,n){
        loop(j,0,m){
            if(!vis[i][j] && grid[i][j] == 'O'){
                grid[i][j] = 'X';
            }
        }
    }
    loop(i,0,n){
        loop(j,0,m){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
  
  
int32_t main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
