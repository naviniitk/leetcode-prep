// O(n^2) time and O(1) space 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int m = 200;
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            if(m > strs[i].size()) {
                m = strs[i].size();
            }
        }
        if(m == 0) return ans;
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(strs[j][i] != strs[0][i]) return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};

// O(nlogn) time and O(1) space

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans = "";
        sort(v.begin(), v.end());
        int n = v.size();
        string first = v[0], last = v[n-1];
        for(int i = 0; i < min(first.size(),last.size()); i++){
            if(first[i] != last[i]){
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};
