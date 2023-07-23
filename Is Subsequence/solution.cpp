class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "") return true;
        if(s.size() > t.size()) return false;
        int j = 0;
        for(int i = 0; i < t.size(); i++) {
            if(s[j] == t[i]) j++;
        }
        if(j < s.size()) return false;
        return true;
    }
};
