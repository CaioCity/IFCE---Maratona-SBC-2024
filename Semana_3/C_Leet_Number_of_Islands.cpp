// https://leetcode.com/problems/number-of-islands/
// Number of Islands

class Solution {
public:
    void define_ilha(short int i, short int j, vector<vector<char>>& grid,
                     bool visited[][310]) {
        queue<pair<short int, short int>> fila;
        fila.push(make_pair(i, j));

        while (!(fila.empty())) {
            short int a = fila.front().first, b = fila.front().second;
            fila.pop();
            if (visited[a][b])
                continue;
            visited[a][b] = 1;

            if (grid[a][b + 1] && !(visited[a][b + 1]))
                fila.push(make_pair(a, (b + 1)));
            if (grid[a][b - 1] && !(visited[a][b - 1]))
                fila.push(make_pair(a, (b - 1)));
            if (grid[a + 1][b] && !(visited[a + 1][b]))
                fila.push(make_pair((a + 1), b));
            if (grid[a - 1][b] && !(visited[a - 1][b]))
                fila.push(make_pair((a - 1), b));
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int ilhas = 0;
        short int y = grid.size(), x = grid[0].size();
        bool visited[310][310];

        for (short int i = 0; i < y; i++)
            for (short int j = 0; j < y; j++)
                visited[i][j] = 0;

        for (short int i = 0; i < y; i++)
            for (short int j = 0; j < x; j++)
                if (grid[i][j] && !visited[i][j]) {
                    ilhas++;
                    define_ilha(i, j, grid, visited);
                }

        return ilhas;
    }
};
