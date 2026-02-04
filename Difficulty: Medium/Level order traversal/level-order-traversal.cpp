class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        
        vector<vector<int>> result;
        if(root == NULL) return result;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            
            int size = q.size();      // nodes at current level
            vector<int> level;

            for(int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();

                level.push_back(temp->data);

                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            result.push_back(level);   // store this level
        }

        return result;
    }
};
