class Solution {
public:

    string encode(vector<string>& strs) {
        string encoding ="";
        for(int i=0; i<strs.size(); i++){
            encoding += to_string(strs[i].size()) + '#' + strs[i];
        }
        return encoding;
    }

    vector<string> decode(string s) {
        vector<string>decoding;
        int i= 0;
        while(i < s.size()){
            int j = i;
            while( s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            decoding.push_back(s.substr(j+1, len));
            i = j+1+len;
        }
        return decoding;
    }
};
