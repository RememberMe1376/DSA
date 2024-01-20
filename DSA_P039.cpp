#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximize_sum(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<bool> row_chosen(n, false);
    vector<bool> col_chosen(n, false);

    int result = 0;

    for (int _ = 0; _ < n; ++_)
    {
        int max_val = -1;
        int max_row = -1;
        int max_col = -1;

        for (int i = 0; i < n; ++i)
        {
            if (!row_chosen[i])
            {
                for (int j = 0; j < n; ++j)
                {
                    if (!col_chosen[j] && matrix[i][j] > max_val)
                    {
                        max_val = matrix[i][j];
                        max_row = i;
                        max_col = j;
                    }
                }
            }
        }

        row_chosen[max_row] = true;
        col_chosen[max_col] = true;
        result += max_val;
    }

    return result;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;

        vector<vector<int>> matrix(N, vector<int>(N));
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> matrix[i][j];
            }
        }

        int result = maximize_sum(matrix);
        cout << result << endl;
    }

    return 0;
}
