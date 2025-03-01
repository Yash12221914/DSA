//Problem link --  https://leetcode.com/problems/flood-fill/description/


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
 

void dfs(int row,int col,vvi& ans,vvi& image,int delrow[],int delcol[],int iniColor,int newColor){
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for(int i = 0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){
            dfs(nrow,ncol,ans,image,delrow,delcol,iniColor,newColor);
        }
    }
}
 
void solve(){
    int n,m;
    cin>>n>>m;
    vvi image(n,vi(m,0));
    loop(i,0,n){
        loop(j,0,m){
            cin>>image[i][j];
        }
    }
    int sr,sc,newColor;
    cin>>sr>>sc>>newColor;

    int iniColor = image[sr][sc];
    vvi ans = image;
    int delrow[] = {-1,0,+1,0};
    int delcol[] = {0,+1,0,-1};
    dfs(sr,sc,ans,image,delrow,delcol,iniColor,newColor);
    loop(i,0,n){
        loop(j,0,m){
            cout<<image[i][j]<<" ";
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
