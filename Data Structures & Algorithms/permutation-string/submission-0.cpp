class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()> s2.size()){
            return false;
        }
        vector<int>count_s1(26,0);
        vector<int>count_s2(26,0);
        for(int i=0; i<s1.size(); i++){
            count_s1[s1[i]-'a']++;
            count_s2[s2[i]-'a']++;
        }
        int matches = 0;
        for(int i=0; i<26; i++){
            if(count_s1[i] == count_s2[i]){
                matches++;
            }
        }
        int l =0;
        for(int r = s1.size(); r < s2.size(); r++){
            if(matches == 26){
                return true;
            }
            int index = (s2[r]-'a');
            count_s2[index]++;
            if(count_s1[index] == count_s2[index]){
                matches ++;
            }
            else if(count_s1[index] + 1 == count_s2[index]){
                matches--;
            }

            index = (s2[l]-'a');
            count_s2[index]--;
            if(count_s1[index] == count_s2[index]){
                matches++;
            }
            else if(count_s1[index]-1 == count_s2[index]){
                matches--;
            } 
            l++;

        }
        return matches == 26;
    }
};
