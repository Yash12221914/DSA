//Problem link - https://leetcode.com/problems/binary-subarrays-with-sum/description/

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
 
int f(vi arr,int goal){
    int n = arr.size();
    int l = 0,r = 0,sum = 0,cnt = 0;
    if(goal<0) return 0;
    while(r<n){
        sum += arr[r];
        while(sum > goal){
            sum -= arr[l];
            l++;
        }
        cnt = cnt + (r-l+1);
        r++;
    }
    return cnt;
} 

void solve(){
    int n;cin>>n;
    vi arr(n);
    loop(i,0,n){
        cin>>arr[i];
    }
    int goal;cin>>goal;
    cout<<f(arr,goal) - f(arr,goal-1);
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}
