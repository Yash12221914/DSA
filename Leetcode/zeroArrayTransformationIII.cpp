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
    int n; cin>> n;
    vi nums(n);
    loop(i,0,n){
        cin>>nums[i];
    }
    int row;cin>>row;
    int col;cin>>col;
    vvi queries(row,vi(col));
    loop(i,0,row){
        loop(j,0,col){
            cin>>queries[i][j];
        }
    }

    minheap used_query;
    maxheap available_query;
    sort(queries.begin(),queries.end());

    int query_pos = 0,applied_count = 0;
    for(int i = 0;i<n;i++){
        while(query_pos<queries.size() && queries[query_pos][0] == i){
            available_query.push(queries[query_pos][1]);
            query_pos++;
        }
        nums[i] -= used_query.size();
        while(nums[i] > 0 && !available_query.empty() && available_query.top()>= i){
            used_query.push(available_query.top());
            available_query.pop();
            nums[i]--;
            applied_count++;
        }
        if(nums[i] > 0){
            cout<< -1;
            break;
        }
        while(!used_query.empty() && used_query.top() == i){
            used_query.pop();
        }
    }
    cout<<queries.size() - applied_count;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}
