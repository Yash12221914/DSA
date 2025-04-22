#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define revloop(i,l,r)  for(int i=l;i>=r;i--)
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

    int n;cin>>n;
    vi arr1(n);
    loop(i,0,n){
        cin>>arr1[i];
    }
    int m;cin>>m;
    vi arr2(m);
    loop(i,0,m){
        cin>>arr2[i];
    }
    map<int,int> mpp;
    vi nge;
    stack<int> st;
    revloop(i,m,0){
        while(!st.empty() && st.top() <= arr2[i]){
            st.pop();
        }
        if(st.empty()){
            mpp[arr2[i]] = -1;
        }else{
            mpp[arr2[i]] = st.top();
        }
        mpp.push(arr2[i]);
    }
    for(auto& i:arr1){
        nge.push_back(mpp[i]);
    }
    loop(i,0,nge.size()){
        cout<<nge[i]<<" ";
    }
    cout<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}
