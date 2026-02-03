class Solution {
  public:
    int findMin(int n) {
        int coins[] = {10, 5, 2, 1};
        int count = 0;
        
        for(int c : coins) {
            count += n / c;  // take max possible coins
            n %= c;          // reduce remaining amount
        }
        
        return count;
    }
};
