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
 
vi prevSmaller(vi &arr) {
    int n = arr.size();
    vi ans(n); // fix: allocate size
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

vi nextSmaller(vi &arr) {
    int n = arr.size();
    vi ans(n); // fix: allocate size
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    loop(i, 0, n) {
        cin >> arr[i];
    }

    int ans = 0;
    vi left = prevSmaller(arr);
    vi right = nextSmaller(arr);

    for(int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = arr[i] * width;
        ans = max(ans, area);
    }

    cout << ans << endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}
