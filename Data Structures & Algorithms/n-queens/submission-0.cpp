class Solution {
public:
    void isrow(vector<vector<int>> &table, int x, int y) {

        int n = table.size();

        // Row
        for (int j = 0; j < n; j++) {
            if (table[x][j] != -1)
                table[x][j] = 1;
        }

        // Column
        for (int i = 0; i < n; i++) {
            if (table[i][y] != -1)
                table[i][y] = 1;
        }

        // Top Left
        for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
            if (table[i][j] != -1)
                table[i][j] = 1;
        }

        // Top Right
        for (int i = x, j = y; i >= 0 && j < n; i--, j++) {
            if (table[i][j] != -1)
                table[i][j] = 1;
        }

        // Bottom Left
        for (int i = x, j = y; i < n && j >= 0; i++, j--) {
            if (table[i][j] != -1)
                table[i][j] = 1;
        }

        // Bottom Right
        for (int i = x, j = y; i < n && j < n; i++, j++) {
            if (table[i][j] != -1)
                table[i][j] = 1;
        }
    }

    void solve(int x,
               vector<vector<int>> &table,
               vector<vector<string>> &ans,
               int n) {

        if (x == n) {

            vector<string> board;

            for (int i = 0; i < n; i++) {
                string row = "";

                for (int j = 0; j < n; j++) {
                    if (table[i][j] == -1)
                        row += 'Q';
                    else
                        row += '.';
                }

                board.push_back(row);
            }

            ans.push_back(board);
            return;
        }

        for (int y = 0; y < n; y++) {

            if (table[x][y] != 1 && table[x][y] != -1) {

                vector<vector<int>> newTable = table;

                newTable[x][y] = -1;
                isrow(newTable, x, y);

                solve(x + 1, newTable, ans, n);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<int>> table(n, vector<int>(n, 0));
        vector<vector<string>> ans;

        solve(0, table, ans, n);

        return ans;
    }
};