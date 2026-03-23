class Solution {
public:

    int Rectangle(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while(!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;

                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;   // ✅ added safety

        int col = matrix[0].size();
        int ans = 0;             // ✅ initialized

        vector<int> height(col, 0);

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] = height[j] + 1;
            }
            ans = max(ans, Rectangle(height));
        }
        return ans;
    }
};