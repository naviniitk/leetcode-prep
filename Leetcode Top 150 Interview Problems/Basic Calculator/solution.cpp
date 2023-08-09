class Solution {
public:
    int calculate(string s) {
        stack<int> nums; 
        int ans = 0;
        int sign = 1;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(isdigit(ch)) {
                int val = 0;
                while(i < s.size() && isdigit(s[i])) {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                ans += sign * val;
                sign = 1;
            } else if (ch == '(') {
                nums.push(ans);
                nums.push(sign);
                ans = 0;
                sign = 1;
            } else if(ch == ')') {
                ans = nums.top() * ans;
                nums.pop();
                ans += nums.top();
                nums.pop();
            } else if(ch == '-') {
                sign *= -1;
            }
        }
        return ans;
    }
};
