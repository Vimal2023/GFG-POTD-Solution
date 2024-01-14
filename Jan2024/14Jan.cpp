class Solution
{
public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N)
    {
        unordered_set<string> seen_rows;
        vector<int> duplicates;

        for (int i = 0; i < M; i++)
        {
            string row_str = "";
            for (int j = 0; j < N; j++)
            {
                row_str += to_string(matrix[i][j]);
            }

            if (seen_rows.find(row_str) != seen_rows.end())
            {
                duplicates.push_back(i);
            }
            else
            {
                seen_rows.insert(row_str);
            }
        }

        return duplicates;
    }
};
