class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row = image.size();
        int col = image[0].size();

        for(int i = 0; i < row; i++) {

            // STEP 1: SWAP (reverse row)
            int start = 0;
            int end = col - 1;

            while(start < end) {
                swap(image[i][start], image[i][end]);
                start++;
                end--;
            }

            // STEP 2: INVERT (0->1, 1->0)
            for(int j = 0; j < col; j++) {
                image[i][j] = image[i][j] ^ 1;
            }
        }

        return image;
    }
};