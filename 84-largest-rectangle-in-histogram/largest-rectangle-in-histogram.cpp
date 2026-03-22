class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> left(n), right(n);
        stack<int> st;

        // Step 1: Find Next Smaller Element to the RIGHT
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) {
            right[st.top()] = n;
            st.pop();
        }

        // Step 2: Find Next Smaller Element to the LEFT
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) {
            left[st.top()] = -1;
            st.pop();
        }

        // Step 3: Calculate max area
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};