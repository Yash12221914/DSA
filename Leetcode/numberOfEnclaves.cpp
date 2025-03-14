// question link ----  https://leetcode.com/problems/number-of-enclaves/

#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define vs              vector<string>
#define vvi             vector<vector<int>>
#define vvs             vector<vector<string>>
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
 
 
void solve(){
    int n, m;
    cin >> n >> m;
    vvi grid(n, vi(m));
    loop(i,0,n){
        loop(j,0,m){
            cin>>grid[i][j];
        }
    }
    queue<pair<int,int>> q;
    vvi vis(n,vi(m,0));
    loop(i,0,n){
        loop(j,0,m){
            if(i == 0 || j == 0 || i == n-1 || j == m-1){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
    }
    int delrow[] = {-1,0,+1,0};
    int delcol[] = {0,+1,0,-1};
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        loop(i,0,4){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                q.push({nrow,ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
    int count = 0;
    loop(i,0,n){
        loop(j,0,m){
            if(vis[i][j] == 0 && grid[i][j] == 1){
                count++;
            }
        }
    }
    cout<<count;
}
  
  
int32_t main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
