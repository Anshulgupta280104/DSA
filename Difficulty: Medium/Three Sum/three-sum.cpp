class Solution {
public:
    vector<vector<int>> triplets(vector<int>& arr) {
        
        vector<vector<int>> result;
        int n = arr.size();
        
        // Sort array
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n - 2; i++)
        {
            // Skip duplicate i
            if(i > 0 && arr[i] == arr[i-1])
                continue;
            
            int start = i + 1;
            int end = n - 1;
            
            while(start < end)
            {
                int sum = arr[i] + arr[start] + arr[end];
                
                if(sum == 0)
                {
                    result.push_back({arr[i], arr[start], arr[end]});
                    
                    start++;
                    end--;
                    
                    // Skip duplicate start
                    while(start < end && arr[start] == arr[start-1])
                        start++;
                    
                    // Skip duplicate end
                    while(start < end && arr[end] == arr[end+1])
                        end--;
                }
                else if(sum > 0)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
        
        return result;
    }
};
