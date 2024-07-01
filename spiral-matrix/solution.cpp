class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = height ? matrix[0].size() : 0;
        
        int up = 0;
        int down = height - 1;
        int left = 0;
        int right = width - 1;
        int current_pointer = 0;
        
        vector<int> ordered_array(height*width);

        while (up <= down && left <= right) {
            
            for (int current_col = left; current_col <= right; current_col++) {
                ordered_array[current_pointer] = matrix[up][current_col];
                current_pointer++;
            }

            up++;
            if (up > down) {
                break;
            }

            for(int current_row = up; current_row <= down; current_row++) {
                ordered_array[current_pointer] = matrix[current_row][right];
                current_pointer++;
            }

            right--;
            if (right < left) {
                break;
            }

            for (int current_col = right; current_col >= left; current_col--) {
                ordered_array[current_pointer] = matrix[down][current_col];
                current_pointer++;
            }

            down--;
            if (down < up) {
                break;
            }

            for (int current_row = down; current_row >= up; current_row--) {
                ordered_array[current_pointer] = matrix[current_row][left];
                current_pointer++;
            }

            left++;
            if (left > right) {
                break;
            }
        }

        return ordered_array;
    }
};