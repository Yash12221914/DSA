//question link - https://leetcode.com/problems/count-square-submatrices-with-all-ones/

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
    int n,m;
    cin>>n>>m;
    vvi arr(n,vi(m));
    loop(i,0,n){
        loop(j,0,m){
            cin>>arr[i][j];
        }
    }

    vvi dp(n,vi(m));
    loop(i,0,n) dp[i][0] = arr[i][0];
    loop(j,0,m) dp[0][j] = arr[0][j];

    loop(i,1,n){
        loop(j,1,m){
            if(arr[i][i] == 0){
                dp[i][j] = 0;
            }else{
                dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }
        }
    }
    int sum = 0;
    loop(i,0,n){
        loop(j,0,m){
            sum += dp[i][j];
        }
    }
    cout<<sum<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}
