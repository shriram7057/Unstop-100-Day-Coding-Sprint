#include <iostream>
#include <vector>
using namespace std;

vector<int> find_stone_path(const vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    vector<int> result(cols);

    for (int start = 0; start < cols; start++) {
        int col = start;
        bool stuck = false;

        for (int row = 0; row < rows; row++) {
            int dir = grid[row][col];
            int nextCol = col + dir;

            // check boundary or V-shape blockage
            if (nextCol < 0 || nextCol >= cols || grid[row][nextCol] != dir) {
                stuck = true;
                break;
            }

            col = nextCol;
        }

        result[start] = stuck ? -1 : col;
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<int> result = find_stone_path(grid);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}