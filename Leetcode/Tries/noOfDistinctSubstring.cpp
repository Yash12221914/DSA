//Problem link -- https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/description/
struct Node{
    Node* link[26];
    bool containsKey(char ch){
        return link[ch-'a'];
    }
    void put(char ch,Node* node){
        link[ch-'a'] = node;
    }
    Node* get(char ch){
        return link[ch-'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int count = 0;
    Node* root = new Node();
    for(int i = 0;i<s.length();i++){
        Node* node = root;
        for(int j = i;j<s.length();j++){
            if(!node->containsKey(s[j])){
                count++;
                node->put(s[j],new Node());
            }
            node = node->get(s[j]);
        }
    }
    return count+1;
}
