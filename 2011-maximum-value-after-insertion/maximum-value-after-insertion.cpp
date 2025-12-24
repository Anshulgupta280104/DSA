class Solution {
public:
    string maxValue(string n, int x) {
        char ch = x + '0';

        // Positive number case
        if (n[0] != '-') {
            for (int i = 0; i < n.size(); i++) {
                if (n[i] - '0' < x) {
                    return n.substr(0, i) + ch + n.substr(i);
                }
            }
            return n + ch; // insert at end if no smaller digit found
        }

        // Negative number case
        for (int i = 1; i < n.size(); i++) {
            if (n[i] - '0' > x) {
                return n.substr(0, i) + ch + n.substr(i);
            }
        }
        return n + ch; // insert at end
    }
};
