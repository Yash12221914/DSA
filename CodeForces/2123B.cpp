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
#define int             long long

const int mod= 1e9+7;
const int inf= 1e15;
 
 
void solve(){

    long long n;
    cin >> n;
    vector<long long> ans;

    long long ten = 10;
    for (int k = 1; k <= 18; k++) {
        long long d = 1 + ten; 
        if (n % d == 0) {
            long long x = n / d;
            if (x > 0) ans.push_back(x);
        }
        ten *= 10;
    }

    if (ans.empty()) {
        cout << 0 << "\n";
    } else {
        cout << ans.size() << "\n";
        sort(ans.begin(), ans.end());
        for (auto v : ans) cout << v << " ";
        cout << "\n";
    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}
