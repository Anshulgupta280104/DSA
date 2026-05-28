class Solution {
public:
    
    struct Node {
        int child[26];
        int bestIdx;
        
        Node() {
            memset(child, -1, sizeof(child));
            bestIdx = -1;
        }
    };

    vector<Node> trie;
    
    // returns better index
    int better(vector<string>& words, int a, int b) {
        if(a == -1) return b;

        if(words[a].size() != words[b].size())
            return (words[a].size() < words[b].size()) ? a : b;

        return min(a, b);
    }

    void insert(string &s, int idx, vector<string>& words) {
        int node = 0;

        trie[node].bestIdx = better(words, trie[node].bestIdx, idx);

        for(int i = s.size() - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if(trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[c];

            trie[node].bestIdx = better(words, trie[node].bestIdx, idx);
        }
    }

    int query(string &s) {
        int node = 0;

        for(int i = s.size() - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if(trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].bestIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        trie.push_back(Node());

        for(int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;

        for(auto &q : wordsQuery) {
            ans.push_back(query(q));
        }

        return ans;
    }
};