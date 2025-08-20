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
    int n,m,k;
    cin>>n>>m>>k;
    vvi times(n,vi(m));
    loop(i,0,n){
        loop(j,0,m){
            cin>>times[i][j];
        }
    }
     vector<pair<int,int>> adj[n+1];
        for (auto &time : times) {
            int u = time[0];
            int v = time[1];
            int d = time[2];
            adj[u].push_back({v, d});
        }
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        queue<pair<int,int>> q;
        q.push({0, k});
        while (!q.empty()) {
            auto [cost, node] = q.front();
            q.pop();
            for (auto &[nextNode, weight] : adj[node]) {
                if (cost + weight < dist[nextNode]) {
                    dist[nextNode] = cost + weight;
                    q.push({dist[nextNode], nextNode});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        
        cout<<maxTime<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}
