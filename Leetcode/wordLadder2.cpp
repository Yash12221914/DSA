// question link --  https://leetcode.com/problems/word-ladder-ii/description/


#include<bits/stdc++.h>
using namespace std;
class Ans{
    public:
    vector<vector<string>> ladderLength(string begin,string end,vector<string>& arr){
        unordered_set<string> st(arr.begin(),arr.end());
        queue<vector<string>> q;
        q.push({begin});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(begin);
        int level = 0;
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();

            if(vec.size() > level){
                level++;
                for(auto it: usedOnLevel){
                    st.erase(it);
                }
            }
            string word = vec.back();
            if(word == end){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i = 0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a';ch <='z';ch++){
                    word[i] = ch;
                    if(st.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }

};

bool comp(vector<string> a,vector<string> b){
    string x = "",y ="";
    for(string i:a)
        x += i;
    for(string i:b)
        y += i;
    return x<y;
}


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
    vector<vector<string>> answer = obj.ladderLength(begin,end,arr);
    if(answer.size() == 0){
        cout<<-1<<endl;
    }else{
        sort(answer.begin(),answer.end(),comp);
        for(int i = 0;i<answer.size();i++){
            for(int j = 0;j<answer[i].size();j++){
                cout<<answer[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    }
    return 0;
}
