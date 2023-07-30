class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arrayS(26 , 0), arrayT(26, 0);
        for(auto x:s) {
            arrayS[x - 'a']++;
        }
        for(auto x:t) {
            arrayT[x - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(arrayS[i] != arrayT[i])
                return false;
        }
        return true;
    }
};
