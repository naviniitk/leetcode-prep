class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> replaced;
        unordered_map<char, bool> used;
        for(int i = 0; i < s.length(); i++) {
            if(replaced.count(s[i])) {
                if(replaced[s[i]] != t[i]) // if replacement not equals then false
                    return false;
            } else {
                if(used[t[i]])
                    return false;
                replaced[s[i]] = t[i]; // assign the element to be used as replaced for s[i]
                used[t[i]] = true;
            }
        }
        return true;
    }
};
