// #include <bits/stdc++.h>
// using namespace std;
// #define loop(i,l,r)     for(int i=l; i<r; i++)
// #define int             long long
// #define pb              push_back
// #define vi              vector<int>
// #define vs              vector<string>
// #define vvi             vector<vector<int>>
// #define vvs             vector<vector<string>>
// #define mkp             make_pair<int,int>
// #define umpii           unordered_map<int,int>
// #define maxheap         priority_queue<int>
// #define minheap         priority_queue<int, vi,greater<int>>
// #define setbits(x)      __builtin_popcountll(x)
// #define zerobits(x)     __builtin_ctzll(x)
// #define in_arr(A,n)     loop(i,0,n) cin>>A[i];
// #define p_arr(A,n)      loop(i,0,n) cout<<A[i];
// #define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
// #define take_n          int n; cin>>n;
// #define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
// #define take_vi         vi(n);loop(i,0,n) cin>>arr[i];
// #define take_vs         vs(n);loop(i,0,n) cin>>arr[i];
  
// const int mod= 1e9+7;
// const int inf= 1e15;
 
// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vi arr(n);
//     umpii freq;
    
//     loop(i,0,n){
//         cin >> arr[i];
//         freq[arr[i]]++;
//     }
    
//     int count = 0;
//     for (auto &[num, cnt] : freq) {
//         int complement = k - num;
//         if (freq.count(complement)) {
//             if (num == complement) {
//                 count += cnt / 2;
//             } else {
//                 int pairs = min(cnt, freq[complement]);
//                 count += pairs;
//                 freq[complement] -= pairs;
//             }
//             freq[num] = 0;
//         }
//     }
    
//     cout << count << endl;
// }
  
// int32_t main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while(t--) solve();
//     return 0;
// }

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
    int n, k;
    cin >> n >> k;
    vi arr(n);
    umpii freq;
    
    loop(i,0,n){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    
    int count = 0;
    for (auto &[num, cnt] : freq) {
        int complement = k - num;
        if (freq.count(complement)) {
            if (num == complement) {
                count += cnt / 2;
            } else {
                int pairs = min(cnt, freq[complement]);
                count += pairs;
                freq[complement] -= pairs;
            }
            freq[num] = 0;
        }
    }
    
    cout << count << endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}
