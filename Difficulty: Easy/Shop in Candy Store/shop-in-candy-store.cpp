class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        
        int n = prices.size();
        sort(prices.begin(), prices.end());
        
        int min_amount = 0, max_amount = 0;
        int i = 0, j = n - 1;
        
        // Minimum amount
        while(i <= j)
        {
            min_amount += prices[i];
            i++;
            j -= k;
        }
        
        // reset pointers
        i = 0;
        j = n - 1;
        
        // Maximum amount
        while(j >= i)
        {
            max_amount += prices[j];
            j--;
            i += k;
        }
        
        return {min_amount, max_amount};
    }
};

