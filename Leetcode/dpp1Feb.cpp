//problem link -- https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02

// Now I am trying to update using my vscode
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
    int row1,col1;
    cin>>row1>>col1;
    vvi nums1(row1,vi(col1,0));
    loop(i,0,row1){
        loop(j,0,col1){
            cin>>nums1[i][j];
        }
    }
    int row2,col2;
    cin>>row2>>col2;
    vvi nums2(row2,vi(col2,0));
    loop(i,0,row2){
        loop(j,0,col2){
            cin>>nums2[i][j];
        }
    }
    umpii mp;
    for(auto& p : nums1) mp[p[0]] += p[1];
    for(auto& p : nums2) mp[p[0]] += p[1];
    
    vvi result;
    for (auto& p : mp) {
        result.push_back({p.first, p.second});
    }
    
    sort(result.begin(), result.end()); 
    
    loop(i,0,result.size()){
        loop(j,0,result[0].size()){
            cout<<result[i][j]<<" ";
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
