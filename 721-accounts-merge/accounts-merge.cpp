class Solution {
public:
    
    int findParent(int x, vector<int> &parent) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);
    }

    void unite(int a, int b, vector<int> &parent) {
        a = findParent(a, parent);
        b = findParent(b, parent);
        if (a != b) parent[b] = a;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        unordered_map<string, int> emailToIndex;

        // Union accounts having same email
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToIndex.count(email)) {
                    unite(i, emailToIndex[email], parent);
                } else {
                    emailToIndex[email] = i;
                }
            }
        }

        // Group emails by root parent
        unordered_map<int, set<string>> groups;
        for (auto &p : emailToIndex) {
            int root = findParent(p.second, parent);
            groups[root].insert(p.first);
        }

        // Build result
        vector<vector<string>> result;
        for (auto &g : groups) {
            vector<string> merged;
            merged.push_back(accounts[g.first][0]); // name
            for (auto &mail : g.second)
                merged.push_back(mail);
            result.push_back(merged);
        }

        return result;
    }
};
