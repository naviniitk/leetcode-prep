class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string x:tokens) {
            if(x != "+" && x != "-" && x != "/" && x != "*") {
                st.push(stoi(x));
            } else {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                int res = 0;
                if(x == "+")
                    res = first + second;
                else if(x == "-")
                    res = first - second;
                else if(x == "*")
                    res = first * second;
                else
                    res = first / second;
                st.push(res);
            }
        }
        return st.top();
    }
};
