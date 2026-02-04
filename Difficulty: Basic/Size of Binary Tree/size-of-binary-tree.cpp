
class Solution {
  public:
  void Total(Node *root, int &count)
  {
      if(root==NULL)
      return;
      
      count++;
      Total(root->left,count);
      Total(root->right,count);
  }
  
  
  
  
    int getSize(Node* node) {
        int count =0;
        Total(node,count);
        return count;
        
    }
};