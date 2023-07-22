// O(n) time O(1) space
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ans = 0;
        for(int j = n-1; j >= 0; j--) {
            if(ans > 0 && s[j] == ' ') break;
            if(s[j] != ' ') {
                ans++;
            }
        }
        return ans;
    }
};
