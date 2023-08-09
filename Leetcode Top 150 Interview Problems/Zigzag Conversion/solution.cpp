class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string> zigzag(numRows, "");

        int j = 0;
        bool edge = false;
        for(int i = 0; i < s.size(); i++) {
            if(j == numRows - 1 || j == 0)
                edge = !edge; // this is for alternating up and down
            zigzag[j] += s[i];
            if(edge)
                j++; // will keep increasin until lower edge reaches
            else
                j--; // will keep decreasing until uper edge reaches
        }
        string ans = "";

        for(auto &it:zigzag)
            ans += it;
        return ans;
    }
};
