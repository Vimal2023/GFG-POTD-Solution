
// Problem name --- Largest rectangular sub-matrix whose sum is 0.

class Solution{
public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> mat){
        int n = mat.size();
        int m = mat[0].size();

        int maxArea = 0;
        int startX = -1, startY = -1, endX = -1, endY = -1;

        for (int left = 0; left < m; ++left) {
            vector<int> temp(n, 0);
            for (int right = left; right < m; ++right) {
                for (int i = 0; i < n; ++i) {
                    temp[i] += mat[i][right];
                }

                unordered_map<int, int> prefixSums;
                prefixSums[0] = -1;
                int currentSum = 0;

                for (int i = 0; i < n; ++i) {
                    currentSum += temp[i];
                    if (prefixSums.find(currentSum) != prefixSums.end()) {
                        int len = (right - left + 1) * (i - prefixSums[currentSum]);
                        if (len > maxArea) {
                            maxArea = len;
                            startX = prefixSums[currentSum] + 1;
                            startY = left;
                            endX = i;
                            endY = right;
                        }
                    } else {
                        prefixSums[currentSum] = i;
                    }
                }
            }
        }

        if (maxArea == 0) return {};

        vector<vector<int>> result;
        for (int i = startX; i <= endX; ++i) {
            vector<int> row(mat[i].begin() + startY, mat[i].begin() + endY + 1);
            result.push_back(row);
        }
        return result;
    }
};
