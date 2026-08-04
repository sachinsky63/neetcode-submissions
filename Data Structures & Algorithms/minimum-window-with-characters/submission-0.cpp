class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        unordered_map<int,int>window;
        unordered_map<int,int>t_count;
        for(int i=0; i<t.size(); i++){
            t_count[t[i]]++;
        }
        int l =0;
        pair<int,int>ans = {-1,-1};
        int ans_len = INT_MAX;
        int have = 0;
        int need = t_count.size();
        for(int r=0; r < s.size(); r++){
            char c = s[r];
            window[c]++;
            if(t_count.count(c) && t_count[c] == window[c]){
                have ++;
            }
            while( have == need){
                // update the ans
                if(r - l + 1 < ans_len){
                    ans_len = r - l + 1;
                    ans ={l, r};
                }
                // pop from left of our window
                window[s[l]]--;
                if(t_count.count(s[l])  && t_count[s[l]] > window[s[l]]){
                    have--;
                }
                l++;
            }

        }
        if(ans_len != INT_MAX){
            return s.substr(ans.first,ans_len);
        }
        return "";
    }
};
