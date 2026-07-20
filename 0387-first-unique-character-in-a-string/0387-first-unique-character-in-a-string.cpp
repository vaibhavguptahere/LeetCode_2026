class Solution {
public:
    int firstUniqChar(string s) {
        queue<char> q;
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        for (char ch : s) {
            q.push(ch);

            while (!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }
        }

        if (q.empty()) {
            return -1;
        }

        return s.find(q.front());
    }
};