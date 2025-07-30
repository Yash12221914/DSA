#include<bits/stdc++.h>
using namespace std;
#define loop(i,l,r)   for(int i = l;i<r;i++)
#define pb            push_back
#define vi            vector<int>
#define vvi           vector<vector<int>>


void dfs(int node,vi& vis,stack<int>& st,vvi& adj){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]) dfs(node,vis,st,adj);
    }
    st.push(node);
}

void solve(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges;
    loop(i,0,e){
        int u,v;
        cin>>u>>v;
        edges.pb({u,v});
    }
    vvi adj(v);
    for(auto& it: edges){
        adj[it[0]].pb(it[1]);
    }
    
    vector<int> vis(v,0);
    stack<int> st;
    loop(i,0,v){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }

   vi ans;
   while(!st.empty()){
    ans.pb(st.top());
    st.pop();
   }
   loop(i,0,ans.size()){
    cout<<ans[i]<<" ";
   }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}