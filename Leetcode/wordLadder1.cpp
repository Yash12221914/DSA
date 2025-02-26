//  question link ---  https://leetcode.com/problems/word-ladder/

#include<bits/stdc++.h>
using namespace std;

class Ans{
    public:
    int ladderLength(string begin,string end,vector<string>& arr){
        queue<pair<string,int>> q;
        q.push({begin,1});
        unordered_set<string> st(arr.begin(),arr.end());
        st.erase(begin);
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == end) return step;
            for(int i = 0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }

};
int main(){
    int tc;
    cin>>tc;
    while(tc--){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i = 0;i<n;i++) cin>>arr[i];
    string begin,end;
    cin>>begin>>end;
    Ans obj;
    int answer = obj.ladderLength(begin,end,arr);
    cout<<answer<<"\n";
    cout<<"~"<<"\n";
    }
    return 0;
}
