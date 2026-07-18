class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int ch = 0; ch < s.size(); ch++) {
            if (s[ch] == '(' || s[ch] == '{' || s[ch] == '[') {
                st.push(s[ch]);
            } else {
                if (st.empty()) {
                    return false;
                }
                if (s[ch] == ')' && st.top() == '(' ||
                    s[ch] == '}' && st.top() == '{' ||
                    s[ch] == ']' && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return (st.empty());
    }
};